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
struct $8DWSTRING {
	uint16* DATA;
	int64 LEN;
	int64 SIZE;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
__FB_STATIC_ASSERT( sizeof( struct $8DWSTRING ) == 24 );
typedef int64 $13FB_WARNINGMSG;
struct $8DZSTRING {
	char* DATA;
	int64 LEN;
	int64 SIZE;
};
__FB_STATIC_ASSERT( sizeof( struct $8DZSTRING ) == 24 );
typedef int64 $12FB_DATACLASS;
typedef int64 $11FB_DATATYPE;
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
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $7FBARRAYI8FBSTRINGE {
	FBSTRING* DATA;
	FBSTRING* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYI8FBSTRINGE ) == 240 );
struct $8FBARRAY1Iu7INTEGERE {
	int64* DATA;
	int64* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1Iu7INTEGERE ) == 72 );
struct $7FBARRAYIvE {
	void* DATA;
	void* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYIvE ) == 240 );
struct $7FBARRAYI8DWSTRINGE {
	struct $8DWSTRING* DATA;
	struct $8DWSTRING* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYI8DWSTRINGE ) == 240 );
struct $8HASHITEM;
struct $8HASHITEM {
	char* NAME;
	void* DATA;
	struct $8HASHITEM* PREV;
	struct $8HASHITEM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8HASHITEM ) == 32 );
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
int32 fb_ArrayRedimEx( struct $7FBARRAYIvE*, uint64, int32, int32, uint64, ... );
int32 fb_ArrayRedimPresvEx( struct $7FBARRAYIvE*, uint64, int32, int32, uint64, ... );
int32 fb_ArrayErase( struct $7FBARRAYIvE* );
void* fb_ErrorThrowAt( int32, char*, void*, void* );
void free( void* );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
uint16* fb_WstrAssign( uint16*, int64, uint16* );
uint16* fb_WstrAssignFromA( uint16*, int64, void*, int64 );
FBSTRING* fb_WstrAssignToA( void*, int64, uint16*, int32 );
void fb_StrDelete( FBSTRING* );
void fb_WstrDelete( uint16* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAllocTempResult( FBSTRING* );
FBSTRING* fb_StrAllocTempDescZ( char* );
FBSTRING* fb_StrMid( FBSTRING*, int64, int64 );
uint16* fb_WstrMid( uint16*, int64, int64 );
int64 fb_StrLen( void*, int64 );
int64 fb_WstrLen( uint16* );
FBSTRING* fb_CHR( int32, ... );
uint16* fb_WstrChr( int32, ... );
int64 fb_StrInstr( int64, FBSTRING*, FBSTRING* );
int64 fb_WstrInstr( int64, uint16*, uint16* );
FBSTRING* fb_OCT_l( uint64 );
uint16* fb_WstrOct_l( uint64 );
FBSTRING* fb_LEFT( FBSTRING*, int64 );
uint16* fb_WstrLeft( uint16*, int64 );
static void fb_ctor__hlpzstr( void ) __attribute__(( constructor ));
void* XALLOCATE( int32 );
void* XREALLOCATE( void*, int32 );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTWARN( int64, char*, $12FB_ERRMSGOPT, char* );
void DZSTRALLOCATE( struct $8DZSTRING*, int64 );
void DWSTRALLOCATE( struct $8DWSTRING*, int64 );
void DWSTRASSIGN( struct $8DWSTRING*, uint16* );
void DWSTRCONCATASSIGN( struct $8DWSTRING*, uint16* );
static int64 HREMAPCHAR( int64 );
static int64 HHEXCHAR( int64 );
static uint64 HUNICODEHEXTOCODEPOINTW( uint16**, int64 );
static void HUNICODECODEPOINTCHARTOHEX( uint64*, char**, int64 );
typedef int64 $13AST_NODECLASS;
typedef int64 $11AST_OPFLAGS;
typedef int64 $6AST_OP;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
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
static struct $8FBARRAY1I10AST_OPINFOE tmp$83$;
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
static struct $8FBARRAY1I13SYMB_DATATYPEE tmp$84$;
struct $8FBARRAY2Iu7INTEGERE {
	int64* DATA;
	int64* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[2];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY2Iu7INTEGERE ) == 96 );
static struct $8FBARRAY2Iu7INTEGERE tmp$85$;
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
typedef int64 $10FB_OUTTYPE;
typedef int64 $10FB_BACKEND;
typedef int64 $13FB_COMPTARGET;
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
typedef int64 $11FB_FUNCMODE;
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
struct $8FBSYMBOL;
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
		uint16* LITTEXTW;
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
typedef int64 $21FB_PROC_RETURN_METHOD;
typedef int64 (*tmp$35)( struct $8FBSYMBOL* );
struct $10FB_PROCRTL {
	tmp$35 CALLBACK;
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
		uint16* TEXTW;
		int64 PARAMNUM;
	};
	struct $9FB_DEFTOK* PREV;
	struct $9FB_DEFTOK* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $9FB_DEFTOK ) == 32 );
typedef int64 $15FB_DEFINE_FLAGS;
typedef FBSTRING* (*tmp$29)( void );
typedef FBSTRING* (*tmp$30)( void*, int64* );
typedef uint16* (*tmp$31)( void*, int64* );
struct $10FBS_DEFINE {
	int64 PARAMS;
	struct $11FB_DEFPARAM* PARAMHEAD;
	union {
		struct $9FB_DEFTOK* TOKHEAD;
		char* TEXT;
		uint16* TEXTW;
	};
	int64 ISARGLESS;
	$15FB_DEFINE_FLAGS FLAGS;
	union {
		tmp$29 DPROCZ;
		tmp$30 MPROCZ;
	};
	union {
		tmp$31 MPROCW;
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

void ZSTRASSIGN( char** DST$1, char* SRC$1 )
{
	label$10:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (char*)0ull) goto label$13;
	{
		SRC_LEN$1 = 0ll;
	}
	goto label$12;
	label$13:;
	{
		int64 vr$2 = fb_StrLen( (void*)SRC$1, 0ll );
		SRC_LEN$1 = vr$2;
	}
	label$12:;
	if( SRC_LEN$1 != 0ll) goto label$15;
	{
		if( *DST$1 == (char*)0ull) goto label$17;
		{
			free( *(void**)DST$1 );
			*DST$1 = (char*)0ull;
			goto label$11;
		}
		label$17:;
		label$16:;
	}
	label$15:;
	label$14:;
	if( *DST$1 != (char*)0ull) goto label$19;
	{
		DST_LEN$1 = 0ll;
	}
	goto label$18;
	label$19:;
	{
		int64 vr$8 = fb_StrLen( *(void**)DST$1, 0ll );
		DST_LEN$1 = vr$8;
	}
	label$18:;
	if( DST_LEN$1 == SRC_LEN$1) goto label$21;
	{
		void* vr$11 = XALLOCATE( (int32)(SRC_LEN$1 + 1ll) );
		*DST$1 = (char*)vr$11;
	}
	label$21:;
	label$20:;
	if( *DST$1 == (char*)0ull) goto label$23;
	{
		fb_StrAssign( *(void**)DST$1, 0ll, (void*)SRC$1, 0ll, 0 );
	}
	label$23:;
	label$22:;
	label$11:;
}

void ZSTRASSIGNW( char** DST$1, uint16* SRC$1 )
{
	label$24:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (uint16*)0ull) goto label$27;
	{
		SRC_LEN$1 = 0ll;
	}
	goto label$26;
	label$27:;
	{
		int64 vr$2 = fb_WstrLen( (uint16*)SRC$1 );
		SRC_LEN$1 = vr$2;
	}
	label$26:;
	if( SRC_LEN$1 != 0ll) goto label$29;
	{
		if( *DST$1 == (char*)0ull) goto label$31;
		{
			free( *(void**)DST$1 );
			*DST$1 = (char*)0ull;
			goto label$25;
		}
		label$31:;
		label$30:;
	}
	label$29:;
	label$28:;
	if( *DST$1 != (char*)0ull) goto label$33;
	{
		DST_LEN$1 = 0ll;
	}
	goto label$32;
	label$33:;
	{
		int64 vr$8 = fb_StrLen( *(void**)DST$1, 0ll );
		DST_LEN$1 = vr$8;
	}
	label$32:;
	if( DST_LEN$1 == SRC_LEN$1) goto label$35;
	{
		void* vr$11 = XALLOCATE( (int32)(SRC_LEN$1 + 1ll) );
		*DST$1 = (char*)vr$11;
	}
	label$35:;
	label$34:;
	if( *DST$1 == (char*)0ull) goto label$37;
	{
		fb_WstrAssignToA( *(void**)DST$1, 0ll, (uint16*)SRC$1, 0 );
	}
	label$37:;
	label$36:;
	label$25:;
}

void ZSTRCONCATASSIGN( char** DST$1, char* SRC$1 )
{
	label$38:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (char*)0ull) goto label$41;
	{
		goto label$39;
	}
	label$41:;
	label$40:;
	int64 vr$2 = fb_StrLen( (void*)SRC$1, 0ll );
	SRC_LEN$1 = vr$2;
	if( SRC_LEN$1 != 0ll) goto label$43;
	{
		goto label$39;
	}
	label$43:;
	label$42:;
	if( *DST$1 != (char*)0ull) goto label$45;
	{
		DST_LEN$1 = 0ll;
		void* vr$6 = XALLOCATE( (int32)(SRC_LEN$1 + 1ll) );
		*DST$1 = (char*)vr$6;
	}
	goto label$44;
	label$45:;
	{
		int64 vr$9 = fb_StrLen( *(void**)DST$1, 0ll );
		DST_LEN$1 = vr$9;
		void* vr$14 = XREALLOCATE( *(void**)DST$1, (int32)((DST_LEN$1 + SRC_LEN$1) + 1ll) );
		*DST$1 = (char*)vr$14;
	}
	label$44:;
	if( *DST$1 == (char*)0ull) goto label$47;
	{
		fb_StrAssign( (void*)((uint8*)*DST$1 + DST_LEN$1), 0ll, (void*)SRC$1, 0ll, 0 );
	}
	label$47:;
	label$46:;
	label$39:;
}

void ZSTRCONCATASSIGNW( char** DST$1, uint16* SRC$1 )
{
	label$48:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (uint16*)0ull) goto label$51;
	{
		goto label$49;
	}
	label$51:;
	label$50:;
	int64 vr$2 = fb_WstrLen( (uint16*)SRC$1 );
	SRC_LEN$1 = vr$2;
	if( SRC_LEN$1 != 0ll) goto label$53;
	{
		goto label$49;
	}
	label$53:;
	label$52:;
	if( *DST$1 != (char*)0ull) goto label$55;
	{
		DST_LEN$1 = 0ll;
		void* vr$6 = XALLOCATE( (int32)(SRC_LEN$1 + 1ll) );
		*DST$1 = (char*)vr$6;
	}
	goto label$54;
	label$55:;
	{
		int64 vr$9 = fb_StrLen( *(void**)DST$1, 0ll );
		DST_LEN$1 = vr$9;
		void* vr$14 = XREALLOCATE( *(void**)DST$1, (int32)((DST_LEN$1 + SRC_LEN$1) + 1ll) );
		*DST$1 = (char*)vr$14;
	}
	label$54:;
	if( *DST$1 == (char*)0ull) goto label$57;
	{
		fb_WstrAssignToA( (void*)((uint8*)*DST$1 + DST_LEN$1), 0ll, (uint16*)SRC$1, 0 );
	}
	label$57:;
	label$56:;
	label$49:;
}

