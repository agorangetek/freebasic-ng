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
typedef int64 $12FB_SYMBCLASS;
typedef int64 $13FB_SYMBATTRIB;
typedef int64 $13FB_PROCATTRIB;
typedef int64 $12FB_SYMBSTATS;
struct $9FB_SYMBID {
	char* NAME;
	char* ALIAS;
	char* MANGLED;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
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
struct $8HASHITEM;
struct $8HASHITEM {
	char* NAME;
	void* DATA;
	struct $8HASHITEM* PREV;
	struct $8HASHITEM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $8HASHITEM ) == 32 );
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
struct $10FBSYMCHAIN {
	struct $8FBSYMBOL* SYM;
	struct $10FBSYMCHAIN* NEXT;
	int64 ISIMPORT;
	struct $10FBSYMCHAIN* PREV;
	struct $8HASHITEM* ITEM;
	struct $10FBSYMCHAIN* IMP_NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $10FBSYMCHAIN ) == 48 );
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
typedef int64 $8LEXCHECK;
typedef int64 $8FB_TOKEN;
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
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
int32 fb_FileGetStrLarge( int32, int64, void*, int64 );
int64 fb_FileTell( int32 );
int32 fb_FileSeekLarge( int32, int64 );
int32 fb_FileEof( int32 );
void fb_PrintString( int32, FBSTRING*, int32 );
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
FBSTRING* fb_WstrToStr( uint32* );
FBSTRING* fb_StrMid( FBSTRING*, int64, int64 );
int64 fb_StrLen( void*, int64 );
FBSTRING* fb_CHR( int32, ... );
FBSTRING* fb_LEFT( FBSTRING*, int64 );
FBSTRING* fb_StrUcase2( FBSTRING*, int32 );
static void fb_ctor__lex( void ) __attribute__(( constructor ));
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
void ERRREPORTWARN( int64, char*, $12FB_ERRMSGOPT, char* );
struct $10FBSYMCHAIN* SYMBLOOKUP( char*, $8FB_TOKEN*, $10FB_TKCLASS* );
struct $10FBSYMCHAIN* SYMBLOOKUPAT( struct $8FBSYMBOL*, char*, int64, int64 );
int64 TYPETOUNSIGNED( int64 );
void DZSTRALLOCATE( struct $8DZSTRING*, int64 );
void DZSTRCONCATASSIGN( struct $8DZSTRING*, char* );
void DZSTRCONCATASSIGNC( struct $8DZSTRING*, uint64 );
void DWSTRALLOCATE( struct $8DWSTRING*, int64 );
int64 LEXGETTOKEN( $8LEXCHECK );
int64 LEXGETCLASS( $8LEXCHECK );
char* LEXGETTEXT( void );
void LEXPPONLYEMITTOKEN( void );
void LEXSKIPTOKEN( $8LEXCHECK );
void LEXREADLINE( uint64, char*, int64 );
void LEXNEXTTOKEN( struct $7FBTOKEN*, $8LEXCHECK );
uint64 LEXCURRENTCHAR( void );
uint64 LEXGETLOOKAHEADCHAR( void );
uint64 LEXGETLOOKAHEADCHAR2( void );
void LEXEATCHAR( void );
void LEXCHECKTOKEN( $8LEXCHECK );
void PPINIT( void );
void PPEND( void );
void PPCHECK( void );
int64 PPDEFINELOAD( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
void LEXREADUTF8( void );
void LEXREADUTF16LE( void );
void LEXREADUTF16BE( void );
void LEXREADUTF32LE( void );
void LEXREADUTF32BE( void );
static void HMULTILINECOMMENT( void );
static void HSKIPCHAR( void );
static void HCOLLECTCHARFORDEBUGOUTPUT( uint64 );
static uint64 HREADCHAR( void );
static void HREADIDENTIFIER( char*, int64*, int64*, int64*, $8LEXCHECK );
static uint64 HREADNONDECNUMBER( char**, int64*, int64*, $8LEXCHECK );
static void HREADFLOATNUMBER( char**, struct $7FBTOKEN*, int64, $8LEXCHECK );
static void READNUMBERCHARS( struct $7FBTOKEN*, $8LEXCHECK*, char**, int64*, uint64* );
static void HREADNUMBER( struct $7FBTOKEN*, $8LEXCHECK );
static void HREADSTRING( struct $7FBTOKEN*, char*, $8LEXCHECK );
static void HREADWSTR( struct $7FBTOKEN*, uint32*, $8LEXCHECK );
static void HCHECKPERIODS( struct $7FBTOKEN*, $8LEXCHECK, struct $10FBSYMCHAIN* );
static int64 READID( struct $7FBTOKEN*, $8LEXCHECK );
static void HMOVEKDOWN( void );
static FBSTRING* LEXGETSTRLITTEXT( int64 );
typedef int64 $11AST_OPFLAGS;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
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
typedef int64 $15FB_CMPSTMT_MASK;
struct $17FB_CMPSTMT_FORELM {
	struct $8FBSYMBOL* SYM;
	union $7FBVALUE VALUE;
	int64 DTYPE;
};
__FB_STATIC_ASSERT( sizeof( struct $17FB_CMPSTMT_FORELM ) == 24 );
struct $13FB_CMPSTMTSTK;
struct $14FB_CMPSTMT_FOR {
	struct $7ASTNODE* OUTERSCOPENODE;
	struct $17FB_CMPSTMT_FORELM CNT;
	struct $17FB_CMPSTMT_FORELM END;
	struct $17FB_CMPSTMT_FORELM STP;
	struct $17FB_CMPSTMT_FORELM ISPOS;
	struct $8FBSYMBOL* TESTLABEL;
	struct $8FBSYMBOL* INILABEL;
	struct $8FBSYMBOL* CMPLABEL;
	struct $8FBSYMBOL* ENDLABEL;
	struct $13FB_CMPSTMTSTK* LAST;
	int64 EXPLICIT_STEP;
};
__FB_STATIC_ASSERT( sizeof( struct $14FB_CMPSTMT_FOR ) == 152 );
struct $13FB_CMPSTMT_DO {
	int64 ATTOP;
	struct $8FBSYMBOL* INILABEL;
	struct $8FBSYMBOL* CMPLABEL;
	struct $8FBSYMBOL* ENDLABEL;
	struct $13FB_CMPSTMTSTK* LAST;
};
__FB_STATIC_ASSERT( sizeof( struct $13FB_CMPSTMT_DO ) == 40 );
struct $16FB_CMPSTMT_WHILE {
	struct $8FBSYMBOL* CMPLABEL;
	struct $8FBSYMBOL* ENDLABEL;
	struct $13FB_CMPSTMTSTK* LAST;
};
__FB_STATIC_ASSERT( sizeof( struct $16FB_CMPSTMT_WHILE ) == 24 );
struct $13FB_CMPSTMT_IF {
	int64 ISSINGLE;
	struct $8FBSYMBOL* NXTLABEL;
	struct $8FBSYMBOL* ENDLABEL;
	int64 ELSECNT;
};
__FB_STATIC_ASSERT( sizeof( struct $13FB_CMPSTMT_IF ) == 32 );
struct $15FB_CMPSTMT_PROC {
	$8FB_TOKEN TKN;
	int64 IS_NESTED;
	struct $8FBSYMBOL* ENDLABEL;
	struct $13FB_CMPSTMTSTK* LAST;
};
__FB_STATIC_ASSERT( sizeof( struct $15FB_CMPSTMT_PROC ) == 32 );
struct $19FB_CMPSTMT_SELCONST {
	int64 BASE;
	struct $8FBSYMBOL* DEFLABEL;
	int64 DTYPE;
	uint64 BIAS;
};
__FB_STATIC_ASSERT( sizeof( struct $19FB_CMPSTMT_SELCONST ) == 32 );
struct $17FB_CMPSTMT_SELECT {
	int64 ISCONST;
	struct $8FBSYMBOL* SYM;
	int64 CASECNT;
	struct $19FB_CMPSTMT_SELCONST CONST_;
	struct $8FBSYMBOL* CMPLABEL;
	struct $8FBSYMBOL* ENDLABEL;
	struct $13FB_CMPSTMTSTK* LAST;
	struct $7ASTNODE* OUTERSCOPENODE;
};
__FB_STATIC_ASSERT( sizeof( struct $17FB_CMPSTMT_SELECT ) == 88 );
struct $15FB_CMPSTMT_WITH {
	struct $8FBSYMBOL* SYM;
	int64 IS_PTR;
	struct $13FB_CMPSTMTSTK* LAST;
};
__FB_STATIC_ASSERT( sizeof( struct $15FB_CMPSTMT_WITH ) == 24 );
struct $20FB_CMPSTMT_NAMESPACE {
	struct $8FBSYMBOL* SYM;
	int64 LEVELS;
};
__FB_STATIC_ASSERT( sizeof( struct $20FB_CMPSTMT_NAMESPACE ) == 16 );
typedef int64 $11FB_MANGLING;
struct $17FB_CMPSTMT_EXTERN {
	$11FB_MANGLING LASTMANG;
};
__FB_STATIC_ASSERT( sizeof( struct $17FB_CMPSTMT_EXTERN ) == 8 );
struct $16FB_CMPSTMT_SCOPE {
	int64 LASTIS_SCOPE;
};
__FB_STATIC_ASSERT( sizeof( struct $16FB_CMPSTMT_SCOPE ) == 8 );
struct $13FB_CMPSTMTSTK {
	int64 ID;
	$15FB_CMPSTMT_MASK ALLOWMASK;
	struct $7ASTNODE* SCOPENODE;
	union {
		struct $14FB_CMPSTMT_FOR FOR;
		struct $13FB_CMPSTMT_DO DO;
		struct $16FB_CMPSTMT_WHILE WHILE;
		struct $13FB_CMPSTMT_IF IF;
		struct $15FB_CMPSTMT_PROC PROC;
		struct $17FB_CMPSTMT_SELECT SELECT;
		struct $15FB_CMPSTMT_WITH WITH;
		struct $20FB_CMPSTMT_NAMESPACE NSPC;
		struct $17FB_CMPSTMT_EXTERN EXT;
		struct $16FB_CMPSTMT_SCOPE SCP;
	};
};
__FB_STATIC_ASSERT( sizeof( struct $13FB_CMPSTMTSTK ) == 176 );
struct $17FBPARSER_STMT_LET {
	struct $5TLIST LIST;
};
__FB_STATIC_ASSERT( sizeof( struct $17FBPARSER_STMT_LET ) == 64 );
struct $13FBPARSER_STMT {
	struct $6TSTACK STK;
	$8FB_TOKEN ID;
	int64 CNT;
	struct $13FB_CMPSTMTSTK* FOR;
	struct $13FB_CMPSTMTSTK* DO;
	struct $13FB_CMPSTMTSTK* WHILE;
	struct $13FB_CMPSTMTSTK* SELECT;
	struct $13FB_CMPSTMTSTK* PROC;
	struct $13FB_CMPSTMTSTK* WITH;
	struct $17FBPARSER_STMT_LET LET;
};
__FB_STATIC_ASSERT( sizeof( struct $13FBPARSER_STMT ) == 176 );
typedef int64 $12FB_PARSEROPT;
struct $9PARSERCTX {
	struct $13FBPARSER_STMT STMT;
	int64 NSPCREC;
	struct $10FBSYMCHAIN* NSPREFIX;
	uint64 STAGE;
	uint64 SCOPE;
	$11FB_MANGLING MANGLING;
	struct $8FBSYMBOL* CURRPROC;
	struct $8FBSYMBOL* CURRBLOCK;
	struct $5TLIST OVLARGLIST;
	int64 PRNTCNT;
	$12FB_PARSEROPT OPTIONS;
	int64 CTX_DTYPE;
	struct $8FBSYMBOL* CTXSYM;
	int64 HAVE_EQ_OUTSIDE_PARENS;
};
__FB_STATIC_ASSERT( sizeof( struct $9PARSERCTX ) == 336 );
extern struct $9PARSERCTX PARSER$;
static FBSTRING PPONLY_LN$;
struct $7LEX_CTX LEX$;

void LEXPUSHCTX( void )
{
	label$10:;
	*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) = (struct $9LEX_TKCTX*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49688ll);
	label$11:;
}

void LEXPOPCTX( void )
{
	label$12:;
	if( *(int64*)((uint8*)&ENV$ + 1296ll) != 0ll) goto label$15;
	{
		DZSTRALLOCATE( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll), 0ll );
	}
	label$15:;
	label$14:;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$17;
	{
		DZSTRALLOCATE( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), 0ll );
	}
	goto label$16;
	label$17:;
	{
		DWSTRALLOCATE( (struct $8DWSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), 0ll );
	}
	label$16:;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16792ll) == 1ll) goto label$19;
	{
		if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -40ll) <= 0ll) goto label$21;
		{
			if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -40ll) == *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49648ll)) goto label$23;
			{
				fb_FileSeekLarge( (int32)*(int64*)((uint8*)&ENV$ + 624ll), *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -40ll) );
			}
			label$23:;
			label$22:;
		}
		label$21:;
		label$20:;
	}
	label$19:;
	label$18:;
	*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) = (struct $9LEX_TKCTX*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -49688ll);
	label$13:;
}

void LEXINIT( $17LEX_TKCTX_CONTEXT CTX_KIND$1 )
{
	label$24:;
	int64 I$1;
	__builtin_memset( &I$1, 0, 8ll );
	struct $7FBTOKEN* N$1;
	__builtin_memset( &N$1, 0, 8ll );
	if( ((int64)-(*(int64*)((uint8*)&ENV$ + 1296ll) == 0ll) & (int64)-(CTX_KIND$1 == 0ll)) == 0ll) goto label$27;
	{
		*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) = (struct $9LEX_TKCTX*)&LEX$;
	}
	label$27:;
	label$26:;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) = 0ll;
	*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = (struct $7FBTOKEN*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll);
	*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) = *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
	N$1 = *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
	{
		I$1 = 0ll;
		label$31:;
		{
			*(struct $7FBTOKEN**)((uint8*)N$1 + 4168ll) = (struct $7FBTOKEN*)((uint8*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + (I$1 * 4176ll)) + 4176ll);
			N$1 = *(struct $7FBTOKEN**)((uint8*)N$1 + 4168ll);
		}
		label$29:;
		I$1 = I$1 + 1ll;
		label$28:;
		if( I$1 <= 2ll) goto label$31;
		label$30:;
	}
	*(struct $7FBTOKEN**)((uint8*)N$1 + 4168ll) = *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
	{
		I$1 = 0ll;
		label$35:;
		{
			*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + (I$1 * 4176ll)) = -1ll;
		}
		label$33:;
		I$1 = I$1 + 1ll;
		label$32:;
		if( I$1 <= 3ll) goto label$35;
		label$34:;
	}
	*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = 18446744073709551615ull;
	*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) = 18446744073709551615ull;
	*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll) = 18446744073709551615ull;
	*($17LEX_TKCTX_CONTEXT*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16792ll) = CTX_KIND$1;
	if( CTX_KIND$1 != 2ll) goto label$37;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -32936ll);
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -32920ll);
		*(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16776ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -32912ll);
	}
	goto label$36;
	label$37:;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = 1ll;
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = 0ll;
		*(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16776ll) = (struct $8FBSYMBOL*)0ull;
	}
	label$36:;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16760ll) = -1ll;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) = 0ll;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = 0ll;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$39;
	{
		char* TMP$95$2;
		if( CTX_KIND$1 != 2ll) goto label$40;
		TMP$95$2 = (char*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16856ll);
		goto label$47;
		label$40:;
		TMP$95$2 = (char*)0ull;
		label$47:;
		*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) = TMP$95$2;
		*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = (char*)0ull;
		DZSTRALLOCATE( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), 0ll );
	}
	goto label$38;
	label$39:;
	{
		*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) = (uint32*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16856ll);
		*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = (uint32*)0ull;
		DWSTRALLOCATE( (struct $8DWSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), 0ll );
	}
	label$38:;
	if( CTX_KIND$1 != 2ll) goto label$42;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49632ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -56ll);
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49640ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -48ll);
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49648ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -40ll);
	}
	goto label$41;
	label$42:;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49632ll) = 0ll;
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49640ll) = 0ll;
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49648ll) = 0ll;
	}
	label$41:;
	if( ((int64)-(*(int64*)((uint8*)&ENV$ + 1296ll) == 0ll) | (int64)-(CTX_KIND$1 == 2ll)) == 0ll) goto label$44;
	{
		DZSTRALLOCATE( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll), 0ll );
		*(int64*)((uint8*)&LEX$ + 844704ll) = 0ll;
	}
	label$44:;
	label$43:;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49680ll) = 0ll;
	if( CTX_KIND$1 != 0ll) goto label$46;
	{
		PPINIT(  );
	}
	label$46:;
	label$45:;
	label$25:;
}

void LEXEND( void )
{
	label$48:;
	fb_StrAssign( (void*)&PPONLY_LN$, -1ll, (void*)"", 1ll, 0 );
	PPEND(  );
	label$49:;
}

