/* file device */

#include "fb.h"

/* Convert a NUL-terminated multibyte buffer without writing a terminator past
   the caller-provided destination. fb_wstr_ConvFromA() deliberately requires
   one extra wchar slot, but pfnReadWstr() receives exactly the requested
   number of wchar slots. */
static size_t hConvertFromA( FB_WCHAR *dst, size_t dst_chars, const char *src )
{
#if defined( DISABLE_WCHAR )
    size_t chars = strlen( src );

    if( chars > dst_chars )
        chars = dst_chars;
    memcpy( dst, src, chars );
    return chars;
#else
    size_t chars = mbstowcs( dst, src, dst_chars );

    if( chars != (size_t)-1 )
        return chars;

    /* Match fb_wstr_ConvFromA()'s conservative fallback for an invalid
       multibyte sequence, while preserving the destination bound. */
    chars = 0;
    while( (chars < dst_chars) && (src[chars] != '\0') )
    {
        unsigned char c = src[chars];
        dst[chars] = (c > 127 ? _LC('?') : c);
        ++chars;
    }
    return chars;
#endif
}

int fb_DevFileReadWstr( FB_FILE *handle, FB_WCHAR *dst, size_t *pchars )
{
    FILE *fp;
    size_t chars, requested_chars;
    char *buffer;
    int heap_buffer;

    FB_LOCK();

    if( handle == NULL )
        fp = stdin;
    else
    {
        fp = (FILE*) handle->opaque;
        if( fp == stdout || fp == stderr )
            fp = stdin;

        if( fp == NULL )
        {
            FB_UNLOCK();
            return fb_ErrorSetNum( FB_RTERROR_ILLEGALFUNCTIONCALL );
        }
    }

    requested_chars = *pchars;
    chars = requested_chars;
    heap_buffer = (chars >= FB_LOCALBUFF_MAXLEN);

	if( !heap_buffer )
	{
		buffer = alloca( chars + 1 );
		/* note: if out of memory on alloca, it's a stack exception */
	}
	else
	{
		buffer = malloc( chars + 1 );
		if( buffer == NULL )
		{
			FB_UNLOCK();
			return fb_ErrorSetNum( FB_RTERROR_OUTOFMEM );
		}
	}

	/* do read */
	chars = fread( buffer, 1, chars, fp );
	buffer[chars] = '\0';

    /* Do not use fb_wstr_ConvFromA() here: it always writes a terminator,
       while dst has exactly requested_chars slots. */
    chars = hConvertFromA( dst, requested_chars, buffer );

	if( heap_buffer )
		free( buffer );

	/* fill with nulls if at eof */
    if( chars != requested_chars )
        memset( (void *)&dst[chars], 0,
                (requested_chars - chars) * sizeof( FB_WCHAR ) );

    *pchars = chars;

	FB_UNLOCK();

	return fb_ErrorSetNum( FB_RTERROR_OK );
}