void WSTRASSIGN( uint16** DST$1, uint16* SRC$1 )
{
	label$58:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (uint16*)0ull) goto label$61;
	{
		SRC_LEN$1 = 0ll;
	}
	goto label$60;
	label$61:;
	{
		int64 vr$2 = fb_WstrLen( (uint16*)SRC$1 );
		SRC_LEN$1 = vr$2;
	}
	label$60:;
	if( SRC_LEN$1 != 0ll) goto label$63;
	{
		if( *DST$1 == (uint16*)0ull) goto label$65;
		{
			free( *(void**)DST$1 );
			*DST$1 = (uint16*)0ull;
			goto label$59;
		}
		label$65:;
		label$64:;
	}
	label$63:;
	label$62:;
	if( *DST$1 != (uint16*)0ull) goto label$67;
	{
		DST_LEN$1 = 0ll;
	}
	goto label$66;
	label$67:;
	{
		int64 vr$8 = fb_WstrLen( (uint16*)*DST$1 );
		DST_LEN$1 = vr$8;
	}
	label$66:;
	if( DST_LEN$1 == SRC_LEN$1) goto label$69;
	{
		void* vr$12 = XALLOCATE( (int32)((SRC_LEN$1 << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$12;
	}
	label$69:;
	label$68:;
	if( *DST$1 == (uint16*)0ull) goto label$71;
	{
		fb_WstrAssign( *DST$1, 0ll, (uint16*)SRC$1 );
	}
	label$71:;
	label$70:;
	label$59:;
}

void WSTRASSIGNA( uint16** DST$1, char* SRC$1 )
{
	label$72:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (char*)0ull) goto label$75;
	{
		SRC_LEN$1 = 0ll;
	}
	goto label$74;
	label$75:;
	{
		int64 vr$2 = fb_StrLen( (void*)SRC$1, 0ll );
		SRC_LEN$1 = vr$2;
	}
	label$74:;
	if( SRC_LEN$1 != 0ll) goto label$77;
	{
		if( *DST$1 == (uint16*)0ull) goto label$79;
		{
			free( *(void**)DST$1 );
			*DST$1 = (uint16*)0ull;
			goto label$73;
		}
		label$79:;
		label$78:;
	}
	label$77:;
	label$76:;
	if( *DST$1 != (uint16*)0ull) goto label$81;
	{
		DST_LEN$1 = 0ll;
	}
	goto label$80;
	label$81:;
	{
		int64 vr$8 = fb_WstrLen( (uint16*)*DST$1 );
		DST_LEN$1 = vr$8;
	}
	label$80:;
	if( DST_LEN$1 == SRC_LEN$1) goto label$83;
	{
		void* vr$12 = XALLOCATE( (int32)((SRC_LEN$1 << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$12;
	}
	label$83:;
	label$82:;
	if( *DST$1 == (uint16*)0ull) goto label$85;
	{
		fb_WstrAssignFromA( *DST$1, 0ll, (void*)SRC$1, 0ll );
	}
	label$85:;
	label$84:;
	label$73:;
}

void WSTRCONCATASSIGN( uint16** DST$1, uint16* SRC$1 )
{
	label$86:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (uint16*)0ull) goto label$89;
	{
		goto label$87;
	}
	label$89:;
	label$88:;
	int64 vr$2 = fb_WstrLen( (uint16*)SRC$1 );
	SRC_LEN$1 = vr$2;
	if( SRC_LEN$1 != 0ll) goto label$91;
	{
		goto label$87;
	}
	label$91:;
	label$90:;
	if( *DST$1 != (uint16*)0ull) goto label$93;
	{
		DST_LEN$1 = 0ll;
		void* vr$7 = XALLOCATE( (int32)((SRC_LEN$1 << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$7;
	}
	goto label$92;
	label$93:;
	{
		int64 vr$10 = fb_WstrLen( (uint16*)*DST$1 );
		DST_LEN$1 = vr$10;
		void* vr$16 = XREALLOCATE( *(void**)DST$1, (int32)(((DST_LEN$1 + SRC_LEN$1) << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$16;
	}
	label$92:;
	if( *DST$1 == (uint16*)0ull) goto label$95;
	{
		fb_WstrAssign( (uint16*)((uint8*)*DST$1 + (DST_LEN$1 << (1ll & 63ll))), 0ll, (uint16*)SRC$1 );
	}
	label$95:;
	label$94:;
	label$87:;
}

void WSTRCONCATASSIGNW( uint16** DST$1, char* SRC$1 )
{
	label$96:;
	int64 DST_LEN$1;
	__builtin_memset( &DST_LEN$1, 0, 8ll );
	int64 SRC_LEN$1;
	__builtin_memset( &SRC_LEN$1, 0, 8ll );
	if( SRC$1 != (char*)0ull) goto label$99;
	{
		goto label$97;
	}
	label$99:;
	label$98:;
	int64 vr$2 = fb_StrLen( (void*)SRC$1, 0ll );
	SRC_LEN$1 = vr$2;
	if( SRC_LEN$1 != 0ll) goto label$101;
	{
		goto label$97;
	}
	label$101:;
	label$100:;
	if( *DST$1 != (uint16*)0ull) goto label$103;
	{
		DST_LEN$1 = 0ll;
		void* vr$7 = XALLOCATE( (int32)((SRC_LEN$1 << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$7;
	}
	goto label$102;
	label$103:;
	{
		int64 vr$10 = fb_WstrLen( (uint16*)*DST$1 );
		DST_LEN$1 = vr$10;
		void* vr$16 = XREALLOCATE( *(void**)DST$1, (int32)(((DST_LEN$1 + SRC_LEN$1) << (1ll & 63ll)) + 2ll) );
		*DST$1 = (uint16*)vr$16;
	}
	label$102:;
	if( *DST$1 == (uint16*)0ull) goto label$105;
	{
		fb_WstrAssignFromA( (uint16*)((uint8*)*DST$1 + (DST_LEN$1 << (1ll & 63ll))), 0ll, (void*)SRC$1, 0ll );
	}
	label$105:;
	label$104:;
	label$97:;
}

char* ZSTRDUP( char* S$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$106:;
	char* DST$1;
	__builtin_memset( &DST$1, 0, 8ll );
	int64 vr$2 = fb_StrLen( (void*)S$1, 0ll );
	void* vr$5 = XALLOCATE( (int32)(vr$2 + 1ll) );
	DST$1 = (char*)vr$5;
	fb_StrAssign( (void*)DST$1, 0ll, (void*)S$1, 0ll, 0 );
	fb$result$1 = DST$1;
	label$107:;
	return fb$result$1;
}

uint16* WSTRDUP( uint16* S$1 )
{
	uint16* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$108:;
	uint16* DST$1;
	__builtin_memset( &DST$1, 0, 8ll );
	int64 vr$2 = fb_WstrLen( (uint16*)S$1 );
	void* vr$6 = XALLOCATE( (int32)((vr$2 << (1ll & 63ll)) + 2ll) );
	DST$1 = (uint16*)vr$6;
	fb_WstrAssign( DST$1, 0ll, (uint16*)S$1 );
	fb$result$1 = DST$1;
	label$109:;
	return fb$result$1;
}

FBSTRING* HREPLACE( char* ORGTEXT$1, char* OLDTEXT$1, char* NEWTEXT$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$110:;
	static int64 OLDLEN$1;
	static int64 NEWLEN$1;
	static int64 P$1;
	static FBSTRING TEXT$1;
	static FBSTRING REMTEXT$1;
	int64 vr$1 = fb_StrLen( (void*)OLDTEXT$1, 0ll );
	OLDLEN$1 = vr$1;
	int64 vr$2 = fb_StrLen( (void*)NEWTEXT$1, 0ll );
	NEWLEN$1 = vr$2;
	fb_StrAssign( (void*)&TEXT$1, -1ll, (void*)ORGTEXT$1, 0ll, 0 );
	P$1 = 0ll;
	label$112:;
	{
		FBSTRING TMP$86$2;
		FBSTRING* vr$3 = fb_StrAllocTempDescZ( (char*)OLDTEXT$1 );
		int64 vr$5 = fb_StrInstr( P$1 + 1ll, (FBSTRING*)&TEXT$1, (FBSTRING*)vr$3 );
		P$1 = vr$5;
		if( P$1 != 0ll) goto label$116;
		{
			goto label$113;
		}
		label$116:;
		label$115:;
		FBSTRING* vr$7 = fb_StrMid( (FBSTRING*)&TEXT$1, P$1 + OLDLEN$1, -1ll );
		fb_StrAssign( (void*)&REMTEXT$1, -1ll, (void*)vr$7, -1ll, 0 );
		FBSTRING* vr$9 = fb_LEFT( (FBSTRING*)&TEXT$1, P$1 + -1ll );
		fb_StrAssign( (void*)&TEXT$1, -1ll, (void*)vr$9, -1ll, 0 );
		__builtin_memset( &TMP$86$2, 0, 24ll );
		FBSTRING* vr$12 = fb_StrConcat( &TMP$86$2, (void*)&TEXT$1, -1ll, (void*)NEWTEXT$1, 0ll );
		fb_StrAssign( (void*)&TEXT$1, -1ll, (void*)vr$12, -1ll, 0 );
		fb_StrConcatAssign( (void*)&TEXT$1, -1ll, (void*)&REMTEXT$1, -1ll, 0 );
		P$1 = (P$1 + NEWLEN$1) + -1ll;
	}
	label$114:;
	goto label$112;
	label$113:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&TEXT$1, -1ll, 0 );
	label$111:;
	FBSTRING* vr$17 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$17;
}

uint16* HREPLACEW( uint16* ORGTEXT$1, uint16* OLDTEXT$1, uint16* NEWTEXT$1 )
{
	uint16* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$117:;
	static int64 OLDLEN$1;
	static int64 NEWLEN$1;
	static int64 P$1;
	static struct $8DWSTRING TEXT$1;
	static struct $8DWSTRING REMTEXT$1;
	int64 vr$1 = fb_WstrLen( (uint16*)OLDTEXT$1 );
	OLDLEN$1 = vr$1;
	int64 vr$2 = fb_WstrLen( (uint16*)NEWTEXT$1 );
	NEWLEN$1 = vr$2;
	DWSTRASSIGN( &TEXT$1, (uint16*)ORGTEXT$1 );
	P$1 = 0ll;
	label$119:;
	{
		uint16* TMP$87$2;
		uint16* TMP$88$2;
		int64 vr$4 = fb_WstrInstr( P$1 + 1ll, (uint16*)*(uint16**)&TEXT$1, (uint16*)OLDTEXT$1 );
		P$1 = vr$4;
		if( P$1 != 0ll) goto label$123;
		{
			goto label$120;
		}
		label$123:;
		label$122:;
		uint16* vr$6 = fb_WstrMid( (uint16*)*(uint16**)&TEXT$1, P$1 + OLDLEN$1, -1ll );
		TMP$87$2 = vr$6;
		DWSTRASSIGN( &REMTEXT$1, (uint16*)TMP$87$2 );
		fb_WstrDelete( (uint16*)TMP$87$2 );
		uint16* vr$8 = fb_WstrLeft( *(uint16**)&TEXT$1, P$1 + -1ll );
		TMP$88$2 = vr$8;
		DWSTRASSIGN( &TEXT$1, (uint16*)TMP$88$2 );
		fb_WstrDelete( (uint16*)TMP$88$2 );
		DWSTRCONCATASSIGN( &TEXT$1, (uint16*)NEWTEXT$1 );
		DWSTRCONCATASSIGN( &TEXT$1, (uint16*)*(uint16**)&REMTEXT$1 );
		P$1 = (P$1 + NEWLEN$1) + -1ll;
	}
	label$121:;
	goto label$119;
	label$120:;
	fb$result$1 = *(uint16**)&TEXT$1;
	label$118:;
	return fb$result$1;
}

char* HREPLACECHAR( char* ORGTEXT$1, int64 OLDCHAR$1, int64 NEWCHAR$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$124:;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$89$2;
		int64 vr$1 = fb_StrLen( (void*)ORGTEXT$1, 0ll );
		TMP$89$2 = vr$1 + -1ll;
		goto label$126;
		label$129:;
		{
			if( (int64)(uint8)*(char*)((uint8*)ORGTEXT$1 + I$2) != OLDCHAR$1) goto label$131;
			{
				*(char*)((uint8*)ORGTEXT$1 + I$2) = (uint8)NEWCHAR$1;
			}
			label$131:;
			label$130:;
		}
		label$127:;
		I$2 = I$2 + 1ll;
		label$126:;
		if( I$2 <= TMP$89$2) goto label$129;
		label$128:;
	}
	fb$result$1 = ORGTEXT$1;
	label$125:;
	return fb$result$1;
}

int64 HHASESCAPE( char* TEXT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$167:;
	static uint64 CHAR$1;
	static int64 LGT$1;
	int64 vr$1 = fb_StrLen( (void*)TEXT$1, 0ll );
	LGT$1 = vr$1;
	label$169:;
	if( LGT$1 <= 0ll) goto label$170;
	{
		if( (int64)(uint8)*TEXT$1 != 92ll) goto label$172;
		{
			TEXT$1 = (char*)((uint8*)TEXT$1 + 1ll);
			CHAR$1 = (uint64)(uint8)*TEXT$1;
			{
				uint64 TMP$101$4;
				TMP$101$4 = CHAR$1;
				goto label$174;
				label$175:;
				{
					fb$result$1 = -1ll;
					goto label$168;
				}
				goto label$173;
				label$174:;
				static const void* tmp$102[85ll] = {
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$173,
					&&label$173,
					&&label$175,
					&&label$173,
					&&label$175,
					&&label$175,
					&&label$175,
				};
				if( (TMP$101$4 - 34ull) > 84ull ) goto label$173;
				goto *tmp$102[TMP$101$4 - 34ull];
				label$173:;
			}
		}
		label$172:;
		label$171:;
		TEXT$1 = (char*)((uint8*)TEXT$1 + 1ll);
		LGT$1 = LGT$1 + -1ll;
	}
	goto label$169;
	label$170:;
	fb$result$1 = 0ll;
	label$168:;
	return fb$result$1;
}

int64 HHASESCAPEW( uint16* TEXT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$176:;
	static uint64 CHAR$1;
	static int64 LGT$1;
	int64 vr$1 = fb_WstrLen( (uint16*)TEXT$1 );
	LGT$1 = vr$1;
	label$178:;
	if( LGT$1 <= 0ll) goto label$179;
	{
		if( (int64)*TEXT$1 != 92ll) goto label$181;
		{
			TEXT$1 = (uint16*)((uint8*)TEXT$1 + 2ll);
			CHAR$1 = (uint64)*TEXT$1;
			{
				uint64 TMP$103$4;
				TMP$103$4 = CHAR$1;
				goto label$183;
				label$184:;
				{
					fb$result$1 = -1ll;
					goto label$177;
				}
				goto label$182;
				label$183:;
				static const void* tmp$104[85ll] = {
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$182,
					&&label$182,
					&&label$184,
					&&label$182,
					&&label$184,
					&&label$184,
					&&label$184,
				};
				if( (TMP$103$4 - 34ull) > 84ull ) goto label$182;
				goto *tmp$104[TMP$103$4 - 34ull];
				label$182:;
			}
		}
		label$181:;
		label$180:;
		TEXT$1 = (uint16*)((uint8*)TEXT$1 + 2ll);
		LGT$1 = LGT$1 + -1ll;
	}
	goto label$178;
	label$179:;
	fb$result$1 = 0ll;
	label$177:;
	return fb$result$1;
}

char* HREESCAPE( char* TEXT$1, int64* TEXTLEN$1, int64* ISUNICODE$1, $13FB_WARNINGMSG* WRNMSG$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$185:;
	static struct $8DZSTRING RES$1;
	static int64 CHAR$1;
	static int64 LGT$1;
	static int64 I$1;
	static int64 VALUE$1;
	static int64 ISNUMBER$1;
	static char* SRC$1;
	static char* DST$1;
	static char* SRC_END$1;
	*ISUNICODE$1 = 0ll;
	*TEXTLEN$1 = 0ll;
	int64 vr$3 = fb_StrLen( (void*)TEXT$1, 0ll );
	LGT$1 = vr$3;
	if( LGT$1 != 0ll) goto label$188;
	{
		fb$result$1 = TEXT$1;
		goto label$186;
	}
	label$188:;
	label$187:;
	DZSTRALLOCATE( &RES$1, LGT$1 << (1ll & 63ll) );
	SRC$1 = TEXT$1;
	DST$1 = *(char**)&RES$1;
	SRC_END$1 = (char*)((uint8*)SRC$1 + LGT$1);
	label$189:;
	if( SRC$1 >= SRC_END$1) goto label$190;
	{
		CHAR$1 = (int64)(uint8)*SRC$1;
		SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
		if( CHAR$1 != 92ll) goto label$192;
		{
			if( SRC$1 < SRC_END$1) goto label$194;
			{
				goto label$190;
				label$194:;
			}
			*DST$1 = (uint8)27u;
			DST$1 = (char*)((uint8*)DST$1 + 1ll);
			ISNUMBER$1 = 0ll;
			CHAR$1 = (int64)(uint8)*SRC$1;
			SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
			{
				if( CHAR$1 < 48ll) goto label$196;
				if( CHAR$1 > 57ll) goto label$196;
				label$197:;
				{
					ISNUMBER$1 = -1ll;
					VALUE$1 = CHAR$1 + -48ll;
					{
						I$1 = 2ll;
						label$201:;
						{
							if( SRC$1 < SRC_END$1) goto label$203;
							{
								goto label$200;
								label$203:;
							}
							CHAR$1 = (int64)(uint8)*SRC$1;
							if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 57ll)) == 0ll) goto label$205;
							{
								goto label$200;
							}
							label$205:;
							label$204:;
							VALUE$1 = ((VALUE$1 * 10ll) + CHAR$1) + -48ll;
							SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
						}
						label$199:;
						I$1 = I$1 + 1ll;
						label$198:;
						if( I$1 <= 3ll) goto label$201;
						label$200:;
					}
				}
				goto label$195;
				label$196:;
				if( CHAR$1 == 38ll) goto label$207;
				label$208:;
				if( CHAR$1 == 88ll) goto label$207;
				label$209:;
				if( CHAR$1 != 120ll) goto label$206;
				label$207:;
				{
					if( SRC$1 < SRC_END$1) goto label$211;
					{
						goto label$190;
						label$211:;
					}
					VALUE$1 = 0ll;
					if( CHAR$1 != 38ll) goto label$213;
					{
						CHAR$1 = (int64)(uint8)*SRC$1;
						SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
					}
					goto label$212;
					label$213:;
					{
						CHAR$1 = 72ll;
					}
					label$212:;
					{
						uint64 TMP$105$6;
						TMP$105$6 = (uint64)CHAR$1;
						goto label$215;
						label$216:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$220:;
								{
									if( SRC$1 < SRC_END$1) goto label$222;
									{
										goto label$219;
										label$222:;
									}
									CHAR$1 = (int64)(uint8)*SRC$1;
									{
										if( CHAR$1 < 97ll) goto label$226;
										if( CHAR$1 <= 102ll) goto label$225;
										label$226:;
										if( CHAR$1 < 65ll) goto label$227;
										if( CHAR$1 <= 70ll) goto label$225;
										label$227:;
										if( CHAR$1 < 48ll) goto label$224;
										if( CHAR$1 > 57ll) goto label$224;
										label$225:;
										{
											CHAR$1 = CHAR$1 + -48ll;
											if( CHAR$1 <= 9ll) goto label$229;
											{
												CHAR$1 = CHAR$1 + -7ll;
											}
											label$229:;
											label$228:;
											if( CHAR$1 <= 16ll) goto label$231;
											{
												CHAR$1 = CHAR$1 + -32ll;
											}
											label$231:;
											label$230:;
											VALUE$1 = (VALUE$1 << (4ll & 63ll)) + CHAR$1;
										}
										goto label$223;
										label$224:;
										{
											goto label$219;
										}
										label$232:;
										label$223:;
									}
									SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
								}
								label$218:;
								I$1 = I$1 + 1ll;
								label$217:;
								if( I$1 <= 2ll) goto label$220;
								label$219:;
							}
						}
						goto label$214;
						label$233:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$237:;
								{
									if( SRC$1 < SRC_END$1) goto label$239;
									{
										goto label$236;
										label$239:;
									}
									CHAR$1 = (int64)(uint8)*SRC$1;
									if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 55ll)) == 0ll) goto label$241;
									{
										goto label$236;
									}
									label$241:;
									label$240:;
									VALUE$1 = ((VALUE$1 << (3ll & 63ll)) + CHAR$1) + -48ll;
									SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
								}
								label$235:;
								I$1 = I$1 + 1ll;
								label$234:;
								if( I$1 <= 3ll) goto label$237;
								label$236:;
							}
						}
						goto label$214;
						label$242:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$246:;
								{
									if( SRC$1 < SRC_END$1) goto label$248;
									{
										goto label$245;
										label$248:;
									}
									CHAR$1 = (int64)(uint8)*SRC$1;
									if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 49ll)) == 0ll) goto label$250;
									{
										goto label$245;
									}
									label$250:;
									label$249:;
									VALUE$1 = ((VALUE$1 << (1ll & 63ll)) + CHAR$1) + -48ll;
									SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
								}
								label$244:;
								I$1 = I$1 + 1ll;
								label$243:;
								if( I$1 <= 8ll) goto label$246;
								label$245:;
							}
						}
						goto label$214;
						label$215:;
						static const void* tmp$106[46ll] = {
							&&label$242,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$216,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$233,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$242,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$216,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$214,
							&&label$233,
						};
						if( (TMP$105$6 - 66ull) > 45ull ) goto label$214;
						goto *tmp$106[TMP$105$6 - 66ull];
						label$214:;
					}
				}
				goto label$195;
				label$206:;
				if( CHAR$1 != 97ll) goto label$251;
				label$252:;
				{
					ISNUMBER$1 = -1ll;
					VALUE$1 = 7ll;
				}
				goto label$195;
				label$251:;
				if( CHAR$1 != 117ll) goto label$253;
				label$254:;
				{
					*ISUNICODE$1 = -1ll;
					*DST$1 = (uint8)CHAR$1;
					DST$1 = (char*)((uint8*)DST$1 + 1ll);
					{
						I$1 = 1ll;
						label$258:;
						{
							if( SRC$1 < SRC_END$1) goto label$260;
							{
								*WRNMSG$1 = 52ll;
								goto label$257;
							}
							label$260:;
							label$259:;
							CHAR$1 = (int64)(uint8)*SRC$1;
							{
								if( CHAR$1 < 48ll) goto label$264;
								if( CHAR$1 <= 57ll) goto label$263;
								label$264:;
								if( CHAR$1 < 97ll) goto label$265;
								if( CHAR$1 <= 102ll) goto label$263;
								label$265:;
								if( CHAR$1 < 65ll) goto label$262;
								if( CHAR$1 > 70ll) goto label$262;
								label$263:;
								{
								}
								goto label$261;
								label$262:;
								{
									*WRNMSG$1 = 52ll;
									goto label$257;
								}
								label$266:;
								label$261:;
							}
							fb_StrAssign( (void*)DST$1, 0ll, (void*)SRC$1, 0ll, 0 );
							DST$1 = (char*)((uint8*)DST$1 + 1ll);
							SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
						}
						label$256:;
						I$1 = I$1 + 1ll;
						label$255:;
						if( I$1 <= 4ll) goto label$258;
						label$257:;
					}
					*TEXTLEN$1 = *TEXTLEN$1 + 2ll;
					goto label$189;
				}
				goto label$195;
				label$253:;
				if( CHAR$1 != 85ll) goto label$267;
				label$268:;
				{
					*ISUNICODE$1 = -1ll;
					{
						I$1 = 1ll;
						label$272:;
						{
							if( SRC$1 < SRC_END$1) goto label$274;
							{
								*WRNMSG$1 = 52ll;
								goto label$271;
							}
							label$274:;
							label$273:;
							CHAR$1 = (int64)(uint8)*SRC$1;
							{
								if( CHAR$1 < 48ll) goto label$276;
								if( CHAR$1 > 57ll) goto label$276;
								label$277:;
								{
									VALUE$1 = ((VALUE$1 << (4ll & 63ll)) + CHAR$1) + -48ll;
								}
								goto label$275;
								label$276:;
								if( CHAR$1 < 97ll) goto label$278;
								if( CHAR$1 > 102ll) goto label$278;
								label$279:;
								{
									VALUE$1 = ((VALUE$1 << (4ll & 63ll)) + CHAR$1) + -87ll;
								}
								goto label$275;
								label$278:;
								if( CHAR$1 < 65ll) goto label$280;
								if( CHAR$1 > 70ll) goto label$280;
								label$281:;
								{
									VALUE$1 = ((VALUE$1 << (4ll & 63ll)) + CHAR$1) + -55ll;
								}
								goto label$275;
								label$280:;
								{
									*WRNMSG$1 = 52ll;
									goto label$271;
								}
								label$282:;
								label$275:;
							}
							SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
						}
						label$270:;
						I$1 = I$1 + 1ll;
						label$269:;
						if( I$1 <= 8ll) goto label$272;
						label$271:;
					}
					if( VALUE$1 <= 65535ll) goto label$284;
					{
						*DST$1 = (uint8)85u;
						DST$1 = (char*)((uint8*)DST$1 + 1ll);
						int64 vr$90 = HHEXCHAR( VALUE$1 >> (28ll & 63ll) );
						*DST$1 = (uint8)vr$90;
						int64 vr$94 = HHEXCHAR( VALUE$1 >> (24ll & 63ll) );
						*(char*)((uint8*)DST$1 + 1ll) = (uint8)vr$94;
						int64 vr$98 = HHEXCHAR( VALUE$1 >> (20ll & 63ll) );
						*(char*)((uint8*)DST$1 + 2ll) = (uint8)vr$98;
						int64 vr$102 = HHEXCHAR( VALUE$1 >> (16ll & 63ll) );
						*(char*)((uint8*)DST$1 + 3ll) = (uint8)vr$102;
						int64 vr$106 = HHEXCHAR( VALUE$1 >> (12ll & 63ll) );
						*(char*)((uint8*)DST$1 + 4ll) = (uint8)vr$106;
						int64 vr$110 = HHEXCHAR( VALUE$1 >> (8ll & 63ll) );
						*(char*)((uint8*)DST$1 + 5ll) = (uint8)vr$110;
						int64 vr$114 = HHEXCHAR( VALUE$1 >> (4ll & 63ll) );
						*(char*)((uint8*)DST$1 + 6ll) = (uint8)vr$114;
						int64 vr$117 = HHEXCHAR( VALUE$1 );
						*(char*)((uint8*)DST$1 + 7ll) = (uint8)vr$117;
						DST$1 = (char*)((uint8*)DST$1 + 8ll);
						*TEXTLEN$1 = *TEXTLEN$1 + 4ll;
					}
					goto label$283;
					label$284:;
					{
						*DST$1 = (uint8)117u;
						DST$1 = (char*)((uint8*)DST$1 + 1ll);
						int64 vr$127 = HHEXCHAR( VALUE$1 >> (12ll & 63ll) );
						*DST$1 = (uint8)vr$127;
						int64 vr$131 = HHEXCHAR( VALUE$1 >> (8ll & 63ll) );
						*(char*)((uint8*)DST$1 + 1ll) = (uint8)vr$131;
						int64 vr$135 = HHEXCHAR( VALUE$1 >> (4ll & 63ll) );
						*(char*)((uint8*)DST$1 + 2ll) = (uint8)vr$135;
						int64 vr$138 = HHEXCHAR( VALUE$1 );
						*(char*)((uint8*)DST$1 + 3ll) = (uint8)vr$138;
						DST$1 = (char*)((uint8*)DST$1 + 4ll);
						*TEXTLEN$1 = *TEXTLEN$1 + 2ll;
					}
					label$283:;
					goto label$189;
				}
				label$267:;
				label$195:;
			}
			if( ISNUMBER$1 == 0ll) goto label$286;
			{
				if( (uint64)VALUE$1 <= 255ull) goto label$288;
				{
					ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
					VALUE$1 = 255ll;
				}
				label$288:;
				label$287:;
				if( VALUE$1 >= 8ll) goto label$290;
				{
					LGT$1 = 1ll;
				}
				goto label$289;
				label$290:;
				if( VALUE$1 >= 64ll) goto label$291;
				{
					LGT$1 = 2ll;
				}
				goto label$289;
				label$291:;
				{
					LGT$1 = 3ll;
				}
				label$289:;
				*DST$1 = (uint8)LGT$1;
				DST$1 = (char*)((uint8*)DST$1 + 1ll);
				FBSTRING* vr$148 = fb_OCT_l( (uint64)VALUE$1 );
				fb_StrAssign( (void*)DST$1, 0ll, (void*)vr$148, -1ll, 0 );
				DST$1 = (char*)((uint8*)DST$1 + LGT$1);
				*TEXTLEN$1 = *TEXTLEN$1 + 1ll;
				goto label$189;
			}
			label$286:;
			label$285:;
		}
		label$192:;
		label$191:;
		*DST$1 = (uint8)CHAR$1;
		DST$1 = (char*)((uint8*)DST$1 + 1ll);
		*TEXTLEN$1 = *TEXTLEN$1 + 1ll;
	}
	goto label$189;
	label$190:;
	*DST$1 = (uint8)0u;
	fb$result$1 = *(char**)&RES$1;
	label$186:;
	return fb$result$1;
}