void LEXEATCHAR( void )
{
	label$97:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) != 18446744073709551615ull) goto label$100;
	{
		HSKIPCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = 18446744073709551615ull;
	}
	goto label$99;
	label$100:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll) != 18446744073709551615ull) goto label$101;
	{
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll);
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) = 18446744073709551615ull;
	}
	goto label$99;
	label$101:;
	{
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll);
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll);
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll) = 18446744073709551615ull;
	}
	label$99:;
	label$98:;
}

int64 LEXEATWHITESPACE( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$102:;
	fb$result$1 = 0ll;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) != 18446744073709551615ull) goto label$105;
	{
		uint64 vr$2 = HREADCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = vr$2;
	}
	label$105:;
	label$104:;
	label$106:;
	if( ((int64)-(*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) == 9ull) | (int64)-(*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) == 32ull)) == 0ll) goto label$107;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49680ll) = -1ll;
		LEXEATCHAR(  );
		uint64 vr$10 = HREADCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = vr$10;
		fb$result$1 = -1ll;
	}
	goto label$106;
	label$107:;
	label$103:;
	return fb$result$1;
}

uint64 LEXCURRENTCHAR( void )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$119:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) != 18446744073709551615ull) goto label$122;
	{
		uint64 vr$2 = HREADCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) = vr$2;
	}
	label$122:;
	label$121:;
	fb$result$1 = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll);
	label$120:;
	return fb$result$1;
}

uint64 LEXGETLOOKAHEADCHAR( void )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$123:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) != 18446744073709551615ull) goto label$126;
	{
		HSKIPCHAR(  );
		uint64 vr$2 = HREADCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll) = vr$2;
	}
	label$126:;
	label$125:;
	fb$result$1 = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16736ll);
	label$124:;
	return fb$result$1;
}

uint64 LEXGETLOOKAHEADCHAR2( void )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$127:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll) != 18446744073709551615ull) goto label$130;
	{
		HSKIPCHAR(  );
		uint64 vr$2 = HREADCHAR(  );
		*(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll) = vr$2;
	}
	label$130:;
	label$129:;
	fb$result$1 = *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16744ll);
	label$128:;
	return fb$result$1;
}

void LEXNEXTTOKEN( struct $7FBTOKEN* T$1, $8LEXCHECK FLAGS$1 )
{
	label$583:;
	uint64 CHAR$1;
	int64 ISLINECONT$1;
	int64 LGT$1;
	*(int64*)((uint8*)T$1 + 4160ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49680ll);
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49680ll) = 0ll;
	label$585:;
	*(uint8*)((uint8*)T$1 + 24ll) = (uint8)0u;
	*(int64*)((uint8*)T$1 + 4128ll) = 0ll;
	*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) = (struct $10FBSYMCHAIN*)0ull;
	ISLINECONT$1 = 0ll;
	label$586:;
	{
		uint64 vr$6 = LEXCURRENTCHAR(  );
		CHAR$1 = vr$6;
		{
			uint64 TMP$123$3;
			TMP$123$3 = CHAR$1;
			goto label$590;
			label$591:;
			{
				*(int64*)T$1 = 256ll;
				*(int64*)((uint8*)T$1 + 8ll) = 6ll;
				*(int64*)((uint8*)T$1 + 16ll) = 2147483648ll;
				*(int64*)((uint8*)T$1 + 4152ll) = 0ll;
				goto label$584;
			}
			goto label$589;
			label$592:;
			{
				if( ISLINECONT$1 == 0ll) goto label$594;
				{
					LEXEATCHAR(  );
					goto label$588;
				}
				label$594:;
				label$593:;
				if( (FLAGS$1 & 1ll) != 0ll) goto label$596;
				{
					{
						uint64 TMP$124$6;
						uint64 vr$12 = LEXGETLOOKAHEADCHAR(  );
						TMP$124$6 = vr$12;
						goto label$598;
						label$599:;
						{
							goto label$587;
						}
						goto label$597;
						label$600:;
						{
							uint64 vr$13 = LEXGETLOOKAHEADCHAR2(  );
							if( vr$13 != 35ull) goto label$602;
							{
								goto label$587;
							}
							label$602:;
							label$601:;
						}
						goto label$597;
						label$598:;
						static const void* tmp$133[88ll] = {
							&&label$600,
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
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$597,
							&&label$599,
							&&label$597,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
							&&label$599,
						};
						if( (TMP$124$6 - 35ull) > 87ull ) goto label$597;
						goto *tmp$133[TMP$124$6 - 35ull];
						label$597:;
					}
					LEXEATCHAR(  );
					ISLINECONT$1 = -1ll;
					goto label$588;
				}
				goto label$595;
				label$596:;
				{
					goto label$587;
				}
				label$595:;
			}
			goto label$589;
			label$603:;
			{
				LEXEATCHAR(  );
				if( CHAR$1 != 13ull) goto label$605;
				{
					uint64 vr$14 = LEXCURRENTCHAR(  );
					if( vr$14 != 10ull) goto label$607;
					{
						LEXEATCHAR(  );
					}
					label$607:;
					label$606:;
				}
				label$605:;
				label$604:;
				if( ISLINECONT$1 != 0ll) goto label$609;
				{
					*(int64*)T$1 = 257ll;
					*(int64*)((uint8*)T$1 + 8ll) = 6ll;
					*(int64*)((uint8*)T$1 + 16ll) = 2147483648ll;
					*(int64*)((uint8*)T$1 + 4152ll) = 0ll;
					*(int64*)((uint8*)T$1 + 4128ll) = 1ll;
					*(uint8*)((uint8*)T$1 + 24ll) = (uint8)10u;
					*(uint8*)((uint8*)T$1 + 25ll) = (uint8)0u;
					goto label$584;
				}
				goto label$608;
				label$609:;
				{
					*(int64*)((uint8*)T$1 + 4160ll) = -1ll;
					if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) != 0ll) goto label$611;
					{
						*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) + 1ll;
					}
					label$611:;
					label$610:;
					ISLINECONT$1 = 0ll;
					goto label$588;
				}
				label$608:;
			}
			goto label$589;
			label$612:;
			{
				*(int64*)((uint8*)T$1 + 4160ll) = -1ll;
				if( ISLINECONT$1 != 0ll) goto label$614;
				{
					if( (FLAGS$1 & 4ll) == 0ll) goto label$616;
					{
						goto label$587;
					}
					label$616:;
					label$615:;
				}
				label$614:;
				label$613:;
				LEXEATCHAR(  );
			}
			goto label$589;
			label$617:;
			{
				if( ISLINECONT$1 != 0ll) goto label$619;
				{
					goto label$587;
				}
				label$619:;
				label$618:;
				LEXEATCHAR(  );
			}
			goto label$589;
			label$590:;
			static const void* tmp$134[96ll] = {
				&&label$591,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$612,
				&&label$603,
				&&label$617,
				&&label$617,
				&&label$603,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$612,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$617,
				&&label$592,
			};
			if( TMP$123$3 > 95ull ) goto label$617;
			goto *tmp$134[TMP$123$3 - 0ull];
			label$589:;
		}
	}
	label$588:;
	goto label$586;
	label$587:;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49640ll) = (*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49632ll) + (*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) - (int64)(char*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16856ll))) + -1ll;
	{
		uint64 TMP$125$2;
		TMP$125$2 = CHAR$1;
		goto label$621;
		label$622:;
		{
			if( (FLAGS$1 & 9ll) != 0ll) goto label$624;
			{
				uint64 LACHAR$4;
				uint64 vr$38 = LEXGETLOOKAHEADCHAR(  );
				LACHAR$4 = vr$38;
				if( ((int64)-(LACHAR$4 >= 48ull) & (int64)-(LACHAR$4 <= 57ull)) == 0ll) goto label$626;
				{
					HREADNUMBER( T$1, FLAGS$1 );
					goto label$620;
				}
				label$626:;
				label$625:;
			}
			label$624:;
			label$623:;
			goto label$627;
		}
		goto label$620;
		label$628:;
		{
			{
				uint64 TMP$126$4;
				uint64 vr$42 = LEXGETLOOKAHEADCHAR(  );
				TMP$126$4 = vr$42;
				if( TMP$126$4 == 72ull) goto label$631;
				label$632:;
				if( TMP$126$4 == 104ull) goto label$631;
				label$633:;
				if( TMP$126$4 == 79ull) goto label$631;
				label$634:;
				if( TMP$126$4 == 111ull) goto label$631;
				label$635:;
				if( TMP$126$4 == 66ull) goto label$631;
				label$636:;
				if( TMP$126$4 == 98ull) goto label$631;
				label$637:;
				if( TMP$126$4 < 48ull) goto label$630;
				if( TMP$126$4 > 55ull) goto label$630;
				label$631:;
				{
					HREADNUMBER( T$1, FLAGS$1 );
				}
				goto label$629;
				label$630:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 5ll;
					*(int64*)T$1 = 38ll;
					*(int64*)((uint8*)T$1 + 16ll) = *(int64*)T$1;
					*(int64*)((uint8*)T$1 + 4128ll) = 1ll;
					*(uint8*)((uint8*)T$1 + 24ll) = (uint8)38u;
					*(uint8*)((uint8*)T$1 + 25ll) = (uint8)0u;
					LEXEATCHAR(  );
				}
				label$638:;
				label$629:;
			}
		}
		goto label$620;
		label$639:;
		{
			HREADNUMBER( T$1, FLAGS$1 );
		}
		goto label$620;
		label$640:;
		{
			int64 vr$50 = READID( T$1, FLAGS$1 );
			if( ~vr$50 == 0ll) goto label$642;
			{
				goto label$585;
			}
			label$642:;
			label$641:;
		}
		goto label$620;
		label$643:;
		{
			$8FB_TOKEN TMP$127$3;
			*(int64*)((uint8*)T$1 + 8ll) = 4ll;
			if( *(int64*)((uint8*)&ENV$ + 1560ll) == 0ll) goto label$644;
			TMP$127$3 = 263ll;
			goto label$700;
			label$644:;
			TMP$127$3 = 262ll;
			label$700:;
			*(int64*)T$1 = TMP$127$3;
			*(int64*)((uint8*)T$1 + 16ll) = 2147483648ll;
			if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$646;
			{
				HREADSTRING( T$1, (char*)((uint8*)T$1 + 24ll), FLAGS$1 );
			}
			goto label$645;
			label$646:;
			{
				HREADWSTR( T$1, (uint32*)((uint8*)T$1 + 24ll), FLAGS$1 );
			}
			label$645:;
		}
		goto label$620;
		label$647:;
		{
			$8FB_TOKEN TMP$128$3;
			uint64 vr$59 = LEXGETLOOKAHEADCHAR(  );
			if( vr$59 == 34ull) goto label$649;
			{
				goto label$627;
			}
			label$649:;
			label$648:;
			LEXEATCHAR(  );
			*(int64*)((uint8*)T$1 + 8ll) = 4ll;
			if( CHAR$1 != 33ull) goto label$650;
			TMP$128$3 = 263ll;
			goto label$701;
			label$650:;
			TMP$128$3 = 264ll;
			label$701:;
			*(int64*)T$1 = TMP$128$3;
			*(int64*)((uint8*)T$1 + 16ll) = 2147483648ll;
			if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$652;
			{
				char* PS$4;
				if( (FLAGS$1 & 16ll) != 0ll) goto label$654;
				{
					PS$4 = (char*)((uint8*)T$1 + 24ll);
				}
				goto label$653;
				label$654:;
				{
					*(uint8*)((uint8*)T$1 + 24ll) = (uint8)CHAR$1;
					PS$4 = (char*)((uint8*)T$1 + 25ll);
				}
				label$653:;
				HREADSTRING( T$1, PS$4, FLAGS$1 );
			}
			goto label$651;
			label$652:;
			{
				uint32* PS$4;
				if( (FLAGS$1 & 16ll) != 0ll) goto label$656;
				{
					PS$4 = (uint32*)((uint8*)T$1 + 24ll);
				}
				goto label$655;
				label$656:;
				{
					*(uint32*)((uint8*)T$1 + 24ll) = (uint32)CHAR$1;
					PS$4 = (uint32*)((uint8*)T$1 + 28ll);
				}
				label$655:;
				HREADWSTR( T$1, PS$4, FLAGS$1 );
			}
			label$651:;
		}
		goto label$620;
		label$657:;
		{
			label$627:;
			*(int64*)T$1 = (int64)CHAR$1;
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)T$1;
			*(int64*)((uint8*)T$1 + 4152ll) = 0ll;
			*(int64*)((uint8*)T$1 + 4128ll) = 1ll;
			*(uint8*)((uint8*)T$1 + 24ll) = (uint8)CHAR$1;
			*(uint8*)((uint8*)T$1 + 25ll) = (uint8)0u;
			LEXEATCHAR(  );
			{
				uint64 TMP$129$4;
				TMP$129$4 = CHAR$1;
				goto label$659;
				label$660:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 5ll;
					{
						if( CHAR$1 != 60ull) goto label$662;
						label$663:;
						{
							{
								uint64 TMP$130$8;
								uint64 vr$86 = LEXCURRENTCHAR(  );
								TMP$130$8 = vr$86;
								if( TMP$130$8 != 61ull) goto label$665;
								label$666:;
								{
									*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)61u;
									*(uint8*)((uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) + 1ll) = (uint8)0u;
									*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
									*(int64*)T$1 = 303ll;
									LEXEATCHAR(  );
								}
								goto label$664;
								label$665:;
								if( TMP$130$8 != 62ull) goto label$667;
								label$668:;
								{
									*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)62u;
									*(uint8*)((uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) + 1ll) = (uint8)0u;
									*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
									*(int64*)T$1 = 302ll;
									LEXEATCHAR(  );
								}
								goto label$664;
								label$667:;
								{
									*(int64*)T$1 = 301ll;
								}
								label$669:;
								label$664:;
							}
						}
						goto label$661;
						label$662:;
						if( CHAR$1 != 62ull) goto label$670;
						label$671:;
						{
							int64 TMP$131$7;
							if( (*(int64*)((uint8*)&PARSER$ + 304ll) & 512ll) != 0ll) goto label$672;
							uint64 vr$113 = LEXCURRENTCHAR(  );
							TMP$131$7 = (int64)-(vr$113 == 61ull);
							goto label$702;
							label$672:;
							TMP$131$7 = 0ll;
							label$702:;
							if( TMP$131$7 == 0ll) goto label$674;
							{
								*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)61u;
								*(uint8*)((uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) + 1ll) = (uint8)0u;
								*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
								*(int64*)T$1 = 304ll;
								LEXEATCHAR(  );
							}
							goto label$673;
							label$674:;
							{
								*(int64*)T$1 = 300ll;
							}
							label$673:;
						}
						goto label$661;
						label$670:;
						if( CHAR$1 != 61ull) goto label$675;
						label$676:;
						{
							uint64 vr$128 = LEXCURRENTCHAR(  );
							if( vr$128 != 62ull) goto label$678;
							{
								*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)62u;
								*(uint8*)((uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) + 1ll) = (uint8)0u;
								*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
								*(int64*)T$1 = 305ll;
								LEXEATCHAR(  );
							}
							goto label$677;
							label$678:;
							{
								*(int64*)T$1 = 299ll;
							}
							label$677:;
						}
						label$675:;
						label$661:;
					}
				}
				goto label$658;
				label$679:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 5ll;
				}
				goto label$658;
				label$680:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 5ll;
					uint64 vr$144 = LEXCURRENTCHAR(  );
					if( vr$144 != 62ull) goto label$682;
					{
						*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)62u;
						*(uint8*)((uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) + 1ll) = (uint8)0u;
						*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
						*(int64*)T$1 = 400ll;
						LEXEATCHAR(  );
					}
					label$682:;
					label$681:;
				}
				goto label$658;
				label$683:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 5ll;
					if( (FLAGS$1 & 512ll) != 0ll) goto label$685;
					{
						uint64 vr$159 = LEXCURRENTCHAR(  );
						if( vr$159 != 39ull) goto label$687;
						{
							HMULTILINECOMMENT(  );
							*(int64*)((uint8*)T$1 + 4160ll) = -1ll;
							goto label$585;
						}
						label$687:;
						label$686:;
					}
					label$685:;
					label$684:;
				}
				goto label$658;
				label$688:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 6ll;
					*(int64*)T$1 = 259ll;
				}
				goto label$658;
				label$689:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 6ll;
					*(int64*)T$1 = 258ll;
				}
				goto label$658;
				label$690:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 6ll;
				}
				goto label$658;
				label$691:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 6ll;
					*(int64*)T$1 = 32ll;
					label$692:;
					{
						{
							uint64 TMP$132$7;
							uint64 vr$168 = LEXCURRENTCHAR(  );
							TMP$132$7 = vr$168;
							goto label$696;
							label$697:;
							{
								LEXEATCHAR(  );
								*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)32u;
								*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
							}
							goto label$695;
							label$698:;
							{
								*(uint8*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)) = (uint8)0u;
								goto label$693;
							}
							goto label$695;
							label$696:;
							static const void* tmp$135[24ll] = {
								&&label$697,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$698,
								&&label$697,
							};
							if( (TMP$132$7 - 9ull) > 23ull ) goto label$698;
							goto *tmp$135[TMP$132$7 - 9ull];
							label$695:;
						}
					}
					label$694:;
					goto label$692;
					label$693:;
				}
				goto label$658;
				label$699:;
				{
					*(int64*)((uint8*)T$1 + 8ll) = 7ll;
				}
				goto label$658;
				label$659:;
				static const void* tmp$136[117ll] = {
					&&label$691,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$691,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$688,
					&&label$690,
					&&label$690,
					&&label$679,
					&&label$679,
					&&label$690,
					&&label$680,
					&&label$690,
					&&label$683,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$689,
					&&label$690,
					&&label$660,
					&&label$660,
					&&label$660,
					&&label$699,
					&&label$679,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$690,
					&&label$679,
					&&label$690,
					&&label$679,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$699,
					&&label$690,
					&&label$699,
					&&label$690,
				};
				if( (TMP$129$4 - 9ull) > 116ull ) goto label$699;
				goto *tmp$136[TMP$129$4 - 9ull];
				label$658:;
			}
		}
		goto label$620;
		label$621:;
		static const void* tmp$137[90ll] = {
			&&label$647,
			&&label$643,
			&&label$657,
			&&label$647,
			&&label$657,
			&&label$628,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$622,
			&&label$657,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$639,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$657,
			&&label$640,
			&&label$657,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
			&&label$640,
		};
		if( (TMP$125$2 - 33ull) > 89ull ) goto label$657;
		goto *tmp$137[TMP$125$2 - 33ull];
		label$620:;
	}
	label$584:;
}

