typedef   signed char       int8;
typedef unsigned char      uint8;
typedef   signed short      int16;
typedef unsigned short     uint16;
typedef   signed int        int32;
typedef unsigned int       uint32;
typedef   signed long long  int64;
typedef unsigned long long uint64;
typedef struct { char *data; int64 len; int64 size; } FBSTRING;
typedef int8 boolean;
struct $8HASHITEM;
struct $8HASHITEM {
	char* NAME;
	void* DATA;
	struct $8HASHITEM* PREV;
	struct $8HASHITEM* NEXT;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
__FB_STATIC_ASSERT( sizeof( struct $8HASHITEM ) == 32 );
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
struct $12SECTIONENTRY {
	FBSTRING TEXT;
	int64 OLD;
	int64 INDENT;
};
__FB_STATIC_ASSERT( sizeof( struct $12SECTIONENTRY ) == 40 );
struct $7TLISTTB;
struct $7TLISTTB {
	struct $7TLISTTB* NEXT;
	void* NODETB;
	int64 NODES;
};
__FB_STATIC_ASSERT( sizeof( struct $7TLISTTB ) == 24 );
struct $9TLISTNODE;
struct $9TLISTNODE {
	struct $9TLISTNODE* PREV;
	struct $9TLISTNODE* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9TLISTNODE ) == 16 );
typedef int64 $10LIST_FLAGS;
struct $5TLIST {
	struct $7TLISTTB* TBHEAD;
	struct $7TLISTTB* TBTAIL;
	int64 NODES;
	int64 NODELEN;
	struct $9TLISTNODE* FHEAD;
	void* HEAD;
	void* TAIL;
	$10LIST_FLAGS FLAGS;
};
__FB_STATIC_ASSERT( sizeof( struct $5TLIST ) == 64 );
struct $8IRHLCCTX {
	struct $12SECTIONENTRY SECTIONS[129];
	int64 SECTION;
	int64 SECTIONGOSUBLEVEL;
	int64 LINENUM;
	FBSTRING ESCAPEDINPUTFILENAME;
	uint64 USEDBUILTINS;
	struct $5TLIST ANONSTACK;
	FBSTRING VARINI;
	int64 VARINISCOPELEVEL;
	FBSTRING FBCTINF;
	FBSTRING EXPORTS;
	struct $5TLIST EXPRNODES;
	FBSTRING EXPRTEXT;
	struct $5TLIST EXPRCACHE;
	int64 GLOBALVARPASS;
};
__FB_STATIC_ASSERT( sizeof( struct $8IRHLCCTX ) == 5520 );
typedef int64 $6IR_OPT;
typedef int64 $12FB_SYMBCLASS;
typedef int64 $13FB_SYMBATTRIB;
typedef int64 $13FB_PROCATTRIB;
typedef int64 $12FB_SYMBSTATS;
struct $9FB_SYMBID {
	char* NAME;
	char* ALIAS;
	char* MANGLED;
};
__FB_STATIC_ASSERT( sizeof( struct $9FB_SYMBID ) == 24 );
typedef int64 $11FB_DATATYPE;
struct $8FBSYMBOL;
typedef int64 $13AST_NODECLASS;
union $7FBVALUE {
	struct $8FBSYMBOL* S;
	int64 I;
	double F;
};
__FB_STATIC_ASSERT( sizeof( union $7FBVALUE ) == 8 );
struct $14AST_NODE_CONST {
	union {
		union $7FBVALUE VALUE;
		struct $8FBSYMBOL* S;
		int64 I;
		double F;
	};
	int64 HASSUFFIX;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_CONST ) == 16 );
struct $12AST_NODE_VAR {
	int64 OFS;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_VAR ) == 8 );
struct $12AST_NODE_IDX {
	int64 OFS;
	int64 MULT;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_IDX ) == 16 );
struct $12AST_NODE_PTR {
	int64 OFS;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_PTR ) == 8 );
struct $7ASTNODE;
struct $19AST_TMPSTRLIST_ITEM;
struct $19AST_TMPSTRLIST_ITEM {
	struct $8FBSYMBOL* SYM;
	struct $7ASTNODE* SRCTREE;
	struct $19AST_TMPSTRLIST_ITEM* PREV;
};
__FB_STATIC_ASSERT( sizeof( struct $19AST_TMPSTRLIST_ITEM ) == 24 );
struct $13AST_NODE_CALL {
	int64 ISRTL;
	int64 ARGS;
	struct $8FBSYMBOL* CURRARG;
	struct $7ASTNODE* ARGTAIL;
	struct $19AST_TMPSTRLIST_ITEM* STRTAIL;
	struct $8FBSYMBOL* TMPRES;
	struct $7ASTNODE* PROFBEGIN;
	struct $7ASTNODE* PROFEND;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_CALL ) == 64 );
struct $12AST_NODE_ARG {
	int64 MODE;
	int64 LGT;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_ARG ) == 16 );
struct $12AST_NODE_IIF {
	struct $8FBSYMBOL* FALSELABEL;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_IIF ) == 8 );
typedef int64 $9AST_OPOPT;
struct $11AST_NODE_OP {
	int64 OP;
	$9AST_OPOPT OPTIONS;
	struct $8FBSYMBOL* EX;
};
__FB_STATIC_ASSERT( sizeof( struct $11AST_NODE_OP ) == 24 );
struct $13AST_NODE_LOAD {
	int64 ISRES;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_LOAD ) == 8 );
struct $14AST_NODE_LABEL {
	int64 FLUSH;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_LABEL ) == 8 );
struct $13AST_NODE_OFFS {
	int64 OFS;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_OFFS ) == 8 );
struct $12AST_NODE_LIT {
	char* TEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_LIT ) == 8 );
typedef int64 $14AST_ASMTOKTYPE;
struct $9ASTASMTOK;
struct $9ASTASMTOK {
	$14AST_ASMTOKTYPE TYPE;
	union {
		struct $8FBSYMBOL* SYM;
		char* TEXT;
	};
	struct $9ASTASMTOK* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9ASTASMTOK ) == 24 );
struct $12AST_NODE_ASM {
	struct $9ASTASMTOK* TOKHEAD;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_ASM ) == 8 );
struct $14AST_NODE_JMPTB {
	uint64* VALUES;
	struct $8FBSYMBOL** LABELS;
	int64 LABELCOUNT;
	struct $8FBSYMBOL* DEFLABEL;
	uint64 BIAS;
	uint64 SPAN;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_JMPTB ) == 48 );
struct $12AST_NODE_DBG {
	int64 EX;
	char* FILENAME;
	int64 OP;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_DBG ) == 24 );
struct $12AST_NODE_MEM {
	int64 OP;
	int64 BYTES;
	int64 FILLCHAR;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_NODE_MEM ) == 24 );
struct $14AST_NODE_STACK {
	int64 OP;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_STACK ) == 8 );
struct $16AST_NODE_TYPEINI {
	int64 OFS;
	union {
		int64 BYTES;
		int64 ELEMENTS;
	};
	struct $8FBSYMBOL* SCP;
	struct $8FBSYMBOL* LASTSCP;
};
__FB_STATIC_ASSERT( sizeof( struct $16AST_NODE_TYPEINI ) == 32 );
struct $21AST_NODE_TYPEINISCOPE {
	int64 IS_ARRAY;
};
__FB_STATIC_ASSERT( sizeof( struct $21AST_NODE_TYPEINISCOPE ) == 8 );
struct $13AST_BREAKLIST {
	struct $7ASTNODE* HEAD;
	struct $7ASTNODE* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_BREAKLIST ) == 16 );
struct $13AST_NODE_PROC {
	int64 ISMAIN;
	struct $7ASTNODE* DECL_LAST;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_PROC ) == 16 );
struct $14AST_NODE_BLOCK {
	struct $7ASTNODE* PARENT;
	int64 INISTMT;
	int64 ENDSTMT;
	struct $8FBSYMBOL* INITLABEL;
	struct $8FBSYMBOL* EXITLABEL;
	struct $13AST_BREAKLIST BREAKLIST;
	struct $13AST_NODE_PROC PROC;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_BLOCK ) == 72 );
struct $14AST_NODE_BREAK {
	struct $7ASTNODE* PARENT;
	int64 SCOPE;
	int64 LINENUM;
	int64 STMTNUM;
};
__FB_STATIC_ASSERT( sizeof( struct $14AST_NODE_BREAK ) == 32 );
struct $17AST_NODE_DATASTMT {
	union {
		int64 ID;
		int64 ELMTS;
	};
};
__FB_STATIC_ASSERT( sizeof( struct $17AST_NODE_DATASTMT ) == 8 );
struct $13AST_NODE_LINK {
	int64 RET;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_LINK ) == 8 );
struct $13AST_NODE_CAST {
	int64 DOCONV;
	int64 DO_CONVFD2FS;
	int64 CONVCONST;
};
__FB_STATIC_ASSERT( sizeof( struct $13AST_NODE_CAST ) == 24 );
struct $7ASTNODE {
	$13AST_NODECLASS CLASS;
	int64 DTYPE;
	struct $8FBSYMBOL* SUBTYPE;
	struct $8FBSYMBOL* SYM;
	int64 VECTOR;
	union {
		struct $14AST_NODE_CONST VAL;
		struct $12AST_NODE_VAR VAR_;
		struct $12AST_NODE_IDX IDX;
		struct $12AST_NODE_PTR PTR;
		struct $13AST_NODE_CALL CALL;
		struct $12AST_NODE_ARG ARG;
		struct $12AST_NODE_IIF IIF;
		struct $11AST_NODE_OP OP;
		struct $13AST_NODE_LOAD LOD;
		struct $14AST_NODE_LABEL LBL;
		struct $13AST_NODE_OFFS OFS;
		struct $12AST_NODE_LIT LIT;
		struct $12AST_NODE_ASM ASM;
		struct $14AST_NODE_JMPTB JMPTB;
		struct $12AST_NODE_DBG DBG;
		struct $12AST_NODE_MEM MEM;
		struct $14AST_NODE_STACK STACK;
		struct $16AST_NODE_TYPEINI TYPEINI;
		struct $21AST_NODE_TYPEINISCOPE TYPEINISCOPE;
		struct $14AST_NODE_BLOCK BLOCK;
		struct $14AST_NODE_BREAK BREAK;
		struct $17AST_NODE_DATASTMT DATA;
		struct $13AST_NODE_LINK LINK;
		struct $13AST_NODE_CAST CAST;
	};
	struct $7ASTNODE* L;
	struct $7ASTNODE* R;
	struct $7ASTNODE* PREV;
	struct $7ASTNODE* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $7ASTNODE ) == 144 );
struct $10FBARRAYDIM {
	int64 LOWER;
	int64 UPPER;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBARRAYDIM ) == 16 );
struct $9FBS_ARRAY {
	int64 DIMENSIONS;
	struct $10FBARRAYDIM* DIMTB;
	int64 DIFF;
	int64 ELEMENTS;
	struct $8FBSYMBOL* DESC;
	struct $8FBSYMBOL* DESCTYPE;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBS_ARRAY ) == 48 );
struct $10FBVAR_DESC {
	struct $8FBSYMBOL* ARRAY;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBVAR_DESC ) == 8 );
struct $10FBVAR_DATA {
	struct $8FBSYMBOL* PREV;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBVAR_DATA ) == 8 );
struct $7FBS_VAR {
	union {
		char* LITTEXT;
		uint32* LITTEXTW;
		struct $7ASTNODE* INITREE;
	};
	struct $9FBS_ARRAY ARRAY;
	struct $10FBVAR_DESC DESC;
	int64 STMTNUM;
	int64 ALIGN;
	struct $10FBVAR_DATA DATA;
	int64 BITPOS;
	int64 BITS;
};
__FB_STATIC_ASSERT( sizeof( struct $7FBS_VAR ) == 104 );
struct $9FBS_CONST {
	union {
		union $7FBVALUE VALUE;
		struct $8FBSYMBOL* S;
		int64 I;
		double F;
	};
	int64 HASSUFFIX;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBS_CONST ) == 16 );
struct $10FBSYMBOLTB {
	struct $8FBSYMBOL* OWNER;
	struct $8FBSYMBOL* HEAD;
	struct $8FBSYMBOL* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBSYMBOLTB ) == 24 );
struct $8HASHLIST {
	struct $8HASHITEM* HEAD;
	struct $8HASHITEM* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $8HASHLIST ) == 16 );
struct $5THASH {
	struct $8HASHLIST* LIST;
	int64 NODES;
	int64 DELSTR;
};
__FB_STATIC_ASSERT( sizeof( struct $5THASH ) == 24 );
struct $8FBHASHTB;
struct $8FBHASHTB {
	struct $8FBSYMBOL* OWNER;
	struct $5THASH TB;
	struct $8FBHASHTB* PREV;
	struct $8FBHASHTB* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBHASHTB ) == 48 );
struct $9FBSYMLIST {
	struct $8FBSYMBOL* HEAD;
	struct $8FBSYMBOL* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBSYMLIST ) == 16 );
struct $10FBSYMCHAIN;
struct $10FBSYMCHAIN {
	struct $8FBSYMBOL* SYM;
	struct $10FBSYMCHAIN* NEXT;
	int64 ISIMPORT;
	struct $10FBSYMCHAIN* PREV;
	struct $8HASHITEM* ITEM;
	struct $10FBSYMCHAIN* IMP_NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBSYMCHAIN ) == 48 );
struct $13FBNAMESPC_EXT {
	struct $9FBSYMLIST IMPLIST;
	struct $9FBSYMLIST EXPLIST;
	int64 CNT;
	struct $10FBSYMCHAIN* IMPSYM_HEAD;
	struct $10FBSYMCHAIN* IMPSYM_TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $13FBNAMESPC_EXT ) == 56 );
struct $9FBNAMESPC {
	struct $10FBSYMBOLTB SYMTB;
	struct $8FBHASHTB HASHTB;
	struct $13FBNAMESPC_EXT* EXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBNAMESPC ) == 80 );
typedef int64 $15FB_STRUCT_INREG;
struct $13FB_STRUCT_DBG {
	int64 TYPENUM;
};
__FB_STATIC_ASSERT( sizeof( struct $13FB_STRUCT_DBG ) == 8 );
struct $12FB_STRUCTEXT {
	struct $8FBSYMBOL* CTORHEAD;
	struct $8FBSYMBOL* DEFCTOR;
	struct $8FBSYMBOL* COPYCTOR;
	struct $8FBSYMBOL* COPYCTORCONST;
	struct $8FBSYMBOL* DTOR1;
	struct $8FBSYMBOL* DTOR0;
	struct $8FBSYMBOL* COPYLETOP;
	struct $8FBSYMBOL* COPYLETOPCONST;
	struct $8FBSYMBOL* OPOVLTB[28];
	int64 VTABLEELEMENTS;
	struct $8FBSYMBOL* VTABLE;
	struct $8FBSYMBOL* RTTI;
	int64 ABSTRACTCOUNT;
};
__FB_STATIC_ASSERT( sizeof( struct $12FB_STRUCTEXT ) == 320 );
struct $10FBS_STRUCT {
	struct $9FBNAMESPC NS;
	struct $8FBSYMBOL* BASE;
	struct $8FBSYMBOL* ANONPARENT;
	int64 NATALIGN;
	int64 UNPADLGT;
	int32 OPTIONS;
	uint8 BITPOS;
	uint8 ALIGN;
	$11FB_DATATYPE RETDTYPE;
	$15FB_STRUCT_INREG RETIN2REGS;
	struct $13FB_STRUCT_DBG DBG;
	struct $12FB_STRUCTEXT* EXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBS_STRUCT ) == 152 );
struct $8FBS_ENUM {
	struct $9FBNAMESPC NS;
	int64 ELEMENTS;
	struct $13FB_STRUCT_DBG DBG;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBS_ENUM ) == 96 );
typedef int64 $11FB_FUNCMODE;
typedef int64 $21FB_PROC_RETURN_METHOD;
typedef int64 (*tmp$34)( struct $8FBSYMBOL* );
struct $10FB_PROCRTL {
	tmp$34 CALLBACK;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCRTL ) == 8 );
struct $10FB_PROCOVL {
	int16 MINPARAMS;
	int16 MAXPARAMS;
	struct $8FBSYMBOL* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCOVL ) == 16 );
struct $10FB_PROCSTK {
	int64 ARGOFS;
	int64 LOCALOFS;
	int64 LOCALMAX;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCSTK ) == 24 );
struct $10FB_PROCDBG {
	int64 INILINE;
	int64 ENDLINE;
	char* INCFILE;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCDBG ) == 24 );
struct $10FB_PROCERR {
	struct $8FBSYMBOL* LASTHND;
	struct $8FBSYMBOL* LASTMOD;
	struct $8FBSYMBOL* LASTFUN;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCERR ) == 24 );
typedef int64 $6AST_OP;
struct $12FB_PROCOPOVL {
	$6AST_OP OP;
};
__FB_STATIC_ASSERT( sizeof( struct $12FB_PROCOPOVL ) == 8 );
typedef int64 $12FB_PROCSTATS;
struct $10FB_PROCGSB {
	struct $8FBSYMBOL* CTX;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCGSB ) == 8 );
struct $10FB_PROCEXT {
	struct $8FBSYMBOL* RES;
	struct $10FB_PROCSTK STK;
	struct $10FB_PROCDBG DBG;
	struct $10FB_PROCERR ERR;
	struct $12FB_PROCOPOVL OPOVL;
	struct $5TLIST* STATDTOR;
	$12FB_PROCSTATS STATS;
	int64 STMTNUM;
	int64 PRIORITY;
	struct $10FB_PROCGSB GOSUB;
	struct $7ASTNODE* BASE_INITREE;
	int64 VTABLEINDEX;
	struct $8FBSYMBOL* OVERRIDDEN;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_PROCEXT ) == 152 );
struct $8FBS_PROC {
	struct $10FBSYMBOLTB SYMTB;
	int16 PARAMS;
	int16 OPTPARAMS;
	struct $10FBSYMBOLTB PARAMTB;
	$11FB_FUNCMODE MODE;
	$11FB_DATATYPE REALDTYPE;
	struct $8FBSYMBOL* REALSUBTYPE;
	$21FB_PROC_RETURN_METHOD RETURNMETHOD;
	struct $10FB_PROCRTL RTL;
	struct $10FB_PROCOVL OVL;
	struct $10FB_PROCEXT* EXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBS_PROC ) == 120 );
typedef int64 $12FB_PARAMMODE;
struct $9FBS_PARAM {
	$12FB_PARAMMODE MODE;
	struct $8FBSYMBOL* VAR;
	struct $7ASTNODE* OPTEXPR;
	int64 BYDESCDIMENSIONS;
	struct $8FBSYMBOL* BYDESCREALSUBTYPE;
	int64 REGNUM;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBS_PARAM ) == 48 );
struct $9FBS_LABEL {
	struct $8FBSYMBOL* PARENT;
	int64 DECLARED;
	int64 STMTNUM;
	boolean GOSUB;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBS_LABEL ) == 32 );
struct $11FB_DEFPARAM;
struct $11FB_DEFPARAM {
	char* NAME;
	int64 NUM;
	struct $11FB_DEFPARAM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $11FB_DEFPARAM ) == 24 );
typedef int64 $14FB_DEFTOK_TYPE;
struct $9FB_DEFTOK;
struct $9FB_DEFTOK {
	$14FB_DEFTOK_TYPE TYPE;
	union {
		char* TEXT;
		uint32* TEXTW;
		int64 PARAMNUM;
	};
	struct $9FB_DEFTOK* PREV;
	struct $9FB_DEFTOK* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9FB_DEFTOK ) == 32 );
typedef int64 $15FB_DEFINE_FLAGS;
typedef FBSTRING* (*tmp$28)( void );
struct $8DZSTRING {
	char* DATA;
	int64 LEN;
	int64 SIZE;
};
__FB_STATIC_ASSERT( sizeof( struct $8DZSTRING ) == 24 );
struct $8DWSTRING {
	uint32* DATA;
	int64 LEN;
	int64 SIZE;
};
__FB_STATIC_ASSERT( sizeof( struct $8DWSTRING ) == 24 );
struct $9LEXPP_ARG {
	union {
		struct $8DZSTRING TEXT;
		struct $8DWSTRING TEXTW;
	};
};
__FB_STATIC_ASSERT( sizeof( struct $9LEXPP_ARG ) == 24 );
struct $11LEXPP_ARGTB {
	struct $9LEXPP_ARG TB[32];
	int64 COUNT;
};
__FB_STATIC_ASSERT( sizeof( struct $11LEXPP_ARGTB ) == 776 );
typedef FBSTRING* (*tmp$29)( struct $11LEXPP_ARGTB*, int64* );
typedef uint32* (*tmp$30)( struct $11LEXPP_ARGTB*, int64* );
struct $10FBS_DEFINE {
	int64 PARAMS;
	struct $11FB_DEFPARAM* PARAMHEAD;
	union {
		struct $9FB_DEFTOK* TOKHEAD;
		char* TEXT;
		uint32* TEXTW;
	};
	int64 ISARGLESS;
	$15FB_DEFINE_FLAGS FLAGS;
	union {
		tmp$28 DPROCZ;
		tmp$29 MPROCZ;
	};
	union {
		tmp$30 MPROCW;
	};
};
__FB_STATIC_ASSERT( sizeof( struct $10FBS_DEFINE ) == 56 );
typedef int64 $10FB_TKCLASS;
struct $11FBS_KEYWORD {
	int64 ID;
	$10FB_TKCLASS TKCLASS;
};
__FB_STATIC_ASSERT( sizeof( struct $11FBS_KEYWORD ) == 16 );
struct $8FBFWDREF;
struct $8FBFWDREF {
	struct $8FBSYMBOL* REF;
	struct $8FBFWDREF* PREV;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBFWDREF ) == 16 );
struct $10FBS_FWDREF {
	struct $8FBFWDREF* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBS_FWDREF ) == 8 );
struct $11FB_SCOPEDBG {
	int64 INILINE;
	int64 ENDLINE;
	struct $8FBSYMBOL* INILABEL;
	struct $8FBSYMBOL* ENDLABEL;
};
__FB_STATIC_ASSERT( sizeof( struct $11FB_SCOPEDBG ) == 32 );
struct $12FB_SCOPEEMIT {
	int64 BASEOFS;
};
__FB_STATIC_ASSERT( sizeof( struct $12FB_SCOPEEMIT ) == 8 );
struct $9FBS_SCOPE {
	struct $7ASTNODE* BACKNODE;
	struct $10FBSYMBOLTB SYMTB;
	struct $11FB_SCOPEDBG DBG;
	struct $12FB_SCOPEEMIT EMIT;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBS_SCOPE ) == 72 );
struct $13FBS_NAMESPACE {
	struct $9FBNAMESPC NS;
	int64 CNT;
	struct $8FBSYMBOL* LAST_TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $13FBS_NAMESPACE ) == 96 );
struct $12FBS_NSIMPORT {
	struct $8FBSYMBOL* IMP_NS;
	struct $8FBSYMBOL* IMP_PREV;
	struct $8FBSYMBOL* IMP_NEXT;
	struct $8FBSYMBOL* EXP_NS;
	struct $8FBSYMBOL* EXP_PREV;
	struct $8FBSYMBOL* EXP_NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $12FBS_NSIMPORT ) == 48 );
struct $9FBSYMHASH {
	struct $8FBHASHTB* TB;
	struct $8HASHITEM* ITEM;
	uint64 INDEX;
	struct $8FBSYMBOL* PREV;
	struct $8FBSYMBOL* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9FBSYMHASH ) == 40 );
struct $8FBSYMBOL {
	$12FB_SYMBCLASS CLASS;
	$13FB_SYMBATTRIB ATTRIB;
	$13FB_PROCATTRIB PATTRIB;
	$12FB_SYMBSTATS STATS;
	struct $9FB_SYMBID ID;
	$11FB_DATATYPE TYP;
	struct $8FBSYMBOL* SUBTYPE;
	uint16 SCOPE;
	int16 MANGLING;
	int64 LGT;
	int64 OFS;
	union {
		struct $7FBS_VAR VAR_;
		struct $9FBS_CONST VAL;
		struct $10FBS_STRUCT UDT;
		struct $8FBS_ENUM ENUM_;
		struct $8FBS_PROC PROC;
		struct $9FBS_PARAM PARAM;
		struct $9FBS_LABEL LBL;
		struct $10FBS_DEFINE DEF;
		struct $11FBS_KEYWORD KEY;
		struct $10FBS_FWDREF FWD;
		struct $9FBS_SCOPE SCP;
		struct $13FBS_NAMESPACE NSPC;
		struct $12FBS_NSIMPORT NSIMP;
	};
	struct $9FBSYMHASH HASH;
	struct $10FBSYMBOLTB* SYMTB;
	struct $8FBSYMBOL* PARENT;
	struct $8FBSYMBOL* PREV;
	struct $8FBSYMBOL* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBSYMBOL ) == 320 );
typedef int64 $13FB_COMPTARGET;
typedef int64 $16EMITPROC_OPTIONS;
typedef int64 $19FB_CVA_LIST_TYPEDEF;
typedef int64 $12FB_DATACLASS;
struct $13SYMB_DATATYPE {
	$12FB_DATACLASS CLASS;
	int64 SIZE;
	int64 SIGNED;
	int64 INTRANK;
	$11FB_DATATYPE REMAPTYPE;
	int64 SIZETYPE;
	char* NAME;
};
__FB_STATIC_ASSERT( sizeof( struct $13SYMB_DATATYPE ) == 56 );
typedef void (*tmp$43)( struct $8FBSYMBOL* );
typedef int64 $14IR_OPTIONVALUE;
struct $7FBTOKEN;
struct $7FBTOKEN {
	int64 ID;
	int64 CLASS;
	int64 DTYPE;
	union {
		char TEXT[1025];
		uint32 TEXTW[1025];
	};
	int64 LEN;
	struct $10FBSYMCHAIN* SYM_CHAIN;
	union {
		int64 PRDPOS;
		int64 HASESC;
		int64 HASSUFFIX;
	};
	int64 SUFFIXCHAR;
	int64 AFTER_SPACE;
	struct $7FBTOKEN* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $7FBTOKEN ) == 4176 );
typedef int64 $17LEX_TKCTX_CONTEXT;
struct $9LEX_TKCTX {
	struct $7FBTOKEN TOKENTB[4];
	int64 K;
	struct $7FBTOKEN* HEAD;
	struct $7FBTOKEN* TAIL;
	uint64 CURRCHAR;
	uint64 LAHDCHAR1;
	uint64 LAHDCHAR2;
	int64 LINENUM;
	int64 LASTTK_ID;
	int64 RECLEVEL;
	struct $8FBSYMBOL* CURRMACRO;
	struct $8FBSYMBOL* KWDNS;
	$17LEX_TKCTX_CONTEXT KIND;
	int64 DEFLEN;
	union {
		struct {
			char* DEFPTR;
			struct $8DZSTRING DEFTEXT;
		};
		struct {
			uint32* DEFPTRW;
			struct $8DWSTRING DEFTEXTW;
		};
	};
	int64 BUFFLEN;
	union {
		struct {
			char* BUFFPTR;
			char BUFF[8193];
		};
		struct {
			uint32* BUFFPTRW;
			uint32 BUFFW[8193];
		};
	};
	int64 FILEPOS;
	int64 LASTFILEPOS;
	int64 PHYSFILEPOS;
	struct $8DZSTRING CURRLINE;
	int64 AFTER_SPACE;
};
__FB_STATIC_ASSERT( sizeof( struct $9LEX_TKCTX ) == 49688 );
typedef int64 $15IRVREGTYPE_ENUM;
typedef int64 $12IR_REGFAMILY;
struct $6IRVREG;
struct $9IRTACVREG;
struct $9IRTACVREG {
	struct $6IRVREG* VREG;
	struct $6IRVREG* PARENT;
	struct $9IRTACVREG* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9IRTACVREG ) == 24 );
struct $13IRTACVREG_GRP {
	struct $9IRTACVREG REG;
	struct $9IRTACVREG IDX;
	struct $9IRTACVREG AUX;
};
__FB_STATIC_ASSERT( sizeof( struct $13IRTACVREG_GRP ) == 72 );
struct $5IRTAC {
	int64 POS;
	$6AST_OP OP;
	struct $13IRTACVREG_GRP VR;
	struct $13IRTACVREG_GRP V1;
	struct $13IRTACVREG_GRP V2;
	struct $8FBSYMBOL* EX1;
	int64 EX2;
	char* EX3;
};
__FB_STATIC_ASSERT( sizeof( struct $5IRTAC ) == 256 );
struct $6IRVREG {
	$15IRVREGTYPE_ENUM TYP;
	$11FB_DATATYPE DTYPE;
	struct $8FBSYMBOL* SUBTYPE;
	int64 REG;
	$12IR_REGFAMILY REGFAMILY;
	int64 VECTOR;
	union $7FBVALUE VALUE;
	struct $8FBSYMBOL* SYM;
	int64 OFS;
	int64 MULT;
	struct $6IRVREG* VIDX;
	struct $6IRVREG* VAUX;
	struct $9IRTACVREG* TACVHEAD;
	struct $9IRTACVREG* TACVTAIL;
	struct $5IRTAC* TACLAST;
};
__FB_STATIC_ASSERT( sizeof( struct $6IRVREG ) == 120 );
struct $8EXPRNODE;
struct $8EXPRNODE {
	int64 CLASS;
	int64 DTYPE;
	struct $8FBSYMBOL* SUBTYPE;
	struct $8EXPRNODE* L;
	struct $8EXPRNODE* R;
	union {
		char* TEXT;
		union $7FBVALUE VAL;
		struct $8FBSYMBOL* SYM;
		int64 OP;
	};
};
__FB_STATIC_ASSERT( sizeof( struct $8EXPRNODE ) == 48 );
typedef int64 $11AST_OPFLAGS;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
struct $13EXPRCACHENODE {
	int64 VREGID;
	struct $8EXPRNODE* EXPR;
};
__FB_STATIC_ASSERT( sizeof( struct $13EXPRCACHENODE ) == 16 );
typedef int64 $10IR_EMITOPT;
struct $9IRCALLARG {
	struct $8FBSYMBOL* PARAM;
	struct $6IRVREG* VR;
	int64 LEVEL;
};
__FB_STATIC_ASSERT( sizeof( struct $9IRCALLARG ) == 24 );
int32 fb_FileOpen( FBSTRING*, uint32, uint32, uint32, int32, int32 );
int32 fb_FileClose( int32 );
int32 fb_FilePutStrLarge( int32, int64, void*, int64 );
int32 fb_FileFree( void );
int32 fb_FileKill( FBSTRING* );
void free( void* );
FBSTRING* fb_StrInit( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
FBSTRING* fb_StrConcatByref( void*, int64, void*, int64, int32 );
int32 fb_StrCompare( void*, int64, void*, int64 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAllocTempResult( FBSTRING* );
FBSTRING* fb_StrAllocTempDescZ( char* );
FBSTRING* fb_StrAllocTempDescZEx( char*, int64 );
FBSTRING* fb_UIntToStr( uint32 );
FBSTRING* fb_LongintToStr( int64 );
FBSTRING* fb_ULongintToStr( uint64 );
FBSTRING* fb_StrFill2( int64, FBSTRING* );
int64 fb_StrLen( void*, int64 );
FBSTRING* fb_CHR( int32, ... );
FBSTRING* fb_TRIM( FBSTRING* );
FBSTRING* fb_HEXEx_l( uint64, int32 );
FBSTRING* fb_LEFT( FBSTRING*, int64 );
void fb_LEFTSELF( FBSTRING*, int64 );
FBSTRING* fb_RIGHT( FBSTRING*, int64 );
FBSTRING* fb_SPACE( int64 );
static void fb_ctor__irzhlc( void ) __attribute__(( constructor ));
void LISTINIT( struct $5TLIST*, int64, int64, $10LIST_FLAGS );
void LISTEND( struct $5TLIST* );
void* LISTNEWNODE( struct $5TLIST* );
void LISTDELNODE( struct $5TLIST*, void* );
void* LISTGETHEAD( struct $5TLIST* );
void* LISTGETTAIL( struct $5TLIST* );
void* LISTGETPREV( void* );
void* LISTGETNEXT( void* );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
int64 FBGETOPTION( int64 );
int64 FBIS64BIT( void );
int64 FBGETCPUFAMILY( void );
int64 TYPECALCNATURALALIGN( int64, struct $8FBSYMBOL* );
void _Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
int64 SYMBPROCRETURNSONSTACK( struct $8FBSYMBOL* );
int64 SYMBPROCCALCSTDCALLSUFFIXN( struct $8FBSYMBOL* );
void SYMBGETREALTYPE( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
int64 SYMBHASDTOR( struct $8FBSYMBOL* );
int64 SYMBISDATADESC( struct $8FBSYMBOL* );
$19FB_CVA_LIST_TYPEDEF SYMBGETVALISTTYPE( int64, struct $8FBSYMBOL* );
int64 TYPETOUNSIGNED( int64 );
char* SYMBUNIQUEID( boolean );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETFIRSTFIELD( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETNEXTFIELD( struct $8FBSYMBOL* );
int64 SYMBGETSTRLENGTH( struct $8FBSYMBOL* );
int64 SYMBGETWSTRLENGTH( struct $8FBSYMBOL* );
void SYMBFOREACHGLOBAL( int64, tmp$43 );
int64 HFILEEXISTS( char* );
FBSTRING* HFLOATTOHEX_C99( double );
char* ZSTRDUP( char* );
char* HUNESCAPE( char*, int64* );
uint32* HUNESCAPEW( uint32*, int64* );
FBSTRING* HREPLACE( char*, char*, char* );
int64 HCHARNEEDSESCAPING( int64, int64 );
int64 HISVALIDHEXDIGIT( int64 );
void IRHLINIT( void );
void IRHLEND( void );
void IRHLEMITPROCBEGIN( void );
void IRHLEMITPROCEND( void );
void IRHLEMITPUSHARG( struct $8FBSYMBOL*, struct $6IRVREG*, int64, int64, struct $6IRVREG* );
struct $6IRVREG* IRHLALLOCVREG( int64, struct $8FBSYMBOL* );
struct $6IRVREG* IRHLALLOCVRIMM( int64, struct $8FBSYMBOL*, int64 );
struct $6IRVREG* IRHLALLOCVRIMMF( int64, struct $8FBSYMBOL*, double );
struct $6IRVREG* IRHLALLOCVRVAR( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
struct $6IRVREG* IRHLALLOCVRIDX( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64, int64, struct $6IRVREG* );
struct $6IRVREG* IRHLALLOCVRPTR( int64, struct $8FBSYMBOL*, int64, struct $6IRVREG* );
struct $6IRVREG* IRHLALLOCVROFS( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
void IRFOREACHDATASTMT( tmp$43 );
void IRHLFLUSHSTATICINITIALIZER( struct $8FBSYMBOL* );
static void _ZN12SECTIONENTRYC1Ev( struct $12SECTIONENTRY* );
static void _ZN12SECTIONENTRYaSERKS_( struct $12SECTIONENTRY*, struct $12SECTIONENTRY* );
static void _ZN12SECTIONENTRYD1Ev( struct $12SECTIONENTRY* );
static void _ZN8IRHLCCTXC1Ev( struct $8IRHLCCTX* );
static void _ZN8IRHLCCTXaSERKS_( struct $8IRHLCCTX*, struct $8IRHLCCTX* );
static void _ZN8IRHLCCTXD1Ev( struct $8IRHLCCTX* );
static FBSTRING* HEMITTYPE( int64, struct $8FBSYMBOL* );
static void HEMITSTRUCT( struct $8FBSYMBOL*, int64 );
static void _EMITDBG( int64, struct $8FBSYMBOL*, int64, char* );
static void EXPRFREENODE( struct $8EXPRNODE* );
static void _INIT( void );
static void _END( void );
static void SECTIONBEGIN( void );
static void SECTIONWRITELINE( FBSTRING* );
static void SECTIONINDENT( void );
static void SECTIONUNINDENT( void );
static int64 SECTIONINSIDEPROC( void );
static void SECTIONEND( void );
static int64 SECTIONGOSUB( int64 );
static void SECTIONRETURN( int64 );
static void HWRITELINE( FBSTRING*, int64 );
static void HUPDATECURRENTFILENAME( char* );
static void HWRITESTATICASSERT( FBSTRING* );
static void HAPPENDCTORATTRIB( FBSTRING*, struct $8FBSYMBOL*, int64 );
static FBSTRING* HGETMANGLEDNAMEFORASM( struct $8FBSYMBOL*, int64 );
static int64 HNEEDALIAS( struct $8FBSYMBOL* );
static FBSTRING* HEMITPROCHEADER( struct $8FBSYMBOL*, $16EMITPROC_OPTIONS );
static FBSTRING* HGETUDTTAG( struct $8FBSYMBOL* );
static FBSTRING* HGETUDTID( struct $8FBSYMBOL* );
static FBSTRING* HGETUDTNAME( struct $8FBSYMBOL* );
static void HEMITUDT( struct $8FBSYMBOL*, int64 );
static FBSTRING* HEMITARRAYDECL( struct $8FBSYMBOL* );
static void HEMITVARDECL( int64, struct $8FBSYMBOL*, char* );
static void HMAYBEEMITLOCALVAR( struct $8FBSYMBOL* );
static void HALLOCGLOBALVAR( struct $8FBSYMBOL* );
static void HMAYBEEMITGLOBALVAR( struct $8FBSYMBOL* );
static void HMAYBEEMITGLOBALVAREXCEPTDATASTMT( struct $8FBSYMBOL* );
static void HMAYBEEMITPROCPROTO( struct $8FBSYMBOL* );
static void HEMITFIELDTYPES( struct $8FBSYMBOL* );
static struct $8FBSYMBOL** HFINDPARENTANONALREADYONSTACK( struct $8FBSYMBOL* );
static void HPUSHANONPARENTS( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void HPOPANONPARENTS( struct $8FBSYMBOL** );
static void HEMITSTRUCTWITHFIELDS( struct $8FBSYMBOL* );
static void HWRITEX86F2I( FBSTRING*, int64, int64 );
static void HWRITEGENERICF2I( FBSTRING*, int64, int64 );
static void HWRITEF2I( FBSTRING*, int64, int64 );
static void HMAYBEEMITPROCEXPORT( struct $8FBSYMBOL* );
static int64 _EMITBEGIN( void );
static void _EMITEND( void );
static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE );
static int64 _SUPPORTSOP( int64, int64 );
static void _PROCBEGIN( struct $8FBSYMBOL* );
static void _PROCEND( struct $8FBSYMBOL* );
static void _SCOPEBEGIN( struct $8FBSYMBOL* );
static void _SCOPEEND( struct $8FBSYMBOL* );
static int64 HISSTATICWITHDTOR( struct $8FBSYMBOL* );
static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* );
static void _SETVREGDATATYPE( struct $6IRVREG*, int64, struct $8FBSYMBOL* );
static struct $8EXPRNODE* EXPRNEW( int64, int64, struct $8FBSYMBOL* );
static void EXPRFREETREE( struct $8EXPRNODE* );
static struct $8EXPRNODE* EXPRNEWTEXT( int64, struct $8FBSYMBOL*, char* );
static struct $8EXPRNODE* EXPRNEWIMMI( int64, int64 );
static struct $8EXPRNODE* EXPRNEWIMMF( double, int64 );
static int64 SYMBISCARRAY( struct $8FBSYMBOL* );
static struct $8EXPRNODE* EXPRNEWCAST( int64, struct $8FBSYMBOL*, struct $8EXPRNODE* );
static struct $8EXPRNODE* EXPRNEWMACRO( $6AST_OP, int64, struct $8FBSYMBOL*, struct $8EXPRNODE*, struct $8EXPRNODE* );
static struct $8EXPRNODE* EXPRNEWSYM( struct $8FBSYMBOL* );
static int64 TYPECBOP( int64, int64, int64 );
static struct $8EXPRNODE* EXPRNEWUOP( int64, struct $8EXPRNODE* );
static struct $8EXPRNODE* EXPRNEWBOP( int64, struct $8EXPRNODE*, struct $8EXPRNODE* );
static void EXPRCACHE( int64, struct $8EXPRNODE* );
static struct $8EXPRNODE* EXPRLOOKUP( int64 );
static FBSTRING* HEMITINT( int64, int64 );
static FBSTRING* HEMITFLOAT( int64, double );
static void HBUILDSTRLIT( FBSTRING*, char*, int64, int64 );
static void HBUILDWSTRLIT( FBSTRING*, uint32*, int64 );
static char* HBOPTOSTR( int64 );
static char* HUOPTOSTR( int64, int64, int64* );
static void HIMM2TEXT( FBSTRING*, struct $8EXPRNODE* );
static void HSYM2TEXT( FBSTRING*, struct $8FBSYMBOL* );
static void HEXPRFLUSH( struct $8EXPRNODE*, int64 );
static FBSTRING* EXPRFLUSH( struct $8EXPRNODE*, int64 );
static struct $8EXPRNODE* EXPRNEWOFFSET( struct $8FBSYMBOL*, int64 );
static struct $8EXPRNODE* EXPRNEWVREG( struct $6IRVREG*, int64 );
static void _EMITLABEL( struct $8FBSYMBOL* );
static void EXPRSTORE( struct $6IRVREG*, struct $8EXPRNODE*, int64 );
static void _EMITBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void _EMITUOP( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITCONVERT( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSTORE( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSPILLREGS( void );
static void _EMITLOAD( struct $6IRVREG* );
static void _EMITLOADRES( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITADDR( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HDOCALL( FBSTRING*, int64, struct $6IRVREG*, int64 );
static void _EMITCALL( struct $8FBSYMBOL*, int64, struct $6IRVREG*, int64 );
static void _EMITCALLPTR( struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITJUMPPTR( struct $6IRVREG* );
static void _EMITBRANCH( int64, struct $8FBSYMBOL* );
static void _EMITJMPTB( struct $6IRVREG*, struct $8FBSYMBOL*, uint64*, struct $8FBSYMBOL**, int64, struct $8FBSYMBOL*, uint64, uint64 );
static void _EMITMEM( int64, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITMACRO( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITDECL( struct $8FBSYMBOL* );
static void _EMITCOMMENT( char* );
static int32 HFINDLABELINSEENLIST( struct $5TLIST*, struct $8FBSYMBOL* );
static void _EMITASMLINE( struct $9ASTASMTOK* );
static void _EMITVARINIBEGIN( struct $8FBSYMBOL* );
static void _EMITVARINIEND( struct $8FBSYMBOL* );
static void HVARINISEPARATOR( void );
static void _EMITVARINII( struct $8FBSYMBOL*, int64 );
static void _EMITVARINIF( struct $8FBSYMBOL*, double );
static void _EMITVARINIOFS( struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
static void _EMITVARINISTR( int64, char*, int64, int64 );
static void _EMITVARINIWSTR( int64, uint32*, int64 );
static void _EMITVARINIPAD( int64, int64 );
static void _EMITVARINISCOPEBEGIN( struct $8FBSYMBOL*, int64 );
static void _EMITVARINISCOPEEND( void );
static void _EMITFBCTINFBEGIN( void );
static void _EMITFBCTINFSTRING( char* );
static void _EMITFBCTINFEND( void );
static void _EMITPROCBEGIN( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _EMITPROCEND( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _EMITSCOPEBEGIN( struct $8FBSYMBOL* );
static void _EMITSCOPEEND( struct $8FBSYMBOL* );
static void _GLOBAL__I( void ) __attribute__(( constructor ));
static void _GLOBAL__D( void ) __attribute__(( destructor ));
typedef void (*tmp$39)( void );
typedef int64 (*tmp$40)( void );
typedef int64 (*tmp$41)( $14IR_OPTIONVALUE );
typedef int64 (*tmp$42)( int64, int64 );
typedef void (*tmp$44)( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
typedef char* (*tmp$45)( void );
typedef void (*tmp$46)( struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$47)( int64 );
typedef void (*tmp$48)( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
typedef void (*tmp$49)( struct $8FBSYMBOL*, struct $6IRVREG*, int64, int64, struct $6IRVREG* );
typedef void (*tmp$50)( struct $9ASTASMTOK* );
typedef void (*tmp$51)( char* );
typedef void (*tmp$52)( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
typedef void (*tmp$53)( int64, struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$54)( struct $6IRVREG* );
typedef void (*tmp$55)( struct $8FBSYMBOL*, int64, struct $6IRVREG*, int64 );
typedef void (*tmp$56)( struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
typedef void (*tmp$57)( int64, struct $8FBSYMBOL* );
typedef void (*tmp$58)( struct $6IRVREG*, struct $8FBSYMBOL*, uint64*, struct $8FBSYMBOL**, int64, struct $8FBSYMBOL*, uint64, uint64 );
typedef void (*tmp$59)( int64, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
typedef void (*tmp$60)( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$61)( int64, struct $8FBSYMBOL*, int64, char* );
typedef void (*tmp$62)( struct $8FBSYMBOL*, int64 );
typedef void (*tmp$63)( struct $8FBSYMBOL*, double );
typedef void (*tmp$64)( struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
typedef void (*tmp$65)( int64, char*, int64, int64 );
typedef void (*tmp$66)( int64, uint32*, int64 );
typedef void (*tmp$67)( int64, int64 );
typedef void (*tmp$68)( struct $8FBSYMBOL*, int64 );
typedef void (*tmp$69)( char* );
typedef struct $6IRVREG* (*tmp$70)( int64, struct $8FBSYMBOL* );
typedef struct $6IRVREG* (*tmp$71)( int64, struct $8FBSYMBOL*, int64 );
typedef struct $6IRVREG* (*tmp$72)( int64, struct $8FBSYMBOL*, double );
typedef struct $6IRVREG* (*tmp$73)( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
typedef struct $6IRVREG* (*tmp$74)( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64, int64, struct $6IRVREG* );
typedef struct $6IRVREG* (*tmp$75)( int64, struct $8FBSYMBOL*, int64, struct $6IRVREG* );
typedef void (*tmp$76)( struct $6IRVREG*, int64, struct $8FBSYMBOL* );
typedef uint64 (*tmp$77)( struct $6IRVREG* );
struct $7IR_VTBL {
	tmp$39 INIT;
	tmp$39 END;
	tmp$40 EMITBEGIN;
	tmp$39 EMITEND;
	tmp$41 GETOPTIONVALUE;
	tmp$42 SUPPORTSOP;
	tmp$43 PROCBEGIN;
	tmp$43 PROCEND;
	tmp$44 PROCALLOCARG;
	tmp$44 PROCALLOCLOCAL;
	tmp$45 PROCGETFRAMEREGNAME;
	tmp$43 SCOPEBEGIN;
	tmp$43 SCOPEEND;
	tmp$43 PROCALLOCSTATICVARS;
	tmp$46 EMITCONVERT;
	tmp$43 EMITLABEL;
	tmp$43 EMITLABELNF;
	tmp$47 EMITRETURN;
	tmp$44 EMITPROCBEGIN;
	tmp$48 EMITPROCEND;
	tmp$49 EMITPUSHARG;
	tmp$50 EMITASMLINE;
	tmp$51 EMITCOMMENT;
	tmp$52 EMITBOP;
	tmp$53 EMITUOP;
	tmp$46 EMITSTORE;
	tmp$39 EMITSPILLREGS;
	tmp$54 EMITLOAD;
	tmp$46 EMITLOADRES;
	tmp$53 EMITSTACK;
	tmp$53 EMITADDR;
	tmp$55 EMITCALL;
	tmp$56 EMITCALLPTR;
	tmp$47 EMITSTACKALIGN;
	tmp$54 EMITJUMPPTR;
	tmp$57 EMITBRANCH;
	tmp$58 EMITJMPTB;
	tmp$59 EMITMEM;
	tmp$60 EMITMACRO;
	tmp$43 EMITSCOPEBEGIN;
	tmp$43 EMITSCOPEEND;
	tmp$43 EMITDECL;
	tmp$61 EMITDBG;
	tmp$43 EMITVARINIBEGIN;
	tmp$43 EMITVARINIEND;
	tmp$62 EMITVARINII;
	tmp$63 EMITVARINIF;
	tmp$64 EMITVARINIOFS;
	tmp$65 EMITVARINISTR;
	tmp$66 EMITVARINIWSTR;
	tmp$67 EMITVARINIPAD;
	tmp$68 EMITVARINISCOPEBEGIN;
	tmp$39 EMITVARINISCOPEEND;
	tmp$39 EMITFBCTINFBEGIN;
	tmp$69 EMITFBCTINFSTRING;
	tmp$39 EMITFBCTINFEND;
	tmp$70 ALLOCVREG;
	tmp$71 ALLOCVRIMM;
	tmp$72 ALLOCVRIMMF;
	tmp$73 ALLOCVRVAR;
	tmp$74 ALLOCVRIDX;
	tmp$75 ALLOCVRPTR;
	tmp$73 ALLOCVROFS;
	tmp$76 SETVREGDATATYPE;
	tmp$77 GETDISTANCE;
	tmp$53 LOADVR;
	tmp$46 STOREVR;
	tmp$47 XCHGTOS;
};
__FB_STATIC_ASSERT( sizeof( struct $7IR_VTBL ) == 544 );
extern struct $7IR_VTBL IRHLC_VTBL$;
struct $5IRCTX {
	struct $7IR_VTBL VTBL;
	$6IR_OPT OPTIONS;
};
__FB_STATIC_ASSERT( sizeof( struct $5IRCTX ) == 552 );
extern struct $5IRCTX IR$;
extern struct $10AST_OPINFO AST_OPTB$[122];
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $8FBARRAY1I10AST_OPINFOE {
	struct $10AST_OPINFO* DATA;
	struct $10AST_OPINFO* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1I10AST_OPINFOE ) == 72 );
static struct $8FBARRAY1I10AST_OPINFOE tmp$82$;
struct $12FBHASHTBLIST {
	struct $8FBHASHTB* HEAD;
	struct $8FBHASHTB* TAIL;
};
__FB_STATIC_ASSERT( sizeof( struct $12FBHASHTBLIST ) == 16 );
struct $8TSTACKTB;
struct $10TSTACKNODE;
struct $10TSTACKNODE {
	struct $10TSTACKNODE* PREV;
	struct $10TSTACKNODE* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10TSTACKNODE ) == 16 );
struct $8TSTACKTB {
	struct $8TSTACKTB* NEXT;
	struct $10TSTACKNODE* NODETB;
	int64 NODES;
};
__FB_STATIC_ASSERT( sizeof( struct $8TSTACKTB ) == 24 );
struct $6TSTACK {
	struct $8TSTACKTB* TBHEAD;
	struct $8TSTACKTB* TBTAIL;
	int64 NODES;
	int64 NODELEN;
	struct $10TSTACKNODE* TOS;
	int64 CLEAR;
};
__FB_STATIC_ASSERT( sizeof( struct $6TSTACK ) == 48 );
struct $5TPOOL {
	int64 CHUNKS;
	int64 CHUNKSIZE;
	struct $5TLIST* CHUNKTB;
};
__FB_STATIC_ASSERT( sizeof( struct $5TPOOL ) == 24 );
struct $17SYMB_DEF_UNIQUEID {
	struct $5THASH DICT;
};
__FB_STATIC_ASSERT( sizeof( struct $17SYMB_DEF_UNIQUEID ) == 24 );
struct $14SYMB_DEF_PARAM {
	struct $8HASHITEM* ITEM;
	uint64 INDEX;
};
__FB_STATIC_ASSERT( sizeof( struct $14SYMB_DEF_PARAM ) == 16 );
struct $12SYMB_DEF_CTX {
	struct $5TLIST PARAMLIST;
	struct $5TLIST TOKLIST;
	struct $17SYMB_DEF_UNIQUEID UNIQUEID;
	int64 PARAM;
	struct $5THASH PARAMHASH;
	struct $14SYMB_DEF_PARAM HASH[32];
};
__FB_STATIC_ASSERT( sizeof( struct $12SYMB_DEF_CTX ) == 696 );
struct $20FB_GLOBCTORLIST_ITEM;
struct $20FB_GLOBCTORLIST_ITEM {
	struct $8FBSYMBOL* SYM;
	struct $20FB_GLOBCTORLIST_ITEM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $20FB_GLOBCTORLIST_ITEM ) == 16 );
struct $15FB_GLOBCTORLIST {
	struct $20FB_GLOBCTORLIST_ITEM* HEAD;
	struct $20FB_GLOBCTORLIST_ITEM* TAIL;
	struct $5TLIST LIST;
};
__FB_STATIC_ASSERT( sizeof( struct $15FB_GLOBCTORLIST ) == 80 );
struct $10SYMB_OVLOP {
	struct $8FBSYMBOL* HEAD;
};
__FB_STATIC_ASSERT( sizeof( struct $10SYMB_OVLOP ) == 8 );
struct $10FB_RTTICTX {
	struct $8FBSYMBOL* FB_RTTI;
	struct $8FBSYMBOL* FB_OBJECT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FB_RTTICTX ) == 16 );
struct $7SYMBCTX {
	int64 INITED;
	struct $5TLIST SYMLIST;
	struct $12FBHASHTBLIST HASHLIST;
	struct $10FBSYMCHAIN CHAINPOOL[4096];
	int64 CHAINPOOLHEAD;
	struct $8FBSYMBOL GLOBNSPC;
	struct $8FBSYMBOL* NAMESPC;
	struct $8FBHASHTB* HASHTB;
	struct $10FBSYMBOLTB* SYMTB;
	struct $6TSTACK NESTSTK;
	struct $5THASH IMPHASHTB;
	struct $5TLIST IMPHASHLIST;
	struct $5TPOOL NAMEPOOL;
	struct $5TLIST FWDLIST;
	struct $5TLIST NSEXTLIST;
	int64 FWDREFCNT;
	struct $12SYMB_DEF_CTX DEF;
	struct $8FBSYMBOL* LASTLBL;
	struct $15FB_GLOBCTORLIST GLOBCTORLIST;
	struct $15FB_GLOBCTORLIST GLOBDTORLIST;
	struct $10SYMB_OVLOP GLOBOPOVLTB[122];
	int64 FBARRAY_DATA;
	int64 FBARRAY_PTR;
	int64 FBARRAY_SIZE;
	int64 FBARRAY_DIMTB;
	struct $8FBSYMBOL* FBARRAYDIM;
	int64 FBARRAYDIM_LBOUND;
	int64 FBARRAYDIM_UBOUND;
	struct $10FB_RTTICTX RTTI;
};
__FB_STATIC_ASSERT( sizeof( struct $7SYMBCTX ) == 199256 );
extern struct $7SYMBCTX SYMB$;
extern struct $13SYMB_DATATYPE SYMB_DTYPETB$[26];
struct $8FBARRAY1I13SYMB_DATATYPEE {
	struct $13SYMB_DATATYPE* DATA;
	struct $13SYMB_DATATYPE* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1I13SYMB_DATATYPEE ) == 72 );
static struct $8FBARRAY1I13SYMB_DATATYPEE tmp$83$;
struct $8FBARRAY2IlE {
	int64* DATA;
	int64* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[2];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY2IlE ) == 96 );
static struct $8FBARRAY2IlE tmp$84$;
typedef int64 $10FB_OUTTYPE;
typedef int64 $10FB_BACKEND;
typedef int64 $10FB_CPUTYPE;
typedef int64 $10FB_FPUTYPE;
typedef int64 $9FB_FPMODE;
typedef int64 $17FB_VECTORIZELEVEL;
typedef int64 $12FB_ASMSYNTAX;
typedef int64 $7FB_LANG;
typedef int64 $10FB_PDCHECK;
typedef int64 $11FB_MODEVIEW;
struct $12FBCMMLINEOPT {
	$10FB_OUTTYPE OUTTYPE;
	int64 PPONLY;
	$10FB_BACKEND BACKEND;
	$13FB_COMPTARGET TARGET;
	$10FB_CPUTYPE CPUTYPE;
	$10FB_FPUTYPE FPUTYPE;
	$9FB_FPMODE FPMODE;
	$17FB_VECTORIZELEVEL VECTORIZE;
	int64 OPTLEVEL;
	$12FB_ASMSYNTAX ASMSYNTAX;
	$7FB_LANG LANG;
	int64 FORCELANG;
	int64 DEBUG;
	int64 DEBUGINFO;
	int64 ASSERTIONS;
	int64 ERRORCHECK;
	int64 RESUMEERR;
	int64 EXTRAERRCHK;
	int64 ERRLOCATION;
	int64 ARRAYBOUNDCHK;
	int64 ARRAYDIMSCHK;
	int64 NULLPTRCHK;
	int64 UNWINDINFO;
	int64 PROFILE;
	int64 WARNINGLEVEL;
	int64 SHOWERROR;
	int64 MAXERRORS;
	$10FB_PDCHECK PDCHECKOPT;
	int64 GOSUBSETJMP;
	int64 VALISTASPTR;
	int64 NOTHISCALL;
	int64 NOFASTCALL;
	int64 FBRT;
	int64 EXPORT;
	int64 MSBITFIELDS;
	int64 MULTITHREADED;
	int64 FBGFX;
	int64 PIC;
	int64 STACKSIZE;
	int64 OBJINFO;
	int64 SHOWINCLUDES;
	$11FB_MODEVIEW MODEVIEW;
	int64 NOCMDLINE;
	int64 RETURNINFLTS;
	int64 NOBUILTINS;
	int64 OPTABSTRACT;
};
__FB_STATIC_ASSERT( sizeof( struct $12FBCMMLINEOPT ) == 368 );
typedef int64 $12FB_TARGETOPT;
struct $8FBTARGET {
	char* ID;
	$11FB_DATATYPE WCHAR;
	$11FB_FUNCMODE FBCALL;
	$11FB_FUNCMODE STDCALL;
	$12FB_TARGETOPT OPTIONS;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBTARGET ) == 40 );
typedef int64 $12FB_WCHARCONV;
typedef int64 $13FBFILE_FORMAT;
struct $6FBFILE {
	int64 NUM;
	char NAME[261];
	char* INCFILE;
	int64 ISMAIN;
	$13FBFILE_FORMAT FORMAT;
};
__FB_STATIC_ASSERT( sizeof( struct $6FBFILE ) == 296 );
struct $6FBMAIN {
	struct $8FBSYMBOL* PROC;
	struct $7ASTNODE* INITNODE;
};
__FB_STATIC_ASSERT( sizeof( struct $6FBMAIN ) == 16 );
typedef int64 $11FB_LANG_OPT;
struct $11FB_LANG_CTX {
	$11FB_LANG_OPT OPT;
	$11FB_DATATYPE INTEGERKEYWORDDTYPE;
	$11FB_DATATYPE INT15LITERALDTYPE;
	$11FB_DATATYPE INT16LITERALDTYPE;
	$11FB_DATATYPE INT31LITERALDTYPE;
	$11FB_DATATYPE INT32LITERALDTYPE;
	$11FB_DATATYPE INT63LITERALDTYPE;
	$11FB_DATATYPE INT64LITERALDTYPE;
	$11FB_DATATYPE FLOATLITERALDTYPE;
};
__FB_STATIC_ASSERT( sizeof( struct $11FB_LANG_CTX ) == 72 );
struct $8FBOPTION {
	int64 BASE;
	int64 PARAMMODE;
	int64 EXPLICIT;
	int64 PROCPUBLIC;
	int64 PROCPROFILE;
	int64 ESCAPESTR;
	int64 DYNAMIC;
	int64 GOSUB;
};
__FB_STATIC_ASSERT( sizeof( struct $8FBOPTION ) == 64 );
typedef int64 $16FB_RESTART_FLAGS;
struct $7TSTRSET {
	struct $5TLIST LIST;
	struct $5THASH HASH;
};
__FB_STATIC_ASSERT( sizeof( struct $7TSTRSET ) == 88 );
struct $5FBENV {
	struct $5TLIST PREDEFINES;
	struct $5TLIST PREINCLUDES;
	struct $5TLIST INCLUDEPATHS;
	struct $12FBCMMLINEOPT CLOPT;
	struct $8FBTARGET TARGET;
	$12FB_WCHARCONV WCHARCONV;
	int64 UNDERSCOREPREFIX;
	int64 POINTERSIZE;
	struct $6FBFILE INF;
	struct $6FBFILE OUTF;
	int64 PPFILE_NUM;
	struct $5THASH FILENAMEHASH;
	struct $5THASH INCFILEHASH;
	struct $5THASH INCONCEHASH;
	int64 INCLUDEREC;
	char ENTRY[128];
	struct $6FBMAIN MAIN;
	struct $11FB_LANG_CTX LANG;
	struct $8FBOPTION OPT;
	int64 INITED;
	int64 MODULE_COUNT;
	$16FB_RESTART_FLAGS RESTART_REQUEST;
	$16FB_RESTART_FLAGS RESTART_ACTION;
	$16FB_RESTART_FLAGS RESTART_STATUS;
	int64 RESTART_COUNT;
	$7FB_LANG RESTART_LANG;
	struct $7TSTRSET LIBS;
	struct $7TSTRSET LIBPATHS;
	int64 FBCTINF_STARTED;
};
__FB_STATIC_ASSERT( sizeof( struct $5FBENV ) == 1824 );
extern struct $5FBENV ENV$;
struct $7LEX_CTX {
	struct $9LEX_TKCTX CTXTB[17];
	struct $9LEX_TKCTX* CTX;
	int64 INSIDEMACRO;
};
__FB_STATIC_ASSERT( sizeof( struct $7LEX_CTX ) == 844712 );
extern struct $7LEX_CTX LEX$;
struct $10TFLISTITEM;
struct $10TFLISTITEM {
	struct $10TFLISTITEM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10TFLISTITEM ) == 8 );
struct $6TFLIST {
	int64 TOTITEMS;
	int64 ITEMS;
	struct $10TFLISTITEM* ITEMTB;
	int64 INDEX;
	struct $10TFLISTITEM* LASTITEM;
	struct $5TLIST LIST;
	struct $7TLISTTB* LISTTB;
};
__FB_STATIC_ASSERT( sizeof( struct $6TFLIST ) == 112 );
struct $11IRHLCONTEXT {
	int64 REGCOUNT;
	struct $6TFLIST VREGS;
	struct $5TLIST CALLARGS;
};
__FB_STATIC_ASSERT( sizeof( struct $11IRHLCONTEXT ) == 184 );
extern struct $11IRHLCONTEXT IRHL$;
static struct $8IRHLCCTX CTX$;
static char* DTYPENAME$[26] = { (char*)"void", (char*)"boolean", (char*)"int8", (char*)"uint8", (char*)"char", (char*)"int16", (char*)"uint16", (char*)0ull, (char*)0ull, (char*)0ull, (char*)0ull, (char*)"int32", (char*)"uint32", (char*)"int64", (char*)"uint64", (char*)"float", (char*)"double", (char*)"FBSTRING", (char*)0ull, (char*)"__builtin_va_list", (char*)0ull, (char*)0ull, (char*)0ull, (char*)"void", (char*)0ull };
struct $7IR_VTBL IRHLC_VTBL$ = { (tmp$39)&_INIT, (tmp$39)&_END, (tmp$40)&_EMITBEGIN, (tmp$39)&_EMITEND, (tmp$41)&_GETOPTIONVALUE, (tmp$42)&_SUPPORTSOP, (tmp$43)&_PROCBEGIN, (tmp$43)&_PROCEND, (tmp$44)0ull, (tmp$44)0ull, (tmp$45)0ull, (tmp$43)&_SCOPEBEGIN, (tmp$43)&_SCOPEEND, (tmp$43)&_PROCALLOCSTATICVARS, (tmp$46)&_EMITCONVERT, (tmp$43)&_EMITLABEL, (tmp$43)&_EMITLABEL, (tmp$47)0ull, (tmp$44)&_EMITPROCBEGIN, (tmp$48)&_EMITPROCEND, (tmp$49)&IRHLEMITPUSHARG, (tmp$50)&_EMITASMLINE, (tmp$51)&_EMITCOMMENT, (tmp$52)&_EMITBOP, (tmp$53)&_EMITUOP, (tmp$46)&_EMITSTORE, (tmp$39)&_EMITSPILLREGS, (tmp$54)&_EMITLOAD, (tmp$46)&_EMITLOADRES, (tmp$53)0ull, (tmp$53)&_EMITADDR, (tmp$55)&_EMITCALL, (tmp$56)&_EMITCALLPTR, (tmp$47)0ull, (tmp$54)&_EMITJUMPPTR, (tmp$57)&_EMITBRANCH, (tmp$58)&_EMITJMPTB, (tmp$59)&_EMITMEM, (tmp$60)&_EMITMACRO, (tmp$43)&_EMITSCOPEBEGIN, (tmp$43)&_EMITSCOPEEND, (tmp$43)&_EMITDECL, (tmp$61)&_EMITDBG, (tmp$43)&_EMITVARINIBEGIN, (tmp$43)&_EMITVARINIEND, (tmp$62)&_EMITVARINII, (tmp$63)&_EMITVARINIF, (tmp$64)&_EMITVARINIOFS, (tmp$65)&_EMITVARINISTR, (tmp$66)&_EMITVARINIWSTR, (tmp$67)&_EMITVARINIPAD, (tmp$68)&_EMITVARINISCOPEBEGIN, (tmp$39)&_EMITVARINISCOPEEND, (tmp$39)&_EMITFBCTINFBEGIN, (tmp$69)&_EMITFBCTINFSTRING, (tmp$39)&_EMITFBCTINFEND, (tmp$70)&IRHLALLOCVREG, (tmp$71)&IRHLALLOCVRIMM, (tmp$72)&IRHLALLOCVRIMMF, (tmp$73)&IRHLALLOCVRVAR, (tmp$74)&IRHLALLOCVRIDX, (tmp$75)&IRHLALLOCVRPTR, (tmp$73)&IRHLALLOCVROFS, (tmp$76)&_SETVREGDATATYPE, (tmp$77)0ull, (tmp$53)0ull, (tmp$46)0ull, (tmp$47)0ull };

__attribute__(( constructor )) static void fb_ctor__irzhlc( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM* THIS$1, struct $11TSTRSETITEM* __FB_RHS__$1 )
{
	label$4:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 24ll) = *(int64*)((uint8*)__FB_RHS__$1 + 24ll);
	*(struct $8HASHITEM**)((uint8*)THIS$1 + 32ll) = *(struct $8HASHITEM**)((uint8*)__FB_RHS__$1 + 32ll);
	label$5:;
}

static void _ZN12SECTIONENTRYC1Ev( struct $12SECTIONENTRY* THIS$1 )
{
	__builtin_memset( (FBSTRING*)THIS$1, 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 24ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 32ll), 0, 8ll );
	label$10:;
	label$11:;
}

static void _ZN12SECTIONENTRYaSERKS_( struct $12SECTIONENTRY* THIS$1, struct $12SECTIONENTRY* __FB_RHS__$1 )
{
	label$12:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 24ll) = *(int64*)((uint8*)__FB_RHS__$1 + 24ll);
	*(int64*)((uint8*)THIS$1 + 32ll) = *(int64*)((uint8*)__FB_RHS__$1 + 32ll);
	label$13:;
}

static void _ZN12SECTIONENTRYD1Ev( struct $12SECTIONENTRY* THIS$1 )
{
	label$16:;
	label$17:;
	fb_StrDelete( (FBSTRING*)THIS$1 );
}

static void _ZN8IRHLCCTXC1Ev( struct $8IRHLCCTX* THIS$1 )
{
	int64 TMP$98$1;
	struct $12SECTIONENTRY* TMP$99$1;
	TMP$99$1 = (struct $12SECTIONENTRY*)THIS$1;
	TMP$98$1 = 0ll;
	label$20:;
	_ZN12SECTIONENTRYC1Ev( TMP$99$1 );
	TMP$99$1 = (struct $12SECTIONENTRY*)((uint8*)TMP$99$1 + 40ll);
	TMP$98$1 = TMP$98$1 + 1ll;
	if( TMP$98$1 != 129ll) goto label$20;
	__builtin_memset( (int64*)((uint8*)THIS$1 + 5160ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 5168ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 5176ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 5184ll), 0, 24ll );
	__builtin_memset( (uint64*)((uint8*)THIS$1 + 5208ll), 0, 8ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 5216ll), 0, 64ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 5280ll), 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 5304ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 5312ll), 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 5336ll), 0, 24ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 5360ll), 0, 64ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 5424ll), 0, 24ll );
	__builtin_memset( (struct $5TLIST*)((uint8*)THIS$1 + 5448ll), 0, 64ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 5512ll), 0, 8ll );
	label$18:;
	label$19:;
}

static void _ZN8IRHLCCTXaSERKS_( struct $8IRHLCCTX* THIS$1, struct $8IRHLCCTX* __FB_RHS__$1 )
{
	int64 TMP$100$1;
	struct $12SECTIONENTRY* TMP$101$1;
	struct $12SECTIONENTRY* TMP$102$1;
	label$21:;
	TMP$101$1 = (struct $12SECTIONENTRY*)THIS$1;
	TMP$102$1 = (struct $12SECTIONENTRY*)__FB_RHS__$1;
	TMP$100$1 = 0ll;
	label$23:;
	_ZN12SECTIONENTRYaSERKS_( TMP$101$1, (struct $12SECTIONENTRY*)TMP$102$1 );
	TMP$101$1 = (struct $12SECTIONENTRY*)((uint8*)TMP$101$1 + 40ll);
	TMP$102$1 = (struct $12SECTIONENTRY*)((uint8*)TMP$102$1 + 40ll);
	TMP$100$1 = TMP$100$1 + 1ll;
	if( TMP$100$1 != 129ll) goto label$23;
	*(int64*)((uint8*)THIS$1 + 5160ll) = *(int64*)((uint8*)__FB_RHS__$1 + 5160ll);
	*(int64*)((uint8*)THIS$1 + 5168ll) = *(int64*)((uint8*)__FB_RHS__$1 + 5168ll);
	*(int64*)((uint8*)THIS$1 + 5176ll) = *(int64*)((uint8*)__FB_RHS__$1 + 5176ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 5184ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 5184ll), -1ll, 0 );
	*(uint64*)((uint8*)THIS$1 + 5208ll) = *(uint64*)((uint8*)__FB_RHS__$1 + 5208ll);
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 5216ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 5216ll), 64 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 5280ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 5280ll), -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 5304ll) = *(int64*)((uint8*)__FB_RHS__$1 + 5304ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 5312ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 5312ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 5336ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 5336ll), -1ll, 0 );
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 5360ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 5360ll), 64 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 5424ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 5424ll), -1ll, 0 );
	__builtin_memcpy( (struct $5TLIST*)((uint8*)THIS$1 + 5448ll), (struct $5TLIST*)((uint8*)__FB_RHS__$1 + 5448ll), 64 );
	*(int64*)((uint8*)THIS$1 + 5512ll) = *(int64*)((uint8*)__FB_RHS__$1 + 5512ll);
	label$22:;
}

static void _ZN8IRHLCCTXD1Ev( struct $8IRHLCCTX* THIS$1 )
{
	int64 TMP$105$1;
	struct $12SECTIONENTRY* TMP$106$1;
	label$27:;
	label$28:;
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 5424ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 5336ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 5312ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 5280ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 5184ll) );
	TMP$106$1 = (struct $12SECTIONENTRY*)((uint8*)THIS$1 + 5120ll);
	TMP$105$1 = 0ll;
	label$29:;
	_ZN12SECTIONENTRYD1Ev( TMP$106$1 );
	TMP$106$1 = (struct $12SECTIONENTRY*)((uint8*)TMP$106$1 + -40ll);
	TMP$105$1 = TMP$105$1 + 1ll;
	if( TMP$105$1 != 129ll) goto label$29;
}

static void _INIT( void )
{
	label$30:;
	IRHLINIT(  );
	LISTINIT( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll), 8ll, 8ll, 6ll );
	LISTINIT( (struct $5TLIST*)((uint8*)&CTX$ + 5360ll), 32ll, 48ll, 7ll );
	LISTINIT( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll), 8ll, 16ll, 6ll );
	*($6IR_OPT*)((uint8*)&IR$ + 544ll) = *(int64*)((uint8*)&IR$ + 544ll) | 131074ll;
	int64 vr$4 = FBIS64BIT(  );
	if( vr$4 == 0ll) goto label$33;
	{
		*(char**)((int64)(char**)DTYPENAME$ + 64ll) = *(char**)((int64)(char**)DTYPENAME$ + 104ll);
		*(char**)((int64)(char**)DTYPENAME$ + 72ll) = *(char**)((int64)(char**)DTYPENAME$ + 112ll);
	}
	goto label$32;
	label$33:;
	{
		*(char**)((int64)(char**)DTYPENAME$ + 64ll) = *(char**)((int64)(char**)DTYPENAME$ + 88ll);
		*(char**)((int64)(char**)DTYPENAME$ + 72ll) = *(char**)((int64)(char**)DTYPENAME$ + 96ll);
	}
	label$32:;
	label$31:;
}

static void _END( void )
{
	label$34:;
	LISTEND( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll) );
	LISTEND( (struct $5TLIST*)((uint8*)&CTX$ + 5360ll) );
	LISTEND( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll) );
	IRHLEND(  );
	label$35:;
}

static void SECTIONBEGIN( void )
{
	label$36:;
	*(int64*)((uint8*)&CTX$ + 5160ll) = *(int64*)((uint8*)&CTX$ + 5160ll) + 1ll;
	{
		struct $12SECTIONENTRY* TMP$123$2;
		TMP$123$2 = (struct $12SECTIONENTRY*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll));
		*(int64*)((uint8*)TMP$123$2 + 24ll) = -1ll;
		if( *(int64*)((uint8*)&CTX$ + 5160ll) <= 0ll) goto label$39;
		{
			*(int64*)((uint8*)TMP$123$2 + 32ll) = *(int64*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + -8ll);
		}
		goto label$38;
		label$39:;
		{
			*(int64*)((uint8*)TMP$123$2 + 32ll) = 0ll;
		}
		label$38:;
	}
	label$37:;
}

static void SECTIONWRITELINE( FBSTRING* S$1 )
{
	label$40:;
	{
		FBSTRING TMP$130$2;
		struct $12SECTIONENTRY* TMP$124$2;
		TMP$124$2 = (struct $12SECTIONENTRY*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll));
		if( *(int64*)((uint8*)TMP$124$2 + 24ll) == 0ll) goto label$43;
		{
			if( *(int64*)((uint8*)TMP$124$2 + 32ll) <= 0ll) goto label$45;
			{
				FBSTRING TMP$126$4;
				FBSTRING* vr$5 = fb_StrAllocTempDescZEx( (char*)"\x09", 1ll );
				FBSTRING* vr$7 = fb_StrFill2( *(int64*)((uint8*)TMP$124$2 + 32ll), (FBSTRING*)vr$5 );
				fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)vr$7, -1ll, 0 );
				__builtin_memset( &TMP$126$4, 0, 24ll );
				FBSTRING* vr$14 = fb_StrConcat( &TMP$126$4, (void*)TMP$124$2, -1ll, (void*)S$1, -1ll );
				fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)vr$14, -1ll, 0 );
			}
			goto label$44;
			label$45:;
			{
				fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)S$1, -1ll, 0 );
			}
			label$44:;
			*(int64*)((uint8*)TMP$124$2 + 24ll) = 0ll;
		}
		goto label$42;
		label$43:;
		{
			FBSTRING TMP$128$3;
			if( *(int64*)((uint8*)TMP$124$2 + 32ll) <= 0ll) goto label$47;
			{
				FBSTRING TMP$127$4;
				FBSTRING* vr$21 = fb_StrAllocTempDescZEx( (char*)"\x09", 1ll );
				FBSTRING* vr$23 = fb_StrFill2( *(int64*)((uint8*)TMP$124$2 + 32ll), (FBSTRING*)vr$21 );
				__builtin_memset( &TMP$127$4, 0, 24ll );
				FBSTRING* vr$28 = fb_StrConcat( &TMP$127$4, (void*)TMP$124$2, -1ll, (void*)vr$23, -1ll );
				fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)vr$28, -1ll, 0 );
			}
			label$47:;
			label$46:;
			__builtin_memset( &TMP$128$3, 0, 24ll );
			FBSTRING* vr$35 = fb_StrConcat( &TMP$128$3, (void*)TMP$124$2, -1ll, (void*)S$1, -1ll );
			fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)vr$35, -1ll, 0 );
		}
		label$42:;
		__builtin_memset( &TMP$130$2, 0, 24ll );
		FBSTRING* vr$42 = fb_StrConcat( &TMP$130$2, (void*)TMP$124$2, -1ll, (void*)"\x0A", 2ll );
		fb_StrAssign( (void*)TMP$124$2, -1ll, (void*)vr$42, -1ll, 0 );
	}
	label$41:;
}

static void SECTIONINDENT( void )
{
	label$48:;
	*(int64*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + 32ll) = *(int64*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + 32ll) + 1ll;
	label$49:;
}

static void SECTIONUNINDENT( void )
{
	label$50:;
	*(int64*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + 32ll) = *(int64*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + 32ll) + -1ll;
	label$51:;
}

static int64 SECTIONINSIDEPROC( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$52:;
	fb$result$1 = (int64)-(*(int64*)((uint8*)&CTX$ + 5160ll) >= 2ll);
	label$53:;
	return fb$result$1;
}

static void SECTIONEND( void )
{
	label$54:;
	struct $12SECTIONENTRY* PARENT$1;
	struct $12SECTIONENTRY* CHILD$1;
	if( *(int64*)((uint8*)&CTX$ + 5160ll) <= 0ll) goto label$57;
	{
		PARENT$1 = (struct $12SECTIONENTRY*)((uint8*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll)) + -40ll);
		CHILD$1 = (struct $12SECTIONENTRY*)((uint8*)&CTX$ + (*(int64*)((uint8*)&CTX$ + 5160ll) * 40ll));
		if( *(int64*)((uint8*)CHILD$1 + 24ll) != 0ll) goto label$59;
		{
			if( *(int64*)((uint8*)PARENT$1 + 24ll) == 0ll) goto label$61;
			{
				fb_StrAssign( (void*)PARENT$1, -1ll, (void*)CHILD$1, -1ll, 0 );
				*(int64*)((uint8*)PARENT$1 + 24ll) = 0ll;
			}
			goto label$60;
			label$61:;
			{
				FBSTRING TMP$131$4;
				__builtin_memset( &TMP$131$4, 0, 24ll );
				FBSTRING* vr$19 = fb_StrConcat( &TMP$131$4, (void*)PARENT$1, -1ll, (void*)CHILD$1, -1ll );
				fb_StrAssign( (void*)PARENT$1, -1ll, (void*)vr$19, -1ll, 0 );
			}
			label$60:;
		}
		label$59:;
		label$58:;
	}
	label$57:;
	label$56:;
	*(int64*)((uint8*)&CTX$ + 5160ll) = *(int64*)((uint8*)&CTX$ + 5160ll) + -1ll;
	label$55:;
}

static int64 SECTIONGOSUB( int64 SECTION$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$62:;
	fb$result$1 = *(int64*)((uint8*)&CTX$ + 5160ll);
	*(int64*)((uint8*)&CTX$ + 5160ll) = SECTION$1;
	*(int64*)((uint8*)&CTX$ + 5168ll) = *(int64*)((uint8*)&CTX$ + 5168ll) + 1ll;
	label$63:;
	return fb$result$1;
}

static void SECTIONRETURN( int64 SECTION$1 )
{
	label$64:;
	*(int64*)((uint8*)&CTX$ + 5168ll) = *(int64*)((uint8*)&CTX$ + 5168ll) + -1ll;
	*(int64*)((uint8*)&CTX$ + 5160ll) = SECTION$1;
	label$65:;
}

static void HWRITELINE( FBSTRING* S$1, int64 NOLINE$1 )
{
	label$66:;
	static FBSTRING LN$1;
	if( (*(int64*)((uint8*)&ENV$ + 296ll) & (int64)-(NOLINE$1 == 0ll)) == 0ll) goto label$69;
	{
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)"#line ", 7ll, 0 );
		FBSTRING* vr$2 = fb_LongintToStr( *(int64*)((uint8*)&CTX$ + 5176ll) );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$2, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" \x22", 3ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)((uint8*)&CTX$ + 5184ll), -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
		SECTIONWRITELINE( &LN$1 );
	}
	label$69:;
	label$68:;
	SECTIONWRITELINE( S$1 );
	label$67:;
}

static void HUPDATECURRENTFILENAME( char* FILENAME$1 )
{
	label$70:;
	FBSTRING* vr$0 = HREPLACE( FILENAME$1, (char*)"\x5C", (char*)"\x5C\x5C" );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5184ll), -1ll, (void*)vr$0, -1ll, 0 );
	label$71:;
}

static void HWRITESTATICASSERT( FBSTRING* EXPR$1 )
{
	FBSTRING TMP$141$1;
	FBSTRING TMP$142$1;
	FBSTRING TMP$143$1;
	label$72:;
	int64 SECTION$1;
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 64ull) != 0ull) goto label$75;
	{
		FBSTRING TMP$138$2;
		*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 64ull;
		int64 vr$2 = SECTIONGOSUB( 0ll );
		SECTION$1 = vr$2;
		__builtin_memset( &TMP$138$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$138$2, -1ll, (void*)"#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]", 85ll, 0 );
		HWRITELINE( &TMP$138$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$138$2 );
		SECTIONRETURN( SECTION$1 );
	}
	label$75:;
	label$74:;
	__builtin_memset( &TMP$143$1, 0, 24ll );
	__builtin_memset( &TMP$141$1, 0, 24ll );
	FBSTRING* vr$10 = fb_StrConcat( &TMP$141$1, (void*)"__FB_STATIC_ASSERT( ", 21ll, (void*)EXPR$1, -1ll );
	__builtin_memset( &TMP$142$1, 0, 24ll );
	FBSTRING* vr$13 = fb_StrConcat( &TMP$142$1, (void*)vr$10, -1ll, (void*)" );", 4ll );
	fb_StrAssign( (void*)&TMP$143$1, -1ll, (void*)vr$13, -1ll, 0 );
	HWRITELINE( &TMP$143$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$143$1 );
	label$73:;
}

static void HAPPENDCTORATTRIB( FBSTRING* LN$1, struct $8FBSYMBOL* PROC$1, int64 IN_FRONT$1 )
{
	label$76:;
	int64 PRIORITY$1;
	if( (*(int64*)((uint8*)PROC$1 + 24ll) & 196608ll) == 0ll) goto label$79;
	{
		if( IN_FRONT$1 != 0ll) goto label$81;
		{
			fb_StrConcatByref( (void*)LN$1, -1ll, (void*)" ", 2ll, 0 );
		}
		label$81:;
		label$80:;
		fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"__attribute__(( ", 17ll, 0 );
		if( (*(int64*)((uint8*)PROC$1 + 24ll) & 65536ll) == 0ll) goto label$83;
		{
			fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"constructor", 12ll, 0 );
		}
		goto label$82;
		label$83:;
		{
			fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"destructor", 11ll, 0 );
		}
		label$82:;
		PRIORITY$1 = *(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 112ll);
		if( PRIORITY$1 == 0ll) goto label$85;
		{
			FBSTRING TMP$150$3;
			FBSTRING TMP$151$3;
			FBSTRING* vr$6 = fb_LongintToStr( PRIORITY$1 );
			__builtin_memset( &TMP$150$3, 0, 24ll );
			FBSTRING* vr$9 = fb_StrConcat( &TMP$150$3, (void*)"( ", 3ll, (void*)vr$6, -1ll );
			__builtin_memset( &TMP$151$3, 0, 24ll );
			FBSTRING* vr$12 = fb_StrConcat( &TMP$151$3, (void*)vr$9, -1ll, (void*)" )", 3ll );
			fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$12, -1ll, 0 );
		}
		label$85:;
		label$84:;
		fb_StrConcatByref( (void*)LN$1, -1ll, (void*)" ))", 4ll, 0 );
		if( IN_FRONT$1 == 0ll) goto label$87;
		{
			fb_StrConcatByref( (void*)LN$1, -1ll, (void*)" ", 2ll, 0 );
		}
		label$87:;
		label$86:;
	}
	label$79:;
	label$78:;
	label$77:;
}

static FBSTRING* HGETMANGLEDNAMEFORASM( struct $8FBSYMBOL* SYM$1, int64 UNDERSCORE_PREFIX$1 )
{
	int64 TMP$153$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$88:;
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 6ll) goto label$90;
	TMP$153$1 = (int64)-(*(char**)((uint8*)SYM$1 + 40ll) != (char*)0ull);
	goto label$1230;
	label$90:;
	TMP$153$1 = 0ll;
	label$1230:;
	if( TMP$153$1 == 0ll) goto label$92;
	{
		fb_StrAssign( (void*)&MANGLED$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
	}
	goto label$91;
	label$92:;
	{
		char* vr$8 = SYMBGETMANGLEDNAME( SYM$1 );
		fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$8, 0ll, 0 );
	}
	label$91:;
	if( (UNDERSCORE_PREFIX$1 & *(int64*)((uint8*)&ENV$ + 608ll)) == 0ll) goto label$94;
	{
		FBSTRING TMP$155$2;
		__builtin_memset( &TMP$155$2, 0, 24ll );
		FBSTRING* vr$14 = fb_StrConcat( &TMP$155$2, (void*)"_", 2ll, (void*)&MANGLED$1, -1ll );
		fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$14, -1ll, 0 );
	}
	label$94:;
	label$93:;
	int64 vr$16 = FBGETCPUFAMILY(  );
	if( ((int64)-(vr$16 == 0ll) & (int64)-(*(int64*)SYM$1 == 3ll)) == 0ll) goto label$96;
	{
		if( *(int64*)((uint8*)SYM$1 + 152ll) != 1ll) goto label$98;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"@", 2ll, 0 );
			int64 vr$23 = SYMBPROCCALCSTDCALLSUFFIXN( SYM$1 );
			FBSTRING* vr$24 = fb_LongintToStr( vr$23 );
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)vr$24, -1ll, 0 );
		}
		label$98:;
		label$97:;
	}
	label$96:;
	label$95:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&MANGLED$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	label$89:;
	FBSTRING* vr$30 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$30;
}

static int64 HNEEDALIAS( struct $8FBSYMBOL* PROC$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$99:;
	fb$result$1 = 0ll;
	if( (int64)*(int16*)((uint8*)PROC$1 + 74ll) != 6ll) goto label$102;
	{
		fb$result$1 = -1ll;
		goto label$100;
	}
	label$102:;
	label$101:;
	int64 vr$3 = FBGETCPUFAMILY(  );
	if( vr$3 == 0ll) goto label$104;
	{
		goto label$100;
	}
	label$104:;
	label$103:;
	{
		$13FB_COMPTARGET TMP$157$2;
		TMP$157$2 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
		if( TMP$157$2 == 0ll) goto label$107;
		label$108:;
		if( TMP$157$2 == 1ll) goto label$107;
		label$109:;
		if( TMP$157$2 != 5ll) goto label$106;
		label$107:;
		{
			if( *(int64*)((uint8*)PROC$1 + 152ll) != 6ll) goto label$111;
			{
				goto label$100;
			}
			label$111:;
			label$110:;
		}
		goto label$105;
		label$106:;
		{
			goto label$100;
		}
		label$112:;
		label$105:;
	}
	{
		$11FB_FUNCMODE TMP$158$2;
		TMP$158$2 = *($11FB_FUNCMODE*)((uint8*)PROC$1 + 152ll);
		if( TMP$158$2 == 2ll) goto label$115;
		label$116:;
		if( TMP$158$2 != 4ll) goto label$114;
		label$115:;
		{
			fb$result$1 = -1ll;
		}
		goto label$113;
		label$114:;
		if( TMP$158$2 != 1ll) goto label$117;
		label$118:;
		{
			fb$result$1 = -1ll;
		}
		label$117:;
		label$113:;
	}
	label$100:;
	return fb$result$1;
}

static FBSTRING* HEMITPROCHEADER( struct $8FBSYMBOL* PROC$1, $16EMITPROC_OPTIONS OPTIONS$1 )
{
	FBSTRING TMP$160$1;
	struct $8FBSYMBOL* TMP$178$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$119:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	int64 DTYPE$1;
	struct $8FBSYMBOL* SUBTYPE$1;
	if( OPTIONS$1 != 0ll) goto label$122;
	{
		HAPPENDCTORATTRIB( &LN$1, PROC$1, -1ll );
	}
	label$122:;
	label$121:;
	if( (OPTIONS$1 & 2ll) != 0ll) goto label$124;
	{
		if( (*(int64*)((uint8*)PROC$1 + 8ll) & 64ll) == 0ll) goto label$126;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"static ", 8ll, 0 );
		}
		label$126:;
		label$125:;
	}
	label$124:;
	label$123:;
	FBSTRING* vr$10 = HEMITTYPE( *(int64*)((uint8*)PROC$1 + 160ll), *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 168ll) );
	__builtin_memset( &TMP$160$1, 0, 24ll );
	FBSTRING* vr$14 = fb_StrConcat( &TMP$160$1, (void*)&LN$1, -1ll, (void*)vr$10, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$14, -1ll, 0 );
	int64 vr$16 = FBGETCPUFAMILY(  );
	if( vr$16 != 0ll) goto label$128;
	{
		{
			$11FB_FUNCMODE TMP$161$3;
			TMP$161$3 = *($11FB_FUNCMODE*)((uint8*)PROC$1 + 152ll);
			if( TMP$161$3 == 1ll) goto label$131;
			label$132:;
			if( TMP$161$3 == 2ll) goto label$131;
			label$133:;
			if( TMP$161$3 != 4ll) goto label$130;
			label$131:;
			{
				{
					$13FB_COMPTARGET TMP$162$5;
					TMP$162$5 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
					if( TMP$162$5 == 0ll) goto label$136;
					label$137:;
					if( TMP$162$5 != 5ll) goto label$135;
					label$136:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __stdcall", 11ll, 0 );
					}
					goto label$134;
					label$135:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((stdcall))", 26ll, 0 );
					}
					label$138:;
					label$134:;
				}
			}
			goto label$129;
			label$130:;
			if( TMP$161$3 != 5ll) goto label$139;
			label$140:;
			{
				{
					$13FB_COMPTARGET TMP$165$5;
					TMP$165$5 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
					if( TMP$165$5 == 0ll) goto label$143;
					label$144:;
					if( TMP$165$5 != 5ll) goto label$142;
					label$143:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __thiscall", 12ll, 0 );
					}
					goto label$141;
					label$142:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((thiscall))", 27ll, 0 );
					}
					label$145:;
					label$141:;
				}
			}
			goto label$129;
			label$139:;
			if( TMP$161$3 != 6ll) goto label$146;
			label$147:;
			{
				{
					$13FB_COMPTARGET TMP$168$5;
					TMP$168$5 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
					if( TMP$168$5 == 0ll) goto label$150;
					label$151:;
					if( TMP$168$5 != 5ll) goto label$149;
					label$150:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __fastcall", 12ll, 0 );
					}
					goto label$148;
					label$149:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((fastcall))", 27ll, 0 );
					}
					label$152:;
					label$148:;
				}
			}
			label$146:;
			label$129:;
		}
	}
	label$128:;
	label$127:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	char* vr$25 = SYMBGETMANGLEDNAME( PROC$1 );
	fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$25, 0ll, 0 );
	if( (OPTIONS$1 & 2ll) == 0ll) goto label$154;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"(*", 3ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&MANGLED$1, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)")", 2ll, 0 );
	}
	goto label$153;
	label$154:;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&MANGLED$1, -1ll, 0 );
	}
	label$153:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"( ", 3ll, 0 );
	struct $8FBSYMBOL* HIDDEN$1;
	HIDDEN$1 = (struct $8FBSYMBOL*)0ull;
	int64 vr$35 = SYMBPROCRETURNSONSTACK( PROC$1 );
	if( vr$35 == 0ll) goto label$156;
	{
		if( (OPTIONS$1 & 1ll) == 0ll) goto label$158;
		{
			FBSTRING TMP$173$3;
			HIDDEN$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 64ll);
			FBSTRING* vr$55 = HEMITTYPE( ((((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 32505856ll), HIDDEN$1 );
			__builtin_memset( &TMP$173$3, 0, 24ll );
			FBSTRING* vr$59 = fb_StrConcat( &TMP$173$3, (void*)&LN$1, -1ll, (void*)vr$55, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$59, -1ll, 0 );
		}
		goto label$157;
		label$158:;
		{
			FBSTRING TMP$174$3;
			FBSTRING TMP$175$3;
			FBSTRING TMP$176$3;
			HIDDEN$1 = *(struct $8FBSYMBOL**)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll);
			FBSTRING* vr$81 = HEMITTYPE( ((((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)HIDDEN$1 + 64ll) );
			__builtin_memset( &TMP$174$3, 0, 24ll );
			FBSTRING* vr$85 = fb_StrConcat( &TMP$174$3, (void*)&LN$1, -1ll, (void*)vr$81, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$85, -1ll, 0 );
			char* vr$87 = SYMBGETMANGLEDNAME( HIDDEN$1 );
			__builtin_memset( &TMP$175$3, 0, 24ll );
			FBSTRING* vr$90 = fb_StrConcat( &TMP$175$3, (void*)" ", 2ll, (void*)vr$87, 0ll );
			__builtin_memset( &TMP$176$3, 0, 24ll );
			FBSTRING* vr$94 = fb_StrConcat( &TMP$176$3, (void*)&LN$1, -1ll, (void*)vr$90, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$94, -1ll, 0 );
		}
		label$157:;
		if( (int64)*(int16*)((uint8*)PROC$1 + 120ll) <= 0ll) goto label$160;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$160:;
		label$159:;
	}
	label$156:;
	label$155:;
	struct $8FBSYMBOL* PARAM$1;
	if( *(int64*)((uint8*)PROC$1 + 152ll) != 4ll) goto label$161;
	TMP$178$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 144ll);
	goto label$1231;
	label$161:;
	TMP$178$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 136ll);
	label$1231:;
	PARAM$1 = TMP$178$1;
	if( ((int64)-(HIDDEN$1 == (struct $8FBSYMBOL*)0ull) & (int64)-(PARAM$1 == (struct $8FBSYMBOL*)0ull)) == 0ll) goto label$163;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"void", 5ll, 0 );
	}
	label$163:;
	label$162:;
	label$164:;
	if( PARAM$1 == (struct $8FBSYMBOL*)0ull) goto label$165;
	{
		struct $8FBSYMBOL* TMP$183$2;
		if( *(int64*)((uint8*)PARAM$1 + 96ll) != 4ll) goto label$167;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"...", 4ll, 0 );
		}
		goto label$166;
		label$167:;
		{
			if( (*(int64*)((uint8*)PARAM$1 + 24ll) & 524288ll) == 0ll) goto label$169;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"char**", 7ll, 0 );
			}
			goto label$168;
			label$169:;
			{
				_Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( PARAM$1, &DTYPE$1, &SUBTYPE$1 );
				FBSTRING* vr$113 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$113, -1ll, 0 );
			}
			label$168:;
			if( (OPTIONS$1 & 1ll) != 0ll) goto label$171;
			{
				FBSTRING TMP$181$4;
				FBSTRING TMP$182$4;
				char* vr$117 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 104ll) );
				__builtin_memset( &TMP$181$4, 0, 24ll );
				FBSTRING* vr$120 = fb_StrConcat( &TMP$181$4, (void*)" ", 2ll, (void*)vr$117, 0ll );
				__builtin_memset( &TMP$182$4, 0, 24ll );
				FBSTRING* vr$124 = fb_StrConcat( &TMP$182$4, (void*)&LN$1, -1ll, (void*)vr$120, -1ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$124, -1ll, 0 );
			}
			label$171:;
			label$170:;
		}
		label$166:;
		if( *(int64*)((uint8*)PROC$1 + 152ll) != 4ll) goto label$172;
		TMP$183$2 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 304ll);
		goto label$1232;
		label$172:;
		TMP$183$2 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 312ll);
		label$1232:;
		PARAM$1 = TMP$183$2;
		if( PARAM$1 == (struct $8FBSYMBOL*)0ull) goto label$174;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$174:;
		label$173:;
	}
	goto label$164;
	label$165:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" )", 3ll, 0 );
	if( ((int64)-((OPTIONS$1 & 2ll) == 0ll) & (int64)-((OPTIONS$1 & 1ll) != 0ll)) == 0ll) goto label$176;
	{
		int64 vr$136 = HNEEDALIAS( PROC$1 );
		if( vr$136 == 0ll) goto label$178;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" asm(\x22", 7ll, 0 );
			FBSTRING* vr$138 = HGETMANGLEDNAMEFORASM( PROC$1, -1ll );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$138, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22)", 3ll, 0 );
		}
		label$178:;
		label$177:;
		HAPPENDCTORATTRIB( &LN$1, PROC$1, 0ll );
	}
	label$176:;
	label$175:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&LN$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$120:;
	FBSTRING* vr$147 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$147;
}

static FBSTRING* HGETUDTTAG( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$179:;
	if( *(int64*)SYM$1 != 10ll) goto label$182;
	{
		if( ((int64)*(int32*)((uint8*)SYM$1 + 208ll) & 1ll) == 0ll) goto label$184;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"union ", 7ll, 0 );
		}
		goto label$183;
		label$184:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"struct ", 8ll, 0 );
		}
		label$183:;
	}
	label$182:;
	label$181:;
	label$180:;
	FBSTRING* vr$8 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$8;
}

static FBSTRING* HGETUDTID( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING TMP$190$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$185:;
	if( ((*(int64*)((uint8*)SYM$1 + 56ll) & 32505856ll) >> (20ll & 63ll)) != 19ll) goto label$188;
	{
		{
			$19FB_CVA_LIST_TYPEDEF TMP$188$3;
			$19FB_CVA_LIST_TYPEDEF vr$6 = SYMBGETVALISTTYPE( *(int64*)((uint8*)SYM$1 + 56ll), *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
			TMP$188$3 = vr$6;
			if( TMP$188$3 == 3ll) goto label$191;
			label$192:;
			if( TMP$188$3 == 4ll) goto label$191;
			label$193:;
			if( TMP$188$3 != 5ll) goto label$190;
			label$191:;
			{
				fb_StrAssign( (void*)&fb$result$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
				goto label$186;
			}
			label$190:;
			label$189:;
		}
	}
	label$188:;
	label$187:;
	char* vr$9 = SYMBGETMANGLEDNAME( SYM$1 );
	__builtin_memset( &TMP$190$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$190$1, (void*)"$", 2ll, (void*)vr$9, 0ll );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$12, -1ll, 0 );
	label$186:;
	FBSTRING* vr$15 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$15;
}

static FBSTRING* HGETUDTNAME( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$194:;
	FBSTRING* vr$1 = HGETUDTTAG( SYM$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	FBSTRING* vr$3 = HGETUDTID( SYM$1 );
	fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)vr$3, -1ll, 0 );
	label$195:;
	FBSTRING* vr$6 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$6;
}

static void HEMITUDT( struct $8FBSYMBOL* S$1, int64 IS_PTR$1 )
{
	label$196:;
	int64 SECTION$1;
	if( S$1 != (struct $8FBSYMBOL*)0ull) goto label$199;
	{
		goto label$197;
	}
	label$199:;
	label$198:;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 67108864ll) == 0ll) goto label$201;
	{
		goto label$197;
	}
	label$201:;
	label$200:;
	if( (*(int64*)((uint8*)S$1 + 8ll) & 128ll) == 0ll) goto label$203;
	{
		SECTION$1 = (int64)*(uint16*)((uint8*)S$1 + 72ll) + 1ll;
		if( (int64)*(uint16*)((uint8*)S$1 + 72ll) != 0ll) goto label$205;
		{
			SECTION$1 = SECTION$1 + 1ll;
		}
		goto label$204;
		label$205:;
		if( *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)S$1 + 248ll) != (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$206;
		{
			SECTION$1 = SECTION$1 + 1ll;
		}
		label$206:;
		label$204:;
		if( SECTION$1 <= *(int64*)((uint8*)&CTX$ + 5160ll)) goto label$208;
		{
			SECTION$1 = *(int64*)((uint8*)&CTX$ + 5160ll);
		}
		label$208:;
		label$207:;
	}
	goto label$202;
	label$203:;
	{
		SECTION$1 = 0ll;
	}
	label$202:;
	int64 vr$14 = SECTIONGOSUB( SECTION$1 );
	SECTION$1 = vr$14;
	{
		uint64 TMP$191$2;
		TMP$191$2 = *(uint64*)S$1;
		goto label$210;
		label$211:;
		{
			FBSTRING TMP$194$3;
			FBSTRING TMP$195$3;
			FBSTRING TMP$196$3;
			FBSTRING TMP$197$3;
			FBSTRING TMP$198$3;
			*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 67108864ll;
			__builtin_memset( &TMP$198$3, 0, 24ll );
			FBSTRING* vr$20 = HGETUDTNAME( S$1 );
			FBSTRING* vr$21 = HEMITTYPE( 10ll, (struct $8FBSYMBOL*)0ull );
			__builtin_memset( &TMP$194$3, 0, 24ll );
			FBSTRING* vr$24 = fb_StrConcat( &TMP$194$3, (void*)"typedef ", 9ll, (void*)vr$21, -1ll );
			__builtin_memset( &TMP$195$3, 0, 24ll );
			FBSTRING* vr$27 = fb_StrConcat( &TMP$195$3, (void*)vr$24, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$196$3, 0, 24ll );
			FBSTRING* vr$30 = fb_StrConcat( &TMP$196$3, (void*)vr$27, -1ll, (void*)vr$20, -1ll );
			__builtin_memset( &TMP$197$3, 0, 24ll );
			FBSTRING* vr$33 = fb_StrConcat( &TMP$197$3, (void*)vr$30, -1ll, (void*)";", 2ll );
			fb_StrAssign( (void*)&TMP$198$3, -1ll, (void*)vr$33, -1ll, 0 );
			HWRITELINE( &TMP$198$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$198$3 );
		}
		goto label$209;
		label$212:;
		{
			HEMITSTRUCT( S$1, IS_PTR$1 );
		}
		goto label$209;
		label$213:;
		{
			if( (*(int64*)((uint8*)S$1 + 24ll) & 16384ll) == 0ll) goto label$215;
			{
				FBSTRING DECL$4;
				FBSTRING* vr$39 = HEMITPROCHEADER( S$1, 3ll );
				fb_StrInit( (void*)&DECL$4, -1ll, (void*)vr$39, -1ll, 0 );
				if( (*(int64*)((uint8*)S$1 + 24ll) & 67108864ll) != 0ll) goto label$217;
				{
					FBSTRING TMP$199$5;
					FBSTRING TMP$200$5;
					FBSTRING TMP$201$5;
					__builtin_memset( &TMP$201$5, 0, 24ll );
					__builtin_memset( &TMP$199$5, 0, 24ll );
					FBSTRING* vr$47 = fb_StrConcat( &TMP$199$5, (void*)"typedef ", 9ll, (void*)&DECL$4, -1ll );
					__builtin_memset( &TMP$200$5, 0, 24ll );
					FBSTRING* vr$50 = fb_StrConcat( &TMP$200$5, (void*)vr$47, -1ll, (void*)";", 2ll );
					fb_StrAssign( (void*)&TMP$201$5, -1ll, (void*)vr$50, -1ll, 0 );
					HWRITELINE( &TMP$201$5, 0ll );
					fb_StrDelete( (FBSTRING*)&TMP$201$5 );
					*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 67108864ll;
				}
				label$217:;
				label$216:;
				fb_StrDelete( (FBSTRING*)&DECL$4 );
			}
			label$215:;
			label$214:;
		}
		goto label$209;
		label$210:;
		static const void* tmp$701[8ll] = {
			&&label$213,
			&&label$209,
			&&label$209,
			&&label$209,
			&&label$209,
			&&label$209,
			&&label$211,
			&&label$212,
		};
		if( (TMP$191$2 - 3ull) > 7ull ) goto label$209;
		goto *tmp$701[TMP$191$2 - 3ull];
		label$209:;
	}
	SECTIONRETURN( SECTION$1 );
	label$197:;
}

static FBSTRING* HEMITARRAYDECL( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$218:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 512ll) == 0ll) goto label$221;
	{
		fb_StrDelete( (FBSTRING*)&S$1 );
		goto label$219;
	}
	label$221:;
	label$220:;
	{
		$12FB_SYMBCLASS TMP$202$2;
		TMP$202$2 = *($12FB_SYMBCLASS*)SYM$1;
		if( TMP$202$2 == 1ll) goto label$224;
		label$225:;
		if( TMP$202$2 != 12ll) goto label$223;
		label$224:;
		{
			if( (*(int64*)((uint8*)SYM$1 + 8ll) & 16388ll) != 0ll) goto label$227;
			{
				{
					int64 I$5;
					I$5 = 0ll;
					int64 TMP$203$5;
					TMP$203$5 = *(int64*)((uint8*)SYM$1 + 104ll) + -1ll;
					goto label$228;
					label$231:;
					{
						FBSTRING TMP$206$6;
						FBSTRING TMP$207$6;
						FBSTRING TMP$208$6;
						FBSTRING* vr$18 = fb_LongintToStr( (*(int64*)((uint8*)((uint8*)*(struct $10FBARRAYDIM**)((uint8*)SYM$1 + 112ll) + (I$5 << (4ll & 63ll))) + 8ll) - *(int64*)((uint8*)*(struct $10FBARRAYDIM**)((uint8*)SYM$1 + 112ll) + (I$5 << (4ll & 63ll)))) + 1ll );
						__builtin_memset( &TMP$206$6, 0, 24ll );
						FBSTRING* vr$21 = fb_StrConcat( &TMP$206$6, (void*)"[", 2ll, (void*)vr$18, -1ll );
						__builtin_memset( &TMP$207$6, 0, 24ll );
						FBSTRING* vr$24 = fb_StrConcat( &TMP$207$6, (void*)vr$21, -1ll, (void*)"]", 2ll );
						__builtin_memset( &TMP$208$6, 0, 24ll );
						FBSTRING* vr$28 = fb_StrConcat( &TMP$208$6, (void*)&S$1, -1ll, (void*)vr$24, -1ll );
						fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$28, -1ll, 0 );
					}
					label$229:;
					I$5 = I$5 + 1ll;
					label$228:;
					if( I$5 <= TMP$203$5) goto label$231;
					label$230:;
				}
			}
			label$227:;
			label$226:;
		}
		label$223:;
		label$222:;
	}
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) != 0ll) goto label$233;
	{
		int64 LENGTH$2;
		LENGTH$2 = 0ll;
		{
			int64 TMP$209$3;
			TMP$209$3 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
			if( TMP$209$3 == 18ll) goto label$236;
			label$237:;
			if( TMP$209$3 != 4ll) goto label$235;
			label$236:;
			{
				LENGTH$2 = *(int64*)((uint8*)SYM$1 + 80ll);
			}
			goto label$234;
			label$235:;
			if( TMP$209$3 != 7ll) goto label$238;
			label$239:;
			{
				int64 vr$36 = SYMBGETWSTRLENGTH( SYM$1 );
				LENGTH$2 = vr$36 + 1ll;
			}
			label$238:;
			label$234:;
		}
		if( LENGTH$2 <= 0ll) goto label$241;
		{
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"[", 2ll, 0 );
			FBSTRING* vr$39 = fb_LongintToStr( LENGTH$2 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$39, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"]", 2ll, 0 );
		}
		label$241:;
		label$240:;
	}
	label$233:;
	label$232:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$219:;
	FBSTRING* vr$46 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$46;
}

static void HEMITVARDECL( int64 USE_EXTERN$1, struct $8FBSYMBOL* SYM$1, char* VARINI$1 )
{
	FBSTRING TMP$211$1;
	FBSTRING TMP$212$1;
	FBSTRING TMP$213$1;
	label$242:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	if( USE_EXTERN$1 == 0ll) goto label$245;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"extern ", 8ll, 0 );
	}
	goto label$244;
	label$245:;
	if( ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) != 0ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 56ll) == 0ll)) == 0ll) goto label$246;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"static ", 8ll, 0 );
	}
	label$246:;
	label$244:;
	int64 DTYPE$1;
	__builtin_memset( &DTYPE$1, 0, 8ll );
	struct $8FBSYMBOL* SUBTYPE$1;
	__builtin_memset( &SUBTYPE$1, 0, 8ll );
	SYMBGETREALTYPE( SYM$1, &DTYPE$1, &SUBTYPE$1 );
	FBSTRING* vr$15 = HEMITTYPE( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
	__builtin_memset( &TMP$211$1, 0, 24ll );
	FBSTRING* vr$19 = fb_StrConcat( &TMP$211$1, (void*)&LN$1, -1ll, (void*)vr$15, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$19, -1ll, 0 );
	char* vr$21 = SYMBGETMANGLEDNAME( SYM$1 );
	__builtin_memset( &TMP$212$1, 0, 24ll );
	FBSTRING* vr$24 = fb_StrConcat( &TMP$212$1, (void*)" ", 2ll, (void*)vr$21, 0ll );
	__builtin_memset( &TMP$213$1, 0, 24ll );
	FBSTRING* vr$28 = fb_StrConcat( &TMP$213$1, (void*)&LN$1, -1ll, (void*)vr$24, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$28, -1ll, 0 );
	FBSTRING* vr$30 = HEMITARRAYDECL( SYM$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$30, -1ll, 0 );
	if( ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 8ll) != 0ll) & ~USE_EXTERN$1) == 0ll) goto label$248;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((common))", 25ll, 0 );
	}
	label$248:;
	label$247:;
	if( VARINI$1 == (char*)0ull) goto label$250;
	{
		FBSTRING TMP$216$2;
		FBSTRING TMP$217$2;
		__builtin_memset( &TMP$216$2, 0, 24ll );
		FBSTRING* vr$40 = fb_StrConcat( &TMP$216$2, (void*)" = ", 4ll, (void*)VARINI$1, 0ll );
		__builtin_memset( &TMP$217$2, 0, 24ll );
		FBSTRING* vr$44 = fb_StrConcat( &TMP$217$2, (void*)&LN$1, -1ll, (void*)vr$40, -1ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$44, -1ll, 0 );
	}
	label$250:;
	label$249:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)";", 2ll, 0 );
	HWRITELINE( &LN$1, 0ll );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$243:;
}

static void HMAYBEEMITLOCALVAR( struct $8FBSYMBOL* SYM$1 )
{
	label$251:;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 16388ll) == 0ll) goto label$254;
	{
		goto label$252;
	}
	label$254:;
	label$253:;
	if( ((int64)-(*(struct $7ASTNODE**)((uint8*)SYM$1 + 96ll) != (struct $7ASTNODE*)0ull) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) != 0ll)) == 0ll) goto label$256;
	{
		IRHLFLUSHSTATICINITIALIZER( SYM$1 );
	}
	goto label$255;
	label$256:;
	{
		HEMITVARDECL( 0ll, SYM$1, (char*)0ull );
	}
	label$255:;
	label$252:;
}

static void HALLOCGLOBALVAR( struct $8FBSYMBOL* SYM$1 )
{
	label$257:;
	if( *(struct $7ASTNODE**)((uint8*)SYM$1 + 96ll) == (struct $7ASTNODE*)0ull) goto label$260;
	{
		if( ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 32ll) == 0ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 24ll) & 2ll) == 0ll)) == 0ll) goto label$262;
		{
			goto label$258;
		}
		label$262:;
		label$261:;
		IRHLFLUSHSTATICINITIALIZER( SYM$1 );
	}
	goto label$259;
	label$260:;
	{
		HEMITVARDECL( 0ll, SYM$1, (char*)0ull );
	}
	label$259:;
	label$258:;
}

static void HMAYBEEMITGLOBALVAR( struct $8FBSYMBOL* SYM$1 )
{
	label$263:;
	if( (((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 1024ll) != 0ll) | ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 16ll) != 0ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 24ll) & 2ll) == 0ll))) | (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 16388ll) != 0ll)) == 0ll) goto label$266;
	{
		goto label$264;
	}
	label$266:;
	label$265:;
	{
		int64 TMP$218$2;
		TMP$218$2 = *(int64*)((uint8*)&CTX$ + 5512ll);
		if( TMP$218$2 != 1ll) goto label$268;
		label$269:;
		{
			if( (*(int64*)((uint8*)SYM$1 + 8ll) & 56ll) == 0ll) goto label$271;
			{
				HEMITVARDECL( -1ll, SYM$1, (char*)0ull );
			}
			goto label$270;
			label$271:;
			{
				HALLOCGLOBALVAR( SYM$1 );
			}
			label$270:;
		}
		goto label$267;
		label$268:;
		if( TMP$218$2 != 2ll) goto label$272;
		label$273:;
		{
			if( (*(int64*)((uint8*)SYM$1 + 8ll) & 40ll) == 0ll) goto label$275;
			{
				HALLOCGLOBALVAR( SYM$1 );
			}
			label$275:;
			label$274:;
		}
		label$272:;
		label$267:;
	}
	label$264:;
}

static void HMAYBEEMITGLOBALVAREXCEPTDATASTMT( struct $8FBSYMBOL* SYM$1 )
{
	label$276:;
	int64 vr$0 = SYMBISDATADESC( SYM$1 );
	if( vr$0 == 0ll) goto label$279;
	{
		goto label$277;
	}
	label$279:;
	label$278:;
	HMAYBEEMITGLOBALVAR( SYM$1 );
	label$277:;
}

static void HMAYBEEMITPROCPROTO( struct $8FBSYMBOL* S$1 )
{
	FBSTRING TMP$219$1;
	FBSTRING TMP$220$1;
	label$280:;
	int64 SECTION$1;
	if( ((int64)-((*(int64*)((uint8*)S$1 + 24ll) & 16384ll) != 0ll) | (int64)-((*(int64*)((uint8*)S$1 + 24ll) & 2ll) == 0ll)) == 0ll) goto label$283;
	{
		goto label$281;
	}
	label$283:;
	label$282:;
	char* vr$7 = SYMBGETMANGLEDNAME( S$1 );
	if( vr$7 != (char*)0ull) goto label$285;
	{
		goto label$281;
	}
	label$285:;
	label$284:;
	int64 vr$8 = SECTIONGOSUB( 0ll );
	SECTION$1 = vr$8;
	__builtin_memset( &TMP$220$1, 0, 24ll );
	FBSTRING* vr$10 = HEMITPROCHEADER( S$1, 1ll );
	__builtin_memset( &TMP$219$1, 0, 24ll );
	FBSTRING* vr$13 = fb_StrConcat( &TMP$219$1, (void*)vr$10, -1ll, (void*)";", 2ll );
	fb_StrAssign( (void*)&TMP$220$1, -1ll, (void*)vr$13, -1ll, 0 );
	HWRITELINE( &TMP$220$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$220$1 );
	SECTIONRETURN( SECTION$1 );
	label$281:;
}

static void HEMITFIELDTYPES( struct $8FBSYMBOL* UDT$1 )
{
	label$286:;
	struct $8FBSYMBOL* FLD$1;
	struct $8FBSYMBOL* vr$0 = SYMBUDTGETFIRSTFIELD( UDT$1 );
	FLD$1 = vr$0;
	label$288:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$289;
	{
		HEMITUDT( *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll), (int64)-(((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 480ll) != 0ll) );
		struct $8FBSYMBOL* vr$6 = SYMBUDTGETNEXTFIELD( FLD$1 );
		FLD$1 = vr$6;
	}
	goto label$288;
	label$289:;
	label$287:;
}

static struct $8FBSYMBOL** HFINDPARENTANONALREADYONSTACK( struct $8FBSYMBOL* FLD$1 )
{
	struct $8FBSYMBOL** fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$290:;
	struct $8FBSYMBOL** ANONNODE$1;
	struct $8FBSYMBOL* PARENT$1;
	PARENT$1 = *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 296ll);
	label$292:;
	{
		void* vr$3 = LISTGETTAIL( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll) );
		ANONNODE$1 = (struct $8FBSYMBOL**)vr$3;
		label$295:;
		if( ANONNODE$1 == (struct $8FBSYMBOL**)0ull) goto label$296;
		{
			if( *ANONNODE$1 != PARENT$1) goto label$298;
			{
				fb$result$1 = ANONNODE$1;
				goto label$291;
			}
			label$298:;
			label$297:;
			void* vr$5 = LISTGETPREV( (void*)ANONNODE$1 );
			ANONNODE$1 = (struct $8FBSYMBOL**)vr$5;
		}
		goto label$295;
		label$296:;
		PARENT$1 = *(struct $8FBSYMBOL**)((uint8*)PARENT$1 + 296ll);
	}
	label$294:;
	if( PARENT$1 != (struct $8FBSYMBOL*)0ull) goto label$292;
	label$293:;
	fb$result$1 = (struct $8FBSYMBOL**)0ull;
	label$291:;
	return fb$result$1;
}

static void HPUSHANONPARENTS( struct $8FBSYMBOL* BASEPARENT$1, struct $8FBSYMBOL* PARENT$1 )
{
	label$299:;
	if( PARENT$1 != BASEPARENT$1) goto label$302;
	{
		goto label$300;
	}
	label$302:;
	label$301:;
	HPUSHANONPARENTS( BASEPARENT$1, *(struct $8FBSYMBOL**)((uint8*)PARENT$1 + 296ll) );
	if( ((int64)*(int32*)((uint8*)PARENT$1 + 208ll) & 1ll) == 0ll) goto label$304;
	{
		FBSTRING TMP$222$2;
		__builtin_memset( &TMP$222$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$222$2, -1ll, (void*)"union {", 8ll, 0 );
		HWRITELINE( &TMP$222$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$222$2 );
	}
	goto label$303;
	label$304:;
	{
		FBSTRING TMP$224$2;
		__builtin_memset( &TMP$224$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$224$2, -1ll, (void*)"struct {", 9ll, 0 );
		HWRITELINE( &TMP$224$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$224$2 );
	}
	label$303:;
	SECTIONINDENT(  );
	void* vr$13 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll) );
	*(struct $8FBSYMBOL**)vr$13 = PARENT$1;
	label$300:;
}

static void HPOPANONPARENTS( struct $8FBSYMBOL** ANONNODE$1 )
{
	label$305:;
	label$307:;
	void* vr$1 = LISTGETTAIL( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll) );
	if( (uint64)vr$1 == (uint64)ANONNODE$1) goto label$308;
	{
		FBSTRING TMP$226$2;
		SECTIONUNINDENT(  );
		__builtin_memset( &TMP$226$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$226$2, -1ll, (void*)"};", 3ll, 0 );
		HWRITELINE( &TMP$226$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$226$2 );
		void* vr$7 = LISTGETTAIL( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll) );
		LISTDELNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5216ll), vr$7 );
	}
	goto label$307;
	label$308:;
	label$306:;
}

static void HEMITSTRUCTWITHFIELDS( struct $8FBSYMBOL* S$1 )
{
	label$309:;
	int64 SKIP$1;
	int64 DTYPE$1;
	int64 ALIGN$1;
	struct $8FBSYMBOL* SUBTYPE$1;
	struct $8FBSYMBOL* FLD$1;
	struct $8FBSYMBOL** ANONNODE$1;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	struct $8FBSYMBOL* vr$1 = SYMBUDTGETFIRSTFIELD( S$1 );
	FLD$1 = vr$1;
	label$311:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$312;
	{
		if( *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 296ll) != S$1) goto label$314;
		{
			HPOPANONPARENTS( (struct $8FBSYMBOL**)0ull );
		}
		goto label$313;
		label$314:;
		{
			struct $8FBSYMBOL* TMP$227$3;
			struct $8FBSYMBOL** vr$3 = HFINDPARENTANONALREADYONSTACK( FLD$1 );
			ANONNODE$1 = vr$3;
			HPOPANONPARENTS( ANONNODE$1 );
			if( ANONNODE$1 == (struct $8FBSYMBOL**)0ull) goto label$315;
			TMP$227$3 = *ANONNODE$1;
			goto label$1233;
			label$315:;
			TMP$227$3 = S$1;
			label$1233:;
			HPUSHANONPARENTS( TMP$227$3, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 296ll) );
		}
		label$313:;
		SKIP$1 = (int64)-((*(int64*)((uint8*)FLD$1 + 8ll) & 4ll) != 0ll);
		if( SKIP$1 != 0ll) goto label$317;
		{
			FBSTRING TMP$228$3;
			FBSTRING TMP$229$3;
			int64 TMP$233$3;
			DTYPE$1 = *(int64*)((uint8*)FLD$1 + 56ll) & 511ll;
			SUBTYPE$1 = *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll);
			FBSTRING* vr$12 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$12, -1ll, 0 );
			__builtin_memset( &TMP$228$3, 0, 24ll );
			FBSTRING* vr$17 = fb_StrConcat( &TMP$228$3, (void*)" ", 2ll, *(void**)((uint8*)FLD$1 + 32ll), 0ll );
			__builtin_memset( &TMP$229$3, 0, 24ll );
			FBSTRING* vr$21 = fb_StrConcat( &TMP$229$3, (void*)&LN$1, -1ll, (void*)vr$17, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$21, -1ll, 0 );
			FBSTRING* vr$23 = HEMITARRAYDECL( FLD$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$23, -1ll, 0 );
			ALIGN$1 = (int64)*(uint8*)((uint8*)S$1 + 213ll);
			if( ALIGN$1 <= 0ll) goto label$319;
			{
				int64 TMP$230$4;
				int64 vr$27 = TYPECALCNATURALALIGN( DTYPE$1, SUBTYPE$1 );
				SKIP$1 = (int64)-(ALIGN$1 >= vr$27);
				if( (DTYPE$1 & 480ll) == 0ll) goto label$320;
				TMP$230$4 = 24ll;
				goto label$1234;
				label$320:;
				TMP$230$4 = DTYPE$1 & 31ll;
				label$1234:;
				if( TMP$230$4 != 20ll) goto label$322;
				{
					uint8 FIELDUDTALIGN$5;
					FIELDUDTALIGN$5 = *(uint8*)((uint8*)SUBTYPE$1 + 213ll);
					if( (int64)FIELDUDTALIGN$5 <= 0ll) goto label$324;
					{
						SKIP$1 = SKIP$1 | (int64)-(ALIGN$1 >= (int64)FIELDUDTALIGN$5);
					}
					label$324:;
					label$323:;
				}
				label$322:;
				label$321:;
				if( SKIP$1 != 0ll) goto label$326;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((packed, aligned(", 33ll, 0 );
					FBSTRING* vr$37 = fb_LongintToStr( ALIGN$1 );
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$37, -1ll, 0 );
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)")))", 4ll, 0 );
				}
				label$326:;
				label$325:;
			}
			label$319:;
			label$318:;
			if( ALIGN$1 <= 0ll) goto label$327;
			TMP$233$3 = (int64)-(SKIP$1 != 0ll);
			goto label$1235;
			label$327:;
			TMP$233$3 = -1ll;
			label$1235:;
			if( TMP$233$3 == 0ll) goto label$329;
			{
				int64 TMP$234$4;
				if( (DTYPE$1 & 480ll) == 0ll) goto label$330;
				TMP$234$4 = 24ll;
				goto label$1236;
				label$330:;
				TMP$234$4 = DTYPE$1 & 31ll;
				label$1236:;
				if( TMP$234$4 != 20ll) goto label$332;
				{
					int64 TMP$235$5;
					int64 TMP$236$5;
					int64 EFFECTIVEALIGN$5;
					int64 vr$43 = TYPECALCNATURALALIGN( DTYPE$1, SUBTYPE$1 );
					EFFECTIVEALIGN$5 = vr$43;
					if( ALIGN$1 <= 0ll) goto label$333;
					TMP$235$5 = (int64)-(ALIGN$1 < EFFECTIVEALIGN$5);
					goto label$1237;
					label$333:;
					TMP$235$5 = 0ll;
					label$1237:;
					if( TMP$235$5 == 0ll) goto label$335;
					{
						EFFECTIVEALIGN$5 = ALIGN$1;
					}
					label$335:;
					label$334:;
					uint8 FIELDUDTALIGN$5;
					FIELDUDTALIGN$5 = *(uint8*)((uint8*)SUBTYPE$1 + 213ll);
					if( (int64)FIELDUDTALIGN$5 <= 0ll) goto label$336;
					TMP$236$5 = (int64)-(EFFECTIVEALIGN$5 > (int64)FIELDUDTALIGN$5);
					goto label$1238;
					label$336:;
					TMP$236$5 = 0ll;
					label$1238:;
					if( TMP$236$5 == 0ll) goto label$338;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __attribute__((aligned(", 25ll, 0 );
						FBSTRING* vr$50 = fb_LongintToStr( EFFECTIVEALIGN$5 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$50, -1ll, 0 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)")))", 4ll, 0 );
					}
					label$338:;
					label$337:;
				}
				label$332:;
				label$331:;
			}
			label$329:;
			label$328:;
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)";", 2ll, 0 );
			HWRITELINE( &LN$1, -1ll );
		}
		label$317:;
		label$316:;
		struct $8FBSYMBOL* vr$55 = SYMBUDTGETNEXTFIELD( FLD$1 );
		FLD$1 = vr$55;
	}
	goto label$311;
	label$312:;
	HPOPANONPARENTS( (struct $8FBSYMBOL**)0ull );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$310:;
}

static void HEMITSTRUCT( struct $8FBSYMBOL* S$1, int64 IS_PTR$1 )
{
	FBSTRING TMP$247$1;
	FBSTRING TMP$250$1;
	FBSTRING TMP$251$1;
	FBSTRING TMP$252$1;
	FBSTRING TMP$253$1;
	FBSTRING TMP$254$1;
	label$339:;
	int64 EMIT_FIELDS$1;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	if( (*(int64*)((uint8*)S$1 + 24ll) & 134217728ll) == 0ll) goto label$342;
	{
		if( IS_PTR$1 == 0ll) goto label$344;
		{
			if( (*(int64*)((uint8*)S$1 + 24ll) & 2ll) != 0ll) goto label$346;
			{
				FBSTRING TMP$238$4;
				FBSTRING TMP$239$4;
				*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 2ll;
				__builtin_memset( &TMP$239$4, 0, 24ll );
				FBSTRING* vr$9 = HGETUDTNAME( S$1 );
				__builtin_memset( &TMP$238$4, 0, 24ll );
				FBSTRING* vr$12 = fb_StrConcat( &TMP$238$4, (void*)vr$9, -1ll, (void*)";", 2ll );
				fb_StrAssign( (void*)&TMP$239$4, -1ll, (void*)vr$12, -1ll, 0 );
				HWRITELINE( &TMP$239$4, 0ll );
				fb_StrDelete( (FBSTRING*)&TMP$239$4 );
			}
			label$346:;
			label$345:;
			fb_StrDelete( (FBSTRING*)&LN$1 );
			goto label$340;
		}
		label$344:;
		label$343:;
	}
	label$342:;
	label$341:;
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 134217728ll;
	EMIT_FIELDS$1 = (int64)-(((int64)*(int32*)((uint8*)S$1 + 208ll) & 32768ll) == 0ll);
	if( EMIT_FIELDS$1 == 0ll) goto label$348;
	{
		HEMITFIELDTYPES( S$1 );
	}
	label$348:;
	label$347:;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 67108864ll) == 0ll) goto label$350;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$340;
	}
	label$350:;
	label$349:;
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 67108864ll;
	FBSTRING* vr$30 = HGETUDTTAG( S$1 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$30, -1ll, 0 );
	if( ((int64)-(*(int64*)((uint8*)&ENV$ + 216ll) == 0ll) & (int64)-((int64)*(uint8*)((uint8*)S$1 + 213ll) > 0ll)) == 0ll) goto label$352;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"__attribute__((gcc_struct)) ", 29ll, 0 );
	}
	label$352:;
	label$351:;
	FBSTRING* vr$38 = HGETUDTID( S$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$38, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" {", 3ll, 0 );
	HWRITELINE( &LN$1, -1ll );
	SECTIONINDENT(  );
	if( EMIT_FIELDS$1 == 0ll) goto label$354;
	{
		HEMITSTRUCTWITHFIELDS( S$1 );
	}
	goto label$353;
	label$354:;
	{
		FBSTRING TMP$244$2;
		FBSTRING TMP$245$2;
		FBSTRING TMP$246$2;
		__builtin_memset( &TMP$246$2, 0, 24ll );
		FBSTRING* vr$44 = fb_LongintToStr( *(int64*)((uint8*)S$1 + 80ll) );
		__builtin_memset( &TMP$244$2, 0, 24ll );
		FBSTRING* vr$47 = fb_StrConcat( &TMP$244$2, (void*)"uint8 __fb_struct_body[", 24ll, (void*)vr$44, -1ll );
		__builtin_memset( &TMP$245$2, 0, 24ll );
		FBSTRING* vr$50 = fb_StrConcat( &TMP$245$2, (void*)vr$47, -1ll, (void*)"];", 3ll );
		fb_StrAssign( (void*)&TMP$246$2, -1ll, (void*)vr$50, -1ll, 0 );
		HWRITELINE( &TMP$246$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$246$2 );
	}
	label$353:;
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$247$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$247$1, -1ll, (void*)"};", 3ll, 0 );
	HWRITELINE( &TMP$247$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$247$1 );
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) & -134217729ll;
	__builtin_memset( &TMP$254$1, 0, 24ll );
	FBSTRING* vr$63 = fb_ULongintToStr( *(uint64*)((uint8*)S$1 + 80ll) );
	FBSTRING* vr$64 = HGETUDTID( S$1 );
	FBSTRING* vr$65 = HGETUDTTAG( S$1 );
	__builtin_memset( &TMP$250$1, 0, 24ll );
	FBSTRING* vr$68 = fb_StrConcat( &TMP$250$1, (void*)"sizeof( ", 9ll, (void*)vr$65, -1ll );
	__builtin_memset( &TMP$251$1, 0, 24ll );
	FBSTRING* vr$71 = fb_StrConcat( &TMP$251$1, (void*)vr$68, -1ll, (void*)vr$64, -1ll );
	__builtin_memset( &TMP$252$1, 0, 24ll );
	FBSTRING* vr$74 = fb_StrConcat( &TMP$252$1, (void*)vr$71, -1ll, (void*)" ) == ", 7ll );
	__builtin_memset( &TMP$253$1, 0, 24ll );
	FBSTRING* vr$77 = fb_StrConcat( &TMP$253$1, (void*)vr$74, -1ll, (void*)vr$63, -1ll );
	fb_StrAssign( (void*)&TMP$254$1, -1ll, (void*)vr$77, -1ll, 0 );
	HWRITESTATICASSERT( &TMP$254$1 );
	fb_StrDelete( (FBSTRING*)&TMP$254$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$340:;
}

static void HWRITEX86F2I( FBSTRING* FNAME$1, int64 RTYPE$1, int64 PTYPE$1 )
{
	FBSTRING TMP$260$1;
	FBSTRING TMP$264$1;
	FBSTRING TMP$265$1;
	FBSTRING TMP$266$1;
	FBSTRING TMP$267$1;
	FBSTRING TMP$268$1;
	FBSTRING TMP$269$1;
	FBSTRING TMP$270$1;
	FBSTRING TMP$272$1;
	FBSTRING TMP$275$1;
	FBSTRING TMP$276$1;
	FBSTRING TMP$277$1;
	FBSTRING TMP$279$1;
	FBSTRING TMP$282$1;
	FBSTRING TMP$283$1;
	FBSTRING TMP$284$1;
	FBSTRING TMP$287$1;
	FBSTRING TMP$288$1;
	FBSTRING TMP$289$1;
	FBSTRING TMP$291$1;
	FBSTRING TMP$293$1;
	FBSTRING TMP$295$1;
	FBSTRING TMP$297$1;
	FBSTRING TMP$299$1;
	FBSTRING TMP$301$1;
	label$355:;
	FBSTRING RTYPE_STR$1;
	FBSTRING* vr$0 = HEMITTYPE( RTYPE$1, (struct $8FBSYMBOL*)0ull );
	fb_StrInit( (void*)&RTYPE_STR$1, -1ll, (void*)vr$0, -1ll, 0 );
	FBSTRING PTYPE_STR$1;
	FBSTRING* vr$2 = HEMITTYPE( PTYPE$1, (struct $8FBSYMBOL*)0ull );
	fb_StrInit( (void*)&PTYPE_STR$1, -1ll, (void*)vr$2, -1ll, 0 );
	FBSTRING RTYPE_SUFFIX$1;
	__builtin_memset( &RTYPE_SUFFIX$1, 0, 24ll );
	FBSTRING PTYPE_SUFFIX$1;
	__builtin_memset( &PTYPE_SUFFIX$1, 0, 24ll );
	if( *(int64*)((uint8*)&ENV$ + 264ll) != 1ll) goto label$358;
	{
		{
			int64 TMP$255$3;
			int64 TMP$256$3;
			if( (RTYPE$1 & 480ll) == 0ll) goto label$359;
			TMP$255$3 = 24ll;
			goto label$1239;
			label$359:;
			TMP$255$3 = RTYPE$1 & 31ll;
			label$1239:;
			TMP$256$3 = *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$255$3 * 56ll)) + 8ll);
			if( TMP$256$3 != 4ll) goto label$361;
			label$362:;
			{
				fb_StrAssign( (void*)&RTYPE_SUFFIX$1, -1ll, (void*)"l", 2ll, 0 );
			}
			goto label$360;
			label$361:;
			if( TMP$256$3 != 8ll) goto label$363;
			label$364:;
			{
				fb_StrAssign( (void*)&RTYPE_SUFFIX$1, -1ll, (void*)"q", 2ll, 0 );
			}
			label$363:;
			label$360:;
		}
		if( PTYPE$1 != 15ll) goto label$366;
		{
			fb_StrAssign( (void*)&PTYPE_SUFFIX$1, -1ll, (void*)"s", 2ll, 0 );
		}
		goto label$365;
		label$366:;
		{
			fb_StrAssign( (void*)&PTYPE_SUFFIX$1, -1ll, (void*)"l", 2ll, 0 );
		}
		label$365:;
	}
	label$358:;
	label$357:;
	__builtin_memset( &TMP$260$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$260$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$260$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$260$1 );
	__builtin_memset( &TMP$270$1, 0, 24ll );
	__builtin_memset( &TMP$264$1, 0, 24ll );
	FBSTRING* vr$22 = fb_StrConcat( &TMP$264$1, (void*)"static inline ", 15ll, (void*)&RTYPE_STR$1, -1ll );
	__builtin_memset( &TMP$265$1, 0, 24ll );
	FBSTRING* vr$25 = fb_StrConcat( &TMP$265$1, (void*)vr$22, -1ll, (void*)" fb_", 5ll );
	__builtin_memset( &TMP$266$1, 0, 24ll );
	FBSTRING* vr$28 = fb_StrConcat( &TMP$266$1, (void*)vr$25, -1ll, (void*)FNAME$1, -1ll );
	__builtin_memset( &TMP$267$1, 0, 24ll );
	FBSTRING* vr$31 = fb_StrConcat( &TMP$267$1, (void*)vr$28, -1ll, (void*)"( ", 3ll );
	__builtin_memset( &TMP$268$1, 0, 24ll );
	FBSTRING* vr$34 = fb_StrConcat( &TMP$268$1, (void*)vr$31, -1ll, (void*)&PTYPE_STR$1, -1ll );
	__builtin_memset( &TMP$269$1, 0, 24ll );
	FBSTRING* vr$37 = fb_StrConcat( &TMP$269$1, (void*)vr$34, -1ll, (void*)" value )", 9ll );
	fb_StrAssign( (void*)&TMP$270$1, -1ll, (void*)vr$37, -1ll, 0 );
	HWRITELINE( &TMP$270$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$270$1 );
	__builtin_memset( &TMP$272$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$272$1, -1ll, (void*)"{", 2ll, 0 );
	HWRITELINE( &TMP$272$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$272$1 );
	SECTIONINDENT(  );
	__builtin_memset( &TMP$277$1, 0, 24ll );
	__builtin_memset( &TMP$275$1, 0, 24ll );
	FBSTRING* vr$49 = fb_StrConcat( &TMP$275$1, (void*)"volatile ", 10ll, (void*)&RTYPE_STR$1, -1ll );
	__builtin_memset( &TMP$276$1, 0, 24ll );
	FBSTRING* vr$52 = fb_StrConcat( &TMP$276$1, (void*)vr$49, -1ll, (void*)" result;", 9ll );
	fb_StrAssign( (void*)&TMP$277$1, -1ll, (void*)vr$52, -1ll, 0 );
	HWRITELINE( &TMP$277$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$277$1 );
	__builtin_memset( &TMP$279$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$279$1, -1ll, (void*)"__asm__(", 9ll, 0 );
	HWRITELINE( &TMP$279$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$279$1 );
	SECTIONINDENT(  );
	__builtin_memset( &TMP$284$1, 0, 24ll );
	__builtin_memset( &TMP$282$1, 0, 24ll );
	FBSTRING* vr$64 = fb_StrConcat( &TMP$282$1, (void*)"\x22" "fld", 5ll, (void*)&PTYPE_SUFFIX$1, -1ll );
	__builtin_memset( &TMP$283$1, 0, 24ll );
	FBSTRING* vr$67 = fb_StrConcat( &TMP$283$1, (void*)vr$64, -1ll, (void*)" %1;\x22", 6ll );
	fb_StrAssign( (void*)&TMP$284$1, -1ll, (void*)vr$67, -1ll, 0 );
	HWRITELINE( &TMP$284$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$284$1 );
	__builtin_memset( &TMP$289$1, 0, 24ll );
	__builtin_memset( &TMP$287$1, 0, 24ll );
	FBSTRING* vr$75 = fb_StrConcat( &TMP$287$1, (void*)"\x22" "fistp", 7ll, (void*)&RTYPE_SUFFIX$1, -1ll );
	__builtin_memset( &TMP$288$1, 0, 24ll );
	FBSTRING* vr$78 = fb_StrConcat( &TMP$288$1, (void*)vr$75, -1ll, (void*)" %0;\x22", 6ll );
	fb_StrAssign( (void*)&TMP$289$1, -1ll, (void*)vr$78, -1ll, 0 );
	HWRITELINE( &TMP$289$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$289$1 );
	__builtin_memset( &TMP$291$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$291$1, -1ll, (void*)":\x22=m\x22 (result)", 15ll, 0 );
	HWRITELINE( &TMP$291$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$291$1 );
	__builtin_memset( &TMP$293$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$293$1, -1ll, (void*)":\x22m\x22 (value)", 13ll, 0 );
	HWRITELINE( &TMP$293$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$293$1 );
	__builtin_memset( &TMP$295$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$295$1, -1ll, (void*)":\x22st\x22", 6ll, 0 );
	HWRITELINE( &TMP$295$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$295$1 );
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$297$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$297$1, -1ll, (void*)");", 3ll, 0 );
	HWRITELINE( &TMP$297$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$297$1 );
	__builtin_memset( &TMP$299$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$299$1, -1ll, (void*)"return result;", 15ll, 0 );
	HWRITELINE( &TMP$299$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$299$1 );
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$301$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$301$1, -1ll, (void*)"}", 2ll, 0 );
	HWRITELINE( &TMP$301$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$301$1 );
	fb_StrDelete( (FBSTRING*)&PTYPE_SUFFIX$1 );
	fb_StrDelete( (FBSTRING*)&RTYPE_SUFFIX$1 );
	fb_StrDelete( (FBSTRING*)&PTYPE_STR$1 );
	fb_StrDelete( (FBSTRING*)&RTYPE_STR$1 );
	label$356:;
}

static void HWRITEGENERICF2I( FBSTRING* FNAME$1, int64 RTYPE$1, int64 PTYPE$1 )
{
	FBSTRING TMP$308$1;
	FBSTRING TMP$309$1;
	FBSTRING TMP$310$1;
	FBSTRING TMP$311$1;
	FBSTRING TMP$312$1;
	FBSTRING TMP$313$1;
	FBSTRING TMP$314$1;
	label$367:;
	FBSTRING CALLNAME$1;
	__builtin_memset( &CALLNAME$1, 0, 24ll );
	if( PTYPE$1 != 15ll) goto label$370;
	{
		fb_StrAssign( (void*)&CALLNAME$1, -1ll, (void*)"nearbyintf", 11ll, 0 );
	}
	goto label$369;
	label$370:;
	{
		fb_StrAssign( (void*)&CALLNAME$1, -1ll, (void*)"nearbyint", 10ll, 0 );
	}
	label$369:;
	__builtin_memset( &TMP$314$1, 0, 24ll );
	FBSTRING* vr$5 = HEMITTYPE( RTYPE$1, (struct $8FBSYMBOL*)0ull );
	__builtin_memset( &TMP$308$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$308$1, (void*)"#define fb_", 12ll, (void*)FNAME$1, -1ll );
	__builtin_memset( &TMP$309$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$309$1, (void*)vr$8, -1ll, (void*)"( value ) ((", 13ll );
	__builtin_memset( &TMP$310$1, 0, 24ll );
	FBSTRING* vr$14 = fb_StrConcat( &TMP$310$1, (void*)vr$11, -1ll, (void*)vr$5, -1ll );
	__builtin_memset( &TMP$311$1, 0, 24ll );
	FBSTRING* vr$17 = fb_StrConcat( &TMP$311$1, (void*)vr$14, -1ll, (void*)")__builtin_", 12ll );
	__builtin_memset( &TMP$312$1, 0, 24ll );
	FBSTRING* vr$20 = fb_StrConcat( &TMP$312$1, (void*)vr$17, -1ll, (void*)&CALLNAME$1, -1ll );
	__builtin_memset( &TMP$313$1, 0, 24ll );
	FBSTRING* vr$23 = fb_StrConcat( &TMP$313$1, (void*)vr$20, -1ll, (void*)"( value ))", 11ll );
	fb_StrAssign( (void*)&TMP$314$1, -1ll, (void*)vr$23, -1ll, 0 );
	HWRITELINE( &TMP$314$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$314$1 );
	fb_StrDelete( (FBSTRING*)&CALLNAME$1 );
	label$368:;
}

static void HWRITEF2I( FBSTRING* FNAME$1, int64 RTYPE$1, int64 PTYPE$1 )
{
	label$371:;
	int64 vr$0 = FBGETCPUFAMILY(  );
	if( vr$0 != 0ll) goto label$374;
	{
		{
			if( RTYPE$1 == 11ll) goto label$377;
			label$378:;
			if( RTYPE$1 != 13ll) goto label$376;
			label$377:;
			{
				HWRITEX86F2I( FNAME$1, RTYPE$1, PTYPE$1 );
				goto label$372;
			}
			label$376:;
			label$375:;
		}
	}
	label$374:;
	label$373:;
	HWRITEGENERICF2I( FNAME$1, RTYPE$1, PTYPE$1 );
	label$372:;
}

static void HMAYBEEMITPROCEXPORT( struct $8FBSYMBOL* PROC$1 )
{
	label$379:;
	if( (*(int64*)((uint8*)PROC$1 + 8ll) & 256ll) != 0ll) goto label$382;
	{
		goto label$380;
	}
	label$382:;
	label$381:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x09\x22", 3ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x5Ct.ascii ", 10ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x5C\x22 -export:\x5C\x5C\x5C\x22", 16ll, 0 );
	FBSTRING* vr$5 = HGETMANGLEDNAMEFORASM( PROC$1, 0ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)vr$5, -1ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x5C\x5C\x5C\x22\x5C\x22", 7ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x5Cn", 3ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"\x22\x0A", 3ll, 0 );
	label$380:;
}

static int64 _EMITBEGIN( void )
{
	FBSTRING TMP$322$1;
	FBSTRING TMP$324$1;
	FBSTRING TMP$326$1;
	FBSTRING TMP$328$1;
	FBSTRING TMP$330$1;
	FBSTRING TMP$332$1;
	FBSTRING TMP$334$1;
	FBSTRING TMP$336$1;
	FBSTRING TMP$342$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$383:;
	int64 vr$2 = HFILEEXISTS( (char*)((uint8*)&ENV$ + 928ll) );
	if( vr$2 == 0ll) goto label$386;
	{
		FBSTRING* vr$4 = fb_StrAllocTempDescZ( (char*)((uint8*)&ENV$ + 928ll) );
		fb_FileKill( (FBSTRING*)vr$4 );
	}
	label$386:;
	label$385:;
	int32 vr$5 = fb_FileFree(  );
	*(int64*)((uint8*)&ENV$ + 920ll) = (int64)vr$5;
	FBSTRING* vr$9 = fb_StrAllocTempDescZ( (char*)((uint8*)&ENV$ + 928ll) );
	int32 vr$10 = fb_FileOpen( (FBSTRING*)vr$9, 0u, 3u, 0u, (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0 );
	if( (int64)vr$10 == 0ll) goto label$388;
	{
		fb$result$1 = 0ll;
		goto label$384;
	}
	label$388:;
	label$387:;
	*(int64*)((uint8*)&CTX$ + 5160ll) = -1ll;
	*(int64*)((uint8*)&CTX$ + 5168ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 5176ll) = 0ll;
	*(uint64*)((uint8*)&CTX$ + 5208ll) = 0ull;
	*(int64*)((uint8*)&CTX$ + 5512ll) = 0ll;
	HUPDATECURRENTFILENAME( (char*)((uint8*)&ENV$ + 632ll) );
	SECTIONBEGIN(  );
	if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$390;
	{
		_EMITDBG( 114ll, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	}
	label$390:;
	label$389:;
	__builtin_memset( &TMP$322$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$322$1, -1ll, (void*)"typedef   signed char       int8;", 34ll, 0 );
	HWRITELINE( &TMP$322$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$322$1 );
	__builtin_memset( &TMP$324$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$324$1, -1ll, (void*)"typedef unsigned char      uint8;", 34ll, 0 );
	HWRITELINE( &TMP$324$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$324$1 );
	__builtin_memset( &TMP$326$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$326$1, -1ll, (void*)"typedef   signed short      int16;", 35ll, 0 );
	HWRITELINE( &TMP$326$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$326$1 );
	__builtin_memset( &TMP$328$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$328$1, -1ll, (void*)"typedef unsigned short     uint16;", 35ll, 0 );
	HWRITELINE( &TMP$328$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$328$1 );
	__builtin_memset( &TMP$330$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$330$1, -1ll, (void*)"typedef   signed int        int32;", 35ll, 0 );
	HWRITELINE( &TMP$330$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$330$1 );
	__builtin_memset( &TMP$332$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$332$1, -1ll, (void*)"typedef unsigned int       uint32;", 35ll, 0 );
	HWRITELINE( &TMP$332$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$332$1 );
	__builtin_memset( &TMP$334$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$334$1, -1ll, (void*)"typedef   signed long long  int64;", 35ll, 0 );
	HWRITELINE( &TMP$334$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$334$1 );
	__builtin_memset( &TMP$336$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$336$1, -1ll, (void*)"typedef unsigned long long uint64;", 35ll, 0 );
	HWRITELINE( &TMP$336$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$336$1 );
	int64 vr$45 = FBIS64BIT(  );
	if( vr$45 == 0ll) goto label$392;
	{
		FBSTRING TMP$338$2;
		__builtin_memset( &TMP$338$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$338$2, -1ll, (void*)"typedef struct { char *data; int64 len; int64 size; } FBSTRING;", 64ll, 0 );
		HWRITELINE( &TMP$338$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$338$2 );
	}
	goto label$391;
	label$392:;
	{
		FBSTRING TMP$340$2;
		__builtin_memset( &TMP$340$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$340$2, -1ll, (void*)"typedef struct { char *data; int32 len; int32 size; } FBSTRING;", 64ll, 0 );
		HWRITELINE( &TMP$340$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$340$2 );
	}
	label$391:;
	__builtin_memset( &TMP$342$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$342$1, -1ll, (void*)"typedef int8 boolean;", 22ll, 0 );
	HWRITELINE( &TMP$342$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$342$1 );
	SECTIONBEGIN(  );
	fb$result$1 = -1ll;
	label$384:;
	return fb$result$1;
}

static void _EMITEND( void )
{
	label$393:;
	int64 SECTION$1;
	HUPDATECURRENTFILENAME( (char*)((uint8*)&ENV$ + 632ll) );
	int64 vr$1 = SECTIONGOSUB( 0ll );
	SECTION$1 = vr$1;
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 1ull) == 0ull) goto label$396;
	{
		FBSTRING TMP$344$2;
		__builtin_memset( &TMP$344$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$344$2, -1ll, (void*)"F2I", 4ll, 0 );
		HWRITEF2I( &TMP$344$2, 11ll, 15ll );
		fb_StrDelete( (FBSTRING*)&TMP$344$2 );
		label$396:;
	}
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 2ull) == 0ull) goto label$398;
	{
		FBSTRING TMP$346$2;
		__builtin_memset( &TMP$346$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$346$2, -1ll, (void*)"F2L", 4ll, 0 );
		HWRITEF2I( &TMP$346$2, 13ll, 15ll );
		fb_StrDelete( (FBSTRING*)&TMP$346$2 );
		label$398:;
	}
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 4ull) == 0ull) goto label$400;
	{
		FBSTRING TMP$348$2;
		__builtin_memset( &TMP$348$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$348$2, -1ll, (void*)"F2UL", 5ll, 0 );
		HWRITEF2I( &TMP$348$2, 14ll, 15ll );
		fb_StrDelete( (FBSTRING*)&TMP$348$2 );
		label$400:;
	}
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 8ull) == 0ull) goto label$402;
	{
		FBSTRING TMP$350$2;
		__builtin_memset( &TMP$350$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$350$2, -1ll, (void*)"D2I", 4ll, 0 );
		HWRITEF2I( &TMP$350$2, 11ll, 16ll );
		fb_StrDelete( (FBSTRING*)&TMP$350$2 );
		label$402:;
	}
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 16ull) == 0ull) goto label$404;
	{
		FBSTRING TMP$352$2;
		__builtin_memset( &TMP$352$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$352$2, -1ll, (void*)"D2L", 4ll, 0 );
		HWRITEF2I( &TMP$352$2, 13ll, 16ll );
		fb_StrDelete( (FBSTRING*)&TMP$352$2 );
		label$404:;
	}
	if( (*(uint64*)((uint8*)&CTX$ + 5208ll) & 32ull) == 0ull) goto label$406;
	{
		FBSTRING TMP$354$2;
		__builtin_memset( &TMP$354$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$354$2, -1ll, (void*)"D2UL", 5ll, 0 );
		HWRITEF2I( &TMP$354$2, 14ll, 16ll );
		fb_StrDelete( (FBSTRING*)&TMP$354$2 );
		label$406:;
	}
	SYMBFOREACHGLOBAL( 3ll, (tmp$43)&HMAYBEEMITPROCPROTO );
	*(int64*)((uint8*)&CTX$ + 5512ll) = 1ll;
	SYMBFOREACHGLOBAL( 1ll, (tmp$43)&HMAYBEEMITGLOBALVAREXCEPTDATASTMT );
	IRFOREACHDATASTMT( (tmp$43)&HMAYBEEMITGLOBALVAR );
	*(int64*)((uint8*)&CTX$ + 5512ll) = 2ll;
	SYMBFOREACHGLOBAL( 1ll, (tmp$43)&HMAYBEEMITGLOBALVAREXCEPTDATASTMT );
	IRFOREACHDATASTMT( (tmp$43)&HMAYBEEMITGLOBALVAR );
	SECTIONRETURN( SECTION$1 );
	if( (*(int64*)((uint8*)&ENV$ + 456ll) & (*(int64*)((uint8*)&ENV$ + 592ll) & 4ll)) == 0ll) goto label$408;
	{
		SYMBFOREACHGLOBAL( 3ll, (tmp$43)&HMAYBEEMITPROCEXPORT );
		int64 vr$35 = fb_StrLen( (void*)((uint8*)&CTX$ + 5336ll), -1ll );
		if( vr$35 <= 0ll) goto label$410;
		{
			FBSTRING TMP$356$3;
			FBSTRING TMP$357$3;
			FBSTRING TMP$358$3;
			FBSTRING TMP$360$3;
			__builtin_memset( &TMP$358$3, 0, 24ll );
			__builtin_memset( &TMP$356$3, 0, 24ll );
			FBSTRING* vr$40 = fb_StrConcat( &TMP$356$3, (void*)"\x0A__asm__( \x0A\x09\x22.section .drectve\x5Cn\x22\x0A", 35ll, (void*)((uint8*)&CTX$ + 5336ll), -1ll );
			__builtin_memset( &TMP$357$3, 0, 24ll );
			FBSTRING* vr$43 = fb_StrConcat( &TMP$357$3, (void*)vr$40, -1ll, (void*)");", 3ll );
			fb_StrAssign( (void*)&TMP$358$3, -1ll, (void*)vr$43, -1ll, 0 );
			HWRITELINE( &TMP$358$3, -1ll );
			fb_StrDelete( (FBSTRING*)&TMP$358$3 );
			__builtin_memset( &TMP$360$3, 0, 24ll );
			fb_StrAssign( (void*)&TMP$360$3, -1ll, (void*)"__asm__( \x22.text\x22 );", 20ll, 0 );
			HWRITELINE( &TMP$360$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$360$3 );
		}
		label$410:;
		label$409:;
		fb_StrAssign( (void*)((uint8*)&CTX$ + 5336ll), -1ll, (void*)"", 1ll, 0 );
	}
	label$408:;
	label$407:;
	SECTIONEND(  );
	if( *(int64*)((uint8*)&CTX$ + 24ll) != 0ll) goto label$412;
	{
		int32 vr$54 = fb_FilePutStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0ll, (void*)&CTX$, -1ll );
		if( (int64)vr$54 == 0ll) goto label$414;
		{
		}
		label$414:;
		label$413:;
	}
	label$412:;
	label$411:;
	SECTIONEND(  );
	int32 vr$57 = fb_FileClose( (int32)*(int64*)((uint8*)&ENV$ + 920ll) );
	if( (int64)vr$57 == 0ll) goto label$416;
	{
	}
	label$416:;
	label$415:;
	*(int64*)((uint8*)&ENV$ + 920ll) = 0ll;
	label$394:;
}

static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE OPT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$417:;
	{
		if( OPT$1 != 1ll) goto label$420;
		label$421:;
		{
			fb$result$1 = 0ll;
			goto label$418;
		}
		goto label$419;
		label$420:;
		{
			ERRREPORTEX( 21ll, (char*)"_GETOPTIONVALUE", 0ll, 1ll, (char*)0ull );
		}
		label$422:;
		label$419:;
	}
	label$418:;
	return fb$result$1;
}

static int64 _SUPPORTSOP( int64 OP$1, int64 DTYPE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$423:;
	{
		uint64 TMP$362$2;
		TMP$362$2 = (uint64)OP$1;
		goto label$426;
		label$427:;
		{
			fb$result$1 = 0ll;
		}
		goto label$425;
		label$428:;
		{
			fb$result$1 = -1ll;
		}
		goto label$425;
		label$426:;
		static const void* tmp$702[16ll] = {
			&&label$427,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$427,
			&&label$427,
			&&label$428,
			&&label$428,
			&&label$428,
			&&label$427,
			&&label$427,
		};
		if( (TMP$362$2 - 58ull) > 15ull ) goto label$428;
		goto *tmp$702[TMP$362$2 - 58ull];
		label$425:;
	}
	label$424:;
	return fb$result$1;
}

static void _PROCBEGIN( struct $8FBSYMBOL* PROC$1 )
{
	label$429:;
	*(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 32ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll);
	label$430:;
}

static void _PROCEND( struct $8FBSYMBOL* PROC$1 )
{
	label$431:;
	*(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 40ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll);
	label$432:;
}

static void _SCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	label$433:;
	label$434:;
}

static void _SCOPEEND( struct $8FBSYMBOL* S$1 )
{
	label$435:;
	label$436:;
}

static int64 HISSTATICWITHDTOR( struct $8FBSYMBOL* SYM$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$437:;
	int64 vr$8 = SYMBHASDTOR( SYM$1 );
	fb$result$1 = ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) != 0ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) == 0ll)) & vr$8;
	label$438:;
	return fb$result$1;
}

static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* SYM$1 )
{
	label$439:;
	struct $8FBSYMBOL* DESC$1;
	int64 SECTION$1;
	int64 vr$0 = SECTIONGOSUB( 0ll );
	SECTION$1 = vr$0;
	label$441:;
	if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$442;
	{
		{
			$12FB_SYMBCLASS TMP$363$3;
			TMP$363$3 = *($12FB_SYMBCLASS*)SYM$1;
			if( TMP$363$3 != 15ll) goto label$444;
			label$445:;
			{
				_PROCALLOCSTATICVARS( *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 112ll) );
			}
			goto label$443;
			label$444:;
			if( TMP$363$3 != 1ll) goto label$446;
			label$447:;
			{
				int64 vr$3 = HISSTATICWITHDTOR( SYM$1 );
				if( vr$3 == 0ll) goto label$449;
				{
					HMAYBEEMITLOCALVAR( SYM$1 );
					DESC$1 = *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 136ll);
					if( DESC$1 == (struct $8FBSYMBOL*)0ull) goto label$451;
					{
						HMAYBEEMITLOCALVAR( DESC$1 );
					}
					label$451:;
					label$450:;
				}
				label$449:;
				label$448:;
			}
			label$446:;
			label$443:;
		}
		SYM$1 = *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 312ll);
	}
	goto label$441;
	label$442:;
	SECTIONRETURN( SECTION$1 );
	label$440:;
}

static void _SETVREGDATATYPE( struct $6IRVREG* VREG$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	label$452:;
	if( VREG$1 == (struct $6IRVREG*)0ull) goto label$455;
	{
		*($11FB_DATATYPE*)((uint8*)VREG$1 + 8ll) = DTYPE$1;
		*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll) = SUBTYPE$1;
	}
	label$455:;
	label$454:;
	label$453:;
}

static FBSTRING* HEMITTYPE( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$456:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	int64 PTRCOUNT$1;
	$19FB_CVA_LIST_TYPEDEF vr$2 = SYMBGETVALISTTYPE( DTYPE$1, SUBTYPE$1 );
	if( vr$2 <= 1ll) goto label$459;
	{
		{
			$19FB_CVA_LIST_TYPEDEF TMP$364$3;
			$19FB_CVA_LIST_TYPEDEF vr$3 = SYMBGETVALISTTYPE( DTYPE$1, SUBTYPE$1 );
			TMP$364$3 = vr$3;
			if( TMP$364$3 != 2ll) goto label$461;
			label$462:;
			{
				DTYPE$1 = (((((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + -32ll)) | (((DTYPE$1 & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (DTYPE$1 & 32505856ll)) & -32ll) | 19ll;
			}
			goto label$460;
			label$461:;
			{
				DTYPE$1 = (DTYPE$1 & -32ll) | 19ll;
			}
			label$463:;
			label$460:;
		}
	}
	label$459:;
	label$458:;
	PTRCOUNT$1 = (DTYPE$1 & 480ll) >> (5ll & 63ll);
	DTYPE$1 = DTYPE$1 & 31ll;
	{
		uint64 TMP$365$2;
		TMP$365$2 = (uint64)DTYPE$1;
		goto label$465;
		label$466:;
		{
			if( SUBTYPE$1 == (struct $8FBSYMBOL*)0ull) goto label$468;
			{
				HEMITUDT( SUBTYPE$1, (int64)-(PTRCOUNT$1 > 0ll) );
				FBSTRING* vr$22 = HGETUDTNAME( SUBTYPE$1 );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$22, -1ll, 0 );
			}
			goto label$467;
			label$468:;
			if( DTYPE$1 != 10ll) goto label$469;
			{
				int64 TMP$366$4;
				if( (DTYPE$1 & 480ll) == 0ll) goto label$470;
				TMP$366$4 = 24ll;
				goto label$1240;
				label$470:;
				TMP$366$4 = DTYPE$1 & 31ll;
				label$1240:;
				fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$366$4 * 56ll)) + 32ll) << (3ll & 63ll))), 0ll, 0 );
			}
			goto label$467;
			label$469:;
			{
				fb_StrAssign( (void*)&S$1, -1ll, *(void**)DTYPENAME$, 0ll, 0 );
			}
			label$467:;
		}
		goto label$464;
		label$471:;
		{
			PTRCOUNT$1 = PTRCOUNT$1 + -1ll;
			HEMITUDT( SUBTYPE$1, (int64)-(PTRCOUNT$1 > 0ll) );
			char* vr$32 = SYMBGETMANGLEDNAME( SUBTYPE$1 );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$32, 0ll, 0 );
		}
		goto label$464;
		label$472:;
		{
			int64 TMP$367$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$473;
			TMP$367$3 = 24ll;
			goto label$1241;
			label$473:;
			TMP$367$3 = DTYPE$1 & 31ll;
			label$1241:;
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$367$3 * 56ll)) + 32ll) << (3ll & 63ll))), 0ll, 0 );
		}
		goto label$464;
		label$474:;
		{
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + 24ll), 0ll, 0 );
		}
		goto label$464;
		label$475:;
		{
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (DTYPE$1 << (3ll & 63ll))), 0ll, 0 );
		}
		goto label$464;
		label$465:;
		static const void* tmp$703[16ll] = {
			&&label$472,
			&&label$475,
			&&label$475,
			&&label$466,
			&&label$475,
			&&label$475,
			&&label$475,
			&&label$475,
			&&label$475,
			&&label$475,
			&&label$475,
			&&label$474,
			&&label$475,
			&&label$466,
			&&label$475,
			&&label$471,
		};
		if( (TMP$365$2 - 7ull) > 15ull ) goto label$475;
		goto *tmp$703[TMP$365$2 - 7ull];
		label$464:;
	}
	if( PTRCOUNT$1 <= 0ll) goto label$477;
	{
		FBSTRING* vr$42 = fb_StrAllocTempDescZEx( (char*)"*", 1ll );
		FBSTRING* vr$43 = fb_StrFill2( PTRCOUNT$1, (FBSTRING*)vr$42 );
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$43, -1ll, 0 );
	}
	label$477:;
	label$476:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$457:;
	FBSTRING* vr$49 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$49;
}

static struct $8EXPRNODE* EXPRNEW( int64 CLASS_$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$478:;
	struct $8EXPRNODE* N$1;
	void* vr$2 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5360ll) );
	N$1 = (struct $8EXPRNODE*)vr$2;
	*(int64*)N$1 = CLASS_$1;
	*(int64*)((uint8*)N$1 + 8ll) = DTYPE$1;
	*(struct $8FBSYMBOL**)((uint8*)N$1 + 16ll) = SUBTYPE$1;
	fb$result$1 = N$1;
	label$479:;
	return fb$result$1;
}

static void EXPRFREENODE( struct $8EXPRNODE* N$1 )
{
	label$480:;
	if( *(int64*)N$1 != 0ll) goto label$483;
	{
		if( *(char**)((uint8*)N$1 + 40ll) == (char*)0ull) goto label$485;
		{
			free( *(void**)((uint8*)N$1 + 40ll) );
		}
		label$485:;
		label$484:;
	}
	label$483:;
	label$482:;
	LISTDELNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5360ll), (void*)N$1 );
	label$481:;
}

static void EXPRFREETREE( struct $8EXPRNODE* N$1 )
{
	label$486:;
	if( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) == (struct $8EXPRNODE*)0ull) goto label$489;
	{
		EXPRFREETREE( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) );
	}
	label$489:;
	label$488:;
	if( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll) == (struct $8EXPRNODE*)0ull) goto label$491;
	{
		EXPRFREETREE( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll) );
	}
	label$491:;
	label$490:;
	EXPRFREENODE( N$1 );
	label$487:;
}

static struct $8EXPRNODE* EXPRNEWTEXT( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, char* S$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$492:;
	struct $8EXPRNODE* N$1;
	struct $8EXPRNODE* vr$1 = EXPRNEW( 0ll, DTYPE$1, SUBTYPE$1 );
	N$1 = vr$1;
	char* vr$2 = ZSTRDUP( S$1 );
	*(char**)((uint8*)N$1 + 40ll) = vr$2;
	fb$result$1 = N$1;
	label$493:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWIMMI( int64 I$1, int64 DTYPE$1 )
{
	int64 TMP$369$1;
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$494:;
	struct $8EXPRNODE* N$1;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$496;
	TMP$369$1 = 24ll;
	goto label$1242;
	label$496:;
	TMP$369$1 = DTYPE$1 & 31ll;
	label$1242:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$369$1 * 56ll)) + 8ll) != 8ll) goto label$498;
	{
		int64 TMP$370$2;
		$11FB_DATATYPE TMP$371$2;
		if( (DTYPE$1 & 480ll) == 0ll) goto label$499;
		TMP$370$2 = 24ll;
		goto label$1243;
		label$499:;
		TMP$370$2 = DTYPE$1 & 31ll;
		label$1243:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$370$2 * 56ll)) + 16ll) == 0ll) goto label$500;
		TMP$371$2 = 13ll;
		goto label$1244;
		label$500:;
		TMP$371$2 = 14ll;
		label$1244:;
		DTYPE$1 = TMP$371$2;
	}
	goto label$497;
	label$498:;
	{
		int64 TMP$372$2;
		$11FB_DATATYPE TMP$373$2;
		if( (DTYPE$1 & 480ll) == 0ll) goto label$501;
		TMP$372$2 = 24ll;
		goto label$1245;
		label$501:;
		TMP$372$2 = DTYPE$1 & 31ll;
		label$1245:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$372$2 * 56ll)) + 16ll) == 0ll) goto label$502;
		TMP$373$2 = 11ll;
		goto label$1246;
		label$502:;
		TMP$373$2 = 12ll;
		label$1246:;
		DTYPE$1 = TMP$373$2;
	}
	label$497:;
	struct $8EXPRNODE* vr$10 = EXPRNEW( 1ll, DTYPE$1, (struct $8FBSYMBOL*)0ull );
	N$1 = vr$10;
	*(int64*)((uint8*)N$1 + 40ll) = I$1;
	fb$result$1 = N$1;
	label$495:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWIMMF( double F$1, int64 DTYPE$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$503:;
	struct $8EXPRNODE* N$1;
	struct $8EXPRNODE* vr$1 = EXPRNEW( 1ll, DTYPE$1, (struct $8FBSYMBOL*)0ull );
	N$1 = vr$1;
	*(double*)((uint8*)N$1 + 40ll) = F$1;
	fb$result$1 = N$1;
	label$504:;
	return fb$result$1;
}

static int64 SYMBISCARRAY( struct $8FBSYMBOL* SYM$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$505:;
	if( (((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) != 0ll) | (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 81920ll) != 0ll)) | (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 512ll) != 0ll)) == 0ll) goto label$508;
	{
		fb$result$1 = 0ll;
		goto label$506;
	}
	label$508:;
	label$507:;
	{
		$12FB_SYMBCLASS TMP$374$2;
		TMP$374$2 = *($12FB_SYMBCLASS*)SYM$1;
		if( TMP$374$2 == 1ll) goto label$511;
		label$512:;
		if( TMP$374$2 != 12ll) goto label$510;
		label$511:;
		{
			if( (*(int64*)((uint8*)SYM$1 + 8ll) & 4ll) == 0ll) goto label$514;
			{
				fb$result$1 = 0ll;
				goto label$506;
			}
			label$514:;
			label$513:;
			if( *(int64*)((uint8*)SYM$1 + 104ll) == 0ll) goto label$516;
			{
				fb$result$1 = -1ll;
				goto label$506;
			}
			label$516:;
			label$515:;
		}
		label$510:;
		label$509:;
	}
	{
		int64 TMP$375$2;
		TMP$375$2 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
		if( TMP$375$2 == 18ll) goto label$519;
		label$520:;
		if( TMP$375$2 == 4ll) goto label$519;
		label$521:;
		if( TMP$375$2 != 7ll) goto label$518;
		label$519:;
		{
			fb$result$1 = -1ll;
			goto label$506;
		}
		label$518:;
		label$517:;
	}
	fb$result$1 = 0ll;
	goto label$506;
	label$506:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWCAST( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, struct $8EXPRNODE* L$1 )
{
	int64 TMP$376$1;
	int64 TMP$377$1;
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$522:;
	if( ((int64)-(DTYPE$1 == *(int64*)((uint8*)L$1 + 8ll)) & (int64)-(SUBTYPE$1 == *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll))) == 0ll) goto label$525;
	{
		fb$result$1 = L$1;
		goto label$523;
	}
	label$525:;
	label$524:;
	if( (*(int64*)((uint8*)L$1 + 8ll) & 480ll) == 0ll) goto label$526;
	TMP$376$1 = 24ll;
	goto label$1247;
	label$526:;
	TMP$376$1 = *(int64*)((uint8*)L$1 + 8ll) & 31ll;
	label$1247:;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$527;
	TMP$377$1 = 24ll;
	goto label$1248;
	label$527:;
	TMP$377$1 = DTYPE$1 & 31ll;
	label$1248:;
	if( (((int64)-(*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$376$1 * 56ll)) + 40ll) == *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$377$1 * 56ll)) + 40ll)) & (int64)-((*(int64*)((uint8*)L$1 + 8ll) & 480ll) == 0ll)) & (int64)-((DTYPE$1 & 480ll) == 0ll)) == 0ll) goto label$529;
	{
		fb$result$1 = L$1;
		goto label$523;
	}
	label$529:;
	label$528:;
	if( *(int64*)L$1 != 3ll) goto label$531;
	{
		if( ((int64)-(((DTYPE$1 & 480ll) >> (5ll & 63ll)) > 0ll) & (int64)-(((*(int64*)((uint8*)L$1 + 8ll) & 480ll) >> (5ll & 63ll)) > 0ll)) == 0ll) goto label$533;
		{
			*(int64*)((uint8*)L$1 + 8ll) = DTYPE$1;
			*(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll) = SUBTYPE$1;
			fb$result$1 = L$1;
			goto label$523;
		}
		label$533:;
		label$532:;
	}
	label$531:;
	label$530:;
	if( (*(int64*)((uint8*)L$1 + 8ll) & 511ll) != 4ll) goto label$535;
	{
		struct $8EXPRNODE* N$2;
		struct $8EXPRNODE* vr$35 = EXPRNEW( 3ll, 3ll, (struct $8FBSYMBOL*)0ull );
		N$2 = vr$35;
		*(struct $8EXPRNODE**)((uint8*)N$2 + 24ll) = L$1;
		L$1 = N$2;
	}
	label$535:;
	label$534:;
	struct $8EXPRNODE* N$1;
	struct $8EXPRNODE* vr$37 = EXPRNEW( 3ll, DTYPE$1, SUBTYPE$1 );
	N$1 = vr$37;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) = L$1;
	fb$result$1 = N$1;
	label$523:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWMACRO( $6AST_OP OP$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, struct $8EXPRNODE* L$1, struct $8EXPRNODE* R$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$536:;
	struct $8EXPRNODE* N$1;
	struct $8EXPRNODE* vr$1 = EXPRNEW( 6ll, DTYPE$1, SUBTYPE$1 );
	N$1 = vr$1;
	*(int64*)((uint8*)N$1 + 40ll) = OP$1;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) = L$1;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 32ll) = R$1;
	fb$result$1 = N$1;
	label$537:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWSYM( struct $8FBSYMBOL* SYM$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$538:;
	struct $8EXPRNODE* N$1;
	int64 DTYPE$1;
	struct $8FBSYMBOL* SUBTYPE$1;
	if( ((int64)-(*(int64*)SYM$1 == 1ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 4ll) != 0ll)) == 0ll) goto label$541;
	{
		SYM$1 = *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 136ll);
	}
	label$541:;
	label$540:;
	if( *(int64*)SYM$1 != 7ll) goto label$543;
	{
		struct $8EXPRNODE* vr$9 = EXPRNEW( 2ll, 32ll, (struct $8FBSYMBOL*)0ull );
		N$1 = vr$9;
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) = SYM$1;
	}
	goto label$542;
	label$543:;
	if( *(int64*)SYM$1 != 3ll) goto label$544;
	{
		struct $8EXPRNODE* vr$12 = EXPRNEW( 2ll, 54ll, SYM$1 );
		N$1 = vr$12;
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) = SYM$1;
	}
	goto label$542;
	label$544:;
	int64 vr$14 = SYMBISCARRAY( SYM$1 );
	if( vr$14 == 0ll) goto label$545;
	{
		struct $8EXPRNODE* vr$15 = EXPRNEW( 2ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
		N$1 = vr$15;
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) = SYM$1;
		struct $8EXPRNODE* vr$35 = EXPRNEWCAST( ((((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), N$1 );
		N$1 = vr$35;
	}
	goto label$542;
	label$545:;
	if( (((int64)-(*(int64*)SYM$1 == 1ll) | (int64)-(*(int64*)SYM$1 == 4ll)) & (int64)-((*(int64*)((uint8*)SYM$1 + 24ll) & 524288ll) != 0ll)) == 0ll) goto label$546;
	{
		struct $8EXPRNODE* vr$45 = EXPRNEW( 2ll, 66ll, (struct $8FBSYMBOL*)0ull );
		N$1 = vr$45;
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) = SYM$1;
	}
	goto label$542;
	label$546:;
	{
		SYMBGETREALTYPE( SYM$1, &DTYPE$1, &SUBTYPE$1 );
		struct $8EXPRNODE* vr$49 = EXPRNEW( 2ll, DTYPE$1, SUBTYPE$1 );
		N$1 = vr$49;
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) = SYM$1;
	}
	label$542:;
	fb$result$1 = N$1;
	label$539:;
	return fb$result$1;
}

static int64 TYPECBOP( int64 OP$1, int64 A$1, int64 B$1 )
{
	int64 TMP$378$1;
	int64 TMP$379$1;
	int64 TMP$380$1;
	int64 TMP$383$1;
	int64 TMP$386$1;
	int64 TMP$387$1;
	int64 TMP$388$1;
	int64 TMP$389$1;
	int64 TMP$394$1;
	int64 TMP$395$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$547:;
	if( (*(int64*)(((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) + 8ll) & 8ll) == 0ll) goto label$550;
	{
		fb$result$1 = 11ll;
		goto label$548;
	}
	label$550:;
	label$549:;
	if( (A$1 & 480ll) == 0ll) goto label$551;
	TMP$378$1 = 24ll;
	goto label$1249;
	label$551:;
	TMP$378$1 = A$1 & 31ll;
	label$1249:;
	A$1 = TMP$378$1;
	if( (B$1 & 480ll) == 0ll) goto label$552;
	TMP$379$1 = 24ll;
	goto label$1250;
	label$552:;
	TMP$379$1 = B$1 & 31ll;
	label$1250:;
	B$1 = TMP$379$1;
	if( ((int64)-(A$1 == 16ll) | (int64)-(B$1 == 16ll)) == 0ll) goto label$554;
	{
		fb$result$1 = 16ll;
		goto label$548;
	}
	label$554:;
	label$553:;
	if( ((int64)-(A$1 == 15ll) | (int64)-(B$1 == 15ll)) == 0ll) goto label$556;
	{
		fb$result$1 = 15ll;
		goto label$548;
	}
	label$556:;
	label$555:;
	if( (A$1 & 480ll) == 0ll) goto label$557;
	TMP$380$1 = 24ll;
	goto label$1251;
	label$557:;
	TMP$380$1 = A$1 & 31ll;
	label$1251:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$380$1 * 56ll)) + 8ll) > 4ll) goto label$559;
	{
		int64 TMP$381$2;
		$11FB_DATATYPE TMP$382$2;
		if( (A$1 & 480ll) == 0ll) goto label$560;
		TMP$381$2 = 24ll;
		goto label$1252;
		label$560:;
		TMP$381$2 = A$1 & 31ll;
		label$1252:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$381$2 * 56ll)) + 16ll) == 0ll) goto label$561;
		TMP$382$2 = 11ll;
		goto label$1253;
		label$561:;
		TMP$382$2 = 12ll;
		label$1253:;
		A$1 = TMP$382$2;
	}
	label$559:;
	label$558:;
	if( (B$1 & 480ll) == 0ll) goto label$562;
	TMP$383$1 = 24ll;
	goto label$1254;
	label$562:;
	TMP$383$1 = B$1 & 31ll;
	label$1254:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$383$1 * 56ll)) + 8ll) > 4ll) goto label$564;
	{
		int64 TMP$384$2;
		$11FB_DATATYPE TMP$385$2;
		if( (B$1 & 480ll) == 0ll) goto label$565;
		TMP$384$2 = 24ll;
		goto label$1255;
		label$565:;
		TMP$384$2 = B$1 & 31ll;
		label$1255:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$384$2 * 56ll)) + 16ll) == 0ll) goto label$566;
		TMP$385$2 = 11ll;
		goto label$1256;
		label$566:;
		TMP$385$2 = 12ll;
		label$1256:;
		B$1 = TMP$385$2;
	}
	label$564:;
	label$563:;
	if( (A$1 & 480ll) == 0ll) goto label$567;
	TMP$386$1 = 24ll;
	goto label$1257;
	label$567:;
	TMP$386$1 = A$1 & 31ll;
	label$1257:;
	if( (B$1 & 480ll) == 0ll) goto label$568;
	TMP$387$1 = 24ll;
	goto label$1258;
	label$568:;
	TMP$387$1 = B$1 & 31ll;
	label$1258:;
	if( ~(*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$386$1 * 56ll)) + 16ll) & *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$387$1 * 56ll)) + 16ll)) == 0ll) goto label$570;
	{
		int64 vr$33 = TYPETOUNSIGNED( A$1 );
		A$1 = vr$33;
		int64 vr$34 = TYPETOUNSIGNED( B$1 );
		B$1 = vr$34;
	}
	label$570:;
	label$569:;
	if( (A$1 & 480ll) == 0ll) goto label$571;
	TMP$388$1 = 24ll;
	goto label$1259;
	label$571:;
	TMP$388$1 = A$1 & 31ll;
	label$1259:;
	if( (B$1 & 480ll) == 0ll) goto label$572;
	TMP$389$1 = 24ll;
	goto label$1260;
	label$572:;
	TMP$389$1 = B$1 & 31ll;
	label$1260:;
	if( ((int64)-(*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$388$1 * 56ll)) + 8ll) == 8ll) | (int64)-(*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$389$1 * 56ll)) + 8ll) == 8ll)) == 0ll) goto label$574;
	{
		int64 TMP$390$2;
		$11FB_DATATYPE TMP$391$2;
		int64 TMP$392$2;
		$11FB_DATATYPE TMP$393$2;
		if( (A$1 & 480ll) == 0ll) goto label$575;
		TMP$390$2 = 24ll;
		goto label$1261;
		label$575:;
		TMP$390$2 = A$1 & 31ll;
		label$1261:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$390$2 * 56ll)) + 16ll) == 0ll) goto label$576;
		TMP$391$2 = 13ll;
		goto label$1262;
		label$576:;
		TMP$391$2 = 14ll;
		label$1262:;
		A$1 = TMP$391$2;
		if( (B$1 & 480ll) == 0ll) goto label$577;
		TMP$392$2 = 24ll;
		goto label$1263;
		label$577:;
		TMP$392$2 = B$1 & 31ll;
		label$1263:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$392$2 * 56ll)) + 16ll) == 0ll) goto label$578;
		TMP$393$2 = 13ll;
		goto label$1264;
		label$578:;
		TMP$393$2 = 14ll;
		label$1264:;
		B$1 = TMP$393$2;
	}
	label$574:;
	label$573:;
	if( (A$1 & 480ll) == 0ll) goto label$579;
	TMP$394$1 = 24ll;
	goto label$1265;
	label$579:;
	TMP$394$1 = A$1 & 31ll;
	label$1265:;
	if( (B$1 & 480ll) == 0ll) goto label$580;
	TMP$395$1 = 24ll;
	goto label$1266;
	label$580:;
	TMP$395$1 = B$1 & 31ll;
	label$1266:;
	if( ~(*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$394$1 * 56ll)) + 16ll) & *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$395$1 * 56ll)) + 16ll)) == 0ll) goto label$582;
	{
		int64 vr$58 = TYPETOUNSIGNED( A$1 );
		A$1 = vr$58;
		int64 vr$59 = TYPETOUNSIGNED( B$1 );
		B$1 = vr$59;
	}
	label$582:;
	label$581:;
	fb$result$1 = A$1;
	label$548:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWUOP( int64 OP$1, struct $8EXPRNODE* L$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$583:;
	struct $8EXPRNODE* N$1;
	int64 DTYPE$1;
	int64 SOLVED_OUT$1;
	SOLVED_OUT$1 = 0ll;
	{
		uint64 TMP$396$2;
		TMP$396$2 = (uint64)OP$1;
		goto label$586;
		label$587:;
		{
			if( *(int64*)L$1 != 4ll) goto label$589;
			{
				SOLVED_OUT$1 = (int64)-(*(int64*)((uint8*)L$1 + 40ll) == 77ll);
			}
			label$589:;
			label$588:;
			DTYPE$1 = *(int64*)((uint8*)L$1 + 8ll);
			DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll);
		}
		goto label$585;
		label$590:;
		{
			if( *(int64*)L$1 != 4ll) goto label$592;
			{
				SOLVED_OUT$1 = (int64)-(*(int64*)((uint8*)L$1 + 40ll) == 22ll);
			}
			label$592:;
			label$591:;
			DTYPE$1 = *(int64*)((uint8*)L$1 + 8ll);
			DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + -32ll)) | (((DTYPE$1 & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (DTYPE$1 & 32505856ll);
		}
		goto label$585;
		label$593:;
		{
			if( *(int64*)L$1 != 4ll) goto label$595;
			{
				SOLVED_OUT$1 = (int64)-(*(int64*)((uint8*)L$1 + 40ll) == OP$1);
			}
			label$595:;
			label$594:;
			int64 vr$33 = TYPECBOP( OP$1, *(int64*)((uint8*)L$1 + 8ll), *(int64*)((uint8*)L$1 + 8ll) );
			DTYPE$1 = vr$33;
		}
		goto label$585;
		label$596:;
		{
			DTYPE$1 = *(int64*)((uint8*)L$1 + 8ll);
		}
		goto label$585;
		label$597:;
		{
		}
		goto label$585;
		label$586:;
		static const void* tmp$704[56ll] = {
			&&label$587,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$593,
			&&label$593,
			&&label$597,
			&&label$593,
			&&label$597,
			&&label$596,
			&&label$597,
			&&label$596,
			&&label$596,
			&&label$596,
			&&label$596,
			&&label$596,
			&&label$596,
			&&label$597,
			&&label$596,
			&&label$597,
			&&label$597,
			&&label$596,
			&&label$596,
			&&label$596,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$597,
			&&label$590,
		};
		if( (TMP$396$2 - 22ull) > 55ull ) goto label$597;
		goto *tmp$704[TMP$396$2 - 22ull];
		label$585:;
	}
	if( SOLVED_OUT$1 == 0ll) goto label$599;
	{
		N$1 = *(struct $8EXPRNODE**)((uint8*)L$1 + 24ll);
		EXPRFREENODE( L$1 );
		fb$result$1 = N$1;
		goto label$584;
	}
	label$599:;
	label$598:;
	struct $8EXPRNODE* vr$37 = EXPRNEW( 4ll, DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll) );
	N$1 = vr$37;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) = L$1;
	*(int64*)((uint8*)N$1 + 40ll) = OP$1;
	fb$result$1 = N$1;
	label$584:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWBOP( int64 OP$1, struct $8EXPRNODE* L$1, struct $8EXPRNODE* R$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$600:;
	struct $8EXPRNODE* N$1;
	int64 DTYPE$1;
	int64 vr$3 = TYPECBOP( OP$1, *(int64*)((uint8*)L$1 + 8ll), *(int64*)((uint8*)R$1 + 8ll) );
	DTYPE$1 = vr$3;
	{
		uint64 TMP$397$2;
		TMP$397$2 = (uint64)OP$1;
		goto label$603;
		label$604:;
		{
			if( ((int64)-((*(int64*)((uint8*)L$1 + 8ll) & 480ll) != 0ll) & (int64)-((*(int64*)((uint8*)R$1 + 8ll) & 480ll) != 0ll)) == 0ll) goto label$606;
			{
				if( ((int64)-(((*(int64*)((uint8*)L$1 + 8ll) & 32505856ll) >> (20ll & 63ll)) == 19ll) | (int64)-(((*(int64*)((uint8*)R$1 + 8ll) & 32505856ll) >> (20ll & 63ll)) == 19ll)) == 0ll) goto label$608;
				{
					struct $8EXPRNODE* vr$20 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, L$1 );
					L$1 = vr$20;
					struct $8EXPRNODE* vr$21 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, R$1 );
					R$1 = vr$21;
				}
				label$608:;
				label$607:;
			}
			label$606:;
			label$605:;
		}
		goto label$602;
		label$603:;
		static const void* tmp$705[6ll] = {
			&&label$604,
			&&label$604,
			&&label$604,
			&&label$604,
			&&label$604,
			&&label$604,
		};
		if( (TMP$397$2 - 45ull) > 5ull ) goto label$602;
		goto *tmp$705[TMP$397$2 - 45ull];
		label$602:;
	}
	struct $8EXPRNODE* vr$22 = EXPRNEW( 5ll, DTYPE$1, (struct $8FBSYMBOL*)0ull );
	N$1 = vr$22;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) = L$1;
	*(struct $8EXPRNODE**)((uint8*)N$1 + 32ll) = R$1;
	*(int64*)((uint8*)N$1 + 40ll) = OP$1;
	fb$result$1 = N$1;
	label$601:;
	return fb$result$1;
}

static void EXPRCACHE( int64 VREGID$1, struct $8EXPRNODE* EXPR$1 )
{
	label$609:;
	struct $13EXPRCACHENODE* ENTRY$1;
	void* vr$1 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll) );
	ENTRY$1 = (struct $13EXPRCACHENODE*)vr$1;
	*(int64*)ENTRY$1 = VREGID$1;
	*(struct $8EXPRNODE**)((uint8*)ENTRY$1 + 8ll) = EXPR$1;
	label$610:;
}

static struct $8EXPRNODE* EXPRLOOKUP( int64 VREGID$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$611:;
	struct $13EXPRCACHENODE* ENTRY$1;
	void* vr$2 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll) );
	ENTRY$1 = (struct $13EXPRCACHENODE*)vr$2;
	label$613:;
	if( ENTRY$1 == (struct $13EXPRCACHENODE*)0ull) goto label$614;
	{
		if( *(int64*)ENTRY$1 != VREGID$1) goto label$616;
		{
			goto label$614;
		}
		label$616:;
		label$615:;
		void* vr$4 = LISTGETNEXT( (void*)ENTRY$1 );
		ENTRY$1 = (struct $13EXPRCACHENODE*)vr$4;
	}
	goto label$613;
	label$614:;
	if( ENTRY$1 == (struct $13EXPRCACHENODE*)0ull) goto label$618;
	{
		fb$result$1 = *(struct $8EXPRNODE**)((uint8*)ENTRY$1 + 8ll);
		LISTDELNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll), (void*)ENTRY$1 );
	}
	goto label$617;
	label$618:;
	{
		fb$result$1 = (struct $8EXPRNODE*)0ull;
	}
	label$617:;
	label$612:;
	return fb$result$1;
}

static FBSTRING* HEMITINT( int64 DTYPE$1, int64 VALUE$1 )
{
	int64 TMP$398$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$619:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	if( (DTYPE$1 & 480ll) == 0ll) goto label$621;
	TMP$398$1 = 24ll;
	goto label$1267;
	label$621:;
	TMP$398$1 = DTYPE$1 & 31ll;
	label$1267:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$398$1 * 56ll)) + 16ll) == 0ll) goto label$623;
	{
		int64 TMP$399$2;
		FBSTRING* vr$5 = fb_LongintToStr( VALUE$1 );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$5, -1ll, 0 );
		if( (DTYPE$1 & 480ll) == 0ll) goto label$624;
		TMP$399$2 = 24ll;
		goto label$1268;
		label$624:;
		TMP$399$2 = DTYPE$1 & 31ll;
		label$1268:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$399$2 * 56ll)) + 8ll) != 8ll) goto label$626;
		{
			if( VALUE$1 != (int64)-9223372036854775808ull) goto label$628;
			{
				FBSTRING TMP$402$4;
				FBSTRING TMP$403$4;
				__builtin_memset( &TMP$402$4, 0, 24ll );
				FBSTRING* vr$13 = fb_StrConcat( &TMP$402$4, (void*)"(int64)", 8ll, (void*)&S$1, -1ll );
				__builtin_memset( &TMP$403$4, 0, 24ll );
				FBSTRING* vr$16 = fb_StrConcat( &TMP$403$4, (void*)vr$13, -1ll, (void*)"u", 2ll );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$16, -1ll, 0 );
			}
			label$628:;
			label$627:;
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"ll", 3ll, 0 );
		}
		goto label$625;
		label$626:;
		{
			if( VALUE$1 != -2147483648ll) goto label$630;
			{
				FBSTRING TMP$406$4;
				FBSTRING TMP$407$4;
				__builtin_memset( &TMP$406$4, 0, 24ll );
				FBSTRING* vr$22 = fb_StrConcat( &TMP$406$4, (void*)"(int32)", 8ll, (void*)&S$1, -1ll );
				__builtin_memset( &TMP$407$4, 0, 24ll );
				FBSTRING* vr$25 = fb_StrConcat( &TMP$407$4, (void*)vr$22, -1ll, (void*)"u", 2ll );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$25, -1ll, 0 );
			}
			label$630:;
			label$629:;
		}
		label$625:;
	}
	goto label$622;
	label$623:;
	{
		int64 TMP$408$2;
		if( (DTYPE$1 & 480ll) == 0ll) goto label$631;
		TMP$408$2 = 24ll;
		goto label$1269;
		label$631:;
		TMP$408$2 = DTYPE$1 & 31ll;
		label$1269:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$408$2 * 56ll)) + 8ll) != 8ll) goto label$633;
		{
			FBSTRING* vr$30 = fb_ULongintToStr( (uint64)VALUE$1 );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$30, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"ull", 4ll, 0 );
		}
		goto label$632;
		label$633:;
		{
			FBSTRING* vr$34 = fb_UIntToStr( (uint32)VALUE$1 );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$34, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"u", 2ll, 0 );
		}
		label$632:;
	}
	label$622:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$620:;
	FBSTRING* vr$41 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$41;
}

static FBSTRING* HEMITFLOAT( int64 DTYPE$1, double VALUE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$634:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	uint32 EXPVAL$1;
	EXPVAL$1 = *(uint32*)((uint8*)&VALUE$1 + 4ll);
	{
		if( (int64)EXPVAL$1 == 2146435072ll) goto label$638;
		label$639:;
		if( (int64)EXPVAL$1 != 4293918720ll) goto label$637;
		label$638:;
		{
			if( DTYPE$1 != 16ll) goto label$641;
			{
				if( ((int64)EXPVAL$1 & 2147483648ll) == 0ll) goto label$643;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"(-__builtin_inf())", 19ll, 0 );
				}
				goto label$642;
				label$643:;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"__builtin_inf()", 16ll, 0 );
				}
				label$642:;
			}
			goto label$640;
			label$641:;
			{
				if( ((int64)EXPVAL$1 & 2147483648ll) == 0ll) goto label$645;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"(-__builtin_inff())", 20ll, 0 );
				}
				goto label$644;
				label$645:;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"__builtin_inff()", 17ll, 0 );
				}
				label$644:;
			}
			label$640:;
		}
		goto label$636;
		label$637:;
		if( (int64)EXPVAL$1 == 2146959360ll) goto label$647;
		label$648:;
		if( (int64)EXPVAL$1 != 4294443008ll) goto label$646;
		label$647:;
		{
			if( DTYPE$1 != 16ll) goto label$650;
			{
				if( ((int64)EXPVAL$1 & 2147483648ll) == 0ll) goto label$652;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"(-__builtin_nan( \x22\x22 ))", 23ll, 0 );
				}
				goto label$651;
				label$652:;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"__builtin_nan( \x22\x22 )", 20ll, 0 );
				}
				label$651:;
			}
			goto label$649;
			label$650:;
			{
				if( ((int64)EXPVAL$1 & 2147483648ll) == 0ll) goto label$654;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"(-__builtin_nanf( \x22\x22 ))", 24ll, 0 );
				}
				goto label$653;
				label$654:;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"__builtin_nanf( \x22\x22 )", 21ll, 0 );
				}
				label$653:;
			}
			label$649:;
		}
		goto label$636;
		label$646:;
		{
			FBSTRING* vr$23 = HFLOATTOHEX_C99( VALUE$1 );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$23, -1ll, 0 );
			if( DTYPE$1 != 15ll) goto label$657;
			{
				fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"f", 2ll, 0 );
			}
			label$657:;
			label$656:;
		}
		label$655:;
		label$636:;
	}
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$635:;
	FBSTRING* vr$30 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$30;
}

static void HBUILDSTRLIT( FBSTRING* LN$1, char* Z$1, int64 LENGTH$1, int64 PADDEDLENGTH$1 )
{
	label$658:;
	int64 CH$1;
	fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$419$2;
		TMP$419$2 = LENGTH$1 + -2ll;
		goto label$660;
		label$663:;
		{
			CH$1 = (int64)*(uint8*)((uint8*)Z$1 + I$2);
			int64 vr$3 = HCHARNEEDSESCAPING( CH$1, 34ll );
			if( vr$3 == 0ll) goto label$665;
			{
				FBSTRING TMP$421$4;
				FBSTRING* vr$4 = fb_HEXEx_l( (uint64)CH$1, 2 );
				__builtin_memset( &TMP$421$4, 0, 24ll );
				FBSTRING* vr$7 = fb_StrConcat( &TMP$421$4, (void*)"\x5Cx", 3ll, (void*)vr$4, -1ll );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$7, -1ll, 0 );
				int64 vr$10 = HISVALIDHEXDIGIT( (int64)*(uint8*)((uint8*)((uint8*)Z$1 + I$2) + 1ll) );
				if( vr$10 == 0ll) goto label$667;
				{
					fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x22 \x22", 4ll, 0 );
				}
				label$667:;
				label$666:;
			}
			goto label$664;
			label$665:;
			if( (uint64)CH$1 != 63ull) goto label$668;
			{
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"?", 2ll, 0 );
				if( (uint64)(int64)*(uint8*)((uint8*)((uint8*)Z$1 + I$2) + 1ll) != 63ull) goto label$670;
				{
					{
						uint8 TMP$424$6;
						TMP$424$6 = *(uint8*)((uint8*)((uint8*)Z$1 + I$2) + 2ll);
						if( (uint64)(int64)TMP$424$6 == 61ull) goto label$673;
						label$674:;
						if( (uint64)(int64)TMP$424$6 == 47ull) goto label$673;
						label$675:;
						if( (uint64)(int64)TMP$424$6 == 39ull) goto label$673;
						label$676:;
						if( (uint64)(int64)TMP$424$6 == 40ull) goto label$673;
						label$677:;
						if( (uint64)(int64)TMP$424$6 == 41ull) goto label$673;
						label$678:;
						if( (uint64)(int64)TMP$424$6 == 33ull) goto label$673;
						label$679:;
						if( (uint64)(int64)TMP$424$6 == 60ull) goto label$673;
						label$680:;
						if( (uint64)(int64)TMP$424$6 == 62ull) goto label$673;
						label$681:;
						if( (uint64)(int64)TMP$424$6 != 45ull) goto label$672;
						label$673:;
						{
							fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x22 \x22", 4ll, 0 );
						}
						label$672:;
						label$671:;
					}
				}
				label$670:;
				label$669:;
			}
			goto label$664;
			label$668:;
			{
				FBSTRING* vr$23 = fb_CHR( 1, CH$1 );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$23, -1ll, 0 );
			}
			label$664:;
		}
		label$661:;
		I$2 = I$2 + 1ll;
		label$660:;
		if( I$2 <= TMP$419$2) goto label$663;
		label$662:;
	}
	if( PADDEDLENGTH$1 <= LENGTH$1) goto label$683;
	{
		FBSTRING* vr$26 = fb_SPACE( PADDEDLENGTH$1 - LENGTH$1 );
		fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$26, -1ll, 0 );
	}
	label$683:;
	label$682:;
	fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	label$659:;
}

static void HBUILDWSTRLIT( FBSTRING* LN$1, uint32* W$1, int64 LENGTH$1 )
{
	FBSTRING TMP$433$1;
	label$684:;
	int64 CH$1;
	int64 WCHARSIZE$1;
	char* STRSTART$1;
	WCHARSIZE$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 400ll);
	if( WCHARSIZE$1 != 1ll) goto label$687;
	{
		STRSTART$1 = (char*)"\x22";
	}
	goto label$686;
	label$687:;
	{
		STRSTART$1 = (char*)"L\x22";
	}
	label$686:;
	__builtin_memset( &TMP$433$1, 0, 24ll );
	FBSTRING* vr$2 = fb_StrConcat( &TMP$433$1, (void*)LN$1, -1ll, (void*)STRSTART$1, 0ll );
	fb_StrAssign( (void*)LN$1, -1ll, (void*)vr$2, -1ll, 0 );
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$434$2;
		TMP$434$2 = LENGTH$1 + -2ll;
		goto label$688;
		label$691:;
		{
			CH$1 = (int64)*(uint32*)((uint8*)W$1 + (I$2 << (2ll & 63ll)));
			int64 vr$7 = HCHARNEEDSESCAPING( CH$1, 34ll );
			if( vr$7 == 0ll) goto label$693;
			{
				FBSTRING TMP$435$4;
				FBSTRING* vr$10 = fb_HEXEx_l( (uint64)CH$1, (int32)(WCHARSIZE$1 << (1ll & 63ll)) );
				__builtin_memset( &TMP$435$4, 0, 24ll );
				FBSTRING* vr$13 = fb_StrConcat( &TMP$435$4, (void*)"\x5Cx", 3ll, (void*)vr$10, -1ll );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$13, -1ll, 0 );
				int64 vr$17 = HISVALIDHEXDIGIT( (int64)*(uint32*)((uint8*)((uint8*)W$1 + (I$2 << (2ll & 63ll))) + 4ll) );
				if( vr$17 == 0ll) goto label$695;
				{
					FBSTRING TMP$437$5;
					FBSTRING TMP$438$5;
					__builtin_memset( &TMP$437$5, 0, 24ll );
					FBSTRING* vr$20 = fb_StrConcat( &TMP$437$5, (void*)"\x22 ", 3ll, (void*)STRSTART$1, 0ll );
					__builtin_memset( &TMP$438$5, 0, 24ll );
					FBSTRING* vr$23 = fb_StrConcat( &TMP$438$5, (void*)LN$1, -1ll, (void*)vr$20, -1ll );
					fb_StrAssign( (void*)LN$1, -1ll, (void*)vr$23, -1ll, 0 );
				}
				label$695:;
				label$694:;
			}
			goto label$692;
			label$693:;
			if( (uint64)CH$1 != 63ull) goto label$696;
			{
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"?", 2ll, 0 );
				if( (uint64)(int64)*(uint32*)((uint8*)((uint8*)W$1 + (I$2 << (2ll & 63ll))) + 4ll) != 63ull) goto label$698;
				{
					{
						uint32 TMP$439$6;
						TMP$439$6 = *(uint32*)((uint8*)((uint8*)W$1 + (I$2 << (2ll & 63ll))) + 8ll);
						if( (uint64)(int64)TMP$439$6 == 61ull) goto label$701;
						label$702:;
						if( (uint64)(int64)TMP$439$6 == 47ull) goto label$701;
						label$703:;
						if( (uint64)(int64)TMP$439$6 == 39ull) goto label$701;
						label$704:;
						if( (uint64)(int64)TMP$439$6 == 40ull) goto label$701;
						label$705:;
						if( (uint64)(int64)TMP$439$6 == 41ull) goto label$701;
						label$706:;
						if( (uint64)(int64)TMP$439$6 == 33ull) goto label$701;
						label$707:;
						if( (uint64)(int64)TMP$439$6 == 60ull) goto label$701;
						label$708:;
						if( (uint64)(int64)TMP$439$6 == 62ull) goto label$701;
						label$709:;
						if( (uint64)(int64)TMP$439$6 != 45ull) goto label$700;
						label$701:;
						{
							FBSTRING TMP$440$7;
							FBSTRING TMP$441$7;
							__builtin_memset( &TMP$440$7, 0, 24ll );
							FBSTRING* vr$40 = fb_StrConcat( &TMP$440$7, (void*)"\x22 ", 3ll, (void*)STRSTART$1, 0ll );
							__builtin_memset( &TMP$441$7, 0, 24ll );
							FBSTRING* vr$43 = fb_StrConcat( &TMP$441$7, (void*)LN$1, -1ll, (void*)vr$40, -1ll );
							fb_StrAssign( (void*)LN$1, -1ll, (void*)vr$43, -1ll, 0 );
						}
						label$700:;
						label$699:;
					}
				}
				label$698:;
				label$697:;
			}
			goto label$692;
			label$696:;
			{
				FBSTRING* vr$44 = fb_CHR( 1, CH$1 );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$44, -1ll, 0 );
			}
			label$692:;
		}
		label$689:;
		I$2 = I$2 + 1ll;
		label$688:;
		if( I$2 <= TMP$434$2) goto label$691;
		label$690:;
	}
	fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	label$685:;
}

static char* HBOPTOSTR( int64 OP$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$710:;
	{
		uint64 TMP$442$2;
		TMP$442$2 = (uint64)OP$1;
		goto label$713;
		label$714:;
		{
			fb$result$1 = (char*)" + ";
		}
		goto label$712;
		label$715:;
		{
			fb$result$1 = (char*)" - ";
		}
		goto label$712;
		label$716:;
		{
			fb$result$1 = (char*)" * ";
		}
		goto label$712;
		label$717:;
		{
			fb$result$1 = (char*)" / ";
		}
		goto label$712;
		label$718:;
		{
			fb$result$1 = (char*)" / ";
		}
		goto label$712;
		label$719:;
		{
			fb$result$1 = (char*)" % ";
		}
		goto label$712;
		label$720:;
		{
			fb$result$1 = (char*)" << ";
		}
		goto label$712;
		label$721:;
		{
			fb$result$1 = (char*)" >> ";
		}
		goto label$712;
		label$722:;
		{
			fb$result$1 = (char*)" & ";
		}
		goto label$712;
		label$723:;
		{
			fb$result$1 = (char*)" | ";
		}
		goto label$712;
		label$724:;
		{
			fb$result$1 = (char*)" ^ ";
		}
		goto label$712;
		label$725:;
		{
			fb$result$1 = (char*)" == ";
		}
		goto label$712;
		label$726:;
		{
			fb$result$1 = (char*)" > ";
		}
		goto label$712;
		label$727:;
		{
			fb$result$1 = (char*)" < ";
		}
		goto label$712;
		label$728:;
		{
			fb$result$1 = (char*)" != ";
		}
		goto label$712;
		label$729:;
		{
			fb$result$1 = (char*)" >= ";
		}
		goto label$712;
		label$730:;
		{
			fb$result$1 = (char*)" <= ";
		}
		goto label$712;
		label$713:;
		static const void* tmp$706[23ll] = {
			&&label$714,
			&&label$715,
			&&label$716,
			&&label$717,
			&&label$718,
			&&label$719,
			&&label$722,
			&&label$723,
			&&label$712,
			&&label$712,
			&&label$724,
			&&label$712,
			&&label$712,
			&&label$720,
			&&label$721,
			&&label$712,
			&&label$712,
			&&label$725,
			&&label$726,
			&&label$727,
			&&label$728,
			&&label$729,
			&&label$730,
		};
		if( (TMP$442$2 - 28ull) > 22ull ) goto label$712;
		goto *tmp$706[TMP$442$2 - 28ull];
		label$712:;
	}
	label$711:;
	return fb$result$1;
}

static char* HUOPTOSTR( int64 OP$1, int64 DTYPE$1, int64* IS_BUILTIN$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$731:;
	*IS_BUILTIN$1 = 0ll;
	{
		if( OP$1 != 22ll) goto label$734;
		label$735:;
		{
			fb$result$1 = (char*)"&";
		}
		goto label$733;
		label$734:;
		if( OP$1 != 77ll) goto label$736;
		label$737:;
		{
			fb$result$1 = (char*)"*";
		}
		goto label$733;
		label$736:;
		if( OP$1 != 55ll) goto label$738;
		label$739:;
		{
			fb$result$1 = (char*)"-";
		}
		goto label$733;
		label$738:;
		if( OP$1 != 52ll) goto label$740;
		label$741:;
		{
			fb$result$1 = (char*)"~";
		}
		goto label$733;
		label$740:;
		if( OP$1 != 53ll) goto label$742;
		label$743:;
		{
			fb$result$1 = (char*)"!";
		}
		goto label$733;
		label$742:;
		if( OP$1 != 57ll) goto label$744;
		label$745:;
		{
			*IS_BUILTIN$1 = -1ll;
			{
				int64 TMP$461$4;
				uint64 TMP$462$4;
				if( (DTYPE$1 & 480ll) == 0ll) goto label$746;
				TMP$461$4 = 24ll;
				goto label$1270;
				label$746:;
				TMP$461$4 = DTYPE$1 & 31ll;
				label$1270:;
				TMP$462$4 = *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$461$4 * 56ll)) + 40ll);
				goto label$748;
				label$749:;
				{
					fb$result$1 = (char*)"__builtin_fabsf";
				}
				goto label$747;
				label$750:;
				{
					fb$result$1 = (char*)"__builtin_fabs";
				}
				goto label$747;
				label$751:;
				{
					fb$result$1 = (char*)"__builtin_llabs";
				}
				goto label$747;
				label$752:;
				{
					fb$result$1 = (char*)"__builtin_abs";
				}
				goto label$747;
				label$748:;
				static const void* tmp$707[4ll] = {
					&&label$751,
					&&label$751,
					&&label$749,
					&&label$750,
				};
				if( (TMP$462$4 - 7ull) > 3ull ) goto label$752;
				goto *tmp$707[TMP$462$4 - 7ull];
				label$747:;
			}
		}
		goto label$733;
		label$744:;
		{
			*IS_BUILTIN$1 = -1ll;
			if( (DTYPE$1 & 511ll) != 15ll) goto label$755;
			{
				{
					uint64 TMP$467$5;
					TMP$467$5 = (uint64)OP$1;
					goto label$757;
					label$758:;
					{
						fb$result$1 = (char*)"__builtin_sinf";
					}
					goto label$756;
					label$759:;
					{
						fb$result$1 = (char*)"__builtin_asinf";
					}
					goto label$756;
					label$760:;
					{
						fb$result$1 = (char*)"__builtin_cosf";
					}
					goto label$756;
					label$761:;
					{
						fb$result$1 = (char*)"__builtin_acosf";
					}
					goto label$756;
					label$762:;
					{
						fb$result$1 = (char*)"__builtin_tanf";
					}
					goto label$756;
					label$763:;
					{
						fb$result$1 = (char*)"__builtin_atanf";
					}
					goto label$756;
					label$764:;
					{
						fb$result$1 = (char*)"__builtin_sqrtf";
					}
					goto label$756;
					label$765:;
					{
						fb$result$1 = (char*)"__builtin_logf";
					}
					goto label$756;
					label$766:;
					{
						fb$result$1 = (char*)"__builtin_expf";
					}
					goto label$756;
					label$767:;
					{
						fb$result$1 = (char*)"__builtin_floorf";
					}
					goto label$756;
					label$768:;
					{
					}
					goto label$756;
					label$757:;
					static const void* tmp$708[13ll] = {
						&&label$758,
						&&label$759,
						&&label$760,
						&&label$761,
						&&label$762,
						&&label$763,
						&&label$768,
						&&label$764,
						&&label$768,
						&&label$768,
						&&label$765,
						&&label$766,
						&&label$767,
					};
					if( (TMP$467$5 - 59ull) > 12ull ) goto label$768;
					goto *tmp$708[TMP$467$5 - 59ull];
					label$756:;
				}
			}
			goto label$754;
			label$755:;
			{
				{
					uint64 TMP$478$5;
					TMP$478$5 = (uint64)OP$1;
					goto label$770;
					label$771:;
					{
						fb$result$1 = (char*)"__builtin_sin";
					}
					goto label$769;
					label$772:;
					{
						fb$result$1 = (char*)"__builtin_asin";
					}
					goto label$769;
					label$773:;
					{
						fb$result$1 = (char*)"__builtin_cos";
					}
					goto label$769;
					label$774:;
					{
						fb$result$1 = (char*)"__builtin_acos";
					}
					goto label$769;
					label$775:;
					{
						fb$result$1 = (char*)"__builtin_tan";
					}
					goto label$769;
					label$776:;
					{
						fb$result$1 = (char*)"__builtin_atan";
					}
					goto label$769;
					label$777:;
					{
						fb$result$1 = (char*)"__builtin_sqrt";
					}
					goto label$769;
					label$778:;
					{
						fb$result$1 = (char*)"__builtin_log";
					}
					goto label$769;
					label$779:;
					{
						fb$result$1 = (char*)"__builtin_exp";
					}
					goto label$769;
					label$780:;
					{
						fb$result$1 = (char*)"__builtin_floor";
					}
					goto label$769;
					label$781:;
					{
					}
					goto label$769;
					label$770:;
					static const void* tmp$709[13ll] = {
						&&label$771,
						&&label$772,
						&&label$773,
						&&label$774,
						&&label$775,
						&&label$776,
						&&label$781,
						&&label$777,
						&&label$781,
						&&label$781,
						&&label$778,
						&&label$779,
						&&label$780,
					};
					if( (TMP$478$5 - 59ull) > 12ull ) goto label$781;
					goto *tmp$709[TMP$478$5 - 59ull];
					label$769:;
				}
			}
			label$754:;
		}
		label$753:;
		label$733:;
	}
	label$732:;
	return fb$result$1;
}

static void HIMM2TEXT( FBSTRING* S$1, struct $8EXPRNODE* N$1 )
{
	int64 TMP$489$1;
	label$782:;
	if( (*(int64*)((uint8*)N$1 + 8ll) & 480ll) == 0ll) goto label$784;
	TMP$489$1 = 24ll;
	goto label$1271;
	label$784:;
	TMP$489$1 = *(int64*)((uint8*)N$1 + 8ll) & 31ll;
	label$1271:;
	if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$489$1 * 56ll)) != 1ll) goto label$786;
	{
		FBSTRING TMP$490$2;
		FBSTRING* vr$7 = HEMITFLOAT( *(int64*)((uint8*)N$1 + 8ll), *(double*)((uint8*)N$1 + 40ll) );
		__builtin_memset( &TMP$490$2, 0, 24ll );
		FBSTRING* vr$10 = fb_StrConcat( &TMP$490$2, (void*)S$1, -1ll, (void*)vr$7, -1ll );
		fb_StrAssign( (void*)S$1, -1ll, (void*)vr$10, -1ll, 0 );
	}
	goto label$785;
	label$786:;
	{
		FBSTRING TMP$491$2;
		FBSTRING* vr$13 = HEMITINT( *(int64*)((uint8*)N$1 + 8ll), *(int64*)((uint8*)N$1 + 40ll) );
		__builtin_memset( &TMP$491$2, 0, 24ll );
		FBSTRING* vr$16 = fb_StrConcat( &TMP$491$2, (void*)S$1, -1ll, (void*)vr$13, -1ll );
		fb_StrAssign( (void*)S$1, -1ll, (void*)vr$16, -1ll, 0 );
	}
	label$785:;
	label$783:;
}

static void HSYM2TEXT( FBSTRING* S$1, struct $8FBSYMBOL* SYM$1 )
{
	label$787:;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1024ll) == 0ll) goto label$790;
	{
		if( (*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) != 7ll) goto label$792;
		{
			int64 TMP$492$3;
			int64 vr$4 = SYMBGETWSTRLENGTH( SYM$1 );
			TMP$492$3 = 0ll;
			uint32* vr$8 = HUNESCAPEW( *(uint32**)((uint8*)SYM$1 + 96ll), &TMP$492$3 );
			HBUILDWSTRLIT( S$1, vr$8, vr$4 + 1ll );
		}
		goto label$791;
		label$792:;
		{
			int64 TMP$493$3;
			int64 vr$9 = SYMBGETSTRLENGTH( SYM$1 );
			TMP$493$3 = 0ll;
			char* vr$13 = HUNESCAPE( *(char**)((uint8*)SYM$1 + 96ll), &TMP$493$3 );
			HBUILDSTRLIT( S$1, vr$13, vr$9 + 1ll, 0ll );
		}
		label$791:;
	}
	goto label$789;
	label$790:;
	{
		FBSTRING TMP$495$2;
		if( *(int64*)SYM$1 != 7ll) goto label$794;
		{
			fb_StrConcatByref( (void*)S$1, -1ll, (void*)"&&", 3ll, 0 );
		}
		goto label$793;
		label$794:;
		if( *(int64*)SYM$1 != 3ll) goto label$795;
		{
			fb_StrConcatByref( (void*)S$1, -1ll, (void*)"&", 2ll, 0 );
		}
		label$795:;
		label$793:;
		char* vr$16 = SYMBGETMANGLEDNAME( SYM$1 );
		__builtin_memset( &TMP$495$2, 0, 24ll );
		FBSTRING* vr$19 = fb_StrConcat( &TMP$495$2, (void*)S$1, -1ll, (void*)vr$16, 0ll );
		fb_StrAssign( (void*)S$1, -1ll, (void*)vr$19, -1ll, 0 );
	}
	label$789:;
	label$788:;
}

static void HEXPRFLUSH( struct $8EXPRNODE* N$1, int64 NEED_PARENS$1 )
{
	label$796:;
	struct $8EXPRNODE* L$1;
	struct $8FBSYMBOL* SYM$1;
	int64 IS_BUILTIN$1;
	{
		uint64 TMP$496$2;
		TMP$496$2 = *(uint64*)N$1;
		goto label$799;
		label$800:;
		{
			FBSTRING TMP$497$3;
			__builtin_memset( &TMP$497$3, 0, 24ll );
			FBSTRING* vr$5 = fb_StrConcat( &TMP$497$3, (void*)((uint8*)&CTX$ + 5424ll), -1ll, *(void**)((uint8*)N$1 + 40ll), 0ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$5, -1ll, 0 );
		}
		goto label$798;
		label$801:;
		{
			HIMM2TEXT( (FBSTRING*)((uint8*)&CTX$ + 5424ll), N$1 );
		}
		goto label$798;
		label$802:;
		{
			HSYM2TEXT( (FBSTRING*)((uint8*)&CTX$ + 5424ll), *(struct $8FBSYMBOL**)((uint8*)N$1 + 40ll) );
		}
		goto label$798;
		label$803:;
		{
			FBSTRING TMP$498$3;
			FBSTRING TMP$499$3;
			FBSTRING TMP$500$3;
			FBSTRING* vr$12 = HEMITTYPE( *(int64*)((uint8*)N$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)N$1 + 16ll) );
			__builtin_memset( &TMP$498$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$498$3, (void*)"(", 2ll, (void*)vr$12, -1ll );
			__builtin_memset( &TMP$499$3, 0, 24ll );
			FBSTRING* vr$18 = fb_StrConcat( &TMP$499$3, (void*)vr$15, -1ll, (void*)")", 2ll );
			__builtin_memset( &TMP$500$3, 0, 24ll );
			FBSTRING* vr$22 = fb_StrConcat( &TMP$500$3, (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$18, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$22, -1ll, 0 );
			HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
		}
		goto label$798;
		label$804:;
		{
			{
				int64 TMP$501$4;
				TMP$501$4 = *(int64*)((uint8*)N$1 + 40ll);
				if( TMP$501$4 != 113ll) goto label$806;
				label$807:;
				{
					FBSTRING TMP$503$5;
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_va_arg( ", 19ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)", ", 3ll, 0 );
					FBSTRING* vr$31 = HEMITTYPE( *(int64*)((uint8*)N$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)N$1 + 16ll) );
					__builtin_memset( &TMP$503$5, 0, 24ll );
					FBSTRING* vr$35 = fb_StrConcat( &TMP$503$5, (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$31, -1ll );
					fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$35, -1ll, 0 );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
				}
				goto label$805;
				label$806:;
				if( TMP$501$4 != 110ll) goto label$808;
				label$809:;
				{
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_va_start( ", 21ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)", ", 3ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
				}
				goto label$805;
				label$808:;
				if( TMP$501$4 != 111ll) goto label$810;
				label$811:;
				{
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_va_end( ", 19ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
				}
				goto label$805;
				label$810:;
				if( TMP$501$4 != 112ll) goto label$812;
				label$813:;
				{
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_va_copy( ", 20ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)", ", 3ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll), -1ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
				}
				goto label$805;
				label$812:;
				{
				}
				label$814:;
				label$805:;
			}
		}
		goto label$798;
		label$815:;
		{
			FBSTRING TMP$507$3;
			char* vr$54 = HUOPTOSTR( *(int64*)((uint8*)N$1 + 40ll), *(int64*)((uint8*)N$1 + 8ll), &IS_BUILTIN$1 );
			__builtin_memset( &TMP$507$3, 0, 24ll );
			FBSTRING* vr$58 = fb_StrConcat( &TMP$507$3, (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$54, 0ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$58, -1ll, 0 );
			NEED_PARENS$1 = (int64)-(*(int64*)*(struct $8EXPRNODE**)((uint8*)N$1 + 24ll) == 4ll) | IS_BUILTIN$1;
			if( NEED_PARENS$1 == 0ll) goto label$817;
			{
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"(", 2ll, 0 );
				if( IS_BUILTIN$1 == 0ll) goto label$819;
				{
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)" ", 2ll, 0 );
				}
				label$819:;
				label$818:;
			}
			label$817:;
			label$816:;
			HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
			if( NEED_PARENS$1 == 0ll) goto label$821;
			{
				if( IS_BUILTIN$1 == 0ll) goto label$823;
				{
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)" ", 2ll, 0 );
				}
				label$823:;
				label$822:;
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
			}
			label$821:;
			label$820:;
		}
		goto label$798;
		label$824:;
		{
			{
				int64 TMP$508$4;
				TMP$508$4 = *(int64*)((uint8*)N$1 + 40ll);
				if( TMP$508$4 != 65ll) goto label$826;
				label$827:;
				{
					if( *(int64*)((uint8*)N$1 + 8ll) != 15ll) goto label$829;
					{
						fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_atan2f", 17ll, 0 );
					}
					goto label$828;
					label$829:;
					{
						fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"__builtin_atan2", 16ll, 0 );
					}
					label$828:;
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"(", 2ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), 0ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)", ", 3ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll), 0ll );
					fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
				}
				goto label$825;
				label$826:;
				{
					FBSTRING TMP$511$5;
					if( NEED_PARENS$1 == 0ll) goto label$832;
					{
						fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"(", 2ll, 0 );
					}
					label$832:;
					label$831:;
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 24ll), -1ll );
					char* vr$81 = HBOPTOSTR( *(int64*)((uint8*)N$1 + 40ll) );
					__builtin_memset( &TMP$511$5, 0, 24ll );
					FBSTRING* vr$85 = fb_StrConcat( &TMP$511$5, (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$81, 0ll );
					fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)vr$85, -1ll, 0 );
					HEXPRFLUSH( *(struct $8EXPRNODE**)((uint8*)N$1 + 32ll), -1ll );
					if( NEED_PARENS$1 == 0ll) goto label$834;
					{
						fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)")", 2ll, 0 );
					}
					label$834:;
					label$833:;
				}
				label$830:;
				label$825:;
			}
		}
		goto label$798;
		label$799:;
		static const void* tmp$710[7ll] = {
			&&label$800,
			&&label$801,
			&&label$802,
			&&label$803,
			&&label$815,
			&&label$824,
			&&label$804,
		};
		if( TMP$496$2 > 6ull ) goto label$798;
		goto *tmp$710[TMP$496$2 - 0ull];
		label$798:;
	}
	label$797:;
}

static FBSTRING* EXPRFLUSH( struct $8EXPRNODE* N$1, int64 NEED_PARENS$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$835:;
	HEXPRFLUSH( N$1, NEED_PARENS$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)((uint8*)&CTX$ + 5424ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5424ll), -1ll, (void*)"", 1ll, 0 );
	EXPRFREETREE( N$1 );
	label$836:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static struct $8EXPRNODE* EXPRNEWOFFSET( struct $8FBSYMBOL* SYM$1, int64 OFS$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$837:;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* vr$1 = EXPRNEWSYM( SYM$1 );
	L$1 = vr$1;
	int64 vr$5 = SYMBISCARRAY( SYM$1 );
	if( ((((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 512ll) != 0ll) | vr$5) | (int64)-(*(int64*)SYM$1 == 3ll)) | (int64)-(*(int64*)SYM$1 == 7ll)) != 0ll) goto label$840;
	{
		struct $8EXPRNODE* vr$13 = EXPRNEWUOP( 22ll, L$1 );
		L$1 = vr$13;
	}
	label$840:;
	label$839:;
	if( OFS$1 == 0ll) goto label$842;
	{
		struct $8EXPRNODE* vr$14 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, L$1 );
		L$1 = vr$14;
		struct $8EXPRNODE* vr$15 = EXPRNEWIMMI( OFS$1, 8ll );
		struct $8EXPRNODE* vr$16 = EXPRNEWBOP( 28ll, L$1, vr$15 );
		L$1 = vr$16;
	}
	label$842:;
	label$841:;
	fb$result$1 = L$1;
	label$838:;
	return fb$result$1;
}

static struct $8EXPRNODE* EXPRNEWVREG( struct $6IRVREG* VREG$1, int64 IS_LVALUE$1 )
{
	struct $8EXPRNODE* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$843:;
	struct $8EXPRNODE* L$1;
	int64 DTYPE$1;
	int64 HAVE_OFFSET$1;
	{
		uint64 TMP$512$2;
		TMP$512$2 = *(uint64*)VREG$1;
		goto label$846;
		label$847:;
		{
			if( *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) != (struct $8FBSYMBOL*)0ull) goto label$849;
			{
				if( *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$851;
				{
					struct $8EXPRNODE* vr$5 = EXPRNEWVREG( *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll), 0ll );
					L$1 = vr$5;
					if( *(int64*)((uint8*)VREG$1 + 64ll) == 0ll) goto label$853;
					{
						struct $8EXPRNODE* vr$7 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, L$1 );
						L$1 = vr$7;
						struct $8EXPRNODE* vr$9 = EXPRNEWIMMI( *(int64*)((uint8*)VREG$1 + 64ll), 8ll );
						struct $8EXPRNODE* vr$10 = EXPRNEWBOP( 28ll, L$1, vr$9 );
						L$1 = vr$10;
					}
					label$853:;
					label$852:;
				}
				goto label$850;
				label$851:;
				{
					struct $8EXPRNODE* vr$12 = EXPRNEWIMMI( *(int64*)((uint8*)VREG$1 + 64ll), 8ll );
					L$1 = vr$12;
				}
				label$850:;
				struct $8EXPRNODE* vr$27 = EXPRNEWCAST( (((*(int64*)((uint8*)VREG$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)VREG$1 + 8ll) & 480ll) + 32ll)) | ((*(int64*)((uint8*)VREG$1 + 8ll) & 261632ll) << (1ll & 63ll))) | (*(int64*)((uint8*)VREG$1 + 8ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll), L$1 );
				L$1 = vr$27;
				struct $8EXPRNODE* vr$28 = EXPRNEWUOP( 77ll, L$1 );
				L$1 = vr$28;
				goto label$845;
			}
			label$849:;
			label$848:;
			HAVE_OFFSET$1 = (int64)-(*(int64*)((uint8*)VREG$1 + 64ll) != 0ll) | (int64)-(*(struct $6IRVREG**)((uint8*)VREG$1 + 80ll) != (struct $6IRVREG*)0ull);
			int64 IS_C_ARRAY$3;
			int64 vr$35 = SYMBISCARRAY( *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) );
			IS_C_ARRAY$3 = vr$35;
			int64 DO_DEREF$3;
			DO_DEREF$3 = HAVE_OFFSET$1 | IS_C_ARRAY$3;
			struct $8EXPRNODE* vr$38 = EXPRNEWSYM( *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) );
			L$1 = vr$38;
			int64 SYMDTYPE$3;
			SYMDTYPE$3 = *(int64*)((uint8*)L$1 + 8ll);
			struct $8FBSYMBOL* SYMSUBTYPE$3;
			SYMSUBTYPE$3 = *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll);
			if( ((int64)-(*(int64*)((uint8*)VREG$1 + 8ll) != SYMDTYPE$3) | (int64)-(*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll) != SYMSUBTYPE$3)) == 0ll) goto label$855;
			{
				int64 TMP$513$4;
				int64 TMP$514$4;
				if( (*(int64*)((uint8*)VREG$1 + 8ll) & 480ll) == 0ll) goto label$856;
				TMP$513$4 = 24ll;
				goto label$1272;
				label$856:;
				TMP$513$4 = *(int64*)((uint8*)VREG$1 + 8ll) & 31ll;
				label$1272:;
				if( (SYMDTYPE$3 & 480ll) == 0ll) goto label$857;
				TMP$514$4 = 24ll;
				goto label$1273;
				label$857:;
				TMP$514$4 = SYMDTYPE$3 & 31ll;
				label$1273:;
				DO_DEREF$3 = DO_DEREF$3 | (int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$513$4 * 56ll)) != *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$514$4 * 56ll)));
				{
					int64 TMP$515$5;
					int64 TMP$516$5;
					if( (*(int64*)((uint8*)VREG$1 + 8ll) & 480ll) == 0ll) goto label$858;
					TMP$515$5 = 24ll;
					goto label$1274;
					label$858:;
					TMP$515$5 = *(int64*)((uint8*)VREG$1 + 8ll) & 31ll;
					label$1274:;
					TMP$516$5 = TMP$515$5;
					if( TMP$516$5 != 17ll) goto label$860;
					label$861:;
					{
						DO_DEREF$3 = -1ll;
					}
					goto label$859;
					label$860:;
					if( TMP$516$5 != 20ll) goto label$862;
					label$863:;
					{
						$19FB_CVA_LIST_TYPEDEF vr$64 = SYMBGETVALISTTYPE( *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) + 56ll), *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) + 64ll) );
						DO_DEREF$3 = DO_DEREF$3 | (int64)-(vr$64 != 3ll);
					}
					goto label$859;
					label$862:;
					{
						{
							int64 TMP$517$7;
							int64 TMP$518$7;
							if( (SYMDTYPE$3 & 480ll) == 0ll) goto label$865;
							TMP$517$7 = 24ll;
							goto label$1275;
							label$865:;
							TMP$517$7 = SYMDTYPE$3 & 31ll;
							label$1275:;
							TMP$518$7 = TMP$517$7;
							if( TMP$518$7 != 17ll) goto label$867;
							label$868:;
							{
								DO_DEREF$3 = -1ll;
							}
							goto label$866;
							label$867:;
							if( TMP$518$7 != 20ll) goto label$869;
							label$870:;
							{
								$19FB_CVA_LIST_TYPEDEF vr$73 = SYMBGETVALISTTYPE( *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) + 56ll), *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) + 64ll) );
								DO_DEREF$3 = DO_DEREF$3 | (int64)-(vr$73 != 3ll);
							}
							label$869:;
							label$866:;
						}
					}
					label$864:;
					label$859:;
				}
			}
			label$855:;
			label$854:;
			if( DO_DEREF$3 != 0ll) goto label$872;
			{
				goto label$845;
			}
			label$872:;
			label$871:;
			if( IS_C_ARRAY$3 != 0ll) goto label$874;
			{
				struct $8EXPRNODE* vr$76 = EXPRNEWUOP( 22ll, L$1 );
				L$1 = vr$76;
			}
			label$874:;
			label$873:;
			if( HAVE_OFFSET$1 == 0ll) goto label$876;
			{
				int64 TMP$519$4;
				if( IS_C_ARRAY$3 == 0ll) goto label$877;
				int64 vr$77 = FBGETOPTION( 3ll );
				TMP$519$4 = (int64)-(vr$77 != 12ll);
				goto label$1276;
				label$877:;
				TMP$519$4 = 0ll;
				label$1276:;
				if( TMP$519$4 == 0ll) goto label$879;
				{
					struct $8EXPRNODE* vr$79 = EXPRNEWCAST( 8ll, (struct $8FBSYMBOL*)0ull, L$1 );
					L$1 = vr$79;
				}
				goto label$878;
				label$879:;
				{
					struct $8EXPRNODE* vr$80 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, L$1 );
					L$1 = vr$80;
				}
				label$878:;
				if( *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$881;
				{
					struct $8EXPRNODE* vr$83 = EXPRNEWVREG( *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll), 0ll );
					struct $8EXPRNODE* vr$84 = EXPRNEWBOP( 28ll, L$1, vr$83 );
					L$1 = vr$84;
				}
				label$881:;
				label$880:;
				if( *(int64*)((uint8*)VREG$1 + 64ll) == 0ll) goto label$883;
				{
					struct $8EXPRNODE* vr$87 = EXPRNEWIMMI( *(int64*)((uint8*)VREG$1 + 64ll), 8ll );
					struct $8EXPRNODE* vr$88 = EXPRNEWBOP( 28ll, L$1, vr$87 );
					L$1 = vr$88;
				}
				label$883:;
				label$882:;
			}
			label$876:;
			label$875:;
			struct $8EXPRNODE* vr$103 = EXPRNEWCAST( (((*(int64*)((uint8*)VREG$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)VREG$1 + 8ll) & 480ll) + 32ll)) | ((*(int64*)((uint8*)VREG$1 + 8ll) & 261632ll) << (1ll & 63ll))) | (*(int64*)((uint8*)VREG$1 + 8ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll), L$1 );
			L$1 = vr$103;
			struct $8EXPRNODE* vr$104 = EXPRNEWUOP( 77ll, L$1 );
			L$1 = vr$104;
		}
		goto label$845;
		label$884:;
		{
			struct $8EXPRNODE* vr$107 = EXPRNEWOFFSET( *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll), *(int64*)((uint8*)VREG$1 + 64ll) );
			L$1 = vr$107;
		}
		goto label$845;
		label$885:;
		{
			int64 TMP$520$3;
			DTYPE$1 = *(int64*)((uint8*)VREG$1 + 8ll);
			if( (DTYPE$1 & 480ll) == 0ll) goto label$886;
			TMP$520$3 = 24ll;
			goto label$1277;
			label$886:;
			TMP$520$3 = DTYPE$1 & 31ll;
			label$1277:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$520$3 * 56ll)) != 1ll) goto label$888;
			{
				struct $8EXPRNODE* vr$113 = EXPRNEWIMMF( *(double*)((uint8*)VREG$1 + 48ll), DTYPE$1 );
				L$1 = vr$113;
			}
			goto label$887;
			label$888:;
			if( DTYPE$1 != 1ll) goto label$889;
			{
				int64 TMP$521$4;
				if( *(int64*)((uint8*)VREG$1 + 48ll) == 0ll) goto label$890;
				TMP$521$4 = 1ll;
				goto label$1278;
				label$890:;
				TMP$521$4 = 0ll;
				label$1278:;
				struct $8EXPRNODE* vr$115 = EXPRNEWIMMI( TMP$521$4, 8ll );
				L$1 = vr$115;
			}
			goto label$887;
			label$889:;
			{
				struct $8EXPRNODE* vr$117 = EXPRNEWIMMI( *(int64*)((uint8*)VREG$1 + 48ll), DTYPE$1 );
				L$1 = vr$117;
			}
			label$887:;
		}
		goto label$845;
		label$891:;
		{
			struct $8EXPRNODE* vr$119 = EXPRLOOKUP( *(int64*)((uint8*)VREG$1 + 24ll) );
			L$1 = vr$119;
			if( L$1 != (struct $8EXPRNODE*)0ull) goto label$893;
			{
				FBSTRING TMP$523$4;
				FBSTRING TMP$524$4;
				__builtin_memset( &TMP$524$4, 0, 24ll );
				FBSTRING* vr$122 = fb_LongintToStr( *(int64*)((uint8*)VREG$1 + 24ll) );
				__builtin_memset( &TMP$523$4, 0, 24ll );
				FBSTRING* vr$125 = fb_StrConcat( &TMP$523$4, (void*)"vr$", 4ll, (void*)vr$122, -1ll );
				fb_StrAssign( (void*)&TMP$524$4, -1ll, (void*)vr$125, -1ll, 0 );
				struct $8EXPRNODE* vr$129 = EXPRNEWTEXT( *(int64*)((uint8*)VREG$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll), (char*)*(char**)&TMP$524$4 );
				L$1 = vr$129;
				fb_StrDelete( (FBSTRING*)&TMP$524$4 );
			}
			label$893:;
			label$892:;
		}
		goto label$845;
		label$846:;
		static const void* tmp$711[6ll] = {
			&&label$885,
			&&label$847,
			&&label$847,
			&&label$847,
			&&label$891,
			&&label$884,
		};
		if( TMP$512$2 > 5ull ) goto label$845;
		goto *tmp$711[TMP$512$2 - 0ull];
		label$845:;
	}
	if( IS_LVALUE$1 != 0ll) goto label$895;
	{
		struct $8EXPRNODE* vr$133 = EXPRNEWCAST( *(int64*)((uint8*)VREG$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll), L$1 );
		L$1 = vr$133;
	}
	label$895:;
	label$894:;
	fb$result$1 = L$1;
	label$844:;
	return fb$result$1;
}

static void _EMITLABEL( struct $8FBSYMBOL* LABEL$1 )
{
	label$896:;
	int64 vr$0 = SECTIONINSIDEPROC(  );
	if( vr$0 == 0ll) goto label$899;
	{
		FBSTRING TMP$526$2;
		FBSTRING TMP$527$2;
		__builtin_memset( &TMP$527$2, 0, 24ll );
		char* vr$2 = SYMBGETMANGLEDNAME( LABEL$1 );
		__builtin_memset( &TMP$526$2, 0, 24ll );
		FBSTRING* vr$5 = fb_StrConcat( &TMP$526$2, (void*)vr$2, 0ll, (void*)":;", 3ll );
		fb_StrAssign( (void*)&TMP$527$2, -1ll, (void*)vr$5, -1ll, 0 );
		HWRITELINE( &TMP$527$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$527$2 );
	}
	label$899:;
	label$898:;
	label$897:;
}

static void EXPRSTORE( struct $6IRVREG* VR$1, struct $8EXPRNODE* R$1, int64 HAS_SIDEFX$1 )
{
	label$900:;
	static FBSTRING LN$1;
	static FBSTRING TEMPVAR$1;
	struct $8EXPRNODE* L$1;
	if( *(int64*)VR$1 != 4ll) goto label$903;
	{
		if( HAS_SIDEFX$1 == 0ll) goto label$905;
		{
			FBSTRING TMP$528$3;
			FBSTRING* vr$2 = fb_LongintToStr( *(int64*)((uint8*)VR$1 + 24ll) );
			__builtin_memset( &TMP$528$3, 0, 24ll );
			FBSTRING* vr$5 = fb_StrConcat( &TMP$528$3, (void*)"vr$", 4ll, (void*)vr$2, -1ll );
			fb_StrAssign( (void*)&TEMPVAR$1, -1ll, (void*)vr$5, -1ll, 0 );
			FBSTRING* vr$8 = HEMITTYPE( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$8, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&TEMPVAR$1, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = ", 4ll, 0 );
			FBSTRING* vr$9 = EXPRFLUSH( R$1, 0ll );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$9, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)";", 2ll, 0 );
			HWRITELINE( &LN$1, 0ll );
			struct $8EXPRNODE* vr$12 = EXPRNEWTEXT( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), (char*)*(char**)&TEMPVAR$1 );
			R$1 = vr$12;
		}
		goto label$904;
		label$905:;
		{
			struct $8EXPRNODE* vr$15 = EXPRNEWCAST( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), R$1 );
			R$1 = vr$15;
		}
		label$904:;
		EXPRCACHE( *(int64*)((uint8*)VR$1 + 24ll), R$1 );
	}
	goto label$902;
	label$903:;
	{
		struct $8EXPRNODE* vr$17 = EXPRNEWVREG( VR$1, -1ll );
		L$1 = vr$17;
		struct $8EXPRNODE* vr$20 = EXPRNEWCAST( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), R$1 );
		R$1 = vr$20;
		if( ((int64)-((*(int64*)((uint8*)L$1 + 8ll) & 480ll) != 0ll) | (int64)-((*(int64*)((uint8*)R$1 + 8ll) & 480ll) != 0ll)) == 0ll) goto label$907;
		{
			struct $8EXPRNODE* vr$30 = EXPRNEWCAST( *(int64*)((uint8*)L$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll), R$1 );
			R$1 = vr$30;
		}
		label$907:;
		label$906:;
		FBSTRING* vr$31 = EXPRFLUSH( L$1, 0ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$31, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = ", 4ll, 0 );
		FBSTRING* vr$32 = EXPRFLUSH( R$1, 0ll );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$32, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)";", 2ll, 0 );
		HWRITELINE( &LN$1, 0ll );
	}
	label$902:;
	label$901:;
}

static void _EMITBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* LABEL$1, $10IR_EMITOPT OPTIONS$1 )
{
	label$908:;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* R$1;
	struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V1$1, 0ll );
	L$1 = vr$0;
	struct $8EXPRNODE* vr$1 = EXPRNEWVREG( V2$1, 0ll );
	R$1 = vr$1;
	if( LABEL$1 == (struct $8FBSYMBOL*)0ull) goto label$911;
	{
		FBSTRING TMP$532$2;
		static FBSTRING S$2;
		fb_StrAssign( (void*)&S$2, -1ll, (void*)"if( ", 5ll, 0 );
		if( (OPTIONS$1 & 1ll) == 0ll) goto label$913;
		{
			fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)"!(", 3ll, 0 );
		}
		label$913:;
		label$912:;
		struct $8EXPRNODE* vr$3 = EXPRNEWBOP( OP$1, L$1, R$1 );
		FBSTRING* vr$4 = EXPRFLUSH( vr$3, 0ll );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)vr$4, -1ll, 0 );
		if( (OPTIONS$1 & 1ll) == 0ll) goto label$915;
		{
			fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)")", 2ll, 0 );
		}
		label$915:;
		label$914:;
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)") goto ", 8ll, 0 );
		char* vr$6 = SYMBGETMANGLEDNAME( LABEL$1 );
		__builtin_memset( &TMP$532$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$532$2, (void*)&S$2, -1ll, (void*)vr$6, 0ll );
		fb_StrAssign( (void*)&S$2, -1ll, (void*)vr$9, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)";", 2ll, 0 );
		HWRITELINE( &S$2, 0ll );
		goto label$909;
	}
	label$911:;
	label$910:;
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$917;
	{
		VR$1 = V1$1;
	}
	label$917:;
	label$916:;
	{
		uint64 TMP$533$2;
		TMP$533$2 = (uint64)OP$1;
		goto label$919;
		label$920:;
		{
			struct $8EXPRNODE* vr$10 = EXPRNEWBOP( OP$1, L$1, R$1 );
			L$1 = vr$10;
			if( (OPTIONS$1 & 1ll) == 0ll) goto label$922;
			{
				struct $8EXPRNODE* vr$12 = EXPRNEWUOP( 53ll, L$1 );
				L$1 = vr$12;
			}
			label$922:;
			label$921:;
			if( *(int64*)((uint8*)VR$1 + 8ll) == 1ll) goto label$924;
			{
				struct $8EXPRNODE* vr$14 = EXPRNEWUOP( 55ll, L$1 );
				L$1 = vr$14;
			}
			label$924:;
			label$923:;
		}
		goto label$918;
		label$925:;
		{
			if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$927;
			{
				struct $8EXPRNODE* vr$17 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, L$1 );
				L$1 = vr$17;
			}
			label$927:;
			label$926:;
			if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$929;
			{
				struct $8EXPRNODE* vr$20 = EXPRNEWCAST( 35ll, (struct $8FBSYMBOL*)0ull, R$1 );
				R$1 = vr$20;
			}
			label$929:;
			label$928:;
			struct $8EXPRNODE* vr$21 = EXPRNEWBOP( OP$1, L$1, R$1 );
			L$1 = vr$21;
		}
		goto label$918;
		label$930:;
		{
			struct $8EXPRNODE* vr$22 = EXPRNEWCAST( 16ll, (struct $8FBSYMBOL*)0ull, L$1 );
			L$1 = vr$22;
			struct $8EXPRNODE* vr$23 = EXPRNEWCAST( 16ll, (struct $8FBSYMBOL*)0ull, R$1 );
			R$1 = vr$23;
			struct $8EXPRNODE* vr$24 = EXPRNEWBOP( OP$1, L$1, R$1 );
			L$1 = vr$24;
		}
		goto label$918;
		label$931:;
		{
			struct $8EXPRNODE* vr$25 = EXPRNEWBOP( OP$1, L$1, R$1 );
			L$1 = vr$25;
		}
		goto label$918;
		label$932:;
		{
			int64 TMP$534$3;
			if( (*(int64*)((uint8*)L$1 + 8ll) & 480ll) == 0ll) goto label$933;
			TMP$534$3 = 24ll;
			goto label$1279;
			label$933:;
			TMP$534$3 = *(int64*)((uint8*)L$1 + 8ll) & 31ll;
			label$1279:;
			struct $8EXPRNODE* vr$33 = EXPRNEWIMMI( (*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$534$3 * 56ll)) + 8ll) << (3ll & 63ll)) + -1ll, 8ll );
			struct $8EXPRNODE* vr$34 = EXPRNEWBOP( 34ll, R$1, vr$33 );
			R$1 = vr$34;
			struct $8EXPRNODE* vr$35 = EXPRNEWBOP( OP$1, L$1, R$1 );
			L$1 = vr$35;
		}
		goto label$918;
		label$934:;
		{
			struct $8EXPRNODE* vr$36 = EXPRNEWBOP( 38ll, L$1, R$1 );
			L$1 = vr$36;
			if( *(int64*)((uint8*)VR$1 + 8ll) != 1ll) goto label$936;
			{
				struct $8EXPRNODE* vr$38 = EXPRNEWIMMI( 1ll, 8ll );
				struct $8EXPRNODE* vr$39 = EXPRNEWBOP( 38ll, L$1, vr$38 );
				L$1 = vr$39;
			}
			goto label$935;
			label$936:;
			{
				struct $8EXPRNODE* vr$40 = EXPRNEWUOP( 52ll, L$1 );
				L$1 = vr$40;
			}
			label$935:;
		}
		goto label$918;
		label$937:;
		{
			if( *(int64*)((uint8*)VR$1 + 8ll) != 1ll) goto label$939;
			{
				struct $8EXPRNODE* vr$42 = EXPRNEWIMMI( 1ll, 8ll );
				struct $8EXPRNODE* vr$43 = EXPRNEWBOP( 38ll, L$1, vr$42 );
				L$1 = vr$43;
			}
			goto label$938;
			label$939:;
			{
				struct $8EXPRNODE* vr$44 = EXPRNEWUOP( 52ll, L$1 );
				L$1 = vr$44;
			}
			label$938:;
			struct $8EXPRNODE* vr$45 = EXPRNEWBOP( 35ll, L$1, R$1 );
			L$1 = vr$45;
		}
		goto label$918;
		label$919:;
		static const void* tmp$712[23ll] = {
			&&label$925,
			&&label$925,
			&&label$931,
			&&label$930,
			&&label$931,
			&&label$931,
			&&label$931,
			&&label$931,
			&&label$918,
			&&label$918,
			&&label$931,
			&&label$934,
			&&label$937,
			&&label$932,
			&&label$932,
			&&label$918,
			&&label$918,
			&&label$920,
			&&label$920,
			&&label$920,
			&&label$920,
			&&label$920,
			&&label$920,
		};
		if( (TMP$533$2 - 28ull) > 22ull ) goto label$918;
		goto *tmp$712[TMP$533$2 - 28ull];
		label$918:;
	}
	EXPRSTORE( VR$1, L$1, 0ll );
	label$909:;
}

static void _EMITUOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$940:;
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$943;
	{
		VR$1 = V1$1;
	}
	label$943:;
	label$942:;
	struct $8EXPRNODE* EXPR$1;
	struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V1$1, 0ll );
	EXPR$1 = vr$0;
	if( ((int64)-(OP$1 == 52ll) & (int64)-(*(int64*)((uint8*)VR$1 + 8ll) == 1ll)) == 0ll) goto label$945;
	{
		struct $8EXPRNODE* vr$5 = EXPRNEWIMMI( 0ll, 8ll );
		struct $8EXPRNODE* vr$6 = EXPRNEWBOP( 45ll, EXPR$1, vr$5 );
		EXPR$1 = vr$6;
	}
	goto label$944;
	label$945:;
	{
		struct $8EXPRNODE* vr$7 = EXPRNEWUOP( OP$1, EXPR$1 );
		EXPR$1 = vr$7;
	}
	label$944:;
	EXPRSTORE( VR$1, EXPR$1, 0ll );
	label$941:;
}

static void _EMITCONVERT( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	int64 TMP$537$1;
	int64 TMP$538$1;
	label$946:;
	struct $8EXPRNODE* R$1;
	struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V2$1, 0ll );
	R$1 = vr$0;
	if( ((int64)-(*(int64*)((uint8*)V1$1 + 8ll) != 1ll) & (int64)-(*(int64*)((uint8*)R$1 + 8ll) == 1ll)) == 0ll) goto label$949;
	{
		if( *(int64*)R$1 != 1ll) goto label$951;
		{
			*(int64*)((uint8*)R$1 + 40ll) = (int64)-(*(int64*)((uint8*)R$1 + 40ll) != 0ll);
			*(int64*)((uint8*)R$1 + 8ll) = 11ll;
		}
		goto label$950;
		label$951:;
		{
			struct $8EXPRNODE* vr$11 = EXPRNEWUOP( 55ll, R$1 );
			R$1 = vr$11;
		}
		label$950:;
	}
	goto label$948;
	label$949:;
	if( ((int64)-(*(int64*)((uint8*)V1$1 + 8ll) == 1ll) & (int64)-(*(int64*)((uint8*)R$1 + 8ll) != 1ll)) == 0ll) goto label$952;
	{
		if( *(int64*)R$1 != 1ll) goto label$954;
		{
			int64 TMP$535$3;
			int64 TMP$536$3;
			if( (*(int64*)((uint8*)R$1 + 8ll) & 480ll) == 0ll) goto label$955;
			TMP$535$3 = 24ll;
			goto label$1280;
			label$955:;
			TMP$535$3 = *(int64*)((uint8*)R$1 + 8ll) & 31ll;
			label$1280:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$535$3 * 56ll)) != 1ll) goto label$956;
			TMP$536$3 = (int64)-(*(double*)((uint8*)R$1 + 40ll) != 0x0p+0);
			goto label$1281;
			label$956:;
			TMP$536$3 = (int64)-(*(int64*)((uint8*)R$1 + 40ll) != 0ll);
			label$1281:;
			*(int64*)((uint8*)R$1 + 40ll) = -TMP$536$3;
			*(int64*)((uint8*)R$1 + 8ll) = 11ll;
		}
		goto label$953;
		label$954:;
		{
			struct $8EXPRNODE* vr$30 = EXPRNEWIMMI( 0ll, 8ll );
			struct $8EXPRNODE* vr$31 = EXPRNEWBOP( 48ll, R$1, vr$30 );
			R$1 = vr$31;
		}
		label$953:;
	}
	goto label$948;
	label$952:;
	if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$958;
	TMP$537$1 = 24ll;
	goto label$1282;
	label$958:;
	TMP$537$1 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
	label$1282:;
	if( (*(int64*)((uint8*)R$1 + 8ll) & 480ll) == 0ll) goto label$959;
	TMP$538$1 = 24ll;
	goto label$1283;
	label$959:;
	TMP$538$1 = *(int64*)((uint8*)R$1 + 8ll) & 31ll;
	label$1283:;
	if( ((int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$537$1 * 56ll)) == 0ll) & (int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$538$1 * 56ll)) == 1ll)) == 0ll) goto label$957;
	{
		FBSTRING S$2;
		__builtin_memset( &S$2, 0, 24ll );
		int64 TEMPDTYPE$2;
		__builtin_memset( &TEMPDTYPE$2, 0, 8ll );
		{
			int64 TMP$539$3;
			int64 TMP$540$3;
			if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$960;
			TMP$539$3 = 24ll;
			goto label$1284;
			label$960:;
			TMP$539$3 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
			label$1284:;
			TMP$540$3 = *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$539$3 * 56ll)) + 40ll);
			if( TMP$540$3 > 5ll) goto label$962;
			label$963:;
			{
				if( *(int64*)((uint8*)R$1 + 8ll) != 15ll) goto label$965;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_F2I", 7ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 1ull;
				}
				goto label$964;
				label$965:;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_D2I", 7ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 8ull;
				}
				label$964:;
				TEMPDTYPE$2 = 11ll;
			}
			goto label$961;
			label$962:;
			if( TMP$540$3 > 7ll) goto label$966;
			label$967:;
			{
				if( *(int64*)((uint8*)R$1 + 8ll) != 15ll) goto label$969;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_F2L", 7ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 2ull;
				}
				goto label$968;
				label$969:;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_D2L", 7ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 16ull;
				}
				label$968:;
				TEMPDTYPE$2 = 13ll;
			}
			goto label$961;
			label$966:;
			{
				if( *(int64*)((uint8*)R$1 + 8ll) != 15ll) goto label$972;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_F2UL", 8ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 4ull;
				}
				goto label$971;
				label$972:;
				{
					fb_StrAssign( (void*)&S$2, -1ll, (void*)"fb_D2UL", 8ll, 0 );
					*(uint64*)((uint8*)&CTX$ + 5208ll) = *(uint64*)((uint8*)&CTX$ + 5208ll) | 32ull;
				}
				label$971:;
				TEMPDTYPE$2 = 14ll;
			}
			label$970:;
			label$961:;
		}
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)"( ", 3ll, 0 );
		FBSTRING* vr$68 = EXPRFLUSH( R$1, 0ll );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)vr$68, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)" )", 3ll, 0 );
		struct $8EXPRNODE* vr$71 = EXPRNEWTEXT( TEMPDTYPE$2, (struct $8FBSYMBOL*)0ull, (char*)*(char**)&S$2 );
		R$1 = vr$71;
		fb_StrDelete( (FBSTRING*)&S$2 );
	}
	label$957:;
	label$948:;
	EXPRSTORE( V1$1, R$1, 0ll );
	label$947:;
}

static void _EMITSTORE( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$973:;
	struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V2$1, 0ll );
	EXPRSTORE( V1$1, vr$0, 0ll );
	label$974:;
}

static void _EMITSPILLREGS( void )
{
	label$975:;
	label$976:;
}

static void _EMITLOAD( struct $6IRVREG* V1$1 )
{
	label$977:;
	label$978:;
}

static void _EMITLOADRES( struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	FBSTRING TMP$548$1;
	FBSTRING TMP$549$1;
	FBSTRING TMP$550$1;
	label$979:;
	_EMITSTORE( VR$1, V1$1 );
	__builtin_memset( &TMP$550$1, 0, 24ll );
	struct $8EXPRNODE* vr$1 = EXPRNEWVREG( VR$1, 0ll );
	FBSTRING* vr$2 = EXPRFLUSH( vr$1, 0ll );
	__builtin_memset( &TMP$548$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$548$1, (void*)"return ", 8ll, (void*)vr$2, -1ll );
	__builtin_memset( &TMP$549$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$549$1, (void*)vr$5, -1ll, (void*)";", 2ll );
	fb_StrAssign( (void*)&TMP$550$1, -1ll, (void*)vr$8, -1ll, 0 );
	HWRITELINE( &TMP$550$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$550$1 );
	label$980:;
}

static void _EMITADDR( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$981:;
	struct $8EXPRNODE* L$1;
	L$1 = (struct $8EXPRNODE*)0ull;
	{
		if( OP$1 != 22ll) goto label$984;
		label$985:;
		{
			if( ((int64)-(*(int64*)V1$1 == 1ll) & (int64)-(*(struct $8FBSYMBOL**)((uint8*)V1$1 + 56ll) != (struct $8FBSYMBOL*)0ull)) == 0ll) goto label$987;
			{
				if( *(int64*)*(struct $8FBSYMBOL**)((uint8*)V1$1 + 56ll) != 7ll) goto label$989;
				{
					struct $8EXPRNODE* vr$8 = EXPRNEWSYM( *(struct $8FBSYMBOL**)((uint8*)V1$1 + 56ll) );
					L$1 = vr$8;
					struct $8EXPRNODE* vr$11 = EXPRNEWCAST( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), L$1 );
					L$1 = vr$11;
					goto label$983;
				}
				label$989:;
				label$988:;
			}
			label$987:;
			label$986:;
			struct $8EXPRNODE* vr$12 = EXPRNEWVREG( V1$1, -1ll );
			struct $8EXPRNODE* vr$13 = EXPRNEWUOP( 22ll, vr$12 );
			L$1 = vr$13;
		}
		goto label$983;
		label$984:;
		if( OP$1 != 77ll) goto label$990;
		label$991:;
		{
			struct $8EXPRNODE* vr$14 = EXPRNEWVREG( V1$1, 0ll );
			L$1 = vr$14;
		}
		label$990:;
		label$983:;
	}
	EXPRSTORE( VR$1, L$1, 0ll );
	label$982:;
}

static void HDOCALL( FBSTRING* S$1, int64 BYTESTOPOP$1, struct $6IRVREG* VR$1, int64 LEVEL$1 )
{
	int64 TMP$551$1;
	label$992:;
	struct $9IRCALLARG* ARG$1;
	int64 DTYPE$1;
	struct $8FBSYMBOL* SUBTYPE$1;
	fb_StrConcatByref( (void*)S$1, -1ll, (void*)"( ", 3ll, 0 );
	void* vr$1 = LISTGETTAIL( (struct $5TLIST*)((uint8*)&IRHL$ + 120ll) );
	ARG$1 = (struct $9IRCALLARG*)vr$1;
	label$994:;
	if( ARG$1 == (struct $9IRCALLARG*)0ull) goto label$996;
	TMP$551$1 = (int64)-((struct $9IRCALLARG*)(int64)-(*(int64*)((uint8*)ARG$1 + 16ll) == LEVEL$1) != (struct $9IRCALLARG*)0ull);
	goto label$1285;
	label$996:;
	TMP$551$1 = 0ll;
	label$1285:;
	if( TMP$551$1 == 0ll) goto label$995;
	{
		int64 TMP$552$2;
		struct $9IRCALLARG* PREV$2;
		void* vr$5 = LISTGETPREV( (void*)ARG$1 );
		PREV$2 = (struct $9IRCALLARG*)vr$5;
		struct $8EXPRNODE* EXPR$2;
		struct $8EXPRNODE* vr$7 = EXPRNEWVREG( *(struct $6IRVREG**)((uint8*)ARG$1 + 8ll), 0ll );
		EXPR$2 = vr$7;
		if( *(struct $8FBSYMBOL**)ARG$1 == (struct $8FBSYMBOL*)0ull) goto label$997;
		TMP$552$2 = (int64)-((struct $8FBSYMBOL*)(int64)-(*(int64*)((uint8*)*(struct $8FBSYMBOL**)ARG$1 + 96ll) != 4ll) != (struct $8FBSYMBOL*)0ull);
		goto label$1286;
		label$997:;
		TMP$552$2 = 0ll;
		label$1286:;
		if( TMP$552$2 == 0ll) goto label$999;
		{
			_Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( *(struct $8FBSYMBOL**)ARG$1, &DTYPE$1, &SUBTYPE$1 );
			struct $8EXPRNODE* vr$16 = EXPRNEWCAST( DTYPE$1, SUBTYPE$1, EXPR$2 );
			EXPR$2 = vr$16;
		}
		label$999:;
		label$998:;
		FBSTRING* vr$17 = EXPRFLUSH( EXPR$2, 0ll );
		fb_StrConcatByref( (void*)S$1, -1ll, (void*)vr$17, -1ll, 0 );
		LISTDELNODE( (struct $5TLIST*)((uint8*)&IRHL$ + 120ll), (void*)ARG$1 );
		if( PREV$2 == (struct $9IRCALLARG*)0ull) goto label$1001;
		{
			if( *(int64*)((uint8*)PREV$2 + 16ll) != LEVEL$1) goto label$1003;
			{
				fb_StrConcatByref( (void*)S$1, -1ll, (void*)", ", 3ll, 0 );
			}
			label$1003:;
			label$1002:;
		}
		label$1001:;
		label$1000:;
		ARG$1 = PREV$2;
	}
	goto label$994;
	label$995:;
	fb_StrConcatByref( (void*)S$1, -1ll, (void*)" )", 3ll, 0 );
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$1005;
	{
		fb_StrConcatByref( (void*)S$1, -1ll, (void*)";", 2ll, 0 );
		HWRITELINE( S$1, 0ll );
	}
	goto label$1004;
	label$1005:;
	{
		struct $8EXPRNODE* vr$23 = EXPRNEWTEXT( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), (char*)*(char**)S$1 );
		EXPRSTORE( VR$1, vr$23, -1ll );
	}
	label$1004:;
	label$993:;
}

static void _EMITCALL( struct $8FBSYMBOL* PROC$1, int64 BYTESTOPOP$1, struct $6IRVREG* VR$1, int64 LEVEL$1 )
{
	label$1006:;
	static FBSTRING S$1;
	char* vr$0 = SYMBGETMANGLEDNAME( PROC$1 );
	fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$0, 0ll, 0 );
	HDOCALL( &S$1, BYTESTOPOP$1, VR$1, LEVEL$1 );
	label$1007:;
}

static void _EMITCALLPTR( struct $8FBSYMBOL* PROC$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1, int64 BYTESTOPOP$1, int64 LEVEL$1 )
{
	label$1008:;
	static FBSTRING S$1;
	fb_StrAssign( (void*)&S$1, -1ll, (void*)"(", 2ll, 0 );
	struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V1$1, 0ll );
	FBSTRING* vr$1 = EXPRFLUSH( vr$0, 0ll );
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$1, -1ll, 0 );
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)")", 2ll, 0 );
	HDOCALL( &S$1, BYTESTOPOP$1, VR$1, LEVEL$1 );
	label$1009:;
}

static void _EMITJUMPPTR( struct $6IRVREG* V1$1 )
{
	FBSTRING TMP$554$1;
	FBSTRING TMP$555$1;
	FBSTRING TMP$556$1;
	label$1010:;
	__builtin_memset( &TMP$556$1, 0, 24ll );
	struct $8EXPRNODE* vr$1 = EXPRNEWVREG( V1$1, 0ll );
	FBSTRING* vr$2 = EXPRFLUSH( vr$1, -1ll );
	__builtin_memset( &TMP$554$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$554$1, (void*)"goto *", 7ll, (void*)vr$2, -1ll );
	__builtin_memset( &TMP$555$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$555$1, (void*)vr$5, -1ll, (void*)";", 2ll );
	fb_StrAssign( (void*)&TMP$556$1, -1ll, (void*)vr$8, -1ll, 0 );
	HWRITELINE( &TMP$556$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$556$1 );
	label$1011:;
}

static void _EMITBRANCH( int64 OP$1, struct $8FBSYMBOL* LABEL$1 )
{
	FBSTRING TMP$558$1;
	FBSTRING TMP$559$1;
	FBSTRING TMP$560$1;
	label$1012:;
	__builtin_memset( &TMP$560$1, 0, 24ll );
	char* vr$1 = SYMBGETMANGLEDNAME( LABEL$1 );
	__builtin_memset( &TMP$558$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$558$1, (void*)"goto ", 6ll, (void*)vr$1, 0ll );
	__builtin_memset( &TMP$559$1, 0, 24ll );
	FBSTRING* vr$7 = fb_StrConcat( &TMP$559$1, (void*)vr$4, -1ll, (void*)";", 2ll );
	fb_StrAssign( (void*)&TMP$560$1, -1ll, (void*)vr$7, -1ll, 0 );
	HWRITELINE( &TMP$560$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$560$1 );
	label$1013:;
}

static void _EMITJMPTB( struct $6IRVREG* V1$1, struct $8FBSYMBOL* TBSYM$1, uint64* VALUES$1, struct $8FBSYMBOL** LABELS$1, int64 LABELCOUNT$1, struct $8FBSYMBOL* DEFLABEL$1, uint64 BIAS$1, uint64 SPAN$1 )
{
	FBSTRING TMP$570$1;
	FBSTRING TMP$571$1;
	FBSTRING TMP$572$1;
	FBSTRING TMP$573$1;
	FBSTRING TMP$574$1;
	FBSTRING TMP$579$1;
	FBSTRING TMP$581$1;
	FBSTRING TMP$582$1;
	FBSTRING TMP$583$1;
	FBSTRING TMP$584$1;
	FBSTRING TMP$585$1;
	FBSTRING TMP$586$1;
	FBSTRING TMP$587$1;
	FBSTRING TMP$588$1;
	FBSTRING TMP$589$1;
	FBSTRING TMP$590$1;
	label$1014:;
	FBSTRING TB$1;
	__builtin_memset( &TB$1, 0, 24ll );
	FBSTRING TEMP$1;
	__builtin_memset( &TEMP$1, 0, 24ll );
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	struct $8EXPRNODE* L$1;
	$11FB_DATATYPE DTYPE$1;
	DTYPE$1 = *($11FB_DATATYPE*)((uint8*)V1$1 + 8ll);
	struct $8EXPRNODE* vr$4 = EXPRNEWVREG( V1$1, 0ll );
	FBSTRING* vr$5 = EXPRFLUSH( vr$4, 0ll );
	fb_StrAssign( (void*)&TEMP$1, -1ll, (void*)vr$5, -1ll, 0 );
	if( LABELCOUNT$1 > 0ll) goto label$1017;
	{
		FBSTRING TMP$561$2;
		FBSTRING TMP$562$2;
		FBSTRING TMP$563$2;
		FBSTRING TMP$565$2;
		FBSTRING TMP$566$2;
		FBSTRING TMP$567$2;
		__builtin_memset( &TMP$563$2, 0, 24ll );
		char* vr$8 = SYMBGETMANGLEDNAME( DEFLABEL$1 );
		__builtin_memset( &TMP$561$2, 0, 24ll );
		FBSTRING* vr$11 = fb_StrConcat( &TMP$561$2, (void*)"goto ", 6ll, (void*)vr$8, 0ll );
		__builtin_memset( &TMP$562$2, 0, 24ll );
		FBSTRING* vr$14 = fb_StrConcat( &TMP$562$2, (void*)vr$11, -1ll, (void*)";", 2ll );
		fb_StrAssign( (void*)&TMP$563$2, -1ll, (void*)vr$14, -1ll, 0 );
		HWRITELINE( &TMP$563$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$563$2 );
		__builtin_memset( &TMP$567$2, 0, 24ll );
		__builtin_memset( &TMP$565$2, 0, 24ll );
		FBSTRING* vr$22 = fb_StrConcat( &TMP$565$2, (void*)"(void)", 7ll, (void*)&TEMP$1, -1ll );
		__builtin_memset( &TMP$566$2, 0, 24ll );
		FBSTRING* vr$25 = fb_StrConcat( &TMP$566$2, (void*)vr$22, -1ll, (void*)";", 2ll );
		fb_StrAssign( (void*)&TMP$567$2, -1ll, (void*)vr$25, -1ll, 0 );
		HWRITELINE( &TMP$567$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$567$2 );
		fb_StrDelete( (FBSTRING*)&LN$1 );
		fb_StrDelete( (FBSTRING*)&TEMP$1 );
		fb_StrDelete( (FBSTRING*)&TB$1 );
		goto label$1015;
	}
	label$1017:;
	label$1016:;
	char* vr$32 = SYMBUNIQUEID( (boolean)0ll );
	fb_StrAssign( (void*)&TB$1, -1ll, (void*)vr$32, 0ll, 0 );
	struct $8EXPRNODE* vr$35 = EXPRNEWIMMI( (int64)(SPAN$1 + 1ull), 8ll );
	L$1 = vr$35;
	__builtin_memset( &TMP$574$1, 0, 24ll );
	FBSTRING* vr$37 = EXPRFLUSH( L$1, 0ll );
	__builtin_memset( &TMP$570$1, 0, 24ll );
	FBSTRING* vr$41 = fb_StrConcat( &TMP$570$1, (void*)"static const void* ", 20ll, (void*)&TB$1, -1ll );
	__builtin_memset( &TMP$571$1, 0, 24ll );
	FBSTRING* vr$44 = fb_StrConcat( &TMP$571$1, (void*)vr$41, -1ll, (void*)"[", 2ll );
	__builtin_memset( &TMP$572$1, 0, 24ll );
	FBSTRING* vr$47 = fb_StrConcat( &TMP$572$1, (void*)vr$44, -1ll, (void*)vr$37, -1ll );
	__builtin_memset( &TMP$573$1, 0, 24ll );
	FBSTRING* vr$50 = fb_StrConcat( &TMP$573$1, (void*)vr$47, -1ll, (void*)"] = {", 6ll );
	fb_StrAssign( (void*)&TMP$574$1, -1ll, (void*)vr$50, -1ll, 0 );
	HWRITELINE( &TMP$574$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$574$1 );
	SECTIONINDENT(  );
	int64 I$1;
	I$1 = 0ll;
	int64 VALUE$1;
	VALUE$1 = 0ll;
	label$1018:;
	{
		FBSTRING TMP$576$2;
		FBSTRING TMP$577$2;
		FBSTRING TMP$578$2;
		struct $8FBSYMBOL* LABEL$2;
		__builtin_memset( &LABEL$2, 0, 8ll );
		if( (uint64)VALUE$1 != *(uint64*)((uint8*)VALUES$1 + (I$1 << (3ll & 63ll)))) goto label$1022;
		{
			LABEL$2 = *(struct $8FBSYMBOL**)((uint8*)LABELS$1 + (I$1 << (3ll & 63ll)));
			I$1 = I$1 + 1ll;
		}
		goto label$1021;
		label$1022:;
		{
			LABEL$2 = DEFLABEL$1;
		}
		label$1021:;
		__builtin_memset( &TMP$578$2, 0, 24ll );
		char* vr$61 = SYMBGETMANGLEDNAME( LABEL$2 );
		__builtin_memset( &TMP$576$2, 0, 24ll );
		FBSTRING* vr$64 = fb_StrConcat( &TMP$576$2, (void*)"&&", 3ll, (void*)vr$61, 0ll );
		__builtin_memset( &TMP$577$2, 0, 24ll );
		FBSTRING* vr$67 = fb_StrConcat( &TMP$577$2, (void*)vr$64, -1ll, (void*)",", 2ll );
		fb_StrAssign( (void*)&TMP$578$2, -1ll, (void*)vr$67, -1ll, 0 );
		HWRITELINE( &TMP$578$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$578$2 );
		if( (uint64)VALUE$1 != SPAN$1) goto label$1024;
		{
			goto label$1019;
		}
		label$1024:;
		label$1023:;
		VALUE$1 = VALUE$1 + 1ll;
	}
	label$1020:;
	goto label$1018;
	label$1019:;
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$579$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$579$1, -1ll, (void*)"};", 3ll, 0 );
	HWRITELINE( &TMP$579$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$579$1 );
	struct $8EXPRNODE* vr$76 = EXPRNEWTEXT( DTYPE$1, (struct $8FBSYMBOL*)0ull, (char*)*(char**)&TEMP$1 );
	L$1 = vr$76;
	if( BIAS$1 == 0ull) goto label$1026;
	{
		struct $8EXPRNODE* vr$77 = EXPRNEWIMMI( (int64)BIAS$1, DTYPE$1 );
		struct $8EXPRNODE* vr$78 = EXPRNEWBOP( 29ll, L$1, vr$77 );
		L$1 = vr$78;
	}
	label$1026:;
	label$1025:;
	struct $8EXPRNODE* vr$79 = EXPRNEWIMMI( (int64)SPAN$1, DTYPE$1 );
	struct $8EXPRNODE* vr$80 = EXPRNEWBOP( 46ll, L$1, vr$79 );
	L$1 = vr$80;
	__builtin_memset( &TMP$585$1, 0, 24ll );
	char* vr$82 = SYMBGETMANGLEDNAME( DEFLABEL$1 );
	FBSTRING* vr$83 = EXPRFLUSH( L$1, 0ll );
	__builtin_memset( &TMP$581$1, 0, 24ll );
	FBSTRING* vr$86 = fb_StrConcat( &TMP$581$1, (void*)"if( ", 5ll, (void*)vr$83, -1ll );
	__builtin_memset( &TMP$582$1, 0, 24ll );
	FBSTRING* vr$89 = fb_StrConcat( &TMP$582$1, (void*)vr$86, -1ll, (void*)" ) goto ", 9ll );
	__builtin_memset( &TMP$583$1, 0, 24ll );
	FBSTRING* vr$92 = fb_StrConcat( &TMP$583$1, (void*)vr$89, -1ll, (void*)vr$82, 0ll );
	__builtin_memset( &TMP$584$1, 0, 24ll );
	FBSTRING* vr$95 = fb_StrConcat( &TMP$584$1, (void*)vr$92, -1ll, (void*)";", 2ll );
	fb_StrAssign( (void*)&TMP$585$1, -1ll, (void*)vr$95, -1ll, 0 );
	HWRITELINE( &TMP$585$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$585$1 );
	struct $8EXPRNODE* vr$99 = EXPRNEWTEXT( DTYPE$1, (struct $8FBSYMBOL*)0ull, (char*)*(char**)&TEMP$1 );
	L$1 = vr$99;
	struct $8EXPRNODE* vr$100 = EXPRNEWIMMI( (int64)BIAS$1, DTYPE$1 );
	struct $8EXPRNODE* vr$101 = EXPRNEWBOP( 29ll, L$1, vr$100 );
	L$1 = vr$101;
	__builtin_memset( &TMP$590$1, 0, 24ll );
	FBSTRING* vr$103 = EXPRFLUSH( L$1, 0ll );
	__builtin_memset( &TMP$586$1, 0, 24ll );
	FBSTRING* vr$107 = fb_StrConcat( &TMP$586$1, (void*)"goto *", 7ll, (void*)&TB$1, -1ll );
	__builtin_memset( &TMP$587$1, 0, 24ll );
	FBSTRING* vr$110 = fb_StrConcat( &TMP$587$1, (void*)vr$107, -1ll, (void*)"[", 2ll );
	__builtin_memset( &TMP$588$1, 0, 24ll );
	FBSTRING* vr$113 = fb_StrConcat( &TMP$588$1, (void*)vr$110, -1ll, (void*)vr$103, -1ll );
	__builtin_memset( &TMP$589$1, 0, 24ll );
	FBSTRING* vr$116 = fb_StrConcat( &TMP$589$1, (void*)vr$113, -1ll, (void*)"];", 3ll );
	fb_StrAssign( (void*)&TMP$590$1, -1ll, (void*)vr$116, -1ll, 0 );
	HWRITELINE( &TMP$590$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$590$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	fb_StrDelete( (FBSTRING*)&TEMP$1 );
	fb_StrDelete( (FBSTRING*)&TB$1 );
	label$1015:;
}

static void _EMITMEM( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$1027:;
	{
		if( OP$1 != 108ll) goto label$1030;
		label$1031:;
		{
			FBSTRING TMP$592$3;
			FBSTRING TMP$593$3;
			FBSTRING TMP$594$3;
			FBSTRING TMP$595$3;
			FBSTRING TMP$596$3;
			FBSTRING TMP$597$3;
			FBSTRING TMP$598$3;
			__builtin_memset( &TMP$598$3, 0, 24ll );
			struct $8EXPRNODE* vr$1 = EXPRNEWVREG( V2$1, 0ll );
			FBSTRING* vr$2 = EXPRFLUSH( vr$1, 0ll );
			FBSTRING* vr$3 = fb_LongintToStr( FILLCHAR$1 );
			struct $8EXPRNODE* vr$4 = EXPRNEWVREG( V1$1, 0ll );
			FBSTRING* vr$5 = EXPRFLUSH( vr$4, 0ll );
			__builtin_memset( &TMP$592$3, 0, 24ll );
			FBSTRING* vr$8 = fb_StrConcat( &TMP$592$3, (void*)"__builtin_memset( ", 19ll, (void*)vr$5, -1ll );
			__builtin_memset( &TMP$593$3, 0, 24ll );
			FBSTRING* vr$11 = fb_StrConcat( &TMP$593$3, (void*)vr$8, -1ll, (void*)", ", 3ll );
			__builtin_memset( &TMP$594$3, 0, 24ll );
			FBSTRING* vr$14 = fb_StrConcat( &TMP$594$3, (void*)vr$11, -1ll, (void*)vr$3, -1ll );
			__builtin_memset( &TMP$595$3, 0, 24ll );
			FBSTRING* vr$17 = fb_StrConcat( &TMP$595$3, (void*)vr$14, -1ll, (void*)", ", 3ll );
			__builtin_memset( &TMP$596$3, 0, 24ll );
			FBSTRING* vr$20 = fb_StrConcat( &TMP$596$3, (void*)vr$17, -1ll, (void*)vr$2, -1ll );
			__builtin_memset( &TMP$597$3, 0, 24ll );
			FBSTRING* vr$23 = fb_StrConcat( &TMP$597$3, (void*)vr$20, -1ll, (void*)" );", 4ll );
			fb_StrAssign( (void*)&TMP$598$3, -1ll, (void*)vr$23, -1ll, 0 );
			HWRITELINE( &TMP$598$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$598$3 );
		}
		goto label$1029;
		label$1030:;
		if( OP$1 != 106ll) goto label$1032;
		label$1033:;
		{
			FBSTRING TMP$600$3;
			FBSTRING TMP$601$3;
			FBSTRING TMP$602$3;
			FBSTRING TMP$603$3;
			FBSTRING TMP$604$3;
			FBSTRING TMP$605$3;
			FBSTRING TMP$606$3;
			__builtin_memset( &TMP$606$3, 0, 24ll );
			FBSTRING* vr$28 = fb_ULongintToStr( (uint64)BYTES$1 );
			struct $8EXPRNODE* vr$29 = EXPRNEWVREG( V2$1, 0ll );
			FBSTRING* vr$30 = EXPRFLUSH( vr$29, 0ll );
			struct $8EXPRNODE* vr$31 = EXPRNEWVREG( V1$1, 0ll );
			FBSTRING* vr$32 = EXPRFLUSH( vr$31, 0ll );
			__builtin_memset( &TMP$600$3, 0, 24ll );
			FBSTRING* vr$35 = fb_StrConcat( &TMP$600$3, (void*)"__builtin_memcpy( ", 19ll, (void*)vr$32, -1ll );
			__builtin_memset( &TMP$601$3, 0, 24ll );
			FBSTRING* vr$38 = fb_StrConcat( &TMP$601$3, (void*)vr$35, -1ll, (void*)", ", 3ll );
			__builtin_memset( &TMP$602$3, 0, 24ll );
			FBSTRING* vr$41 = fb_StrConcat( &TMP$602$3, (void*)vr$38, -1ll, (void*)vr$30, -1ll );
			__builtin_memset( &TMP$603$3, 0, 24ll );
			FBSTRING* vr$44 = fb_StrConcat( &TMP$603$3, (void*)vr$41, -1ll, (void*)", ", 3ll );
			__builtin_memset( &TMP$604$3, 0, 24ll );
			FBSTRING* vr$47 = fb_StrConcat( &TMP$604$3, (void*)vr$44, -1ll, (void*)vr$28, -1ll );
			__builtin_memset( &TMP$605$3, 0, 24ll );
			FBSTRING* vr$50 = fb_StrConcat( &TMP$605$3, (void*)vr$47, -1ll, (void*)" );", 4ll );
			fb_StrAssign( (void*)&TMP$606$3, -1ll, (void*)vr$50, -1ll, 0 );
			HWRITELINE( &TMP$606$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$606$3 );
		}
		label$1032:;
		label$1029:;
	}
	label$1028:;
}

static void _EMITMACRO( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1 )
{
	label$1034:;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* R$1;
	{
		if( OP$1 != 110ll) goto label$1037;
		label$1038:;
		{
			FBSTRING TMP$607$3;
			FBSTRING TMP$608$3;
			struct $8EXPRNODE* vr$0 = EXPRNEWVREG( V1$1, 0ll );
			L$1 = vr$0;
			struct $8EXPRNODE* vr$1 = EXPRNEWVREG( V2$1, 0ll );
			R$1 = vr$1;
			__builtin_memset( &TMP$608$3, 0, 24ll );
			struct $8EXPRNODE* vr$3 = EXPRNEWMACRO( OP$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, L$1, R$1 );
			FBSTRING* vr$4 = EXPRFLUSH( vr$3, 0ll );
			__builtin_memset( &TMP$607$3, 0, 24ll );
			FBSTRING* vr$7 = fb_StrConcat( &TMP$607$3, (void*)vr$4, -1ll, (void*)";", 2ll );
			fb_StrAssign( (void*)&TMP$608$3, -1ll, (void*)vr$7, -1ll, 0 );
			HWRITELINE( &TMP$608$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$608$3 );
		}
		goto label$1036;
		label$1037:;
		if( OP$1 != 111ll) goto label$1039;
		label$1040:;
		{
			FBSTRING TMP$609$3;
			FBSTRING TMP$610$3;
			struct $8EXPRNODE* vr$11 = EXPRNEWVREG( V1$1, 0ll );
			L$1 = vr$11;
			__builtin_memset( &TMP$610$3, 0, 24ll );
			struct $8EXPRNODE* vr$13 = EXPRNEWMACRO( OP$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, L$1, (struct $8EXPRNODE*)0ull );
			FBSTRING* vr$14 = EXPRFLUSH( vr$13, 0ll );
			__builtin_memset( &TMP$609$3, 0, 24ll );
			FBSTRING* vr$17 = fb_StrConcat( &TMP$609$3, (void*)vr$14, -1ll, (void*)";", 2ll );
			fb_StrAssign( (void*)&TMP$610$3, -1ll, (void*)vr$17, -1ll, 0 );
			HWRITELINE( &TMP$610$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$610$3 );
		}
		goto label$1036;
		label$1039:;
		if( OP$1 != 113ll) goto label$1041;
		label$1042:;
		{
			struct $8EXPRNODE* vr$21 = EXPRNEWVREG( V1$1, 0ll );
			L$1 = vr$21;
			struct $8EXPRNODE* vr$24 = EXPRNEWMACRO( OP$1, *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 56ll), L$1, (struct $8EXPRNODE*)0ull );
			L$1 = vr$24;
			EXPRSTORE( VR$1, L$1, 0ll );
		}
		goto label$1036;
		label$1041:;
		if( OP$1 != 112ll) goto label$1043;
		label$1044:;
		{
			FBSTRING TMP$611$3;
			FBSTRING TMP$612$3;
			struct $8EXPRNODE* vr$25 = EXPRNEWVREG( V1$1, 0ll );
			L$1 = vr$25;
			struct $8EXPRNODE* vr$26 = EXPRNEWVREG( V2$1, 0ll );
			R$1 = vr$26;
			__builtin_memset( &TMP$612$3, 0, 24ll );
			struct $8EXPRNODE* vr$28 = EXPRNEWMACRO( OP$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, L$1, R$1 );
			FBSTRING* vr$29 = EXPRFLUSH( vr$28, 0ll );
			__builtin_memset( &TMP$611$3, 0, 24ll );
			FBSTRING* vr$32 = fb_StrConcat( &TMP$611$3, (void*)vr$29, -1ll, (void*)";", 2ll );
			fb_StrAssign( (void*)&TMP$612$3, -1ll, (void*)vr$32, -1ll, 0 );
			HWRITELINE( &TMP$612$3, 0ll );
			fb_StrDelete( (FBSTRING*)&TMP$612$3 );
		}
		label$1043:;
		label$1036:;
	}
	label$1035:;
}

static void _EMITDECL( struct $8FBSYMBOL* SYM$1 )
{
	label$1045:;
	struct $8FBSYMBOL* ARRAY$1;
	int64 vr$0 = HISSTATICWITHDTOR( SYM$1 );
	if( vr$0 == 0ll) goto label$1048;
	{
		goto label$1046;
	}
	label$1048:;
	label$1047:;
	ARRAY$1 = *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 152ll);
	if( ARRAY$1 == (struct $8FBSYMBOL*)0ull) goto label$1050;
	{
		int64 vr$2 = HISSTATICWITHDTOR( ARRAY$1 );
		if( vr$2 == 0ll) goto label$1052;
		{
			goto label$1046;
		}
		label$1052:;
		label$1051:;
	}
	label$1050:;
	label$1049:;
	HMAYBEEMITLOCALVAR( SYM$1 );
	label$1046:;
}

static void _EMITDBG( int64 OP$1, struct $8FBSYMBOL* PROC$1, int64 LNUM$1, char* FILENAME$1 )
{
	label$1053:;
	if( OP$1 != 114ll) goto label$1056;
	{
		*(int64*)((uint8*)&CTX$ + 5176ll) = LNUM$1;
		if( FILENAME$1 == (char*)0ull) goto label$1058;
		{
			HUPDATECURRENTFILENAME( FILENAME$1 );
		}
		label$1058:;
		label$1057:;
	}
	label$1056:;
	label$1055:;
	label$1054:;
}

static void _EMITCOMMENT( char* TEXT$1 )
{
	label$1059:;
	int64 LENGTH$1;
	static FBSTRING S$1;
	fb_StrAssign( (void*)&S$1, -1ll, (void*)TEXT$1, 0ll, 0 );
	FBSTRING* vr$0 = fb_TRIM( (FBSTRING*)&S$1 );
	fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$0, -1ll, 0 );
	int64 vr$1 = fb_StrLen( (void*)&S$1, -1ll );
	LENGTH$1 = vr$1;
	if( LENGTH$1 <= 0ll) goto label$1062;
	{
		FBSTRING TMP$615$2;
		FBSTRING TMP$616$2;
		if( (uint64)(int64)*(uint8*)((uint8*)((uint8*)*(char**)&S$1 + LENGTH$1) + -1ll) != 92ull) goto label$1064;
		{
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"not_an_escape", 14ll, 0 );
		}
		label$1064:;
		label$1063:;
		__builtin_memset( &TMP$616$2, 0, 24ll );
		__builtin_memset( &TMP$615$2, 0, 24ll );
		FBSTRING* vr$7 = fb_StrConcat( &TMP$615$2, (void*)"// ", 4ll, (void*)&S$1, -1ll );
		fb_StrAssign( (void*)&TMP$616$2, -1ll, (void*)vr$7, -1ll, 0 );
		HWRITELINE( &TMP$616$2, -1ll );
		fb_StrDelete( (FBSTRING*)&TMP$616$2 );
	}
	label$1062:;
	label$1061:;
	label$1060:;
}

static int32 HFINDLABELINSEENLIST( struct $5TLIST* LABELLIST$1, struct $8FBSYMBOL* LABELSYM$1 )
{
	int32 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 4ll );
	label$1065:;
	struct $8FBSYMBOL** SYMNODE$1;
	void* vr$1 = LISTGETHEAD( LABELLIST$1 );
	SYMNODE$1 = (struct $8FBSYMBOL**)vr$1;
	int32 INDEX$1;
	INDEX$1 = -1;
	int32 CURINDEX$1;
	CURINDEX$1 = 0;
	label$1067:;
	{
		if( SYMNODE$1 != (struct $8FBSYMBOL**)0ull) goto label$1071;
		{
			goto label$1068;
			label$1071:;
		}
		if( *SYMNODE$1 != LABELSYM$1) goto label$1073;
		{
			INDEX$1 = CURINDEX$1;
			goto label$1068;
		}
		label$1073:;
		label$1072:;
		void* vr$3 = LISTGETNEXT( (void*)SYMNODE$1 );
		SYMNODE$1 = (struct $8FBSYMBOL**)vr$3;
		CURINDEX$1 = (int32)((int64)CURINDEX$1 + 1ll);
	}
	label$1069:;
	goto label$1067;
	label$1068:;
	fb$result$1 = INDEX$1;
	goto label$1066;
	label$1066:;
	return fb$result$1;
}

static void _EMITASMLINE( struct $9ASTASMTOK* ASMTOKENHEAD$1 )
{
	label$1074:;
	int64 USES_LABEL$1;
	__builtin_memset( &USES_LABEL$1, 0, 8ll );
	int64 LABELINDEX$1;
	__builtin_memset( &LABELINDEX$1, 0, 8ll );
	int64 LABELINDEXBASE$1;
	__builtin_memset( &LABELINDEXBASE$1, 0, 8ll );
	struct $5TLIST SEENLABELLIST$1;
	__builtin_memset( &SEENLABELLIST$1, 0, 64ll );
	LISTINIT( &SEENLABELLIST$1, 8ll, 8ll, 4294967295ll );
	struct $9ASTASMTOK* N$1;
	N$1 = ASMTOKENHEAD$1;
	label$1076:;
	if( N$1 == (struct $9ASTASMTOK*)0ull) goto label$1077;
	{
		if( *(int64*)N$1 != 1ll) goto label$1079;
		{
			{
				$12FB_SYMBCLASS TMP$617$4;
				TMP$617$4 = *($12FB_SYMBCLASS*)*(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll);
				if( TMP$617$4 != 7ll) goto label$1081;
				label$1082:;
				{
					USES_LABEL$1 = -1ll;
				}
				goto label$1080;
				label$1081:;
				if( TMP$617$4 != 1ll) goto label$1083;
				label$1084:;
				{
					LABELINDEX$1 = LABELINDEX$1 + 1ll;
				}
				label$1083:;
				label$1080:;
			}
		}
		label$1079:;
		label$1078:;
		N$1 = *(struct $9ASTASMTOK**)((uint8*)N$1 + 16ll);
	}
	goto label$1076;
	label$1077:;
	LABELINDEXBASE$1 = LABELINDEX$1;
	FBSTRING LN$1;
	fb_StrInit( (void*)&LN$1, -1ll, (void*)"__asm__", 8ll, 0 );
	int64 vr$11 = SECTIONINSIDEPROC(  );
	if( vr$11 == 0ll) goto label$1086;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" __volatile__", 14ll, 0 );
	}
	label$1086:;
	label$1085:;
	if( USES_LABEL$1 == 0ll) goto label$1088;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" goto", 6ll, 0 );
	}
	label$1088:;
	label$1087:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"( ", 3ll, 0 );
	FBSTRING ASMCODE$1;
	__builtin_memset( &ASMCODE$1, 0, 24ll );
	int64 OPERANDINDEX$1;
	__builtin_memset( &OPERANDINDEX$1, 0, 8ll );
	FBSTRING OUTPUTCONSTRAINTS$1;
	__builtin_memset( &OUTPUTCONSTRAINTS$1, 0, 24ll );
	FBSTRING INPUTCONSTRAINTS$1;
	__builtin_memset( &INPUTCONSTRAINTS$1, 0, 24ll );
	FBSTRING LABELLIST$1;
	__builtin_memset( &LABELLIST$1, 0, 24ll );
	N$1 = ASMTOKENHEAD$1;
	label$1089:;
	if( N$1 == (struct $9ASTASMTOK*)0ull) goto label$1090;
	{
		{
			$14AST_ASMTOKTYPE TMP$621$3;
			TMP$621$3 = *($14AST_ASMTOKTYPE*)N$1;
			if( TMP$621$3 != 0ll) goto label$1092;
			label$1093:;
			{
				FBSTRING TMP$622$4;
				__builtin_memset( &TMP$622$4, 0, 24ll );
				FBSTRING* vr$25 = fb_StrConcat( &TMP$622$4, (void*)&ASMCODE$1, -1ll, *(void**)((uint8*)N$1 + 8ll), 0ll );
				fb_StrAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$25, -1ll, 0 );
			}
			goto label$1091;
			label$1092:;
			if( TMP$621$3 != 1ll) goto label$1094;
			label$1095:;
			{
				if( *(int64*)((uint8*)&ENV$ + 264ll) != 0ll) goto label$1097;
				{
					int64 vr$27 = SECTIONINSIDEPROC(  );
					if( vr$27 == 0ll) goto label$1099;
					{
						{
							$12FB_SYMBCLASS TMP$623$7;
							TMP$623$7 = *($12FB_SYMBCLASS*)*(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll);
							if( TMP$623$7 != 1ll) goto label$1101;
							label$1102:;
							{
								fb_StrConcatAssign( (void*)&ASMCODE$1, -1ll, (void*)"%", 2ll, 0 );
								FBSTRING* vr$31 = fb_LongintToStr( OPERANDINDEX$1 );
								fb_StrConcatAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$31, -1ll, 0 );
								OPERANDINDEX$1 = OPERANDINDEX$1 + 1ll;
								if( USES_LABEL$1 == 0ll) goto label$1104;
								{
									FBSTRING TMP$626$9;
									FBSTRING TMP$627$9;
									FBSTRING TMP$628$9;
									int64 vr$35 = fb_StrLen( (void*)&INPUTCONSTRAINTS$1, -1ll );
									if( vr$35 <= 0ll) goto label$1106;
									{
										fb_StrConcatAssign( (void*)&INPUTCONSTRAINTS$1, -1ll, (void*)", ", 3ll, 0 );
									}
									label$1106:;
									label$1105:;
									char* vr$38 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) );
									__builtin_memset( &TMP$626$9, 0, 24ll );
									FBSTRING* vr$41 = fb_StrConcat( &TMP$626$9, (void*)"\x22m\x22 (", 6ll, (void*)vr$38, 0ll );
									__builtin_memset( &TMP$627$9, 0, 24ll );
									FBSTRING* vr$44 = fb_StrConcat( &TMP$627$9, (void*)vr$41, -1ll, (void*)")", 2ll );
									__builtin_memset( &TMP$628$9, 0, 24ll );
									FBSTRING* vr$48 = fb_StrConcat( &TMP$628$9, (void*)&INPUTCONSTRAINTS$1, -1ll, (void*)vr$44, -1ll );
									fb_StrAssign( (void*)&INPUTCONSTRAINTS$1, -1ll, (void*)vr$48, -1ll, 0 );
								}
								goto label$1103;
								label$1104:;
								{
									FBSTRING TMP$630$9;
									FBSTRING TMP$631$9;
									FBSTRING TMP$632$9;
									int64 vr$51 = fb_StrLen( (void*)&OUTPUTCONSTRAINTS$1, -1ll );
									if( vr$51 <= 0ll) goto label$1108;
									{
										fb_StrConcatAssign( (void*)&OUTPUTCONSTRAINTS$1, -1ll, (void*)", ", 3ll, 0 );
									}
									label$1108:;
									label$1107:;
									char* vr$54 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) );
									__builtin_memset( &TMP$630$9, 0, 24ll );
									FBSTRING* vr$57 = fb_StrConcat( &TMP$630$9, (void*)"\x22+m\x22 (", 7ll, (void*)vr$54, 0ll );
									__builtin_memset( &TMP$631$9, 0, 24ll );
									FBSTRING* vr$60 = fb_StrConcat( &TMP$631$9, (void*)vr$57, -1ll, (void*)")", 2ll );
									__builtin_memset( &TMP$632$9, 0, 24ll );
									FBSTRING* vr$64 = fb_StrConcat( &TMP$632$9, (void*)&OUTPUTCONSTRAINTS$1, -1ll, (void*)vr$60, -1ll );
									fb_StrAssign( (void*)&OUTPUTCONSTRAINTS$1, -1ll, (void*)vr$64, -1ll, 0 );
								}
								label$1103:;
							}
							goto label$1100;
							label$1101:;
							if( TMP$623$7 != 7ll) goto label$1109;
							label$1110:;
							{
								int64 LABELNUM$8;
								struct $8FBSYMBOL* LABELSYM$8;
								LABELSYM$8 = *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll);
								int32 SEENLABELINDEX$8;
								int32 vr$68 = HFINDLABELINSEENLIST( &SEENLABELLIST$1, LABELSYM$8 );
								SEENLABELINDEX$8 = vr$68;
								if( (int64)SEENLABELINDEX$8 == -1ll) goto label$1112;
								{
									LABELNUM$8 = (int64)SEENLABELINDEX$8 + LABELINDEXBASE$1;
								}
								goto label$1111;
								label$1112:;
								{
									FBSTRING TMP$633$9;
									LABELNUM$8 = LABELINDEX$1;
									LABELINDEX$1 = LABELINDEX$1 + 1ll;
									void* vr$74 = LISTNEWNODE( &SEENLABELLIST$1 );
									*(struct $8FBSYMBOL**)vr$74 = LABELSYM$8;
									int64 vr$76 = fb_StrLen( (void*)&LABELLIST$1, -1ll );
									if( vr$76 <= 0ll) goto label$1114;
									{
										fb_StrConcatAssign( (void*)&LABELLIST$1, -1ll, (void*)", ", 3ll, 0 );
									}
									label$1114:;
									label$1113:;
									char* vr$78 = SYMBGETMANGLEDNAME( LABELSYM$8 );
									__builtin_memset( &TMP$633$9, 0, 24ll );
									FBSTRING* vr$82 = fb_StrConcat( &TMP$633$9, (void*)&LABELLIST$1, -1ll, (void*)vr$78, 0ll );
									fb_StrAssign( (void*)&LABELLIST$1, -1ll, (void*)vr$82, -1ll, 0 );
								}
								label$1111:;
								fb_StrConcatAssign( (void*)&ASMCODE$1, -1ll, (void*)"%l", 3ll, 0 );
								FBSTRING* vr$85 = fb_LongintToStr( LABELNUM$8 );
								fb_StrConcatAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$85, -1ll, 0 );
							}
							goto label$1100;
							label$1109:;
							{
								FBSTRING TMP$635$8;
								FBSTRING* vr$88 = HGETMANGLEDNAMEFORASM( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll), -1ll );
								__builtin_memset( &TMP$635$8, 0, 24ll );
								FBSTRING* vr$92 = fb_StrConcat( &TMP$635$8, (void*)&ASMCODE$1, -1ll, (void*)vr$88, -1ll );
								fb_StrAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$92, -1ll, 0 );
							}
							label$1115:;
							label$1100:;
						}
					}
					goto label$1098;
					label$1099:;
					{
						FBSTRING TMP$636$6;
						FBSTRING* vr$95 = HGETMANGLEDNAMEFORASM( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll), -1ll );
						__builtin_memset( &TMP$636$6, 0, 24ll );
						FBSTRING* vr$99 = fb_StrConcat( &TMP$636$6, (void*)&ASMCODE$1, -1ll, (void*)vr$95, -1ll );
						fb_StrAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$99, -1ll, 0 );
					}
					label$1098:;
				}
				goto label$1096;
				label$1097:;
				{
					FBSTRING TMP$637$5;
					char* vr$102 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) );
					__builtin_memset( &TMP$637$5, 0, 24ll );
					FBSTRING* vr$106 = fb_StrConcat( &TMP$637$5, (void*)&ASMCODE$1, -1ll, (void*)vr$102, 0ll );
					fb_StrAssign( (void*)&ASMCODE$1, -1ll, (void*)vr$106, -1ll, 0 );
				}
				label$1096:;
			}
			label$1094:;
			label$1091:;
		}
		N$1 = *(struct $9ASTASMTOK**)((uint8*)N$1 + 16ll);
	}
	goto label$1089;
	label$1090:;
	LISTEND( &SEENLABELLIST$1 );
	if( *(int64*)((uint8*)&ENV$ + 264ll) != 0ll) goto label$1117;
	{
		int64 vr$111 = fb_StrLen( (void*)&ASMCODE$1, -1ll );
		HBUILDSTRLIT( &LN$1, (char*)*(char**)&ASMCODE$1, vr$111 + 1ll, 0ll );
		int64 vr$114 = SECTIONINSIDEPROC(  );
		if( vr$114 == 0ll) goto label$1119;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" : ", 4ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&OUTPUTCONSTRAINTS$1, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" : ", 4ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&INPUTCONSTRAINTS$1, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" : \x22" "cc\x22, \x22memory\x22", 18ll, 0 );
			{
				int64 TMP$640$4;
				int64 vr$122 = FBGETCPUFAMILY(  );
				TMP$640$4 = vr$122;
				if( TMP$640$4 == 0ll) goto label$1122;
				label$1123:;
				if( TMP$640$4 != 1ll) goto label$1121;
				label$1122:;
				{
					int64 vr$123 = FBGETCPUFAMILY(  );
					if( vr$123 != 0ll) goto label$1125;
					{
						if( *(int64*)((uint8*)&ENV$ + 488ll) == 0ll) goto label$1127;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22" "eax\x22, \x22" "ecx\x22, \x22" "edx\x22, \x22" "edi\x22, \x22" "esi\x22", 36ll, 0 );
						}
						goto label$1126;
						label$1127:;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22" "eax\x22, \x22" "ebx\x22, \x22" "ecx\x22, \x22" "edx\x22, \x22" "edi\x22, \x22" "esi\x22", 43ll, 0 );
						}
						label$1126:;
					}
					goto label$1124;
					label$1125:;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22rax\x22, \x22rbx\x22, \x22rcx\x22, \x22rdx\x22, \x22rdi\x22, \x22rsi\x22", 43ll, 0 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r8\x22, \x22r9\x22, \x22r10\x22, \x22r11\x22, \x22r12\x22, \x22r13\x22, \x22r14\x22, \x22r15\x22", 55ll, 0 );
					}
					label$1124:;
					if( *(int64*)((uint8*)&ENV$ + 232ll) != 1ll) goto label$1129;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22mm0\x22, \x22mm1\x22, \x22mm2\x22, \x22mm3\x22, \x22mm4\x22, \x22mm5\x22, \x22mm6\x22, \x22mm7\x22", 57ll, 0 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22xmm0\x22, \x22xmm1\x22, \x22xmm2\x22, \x22xmm3\x22, \x22xmm4\x22, \x22xmm5\x22, \x22xmm6\x22, \x22xmm7\x22", 65ll, 0 );
						int64 vr$130 = FBGETCPUFAMILY(  );
						if( vr$130 != 1ll) goto label$1131;
						{
							fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22xmm8\x22, \x22xmm9\x22, \x22xmm10\x22, \x22xmm11\x22, \x22xmm12\x22, \x22xmm13\x22, \x22xmm14\x22, \x22xmm15\x22", 71ll, 0 );
						}
						label$1131:;
						label$1130:;
					}
					label$1129:;
					label$1128:;
				}
				goto label$1120;
				label$1121:;
				if( TMP$640$4 == 2ll) goto label$1133;
				label$1134:;
				if( TMP$640$4 != 3ll) goto label$1132;
				label$1133:;
				{
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r0\x22, \x22r1\x22, \x22r2\x22, \x22r3\x22, \x22r4\x22, \x22r5\x22, \x22r6\x22", 43ll, 0 );
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r8\x22, \x22r9\x22, \x22r10\x22, \x22r11\x22, \x22r12\x22, \x22r13\x22, \x22r14\x22, \x22r15\x22", 55ll, 0 );
					int64 vr$134 = FBGETCPUFAMILY(  );
					if( vr$134 != 3ll) goto label$1136;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r16\x22, \x22r17\x22, \x22r18\x22, \x22r19\x22", 29ll, 0 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r20\x22, \x22r21\x22, \x22r22\x22, \x22r23\x22, \x22r24\x22, \x22r25\x22, \x22r26\x22, \x22r27\x22, \x22r28\x22", 64ll, 0 );
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", \x22r30\x22", 8ll, 0 );
					}
					label$1136:;
					label$1135:;
				}
				label$1132:;
				label$1120:;
			}
			if( USES_LABEL$1 == 0ll) goto label$1138;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" : ", 4ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&LABELLIST$1, -1ll, 0 );
			}
			label$1138:;
			label$1137:;
		}
		label$1119:;
		label$1118:;
	}
	goto label$1116;
	label$1117:;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&ASMCODE$1, -1ll, 0 );
	}
	label$1116:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" );", 4ll, 0 );
	HWRITELINE( &LN$1, 0ll );
	fb_StrDelete( (FBSTRING*)&LABELLIST$1 );
	fb_StrDelete( (FBSTRING*)&INPUTCONSTRAINTS$1 );
	fb_StrDelete( (FBSTRING*)&OUTPUTCONSTRAINTS$1 );
	fb_StrDelete( (FBSTRING*)&ASMCODE$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$1075:;
}

static void _EMITVARINIBEGIN( struct $8FBSYMBOL* SYM$1 )
{
	label$1139:;
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"", 1ll, 0 );
	*(int64*)((uint8*)&CTX$ + 5304ll) = 0ll;
	label$1140:;
}

static void _EMITVARINIEND( struct $8FBSYMBOL* SYM$1 )
{
	label$1141:;
	HEMITVARDECL( 0ll, SYM$1, (char*)*(char**)((uint8*)&CTX$ + 5280ll) );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"", 1ll, 0 );
	label$1142:;
}

static void HVARINISEPARATOR( void )
{
	label$1143:;
	if( *(int64*)((uint8*)&CTX$ + 5304ll) <= 0ll) goto label$1146;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)", ", 3ll, 0 );
	}
	label$1146:;
	label$1145:;
	label$1144:;
}

static void _EMITVARINII( struct $8FBSYMBOL* SYM$1, int64 VALUE$1 )
{
	label$1147:;
	int64 DTYPE$1;
	DTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	if( ((int64)-(DTYPE$1 == 1ll) & (int64)-(VALUE$1 != 0ll)) == 0ll) goto label$1150;
	{
		VALUE$1 = 1ll;
	}
	label$1150:;
	label$1149:;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* vr$5 = EXPRNEWIMMI( VALUE$1, DTYPE$1 );
	L$1 = vr$5;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) == 0ll) goto label$1152;
	{
		DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll);
	}
	label$1152:;
	label$1151:;
	struct $8EXPRNODE* vr$18 = EXPRNEWCAST( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), L$1 );
	L$1 = vr$18;
	FBSTRING* vr$19 = EXPRFLUSH( L$1, 0ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)vr$19, -1ll, 0 );
	HVARINISEPARATOR(  );
	label$1148:;
}

static void _EMITVARINIF( struct $8FBSYMBOL* SYM$1, double VALUE$1 )
{
	label$1153:;
	int64 DTYPE$1;
	DTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* vr$2 = EXPRNEWIMMF( VALUE$1, DTYPE$1 );
	L$1 = vr$2;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) == 0ll) goto label$1156;
	{
		DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll);
	}
	label$1156:;
	label$1155:;
	struct $8EXPRNODE* vr$15 = EXPRNEWCAST( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), L$1 );
	L$1 = vr$15;
	FBSTRING* vr$16 = EXPRFLUSH( L$1, 0ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)vr$16, -1ll, 0 );
	HVARINISEPARATOR(  );
	label$1154:;
}

static void _EMITVARINIOFS( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* RHS$1, int64 OFS$1 )
{
	label$1157:;
	struct $8EXPRNODE* L$1;
	struct $8EXPRNODE* vr$0 = EXPRNEWOFFSET( RHS$1, OFS$1 );
	L$1 = vr$0;
	int64 DTYPE$1;
	DTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) == 0ll) goto label$1160;
	{
		DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll);
	}
	label$1160:;
	label$1159:;
	struct $8EXPRNODE* vr$15 = EXPRNEWCAST( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), L$1 );
	L$1 = vr$15;
	FBSTRING* vr$16 = EXPRFLUSH( L$1, 0ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)vr$16, -1ll, 0 );
	HVARINISEPARATOR(  );
	label$1158:;
}

static void _EMITVARINISTR( int64 VARLENGTH$1, char* LITERAL$1, int64 LITLENGTH$1, int64 NOTERM$1 )
{
	label$1161:;
	if( LITLENGTH$1 <= VARLENGTH$1) goto label$1164;
	{
		LITLENGTH$1 = VARLENGTH$1;
	}
	label$1164:;
	label$1163:;
	if( NOTERM$1 == 0ll) goto label$1166;
	{
		int64 TMP$652$2;
		TMP$652$2 = 0ll;
		char* vr$3 = HUNESCAPE( LITERAL$1, &TMP$652$2 );
		HBUILDSTRLIT( (FBSTRING*)((uint8*)&CTX$ + 5280ll), vr$3, LITLENGTH$1 + 1ll, VARLENGTH$1 + 1ll );
	}
	goto label$1165;
	label$1166:;
	{
		int64 TMP$653$2;
		TMP$653$2 = 0ll;
		char* vr$7 = HUNESCAPE( LITERAL$1, &TMP$653$2 );
		HBUILDSTRLIT( (FBSTRING*)((uint8*)&CTX$ + 5280ll), vr$7, LITLENGTH$1 + 1ll, 0ll );
	}
	label$1165:;
	HVARINISEPARATOR(  );
	label$1162:;
}

static void _EMITVARINIWSTR( int64 VARLENGTH$1, uint32* LITERAL$1, int64 LITLENGTH$1 )
{
	int64 TMP$655$1;
	label$1167:;
	uint64 CH$1;
	int64 WCHARSIZE$1;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"{ ", 3ll, 0 );
	TMP$655$1 = 0ll;
	uint32* vr$2 = HUNESCAPEW( LITERAL$1, &TMP$655$1 );
	LITERAL$1 = vr$2;
	WCHARSIZE$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 400ll);
	if( LITLENGTH$1 <= VARLENGTH$1) goto label$1170;
	{
		LITLENGTH$1 = VARLENGTH$1;
	}
	label$1170:;
	label$1169:;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$656$2;
		TMP$656$2 = LITLENGTH$1 + -1ll;
		goto label$1171;
		label$1174:;
		{
			if( I$2 <= 0ll) goto label$1176;
			{
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)", ", 3ll, 0 );
			}
			label$1176:;
			label$1175:;
			if( WCHARSIZE$1 != 1ll) goto label$1178;
			{
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"'", 2ll, 0 );
			}
			goto label$1177;
			label$1178:;
			{
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"L'", 3ll, 0 );
			}
			label$1177:;
			CH$1 = (uint64)*(uint32*)((uint8*)LITERAL$1 + (I$2 << (2ll & 63ll)));
			int64 vr$10 = HCHARNEEDSESCAPING( (int64)CH$1, 39ll );
			if( vr$10 == 0ll) goto label$1180;
			{
				fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"\x5Cx", 3ll, 0 );
				FBSTRING* vr$14 = fb_HEXEx_l( CH$1, (int32)(WCHARSIZE$1 << (1ll & 63ll)) );
				fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)vr$14, -1ll, 0 );
			}
			goto label$1179;
			label$1180:;
			{
				FBSTRING* vr$16 = fb_CHR( 1, (int64)CH$1 );
				fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)vr$16, -1ll, 0 );
			}
			label$1179:;
			fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"'", 2ll, 0 );
		}
		label$1172:;
		I$2 = I$2 + 1ll;
		label$1171:;
		if( I$2 <= TMP$656$2) goto label$1174;
		label$1173:;
	}
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)" }", 3ll, 0 );
	HVARINISEPARATOR(  );
	label$1168:;
}

static void _EMITVARINIPAD( int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$1181:;
	label$1182:;
}

static void _EMITVARINISCOPEBEGIN( struct $8FBSYMBOL* SYM$1, int64 IS_ARRAY$1 )
{
	label$1183:;
	*(int64*)((uint8*)&CTX$ + 5304ll) = *(int64*)((uint8*)&CTX$ + 5304ll) + 1ll;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)"{ ", 3ll, 0 );
	label$1184:;
}

static void _EMITVARINISCOPEEND( void )
{
	label$1185:;
	FBSTRING* vr$1 = fb_RIGHT( (FBSTRING*)((uint8*)&CTX$ + 5280ll), 2ll );
	int32 vr$2 = fb_StrCompare( (void*)vr$1, -1ll, (void*)", ", 3ll );
	if( (int64)vr$2 != 0ll) goto label$1188;
	{
		int64 vr$5 = fb_StrLen( (void*)((uint8*)&CTX$ + 5280ll), -1ll );
		fb_LEFTSELF( (FBSTRING*)((uint8*)&CTX$ + 5280ll), vr$5 + -2ll );
	}
	label$1188:;
	label$1187:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5280ll), -1ll, (void*)" }", 3ll, 0 );
	*(int64*)((uint8*)&CTX$ + 5304ll) = *(int64*)((uint8*)&CTX$ + 5304ll) + -1ll;
	HVARINISEPARATOR(  );
	label$1186:;
}

static void _EMITFBCTINFBEGIN( void )
{
	FBSTRING TMP$659$1;
	label$1189:;
	__builtin_memset( &TMP$659$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$659$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$659$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$659$1 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)"static const char ", 19ll, 0 );
	int64 vr$5 = FBGETOPTION( 3ll );
	if( vr$5 != 10ll) goto label$1192;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)"__attribute__((used, section(\x22__DATA,fbctinf\x22))) ", 50ll, 0 );
	}
	goto label$1191;
	label$1192:;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)"__attribute__((used, section(\x22.fbctinf\x22))) ", 44ll, 0 );
	}
	label$1191:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)"__fbctinf[] = \x22", 16ll, 0 );
	label$1190:;
}

static void _EMITFBCTINFSTRING( char* S$1 )
{
	FBSTRING TMP$670$1;
	FBSTRING TMP$671$1;
	label$1193:;
	__builtin_memset( &TMP$670$1, 0, 24ll );
	FBSTRING* vr$2 = fb_StrConcat( &TMP$670$1, (void*)S$1, 0ll, (void*)"\x5C" "0", 3ll );
	__builtin_memset( &TMP$671$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$671$1, (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)vr$2, -1ll );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)vr$6, -1ll, 0 );
	label$1194:;
}

static void _EMITFBCTINFEND( void )
{
	label$1195:;
	FBSTRING* vr$1 = fb_RIGHT( (FBSTRING*)((uint8*)&CTX$ + 5312ll), 2ll );
	int32 vr$2 = fb_StrCompare( (void*)vr$1, -1ll, (void*)"\x5C" "0", 3ll );
	if( (int64)vr$2 != 0ll) goto label$1198;
	{
		int64 vr$5 = fb_StrLen( (void*)((uint8*)&CTX$ + 5312ll), -1ll );
		FBSTRING* vr$8 = fb_LEFT( (FBSTRING*)((uint8*)&CTX$ + 5312ll), vr$5 + -2ll );
		fb_StrAssign( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)vr$8, -1ll, 0 );
	}
	label$1198:;
	label$1197:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 5312ll), -1ll, (void*)"\x22;", 3ll, 0 );
	HWRITELINE( (FBSTRING*)((uint8*)&CTX$ + 5312ll), -1ll );
	label$1196:;
}

static void _EMITPROCBEGIN( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1 )
{
	FBSTRING TMP$673$1;
	FBSTRING TMP$687$1;
	FBSTRING TMP$688$1;
	label$1199:;
	HUPDATECURRENTFILENAME( *(char**)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 48ll) );
	IRHLEMITPROCBEGIN(  );
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	__builtin_memset( &TMP$673$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$673$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$673$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$673$1 );
	if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$1202;
	{
		_EMITDBG( 114ll, PROC$1, *(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 32ll), (char*)0ull );
	}
	label$1202:;
	label$1201:;
	if( (*(int64*)((uint8*)PROC$1 + 16ll) & 128ll) == 0ll) goto label$1204;
	{
		FBSTRING TMP$674$2;
		FBSTRING TMP$677$2;
		FBSTRING TMP$678$2;
		FBSTRING TMP$679$2;
		FBSTRING TMP$682$2;
		FBSTRING TMP$683$2;
		FBSTRING TMP$684$2;
		FBSTRING* vr$11 = HGETMANGLEDNAMEFORASM( PROC$1, -1ll );
		fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$11, -1ll, 0 );
		__builtin_memset( &TMP$674$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$674$2, -1ll, (void*)"__asm__( \x22.text\x22 );", 20ll, 0 );
		HWRITELINE( &TMP$674$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$674$2 );
		__builtin_memset( &TMP$679$2, 0, 24ll );
		__builtin_memset( &TMP$677$2, 0, 24ll );
		FBSTRING* vr$21 = fb_StrConcat( &TMP$677$2, (void*)"__asm__( \x22.globl ", 18ll, (void*)&MANGLED$1, -1ll );
		__builtin_memset( &TMP$678$2, 0, 24ll );
		FBSTRING* vr$24 = fb_StrConcat( &TMP$678$2, (void*)vr$21, -1ll, (void*)"\x22 );", 5ll );
		fb_StrAssign( (void*)&TMP$679$2, -1ll, (void*)vr$24, -1ll, 0 );
		HWRITELINE( &TMP$679$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$679$2 );
		__builtin_memset( &TMP$684$2, 0, 24ll );
		__builtin_memset( &TMP$682$2, 0, 24ll );
		FBSTRING* vr$32 = fb_StrConcat( &TMP$682$2, (void*)"__asm__( \x22", 11ll, (void*)&MANGLED$1, -1ll );
		__builtin_memset( &TMP$683$2, 0, 24ll );
		FBSTRING* vr$35 = fb_StrConcat( &TMP$683$2, (void*)vr$32, -1ll, (void*)":\x22 );", 6ll );
		fb_StrAssign( (void*)&TMP$684$2, -1ll, (void*)vr$35, -1ll, 0 );
		HWRITELINE( &TMP$684$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$684$2 );
		fb_StrDelete( (FBSTRING*)&MANGLED$1 );
		goto label$1200;
	}
	label$1204:;
	label$1203:;
	SECTIONBEGIN(  );
	int64 vr$40 = HNEEDALIAS( PROC$1 );
	if( vr$40 == 0ll) goto label$1206;
	{
		FBSTRING TMP$685$2;
		FBSTRING TMP$686$2;
		__builtin_memset( &TMP$686$2, 0, 24ll );
		FBSTRING* vr$42 = HEMITPROCHEADER( PROC$1, 1ll );
		__builtin_memset( &TMP$685$2, 0, 24ll );
		FBSTRING* vr$45 = fb_StrConcat( &TMP$685$2, (void*)vr$42, -1ll, (void*)";", 2ll );
		fb_StrAssign( (void*)&TMP$686$2, -1ll, (void*)vr$45, -1ll, 0 );
		HWRITELINE( &TMP$686$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$686$2 );
	}
	label$1206:;
	label$1205:;
	__builtin_memset( &TMP$687$1, 0, 24ll );
	FBSTRING* vr$50 = HEMITPROCHEADER( PROC$1, 0ll );
	fb_StrAssign( (void*)&TMP$687$1, -1ll, (void*)vr$50, -1ll, 0 );
	HWRITELINE( &TMP$687$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$687$1 );
	__builtin_memset( &TMP$688$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$688$1, -1ll, (void*)"{", 2ll, 0 );
	HWRITELINE( &TMP$688$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$688$1 );
	SECTIONINDENT(  );
	if( ((int64)-(*(int64*)((uint8*)&ENV$ + 208ll) == 2ll) & (int64)-(*(int64*)((uint8*)&ENV$ + 312ll) == -1ll)) == 0ll) goto label$1208;
	{
		FBSTRING TMP$690$2;
		__builtin_memset( &TMP$690$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$690$2, -1ll, (void*)"_unusedlabel: ; void *_llvmbug18658 = &&_unusedlabel;", 54ll, 0 );
		HWRITELINE( &TMP$690$2, 0ll );
		fb_StrDelete( (FBSTRING*)&TMP$690$2 );
	}
	label$1208:;
	label$1207:;
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	label$1200:;
}

static void _EMITPROCEND( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1, struct $8FBSYMBOL* EXITLABEL$1 )
{
	FBSTRING TMP$698$1;
	label$1209:;
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	struct $13EXPRCACHENODE* CACHENODE$1;
	if( (*(int64*)((uint8*)PROC$1 + 16ll) & 128ll) == 0ll) goto label$1212;
	{
		if( *(int64*)((uint8*)&ENV$ + 216ll) != 2ll) goto label$1214;
		{
			FBSTRING TMP$693$3;
			FBSTRING TMP$694$3;
			FBSTRING TMP$695$3;
			FBSTRING TMP$696$3;
			FBSTRING TMP$697$3;
			FBSTRING* vr$3 = HGETMANGLEDNAMEFORASM( PROC$1, -1ll );
			fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$3, -1ll, 0 );
			__builtin_memset( &TMP$697$3, 0, 24ll );
			__builtin_memset( &TMP$693$3, 0, 24ll );
			FBSTRING* vr$10 = fb_StrConcat( &TMP$693$3, (void*)"__asm__( \x22.size ", 17ll, (void*)&MANGLED$1, -1ll );
			__builtin_memset( &TMP$694$3, 0, 24ll );
			FBSTRING* vr$13 = fb_StrConcat( &TMP$694$3, (void*)vr$10, -1ll, (void*)", .-", 5ll );
			__builtin_memset( &TMP$695$3, 0, 24ll );
			FBSTRING* vr$16 = fb_StrConcat( &TMP$695$3, (void*)vr$13, -1ll, (void*)&MANGLED$1, -1ll );
			__builtin_memset( &TMP$696$3, 0, 24ll );
			FBSTRING* vr$19 = fb_StrConcat( &TMP$696$3, (void*)vr$16, -1ll, (void*)"\x22 );", 5ll );
			fb_StrAssign( (void*)&TMP$697$3, -1ll, (void*)vr$19, -1ll, 0 );
			HWRITELINE( &TMP$697$3, -1ll );
			fb_StrDelete( (FBSTRING*)&TMP$697$3 );
		}
		label$1214:;
		label$1213:;
		fb_StrDelete( (FBSTRING*)&MANGLED$1 );
		goto label$1210;
	}
	label$1212:;
	label$1211:;
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$698$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$698$1, -1ll, (void*)"}", 2ll, 0 );
	HWRITELINE( &TMP$698$1, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$698$1 );
	SECTIONEND(  );
	label$1215:;
	{
		void* vr$29 = LISTGETHEAD( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll) );
		CACHENODE$1 = (struct $13EXPRCACHENODE*)vr$29;
		if( CACHENODE$1 != (struct $13EXPRCACHENODE*)0ull) goto label$1219;
		{
			goto label$1216;
		}
		label$1219:;
		label$1218:;
		EXPRFREETREE( *(struct $8EXPRNODE**)((uint8*)CACHENODE$1 + 8ll) );
		LISTDELNODE( (struct $5TLIST*)((uint8*)&CTX$ + 5448ll), (void*)CACHENODE$1 );
	}
	label$1217:;
	goto label$1215;
	label$1216:;
	IRHLEMITPROCEND(  );
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	label$1210:;
}

static void _EMITSCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	FBSTRING TMP$699$1;
	label$1220:;
	SECTIONBEGIN(  );
	__builtin_memset( &TMP$699$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$699$1, -1ll, (void*)"{", 2ll, 0 );
	HWRITELINE( &TMP$699$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$699$1 );
	SECTIONINDENT(  );
	label$1221:;
}

static void _EMITSCOPEEND( struct $8FBSYMBOL* S$1 )
{
	FBSTRING TMP$700$1;
	label$1222:;
	SECTIONUNINDENT(  );
	__builtin_memset( &TMP$700$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$700$1, -1ll, (void*)"}", 2ll, 0 );
	HWRITELINE( &TMP$700$1, -1ll );
	fb_StrDelete( (FBSTRING*)&TMP$700$1 );
	SECTIONEND(  );
	label$1223:;
}

__attribute__(( constructor )) static void _GLOBAL__I( void )
{
	label$1225:;
	_ZN8IRHLCCTXC1Ev( &CTX$ );
	label$1226:;
}

__attribute__(( destructor )) static void _GLOBAL__D( void )
{
	label$1228:;
	_ZN8IRHLCCTXD1Ev( &CTX$ );
	label$1229:;
}