uint16* HREESCAPEW( uint16* TEXT$1, int64* TEXTLEN$1, $13FB_WARNINGMSG* WRNMSG$1 )
{
	uint16* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$292:;
	static struct $8DWSTRING RES$1;
	static int64 CHAR$1;
	static int64 LGT$1;
	static int64 I$1;
	static int64 ISNUMBER$1;
	static uint64 VALUE$1;
	static uint16* SRC$1;
	static uint16* DST$1;
	static uint16* SRC_END$1;
	*TEXTLEN$1 = 0ll;
	int64 vr$2 = fb_WstrLen( (uint16*)TEXT$1 );
	LGT$1 = vr$2;
	if( LGT$1 != 0ll) goto label$295;
	{
		fb$result$1 = TEXT$1;
		goto label$293;
	}
	label$295:;
	label$294:;
	DWSTRALLOCATE( &RES$1, LGT$1 << (1ll & 63ll) );
	SRC$1 = TEXT$1;
	DST$1 = *(uint16**)&RES$1;
	SRC_END$1 = (uint16*)((uint8*)SRC$1 + (LGT$1 << (1ll & 63ll)));
	label$296:;
	if( SRC$1 >= SRC_END$1) goto label$297;
	{
		CHAR$1 = (int64)*SRC$1;
		SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
		if( CHAR$1 != 92ll) goto label$299;
		{
			if( SRC$1 < SRC_END$1) goto label$301;
			{
				goto label$297;
				label$301:;
			}
			*DST$1 = (uint16)(uint16)27u;
			DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
			ISNUMBER$1 = 0ll;
			CHAR$1 = (int64)*SRC$1;
			SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
			{
				if( CHAR$1 < 48ll) goto label$303;
				if( CHAR$1 > 57ll) goto label$303;
				label$304:;
				{
					ISNUMBER$1 = -1ll;
					VALUE$1 = (uint64)(CHAR$1 + -48ll);
					{
						I$1 = 2ll;
						label$308:;
						{
							if( SRC$1 < SRC_END$1) goto label$310;
							{
								goto label$307;
								label$310:;
							}
							CHAR$1 = (int64)*SRC$1;
							if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 57ll)) == 0ll) goto label$312;
							{
								goto label$307;
							}
							label$312:;
							label$311:;
							VALUE$1 = (VALUE$1 * 10ull) + (uint64)(CHAR$1 + -48ll);
							SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
						}
						label$306:;
						I$1 = I$1 + 1ll;
						label$305:;
						if( I$1 <= 5ll) goto label$308;
						label$307:;
					}
				}
				goto label$302;
				label$303:;
				if( CHAR$1 == 38ll) goto label$314;
				label$315:;
				if( CHAR$1 == 88ll) goto label$314;
				label$316:;
				if( CHAR$1 != 120ll) goto label$313;
				label$314:;
				{
					if( SRC$1 < SRC_END$1) goto label$318;
					{
						goto label$297;
						label$318:;
					}
					VALUE$1 = 0ull;
					if( CHAR$1 != 38ll) goto label$320;
					{
						CHAR$1 = (int64)*SRC$1;
						SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
					}
					goto label$319;
					label$320:;
					{
						CHAR$1 = 72ll;
					}
					label$319:;
					{
						uint64 TMP$107$6;
						TMP$107$6 = (uint64)CHAR$1;
						goto label$322;
						label$323:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$327:;
								{
									if( SRC$1 < SRC_END$1) goto label$329;
									{
										goto label$326;
										label$329:;
									}
									CHAR$1 = (int64)*SRC$1;
									{
										if( CHAR$1 < 97ll) goto label$333;
										if( CHAR$1 <= 102ll) goto label$332;
										label$333:;
										if( CHAR$1 < 65ll) goto label$334;
										if( CHAR$1 <= 70ll) goto label$332;
										label$334:;
										if( CHAR$1 < 48ll) goto label$331;
										if( CHAR$1 > 57ll) goto label$331;
										label$332:;
										{
											CHAR$1 = CHAR$1 + -48ll;
											if( CHAR$1 <= 9ll) goto label$336;
											{
												CHAR$1 = CHAR$1 + -7ll;
											}
											label$336:;
											label$335:;
											if( CHAR$1 <= 16ll) goto label$338;
											{
												CHAR$1 = CHAR$1 + -32ll;
											}
											label$338:;
											label$337:;
											VALUE$1 = (VALUE$1 << (4ull & 63ll)) + (uint64)CHAR$1;
										}
										goto label$330;
										label$331:;
										{
											goto label$326;
										}
										label$339:;
										label$330:;
									}
									SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
								}
								label$325:;
								I$1 = I$1 + 1ll;
								label$324:;
								if( I$1 <= 4ll) goto label$327;
								label$326:;
							}
						}
						goto label$321;
						label$340:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$344:;
								{
									if( SRC$1 < SRC_END$1) goto label$346;
									{
										goto label$343;
										label$346:;
									}
									CHAR$1 = (int64)*SRC$1;
									if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 55ll)) == 0ll) goto label$348;
									{
										goto label$343;
									}
									label$348:;
									label$347:;
									VALUE$1 = (VALUE$1 << (3ull & 63ll)) + (uint64)(CHAR$1 + -48ll);
									SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
								}
								label$342:;
								I$1 = I$1 + 1ll;
								label$341:;
								if( I$1 <= 6ll) goto label$344;
								label$343:;
							}
						}
						goto label$321;
						label$349:;
						{
							ISNUMBER$1 = -1ll;
							{
								I$1 = 1ll;
								label$353:;
								{
									if( SRC$1 < SRC_END$1) goto label$355;
									{
										goto label$352;
										label$355:;
									}
									CHAR$1 = (int64)*SRC$1;
									if( ((int64)-(CHAR$1 < 48ll) | (int64)-(CHAR$1 > 49ll)) == 0ll) goto label$357;
									{
										goto label$352;
									}
									label$357:;
									label$356:;
									VALUE$1 = (VALUE$1 << (1ull & 63ll)) + (uint64)(CHAR$1 + -48ll);
									SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
								}
								label$351:;
								I$1 = I$1 + 1ll;
								label$350:;
								if( I$1 <= 16ll) goto label$353;
								label$352:;
							}
						}
						goto label$321;
						label$322:;
						static const void* tmp$109[46ll] = {
							&&label$349,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$323,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$340,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$349,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$323,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$321,
							&&label$340,
						};
						if( (TMP$107$6 - 66ull) > 45ull ) goto label$321;
						goto *tmp$109[TMP$107$6 - 66ull];
						label$321:;
					}
				}
				goto label$302;
				label$313:;
				if( CHAR$1 != 117ll) goto label$358;
				label$359:;
				{
					*DST$1 = (uint16)(uint16)CHAR$1;
					DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
					{
						I$1 = 1ll;
						label$363:;
						{
							if( SRC$1 < SRC_END$1) goto label$365;
							{
								*WRNMSG$1 = 52ll;
								goto label$362;
							}
							label$365:;
							label$364:;
							CHAR$1 = (int64)*SRC$1;
							{
								if( CHAR$1 < 48ll) goto label$369;
								if( CHAR$1 <= 57ll) goto label$368;
								label$369:;
								if( CHAR$1 < 97ll) goto label$370;
								if( CHAR$1 <= 102ll) goto label$368;
								label$370:;
								if( CHAR$1 < 65ll) goto label$367;
								if( CHAR$1 > 70ll) goto label$367;
								label$368:;
								{
								}
								goto label$366;
								label$367:;
								{
									*WRNMSG$1 = 52ll;
									goto label$362;
								}
								label$371:;
								label$366:;
							}
							fb_WstrAssign( DST$1, 0ll, (uint16*)SRC$1 );
							DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
							SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
						}
						label$361:;
						I$1 = I$1 + 1ll;
						label$360:;
						if( I$1 <= 4ll) goto label$363;
						label$362:;
					}
					*TEXTLEN$1 = *TEXTLEN$1 + 2ll;
					goto label$296;
				}
				goto label$302;
				label$358:;
				if( CHAR$1 != 85ll) goto label$372;
				label$373:;
				{
					{
						I$1 = 1ll;
						label$377:;
						{
							if( SRC$1 < SRC_END$1) goto label$379;
							{
								*WRNMSG$1 = 52ll;
								goto label$376;
							}
							label$379:;
							label$378:;
							CHAR$1 = (int64)*SRC$1;
							{
								if( CHAR$1 < 48ll) goto label$381;
								if( CHAR$1 > 57ll) goto label$381;
								label$382:;
								{
									VALUE$1 = (VALUE$1 << (4ull & 63ll)) + (uint64)(CHAR$1 + -48ll);
								}
								goto label$380;
								label$381:;
								if( CHAR$1 < 97ll) goto label$383;
								if( CHAR$1 > 102ll) goto label$383;
								label$384:;
								{
									VALUE$1 = ((VALUE$1 << (4ull & 63ll)) + (uint64)(CHAR$1 + -97ll)) + 10ull;
								}
								goto label$380;
								label$383:;
								if( CHAR$1 < 65ll) goto label$385;
								if( CHAR$1 > 70ll) goto label$385;
								label$386:;
								{
									VALUE$1 = ((VALUE$1 << (4ull & 63ll)) + (uint64)(CHAR$1 + -65ll)) + 10ull;
								}
								goto label$380;
								label$385:;
								{
									*WRNMSG$1 = 52ll;
									goto label$376;
								}
								label$387:;
								label$380:;
							}
							SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
						}
						label$375:;
						I$1 = I$1 + 1ll;
						label$374:;
						if( I$1 <= 8ll) goto label$377;
						label$376:;
					}
					if( VALUE$1 <= 65535ull) goto label$389;
					{
						*DST$1 = (uint16)(uint16)85u;
						DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
						int64 vr$90 = HHEXCHAR( (int64)(VALUE$1 >> (28ll & 63ll)) );
						*DST$1 = (uint16)(uint16)vr$90;
						int64 vr$94 = HHEXCHAR( (int64)(VALUE$1 >> (24ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 2ll) = (uint16)(uint16)vr$94;
						int64 vr$98 = HHEXCHAR( (int64)(VALUE$1 >> (20ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 4ll) = (uint16)(uint16)vr$98;
						int64 vr$102 = HHEXCHAR( (int64)(VALUE$1 >> (16ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 6ll) = (uint16)(uint16)vr$102;
						int64 vr$106 = HHEXCHAR( (int64)(VALUE$1 >> (12ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 8ll) = (uint16)(uint16)vr$106;
						int64 vr$110 = HHEXCHAR( (int64)(VALUE$1 >> (8ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 10ll) = (uint16)(uint16)vr$110;
						int64 vr$114 = HHEXCHAR( (int64)(VALUE$1 >> (4ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 12ll) = (uint16)(uint16)vr$114;
						int64 vr$117 = HHEXCHAR( (int64)VALUE$1 );
						*(uint16*)((uint8*)DST$1 + 14ll) = (uint16)(uint16)vr$117;
						DST$1 = (uint16*)((uint8*)DST$1 + 16ll);
						*TEXTLEN$1 = *TEXTLEN$1 + 4ll;
					}
					goto label$388;
					label$389:;
					{
						*DST$1 = (uint16)(uint16)117u;
						DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
						int64 vr$127 = HHEXCHAR( (int64)(VALUE$1 >> (12ll & 63ll)) );
						*DST$1 = (uint16)(uint16)vr$127;
						int64 vr$131 = HHEXCHAR( (int64)(VALUE$1 >> (8ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 2ll) = (uint16)(uint16)vr$131;
						int64 vr$135 = HHEXCHAR( (int64)(VALUE$1 >> (4ll & 63ll)) );
						*(uint16*)((uint8*)DST$1 + 4ll) = (uint16)(uint16)vr$135;
						int64 vr$138 = HHEXCHAR( (int64)VALUE$1 );
						*(uint16*)((uint8*)DST$1 + 6ll) = (uint16)(uint16)vr$138;
						DST$1 = (uint16*)((uint8*)DST$1 + 8ll);
						*TEXTLEN$1 = *TEXTLEN$1 + 2ll;
					}
					label$388:;
					goto label$296;
				}
				label$372:;
				label$302:;
			}
			if( ISNUMBER$1 == 0ll) goto label$391;
			{
				uint16* TMP$108$4;
				if( VALUE$1 <= 65535ull) goto label$393;
				{
					ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
					VALUE$1 = 65535ull;
				}
				label$393:;
				label$392:;
				LGT$1 = 1ll;
				static uint64 UIVALUE$4;
				UIVALUE$4 = VALUE$1;
				label$394:;
				if( UIVALUE$4 <= 7ull) goto label$395;
				{
					UIVALUE$4 = UIVALUE$4 >> (3ll & 63ll);
					LGT$1 = LGT$1 + 1ll;
				}
				goto label$394;
				label$395:;
				*DST$1 = (uint16)(uint16)LGT$1;
				DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
				uint16* vr$150 = fb_WstrOct_l( VALUE$1 );
				TMP$108$4 = vr$150;
				fb_WstrAssign( DST$1, 0ll, (uint16*)TMP$108$4 );
				fb_WstrDelete( (uint16*)TMP$108$4 );
				DST$1 = (uint16*)((uint8*)DST$1 + (LGT$1 << (1ll & 63ll)));
				*TEXTLEN$1 = *TEXTLEN$1 + 1ll;
				goto label$296;
			}
			label$391:;
			label$390:;
		}
		label$299:;
		label$298:;
		*DST$1 = (uint16)(uint16)CHAR$1;
		DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
		*TEXTLEN$1 = *TEXTLEN$1 + 1ll;
	}
	goto label$296;
	label$297:;
	*DST$1 = (uint16)(uint16)0u;
	fb$result$1 = *(uint16**)&RES$1;
	label$293:;
	return fb$result$1;
}

char* HESCAPE( char* TEXT$1, int64 MAXLEN$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$396:;
	static struct $8DZSTRING RES$1;
	static int64 C$1;
	static int64 OCTLEN$1;
	static int64 LGT$1;
	static int64 N$1;
	static char* SRC$1;
	static char* SRC_END$1;
	static char* DST$1;
	OCTLEN$1 = 0ll;
	N$1 = 0ll;
	int64 vr$1 = fb_StrLen( (void*)TEXT$1, 0ll );
	LGT$1 = vr$1;
	if( LGT$1 != 0ll) goto label$399;
	{
		fb$result$1 = TEXT$1;
		goto label$397;
	}
	label$399:;
	label$398:;
	DZSTRALLOCATE( &RES$1, LGT$1 << (2ll & 63ll) );
	SRC$1 = TEXT$1;
	DST$1 = *(char**)&RES$1;
	SRC_END$1 = (char*)((uint8*)SRC$1 + LGT$1);
	label$400:;
	if( SRC$1 >= SRC_END$1) goto label$401;
	{
		int64 TMP$110$2;
		C$1 = (int64)(uint8)*SRC$1;
		SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
		{
			if( C$1 == 92ll) goto label$404;
			label$405:;
			if( C$1 != 34ll) goto label$403;
			label$404:;
			{
				*DST$1 = (uint8)92u;
				DST$1 = (char*)((uint8*)DST$1 + 1ll);
			}
			goto label$402;
			label$403:;
			if( C$1 != 27ll) goto label$406;
			label$407:;
			{
				*DST$1 = (uint8)92u;
				DST$1 = (char*)((uint8*)DST$1 + 1ll);
				if( SRC$1 < SRC_END$1) goto label$409;
				{
					goto label$401;
					label$409:;
				}
				C$1 = (int64)(uint8)*SRC$1;
				SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
				if( ((int64)-(C$1 >= 1ll) & (int64)-(C$1 <= 3ll)) == 0ll) goto label$411;
				{
					OCTLEN$1 = C$1;
					if( SRC$1 < SRC_END$1) goto label$413;
					{
						goto label$401;
						label$413:;
					}
					C$1 = (int64)(uint8)*SRC$1;
					SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
				}
				label$411:;
				label$410:;
			}
			goto label$402;
			label$406:;
			if( C$1 < 0ll) goto label$416;
			if( C$1 <= 31ll) goto label$415;
			label$416:;
			if( C$1 < 128ll) goto label$414;
			if( C$1 > 255ll) goto label$414;
			label$415:;
			{
				*DST$1 = (uint8)92u;
				DST$1 = (char*)((uint8*)DST$1 + 1ll);
				if( C$1 >= 8ll) goto label$418;
				{
					*DST$1 = (uint8)48u;
					*(char*)((uint8*)DST$1 + 1ll) = (uint8)48u;
					DST$1 = (char*)((uint8*)DST$1 + 2ll);
					C$1 = C$1 + 48ll;
				}
				goto label$417;
				label$418:;
				if( C$1 >= 64ll) goto label$419;
				{
					*DST$1 = (uint8)48u;
					*(char*)((uint8*)DST$1 + 1ll) = (uint8)((C$1 >> (3ll & 63ll)) + 48ll);
					DST$1 = (char*)((uint8*)DST$1 + 2ll);
					C$1 = (C$1 & 7ll) + 48ll;
				}
				goto label$417;
				label$419:;
				{
					*DST$1 = (uint8)((C$1 >> (6ll & 63ll)) + 48ll);
					*(char*)((uint8*)DST$1 + 1ll) = (uint8)(((C$1 & 56ll) >> (3ll & 63ll)) + 48ll);
					DST$1 = (char*)((uint8*)DST$1 + 2ll);
					C$1 = (C$1 & 7ll) + 48ll;
				}
				label$417:;
			}
			label$414:;
			label$402:;
		}
		*DST$1 = (uint8)C$1;
		DST$1 = (char*)((uint8*)DST$1 + 1ll);
		N$1 = N$1 + 1ll;
		if( MAXLEN$1 <= 0ll) goto label$420;
		TMP$110$2 = (int64)-(N$1 >= MAXLEN$1);
		goto label$427;
		label$420:;
		TMP$110$2 = 0ll;
		label$427:;
		if( TMP$110$2 == 0ll) goto label$422;
		{
			goto label$401;
			label$422:;
		}
		if( OCTLEN$1 <= 0ll) goto label$424;
		{
			OCTLEN$1 = OCTLEN$1 + -1ll;
			if( OCTLEN$1 != 0ll) goto label$426;
			{
				*DST$1 = (uint8)34u;
				*(char*)((uint8*)DST$1 + 1ll) = (uint8)34u;
				DST$1 = (char*)((uint8*)DST$1 + 2ll);
			}
			label$426:;
			label$425:;
		}
		label$424:;
		label$423:;
	}
	goto label$400;
	label$401:;
	*DST$1 = (uint8)0u;
	fb$result$1 = (char*)*(char**)&RES$1;
	label$397:;
	return fb$result$1;
}

char* HESCAPEW( uint16* TEXT$1, int64 MAXLEN$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$428:;
	static struct $8DZSTRING RES$1;
	static uint64 CHAR$1;
	static int64 LGT$1;
	static int64 I$1;
	static int64 WCHARLEN$1;
	static int64 N$1;
	static uint16* SRC$1;
	static uint16* SRC_END$1;
	static char* DST$1;
	WCHARLEN$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 400ll);
	N$1 = 0ll;
	int64 vr$1 = fb_WstrLen( TEXT$1 );
	LGT$1 = vr$1;
	if( LGT$1 != 0ll) goto label$431;
	{
		fb$result$1 = (char*)0ull;
		goto label$429;
	}
	label$431:;
	label$430:;
	DZSTRALLOCATE( &RES$1, (LGT$1 * WCHARLEN$1) << (2ll & 63ll) );
	SRC$1 = TEXT$1;
	DST$1 = *(char**)&RES$1;
	SRC_END$1 = (uint16*)((uint8*)SRC$1 + (LGT$1 << (1ll & 63ll)));
	label$432:;
	if( SRC$1 >= SRC_END$1) goto label$433;
	{
		int64 TMP$115$2;
		CHAR$1 = (uint64)*SRC$1;
		SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
		if( CHAR$1 != 27ull) goto label$435;
		{
			if( SRC$1 < SRC_END$1) goto label$437;
			{
				goto label$433;
				label$437:;
			}
			CHAR$1 = (uint64)*SRC$1;
			SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
			if( ((int64)-(CHAR$1 >= 1ull) & (int64)-(CHAR$1 <= 11ull)) == 0ll) goto label$439;
			{
				I$1 = (int64)CHAR$1;
				CHAR$1 = 0ull;
				if( (uint16*)((uint8*)SRC$1 + (I$1 << (1ll & 63ll))) <= SRC_END$1) goto label$441;
				{
					goto label$433;
					label$441:;
				}
				label$442:;
				if( I$1 <= 0ll) goto label$443;
				{
					CHAR$1 = (CHAR$1 << (3ull & 63ll)) + (uint64)((int64)*SRC$1 + -48ll);
					SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
					I$1 = I$1 + -1ll;
				}
				goto label$442;
				label$443:;
			}
			goto label$438;
			label$439:;
			{
				if( CHAR$1 != 117ull) goto label$445;
				{
					if( (uint16*)((uint8*)SRC$1 + 8ll) <= SRC_END$1) goto label$447;
					{
						goto label$433;
						label$447:;
					}
					uint64 vr$25 = HUNICODEHEXTOCODEPOINTW( &SRC$1, 4ll );
					CHAR$1 = vr$25;
				}
				goto label$444;
				label$445:;
				if( CHAR$1 != 85ull) goto label$448;
				{
					if( (uint16*)((uint8*)SRC$1 + 16ll) <= SRC_END$1) goto label$450;
					{
						goto label$433;
						label$450:;
					}
					uint64 vr$27 = HUNICODEHEXTOCODEPOINTW( &SRC$1, 8ll );
					CHAR$1 = vr$27;
				}
				goto label$444;
				label$448:;
				{
					int64 vr$28 = HREMAPCHAR( (int64)CHAR$1 );
					CHAR$1 = (uint64)vr$28;
				}
				label$444:;
			}
			label$438:;
		}
		label$435:;
		label$434:;
		if( ((int64)-(WCHARLEN$1 == 2ll) & (int64)-(CHAR$1 >= 65536ull)) == 0ll) goto label$452;
		{
			uint64 TMP$113$3;
			uint64 TMP$114$3;
			CHAR$1 = CHAR$1 + 18446744073709486080ull;
			TMP$113$3 = (CHAR$1 >> (10ll & 63ll)) + 55296ull;
			HUNICODECODEPOINTCHARTOHEX( &TMP$113$3, &DST$1, WCHARLEN$1 );
			TMP$114$3 = (CHAR$1 & 1023ull) + 56320ull;
			HUNICODECODEPOINTCHARTOHEX( &TMP$114$3, &DST$1, WCHARLEN$1 );
		}
		goto label$451;
		label$452:;
		{
			HUNICODECODEPOINTCHARTOHEX( &CHAR$1, &DST$1, WCHARLEN$1 );
		}
		label$451:;
		N$1 = N$1 + 1ll;
		if( MAXLEN$1 <= 0ll) goto label$453;
		TMP$115$2 = (int64)-(N$1 >= MAXLEN$1);
		goto label$456;
		label$453:;
		TMP$115$2 = 0ll;
		label$456:;
		if( TMP$115$2 == 0ll) goto label$455;
		{
			goto label$433;
			label$455:;
		}
	}
	goto label$432;
	label$433:;
	*DST$1 = (uint8)0u;
	fb$result$1 = *(char**)&RES$1;
	label$429:;
	return fb$result$1;
}

char* HUNESCAPE( char* TEXT$1, int64* TEXTLEN$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$457:;
	static struct $8DZSTRING RES$1;
	static int64 CHAR$1;
	static int64 LGT$1;
	static int64 I$1;
	static char* SRC$1;
	static char* DST$1;
	static char* SRC_END$1;
	*TEXTLEN$1 = 0ll;
	int64 vr$2 = fb_StrLen( (void*)TEXT$1, 0ll );
	LGT$1 = vr$2;
	if( LGT$1 != 0ll) goto label$460;
	{
		fb$result$1 = TEXT$1;
		goto label$458;
	}
	label$460:;
	label$459:;
	DZSTRALLOCATE( &RES$1, LGT$1 );
	SRC$1 = TEXT$1;
	DST$1 = *(char**)&RES$1;
	SRC_END$1 = (char*)((uint8*)SRC$1 + LGT$1);
	label$461:;
	if( SRC$1 >= SRC_END$1) goto label$462;
	{
		CHAR$1 = (int64)(uint8)*SRC$1;
		SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
		if( CHAR$1 != 27ll) goto label$464;
		{
			if( SRC$1 < SRC_END$1) goto label$466;
			{
				goto label$462;
				label$466:;
			}
			CHAR$1 = (int64)(uint8)*SRC$1;
			SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
			if( ((int64)-(CHAR$1 >= 1ll) & (int64)-(CHAR$1 <= 3ll)) == 0ll) goto label$468;
			{
				I$1 = CHAR$1;
				CHAR$1 = 0ll;
				label$469:;
				if( I$1 <= 0ll) goto label$470;
				{
					CHAR$1 = ((CHAR$1 << (3ll & 63ll)) + (int64)(uint8)*SRC$1) + -48ll;
					SRC$1 = (char*)((uint8*)SRC$1 + 1ll);
					I$1 = I$1 + -1ll;
				}
				goto label$469;
				label$470:;
			}
			goto label$467;
			label$468:;
			{
				int64 vr$20 = HREMAPCHAR( CHAR$1 );
				CHAR$1 = vr$20;
			}
			label$467:;
		}
		label$464:;
		label$463:;
		*DST$1 = (uint8)CHAR$1;
		DST$1 = (char*)((uint8*)DST$1 + 1ll);
	}
	goto label$461;
	label$462:;
	*DST$1 = (uint8)0u;
	*TEXTLEN$1 = (int64)DST$1 - *(int64*)&RES$1;
	fb$result$1 = *(char**)&RES$1;
	label$458:;
	return fb$result$1;
}

uint16* HUNESCAPEW( uint16* TEXT$1, int64* TEXTLEN$1 )
{
	uint16* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$471:;
	static struct $8DWSTRING RES$1;
	static int64 CHAR$1;
	static int64 LGT$1;
	static int64 I$1;
	static uint16* SRC$1;
	static uint16* DST$1;
	static uint16* SRC_END$1;
	*TEXTLEN$1 = 0ll;
	int64 vr$2 = fb_WstrLen( (uint16*)TEXT$1 );
	LGT$1 = vr$2;
	if( LGT$1 != 0ll) goto label$474;
	{
		fb$result$1 = TEXT$1;
		goto label$472;
	}
	label$474:;
	label$473:;
	DWSTRALLOCATE( &RES$1, LGT$1 );
	SRC$1 = TEXT$1;
	DST$1 = *(uint16**)&RES$1;
	SRC_END$1 = (uint16*)((uint8*)SRC$1 + (LGT$1 << (1ll & 63ll)));
	label$475:;
	if( SRC$1 >= SRC_END$1) goto label$476;
	{
		CHAR$1 = (int64)*SRC$1;
		SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
		if( CHAR$1 != 27ll) goto label$478;
		{
			if( SRC$1 < SRC_END$1) goto label$480;
			{
				goto label$476;
				label$480:;
			}
			CHAR$1 = (int64)*SRC$1;
			SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
			if( ((int64)-(CHAR$1 >= 1ll) & (int64)-(CHAR$1 <= 11ll)) == 0ll) goto label$482;
			{
				I$1 = CHAR$1;
				CHAR$1 = 0ll;
				label$483:;
				if( I$1 <= 0ll) goto label$484;
				{
					CHAR$1 = ((CHAR$1 << (3ll & 63ll)) + (int64)*SRC$1) + -48ll;
					SRC$1 = (uint16*)((uint8*)SRC$1 + 2ll);
					I$1 = I$1 + -1ll;
				}
				goto label$483;
				label$484:;
			}
			goto label$481;
			label$482:;
			{
				if( (uint64)CHAR$1 != 117ull) goto label$486;
				{
					if( (uint16*)((uint8*)SRC$1 + 8ll) <= SRC_END$1) goto label$488;
					{
						goto label$476;
						label$488:;
					}
					uint64 vr$22 = HUNICODEHEXTOCODEPOINTW( (uint16**)&SRC$1, 4ll );
					CHAR$1 = (int64)vr$22;
				}
				goto label$485;
				label$486:;
				if( (uint64)CHAR$1 != 85ull) goto label$489;
				{
					if( (uint16*)((uint8*)SRC$1 + 16ll) <= SRC_END$1) goto label$491;
					{
						goto label$476;
						label$491:;
					}
					uint64 vr$24 = HUNICODEHEXTOCODEPOINTW( (uint16**)&SRC$1, 8ll );
					CHAR$1 = (int64)vr$24;
				}
				goto label$485;
				label$489:;
				{
					int64 vr$25 = HREMAPCHAR( CHAR$1 );
					CHAR$1 = vr$25;
				}
				label$485:;
			}
			label$481:;
		}
		label$478:;
		label$477:;
		{
			if( CHAR$1 <= 65535ll) goto label$495;
			{
				CHAR$1 = CHAR$1 + -65536ll;
				*DST$1 = (uint16)(uint16)((CHAR$1 >> (10ll & 63ll)) + 55296ll);
				*(uint16*)((uint8*)DST$1 + 2ll) = (uint16)(uint16)((CHAR$1 & 1023ll) + 56320ll);
				DST$1 = (uint16*)((uint8*)DST$1 + 4ll);
			}
			goto label$494;
			label$495:;
			{
				*DST$1 = (uint16)(uint16)CHAR$1;
				DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
			}
			label$494:;
		}
		goto label$492;
		label$493:;
		{
			*DST$1 = (uint16)(uint16)CHAR$1;
			DST$1 = (uint16*)((uint8*)DST$1 + 2ll);
		}
		label$492:;
	}
	goto label$475;
	label$476:;
	*DST$1 = (uint16)(uint16)0u;
	*TEXTLEN$1 = ((int64)DST$1 - *(int64*)&RES$1) / 2ll;
	fb$result$1 = *(uint16**)&RES$1;
	label$472:;
	return fb$result$1;
}

int64 HCHARNEEDSESCAPING( int64 CH$1, int64 QUOTECHAR$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$496:;
	fb$result$1 = (((int64)-(CH$1 < 32ll) | (int64)-(CH$1 >= 127ll)) | (int64)-((uint64)CH$1 == 92ull)) | (int64)-(CH$1 == QUOTECHAR$1);
	label$497:;
	return fb$result$1;
}

int64 HISVALIDHEXDIGIT( int64 CH$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$498:;
	fb$result$1 = (((int64)-((uint64)CH$1 >= 48ull) & (int64)-((uint64)CH$1 <= 57ull)) | ((int64)-((uint64)CH$1 >= 97ull) & (int64)-((uint64)CH$1 <= 102ull))) | ((int64)-((uint64)CH$1 >= 65ull) & (int64)-((uint64)CH$1 <= 70ull));
	label$499:;
	return fb$result$1;
}

int64 HSTR2LONG( FBSTRING* TXT$1, int32* VALUE$1 )
{
	int64 TMP$120$1;
	int64 TMP$121$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$500:;
	int32 NVALUE$1;
	NVALUE$1 = 0;
	int32 NSIGN$1;
	NSIGN$1 = 1;
	int64 vr$1 = fb_StrLen( (void*)TXT$1, -1ll );
	if( vr$1 != 0ll) goto label$503;
	{
		fb$result$1 = 0ll;
		goto label$501;
	}
	label$503:;
	label$502:;
	uint8* S$1;
	S$1 = (uint8*)*(char**)TXT$1;
	if( S$1 == (uint8*)0ull) goto label$504;
	TMP$120$1 = (int64)-((int64)*S$1 == 0ll);
	goto label$514;
	label$504:;
	TMP$120$1 = -1ll;
	label$514:;
	if( TMP$120$1 == 0ll) goto label$506;
	{
		fb$result$1 = 0ll;
		goto label$501;
	}
	label$506:;
	label$505:;
	if( (int64)*S$1 != 45ll) goto label$508;
	{
		NSIGN$1 = -1;
		S$1 = (uint8*)(S$1 + 1ll);
	}
	label$508:;
	label$507:;
	if( (int64)*S$1 != 0ll) goto label$510;
	{
		fb$result$1 = 0ll;
		goto label$501;
	}
	label$510:;
	label$509:;
	label$511:;
	if( (uint64)(int64)*S$1 > 57ull) goto label$513;
	TMP$121$1 = (int64)-((uint64)(int64)*S$1 >= 48ull);
	goto label$515;
	label$513:;
	TMP$121$1 = 0ll;
	label$515:;
	if( TMP$121$1 == 0ll) goto label$512;
	{
		NVALUE$1 = (int32)((int64)NVALUE$1 * 10ll);
		NVALUE$1 = (int32)(((uint64)(int64)NVALUE$1 + (uint64)(int64)*S$1) + 18446744073709551568ull);
		S$1 = (uint8*)(S$1 + 1ll);
	}
	goto label$511;
	label$512:;
	*VALUE$1 = (int32)((int64)NVALUE$1 * (int64)NSIGN$1);
	fb$result$1 = (int64)-((int64)*S$1 == 0ll);
	goto label$501;
	label$501:;
	return fb$result$1;
}

int64 HWSTR2LONG( uint16* TXT$1, int32* VALUE$1 )
{
	int64 TMP$122$1;
	int64 TMP$123$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$516:;
	int32 NVALUE$1;
	NVALUE$1 = 0;
	int32 NSIGN$1;
	NSIGN$1 = 1;
	int64 vr$1 = fb_WstrLen( (uint16*)TXT$1 );
	if( vr$1 != 0ll) goto label$519;
	{
		fb$result$1 = 0ll;
		goto label$517;
	}
	label$519:;
	label$518:;
	uint16* S$1;
	S$1 = (uint16*)TXT$1;
	if( S$1 == (uint16*)0ull) goto label$520;
	TMP$122$1 = (int64)-((int64)*S$1 == 0ll);
	goto label$530;
	label$520:;
	TMP$122$1 = -1ll;
	label$530:;
	if( TMP$122$1 == 0ll) goto label$522;
	{
		fb$result$1 = 0ll;
		goto label$517;
	}
	label$522:;
	label$521:;
	if( (int64)*S$1 != 45ll) goto label$524;
	{
		NSIGN$1 = -1;
		S$1 = (uint16*)((uint8*)S$1 + 2ll);
	}
	label$524:;
	label$523:;
	if( (int64)*S$1 != 0ll) goto label$526;
	{
		fb$result$1 = 0ll;
		goto label$517;
	}
	label$526:;
	label$525:;
	label$527:;
	if( (uint64)(int64)*S$1 > 57ull) goto label$529;
	TMP$123$1 = (int64)-((uint64)(int64)*S$1 >= 48ull);
	goto label$531;
	label$529:;
	TMP$123$1 = 0ll;
	label$531:;
	if( TMP$123$1 == 0ll) goto label$528;
	{
		NVALUE$1 = (int32)((int64)NVALUE$1 * 10ll);
		NVALUE$1 = (int32)(((uint64)(int64)NVALUE$1 + (uint64)(int64)*S$1) + 18446744073709551568ull);
		S$1 = (uint16*)((uint8*)S$1 + 2ll);
	}
	goto label$527;
	label$528:;
	*VALUE$1 = (int32)((int64)NVALUE$1 * (int64)NSIGN$1);
	fb$result$1 = (int64)-((int64)*S$1 == 0ll);
	goto label$517;
	label$517:;
	return fb$result$1;
}

void HSPLITSTR( FBSTRING* TXT$1, FBSTRING* DEL$1, struct $7FBARRAYI8FBSTRINGE* RES$1 )
{
	label$532:;
	int64 ITEMS$1;
	ITEMS$1 = 10ll;
	struct $8FBARRAY1Iu7INTEGERE DPOS$1;
	*(int64**)&DPOS$1 = (int64*)0ull;
	*(int64**)((uint8*)&DPOS$1 + 8ll) = (int64*)0ull;
	*(int64*)((uint8*)&DPOS$1 + 16ll) = 0ll;
	*(int64*)((uint8*)&DPOS$1 + 24ll) = 8ll;
	*(int64*)((uint8*)&DPOS$1 + 32ll) = 1ll;
	*(int64*)((uint8*)&DPOS$1 + 40ll) = 17ll;
	__builtin_memset( (void*)((uint8*)&DPOS$1 + 48ll), 0, 24ll );
	int32 vr$3 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)&DPOS$1, 8ull, -1, 0, 1ull, 0ll, ITEMS$1 + -1ll );
	if( (int64)vr$3 == 0ll) goto label$534;
	void* vr$5 = fb_ErrorThrowAt( 1539, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
	goto *vr$5;
	label$534:;
	int64 DELLEN$1;
	int64 vr$6 = fb_StrLen( (void*)DEL$1, -1ll );
	DELLEN$1 = vr$6;
	int64 CNT$1;
	CNT$1 = 0ll;
	int64 P$1;
	P$1 = 1ll;
	label$535:;
	{
		int64 vr$7 = fb_StrInstr( P$1, (FBSTRING*)TXT$1, (FBSTRING*)DEL$1 );
		P$1 = vr$7;
		if( P$1 <= 0ll) goto label$539;
		{
			if( CNT$1 < ITEMS$1) goto label$541;
			{
				ITEMS$1 = ITEMS$1 + 10ll;
				int32 vr$11 = fb_ArrayRedimPresvEx( (struct $7FBARRAYIvE*)&DPOS$1, 8ull, -1, 0, 1ull, 0ll, ITEMS$1 + -1ll );
				if( (int64)vr$11 == 0ll) goto label$542;
				void* vr$13 = fb_ErrorThrowAt( 1550, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
				goto *vr$13;
				label$542:;
			}
			label$541:;
			label$540:;
			*(int64*)((CNT$1 << (3ll & 63ll)) + *(int64*)&DPOS$1) = P$1;
			P$1 = P$1 + DELLEN$1;
		}
		label$539:;
		label$538:;
		CNT$1 = CNT$1 + 1ll;
	}
	label$537:;
	if( P$1 != 0ll) goto label$535;
	label$536:;
	CNT$1 = CNT$1 + -1ll;
	if( CNT$1 != 0ll) goto label$544;
	{
		int32 vr$19 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, -1, 1ull, 0ll, 0ll );
		if( (int64)vr$19 == 0ll) goto label$545;
		void* vr$21 = fb_ErrorThrowAt( 1560, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
		goto *vr$21;
		label$545:;
		fb_StrAssign( (void*)*(int64*)RES$1, -1ll, (void*)TXT$1, -1ll, 0 );
		fb_ArrayErase( (struct $7FBARRAYIvE*)&DPOS$1 );
		goto label$533;
	}
	label$544:;
	label$543:;
	int32 vr$25 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, -1, 1ull, 0ll, CNT$1 );
	if( (int64)vr$25 == 0ll) goto label$546;
	void* vr$27 = fb_ErrorThrowAt( 1565, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
	goto *vr$27;
	label$546:;
	FBSTRING* vr$29 = fb_LEFT( (FBSTRING*)TXT$1, *(int64*)*(int64*)&DPOS$1 + -1ll );
	fb_StrAssign( (void*)*(int64*)RES$1, -1ll, (void*)vr$29, -1ll, 0 );
	P$1 = 1ll;
	label$547:;
	if( P$1 == CNT$1) goto label$548;
	{
		FBSTRING* vr$41 = fb_StrMid( (FBSTRING*)TXT$1, *(int64*)((uint8*)((P$1 << (3ll & 63ll)) + *(int64*)&DPOS$1) + -8ll) + DELLEN$1, (*(int64*)((P$1 << (3ll & 63ll)) + *(int64*)&DPOS$1) - *(int64*)((uint8*)((P$1 << (3ll & 63ll)) + *(int64*)&DPOS$1) + -8ll)) - DELLEN$1 );
		fb_StrAssign( (void*)((P$1 * 24ll) + *(int64*)RES$1), -1ll, (void*)vr$41, -1ll, 0 );
		P$1 = P$1 + 1ll;
	}
	goto label$547;
	label$548:;
	FBSTRING* vr$50 = fb_StrMid( (FBSTRING*)TXT$1, *(int64*)((uint8*)((CNT$1 << (3ll & 63ll)) + *(int64*)&DPOS$1) + -8ll) + DELLEN$1, -1ll );
	fb_StrAssign( (void*)((CNT$1 * 24ll) + *(int64*)RES$1), -1ll, (void*)vr$50, -1ll, 0 );
	fb_ArrayErase( (struct $7FBARRAYIvE*)&DPOS$1 );
	label$533:;
}

int64 HSTR2TOK( char* TXT$1, struct $7FBARRAYI8FBSTRINGE* RES$1 )
{
	int64 TMP$126$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$549:;
	int64 T$1;
	T$1 = 0ll;
	uint64 LC$1;
	LC$1 = 32ull;
	uint8* S$1;
	S$1 = (uint8*)TXT$1;
	label$551:;
	if( (int64)*S$1 == 0ll) goto label$552;
	{
		uint64 C$2;
		C$2 = (uint64)*S$1;
		if( C$2 != 7ull) goto label$554;
		{
			C$2 = 32ull;
		}
		label$554:;
		label$553:;
		if( C$2 != 32ull) goto label$556;
		{
			if( LC$1 == 32ull) goto label$558;
			{
				T$1 = T$1 + 1ll;
			}
			label$558:;
			label$557:;
		}
		label$556:;
		label$555:;
		LC$1 = C$2;
		S$1 = (uint8*)((uint8*)S$1 + 1ll);
	}
	goto label$551;
	label$552:;
	if( LC$1 == 32ull) goto label$560;
	{
		T$1 = T$1 + 1ll;
	}
	label$560:;
	label$559:;
	if( T$1 != 0ll) goto label$562;
	{
		fb$result$1 = 0ll;
		goto label$550;
	}
	label$562:;
	label$561:;
	int32 vr$9 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, -1, 1ull, 0ll, T$1 + -1ll );
	if( (int64)vr$9 == 0ll) goto label$563;
	void* vr$11 = fb_ErrorThrowAt( 1607, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
	goto *vr$11;
	label$563:;
	T$1 = 0ll;
	LC$1 = 32ull;
	S$1 = (uint8*)TXT$1;
	label$564:;
	if( (int64)*S$1 == 0ll) goto label$565;
	{
		uint64 C$2;
		C$2 = (uint64)*S$1;
		if( C$2 != 7ull) goto label$567;
		{
			C$2 = 32ull;
		}
		label$567:;
		label$566:;
		if( C$2 != 32ull) goto label$569;
		{
			if( LC$1 == 32ull) goto label$571;
			{
				T$1 = T$1 + 1ll;
			}
			label$571:;
			label$570:;
		}
		goto label$568;
		label$569:;
		{
			FBSTRING TMP$125$3;
			FBSTRING* vr$17 = fb_CHR( 1, (int64)C$2 );
			__builtin_memset( &TMP$125$3, 0, 24ll );
			FBSTRING* vr$24 = fb_StrConcat( &TMP$125$3, (void*)((T$1 * 24ll) + *(int64*)RES$1), -1ll, (void*)vr$17, -1ll );
			fb_StrAssign( (void*)((T$1 * 24ll) + *(int64*)RES$1), -1ll, (void*)vr$24, -1ll, 0 );
		}
		label$568:;
		LC$1 = C$2;
		S$1 = (uint8*)((uint8*)S$1 + 1ll);
	}
	goto label$564;
	label$565:;
	if( LC$1 == 32ull) goto label$572;
	TMP$126$1 = T$1 + 1ll;
	goto label$573;
	label$572:;
	TMP$126$1 = T$1;
	label$573:;
	fb$result$1 = TMP$126$1;
	label$550:;
	return fb$result$1;
}

int64 HSTR2ARGS( char* TXT$1, struct $7FBARRAYI8FBSTRINGE* RES$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$574:;
	int64 T$1;
	T$1 = 0ll;
	uint8* S$1;
	S$1 = (uint8*)TXT$1;
	int64 PRNTCNT$1;
	PRNTCNT$1 = 0ll;
	uint64 C$1;
	C$1 = 0ull;
	int64 MAX_T$1;
	MAX_T$1 = 10ll;
	if( TXT$1 != (char*)0ull) goto label$577;
	{
		fb$result$1 = 0ll;
		goto label$575;
	}
	label$577:;
	label$576:;
	int32 vr$2 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, -1, 1ull, 0ll, MAX_T$1 + -1ll );
	if( (int64)vr$2 == 0ll) goto label$578;
	void* vr$4 = fb_ErrorThrowAt( 1654, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
	goto *vr$4;
	label$578:;
	label$579:;
	{
		C$1 = (uint64)*S$1;
		if( ((int64)-(C$1 == 9ull) | (int64)-(C$1 == 32ull)) == 0ll) goto label$583;
		{
			S$1 = (uint8*)((uint8*)S$1 + 1ll);
		}
		goto label$582;
		label$583:;
		{
			goto label$580;
		}
		label$582:;
	}
	label$581:;
	goto label$579;
	label$580:;
	if( C$1 != 0ull) goto label$585;
	{
		fb$result$1 = 0ll;
		goto label$575;
	}
	label$585:;
	label$584:;
	T$1 = T$1 + 1ll;
	label$586:;
	{
		FBSTRING TMP$137$2;
		C$1 = (uint64)*S$1;
		{
			if( C$1 != 0ull) goto label$590;
			label$591:;
			{
				goto label$587;
			}
			goto label$589;
			label$590:;
			if( C$1 != 40ull) goto label$592;
			label$593:;
			{
				PRNTCNT$1 = PRNTCNT$1 + 1ll;
			}
			goto label$589;
			label$592:;
			if( C$1 != 41ull) goto label$594;
			label$595:;
			{
				if( PRNTCNT$1 <= 0ll) goto label$597;
				{
					PRNTCNT$1 = PRNTCNT$1 + -1ll;
				}
				label$597:;
				label$596:;
			}
			goto label$589;
			label$594:;
			if( C$1 != 44ull) goto label$598;
			label$599:;
			{
				if( PRNTCNT$1 != 0ll) goto label$601;
				{
					T$1 = T$1 + 1ll;
					if( T$1 <= MAX_T$1) goto label$603;
					{
						MAX_T$1 = MAX_T$1 + 10ll;
						int32 vr$19 = fb_ArrayRedimPresvEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, -1, 1ull, 0ll, MAX_T$1 + -1ll );
						if( (int64)vr$19 == 0ll) goto label$604;
						void* vr$21 = fb_ErrorThrowAt( 1693, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
						goto *vr$21;
						label$604:;
					}
					label$603:;
					label$602:;
					S$1 = (uint8*)((uint8*)S$1 + 1ll);
					goto label$588;
				}
				label$601:;
				label$600:;
			}
			goto label$589;
			label$598:;
			if( C$1 == 34ull) goto label$606;
			label$607:;
			if( C$1 == 33ull) goto label$606;
			label$608:;
			if( C$1 != 36ull) goto label$605;
			label$606:;
			{
				FBSTRING TMP$128$4;
				int64 ESCAPED$4;
				ESCAPED$4 = *(int64*)((uint8*)&ENV$ + 1560ll);
				if( C$1 == 34ull) goto label$610;
				{
					FBSTRING TMP$127$5;
					ESCAPED$4 = (int64)-(C$1 == 33ull);
					FBSTRING* vr$24 = fb_CHR( 1, (int64)C$1 );
					__builtin_memset( &TMP$127$5, 0, 24ll );
					FBSTRING* vr$31 = fb_StrConcat( &TMP$127$5, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$24, -1ll );
					fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$31, -1ll, 0 );
					S$1 = (uint8*)((uint8*)S$1 + 1ll);
					C$1 = (uint64)*S$1;
					if( C$1 == 34ull) goto label$612;
					{
						goto label$588;
					}
					label$612:;
					label$611:;
				}
				label$610:;
				label$609:;
				FBSTRING* vr$39 = fb_CHR( 1, (int64)C$1 );
				__builtin_memset( &TMP$128$4, 0, 24ll );
				FBSTRING* vr$46 = fb_StrConcat( &TMP$128$4, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$39, -1ll );
				fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$46, -1ll, 0 );
				S$1 = (uint8*)((uint8*)S$1 + 1ll);
				label$613:;
				{
					FBSTRING TMP$129$5;
					C$1 = (uint64)*S$1;
					if( C$1 != 0ull) goto label$617;
					{
						goto label$614;
					}
					label$617:;
					label$616:;
					FBSTRING* vr$54 = fb_CHR( 1, (int64)C$1 );
					__builtin_memset( &TMP$129$5, 0, 24ll );
					FBSTRING* vr$61 = fb_StrConcat( &TMP$129$5, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$54, -1ll );
					fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$61, -1ll, 0 );
					S$1 = (uint8*)((uint8*)S$1 + 1ll);
					if( C$1 != 34ull) goto label$619;
					{
						FBSTRING TMP$130$6;
						C$1 = (uint64)*S$1;
						if( C$1 == 34ull) goto label$621;
						{
							goto label$614;
						}
						label$621:;
						label$620:;
						FBSTRING* vr$69 = fb_CHR( 1, (int64)C$1 );
						__builtin_memset( &TMP$130$6, 0, 24ll );
						FBSTRING* vr$76 = fb_StrConcat( &TMP$130$6, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$69, -1ll );
						fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$76, -1ll, 0 );
						S$1 = (uint8*)((uint8*)S$1 + 1ll);
					}
					goto label$618;
					label$619:;
					if( C$1 != 92ull) goto label$622;
					{
						C$1 = (uint64)*S$1;
						{
							if( C$1 == 34ull) goto label$625;
							label$626:;
							if( C$1 != 92ull) goto label$624;
							label$625:;
							{
								FBSTRING TMP$131$8;
								FBSTRING* vr$84 = fb_CHR( 1, (int64)C$1 );
								__builtin_memset( &TMP$131$8, 0, 24ll );
								FBSTRING* vr$91 = fb_StrConcat( &TMP$131$8, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$84, -1ll );
								fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$91, -1ll, 0 );
								S$1 = (uint8*)((uint8*)S$1 + 1ll);
							}
							label$624:;
							label$623:;
						}
					}
					label$622:;
					label$618:;
				}
				label$615:;
				goto label$613;
				label$614:;
				goto label$588;
			}
			goto label$589;
			label$605:;
			if( C$1 != 47ull) goto label$627;
			label$628:;
			{
				FBSTRING TMP$132$4;
				FBSTRING TMP$133$4;
				FBSTRING* vr$97 = fb_CHR( 1, (int64)C$1 );
				__builtin_memset( &TMP$132$4, 0, 24ll );
				FBSTRING* vr$104 = fb_StrConcat( &TMP$132$4, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$97, -1ll );
				fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$104, -1ll, 0 );
				S$1 = (uint8*)((uint8*)S$1 + 1ll);
				C$1 = (uint64)*S$1;
				if( C$1 == 39ull) goto label$630;
				{
					goto label$588;
				}
				label$630:;
				label$629:;
				FBSTRING* vr$112 = fb_CHR( 1, (int64)C$1 );
				__builtin_memset( &TMP$133$4, 0, 24ll );
				FBSTRING* vr$119 = fb_StrConcat( &TMP$133$4, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$112, -1ll );
				fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$119, -1ll, 0 );
				S$1 = (uint8*)((uint8*)S$1 + 1ll);
				label$631:;
				{
					FBSTRING TMP$134$5;
					C$1 = (uint64)*S$1;
					if( C$1 != 0ull) goto label$635;
					{
						goto label$632;
					}
					label$635:;
					label$634:;
					FBSTRING* vr$127 = fb_CHR( 1, (int64)C$1 );
					__builtin_memset( &TMP$134$5, 0, 24ll );
					FBSTRING* vr$134 = fb_StrConcat( &TMP$134$5, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$127, -1ll );
					fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$134, -1ll, 0 );
					S$1 = (uint8*)((uint8*)S$1 + 1ll);
					if( C$1 != 39ull) goto label$637;
					{
						C$1 = (uint64)*S$1;
						if( C$1 != 47ull) goto label$639;
						{
							FBSTRING TMP$135$7;
							FBSTRING* vr$142 = fb_CHR( 1, (int64)C$1 );
							__builtin_memset( &TMP$135$7, 0, 24ll );
							FBSTRING* vr$149 = fb_StrConcat( &TMP$135$7, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$142, -1ll );
							fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$149, -1ll, 0 );
							S$1 = (uint8*)((uint8*)S$1 + 1ll);
							goto label$632;
						}
						label$639:;
						label$638:;
					}
					label$637:;
					label$636:;
				}
				label$633:;
				goto label$631;
				label$632:;
				goto label$588;
			}
			goto label$589;
			label$627:;
			if( C$1 != 39ull) goto label$640;
			label$641:;
			{
				label$642:;
				if( C$1 == 0ull) goto label$643;
				{
					FBSTRING TMP$136$5;
					FBSTRING* vr$155 = fb_CHR( 1, (int64)C$1 );
					__builtin_memset( &TMP$136$5, 0, 24ll );
					FBSTRING* vr$162 = fb_StrConcat( &TMP$136$5, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$155, -1ll );
					fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$162, -1ll, 0 );
					S$1 = (uint8*)((uint8*)S$1 + 1ll);
					C$1 = (uint64)*S$1;
				}
				goto label$642;
				label$643:;
				goto label$587;
			}
			label$640:;
			label$589:;
		}
		FBSTRING* vr$170 = fb_CHR( 1, (int64)C$1 );
		__builtin_memset( &TMP$137$2, 0, 24ll );
		FBSTRING* vr$177 = fb_StrConcat( &TMP$137$2, (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$170, -1ll );
		fb_StrAssign( (void*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), -1ll, (void*)vr$177, -1ll, 0 );
		S$1 = (uint8*)((uint8*)S$1 + 1ll);
	}
	label$588:;
	goto label$586;
	label$587:;
	fb$result$1 = T$1;
	label$575:;
	return fb$result$1;
}