int64 LEXGETTOKEN( $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$728:;
	if( *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) != -1ll) goto label$731;
	{
		LEXNEXTTOKEN( *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll), FLAGS$1 );
		PPCHECK(  );
	}
	label$731:;
	label$730:;
	fb$result$1 = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
	label$729:;
	return fb$result$1;
}

int64 LEXGETCLASS( $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$732:;
	if( *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) != -1ll) goto label$735;
	{
		LEXNEXTTOKEN( *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll), FLAGS$1 );
		PPCHECK(  );
	}
	label$735:;
	label$734:;
	fb$result$1 = *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 8ll);
	label$733:;
	return fb$result$1;
}

int64 LEXGETLOOKAHEAD( int64 K$1, $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$736:;
	if( K$1 <= 3ll) goto label$739;
	{
		goto label$737;
	}
	label$739:;
	label$738:;
	if( K$1 <= *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll)) goto label$741;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) = K$1;
		*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) = *(struct $7FBTOKEN**)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) + 4168ll);
	}
	label$741:;
	label$740:;
	if( *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) != -1ll) goto label$743;
	{
		LEXNEXTTOKEN( *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll), FLAGS$1 );
	}
	label$743:;
	label$742:;
	fb$result$1 = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll);
	label$737:;
	return fb$result$1;
}

int64 LEXGETLOOKAHEADCLASS( int64 K$1, $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$744:;
	if( K$1 <= 3ll) goto label$747;
	{
		goto label$745;
	}
	label$747:;
	label$746:;
	if( K$1 <= *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll)) goto label$749;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) = K$1;
		*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) = *(struct $7FBTOKEN**)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) + 4168ll);
	}
	label$749:;
	label$748:;
	if( *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) != -1ll) goto label$751;
	{
		LEXNEXTTOKEN( *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll), FLAGS$1 );
	}
	label$751:;
	label$750:;
	fb$result$1 = *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16720ll) + 8ll);
	label$745:;
	return fb$result$1;
}

void LEXPPONLYEMITTOKEN( void )
{
	label$776:;
	{
		int64 TMP$146$2;
		int64 vr$0 = LEXGETTOKEN( 0ll );
		TMP$146$2 = vr$0;
		if( TMP$146$2 == 259ll) goto label$780;
		label$781:;
		if( TMP$146$2 != 260ll) goto label$779;
		label$780:;
		{
			goto label$777;
		}
		goto label$778;
		label$779:;
		if( TMP$146$2 == 256ll) goto label$783;
		label$784:;
		if( TMP$146$2 != 257ll) goto label$782;
		label$783:;
		{
			int64 vr$1 = fb_StrLen( (void*)&PPONLY_LN$, -1ll );
			if( vr$1 <= 0ll) goto label$786;
			{
				int64 TMP$147$4;
				TMP$147$4 = *(int64*)((uint8*)&ENV$ + 1216ll);
				fb_PrintString( (int32)TMP$147$4, (FBSTRING*)&PPONLY_LN$, 1 );
				fb_StrAssign( (void*)&PPONLY_LN$, -1ll, (void*)"", 1ll, 0 );
			}
			goto label$785;
			label$786:;
			int64 vr$3 = LEXGETTOKEN( 0ll );
			if( vr$3 != 257ll) goto label$787;
			{
				if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16760ll) != 257ll) goto label$789;
				{
					int64 TMP$148$5;
					TMP$148$5 = *(int64*)((uint8*)&ENV$ + 1216ll);
					FBSTRING* vr$5 = fb_StrAllocTempDescZEx( (char*)"", 0ll );
					fb_PrintString( (int32)TMP$148$5, (FBSTRING*)vr$5, 1 );
				}
				label$789:;
				label$788:;
			}
			label$787:;
			label$785:;
			goto label$777;
		}
		label$782:;
		label$778:;
	}
	if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4160ll) == 0ll) goto label$791;
	{
		fb_StrConcatAssign( (void*)&PPONLY_LN$, -1ll, (void*)" ", 2ll, 0 );
	}
	label$791:;
	label$790:;
	{
		int64 TMP$150$2;
		int64 vr$9 = LEXGETTOKEN( 0ll );
		TMP$150$2 = vr$9;
		if( TMP$150$2 == 262ll) goto label$794;
		label$795:;
		if( TMP$150$2 == 263ll) goto label$794;
		label$796:;
		if( TMP$150$2 != 264ll) goto label$793;
		label$794:;
		{
			int64 vr$10 = LEXGETTOKEN( 0ll );
			FBSTRING* vr$11 = LEXGETSTRLITTEXT( vr$10 );
			fb_StrConcatAssign( (void*)&PPONLY_LN$, -1ll, (void*)vr$11, -1ll, 0 );
		}
		goto label$792;
		label$793:;
		{
			FBSTRING TMP$151$3;
			char* vr$12 = LEXGETTEXT(  );
			__builtin_memset( &TMP$151$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$151$3, (void*)&PPONLY_LN$, -1ll, (void*)vr$12, 0ll );
			fb_StrAssign( (void*)&PPONLY_LN$, -1ll, (void*)vr$15, -1ll, 0 );
		}
		label$797:;
		label$792:;
	}
	label$777:;
}

void LEXPPONLYEMITTEXT( FBSTRING* S$1 )
{
	FBSTRING TMP$152$1;
	label$798:;
	__builtin_memset( &TMP$152$1, 0, 24ll );
	FBSTRING* vr$2 = fb_StrConcat( &TMP$152$1, (void*)&PPONLY_LN$, -1ll, (void*)S$1, -1ll );
	fb_StrAssign( (void*)&PPONLY_LN$, -1ll, (void*)vr$2, -1ll, 0 );
	label$799:;
}

void LEXSKIPTOKEN( $8LEXCHECK FLAGS$1 )
{
	label$800:;
	LEXCHECKTOKEN( FLAGS$1 );
	FLAGS$1 = FLAGS$1 & -14337ll;
	if( *(int64*)((uint8*)&ENV$ + 1216ll) <= 0ll) goto label$803;
	{
		if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) != 0ll) goto label$805;
		{
			LEXPPONLYEMITTOKEN(  );
		}
		label$805:;
		label$804:;
	}
	label$803:;
	label$802:;
	{
		int64 TMP$153$2;
		TMP$153$2 = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
		if( TMP$153$2 != 257ll) goto label$807;
		label$808:;
		{
			if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) != 0ll) goto label$810;
			{
				*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) + 1ll;
			}
			label$810:;
			label$809:;
		}
		label$807:;
		label$806:;
	}
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16760ll) = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) != 0ll) goto label$812;
	{
		LEXNEXTTOKEN( *(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll), FLAGS$1 );
	}
	goto label$811;
	label$812:;
	{
		HMOVEKDOWN(  );
	}
	label$811:;
	PPCHECK(  );
	label$801:;
}

void LEXEATTOKEN( char* TOKEN$1, $8LEXCHECK FLAGS$1 )
{
	label$813:;
	if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) == 7ll) goto label$816;
	{
		fb_StrAssign( (void*)TOKEN$1, 0ll, (void*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll), 1025ll, 0 );
	}
	goto label$815;
	label$816:;
	{
		FBSTRING* vr$8 = fb_WstrToStr( (uint32*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll) );
		fb_StrAssign( (void*)TOKEN$1, 0ll, (void*)vr$8, -1ll, 0 );
	}
	label$815:;
	LEXSKIPTOKEN( FLAGS$1 );
	label$814:;
}

char* LEXGETTEXT( void )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$817:;
	static char TMPSTR$1[1025];
	if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) == 7ll) goto label$820;
	{
		fb$result$1 = (char*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll);
	}
	goto label$819;
	label$820:;
	{
		FBSTRING* vr$9 = fb_WstrToStr( (uint32*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll) );
		fb_StrAssign( (void*)TMPSTR$1, 1025ll, (void*)vr$9, -1ll, 0 );
		fb$result$1 = (char*)TMPSTR$1;
	}
	label$819:;
	label$818:;
	return fb$result$1;
}

void LEXREADLINE( uint64 ENDCHAR$1, char* DST$1, int64 SKIPLINE$1 )
{
	label$821:;
	static uint64 CHAR$1;
	if( SKIPLINE$1 != 0ll) goto label$824;
	{
		fb_StrAssign( (void*)DST$1, 0ll, (void*)"", 1ll, 0 );
	}
	label$824:;
	label$823:;
	label$825:;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) <= 0ll) goto label$826;
	{
		{
			int64 TMP$154$3;
			TMP$154$3 = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
			if( TMP$154$3 == 256ll) goto label$829;
			label$830:;
			if( TMP$154$3 == 257ll) goto label$829;
			label$831:;
			if( (uint64)TMP$154$3 != ENDCHAR$1) goto label$828;
			label$829:;
			{
				goto label$822;
			}
			goto label$827;
			label$828:;
			{
				if( SKIPLINE$1 != 0ll) goto label$834;
				{
					FBSTRING TMP$155$5;
					__builtin_memset( &TMP$155$5, 0, 24ll );
					FBSTRING* vr$8 = fb_StrConcat( &TMP$155$5, (void*)DST$1, 0ll, (void*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll), 1025ll );
					fb_StrAssign( (void*)DST$1, 0ll, (void*)vr$8, -1ll, 0 );
				}
				label$834:;
				label$833:;
			}
			label$832:;
			label$827:;
		}
		HMOVEKDOWN(  );
	}
	goto label$825;
	label$826:;
	{
		int64 TMP$156$2;
		TMP$156$2 = *(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll);
		if( TMP$156$2 == 256ll) goto label$837;
		label$838:;
		if( TMP$156$2 == 257ll) goto label$837;
		label$839:;
		if( (uint64)TMP$156$2 != ENDCHAR$1) goto label$836;
		label$837:;
		{
			goto label$822;
		}
		goto label$835;
		label$836:;
		{
			if( SKIPLINE$1 != 0ll) goto label$842;
			{
				FBSTRING TMP$157$4;
				__builtin_memset( &TMP$157$4, 0, 24ll );
				FBSTRING* vr$16 = fb_StrConcat( &TMP$157$4, (void*)DST$1, 0ll, (void*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 24ll), 1025ll );
				fb_StrAssign( (void*)DST$1, 0ll, (void*)vr$16, -1ll, 0 );
			}
			label$842:;
			label$841:;
		}
		label$840:;
		label$835:;
	}
	label$843:;
	{
		uint64 vr$17 = LEXCURRENTCHAR(  );
		CHAR$1 = vr$17;
		{
			uint64 TMP$158$3;
			TMP$158$3 = CHAR$1;
			goto label$847;
			label$848:;
			{
				*(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = 256ll;
				*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 8ll) = 6ll;
				goto label$822;
			}
			goto label$846;
			label$849:;
			{
				LEXEATCHAR(  );
				if( CHAR$1 != 13ull) goto label$851;
				{
					uint64 vr$22 = LEXCURRENTCHAR(  );
					if( vr$22 != 10ull) goto label$853;
					{
						LEXEATCHAR(  );
					}
					label$853:;
					label$852:;
				}
				label$851:;
				label$850:;
				*(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = 257ll;
				*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 8ll) = 6ll;
				goto label$822;
			}
			goto label$846;
			label$854:;
			{
				if( CHAR$1 != ENDCHAR$1) goto label$856;
				{
					*(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = (int64)ENDCHAR$1;
					*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 8ll) = 6ll;
					goto label$822;
				}
				label$856:;
				label$855:;
			}
			goto label$846;
			label$847:;
			static const void* tmp$160[14ll] = {
				&&label$848,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$854,
				&&label$849,
				&&label$854,
				&&label$854,
				&&label$849,
			};
			if( TMP$158$3 > 13ull ) goto label$854;
			goto *tmp$160[TMP$158$3 - 0ull];
			label$846:;
		}
		LEXEATCHAR(  );
		if( SKIPLINE$1 != 0ll) goto label$858;
		{
			FBSTRING TMP$159$3;
			FBSTRING* vr$31 = fb_CHR( 1, (int64)CHAR$1 );
			__builtin_memset( &TMP$159$3, 0, 24ll );
			FBSTRING* vr$34 = fb_StrConcat( &TMP$159$3, (void*)DST$1, 0ll, (void*)vr$31, -1ll );
			fb_StrAssign( (void*)DST$1, 0ll, (void*)vr$34, -1ll, 0 );
		}
		label$858:;
		label$857:;
	}
	label$845:;
	goto label$843;
	label$844:;
	label$822:;
}

void LEXSKIPLINE( void )
{
	label$859:;
	LEXREADLINE( 18446744073709551615ull, (char*)0ull, -1ll );
	label$860:;
}

