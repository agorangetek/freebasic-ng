#!/usr/bin/env python3
"""Fix clang computed goto issue in FreeBASIC-generated C files.

Clang requires at least one &&label expression in any function that uses
indirect goto (goto *ptr). FreeBASIC's error handling emits goto *ptr from
fb_ErrorThrowAt without a corresponding &&label. This script adds a dummy
label address to affected functions.
"""
import re
import sys


def find_function_end(lines, start):
    """Return the line closing a C function body, ignoring strings/comments."""
    depth = 0
    in_block_comment = False

    for line_number in range(start, len(lines)):
        line = lines[line_number]
        character = 0
        while character < len(line):
            current = line[character]
            following = line[character + 1] if character + 1 < len(line) else ""

            if in_block_comment:
                if current == "*" and following == "/":
                    in_block_comment = False
                    character += 2
                else:
                    character += 1
                continue
            if current == "/" and following == "*":
                in_block_comment = True
                character += 2
                continue
            if current == "/" and following == "/":
                break
            if current in ("'", '\"'):
                quote = current
                character += 1
                while character < len(line):
                    if line[character] == "\\":
                        character += 2
                    elif line[character] == quote:
                        character += 1
                        break
                    else:
                        character += 1
                continue
            if current == "{":
                depth += 1
            elif current == "}":
                depth -= 1
                if depth == 0:
                    return line_number
            character += 1

    raise ValueError("unterminated C function body")


def fix_file(filepath):
    with open(filepath) as f:
        content = f.read()

    if 'goto *' not in content:
        return False

    lines = content.split('\n')
    new_lines = []
    i = 0
    modified = False

    while i < len(lines):
        new_lines.append(lines[i])

        if (re.match(r'^[a-zA-Z_$]', lines[i]) and
            not re.match(r'^(if|else|for|while|switch|do)\b', lines[i]) and
            '(' in lines[i] and ')' in lines[i]):

            # -g makes fbc place a #line directive between a C function
            # signature and its opening brace.  It is still the same
            # function, so skip those directives before locating the body.
            func_start = i + 1
            while (func_start < len(lines) and
                   lines[func_start].lstrip().startswith('#line')):
                func_start += 1

            if func_start < len(lines) and lines[func_start].strip() == '{':
                func_end = find_function_end(lines, func_start)
                func_body = '\n'.join(lines[func_start:func_end + 1])
                has_goto_star = bool(re.search(r'goto \*', func_body))
                # It is harmless to add our own label address even if fbc emitted
                # another one elsewhere in the function.  That is more robust
                # than trying to parse C braces in generated strings and comments.
                if has_goto_star:
                    while i < func_start:
                        i += 1
                        new_lines.append(lines[i])
                    new_lines.append('\t__label__ __fb_dummy_label;')
                    new_lines.append('\tif(0) { __fb_dummy_label: ; }')
                    new_lines.append('\t(void)&&__fb_dummy_label;')
                    modified = True

        i += 1

    if modified:
        with open(filepath, 'w') as f:
            f.write('\n'.join(new_lines))

    return modified


if __name__ == '__main__':
    for path in sys.argv[1:]:
        fix_file(path)