int64 HWSTR2ARGS( uint16* TXT$1, struct $7FBARRAYI8DWSTRINGE* RES$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$644:;
	int64 T$1;
	T$1 = 0ll;
	uint16* S$1;
	S$1 = (uint16*)TXT$1;
	int64 PRNTCNT$1;
	PRNTCNT$1 = 0ll;
	uint64 C$1;
	C$1 = 0ull;
	int64 MAX_T$1;
	MAX_T$1 = 10ll;
	if( TXT$1 != (uint16*)0ull) goto label$647;
	{
		fb$result$1 = 0ll;
		goto label$645;
	}
	label$647:;
	label$646:;
	int32 vr$2 = fb_ArrayRedimEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, 0, 1ull, 0ll, MAX_T$1 + -1ll );
	if( (int64)vr$2 == 0ll) goto label$648;
	void* vr$4 = fb_ErrorThrowAt( 1818, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
	goto *vr$4;
	label$648:;
	label$649:;
	{
		C$1 = (uint64)*S$1;
		if( ((int64)-(C$1 == 9ull) | (int64)-(C$1 == 32ull)) == 0ll) goto label$653;
		{
			S$1 = (uint16*)((uint8*)S$1 + 2ll);
		}
		goto label$652;
		label$653:;
		{
			goto label$650;
		}
		label$652:;
	}
	label$651:;
	goto label$649;
	label$650:;
	if( C$1 != 0ull) goto label$655;
	{
		fb$result$1 = 0ll;
		goto label$645;
	}
	label$655:;
	label$654:;
	T$1 = T$1 + 1ll;
	label$656:;
	{
		uint16* TMP$148$2;
		C$1 = (uint64)*S$1;
		{
			if( C$1 != 0ull) goto label$660;
			label$661:;
			{
				goto label$657;
			}
			goto label$659;
			label$660:;
			if( C$1 != 40ull) goto label$662;
			label$663:;
			{
				PRNTCNT$1 = PRNTCNT$1 + 1ll;
			}
			goto label$659;
			label$662:;
			if( C$1 != 41ull) goto label$664;
			label$665:;
			{
				if( PRNTCNT$1 <= 0ll) goto label$667;
				{
					PRNTCNT$1 = PRNTCNT$1 + -1ll;
				}
				label$667:;
				label$666:;
			}
			goto label$659;
			label$664:;
			if( C$1 != 44ull) goto label$668;
			label$669:;
			{
				if( PRNTCNT$1 != 0ll) goto label$671;
				{
					T$1 = T$1 + 1ll;
					if( T$1 <= MAX_T$1) goto label$673;
					{
						MAX_T$1 = MAX_T$1 + 10ll;
						int32 vr$19 = fb_ArrayRedimPresvEx( (struct $7FBARRAYIvE*)RES$1, 24ull, -1, 0, 1ull, 0ll, MAX_T$1 + -1ll );
						if( (int64)vr$19 == 0ll) goto label$674;
						void* vr$21 = fb_ErrorThrowAt( 1857, (char*)"hlp-str.bas", (void*)0ull, (void*)0ull );
						goto *vr$21;
						label$674:;
					}
					label$673:;
					label$672:;
					S$1 = (uint16*)((uint8*)S$1 + 2ll);
					goto label$658;
				}
				label$671:;
				label$670:;
			}
			goto label$659;
			label$668:;
			if( C$1 == 34ull) goto label$676;
			label$677:;
			if( C$1 == 33ull) goto label$676;
			label$678:;
			if( C$1 != 36ull) goto label$675;
			label$676:;
			{
				uint16* TMP$139$4;
				int64 ESCAPED$4;
				ESCAPED$4 = *(int64*)((uint8*)&ENV$ + 1560ll);
				if( C$1 == 34ull) goto label$680;
				{
					uint16* TMP$138$5;
					ESCAPED$4 = (int64)-(C$1 == 33ull);
					uint16* vr$24 = fb_WstrChr( 1, (int64)C$1 );
					TMP$138$5 = vr$24;
					DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$138$5 );
					fb_WstrDelete( (uint16*)TMP$138$5 );
					S$1 = (uint16*)((uint8*)S$1 + 2ll);
					C$1 = (uint64)*S$1;
					if( C$1 == 34ull) goto label$682;
					{
						goto label$658;
					}
					label$682:;
					label$681:;
				}
				label$680:;
				label$679:;
				uint16* vr$32 = fb_WstrChr( 1, (int64)C$1 );
				TMP$139$4 = vr$32;
				DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$139$4 );
				fb_WstrDelete( (uint16*)TMP$139$4 );
				S$1 = (uint16*)((uint8*)S$1 + 2ll);
				label$683:;
				{
					uint16* TMP$140$5;
					C$1 = (uint64)*S$1;
					if( C$1 != 0ull) goto label$687;
					{
						goto label$684;
					}
					label$687:;
					label$686:;
					uint16* vr$40 = fb_WstrChr( 1, (int64)C$1 );
					TMP$140$5 = vr$40;
					DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$140$5 );
					fb_WstrDelete( (uint16*)TMP$140$5 );
					S$1 = (uint16*)((uint8*)S$1 + 2ll);
					if( C$1 != 34ull) goto label$689;
					{
						uint16* TMP$141$6;
						C$1 = (uint64)*S$1;
						if( C$1 == 34ull) goto label$691;
						{
							goto label$684;
						}
						label$691:;
						label$690:;
						uint16* vr$48 = fb_WstrChr( 1, (int64)C$1 );
						TMP$141$6 = vr$48;
						DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$141$6 );
						fb_WstrDelete( (uint16*)TMP$141$6 );
						S$1 = (uint16*)((uint8*)S$1 + 2ll);
					}
					goto label$688;
					label$689:;
					if( C$1 != 92ull) goto label$692;
					{
						C$1 = (uint64)*S$1;
						{
							if( C$1 == 34ull) goto label$695;
							label$696:;
							if( C$1 != 92ull) goto label$694;
							label$695:;
							{
								uint16* TMP$142$8;
								uint16* vr$56 = fb_WstrChr( 1, (int64)C$1 );
								TMP$142$8 = vr$56;
								DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$142$8 );
								fb_WstrDelete( (uint16*)TMP$142$8 );
								S$1 = (uint16*)((uint8*)S$1 + 2ll);
							}
							label$694:;
							label$693:;
						}
					}
					label$692:;
					label$688:;
				}
				label$685:;
				goto label$683;
				label$684:;
				goto label$658;
			}
			goto label$659;
			label$675:;
			if( C$1 != 47ull) goto label$697;
			label$698:;
			{
				uint16* TMP$143$4;
				uint16* TMP$144$4;
				uint16* vr$62 = fb_WstrChr( 1, (int64)C$1 );
				TMP$143$4 = vr$62;
				DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$143$4 );
				fb_WstrDelete( (uint16*)TMP$143$4 );
				S$1 = (uint16*)((uint8*)S$1 + 2ll);
				C$1 = (uint64)*S$1;
				if( C$1 == 39ull) goto label$700;
				{
					goto label$658;
				}
				label$700:;
				label$699:;
				uint16* vr$70 = fb_WstrChr( 1, (int64)C$1 );
				TMP$144$4 = vr$70;
				DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$144$4 );
				fb_WstrDelete( (uint16*)TMP$144$4 );
				S$1 = (uint16*)((uint8*)S$1 + 2ll);
				label$701:;
				{
					uint16* TMP$145$5;
					C$1 = (uint64)*S$1;
					if( C$1 != 0ull) goto label$705;
					{
						goto label$702;
					}
					label$705:;
					label$704:;
					uint16* vr$78 = fb_WstrChr( 1, (int64)C$1 );
					TMP$145$5 = vr$78;
					DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$145$5 );
					fb_WstrDelete( (uint16*)TMP$145$5 );
					S$1 = (uint16*)((uint8*)S$1 + 2ll);
					if( C$1 != 39ull) goto label$707;
					{
						C$1 = (uint64)*S$1;
						if( C$1 != 47ull) goto label$709;
						{
							uint16* TMP$146$7;
							uint16* vr$86 = fb_WstrChr( 1, (int64)C$1 );
							TMP$146$7 = vr$86;
							DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$146$7 );
							fb_WstrDelete( (uint16*)TMP$146$7 );
							S$1 = (uint16*)((uint8*)S$1 + 2ll);
							goto label$702;
						}
						label$709:;
						label$708:;
					}
					label$707:;
					label$706:;
				}
				label$703:;
				goto label$701;
				label$702:;
				goto label$658;
			}
			goto label$659;
			label$697:;
			if( C$1 != 39ull) goto label$710;
			label$711:;
			{
				label$712:;
				if( C$1 == 0ull) goto label$713;
				{
					uint16* TMP$147$5;
					uint16* vr$92 = fb_WstrChr( 1, (int64)C$1 );
					TMP$147$5 = vr$92;
					DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$147$5 );
					fb_WstrDelete( (uint16*)TMP$147$5 );
					S$1 = (uint16*)((uint8*)S$1 + 2ll);
					C$1 = (uint64)*S$1;
				}
				goto label$712;
				label$713:;
				goto label$657;
			}
			label$710:;
			label$659:;
		}
		uint16* vr$100 = fb_WstrChr( 1, (int64)C$1 );
		TMP$148$2 = vr$100;
		DWSTRCONCATASSIGN( (struct $8DWSTRING*)((uint8*)((T$1 * 24ll) + *(int64*)RES$1) + -24ll), (uint16*)TMP$148$2 );
		fb_WstrDelete( (uint16*)TMP$148$2 );
		S$1 = (uint16*)((uint8*)S$1 + 2ll);
	}
	label$658:;
	goto label$656;
	label$657:;
	fb$result$1 = T$1;
	label$645:;
	return fb$result$1;
}