FBSTRING* LEXPEEKCURRENTLINE( FBSTRING* TOKEN_POS$1, int64 DO_TRIM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$861:;
	static char BUFFER$1[1025];
	FBSTRING RES$1;
	__builtin_memset( &RES$1, 0, 24ll );
	int64 P$1;
	__builtin_memset( &P$1, 0, 8ll );
	int64 OLD_P$1;
	__builtin_memset( &OLD_P$1, 0, 8ll );
	int64 START$1;
	__builtin_memset( &START$1, 0, 8ll );
	int64 TOKEN_LEN$1;
	__builtin_memset( &TOKEN_LEN$1, 0, 8ll );
	uint8* C$1;
	__builtin_memset( &C$1, 0, 8ll );
	uint64 CHAR$1;
	__builtin_memset( &CHAR$1, 0, 8ll );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
	if( *(int64*)((uint8*)&ENV$ + 912ll) == 0ll) goto label$864;
	{
		fb_StrDelete( (FBSTRING*)&RES$1 );
		goto label$862;
	}
	label$864:;
	label$863:;
	int64 vr$11 = fb_FileTell( (int32)*(int64*)((uint8*)&ENV$ + 624ll) );
	OLD_P$1 = vr$11;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16792ll) != 2ll) goto label$866;
	{
		P$1 = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + -48ll) + -512ll;
	}
	goto label$865;
	label$866:;
	{
		P$1 = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49640ll) + -512ll;
	}
	label$865:;
	START$1 = 512ll;
	if( P$1 >= 0ll) goto label$868;
	{
		START$1 = START$1 + P$1;
		P$1 = 0ll;
	}
	label$868:;
	label$867:;
	fb_FileGetStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 624ll), P$1 + 1ll, (void*)BUFFER$1, 1025ll );
	fb_FileSeekLarge( (int32)*(int64*)((uint8*)&ENV$ + 624ll), OLD_P$1 );
	C$1 = (uint8*)((uint8*)BUFFER$1 + START$1);
	TOKEN_LEN$1 = 0ll;
	if( START$1 <= 0ll) goto label$870;
	{
		C$1 = (uint8*)(C$1 + -1ll);
		label$871:;
		{
			CHAR$1 = (uint64)*C$1;
			{
				if( CHAR$1 == 13ull) goto label$876;
				label$877:;
				if( CHAR$1 != 10ull) goto label$875;
				label$876:;
				{
					goto label$872;
				}
				label$875:;
				label$874:;
			}
			if( START$1 > 0ll) goto label$879;
			{
				goto label$872;
			}
			label$879:;
			label$878:;
			TOKEN_LEN$1 = TOKEN_LEN$1 + 1ll;
			C$1 = (uint8*)(C$1 + -1ll);
			START$1 = START$1 + -1ll;
		}
		label$873:;
		goto label$871;
		label$872:;
		C$1 = (uint8*)(C$1 + 1ll);
	}
	label$870:;
	label$869:;
	fb_StrAssign( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	fb_StrAssign( (void*)TOKEN_POS$1, -1ll, (void*)"", 1ll, 0 );
	label$880:;
	{
		CHAR$1 = (uint64)*C$1;
		{
			if( CHAR$1 == 0ull) goto label$885;
			label$886:;
			if( CHAR$1 == 13ull) goto label$885;
			label$887:;
			if( CHAR$1 != 10ull) goto label$884;
			label$885:;
			{
				goto label$881;
			}
			label$884:;
			label$883:;
		}
		FBSTRING* vr$32 = fb_CHR( 1, (int64)CHAR$1 );
		fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)vr$32, -1ll, 0 );
		if( TOKEN_LEN$1 <= 0ll) goto label$889;
		{
			int64 TMP$161$3;
			if( CHAR$1 != 9ull) goto label$890;
			TMP$161$3 = 9ll;
			goto label$915;
			label$890:;
			TMP$161$3 = 32ll;
			label$915:;
			FBSTRING* vr$34 = fb_CHR( 1, TMP$161$3 );
			fb_StrConcatByref( (void*)TOKEN_POS$1, -1ll, (void*)vr$34, -1ll, 0 );
			TOKEN_LEN$1 = TOKEN_LEN$1 + -1ll;
		}
		label$889:;
		label$888:;
		C$1 = (uint8*)(C$1 + 1ll);
	}
	label$882:;
	goto label$880;
	label$881:;
	if( DO_TRIM$1 == 0ll) goto label$892;
	{
		int64 I$2;
		__builtin_memset( &I$2, 0, 8ll );
		{
			I$2 = 0ll;
			int64 TMP$162$3;
			int64 vr$39 = fb_StrLen( (void*)&RES$1, -1ll );
			TMP$162$3 = vr$39 + -1ll;
			goto label$893;
			label$896:;
			{
				{
					uint8 TMP$163$5;
					TMP$163$5 = *(uint8*)((uint8*)*(char**)&RES$1 + I$2);
					if( (int64)TMP$163$5 == 9ll) goto label$899;
					label$900:;
					if( (int64)TMP$163$5 != 32ll) goto label$898;
					label$899:;
					{
					}
					goto label$897;
					label$898:;
					{
						goto label$895;
					}
					label$901:;
					label$897:;
				}
			}
			label$894:;
			I$2 = I$2 + 1ll;
			label$893:;
			if( I$2 <= TMP$162$3) goto label$896;
			label$895:;
		}
		int64 vr$46 = fb_StrLen( (void*)&RES$1, -1ll );
		if( I$2 >= vr$46) goto label$903;
		{
			FBSTRING* vr$49 = fb_StrMid( (FBSTRING*)&RES$1, I$2 + 1ll, -1ll );
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$49, -1ll, 0 );
		}
		goto label$902;
		label$903:;
		{
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
		}
		label$902:;
		{
			int64 vr$53 = fb_StrLen( (void*)&RES$1, -1ll );
			I$2 = vr$53 + -1ll;
			goto label$904;
			label$907:;
			{
				{
					uint8 TMP$164$5;
					TMP$164$5 = *(uint8*)((uint8*)*(char**)&RES$1 + I$2);
					if( (int64)TMP$164$5 == 9ll) goto label$910;
					label$911:;
					if( (int64)TMP$164$5 != 32ll) goto label$909;
					label$910:;
					{
					}
					goto label$908;
					label$909:;
					{
						goto label$906;
					}
					label$912:;
					label$908:;
				}
			}
			label$905:;
			I$2 = I$2 + -1ll;
			label$904:;
			if( I$2 >= 0ll) goto label$907;
			label$906:;
		}
		if( I$2 <= 0ll) goto label$914;
		{
			FBSTRING* vr$61 = fb_LEFT( (FBSTRING*)&RES$1, I$2 + 1ll );
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$61, -1ll, 0 );
		}
		label$914:;
		label$913:;
	}
	label$892:;
	label$891:;
	fb_StrConcatByref( (void*)TOKEN_POS$1, -1ll, (void*)"^", 2ll, 0 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$862:;
	FBSTRING* vr$67 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$67;
}

void LEXCHECKTOKEN( $8LEXCHECK FLAGS$1 )
{
	label$916:;
	if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$919;
	{
		if( (FLAGS$1 & 14336ll) == 0ll) goto label$921;
		{
			if( (FLAGS$1 & 2048ll) == 0ll) goto label$923;
			{
				FBSTRING TMP$167$4;
				FBSTRING TMP$169$4;
				FBSTRING TMP$170$4;
				FBSTRING TMP$171$4;
				FBSTRING TMP$172$4;
				__builtin_memset( &TMP$172$4, 0, 24ll );
				if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$924;
				FBSTRING* vr$9 = fb_CHR( 1, *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) );
				fb_StrInit( (void*)&TMP$167$4, -1ll, (void*)vr$9, -1ll, 0 );
				goto label$941;
				label$924:;
				fb_StrInit( (void*)&TMP$167$4, -1ll, (void*)"", 1ll, 0 );
				label$941:;
				char* vr$13 = LEXGETTEXT(  );
				__builtin_memset( &TMP$169$4, 0, 24ll );
				FBSTRING* vr$16 = fb_StrConcat( &TMP$169$4, (void*)"in '", 5ll, (void*)vr$13, 0ll );
				__builtin_memset( &TMP$170$4, 0, 24ll );
				FBSTRING* vr$19 = fb_StrConcat( &TMP$170$4, (void*)vr$16, -1ll, (void*)&TMP$167$4, -1ll );
				__builtin_memset( &TMP$171$4, 0, 24ll );
				FBSTRING* vr$22 = fb_StrConcat( &TMP$171$4, (void*)vr$19, -1ll, (void*)"'", 2ll );
				fb_StrAssign( (void*)&TMP$172$4, -1ll, (void*)vr$22, -1ll, 0 );
				ERRREPORTWARN( 44ll, (char*)*(char**)&TMP$172$4, 0ll, (char*)0ull );
				fb_StrDelete( (FBSTRING*)&TMP$172$4 );
				fb_StrDelete( (FBSTRING*)&TMP$167$4 );
				*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) = 2147483648ll;
				*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) = 0ll;
			}
			goto label$922;
			label$923:;
			if( (FLAGS$1 & 4096ll) == 0ll) goto label$925;
			{
				if( (*(int64*)((uint8*)&ENV$ + 1448ll) & 8388608ll) != 0ll) goto label$927;
				{
					FBSTRING TMP$173$5;
					FBSTRING TMP$174$5;
					FBSTRING TMP$175$5;
					FBSTRING TMP$176$5;
					FBSTRING TMP$177$5;
					__builtin_memset( &TMP$177$5, 0, 24ll );
					if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$928;
					FBSTRING* vr$37 = fb_CHR( 1, *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) );
					fb_StrInit( (void*)&TMP$173$5, -1ll, (void*)vr$37, -1ll, 0 );
					goto label$942;
					label$928:;
					fb_StrInit( (void*)&TMP$173$5, -1ll, (void*)"", 1ll, 0 );
					label$942:;
					char* vr$41 = LEXGETTEXT(  );
					__builtin_memset( &TMP$174$5, 0, 24ll );
					FBSTRING* vr$44 = fb_StrConcat( &TMP$174$5, (void*)"in '", 5ll, (void*)vr$41, 0ll );
					__builtin_memset( &TMP$175$5, 0, 24ll );
					FBSTRING* vr$47 = fb_StrConcat( &TMP$175$5, (void*)vr$44, -1ll, (void*)&TMP$173$5, -1ll );
					__builtin_memset( &TMP$176$5, 0, 24ll );
					FBSTRING* vr$50 = fb_StrConcat( &TMP$176$5, (void*)vr$47, -1ll, (void*)"'", 2ll );
					fb_StrAssign( (void*)&TMP$177$5, -1ll, (void*)vr$50, -1ll, 0 );
					ERRREPORTWARN( 44ll, (char*)*(char**)&TMP$177$5, 0ll, (char*)0ull );
					fb_StrDelete( (FBSTRING*)&TMP$177$5 );
					fb_StrDelete( (FBSTRING*)&TMP$173$5 );
					*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) = 2147483648ll;
					*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) = 0ll;
				}
				label$927:;
				label$926:;
			}
			goto label$922;
			label$925:;
			if( (FLAGS$1 & 8192ll) == 0ll) goto label$929;
			{
				if( (*(int64*)((uint8*)&ENV$ + 1448ll) & 8388608ll) == 0ll) goto label$931;
				{
					if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 36ll) goto label$933;
					{
						FBSTRING TMP$178$6;
						FBSTRING TMP$179$6;
						FBSTRING TMP$180$6;
						FBSTRING TMP$181$6;
						FBSTRING TMP$182$6;
						__builtin_memset( &TMP$182$6, 0, 24ll );
						if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$934;
						FBSTRING* vr$67 = fb_CHR( 1, *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) );
						fb_StrInit( (void*)&TMP$178$6, -1ll, (void*)vr$67, -1ll, 0 );
						goto label$943;
						label$934:;
						fb_StrInit( (void*)&TMP$178$6, -1ll, (void*)"", 1ll, 0 );
						label$943:;
						char* vr$71 = LEXGETTEXT(  );
						__builtin_memset( &TMP$179$6, 0, 24ll );
						FBSTRING* vr$74 = fb_StrConcat( &TMP$179$6, (void*)"in '", 5ll, (void*)vr$71, 0ll );
						__builtin_memset( &TMP$180$6, 0, 24ll );
						FBSTRING* vr$77 = fb_StrConcat( &TMP$180$6, (void*)vr$74, -1ll, (void*)&TMP$178$6, -1ll );
						__builtin_memset( &TMP$181$6, 0, 24ll );
						FBSTRING* vr$80 = fb_StrConcat( &TMP$181$6, (void*)vr$77, -1ll, (void*)"'", 2ll );
						fb_StrAssign( (void*)&TMP$182$6, -1ll, (void*)vr$80, -1ll, 0 );
						ERRREPORTWARN( 44ll, (char*)*(char**)&TMP$182$6, 0ll, (char*)0ull );
						fb_StrDelete( (FBSTRING*)&TMP$182$6 );
						fb_StrDelete( (FBSTRING*)&TMP$178$6 );
						*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) = 2147483648ll;
						*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) = 0ll;
					}
					label$933:;
					label$932:;
				}
				goto label$930;
				label$931:;
				{
					if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) != 36ll) goto label$936;
					{
						if( (*(int64*)((uint8*)&ENV$ + 408ll) & 256ll) == 0ll) goto label$938;
						{
							FBSTRING TMP$183$7;
							FBSTRING TMP$184$7;
							FBSTRING TMP$185$7;
							FBSTRING TMP$186$7;
							FBSTRING TMP$187$7;
							__builtin_memset( &TMP$187$7, 0, 24ll );
							if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$939;
							FBSTRING* vr$96 = fb_CHR( 1, *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) );
							fb_StrInit( (void*)&TMP$183$7, -1ll, (void*)vr$96, -1ll, 0 );
							goto label$944;
							label$939:;
							fb_StrInit( (void*)&TMP$183$7, -1ll, (void*)"", 1ll, 0 );
							label$944:;
							char* vr$100 = LEXGETTEXT(  );
							__builtin_memset( &TMP$184$7, 0, 24ll );
							FBSTRING* vr$103 = fb_StrConcat( &TMP$184$7, (void*)"in '", 5ll, (void*)vr$100, 0ll );
							__builtin_memset( &TMP$185$7, 0, 24ll );
							FBSTRING* vr$106 = fb_StrConcat( &TMP$185$7, (void*)vr$103, -1ll, (void*)&TMP$183$7, -1ll );
							__builtin_memset( &TMP$186$7, 0, 24ll );
							FBSTRING* vr$109 = fb_StrConcat( &TMP$186$7, (void*)vr$106, -1ll, (void*)"'", 2ll );
							fb_StrAssign( (void*)&TMP$187$7, -1ll, (void*)vr$109, -1ll, 0 );
							ERRREPORTWARN( 44ll, (char*)*(char**)&TMP$187$7, 0ll, (char*)0ull );
							fb_StrDelete( (FBSTRING*)&TMP$187$7 );
							fb_StrDelete( (FBSTRING*)&TMP$183$7 );
						}
						label$938:;
						label$937:;
					}
					goto label$935;
					label$936:;
					{
						FBSTRING TMP$188$6;
						FBSTRING TMP$189$6;
						FBSTRING TMP$190$6;
						FBSTRING TMP$191$6;
						FBSTRING TMP$192$6;
						__builtin_memset( &TMP$192$6, 0, 24ll );
						if( *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) == 0ll) goto label$940;
						FBSTRING* vr$118 = fb_CHR( 1, *(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) );
						fb_StrInit( (void*)&TMP$188$6, -1ll, (void*)vr$118, -1ll, 0 );
						goto label$945;
						label$940:;
						fb_StrInit( (void*)&TMP$188$6, -1ll, (void*)"", 1ll, 0 );
						label$945:;
						char* vr$122 = LEXGETTEXT(  );
						__builtin_memset( &TMP$189$6, 0, 24ll );
						FBSTRING* vr$125 = fb_StrConcat( &TMP$189$6, (void*)"in '", 5ll, (void*)vr$122, 0ll );
						__builtin_memset( &TMP$190$6, 0, 24ll );
						FBSTRING* vr$128 = fb_StrConcat( &TMP$190$6, (void*)vr$125, -1ll, (void*)&TMP$188$6, -1ll );
						__builtin_memset( &TMP$191$6, 0, 24ll );
						FBSTRING* vr$131 = fb_StrConcat( &TMP$191$6, (void*)vr$128, -1ll, (void*)"'", 2ll );
						fb_StrAssign( (void*)&TMP$192$6, -1ll, (void*)vr$131, -1ll, 0 );
						ERRREPORTWARN( 44ll, (char*)*(char**)&TMP$192$6, 0ll, (char*)0ull );
						fb_StrDelete( (FBSTRING*)&TMP$192$6 );
						fb_StrDelete( (FBSTRING*)&TMP$188$6 );
					}
					label$935:;
					*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 16ll) = 2147483648ll;
					*(int64*)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4152ll) = 0ll;
				}
				label$930:;
			}
			label$929:;
			label$922:;
		}
		label$921:;
		label$920:;
	}
	label$919:;
	label$918:;
	label$917:;
}

int64 HMATCHIDORKW( char* TXT$1, $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$946:;
	{
		int64 TMP$193$2;
		int64 vr$1 = LEXGETCLASS( 0ll );
		TMP$193$2 = vr$1;
		if( TMP$193$2 == 0ll) goto label$950;
		label$951:;
		if( TMP$193$2 == 2ll) goto label$950;
		label$952:;
		if( TMP$193$2 != 1ll) goto label$949;
		label$950:;
		{
			char* vr$2 = LEXGETTEXT(  );
			FBSTRING* vr$3 = fb_StrAllocTempDescZ( (char*)vr$2 );
			FBSTRING* vr$4 = fb_StrUcase2( (FBSTRING*)vr$3, 0 );
			int32 vr$5 = fb_StrCompare( (void*)vr$4, -1ll, (void*)TXT$1, 0ll );
			if( (int64)vr$5 != 0ll) goto label$954;
			{
				LEXSKIPTOKEN( FLAGS$1 );
				fb$result$1 = -1ll;
				goto label$947;
			}
			label$954:;
			label$953:;
		}
		label$949:;
		label$948:;
	}
	fb$result$1 = 0ll;
	goto label$947;
	label$947:;
	return fb$result$1;
}

int64 HMATCH( int64 TOKEN$1, $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$955:;
	int64 vr$1 = LEXGETTOKEN( 0ll );
	if( vr$1 != TOKEN$1) goto label$958;
	{
		LEXSKIPTOKEN( FLAGS$1 );
		fb$result$1 = -1ll;
	}
	goto label$957;
	label$958:;
	{
		fb$result$1 = 0ll;
	}
	label$957:;
	label$956:;
	return fb$result$1;
}

__attribute__(( constructor )) static void fb_ctor__lex( void )
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

static void HCOLLECTCHARFORDEBUGOUTPUT( uint64 CHAR$1 )
{
	label$50:;
	if( CHAR$1 >= 32ull) goto label$53;
	{
		{
			uint64 TMP$96$3;
			TMP$96$3 = CHAR$1;
			goto label$55;
			label$56:;
			{
				goto label$51;
			}
			goto label$54;
			label$57:;
			{
			}
			goto label$54;
			label$58:;
			{
				CHAR$1 = 63ull;
			}
			goto label$54;
			label$55:;
			static const void* tmp$194[14ll] = {
				&&label$56,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$58,
				&&label$57,
				&&label$56,
				&&label$57,
				&&label$57,
				&&label$56,
			};
			if( TMP$96$3 > 13ull ) goto label$58;
			goto *tmp$194[TMP$96$3 - 0ull];
			label$54:;
		}
	}
	goto label$52;
	label$53:;
	if( CHAR$1 <= 255ull) goto label$59;
	{
		CHAR$1 = 63ull;
	}
	label$59:;
	label$52:;
	DZSTRCONCATASSIGNC( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll), CHAR$1 );
	label$51:;
}