static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM* THIS$1, struct $11TSTRSETITEM* __FB_RHS__$1 )
{
	label$4:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 24ll) = *(int64*)((uint8*)__FB_RHS__$1 + 24ll);
	*(struct $8HASHITEM**)((uint8*)THIS$1 + 32ll) = *(struct $8HASHITEM**)((uint8*)__FB_RHS__$1 + 32ll);
	label$5:;
}

static int64 HREMAPCHAR( int64 CHAR$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$132:;
	{
		uint64 TMP$90$2;
		TMP$90$2 = (uint64)CHAR$1;
		goto label$135;
		label$136:;
		{
			fb$result$1 = 13ll;
		}
		goto label$134;
		label$137:;
		{
			fb$result$1 = 10ll;
		}
		goto label$134;
		label$138:;
		{
			fb$result$1 = 9ll;
		}
		goto label$134;
		label$139:;
		{
			fb$result$1 = 8ll;
		}
		goto label$134;
		label$140:;
		{
			fb$result$1 = 7ll;
		}
		goto label$134;
		label$141:;
		{
			fb$result$1 = 12ll;
		}
		goto label$134;
		label$142:;
		{
			fb$result$1 = 11ll;
		}
		goto label$134;
		label$143:;
		{
			fb$result$1 = CHAR$1;
		}
		goto label$134;
		label$135:;
		static const void* tmp$149[22ll] = {
			&&label$140,
			&&label$139,
			&&label$143,
			&&label$143,
			&&label$143,
			&&label$141,
			&&label$143,
			&&label$143,
			&&label$143,
			&&label$143,
			&&label$143,
			&&label$137,
			&&label$143,
			&&label$137,
			&&label$143,
			&&label$143,
			&&label$143,
			&&label$136,
			&&label$143,
			&&label$138,
			&&label$143,
			&&label$142,
		};
		if( (TMP$90$2 - 97ull) > 21ull ) goto label$143;
		goto *tmp$149[TMP$90$2 - 97ull];
		label$134:;
	}
	label$133:;
	return fb$result$1;
}

static int64 HHEXCHAR( int64 VALUE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$144:;
	VALUE$1 = VALUE$1 & 15ll;
	VALUE$1 = VALUE$1 + 48ll;
	if( VALUE$1 <= 57ll) goto label$147;
	{
		VALUE$1 = VALUE$1 + 7ll;
	}
	label$147:;
	label$146:;
	fb$result$1 = VALUE$1;
	label$145:;
	return fb$result$1;
}

static uint64 HUNICODEHEXTOCODEPOINTW( uint16** SRC$1, int64 DIGITS$1 )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$148:;
	static uint64 CHAR$1;
	static uint64 C$1;
	static int64 I$1;
	CHAR$1 = 0ull;
	{
		I$1 = 1ll;
		int64 TMP$99$2;
		TMP$99$2 = DIGITS$1;
		goto label$150;
		label$153:;
		{
			C$1 = (uint64)((int64)*(*SRC$1) + -48ll);
			*SRC$1 = (uint16*)((uint8*)*SRC$1 + 2ll);
			if( C$1 <= 9ull) goto label$155;
			{
				C$1 = C$1 + 18446744073709551609ull;
			}
			label$155:;
			label$154:;
			if( C$1 <= 16ull) goto label$157;
			{
				C$1 = C$1 + 18446744073709551584ull;
			}
			label$157:;
			label$156:;
			CHAR$1 = (CHAR$1 << (4ull & 63ll)) | C$1;
		}
		label$151:;
		I$1 = I$1 + 1ll;
		label$150:;
		if( I$1 <= TMP$99$2) goto label$153;
		label$152:;
	}
	fb$result$1 = CHAR$1;
	label$149:;
	return fb$result$1;
}