static uint64 HREADCHAR( void )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$60:;
	uint64 CHAR$1;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) <= 0ll) goto label$63;
	{
		if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$65;
		{
			CHAR$1 = (uint64)(uint8)*(*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll));
		}
		goto label$64;
		label$65:;
		{
			CHAR$1 = (uint64)*(*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll));
		}
		label$64:;
		if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$67;
		{
			if( *(int64*)((uint8*)&ENV$ + 1296ll) != 0ll) goto label$69;
			{
				if( *(int64*)((uint8*)&LEX$ + 844704ll) != 0ll) goto label$71;
				{
					*(int64*)((uint8*)&LEX$ + 844704ll) = -1ll;
					DZSTRCONCATASSIGN( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll), (char*)" [Macro Expansion: " );
				}
				label$71:;
				label$70:;
				HCOLLECTCHARFORDEBUGOUTPUT( CHAR$1 );
			}
			label$69:;
			label$68:;
		}
		label$67:;
		label$66:;
	}
	goto label$62;
	label$63:;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16792ll) != 2ll) goto label$72;
	{
		CHAR$1 = 0ull;
	}
	goto label$62;
	label$72:;
	{
		if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) != 0ll) goto label$74;
		{
			int32 vr$13 = fb_FileEof( (int32)*(int64*)((uint8*)&ENV$ + 624ll) );
			if( (int64)vr$13 != 0ll) goto label$76;
			{
				int64 vr$16 = fb_FileTell( (int32)*(int64*)((uint8*)&ENV$ + 624ll) );
				*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49632ll) = vr$16;
				{
					uint64 TMP$99$5;
					TMP$99$5 = *(uint64*)((uint8*)&ENV$ + 912ll);
					goto label$78;
					label$79:;
					{
						int32 vr$21 = fb_FileGetStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 624ll), 0ll, (void*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16856ll), 8193ll );
						if( (int64)vr$21 != 0ll) goto label$81;
						{
							int64 vr$24 = fb_FileTell( (int32)*(int64*)((uint8*)&ENV$ + 624ll) );
							*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49648ll) = vr$24;
							*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49648ll) - *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49632ll);
							*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) = (char*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16856ll);
						}
						label$81:;
						label$80:;
					}
					goto label$77;
					label$82:;
					{
						LEXREADUTF8(  );
					}
					goto label$77;
					label$83:;
					{
						LEXREADUTF16LE(  );
					}
					goto label$77;
					label$84:;
					{
						LEXREADUTF16BE(  );
					}
					goto label$77;
					label$85:;
					{
						LEXREADUTF32LE(  );
					}
					goto label$77;
					label$86:;
					{
						LEXREADUTF32BE(  );
					}
					goto label$77;
					label$78:;
					static const void* tmp$195[6ll] = {
						&&label$79,
						&&label$82,
						&&label$83,
						&&label$84,
						&&label$85,
						&&label$86,
					};
					if( TMP$99$5 > 5ull ) goto label$77;
					goto *tmp$195[TMP$99$5 - 0ull];
					label$77:;
				}
			}
			label$76:;
			label$75:;
		}
		label$74:;
		label$73:;
		if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) <= 0ll) goto label$88;
		{
			if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$90;
			{
				CHAR$1 = (uint64)(uint8)*(*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll));
			}
			goto label$89;
			label$90:;
			{
				CHAR$1 = (uint64)*(*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll));
			}
			label$89:;
		}
		goto label$87;
		label$88:;
		{
			CHAR$1 = 0ull;
		}
		label$87:;
		if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$92;
		{
			if( *(int64*)((uint8*)&ENV$ + 1296ll) != 0ll) goto label$94;
			{
				if( *(int64*)((uint8*)&LEX$ + 844704ll) == 0ll) goto label$96;
				{
					*(int64*)((uint8*)&LEX$ + 844704ll) = 0ll;
					DZSTRCONCATASSIGN( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll), (char*)" ] " );
				}
				label$96:;
				label$95:;
				HCOLLECTCHARFORDEBUGOUTPUT( CHAR$1 );
			}
			label$94:;
			label$93:;
		}
		label$92:;
		label$91:;
	}
	label$62:;
	fb$result$1 = CHAR$1;
	label$61:;
	return fb$result$1;
}

static void HSKIPCHAR( void )
{
	label$108:;
	if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) <= 0ll) goto label$111;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + -1ll;
		if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$113;
		{
			*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = (char*)((uint8*)*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) + 1ll);
		}
		goto label$112;
		label$113:;
		{
			*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = (uint32*)((uint8*)*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) + 4ll);
		}
		label$112:;
		if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) != 0ll) goto label$115;
		{
			*(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16776ll) = (struct $8FBSYMBOL*)0ull;
		}
		label$115:;
		label$114:;
	}
	goto label$110;
	label$111:;
	if( *(uint64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16728ll) == 0ull) goto label$116;
	{
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16840ll) + -1ll;
		if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$118;
		{
			*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) = (char*)((uint8*)*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) + 1ll);
		}
		goto label$117;
		label$118:;
		{
			*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) = (uint32*)((uint8*)*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16848ll) + 4ll);
		}
		label$117:;
	}
	label$116:;
	label$110:;
	label$109:;
}

static void HREADIDENTIFIER( char* PID$1, int64* TLEN$1, int64* DTYPE$1, int64* SUFFIXCHAR$1, $8LEXCHECK FLAGS$1 )
{
	label$131:;
	int64 SKIPCHAR$1;
	uint64 vr$0 = LEXCURRENTCHAR(  );
	*PID$1 = (uint8)vr$0;
	PID$1 = (char*)((uint8*)PID$1 + 1ll);
	*TLEN$1 = *TLEN$1 + 1ll;
	*SUFFIXCHAR$1 = 0ll;
	LEXEATCHAR(  );
	SKIPCHAR$1 = 0ll;
	label$133:;
	{
		uint64 C$2;
		uint64 vr$8 = LEXCURRENTCHAR(  );
		C$2 = vr$8;
		{
			uint64 TMP$101$3;
			TMP$101$3 = C$2;
			goto label$137;
			label$138:;
			{
			}
			goto label$136;
			label$139:;
			{
				if( (FLAGS$1 & 128ll) != 0ll) goto label$141;
				{
					goto label$134;
				}
				label$141:;
				label$140:;
			}
			goto label$136;
			label$142:;
			{
				goto label$134;
			}
			goto label$136;
			label$137:;
			static const void* tmp$196[77ll] = {
				&&label$139,
				&&label$142,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$142,
				&&label$138,
				&&label$142,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
				&&label$138,
			};
			if( (TMP$101$3 - 46ull) > 76ull ) goto label$142;
			goto *tmp$196[TMP$101$3 - 46ull];
			label$136:;
		}
		LEXEATCHAR(  );
		if( SKIPCHAR$1 != 0ll) goto label$144;
		{
			if( *TLEN$1 != 128ll) goto label$146;
			{
				if( (FLAGS$1 & 1ll) != 0ll) goto label$148;
				{
					FLAGS$1 = FLAGS$1 | 1ll;
					ERRREPORTWARN( 7ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$148:;
				label$147:;
				SKIPCHAR$1 = -1ll;
			}
			goto label$145;
			label$146:;
			{
				*PID$1 = (uint8)C$2;
				PID$1 = (char*)((uint8*)PID$1 + 1ll);
				*TLEN$1 = *TLEN$1 + 1ll;
			}
			label$145:;
		}
		label$144:;
		label$143:;
	}
	label$135:;
	goto label$133;
	label$134:;
	*PID$1 = (uint8)0u;
	*DTYPE$1 = 2147483648ll;
	if( (FLAGS$1 & 8ll) != 0ll) goto label$150;
	{
		{
			uint64 TMP$102$3;
			uint64 vr$22 = LEXCURRENTCHAR(  );
			TMP$102$3 = vr$22;
			goto label$152;
			label$153:;
			{
				*DTYPE$1 = *(int64*)((uint8*)&ENV$ + 1456ll);
				*SUFFIXCHAR$1 = 37ll;
				LEXEATCHAR(  );
			}
			goto label$151;
			label$154:;
			{
				*DTYPE$1 = 11ll;
				*SUFFIXCHAR$1 = 38ll;
				LEXEATCHAR(  );
			}
			goto label$151;
			label$155:;
			{
				*DTYPE$1 = 15ll;
				*SUFFIXCHAR$1 = 33ll;
				LEXEATCHAR(  );
			}
			goto label$151;
			label$156:;
			{
				uint64 vr$29 = LEXGETLOOKAHEADCHAR(  );
				if( vr$29 == 35ull) goto label$158;
				{
					*DTYPE$1 = 16ll;
					*SUFFIXCHAR$1 = 35ll;
					LEXEATCHAR(  );
				}
				label$158:;
				label$157:;
			}
			goto label$151;
			label$159:;
			{
				*DTYPE$1 = 17ll;
				*SUFFIXCHAR$1 = 36ll;
				LEXEATCHAR(  );
			}
			goto label$151;
			label$152:;
			static const void* tmp$197[6ll] = {
				&&label$155,
				&&label$151,
				&&label$156,
				&&label$159,
				&&label$153,
				&&label$154,
			};
			if( (TMP$102$3 - 33ull) > 5ull ) goto label$151;
			goto *tmp$197[TMP$102$3 - 33ull];
			label$151:;
		}
	}
	label$150:;
	label$149:;
	label$132:;
}

static uint64 HREADNONDECNUMBER( char** PNUM$1, int64* TLEN$1, int64* DTYPE$1, $8LEXCHECK FLAGS$1 )
{
	int64 TMP$107$1;
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$160:;
	uint64 VALUE$1;
	uint64 C$1;
	uint64 FIRST_C$1;
	uint64 VALUE64$1;
	int64 LGT$1;
	int64 HAVEDIGITS$1;
	int64 SKIPCHAR$1;
	VALUE$1 = 0ull;
	LGT$1 = 0ll;
	SKIPCHAR$1 = 0ll;
	HAVEDIGITS$1 = 0ll;
	uint64 vr$1 = LEXGETLOOKAHEADCHAR(  );
	C$1 = vr$1;
	{
		uint64 TMP$103$2;
		TMP$103$2 = C$1;
		goto label$163;
		label$164:;
		{
			C$1 = 79ull;
		}
		goto label$162;
		label$165:;
		{
			LEXEATCHAR(  );
		}
		goto label$162;
		label$163:;
		static const void* tmp$198[8ll] = {
			&&label$164,
			&&label$164,
			&&label$164,
			&&label$164,
			&&label$164,
			&&label$164,
			&&label$164,
			&&label$164,
		};
		if( (TMP$103$2 - 48ull) > 7ull ) goto label$165;
		goto *tmp$198[TMP$103$2 - 48ull];
		label$162:;
	}
	{
		uint64 TMP$104$2;
		TMP$104$2 = C$1;
		goto label$167;
		label$168:;
		{
			*(*PNUM$1) = (uint8)38u;
			*(char*)((uint8*)*PNUM$1 + 1ll) = (uint8)C$1;
			*PNUM$1 = (char*)((uint8*)*PNUM$1 + 2ll);
			*TLEN$1 = *TLEN$1 + 2ll;
			LEXEATCHAR(  );
			if( (FLAGS$1 & 9ll) != 0ll) goto label$170;
			{
				label$171:;
				uint64 vr$14 = LEXCURRENTCHAR(  );
				if( vr$14 != 48ull) goto label$172;
				{
					*(*PNUM$1) = (uint8)48u;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*TLEN$1 = *TLEN$1 + 1ll;
					LEXEATCHAR(  );
					HAVEDIGITS$1 = -1ll;
				}
				goto label$171;
				label$172:;
			}
			label$170:;
			label$169:;
			label$173:;
			{
				uint64 vr$23 = LEXCURRENTCHAR(  );
				C$1 = vr$23;
				{
					if( C$1 < 97ull) goto label$179;
					if( C$1 <= 102ull) goto label$178;
					label$179:;
					if( C$1 < 65ull) goto label$180;
					if( C$1 <= 70ull) goto label$178;
					label$180:;
					if( C$1 < 48ull) goto label$177;
					if( C$1 > 57ull) goto label$177;
					label$178:;
					{
						LEXEATCHAR(  );
						HAVEDIGITS$1 = -1ll;
						if( SKIPCHAR$1 != 0ll) goto label$182;
						{
							*(*PNUM$1) = (uint8)C$1;
							*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
							*TLEN$1 = *TLEN$1 + 1ll;
							C$1 = C$1 + 18446744073709551568ull;
							if( C$1 <= 9ull) goto label$184;
							{
								C$1 = C$1 + 18446744073709551609ull;
							}
							label$184:;
							label$183:;
							if( C$1 <= 16ull) goto label$186;
							{
								C$1 = C$1 + 18446744073709551584ull;
							}
							label$186:;
							label$185:;
							LGT$1 = LGT$1 + 1ll;
							if( LGT$1 <= 8ll) goto label$188;
							{
								if( LGT$1 != 9ll) goto label$190;
								{
									*DTYPE$1 = 13ll;
									VALUE64$1 = (VALUE$1 << (4ull & 63ll)) + C$1;
								}
								goto label$189;
								label$190:;
								if( LGT$1 != 17ll) goto label$191;
								{
									if( (FLAGS$1 & 1ll) != 0ll) goto label$193;
									{
										ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
									}
									label$193:;
									label$192:;
									SKIPCHAR$1 = -1ll;
								}
								goto label$189;
								label$191:;
								{
									VALUE64$1 = (VALUE64$1 << (4ull & 63ll)) + C$1;
								}
								label$189:;
							}
							goto label$187;
							label$188:;
							{
								if( LGT$1 != 5ll) goto label$195;
								{
									*DTYPE$1 = 11ll;
								}
								label$195:;
								label$194:;
								VALUE$1 = (VALUE$1 << (4ull & 63ll)) + C$1;
							}
							label$187:;
						}
						label$182:;
						label$181:;
					}
					goto label$176;
					label$177:;
					{
						goto label$174;
					}
					label$196:;
					label$176:;
				}
			}
			label$175:;
			goto label$173;
			label$174:;
		}
		goto label$166;
		label$197:;
		{
			*(*PNUM$1) = (uint8)38u;
			*(char*)((uint8*)*PNUM$1 + 1ll) = (uint8)C$1;
			*PNUM$1 = (char*)((uint8*)*PNUM$1 + 2ll);
			*TLEN$1 = *TLEN$1 + 2ll;
			LEXEATCHAR(  );
			if( (FLAGS$1 & 9ll) != 0ll) goto label$199;
			{
				label$200:;
				uint64 vr$58 = LEXCURRENTCHAR(  );
				if( vr$58 != 48ull) goto label$201;
				{
					*(*PNUM$1) = (uint8)48u;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*TLEN$1 = *TLEN$1 + 1ll;
					LEXEATCHAR(  );
					HAVEDIGITS$1 = -1ll;
				}
				goto label$200;
				label$201:;
			}
			label$199:;
			label$198:;
			uint64 vr$67 = LEXCURRENTCHAR(  );
			FIRST_C$1 = vr$67;
			label$202:;
			{
				uint64 vr$68 = LEXCURRENTCHAR(  );
				C$1 = vr$68;
				{
					if( C$1 < 48ull) goto label$206;
					if( C$1 > 55ull) goto label$206;
					label$207:;
					{
						LEXEATCHAR(  );
						HAVEDIGITS$1 = -1ll;
						if( SKIPCHAR$1 != 0ll) goto label$209;
						{
							*(*PNUM$1) = (uint8)C$1;
							*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
							*TLEN$1 = *TLEN$1 + 1ll;
							C$1 = C$1 + 18446744073709551568ull;
							LGT$1 = LGT$1 + 1ll;
							if( LGT$1 <= 10ll) goto label$211;
							{
								{
									uint64 TMP$105$9;
									TMP$105$9 = (uint64)LGT$1;
									goto label$213;
									label$214:;
									{
										if( FIRST_C$1 <= 51ull) goto label$216;
										{
											*DTYPE$1 = 13ll;
											VALUE64$1 = (VALUE$1 << (3ull & 63ll)) + C$1;
										}
										goto label$215;
										label$216:;
										{
											VALUE$1 = (VALUE$1 << (3ull & 63ll)) + C$1;
										}
										label$215:;
									}
									goto label$212;
									label$217:;
									{
										int64 TMP$106$10;
										if( (*DTYPE$1 & 480ll) == 0ll) goto label$218;
										TMP$106$10 = 24ll;
										goto label$959;
										label$218:;
										TMP$106$10 = *DTYPE$1 & 31ll;
										label$959:;
										if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$106$10 * 56ll)) + 8ll) >= 8ll) goto label$220;
										{
											*DTYPE$1 = 13ll;
											VALUE64$1 = VALUE$1;
										}
										label$220:;
										label$219:;
										VALUE64$1 = (VALUE64$1 << (3ull & 63ll)) + C$1;
									}
									goto label$212;
									label$221:;
									{
										if( FIRST_C$1 <= 49ull) goto label$223;
										{
											if( (FLAGS$1 & 1ll) != 0ll) goto label$225;
											{
												ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
											}
											label$225:;
											label$224:;
											SKIPCHAR$1 = -1ll;
										}
										goto label$222;
										label$223:;
										{
											VALUE64$1 = (VALUE64$1 << (3ull & 63ll)) + C$1;
										}
										label$222:;
									}
									goto label$212;
									label$226:;
									{
										if( (FLAGS$1 & 1ll) != 0ll) goto label$228;
										{
											ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
										}
										label$228:;
										label$227:;
										SKIPCHAR$1 = -1ll;
									}
									goto label$212;
									label$229:;
									{
										VALUE64$1 = (VALUE64$1 << (3ull & 63ll)) + C$1;
									}
									goto label$212;
									label$213:;
									static const void* tmp$199[13ll] = {
										&&label$214,
										&&label$217,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$229,
										&&label$221,
										&&label$226,
									};
									if( (TMP$105$9 - 11ull) > 12ull ) goto label$229;
									goto *tmp$199[TMP$105$9 - 11ull];
									label$212:;
								}
							}
							goto label$210;
							label$211:;
							{
								if( LGT$1 != 6ll) goto label$231;
								{
									if( FIRST_C$1 <= 49ull) goto label$233;
									{
										*DTYPE$1 = 11ll;
									}
									label$233:;
									label$232:;
								}
								goto label$230;
								label$231:;
								if( LGT$1 != 7ll) goto label$234;
								{
									*DTYPE$1 = 11ll;
								}
								label$234:;
								label$230:;
								VALUE$1 = (VALUE$1 << (3ull & 63ll)) + C$1;
							}
							label$210:;
						}
						label$209:;
						label$208:;
					}
					goto label$205;
					label$206:;
					{
						goto label$203;
					}
					label$235:;
					label$205:;
				}
			}
			label$204:;
			goto label$202;
			label$203:;
		}
		goto label$166;
		label$236:;
		{
			*(*PNUM$1) = (uint8)38u;
			*(char*)((uint8*)*PNUM$1 + 1ll) = (uint8)C$1;
			*PNUM$1 = (char*)((uint8*)*PNUM$1 + 2ll);
			*TLEN$1 = *TLEN$1 + 2ll;
			LEXEATCHAR(  );
			if( (FLAGS$1 & 9ll) != 0ll) goto label$238;
			{
				label$239:;
				uint64 vr$115 = LEXCURRENTCHAR(  );
				if( vr$115 != 48ull) goto label$240;
				{
					*(*PNUM$1) = (uint8)48u;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*TLEN$1 = *TLEN$1 + 1ll;
					LEXEATCHAR(  );
					HAVEDIGITS$1 = -1ll;
				}
				goto label$239;
				label$240:;
			}
			label$238:;
			label$237:;
			label$241:;
			{
				uint64 vr$124 = LEXCURRENTCHAR(  );
				C$1 = vr$124;
				{
					if( C$1 == 48ull) goto label$246;
					label$247:;
					if( C$1 != 49ull) goto label$245;
					label$246:;
					{
						LEXEATCHAR(  );
						HAVEDIGITS$1 = -1ll;
						if( SKIPCHAR$1 != 0ll) goto label$249;
						{
							*(*PNUM$1) = (uint8)C$1;
							*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
							*TLEN$1 = *TLEN$1 + 1ll;
							C$1 = C$1 + 18446744073709551568ull;
							LGT$1 = LGT$1 + 1ll;
							if( LGT$1 <= 32ll) goto label$251;
							{
								if( LGT$1 != 33ll) goto label$253;
								{
									*DTYPE$1 = 13ll;
									VALUE64$1 = (VALUE$1 << (1ull & 63ll)) + C$1;
								}
								goto label$252;
								label$253:;
								if( LGT$1 != 65ll) goto label$254;
								{
									if( (FLAGS$1 & 1ll) != 0ll) goto label$256;
									{
										ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
									}
									label$256:;
									label$255:;
									SKIPCHAR$1 = -1ll;
								}
								goto label$252;
								label$254:;
								{
									VALUE64$1 = (VALUE64$1 << (1ull & 63ll)) + C$1;
								}
								label$252:;
							}
							goto label$250;
							label$251:;
							{
								if( LGT$1 != 17ll) goto label$258;
								{
									*DTYPE$1 = 11ll;
								}
								label$258:;
								label$257:;
								VALUE$1 = (VALUE$1 << (1ull & 63ll)) + C$1;
							}
							label$250:;
						}
						label$249:;
						label$248:;
					}
					goto label$244;
					label$245:;
					{
						goto label$242;
					}
					label$259:;
					label$244:;
				}
			}
			label$243:;
			goto label$241;
			label$242:;
		}
		goto label$166;
		label$260:;
		{
			goto label$161;
		}
		goto label$166;
		label$167:;
		static const void* tmp$200[46ll] = {
			&&label$236,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$168,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$197,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$236,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$168,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$260,
			&&label$197,
		};
		if( (TMP$104$2 - 66ull) > 45ull ) goto label$260;
		goto *tmp$200[TMP$104$2 - 66ull];
		label$166:;
	}
	if( LGT$1 != 0ll) goto label$262;
	{
		if( HAVEDIGITS$1 != 0ll) goto label$264;
		{
			if( (FLAGS$1 & 9ll) != 0ll) goto label$266;
			{
				ERRREPORTWARN( 48ll, (char*)0ull, 1ll, (char*)0ull );
			}
			label$266:;
			label$265:;
		}
		label$264:;
		label$263:;
		*(*PNUM$1) = (uint8)48u;
		*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
		*TLEN$1 = *TLEN$1 + 1ll;
	}
	label$262:;
	label$261:;
	if( (*DTYPE$1 & 480ll) == 0ll) goto label$267;
	TMP$107$1 = 24ll;
	goto label$960;
	label$267:;
	TMP$107$1 = *DTYPE$1 & 31ll;
	label$960:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$107$1 * 56ll)) + 8ll) >= 8ll) goto label$269;
	{
		fb$result$1 = VALUE$1;
	}
	goto label$268;
	label$269:;
	{
		fb$result$1 = VALUE64$1;
	}
	label$268:;
	label$161:;
	return fb$result$1;
}

static void HREADFLOATNUMBER( char** PNUM$1, struct $7FBTOKEN* T$1, int64 HASDOT$1, $8LEXCHECK FLAGS$1 )
{
	int64 TMP$108$1;
	label$270:;
	uint64 C$1;
	int64 LLEN$1;
	int64 SKIPCHAR$1;
	*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1512ll);
	LLEN$1 = *(int64*)((uint8*)T$1 + 4128ll);
	SKIPCHAR$1 = 0ll;
	label$272:;
	{
		uint64 vr$2 = LEXCURRENTCHAR(  );
		C$1 = vr$2;
		{
			if( C$1 < 48ull) goto label$276;
			if( C$1 > 57ull) goto label$276;
			label$277:;
			{
				LEXEATCHAR(  );
				if( SKIPCHAR$1 != 0ll) goto label$279;
				{
					*(*PNUM$1) = (uint8)C$1;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
				}
				label$279:;
				label$278:;
			}
			goto label$275;
			label$276:;
			{
				goto label$273;
			}
			label$280:;
			label$275:;
		}
		if( *(int64*)((uint8*)T$1 + 4128ll) != 64ll) goto label$282;
		{
			if( SKIPCHAR$1 != 0ll) goto label$284;
			{
				SKIPCHAR$1 = -1ll;
			}
			goto label$283;
			label$284:;
			{
				if( (FLAGS$1 & 1ll) != 0ll) goto label$286;
				{
					FLAGS$1 = FLAGS$1 | 1ll;
					ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$286:;
				label$285:;
			}
			label$283:;
		}
		label$282:;
		label$281:;
	}
	label$274:;
	goto label$272;
	label$273:;
	if( HASDOT$1 == 0ll) goto label$287;
	TMP$108$1 = 1ll;
	goto label$961;
	label$287:;
	TMP$108$1 = 0ll;
	label$961:;
	if( *(int64*)((uint8*)T$1 + 4128ll) <= (TMP$108$1 + 7ll)) goto label$289;
	{
		*(int64*)((uint8*)T$1 + 16ll) = 16ll;
	}
	label$289:;
	label$288:;
	uint64 vr$18 = LEXCURRENTCHAR(  );
	C$1 = vr$18;
	{
		uint64 TMP$109$2;
		TMP$109$2 = C$1;
		goto label$291;
		label$292:;
		{
			if( ((int64)-(C$1 == 100ull) | (int64)-(C$1 == 68ull)) == 0ll) goto label$294;
			{
				*(int64*)((uint8*)T$1 + 16ll) = 16ll;
			}
			label$294:;
			label$293:;
			if( SKIPCHAR$1 != 0ll) goto label$296;
			{
				if( FLAGS$1 != 0ll) goto label$298;
				{
					C$1 = 101ull;
				}
				label$298:;
				label$297:;
				*(*PNUM$1) = (uint8)C$1;
				*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
				*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
			}
			label$296:;
			label$295:;
			LEXEATCHAR(  );
			uint64 vr$32 = LEXCURRENTCHAR(  );
			C$1 = vr$32;
			if( ((int64)-(C$1 == 43ull) | (int64)-(C$1 == 45ull)) == 0ll) goto label$300;
			{
				LEXEATCHAR(  );
				if( SKIPCHAR$1 != 0ll) goto label$302;
				{
					*(*PNUM$1) = (uint8)C$1;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
				}
				label$302:;
				label$301:;
			}
			label$300:;
			label$299:;
			label$303:;
			{
				uint64 vr$45 = LEXCURRENTCHAR(  );
				C$1 = vr$45;
				{
					uint64 TMP$110$5;
					TMP$110$5 = C$1;
					goto label$307;
					label$308:;
					{
						LEXEATCHAR(  );
						if( SKIPCHAR$1 != 0ll) goto label$310;
						{
							*(*PNUM$1) = (uint8)C$1;
							*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
							*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
						}
						label$310:;
						label$309:;
					}
					goto label$306;
					label$311:;
					{
						goto label$304;
					}
					goto label$306;
					label$307:;
					static const void* tmp$201[10ll] = {
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
						&&label$308,
					};
					if( (TMP$110$5 - 48ull) > 9ull ) goto label$311;
					goto *tmp$201[TMP$110$5 - 48ull];
					label$306:;
				}
				if( *(int64*)((uint8*)T$1 + 4128ll) != 64ll) goto label$313;
				{
					if( SKIPCHAR$1 != 0ll) goto label$315;
					{
						SKIPCHAR$1 = -1ll;
					}
					goto label$314;
					label$315:;
					{
						if( (FLAGS$1 & 1ll) != 0ll) goto label$317;
						{
							FLAGS$1 = FLAGS$1 | 1ll;
							ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
						}
						label$317:;
						label$316:;
					}
					label$314:;
				}
				label$313:;
				label$312:;
			}
			label$305:;
			goto label$303;
			label$304:;
		}
		goto label$290;
		label$291:;
		static const void* tmp$202[34ll] = {
			&&label$292,
			&&label$292,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$290,
			&&label$292,
			&&label$292,
		};
		if( (TMP$109$2 - 68ull) > 33ull ) goto label$290;
		goto *tmp$202[TMP$109$2 - 68ull];
		label$290:;
	}
	{
		uint64 TMP$111$2;
		uint64 vr$58 = LEXCURRENTCHAR(  );
		TMP$111$2 = vr$58;
		goto label$319;
		label$320:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = 15ll;
			if( (FLAGS$1 & 1032ll) != 0ll) goto label$322;
			{
				LEXEATCHAR(  );
			}
			label$322:;
			label$321:;
		}
		goto label$318;
		label$323:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = 15ll;
			if( (FLAGS$1 & 8ll) != 0ll) goto label$325;
			{
				LEXEATCHAR(  );
			}
			label$325:;
			label$324:;
		}
		goto label$318;
		label$326:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = 16ll;
			if( (FLAGS$1 & 8ll) != 0ll) goto label$328;
			{
				LEXEATCHAR(  );
			}
			label$328:;
			label$327:;
		}
		goto label$318;
		label$319:;
		static const void* tmp$203[70ll] = {
			&&label$323,
			&&label$318,
			&&label$326,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$320,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$318,
			&&label$320,
		};
		if( (TMP$111$2 - 33ull) > 69ull ) goto label$318;
		goto *tmp$203[TMP$111$2 - 33ull];
		label$318:;
	}
	if( FLAGS$1 != 0ll) goto label$330;
	{
		if( (*(int64*)((uint8*)T$1 + 4128ll) - LLEN$1) != 0ll) goto label$332;
		{
			*(*PNUM$1) = (uint8)48u;
			*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
			*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
		}
		label$332:;
		label$331:;
	}
	label$330:;
	label$329:;
	label$271:;
}

static void READNUMBERCHARS( struct $7FBTOKEN* T$1, $8LEXCHECK* FLAGS$1, char** PNUM$1, int64* SKIPCHAR$1, uint64* VALUE$1 )
{
	label$333:;
	int64 SAVE_FIRST_LEADING_ZERO$1;
	SAVE_FIRST_LEADING_ZERO$1 = (int64)-((*(int64*)FLAGS$1 & 9ll) != 0ll);
	uint64 VALUE_PREV$1;
	__builtin_memset( &VALUE_PREV$1, 0, 8ll );
	label$335:;
	{
		uint64 C$2;
		uint64 vr$4 = LEXCURRENTCHAR(  );
		C$2 = vr$4;
		{
			uint64 TMP$112$3;
			TMP$112$3 = C$2;
			goto label$339;
			label$340:;
			{
				LEXEATCHAR(  );
				if( ((((int64)-(C$2 != 48ull) | (int64)-(*(int64*)((uint8*)T$1 + 4128ll) > 0ll)) | SAVE_FIRST_LEADING_ZERO$1) & ~(*SKIPCHAR$1)) == 0ll) goto label$342;
				{
					*(*PNUM$1) = (uint8)C$2;
					*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
					*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
					*VALUE$1 = (((*(uint64*)VALUE$1 << (3ll & 63ll)) + (*(uint64*)VALUE$1 << (1ll & 63ll))) + C$2) + 18446744073709551568ull;
				}
				label$342:;
				label$341:;
			}
			goto label$338;
			label$343:;
			{
				int64 HASDOT$4;
				HASDOT$4 = 0ll;
				if( C$2 != 46ull) goto label$345;
				{
					LEXEATCHAR(  );
					if( *SKIPCHAR$1 != 0ll) goto label$347;
					{
						*(*PNUM$1) = (uint8)46u;
						*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
						*(int64*)((uint8*)T$1 + 4128ll) = *(int64*)((uint8*)T$1 + 4128ll) + 1ll;
					}
					label$347:;
					label$346:;
					HASDOT$4 = -1ll;
				}
				label$345:;
				label$344:;
				HREADFLOATNUMBER( PNUM$1, T$1, HASDOT$4, *FLAGS$1 );
				goto label$336;
			}
			goto label$338;
			label$348:;
			{
				goto label$336;
			}
			goto label$338;
			label$339:;
			static const void* tmp$204[56ll] = {
				&&label$343,
				&&label$348,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$340,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$343,
				&&label$343,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$348,
				&&label$343,
				&&label$343,
			};
			if( (TMP$112$3 - 46ull) > 55ull ) goto label$348;
			goto *tmp$204[TMP$112$3 - 46ull];
			label$338:;
		}
		if( (*(int64*)FLAGS$1 & 8ll) != 0ll) goto label$350;
		{
			if( *SKIPCHAR$1 != 0ll) goto label$352;
			{
				{
					uint64 TMP$113$5;
					TMP$113$5 = *(uint64*)((uint8*)T$1 + 4128ll);
					goto label$354;
					label$355:;
					{
						if( *(uint64*)VALUE$1 <= 32767ull) goto label$357;
						{
							*(int64*)((uint8*)T$1 + 16ll) = 11ll;
						}
						label$357:;
						label$356:;
					}
					goto label$353;
					label$358:;
					{
						*(int64*)((uint8*)T$1 + 16ll) = 11ll;
					}
					goto label$353;
					label$359:;
					{
						if( *(uint64*)VALUE$1 <= 2147483647ull) goto label$361;
						{
							if( *(uint64*)VALUE$1 <= 4294967295ull) goto label$363;
							{
								*(int64*)((uint8*)T$1 + 16ll) = 13ll;
							}
							goto label$362;
							label$363:;
							{
								*(int64*)((uint8*)T$1 + 16ll) = 12ll;
							}
							label$362:;
						}
						label$361:;
						label$360:;
					}
					goto label$353;
					label$364:;
					{
						*(int64*)((uint8*)T$1 + 16ll) = 13ll;
					}
					goto label$353;
					label$365:;
					{
						if( *(uint64*)VALUE$1 <= 9223372036854775807ull) goto label$367;
						{
							*(int64*)((uint8*)T$1 + 16ll) = 14ll;
						}
						label$367:;
						label$366:;
						VALUE_PREV$1 = *VALUE$1;
					}
					goto label$353;
					label$368:;
					{
						*(int64*)((uint8*)T$1 + 16ll) = 14ll;
						if( (*(int64*)FLAGS$1 & 1ll) != 0ll) goto label$370;
						{
							if( ((int64)-(VALUE_PREV$1 > 1844674407370955161ull) | (int64)-((*(uint64*)VALUE$1 & 9223372036854775808ull) == 0ull)) == 0ll) goto label$372;
							{
								ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
								*SKIPCHAR$1 = -1ll;
							}
							label$372:;
							label$371:;
						}
						label$370:;
						label$369:;
					}
					goto label$353;
					label$373:;
					{
						if( (*(int64*)FLAGS$1 & 1ll) != 0ll) goto label$375;
						{
							ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
							*SKIPCHAR$1 = -1ll;
						}
						label$375:;
						label$374:;
					}
					goto label$353;
					label$354:;
					static const void* tmp$205[17ll] = {
						&&label$355,
						&&label$358,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$359,
						&&label$364,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$353,
						&&label$365,
						&&label$368,
						&&label$373,
					};
					if( (TMP$113$5 - 5ull) > 16ull ) goto label$353;
					goto *tmp$205[TMP$113$5 - 5ull];
					label$353:;
				}
				if( *(int64*)((uint8*)T$1 + 4128ll) != 64ll) goto label$377;
				{
					if( *SKIPCHAR$1 != 0ll) goto label$379;
					{
						*SKIPCHAR$1 = -1ll;
					}
					goto label$378;
					label$379:;
					{
						if( (*(int64*)FLAGS$1 & 1ll) != 0ll) goto label$381;
						{
							*FLAGS$1 = *(int64*)FLAGS$1 | 1ll;
							ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
						}
						label$381:;
						label$380:;
					}
					label$378:;
				}
				label$377:;
				label$376:;
			}
			label$352:;
			label$351:;
		}
		label$350:;
		label$349:;
	}
	label$337:;
	goto label$335;
	label$336:;
	if( *(int64*)((uint8*)T$1 + 4128ll) != 0ll) goto label$383;
	{
		*(*PNUM$1) = (uint8)48u;
		*PNUM$1 = (char*)((uint8*)*PNUM$1 + 1ll);
		*(int64*)((uint8*)T$1 + 4128ll) = 1ll;
	}
	label$383:;
	label$382:;
	label$334:;
}