static void HUNICODECODEPOINTCHARTOHEX( uint64* CHAR$1, char** DST$1, int64 WCHARLEN$1 )
{
	label$158:;
	int64 I$1;
	uint64 C$1;
	{
		I$1 = 1ll;
		int64 TMP$100$2;
		TMP$100$2 = WCHARLEN$1;
		goto label$160;
		label$163:;
		{
			*(*DST$1) = (uint8)92u;
			*DST$1 = (char*)((uint8*)*DST$1 + 1ll);
			C$1 = *CHAR$1 & 255ull;
			if( C$1 >= 8ull) goto label$165;
			{
				*(*DST$1) = (uint8)(C$1 + 48ull);
				*DST$1 = (char*)((uint8*)*DST$1 + 1ll);
			}
			goto label$164;
			label$165:;
			if( C$1 >= 64ull) goto label$166;
			{
				*(*DST$1) = (uint8)((C$1 >> (3ll & 63ll)) + 48ull);
				*(char*)((uint8*)*DST$1 + 1ll) = (uint8)((C$1 & 7ull) + 48ull);
				*DST$1 = (char*)((uint8*)*DST$1 + 2ll);
			}
			goto label$164;
			label$166:;
			{
				*(*DST$1) = (uint8)((C$1 >> (6ll & 63ll)) + 48ull);
				*(char*)((uint8*)*DST$1 + 1ll) = (uint8)(((C$1 & 56ull) >> (3ll & 63ll)) + 48ull);
				*(char*)((uint8*)*DST$1 + 2ll) = (uint8)((C$1 & 7ull) + 48ull);
				*DST$1 = (char*)((uint8*)*DST$1 + 3ll);
			}
			label$164:;
			*CHAR$1 = *CHAR$1 >> (8ll & 63ll);
		}
		label$161:;
		I$1 = I$1 + 1ll;
		label$160:;
		if( I$1 <= TMP$100$2) goto label$163;
		label$162:;
	}
	label$159:;
}