static void HREADNUMBER( struct $7FBTOKEN* T$1, $8LEXCHECK FLAGS$1 )
{
	int64 TMP$116$1;
	label$384:;
	*(int64*)((uint8*)T$1 + 16ll) = 5ll;
	int64 HAVE_U_SUFFIX$1;
	HAVE_U_SUFFIX$1 = 0ll;
	int64 SKIPCHAR$1;
	SKIPCHAR$1 = 0ll;
	uint64 VALUE$1;
	__builtin_memset( &VALUE$1, 0, 8ll );
	uint8* PNUM$1;
	PNUM$1 = (uint8*)((uint8*)T$1 + 24ll);
	*PNUM$1 = (uint8)0u;
	*(int64*)((uint8*)T$1 + 4128ll) = 0ll;
	*(int64*)((uint8*)T$1 + 4144ll) = 0ll;
	{
		uint64 TMP$114$2;
		uint64 vr$7 = LEXCURRENTCHAR(  );
		TMP$114$2 = vr$7;
		goto label$387;
		label$388:;
		{
			READNUMBERCHARS( T$1, &FLAGS$1, (char**)&PNUM$1, &SKIPCHAR$1, &VALUE$1 );
		}
		goto label$386;
		label$389:;
		{
			LEXEATCHAR(  );
			*PNUM$1 = (uint8)46u;
			PNUM$1 = (uint8*)(PNUM$1 + 1ll);
			*(int64*)((uint8*)T$1 + 4128ll) = 1ll;
			HREADFLOATNUMBER( (char**)&PNUM$1, T$1, -1ll, FLAGS$1 );
		}
		goto label$386;
		label$390:;
		{
			*(int64*)((uint8*)T$1 + 4128ll) = 0ll;
			uint64 vr$22 = HREADNONDECNUMBER( (char**)&PNUM$1, (int64*)((uint8*)T$1 + 4128ll), (int64*)((uint8*)T$1 + 16ll), FLAGS$1 );
			VALUE$1 = vr$22;
		}
		goto label$386;
		label$387:;
		static const void* tmp$206[20ll] = {
			&&label$390,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$389,
			&&label$386,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
			&&label$388,
		};
		if( (TMP$114$2 - 38ull) > 19ull ) goto label$386;
		goto *tmp$206[TMP$114$2 - 38ull];
		label$386:;
	}
	*PNUM$1 = (uint8)0u;
	{
		int64 TMP$115$2;
		TMP$115$2 = *(int64*)((uint8*)T$1 + 16ll);
		if( TMP$115$2 != 5ll) goto label$392;
		label$393:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1464ll);
		}
		goto label$391;
		label$392:;
		if( TMP$115$2 != 6ll) goto label$394;
		label$395:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1472ll);
		}
		goto label$391;
		label$394:;
		if( TMP$115$2 != 11ll) goto label$396;
		label$397:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1480ll);
		}
		goto label$391;
		label$396:;
		if( TMP$115$2 != 12ll) goto label$398;
		label$399:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1488ll);
		}
		goto label$391;
		label$398:;
		if( TMP$115$2 != 13ll) goto label$400;
		label$401:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1496ll);
		}
		goto label$391;
		label$400:;
		if( TMP$115$2 != 14ll) goto label$402;
		label$403:;
		{
			*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1504ll);
		}
		label$402:;
		label$391:;
	}
	if( (*(int64*)((uint8*)T$1 + 16ll) & 480ll) == 0ll) goto label$404;
	TMP$116$1 = 24ll;
	goto label$962;
	label$404:;
	TMP$116$1 = *(int64*)((uint8*)T$1 + 16ll) & 31ll;
	label$962:;
	if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$116$1 * 56ll)) == 1ll) goto label$406;
	{
		if( (FLAGS$1 & 8ll) != 0ll) goto label$408;
		{
			if( (FLAGS$1 & 1024ll) != 0ll) goto label$410;
			{
				{
					uint64 TMP$117$5;
					uint64 vr$38 = LEXCURRENTCHAR(  );
					TMP$117$5 = vr$38;
					if( TMP$117$5 == 85ull) goto label$413;
					label$414:;
					if( TMP$117$5 != 117ull) goto label$412;
					label$413:;
					{
						*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
						LEXEATCHAR(  );
						int64 vr$41 = TYPETOUNSIGNED( *(int64*)((uint8*)T$1 + 16ll) );
						*(int64*)((uint8*)T$1 + 16ll) = vr$41;
						HAVE_U_SUFFIX$1 = -1ll;
					}
					label$412:;
					label$411:;
				}
			}
			label$410:;
			label$409:;
			{
				uint64 TMP$118$4;
				uint64 vr$43 = LEXCURRENTCHAR(  );
				TMP$118$4 = vr$43;
				goto label$416;
				label$417:;
				{
					if( (FLAGS$1 & 1024ll) != 0ll) goto label$419;
					{
						*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
						LEXEATCHAR(  );
						uint64 C$6;
						uint64 vr$46 = LEXCURRENTCHAR(  );
						C$6 = vr$46;
						if( ((int64)-(C$6 == 76ull) | (int64)-(C$6 == 108ull)) == 0ll) goto label$421;
						{
							$11FB_DATATYPE TMP$119$7;
							LEXEATCHAR(  );
							if( HAVE_U_SUFFIX$1 == 0ll) goto label$422;
							TMP$119$7 = 14ll;
							goto label$963;
							label$422:;
							TMP$119$7 = 13ll;
							label$963:;
							*(int64*)((uint8*)T$1 + 16ll) = TMP$119$7;
						}
						goto label$420;
						label$421:;
						{
							$11FB_DATATYPE TMP$120$7;
							if( VALUE$1 <= 4294967295ull) goto label$424;
							{
								if( SKIPCHAR$1 != 0ll) goto label$426;
								{
									if( (FLAGS$1 & 1ll) != 0ll) goto label$428;
									{
										ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
									}
									label$428:;
									label$427:;
								}
								label$426:;
								label$425:;
							}
							label$424:;
							label$423:;
							if( HAVE_U_SUFFIX$1 == 0ll) goto label$429;
							TMP$120$7 = 12ll;
							goto label$964;
							label$429:;
							TMP$120$7 = 11ll;
							label$964:;
							*(int64*)((uint8*)T$1 + 16ll) = TMP$120$7;
						}
						label$420:;
					}
					label$419:;
					label$418:;
				}
				goto label$415;
				label$430:;
				{
					if( (FLAGS$1 & 1024ll) != 0ll) goto label$432;
					{
						if( HAVE_U_SUFFIX$1 != 0ll) goto label$434;
						{
							*(int64*)((uint8*)T$1 + 16ll) = 15ll;
							*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
							LEXEATCHAR(  );
						}
						label$434:;
						label$433:;
					}
					label$432:;
					label$431:;
				}
				goto label$415;
				label$435:;
				{
					if( (FLAGS$1 & 1024ll) != 0ll) goto label$437;
					{
						if( HAVE_U_SUFFIX$1 != 0ll) goto label$439;
						{
							*(int64*)((uint8*)T$1 + 16ll) = 16ll;
							*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
							LEXEATCHAR(  );
						}
						label$439:;
						label$438:;
					}
					label$437:;
					label$436:;
				}
				goto label$415;
				label$440:;
				{
					int64 WARN$5;
					WARN$5 = 0ll;
					{
						int64 TMP$121$6;
						int64 TMP$122$6;
						if( (*(int64*)((uint8*)&ENV$ + 1456ll) & 480ll) == 0ll) goto label$441;
						TMP$121$6 = 24ll;
						goto label$965;
						label$441:;
						TMP$121$6 = *(int64*)((uint8*)&ENV$ + 1456ll) & 31ll;
						label$965:;
						TMP$122$6 = *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$121$6 * 56ll)) + 8ll);
						if( TMP$122$6 != 2ll) goto label$443;
						label$444:;
						{
							WARN$5 = (int64)-(VALUE$1 > 65535ull);
						}
						goto label$442;
						label$443:;
						if( TMP$122$6 != 4ll) goto label$445;
						label$446:;
						{
							WARN$5 = (int64)-(VALUE$1 > 4294967295ull);
						}
						label$445:;
						label$442:;
					}
					if( WARN$5 == 0ll) goto label$448;
					{
						if( SKIPCHAR$1 != 0ll) goto label$450;
						{
							if( (FLAGS$1 & 1ll) != 0ll) goto label$452;
							{
								ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
							}
							label$452:;
							label$451:;
						}
						label$450:;
						label$449:;
					}
					label$448:;
					label$447:;
					*(int64*)((uint8*)T$1 + 16ll) = *(int64*)((uint8*)&ENV$ + 1456ll);
					LEXEATCHAR(  );
				}
				goto label$415;
				label$453:;
				{
					if( VALUE$1 <= 4294967295ull) goto label$455;
					{
						if( SKIPCHAR$1 != 0ll) goto label$457;
						{
							if( (FLAGS$1 & 1ll) != 0ll) goto label$459;
							{
								ERRREPORTWARN( 8ll, (char*)0ull, 1ll, (char*)0ull );
							}
							label$459:;
							label$458:;
						}
						label$457:;
						label$456:;
					}
					label$455:;
					label$454:;
					*(int64*)((uint8*)T$1 + 16ll) = 11ll;
					*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
					LEXEATCHAR(  );
				}
				goto label$415;
				label$460:;
				{
					if( HAVE_U_SUFFIX$1 != 0ll) goto label$462;
					{
						*(int64*)((uint8*)T$1 + 16ll) = 15ll;
						*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
						LEXEATCHAR(  );
					}
					label$462:;
					label$461:;
				}
				goto label$415;
				label$463:;
				{
					if( HAVE_U_SUFFIX$1 != 0ll) goto label$465;
					{
						uint64 vr$71 = LEXGETLOOKAHEADCHAR(  );
						if( vr$71 == 35ull) goto label$467;
						{
							*(int64*)((uint8*)T$1 + 16ll) = 16ll;
							*(int64*)((uint8*)T$1 + 4144ll) = -1ll;
							LEXEATCHAR(  );
						}
						label$467:;
						label$466:;
					}
					label$465:;
					label$464:;
				}
				goto label$415;
				label$416:;
				static const void* tmp$207[76ll] = {
					&&label$460,
					&&label$415,
					&&label$463,
					&&label$415,
					&&label$440,
					&&label$453,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$435,
					&&label$415,
					&&label$430,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$417,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$435,
					&&label$415,
					&&label$430,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$415,
					&&label$417,
				};
				if( (TMP$118$4 - 33ull) > 75ull ) goto label$415;
				goto *tmp$207[TMP$118$4 - 33ull];
				label$415:;
			}
		}
		label$408:;
		label$407:;
	}
	label$406:;
	label$405:;
	*(int64*)((uint8*)T$1 + 8ll) = 3ll;
	*(int64*)T$1 = *(int64*)((uint8*)T$1 + 16ll);
	label$385:;
}

static void HREADSTRING( struct $7FBTOKEN* TK$1, char* PS$1, $8LEXCHECK FLAGS$1 )
{
	label$468:;
	int64 LGT$1;
	int64 HASESC$1;
	int64 ESCAPED$1;
	int64 SKIPCHAR$1;
	uint64 CHAR$1;
	*PS$1 = (uint8)0u;
	LGT$1 = 0ll;
	HASESC$1 = 0ll;
	ESCAPED$1 = (int64)-(*(int64*)TK$1 == 263ll);
	SKIPCHAR$1 = 0ll;
	if( (FLAGS$1 & 16ll) == 0ll) goto label$471;
	{
		uint64 vr$4 = LEXCURRENTCHAR(  );
		*PS$1 = (uint8)vr$4;
		PS$1 = (char*)((uint8*)PS$1 + 1ll);
		LGT$1 = LGT$1 + 1ll;
	}
	label$471:;
	label$470:;
	LEXEATCHAR(  );
	label$472:;
	{
		uint64 vr$9 = LEXCURRENTCHAR(  );
		CHAR$1 = vr$9;
		if( CHAR$1 != 34ull) goto label$476;
		{
			LEXEATCHAR(  );
			if( (FLAGS$1 & 16ll) == 0ll) goto label$478;
			{
				if( SKIPCHAR$1 != 0ll) goto label$480;
				{
					*PS$1 = (uint8)34u;
					PS$1 = (char*)((uint8*)PS$1 + 1ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$480:;
				label$479:;
			}
			label$478:;
			label$477:;
			uint64 vr$14 = LEXCURRENTCHAR(  );
			CHAR$1 = vr$14;
			if( CHAR$1 == 34ull) goto label$482;
			{
				goto label$473;
				label$482:;
			}
		}
		goto label$475;
		label$476:;
		if( CHAR$1 != 27ull) goto label$483;
		{
			if( (FLAGS$1 & 16ll) != 0ll) goto label$485;
			{
				if( SKIPCHAR$1 != 0ll) goto label$487;
				{
					*PS$1 = (uint8)27u;
					PS$1 = (char*)((uint8*)PS$1 + 1ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$487:;
				label$486:;
			}
			label$485:;
			label$484:;
		}
		goto label$475;
		label$483:;
		if( CHAR$1 != 92ull) goto label$488;
		{
			HASESC$1 = -1ll;
			if( ESCAPED$1 == 0ll) goto label$490;
			{
				LEXEATCHAR(  );
				if( SKIPCHAR$1 != 0ll) goto label$492;
				{
					*PS$1 = (uint8)92u;
					PS$1 = (char*)((uint8*)PS$1 + 1ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$492:;
				label$491:;
				uint64 vr$22 = LEXCURRENTCHAR(  );
				CHAR$1 = vr$22;
			}
			label$490:;
			label$489:;
		}
		label$488:;
		label$475:;
		{
			if( CHAR$1 == 0ull) goto label$495;
			label$496:;
			if( CHAR$1 == 13ull) goto label$495;
			label$497:;
			if( CHAR$1 != 10ull) goto label$494;
			label$495:;
			{
				if( (FLAGS$1 & 9ll) != 0ll) goto label$499;
				{
					ERRREPORTWARN( 12ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$499:;
				label$498:;
				goto label$473;
			}
			label$494:;
			label$493:;
		}
		LEXEATCHAR(  );
		if( SKIPCHAR$1 != 0ll) goto label$501;
		{
			if( LGT$1 != 1024ll) goto label$503;
			{
				if( (FLAGS$1 & 1ll) != 0ll) goto label$505;
				{
					FLAGS$1 = FLAGS$1 | 1ll;
					ERRREPORTWARN( 9ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$505:;
				label$504:;
				SKIPCHAR$1 = -1ll;
			}
			goto label$502;
			label$503:;
			{
				*PS$1 = (uint8)CHAR$1;
				PS$1 = (char*)((uint8*)PS$1 + 1ll);
				LGT$1 = LGT$1 + 1ll;
			}
			label$502:;
		}
		label$501:;
		label$500:;
	}
	label$474:;
	goto label$472;
	label$473:;
	*PS$1 = (uint8)0u;
	*(int64*)((uint8*)TK$1 + 16ll) = 4ll;
	*(int64*)((uint8*)TK$1 + 4128ll) = LGT$1;
	*(int64*)((uint8*)TK$1 + 4144ll) = HASESC$1;
	label$469:;
}

static void HREADWSTR( struct $7FBTOKEN* TK$1, uint32* PS$1, $8LEXCHECK FLAGS$1 )
{
	label$506:;
	int64 LGT$1;
	int64 HASESC$1;
	int64 ESCAPED$1;
	int64 SKIPCHAR$1;
	uint64 CHAR$1;
	*PS$1 = (uint32)0u;
	LGT$1 = 0ll;
	HASESC$1 = 0ll;
	ESCAPED$1 = (int64)-(*(int64*)TK$1 == 263ll);
	SKIPCHAR$1 = 0ll;
	if( (FLAGS$1 & 16ll) == 0ll) goto label$509;
	{
		uint64 vr$4 = LEXCURRENTCHAR(  );
		*PS$1 = (uint32)(uint32)vr$4;
		PS$1 = (uint32*)((uint8*)PS$1 + 4ll);
		LGT$1 = LGT$1 + 1ll;
	}
	label$509:;
	label$508:;
	LEXEATCHAR(  );
	label$510:;
	{
		uint64 vr$9 = LEXCURRENTCHAR(  );
		CHAR$1 = vr$9;
		if( CHAR$1 != 34ull) goto label$514;
		{
			LEXEATCHAR(  );
			if( (FLAGS$1 & 16ll) == 0ll) goto label$516;
			{
				if( SKIPCHAR$1 != 0ll) goto label$518;
				{
					*PS$1 = (uint32)34u;
					PS$1 = (uint32*)((uint8*)PS$1 + 4ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$518:;
				label$517:;
			}
			label$516:;
			label$515:;
			uint64 vr$14 = LEXCURRENTCHAR(  );
			CHAR$1 = vr$14;
			if( CHAR$1 == 34ull) goto label$520;
			{
				goto label$511;
				label$520:;
			}
		}
		goto label$513;
		label$514:;
		if( CHAR$1 != 27ull) goto label$521;
		{
			if( (FLAGS$1 & 16ll) != 0ll) goto label$523;
			{
				if( SKIPCHAR$1 != 0ll) goto label$525;
				{
					*PS$1 = (uint32)27u;
					PS$1 = (uint32*)((uint8*)PS$1 + 4ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$525:;
				label$524:;
			}
			label$523:;
			label$522:;
		}
		goto label$513;
		label$521:;
		if( CHAR$1 != 92ull) goto label$526;
		{
			HASESC$1 = -1ll;
			if( ESCAPED$1 == 0ll) goto label$528;
			{
				LEXEATCHAR(  );
				if( SKIPCHAR$1 != 0ll) goto label$530;
				{
					*PS$1 = (uint32)92u;
					PS$1 = (uint32*)((uint8*)PS$1 + 4ll);
					LGT$1 = LGT$1 + 1ll;
				}
				label$530:;
				label$529:;
				uint64 vr$22 = LEXCURRENTCHAR(  );
				CHAR$1 = vr$22;
			}
			label$528:;
			label$527:;
		}
		label$526:;
		label$513:;
		{
			if( CHAR$1 == 0ull) goto label$533;
			label$534:;
			if( CHAR$1 == 13ull) goto label$533;
			label$535:;
			if( CHAR$1 != 10ull) goto label$532;
			label$533:;
			{
				if( (FLAGS$1 & 9ll) != 0ll) goto label$537;
				{
					ERRREPORTWARN( 12ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$537:;
				label$536:;
				goto label$511;
			}
			label$532:;
			label$531:;
		}
		LEXEATCHAR(  );
		if( SKIPCHAR$1 != 0ll) goto label$539;
		{
			if( LGT$1 != 1024ll) goto label$541;
			{
				if( (FLAGS$1 & 1ll) != 0ll) goto label$543;
				{
					FLAGS$1 = FLAGS$1 | 1ll;
					ERRREPORTWARN( 9ll, (char*)0ull, 1ll, (char*)0ull );
				}
				label$543:;
				label$542:;
				SKIPCHAR$1 = -1ll;
			}
			goto label$540;
			label$541:;
			{
				*PS$1 = (uint32)(uint32)CHAR$1;
				PS$1 = (uint32*)((uint8*)PS$1 + 4ll);
				LGT$1 = LGT$1 + 1ll;
			}
			label$540:;
		}
		label$539:;
		label$538:;
	}
	label$512:;
	goto label$510;
	label$511:;
	*PS$1 = (uint32)0u;
	*(int64*)((uint8*)TK$1 + 16ll) = 7ll;
	*(int64*)((uint8*)TK$1 + 4128ll) = LGT$1;
	*(int64*)((uint8*)TK$1 + 4144ll) = HASESC$1;
	label$507:;
}

static void HCHECKPERIODS( struct $7FBTOKEN* T$1, $8LEXCHECK FLAGS$1, struct $10FBSYMCHAIN* CHAIN_$1 )
{
	label$544:;
	int64 READFULLID$1;
	if( CHAIN_$1 == (struct $10FBSYMCHAIN*)0ull) goto label$547;
	{
		READFULLID$1 = 0ll;
		uint64 vr$0 = LEXCURRENTCHAR(  );
		if( vr$0 != 46ull) goto label$549;
		{
			if( *(int64*)*(struct $8FBSYMBOL**)CHAIN_$1 == 8ll) goto label$551;
			{
				READFULLID$1 = -1ll;
				label$552:;
				if( CHAIN_$1 == (struct $10FBSYMCHAIN*)0ull) goto label$553;
				{
					struct $8FBSYMBOL* SYM$5;
					SYM$5 = *(struct $8FBSYMBOL**)CHAIN_$1;
					label$554:;
					{
						if( *(int64*)SYM$5 != 1ll) goto label$558;
						{
							if( (*(int64*)((uint8*)SYM$5 + 56ll) & 511ll) != 20ll) goto label$560;
							{
								goto label$545;
							}
							label$560:;
							label$559:;
						}
						label$558:;
						label$557:;
						SYM$5 = *(struct $8FBSYMBOL**)((uint8*)SYM$5 + 280ll);
					}
					label$556:;
					if( SYM$5 != (struct $8FBSYMBOL*)0ull) goto label$554;
					label$555:;
					CHAIN_$1 = *(struct $10FBSYMCHAIN**)((uint8*)CHAIN_$1 + 8ll);
				}
				goto label$552;
				label$553:;
			}
			label$551:;
			label$550:;
		}
		label$549:;
		label$548:;
	}
	goto label$546;
	label$547:;
	{
		uint64 vr$9 = LEXCURRENTCHAR(  );
		READFULLID$1 = (int64)-(vr$9 == 46ull);
	}
	label$546:;
	if( READFULLID$1 == 0ll) goto label$562;
	{
		*(int64*)((uint8*)T$1 + 4144ll) = *(int64*)((uint8*)T$1 + 4128ll);
		HREADIDENTIFIER( (char*)((uint8*)((uint8*)T$1 + 24ll) + *(int64*)((uint8*)T$1 + 4128ll)), (int64*)((uint8*)T$1 + 4128ll), (int64*)((uint8*)T$1 + 16ll), (int64*)((uint8*)T$1 + 4152ll), FLAGS$1 | 128ll );
		struct $10FBSYMCHAIN* vr$30 = SYMBLOOKUP( (char*)((uint8*)T$1 + 24ll), ($8FB_TOKEN*)T$1, ($10FB_TKCLASS*)((uint8*)T$1 + 8ll) );
		*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) = vr$30;
	}
	label$562:;
	label$561:;
	label$545:;
}

static int64 READID( struct $7FBTOKEN* T$1, $8LEXCHECK FLAGS$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$563:;
	struct $8FBSYMBOL* CURRMACRO$1;
	CURRMACRO$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16776ll);
	*(int64*)((uint8*)T$1 + 4128ll) = 0ll;
	*(int64*)((uint8*)T$1 + 4144ll) = 0ll;
	HREADIDENTIFIER( (char*)((uint8*)T$1 + 24ll), (int64*)((uint8*)T$1 + 4128ll), (int64*)((uint8*)T$1 + 16ll), (int64*)((uint8*)T$1 + 4152ll), FLAGS$1 );
	if( (FLAGS$1 & 256ll) == 0ll) goto label$566;
	{
		struct $10FBSYMCHAIN* vr$16 = SYMBLOOKUPAT( *(struct $8FBSYMBOL**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16784ll), (char*)((uint8*)T$1 + 24ll), 0ll, 0ll );
		*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) = vr$16;
		if( *(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) != (struct $10FBSYMCHAIN*)0ull) goto label$568;
		{
			*(int64*)T$1 = 265ll;
			*(int64*)((uint8*)T$1 + 8ll) = 0ll;
		}
		goto label$567;
		label$568:;
		{
			*(int64*)T$1 = *(int64*)((uint8*)*(struct $8FBSYMBOL**)*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) + 96ll);
			*(int64*)((uint8*)T$1 + 8ll) = *(int64*)((uint8*)*(struct $8FBSYMBOL**)*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) + 104ll);
		}
		label$567:;
		fb$result$1 = -1ll;
		goto label$564;
	}
	label$566:;
	label$565:;
	if( (FLAGS$1 & 32ll) == 0ll) goto label$570;
	{
		*(int64*)T$1 = 265ll;
		*(int64*)((uint8*)T$1 + 8ll) = 0ll;
		fb$result$1 = -1ll;
		goto label$564;
	}
	label$570:;
	label$569:;
	struct $10FBSYMCHAIN* vr$38 = SYMBLOOKUP( (char*)((uint8*)T$1 + 24ll), ($8FB_TOKEN*)T$1, ($10FB_TKCLASS*)((uint8*)T$1 + 8ll) );
	*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) = vr$38;
	if( (FLAGS$1 & 2ll) == 0ll) goto label$572;
	{
		fb$result$1 = -1ll;
		goto label$564;
	}
	label$572:;
	label$571:;
	if( *(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) == (struct $10FBSYMCHAIN*)0ull) goto label$574;
	{
		if( *(int64*)*(struct $8FBSYMBOL**)*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) != 5ll) goto label$576;
		{
			int64 vr$47 = PPDEFINELOAD( *(struct $8FBSYMBOL**)*(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll), CURRMACRO$1 );
			if( vr$47 == 0ll) goto label$578;
			{
				*(int64*)((uint8*)T$1 + 4160ll) = -1ll;
				fb$result$1 = 0ll;
				goto label$564;
			}
			label$578:;
			label$577:;
		}
		label$576:;
		label$575:;
	}
	label$574:;
	label$573:;
	if( (*(int64*)((uint8*)&ENV$ + 1448ll) & 524288ll) == 0ll) goto label$580;
	{
		if( (FLAGS$1 & 64ll) != 0ll) goto label$582;
		{
			HCHECKPERIODS( T$1, FLAGS$1, *(struct $10FBSYMCHAIN**)((uint8*)T$1 + 4136ll) );
		}
		label$582:;
		label$581:;
	}
	label$580:;
	label$579:;
	fb$result$1 = -1ll;
	goto label$564;
	label$564:;
	return fb$result$1;
}

static void HMULTILINECOMMENT( void )
{
	label$703:;
	static int64 CNT$1;
	LEXEATCHAR(  );
	CNT$1 = 0ll;
	label$705:;
	{
		{
			uint64 TMP$138$3;
			uint64 vr$0 = LEXCURRENTCHAR(  );
			TMP$138$3 = vr$0;
			goto label$709;
			label$710:;
			{
				ERRREPORTEX( 132ll, (char*)0ull, 0ll, 1ll, (char*)0ull );
				goto label$704;
			}
			goto label$708;
			label$711:;
			{
				LEXEATCHAR(  );
				uint64 vr$1 = LEXCURRENTCHAR(  );
				if( vr$1 != 10ull) goto label$713;
				{
					LEXEATCHAR(  );
				}
				label$713:;
				label$712:;
				if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) != 0ll) goto label$715;
				{
					*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) + 1ll;
				}
				label$715:;
				label$714:;
			}
			goto label$708;
			label$716:;
			{
				LEXEATCHAR(  );
				if( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) != 0ll) goto label$718;
				{
					*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) + 1ll;
				}
				label$718:;
				label$717:;
			}
			goto label$708;
			label$719:;
			{
				LEXEATCHAR(  );
				uint64 vr$10 = LEXCURRENTCHAR(  );
				if( vr$10 != 39ull) goto label$721;
				{
					LEXEATCHAR(  );
					CNT$1 = CNT$1 + 1ll;
				}
				label$721:;
				label$720:;
			}
			goto label$708;
			label$722:;
			{
				LEXEATCHAR(  );
				uint64 vr$12 = LEXCURRENTCHAR(  );
				if( vr$12 != 47ull) goto label$724;
				{
					LEXEATCHAR(  );
					if( CNT$1 != 0ll) goto label$726;
					{
						goto label$706;
					}
					label$726:;
					label$725:;
					CNT$1 = CNT$1 + -1ll;
				}
				label$724:;
				label$723:;
			}
			goto label$708;
			label$727:;
			{
				LEXEATCHAR(  );
			}
			goto label$708;
			label$709:;
			static const void* tmp$208[48ll] = {
				&&label$710,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$716,
				&&label$727,
				&&label$727,
				&&label$711,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$722,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$727,
				&&label$719,
			};
			if( TMP$138$3 > 47ull ) goto label$727;
			goto *tmp$208[TMP$138$3 - 0ull];
			label$708:;
		}
	}
	label$707:;
	goto label$705;
	label$706:;
	label$704:;
}

static void HMOVEKDOWN( void )
{
	label$752:;
	*(int64*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = -1ll;
	*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16704ll) + -1ll;
	*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) = *(struct $7FBTOKEN**)((uint8*)*(struct $7FBTOKEN**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16712ll) + 4168ll);
	label$753:;
}

static FBSTRING* LEXGETSTRLITTEXT( int64 TK$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$754:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	int64 IS_ESCAPED$1;
	int64 SAW_BACKSLASH$1;
	uint8* P$1;
	{
		if( TK$1 != 262ll) goto label$757;
		label$758:;
		{
			IS_ESCAPED$1 = 0ll;
		}
		goto label$756;
		label$757:;
		if( TK$1 != 263ll) goto label$759;
		label$760:;
		{
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"!", 2ll, 0 );
			IS_ESCAPED$1 = -1ll;
		}
		goto label$756;
		label$759:;
		if( TK$1 != 264ll) goto label$761;
		label$762:;
		{
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"$", 2ll, 0 );
			IS_ESCAPED$1 = 0ll;
		}
		label$761:;
		label$756:;
	}
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"\x22", 2ll, 0 );
	SAW_BACKSLASH$1 = 0ll;
	char* vr$5 = LEXGETTEXT(  );
	P$1 = (uint8*)vr$5;
	label$763:;
	{
		{
			uint8 TMP$142$3;
			TMP$142$3 = *P$1;
			if( (int64)TMP$142$3 != 0ll) goto label$767;
			label$768:;
			{
				goto label$764;
			}
			goto label$766;
			label$767:;
			if( (uint64)(int64)TMP$142$3 != 34ull) goto label$769;
			label$770:;
			{
				if( SAW_BACKSLASH$1 == 0ll) goto label$772;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"\x22", 2ll, 0 );
				}
				goto label$771;
				label$772:;
				{
					fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"\x22\x22", 3ll, 0 );
				}
				label$771:;
				SAW_BACKSLASH$1 = 0ll;
			}
			goto label$766;
			label$769:;
			if( (uint64)(int64)TMP$142$3 != 92ull) goto label$773;
			label$774:;
			{
				SAW_BACKSLASH$1 = IS_ESCAPED$1;
				fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"\x5C", 2ll, 0 );
			}
			goto label$766;
			label$773:;
			{
				FBSTRING TMP$145$4;
				SAW_BACKSLASH$1 = 0ll;
				FBSTRING* vr$15 = fb_CHR( 1, (int64)*P$1 );
				__builtin_memset( &TMP$145$4, 0, 24ll );
				FBSTRING* vr$19 = fb_StrConcat( &TMP$145$4, (void*)&S$1, -1ll, (void*)vr$15, -1ll );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$19, -1ll, 0 );
			}
			label$775:;
			label$766:;
		}
		P$1 = (uint8*)(P$1 + 1ll);
	}
	label$765:;
	goto label$763;
	label$764:;
	fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"\x22", 2ll, 0 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$755:;
	FBSTRING* vr$27 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$27;
}
