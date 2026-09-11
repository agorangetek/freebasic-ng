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
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
struct $15ASMKEYWORDSINFO {
	int64 INITED;
	struct $5THASH HASH;
	struct $5TLIST LIST;
};
__FB_STATIC_ASSERT( sizeof( struct $15ASMKEYWORDSINFO ) == 96 );
void* calloc( uint64, uint64 );
void free( void* );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_WstrAssignToA( void*, int64, uint32*, int32 );
void fb_StrDelete( FBSTRING* );
void fb_WstrDelete( uint32* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
uint32* fb_WstrConcatAW( void*, int64, uint32* );
FBSTRING* fb_StrAllocTempDescZ( char* );
int64 fb_StrLen( void*, int64 );
FBSTRING* fb_StrLcase2( FBSTRING*, int32 );
static void fb_ctor__parserzinlineasm( void ) __attribute__(( constructor ));
void LISTINIT( struct $5TLIST*, int64, int64, $10LIST_FLAGS );
void LISTEND( struct $5TLIST* );
void* LISTNEWNODE( struct $5TLIST* );
void* LISTGETHEAD( struct $5TLIST* );
void* LISTGETNEXT( void* );
void HASHINIT( struct $5THASH*, int64, int64 );
void HASHEND( struct $5THASH* );
void* HASHLOOKUP( struct $5THASH*, char* );
struct $8HASHITEM* HASHADD( struct $5THASH*, char*, void*, uint64 );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
void ERRREPORT( int64, int64, char* );
int64 FBGETCPUFAMILY( void );
void ASTDELTREE( struct $7ASTNODE* );
struct $7ASTNODE* ASTADD( struct $7ASTNODE* );
FBSTRING* ASTCONSTFLUSHTOSTR( struct $7ASTNODE* );
struct $7ASTNODE* ASTNEWLIT( char* );
struct $9ASTASMTOK* ASTASMAPPENDTEXT( struct $9ASTASMTOK*, char* );
struct $9ASTASMTOK* ASTASMAPPENDSYMB( struct $9ASTASMTOK*, struct $8FBSYMBOL* );
struct $7ASTNODE* ASTNEWASM( struct $9ASTASMTOK* );
struct $7ASTNODE* ASTNEWDBG( int64, int64, char* );
struct $8FBSYMBOL* ASTGETSTRLITSYMBOL( struct $7ASTNODE* );
struct $8FBSYMBOL* SYMBFINDBYCLASS( struct $10FBSYMCHAIN*, int64 );
struct $8FBSYMBOL* SYMBGETPROCRESULT( struct $8FBSYMBOL* );
FBSTRING* SYMBGETCONSTVALUEASSTR( struct $8FBSYMBOL* );
void DZSTRRESET( struct $8DZSTRING* );
typedef int64 $8LEXCHECK;
int64 LEXGETTOKEN( $8LEXCHECK );
int64 LEXGETCLASS( $8LEXCHECK );
char* LEXGETTEXT( void );
void LEXSKIPTOKEN( $8LEXCHECK );
int64 HMATCH( int64, $8LEXCHECK );
int64 PARSERISGLOBALASMKEYWORD( char* );
int64 CCOMMENT( $8LEXCHECK );
int64 CSTMTSEPARATOR( $8LEXCHECK );
typedef int64 $8FB_IDOPT;
struct $10FBSYMCHAIN* CIDENTIFIER( struct $8FBSYMBOL**, $8FB_IDOPT );
typedef int64 $15FB_CMPSTMT_MASK;
int64 CCOMPSTMTISALLOWED( $15FB_CMPSTMT_MASK );
typedef int64 $8FB_TOKEN;
struct $7ASTNODE* CTYPECONVEXPR( $8FB_TOKEN, int64 );
struct $7ASTNODE* CSTRLITERAL( int64 );
struct $7ASTNODE* CNUMLITERAL( int64 );
struct $7ASTNODE* CMATHFUNCT( $8FB_TOKEN, int64 );
void HSKIPUNTIL( int64, int64, $8LEXCHECK, int64 );
void HSKIPCOMPOUND( int64, int64, $8LEXCHECK );
static void HINITINLINEASMKEYWORDS( void );
static void HINITGLOBALASMKEYWORDS( void );
static void HASMKEYWORDSEND( struct $15ASMKEYWORDSINFO* );
static int64 HISINLINEASMKEYWORD( char* );
static void HADDASMKEYWORD( struct $15ASMKEYWORDSINFO*, char* );
void CASMCODE( void );
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
static char* INLINEASMKEYWORDSX86$[556] = { (char*)"byte", (char*)"ptr", (char*)"offset", (char*)"aaa", (char*)"aad", (char*)"aam", (char*)"aas", (char*)"adc", (char*)"add", (char*)"addpd", (char*)"addps", (char*)"addsd", (char*)"addss", (char*)"and", (char*)"andpd", (char*)"andps", (char*)"andnpd", (char*)"andnps", (char*)"arpl", (char*)"bound", (char*)"bsf", (char*)"bsr", (char*)"bswap", (char*)"bt", (char*)"btc", (char*)"btr", (char*)"bts", (char*)"call", (char*)"cbw", (char*)"cwde", (char*)"cdq", (char*)"clc", (char*)"cld", (char*)"clflush", (char*)"cli", (char*)"clts", (char*)"cmc", (char*)"cmova", (char*)"cmovae", (char*)"cmovb", (char*)"cmovbe", (char*)"cmovc", (char*)"cmove", (char*)"cmovg", (char*)"cmovge", (char*)"cmovl", (char*)"cmovle", (char*)"cmovna", (char*)"cmovnae", (char*)"cmovnb", (char*)"cmovnbe", (char*)"cmovnc", (char*)"cmovne", (char*)"cmovng", (char*)"cmovnge", (char*)"cmovnl", (char*)"cmovnle", (char*)"cmovno", (char*)"cmovnp", (char*)"cmovns", (char*)"cmovnz", (char*)"cmovo", (char*)"cmovp", (char*)"cmovpe", (char*)"cmovpe", (char*)"cmovpo", (char*)"cmovs", (char*)"cmovz", (char*)"cmp", (char*)"cmppd", (char*)"cmpps", (char*)"cmps", (char*)"cmpsb", (char*)"cmpsw", (char*)"cmpsd", (char*)"cmpss", (char*)"cmpxchg", (char*)"cmpxchg8b", (char*)"comisd", (char*)"comiss", (char*)"cpuid", (char*)"cvtdq2pd", (char*)"cvtdq2ps", (char*)"cvtpd2dq", (char*)"cvtpd2pi", (char*)"cvtpd2ps", (char*)"cvtpi2pd", (char*)"cvtpi2ps", (char*)"cvtps2dq", (char*)"cvtps2pd", (char*)"cvtps2pi", (char*)"cvtsd2si", (char*)"cvtsd2ss", (char*)"cvtsi2sd", (char*)"cvtsi2ss", (char*)"cvtss2sd", (char*)"cvtss2si", (char*)"cvttpd2pi", (char*)"cvttpd2dq", (char*)"cvttps2dq", (char*)"cvttps2pi", (char*)"cvttsd2si", (char*)"cvttss2si", (char*)"cwd", (char*)"daa", (char*)"das", (char*)"dec", (char*)"div", (char*)"divpd", (char*)"divps", (char*)"divss", (char*)"emms", (char*)"enter", (char*)"f2xm1", (char*)"fabs", (char*)"fadd", (char*)"faddp", (char*)"fiadd", (char*)"fbld", (char*)"fbstp", (char*)"fchs", (char*)"fclex", (char*)"fnclex", (char*)"fcmovb", (char*)"fcmove", (char*)"fcmovbe", (char*)"fcmovu", (char*)"fcmovnb", (char*)"fcmovne", (char*)"fcmovnbe", (char*)"fcmovnu", (char*)"fcom", (char*)"fcomp", (char*)"fcompp", (char*)"fcomi", (char*)"fcomip", (char*)"fucomi", (char*)"fucomip", (char*)"fcos", (char*)"fdecstp", (char*)"fdiv", (char*)"fdivp", (char*)"fidiv", (char*)"fdivr", (char*)"fdivrp", (char*)"fidivr", (char*)"ffree", (char*)"ficom", (char*)"ficomp", (char*)"fild", (char*)"fincstp", (char*)"finit", (char*)"fninit", (char*)"fist", (char*)"fistp", (char*)"fld", (char*)"fld1", (char*)"fldl2t", (char*)"fldl2e", (char*)"fldpi", (char*)"fldlg2", (char*)"fldln2", (char*)"fldz", (char*)"fldcw", (char*)"fldenv", (char*)"fmul", (char*)"fmulp", (char*)"fimul", (char*)"fnop", (char*)"fpatan", (char*)"fprem", (char*)"fprem1", (char*)"fptan", (char*)"frndint", (char*)"frstor", (char*)"fsave", (char*)"fnsave", (char*)"fscale", (char*)"fsin", (char*)"fsincos", (char*)"fsqrt", (char*)"fst", (char*)"fstp", (char*)"fstcw", (char*)"fnstcw", (char*)"fstenv", (char*)"fnstenv", (char*)"fstsw", (char*)"fnstsw", (char*)"fsub", (char*)"fsubp", (char*)"fisub", (char*)"fsubr", (char*)"fsubrp", (char*)"fisubr", (char*)"ftst", (char*)"fucom", (char*)"fucomp", (char*)"fucompp", (char*)"fwait", (char*)"fxam", (char*)"fxch", (char*)"fxrstor", (char*)"fxsave", (char*)"fxtract", (char*)"fyl2x", (char*)"fyl2xp1", (char*)"hlt", (char*)"idiv", (char*)"imul", (char*)"in", (char*)"inc", (char*)"ins", (char*)"insb", (char*)"insw", (char*)"insd", (char*)"int", (char*)"into", (char*)"invd", (char*)"invlpg", (char*)"iret", (char*)"iretd", (char*)"ja", (char*)"jae", (char*)"jb", (char*)"jbe", (char*)"jc", (char*)"jcxz", (char*)"jecxz", (char*)"je", (char*)"jg", (char*)"jge", (char*)"jl", (char*)"jle", (char*)"jna", (char*)"jnae", (char*)"jnb", (char*)"jnbe", (char*)"jnc", (char*)"jne", (char*)"jng", (char*)"jnge", (char*)"jnl", (char*)"jnle", (char*)"jno", (char*)"jnp", (char*)"jns", (char*)"jnz", (char*)"jo", (char*)"jp", (char*)"jpe", (char*)"jpo", (char*)"js", (char*)"jz", (char*)"jmp", (char*)"lahf", (char*)"lar", (char*)"ldmxcsr", (char*)"lds", (char*)"les", (char*)"lfs", (char*)"lgs", (char*)"lss", (char*)"lea", (char*)"leave", (char*)"lfence", (char*)"lgdt", (char*)"lidt", (char*)"lldt", (char*)"lmsw", (char*)"lock", (char*)"lods", (char*)"lodsb", (char*)"lodsw", (char*)"lodsd", (char*)"loop", (char*)"loope", (char*)"loopz", (char*)"loopne", (char*)"loopnz", (char*)"lsl", (char*)"ltr", (char*)"maskmovdqu", (char*)"maskmovq", (char*)"maxpd", (char*)"maxps", (char*)"maxsd", (char*)"maxss", (char*)"mfence", (char*)"minpd", (char*)"minps", (char*)"minsd", (char*)"minss", (char*)"mov", (char*)"movapd", (char*)"movaps", (char*)"movd", (char*)"movdqa", (char*)"movdqu", (char*)"movdq2q", (char*)"movhlps", (char*)"movhpd", (char*)"movhps", (char*)"movlhps", (char*)"movlpd", (char*)"movlps", (char*)"movmskpd", (char*)"movmskps", (char*)"movntdq", (char*)"movnti", (char*)"movntpd", (char*)"movntps", (char*)"movntq", (char*)"movq", (char*)"movq2dq", (char*)"movs", (char*)"movsb", (char*)"movsw", (char*)"movsd", (char*)"movss", (char*)"movsx", (char*)"movupd", (char*)"movups", (char*)"movzx", (char*)"mul", (char*)"mulpd", (char*)"mulps", (char*)"mulsd", (char*)"mulss", (char*)"neg", (char*)"nop", (char*)"not", (char*)"or", (char*)"orpd", (char*)"orps", (char*)"out", (char*)"outs", (char*)"outsb", (char*)"outsw", (char*)"outsd", (char*)"packsswb", (char*)"packssdw", (char*)"packuswb", (char*)"paddb", (char*)"paddw", (char*)"paddd", (char*)"paddq", (char*)"paddsb", (char*)"paddsw", (char*)"paddusb", (char*)"paddusw", (char*)"pand", (char*)"pandn", (char*)"pause", (char*)"pavgb", (char*)"pavgw", (char*)"pcmpeqb", (char*)"pcmpeqw", (char*)"pcmpeqd", (char*)"pcmpgtb", (char*)"pcmpgtw", (char*)"pcmpgtd", (char*)"pextrw", (char*)"pinsrw", (char*)"pmaddwd", (char*)"pmaxsw", (char*)"pmaxub", (char*)"pminsw", (char*)"pminub", (char*)"pmovmskb", (char*)"pmulhuv", (char*)"pmulhw", (char*)"pmullw", (char*)"pmuludq", (char*)"pop", (char*)"popa", (char*)"popad", (char*)"popf", (char*)"popfd", (char*)"por", (char*)"prefetcht0", (char*)"prefetcht1", (char*)"prefetcht2", (char*)"prefetchnta", (char*)"psadbw", (char*)"pshufd", (char*)"pshufhw", (char*)"pshuflw", (char*)"pshufw", (char*)"psllw", (char*)"pslld", (char*)"psllq", (char*)"psraw", (char*)"psrad", (char*)"psrldq", (char*)"psrlw", (char*)"psrld", (char*)"psrlq", (char*)"psubb", (char*)"psubw", (char*)"psubd", (char*)"psubq", (char*)"psubsb", (char*)"psubsw", (char*)"psubusb", (char*)"psubusw", (char*)"punpckhbw", (char*)"punpckhwd", (char*)"punpckhdq", (char*)"punpckhqdq", (char*)"punpcklbw", (char*)"punpcklwd", (char*)"punpckldq", (char*)"punpcklqdq", (char*)"push", (char*)"pusha", (char*)"pushad", (char*)"pushf", (char*)"pushfd", (char*)"pxor", (char*)"rcl", (char*)"rcr", (char*)"rol", (char*)"ror", (char*)"rcpps", (char*)"rcpss", (char*)"rdmsr", (char*)"rdpmc", (char*)"rdtsc", (char*)"rep", (char*)"repe", (char*)"repz", (char*)"repne", (char*)"repnz", (char*)"ret", (char*)"rsm", (char*)"rsqrtps", (char*)"rsqrtss", (char*)"sahf", (char*)"sal", (char*)"sar", (char*)"shl", (char*)"shr", (char*)"sbb", (char*)"scas", (char*)"scasb", (char*)"scasw", (char*)"scasd", (char*)"seta", (char*)"setae", (char*)"setb", (char*)"setbe", (char*)"setc", (char*)"sete", (char*)"setg", (char*)"setge", (char*)"setl", (char*)"setle", (char*)"setna", (char*)"setnae", (char*)"setnb", (char*)"setnbe", (char*)"setnc", (char*)"setne", (char*)"setng", (char*)"setnge", (char*)"setnl", (char*)"setnle", (char*)"setno", (char*)"setnp", (char*)"setns", (char*)"setnz", (char*)"seto", (char*)"setp", (char*)"setpe", (char*)"setpo", (char*)"sets", (char*)"setz", (char*)"sfence", (char*)"sgdt", (char*)"sidt", (char*)"shld", (char*)"shrd", (char*)"shufpd", (char*)"shufps", (char*)"sldt", (char*)"smsw", (char*)"sqrtpd", (char*)"sqrtps", (char*)"sqrtsd", (char*)"sqrtss", (char*)"stc", (char*)"std", (char*)"sti", (char*)"stmxcsr", (char*)"stos", (char*)"stosb", (char*)"stosw", (char*)"stosd", (char*)"str", (char*)"sub", (char*)"subpd", (char*)"subps", (char*)"subsd", (char*)"subss", (char*)"sysenter", (char*)"sysexit", (char*)"test", (char*)"ucomisd", (char*)"ucomiss", (char*)"ud2", (char*)"unpckhpd", (char*)"unpckhps", (char*)"unpcklpd", (char*)"unpcklps", (char*)"verr", (char*)"verw", (char*)"wait", (char*)"wbinvd", (char*)"wrmsr", (char*)"xadd", (char*)"xchg", (char*)"xlat", (char*)"xlatb", (char*)"xor", (char*)"xorpd", (char*)"xorps", (char*)"pavgusb", (char*)"pfadd", (char*)"pfsub", (char*)"pfsubr", (char*)"pfacc", (char*)"pfcmpge", (char*)"pfcmpgt", (char*)"pfcmpeq", (char*)"pfmin", (char*)"pfmax", (char*)"pi2fw", (char*)"pi2fd", (char*)"pf2iw", (char*)"pf2id", (char*)"pfrcp", (char*)"pfrsqrt", (char*)"pfmul", (char*)"pfrcpit1", (char*)"pfrsqit1", (char*)"pfrcpit2", (char*)"pmulhrw", (char*)"pswapw", (char*)"femms", (char*)"prefetch", (char*)"prefetchw", (char*)"pfnacc", (char*)"pfpnacc", (char*)"pswapd", (char*)"pmulhuw" };
static char* GLOBALASMKEYWORDSX86$[177] = { (char*)"dl", (char*)"di", (char*)"si", (char*)"cl", (char*)"bl", (char*)"al", (char*)"bp", (char*)"sp", (char*)"dx", (char*)"cx", (char*)"bx", (char*)"ax", (char*)"edx", (char*)"edi", (char*)"esi", (char*)"ecx", (char*)"ebx", (char*)"eax", (char*)"ebp", (char*)"esp", (char*)"st", (char*)"cs", (char*)"ds", (char*)"es", (char*)"fs", (char*)"gs", (char*)"ss", (char*)"mm0", (char*)"mm1", (char*)"mm2", (char*)"mm3", (char*)"mm4", (char*)"mm5", (char*)"mm6", (char*)"mm7", (char*)"xmm0", (char*)"xmm1", (char*)"xmm2", (char*)"xmm3", (char*)"xmm4", (char*)"xmm5", (char*)"xmm6", (char*)"xmm7", (char*)"xmm8", (char*)"xmm9", (char*)"xmm10", (char*)"xmm11", (char*)"xmm12", (char*)"xmm13", (char*)"xmm14", (char*)"xmm15", (char*)"word", (char*)"dword", (char*)"qword", (char*)"fword", (char*)"mmword", (char*)"oword", (char*)"r8", (char*)"r9", (char*)"r10", (char*)"r11", (char*)"r12", (char*)"r13", (char*)"r14", (char*)"r15", (char*)"r8w", (char*)"r9w", (char*)"r10w", (char*)"r11w", (char*)"r12w", (char*)"r13w", (char*)"r14w", (char*)"r15w", (char*)"rax", (char*)"rbp", (char*)"rbx", (char*)"rcx", (char*)"rdi", (char*)"rdx", (char*)"rsi", (char*)"rsp", (char*)"tbyte", (char*)"xmmword", (char*)"ymmword", (char*)"zmmword", (char*)"ah", (char*)"axl", (char*)"bh", (char*)"bpl", (char*)"bxl", (char*)"ch", (char*)"cxl", (char*)"dh", (char*)"dil", (char*)"dr0", (char*)"dr1", (char*)"dr2", (char*)"dr3", (char*)"dr4", (char*)"dr5", (char*)"dr6", (char*)"dr7", (char*)"dxl", (char*)"eip", (char*)"eq", (char*)"ge", (char*)"gt", (char*)"le", (char*)"lt", (char*)"ne", (char*)"r8b", (char*)"r9b", (char*)"r10b", (char*)"r11b", (char*)"r12b", (char*)"r13b", (char*)"r14b", (char*)"r15b", (char*)"r8d", (char*)"r9d", (char*)"r10d", (char*)"r11d", (char*)"r12d", (char*)"r13d", (char*)"r14d", (char*)"r15d", (char*)"rip", (char*)"sil", (char*)"spl", (char*)"ymm0", (char*)"ymm1", (char*)"ymm2", (char*)"ymm3", (char*)"ymm4", (char*)"ymm5", (char*)"ymm6", (char*)"ymm7", (char*)"ymm8", (char*)"ymm9", (char*)"ymm10", (char*)"ymm11", (char*)"ymm12", (char*)"ymm13", (char*)"ymm14", (char*)"ymm15", (char*)"zmm0", (char*)"zmm1", (char*)"zmm2", (char*)"zmm3", (char*)"zmm4", (char*)"zmm5", (char*)"zmm6", (char*)"zmm7", (char*)"zmm8", (char*)"zmm9", (char*)"zmm10", (char*)"zmm11", (char*)"zmm12", (char*)"zmm13", (char*)"zmm14", (char*)"zmm15", (char*)"zmm16", (char*)"zmm17", (char*)"zmm18", (char*)"zmm19", (char*)"zmm20", (char*)"zmm21", (char*)"zmm22", (char*)"zmm23", (char*)"zmm24", (char*)"zmm25", (char*)"zmm26", (char*)"zmm27", (char*)"zmm28", (char*)"zmm29", (char*)"zmm30", (char*)"zmm31" };
static struct $15ASMKEYWORDSINFO INLINEASMKEYWORDS$;
static struct $15ASMKEYWORDSINFO GLOBALASMKEYWORDS$;

int64 PARSERINLINEASMADDKEYWORD( char* ID$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$44:;
	static char TEXT$1[1025];
	FBSTRING* vr$1 = fb_StrAllocTempDescZ( ID$1 );
	FBSTRING* vr$2 = fb_StrLcase2( (FBSTRING*)vr$1, 0 );
	fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$2, -1ll, 0 );
	HINITINLINEASMKEYWORDS(  );
	int64 vr$3 = HISINLINEASMKEYWORD( (char*)TEXT$1 );
	if( vr$3 == 0ll) goto label$47;
	{
		fb$result$1 = 0ll;
		goto label$45;
	}
	label$47:;
	label$46:;
	HADDASMKEYWORD( &INLINEASMKEYWORDS$, (char*)TEXT$1 );
	fb$result$1 = -1ll;
	goto label$45;
	label$45:;
	return fb$result$1;
}

int64 PARSERGLOBALASMADDKEYWORD( char* ID$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$48:;
	static char TEXT$1[1025];
	FBSTRING* vr$1 = fb_StrAllocTempDescZ( ID$1 );
	FBSTRING* vr$2 = fb_StrLcase2( (FBSTRING*)vr$1, 0 );
	fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$2, -1ll, 0 );
	int64 vr$3 = PARSERISGLOBALASMKEYWORD( (char*)TEXT$1 );
	if( vr$3 == 0ll) goto label$51;
	{
		fb$result$1 = 0ll;
		goto label$49;
	}
	label$51:;
	label$50:;
	HADDASMKEYWORD( &GLOBALASMKEYWORDS$, (char*)TEXT$1 );
	fb$result$1 = -1ll;
	goto label$49;
	label$49:;
	return fb$result$1;
}

int64 PARSERISGLOBALASMKEYWORD( char* ID$1 )
{
	FBSTRING TMP$830$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$52:;
	__builtin_memset( &TMP$830$1, 0, 24ll );
	FBSTRING* vr$2 = fb_StrAllocTempDescZ( ID$1 );
	FBSTRING* vr$3 = fb_StrLcase2( (FBSTRING*)vr$2, 0 );
	fb_StrAssign( (void*)&TMP$830$1, -1ll, (void*)vr$3, -1ll, 0 );
	void* vr$6 = HASHLOOKUP( (struct $5THASH*)((uint8*)&GLOBALASMKEYWORDS$ + 8ll), (char*)*(char**)&TMP$830$1 );
	fb$result$1 = (int64)-(vr$6 != (void*)0ull);
	fb_StrDelete( (FBSTRING*)&TMP$830$1 );
	label$53:;
	return fb$result$1;
}

void PARSERASMINIT( void )
{
	label$54:;
	HINITGLOBALASMKEYWORDS(  );
	label$55:;
}

void PARSERASMEND( void )
{
	label$56:;
	HASMKEYWORDSEND( &GLOBALASMKEYWORDS$ );
	HASMKEYWORDSEND( &INLINEASMKEYWORDS$ );
	label$57:;
}

void CASMCODE( void )
{
	label$58:;
	static char TEXT$1[1025];
	struct $10FBSYMCHAIN* CHAIN_$1;
	struct $8FBSYMBOL* SYM$1;
	struct $7ASTNODE* EXPR$1;
	struct $9ASTASMTOK* HEAD$1;
	struct $9ASTASMTOK* TAIL$1;
	int64 DOSKIP$1;
	int64 THISTOK$1;
	HEAD$1 = (struct $9ASTASMTOK*)0ull;
	TAIL$1 = (struct $9ASTASMTOK*)0ull;
	label$60:;
	{
		int64 vr$0 = LEXGETTOKEN( 1028ll );
		THISTOK$1 = vr$0;
		{
			uint64 TMP$831$3;
			TMP$831$3 = (uint64)THISTOK$1;
			goto label$64;
			label$65:;
			{
				goto label$61;
			}
			goto label$63;
			label$64:;
			static const void* tmp$840[85ll] = {
				&&label$65,
				&&label$65,
				&&label$63,
				&&label$65,
				&&label$65,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$63,
				&&label$65,
			};
			if( (TMP$831$3 - 256ull) > 84ull ) goto label$63;
			goto *tmp$840[TMP$831$3 - 256ull];
			label$63:;
		}
		char* vr$1 = LEXGETTEXT(  );
		fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$1, 0ll, 0 );
		SYM$1 = (struct $8FBSYMBOL*)0ull;
		DOSKIP$1 = 0ll;
		{
			uint64 TMP$832$3;
			int64 vr$2 = LEXGETCLASS( 1028ll );
			TMP$832$3 = (uint64)vr$2;
			goto label$67;
			label$68:;
			{
				FBSTRING TMP$833$4;
				int64 TMP$834$4;
				if( THISTOK$1 != 466ll) goto label$70;
				{
					struct $7ASTNODE* vr$3 = CMATHFUNCT( THISTOK$1, -1ll );
					EXPR$1 = vr$3;
					if( EXPR$1 == (struct $7ASTNODE*)0ull) goto label$72;
					{
						if( *(int64*)EXPR$1 != 16ll) goto label$74;
						{
							FBSTRING* vr$5 = ASTCONSTFLUSHTOSTR( EXPR$1 );
							fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$5, -1ll, 0 );
						}
						goto label$73;
						label$74:;
						{
							ERRREPORT( 11ll, 0ll, (char*)0ull );
							DOSKIP$1 = -1ll;
						}
						label$73:;
					}
					goto label$71;
					label$72:;
					{
						ERRREPORT( 17ll, 0ll, (char*)0ull );
						DOSKIP$1 = -1ll;
					}
					label$71:;
				}
				goto label$69;
				label$70:;
				__builtin_memset( &TMP$833$4, 0, 24ll );
				FBSTRING* vr$7 = fb_StrAllocTempDescZ( (char*)TEXT$1 );
				FBSTRING* vr$8 = fb_StrLcase2( (FBSTRING*)vr$7, 0 );
				fb_StrAssign( (void*)&TMP$833$4, -1ll, (void*)vr$8, -1ll, 0 );
				int64 vr$10 = HISINLINEASMKEYWORD( (char*)*(char**)&TMP$833$4 );
				TMP$834$4 = (int64)-(vr$10 == 0ll);
				fb_StrDelete( (FBSTRING*)&TMP$833$4 );
				if( TMP$834$4 == 0ll) goto label$75;
				{
					struct $8FBSYMBOL* BASE_PARENT$5;
					struct $10FBSYMCHAIN* vr$14 = CIDENTIFIER( &BASE_PARENT$5, 34ll );
					CHAIN_$1 = vr$14;
					label$76:;
					if( CHAIN_$1 == (struct $10FBSYMCHAIN*)0ull) goto label$77;
					{
						struct $8FBSYMBOL* S$6;
						S$6 = *(struct $8FBSYMBOL**)CHAIN_$1;
						label$78:;
						{
							{
								$12FB_SYMBCLASS TMP$835$8;
								TMP$835$8 = *($12FB_SYMBCLASS*)S$6;
								if( TMP$835$8 == 3ll) goto label$83;
								label$84:;
								if( TMP$835$8 != 7ll) goto label$82;
								label$83:;
								{
									SYM$1 = S$6;
									goto label$77;
								}
								goto label$81;
								label$82:;
								if( TMP$835$8 != 2ll) goto label$85;
								label$86:;
								{
									FBSTRING* vr$17 = SYMBGETCONSTVALUEASSTR( S$6 );
									fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$17, -1ll, 0 );
									goto label$77;
								}
								goto label$81;
								label$85:;
								if( TMP$835$8 != 1ll) goto label$87;
								label$88:;
								{
									struct $8FBSYMBOL* vr$18 = SYMBFINDBYCLASS( CHAIN_$1, 1ll );
									SYM$1 = vr$18;
									if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$90;
									{
										*($12FB_SYMBSTATS*)((uint8*)SYM$1 + 24ll) = *(int64*)((uint8*)SYM$1 + 24ll) | 2ll;
									}
									label$90:;
									label$89:;
									goto label$77;
								}
								label$87:;
								label$81:;
							}
							S$6 = *(struct $8FBSYMBOL**)((uint8*)S$6 + 280ll);
						}
						label$80:;
						if( S$6 != (struct $8FBSYMBOL*)0ull) goto label$78;
						label$79:;
						CHAIN_$1 = *(struct $10FBSYMCHAIN**)((uint8*)CHAIN_$1 + 8ll);
					}
					goto label$76;
					label$77:;
				}
				label$75:;
				label$69:;
			}
			goto label$66;
			label$91:;
			{
				struct $7ASTNODE* vr$24 = CNUMLITERAL( 0ll );
				EXPR$1 = vr$24;
				if( EXPR$1 == (struct $7ASTNODE*)0ull) goto label$93;
				{
					FBSTRING* vr$25 = ASTCONSTFLUSHTOSTR( EXPR$1 );
					fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$25, -1ll, 0 );
				}
				label$93:;
				label$92:;
			}
			goto label$66;
			label$94:;
			{
				struct $7ASTNODE* vr$26 = CSTRLITERAL( 0ll );
				EXPR$1 = vr$26;
				if( EXPR$1 == (struct $7ASTNODE*)0ull) goto label$96;
				{
					struct $8FBSYMBOL* LITSYM$5;
					struct $8FBSYMBOL* vr$27 = ASTGETSTRLITSYMBOL( EXPR$1 );
					LITSYM$5 = vr$27;
					if( LITSYM$5 == (struct $8FBSYMBOL*)0ull) goto label$98;
					{
						FBSTRING TMP$839$6;
						fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)"\x22", 2ll, 0 );
						if( (*(int64*)((uint8*)LITSYM$5 + 56ll) & 511ll) == 7ll) goto label$100;
						{
							FBSTRING TMP$837$7;
							__builtin_memset( &TMP$837$7, 0, 24ll );
							FBSTRING* vr$33 = fb_StrConcat( &TMP$837$7, (void*)TEXT$1, 1025ll, *(void**)((uint8*)LITSYM$5 + 96ll), 0ll );
							fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$33, -1ll, 0 );
						}
						goto label$99;
						label$100:;
						{
							uint32* TMP$838$7;
							uint32* vr$35 = fb_WstrConcatAW( (void*)TEXT$1, 1025ll, (uint32*)*(uint32**)((uint8*)LITSYM$5 + 96ll) );
							TMP$838$7 = vr$35;
							fb_WstrAssignToA( (void*)TEXT$1, 1025ll, (uint32*)TMP$838$7, 0 );
							fb_WstrDelete( (uint32*)TMP$838$7 );
						}
						label$99:;
						__builtin_memset( &TMP$839$6, 0, 24ll );
						FBSTRING* vr$38 = fb_StrConcat( &TMP$839$6, (void*)TEXT$1, 1025ll, (void*)"\x22", 2ll );
						fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$38, -1ll, 0 );
					}
					label$98:;
					label$97:;
					ASTDELTREE( EXPR$1 );
				}
				label$96:;
				label$95:;
			}
			goto label$66;
			label$101:;
			{
				{
					if( THISTOK$1 != 346ll) goto label$103;
					label$104:;
					{
						struct $8FBSYMBOL* vr$39 = SYMBGETPROCRESULT( *(struct $8FBSYMBOL**)((uint8*)&PARSER$ + 216ll) );
						SYM$1 = vr$39;
						if( SYM$1 != (struct $8FBSYMBOL*)0ull) goto label$106;
						{
							ERRREPORT( 17ll, 0ll, (char*)0ull );
							DOSKIP$1 = -1ll;
						}
						goto label$105;
						label$106:;
						{
							*($12FB_SYMBSTATS*)((uint8*)SYM$1 + 24ll) = *(int64*)((uint8*)SYM$1 + 24ll) | 2ll;
						}
						label$105:;
					}
					goto label$102;
					label$103:;
					if( THISTOK$1 != 406ll) goto label$107;
					label$108:;
					{
						struct $7ASTNODE* vr$43 = CTYPECONVEXPR( THISTOK$1, -1ll );
						EXPR$1 = vr$43;
						if( EXPR$1 == (struct $7ASTNODE*)0ull) goto label$110;
						{
							if( *(int64*)EXPR$1 != 16ll) goto label$112;
							{
								FBSTRING* vr$45 = ASTCONSTFLUSHTOSTR( EXPR$1 );
								fb_StrAssign( (void*)TEXT$1, 1025ll, (void*)vr$45, -1ll, 0 );
							}
							goto label$111;
							label$112:;
							{
								ERRREPORT( 11ll, 0ll, (char*)0ull );
								DOSKIP$1 = -1ll;
							}
							label$111:;
						}
						goto label$109;
						label$110:;
						{
							ERRREPORT( 17ll, 0ll, (char*)0ull );
							DOSKIP$1 = -1ll;
						}
						label$109:;
					}
					label$107:;
					label$102:;
				}
			}
			goto label$66;
			label$67:;
			static const void* tmp$841[5ll] = {
				&&label$68,
				&&label$101,
				&&label$68,
				&&label$91,
				&&label$94,
			};
			if( TMP$832$3 > 4ull ) goto label$66;
			goto *tmp$841[TMP$832$3 - 0ull];
			label$66:;
		}
		if( DOSKIP$1 != 0ll) goto label$114;
		{
			if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$116;
			{
				struct $9ASTASMTOK* vr$46 = ASTASMAPPENDSYMB( TAIL$1, SYM$1 );
				TAIL$1 = vr$46;
			}
			goto label$115;
			label$116:;
			{
				struct $9ASTASMTOK* vr$47 = ASTASMAPPENDTEXT( TAIL$1, (char*)TEXT$1 );
				TAIL$1 = vr$47;
			}
			label$115:;
			if( HEAD$1 != (struct $9ASTASMTOK*)0ull) goto label$118;
			{
				HEAD$1 = TAIL$1;
			}
			label$118:;
			label$117:;
		}
		label$114:;
		label$113:;
		LEXSKIPTOKEN( 1028ll );
	}
	label$62:;
	goto label$60;
	label$61:;
	if( HEAD$1 == (struct $9ASTASMTOK*)0ull) goto label$120;
	{
		struct $7ASTNODE* vr$48 = ASTNEWASM( HEAD$1 );
		ASTADD( vr$48 );
	}
	label$120:;
	label$119:;
	label$59:;
}

int64 CASMBLOCK( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$121:;
	int64 ISSINGLELINE$1;
	fb$result$1 = 0ll;
	int64 vr$1 = LEXGETTOKEN( 0ll );
	if( vr$1 == 344ll) goto label$124;
	{
		goto label$122;
	}
	label$124:;
	label$123:;
	int64 vr$2 = CCOMPSTMTISALLOWED( 1ll );
	if( vr$2 != 0ll) goto label$126;
	{
		HSKIPCOMPOUND( 344ll, -1ll, 0ll );
		goto label$122;
	}
	label$126:;
	label$125:;
	LEXSKIPTOKEN( 2048ll );
	ISSINGLELINE$1 = 0ll;
	int64 vr$3 = CCOMMENT( 0ll );
	if( vr$3 == 0ll) goto label$128;
	{
		if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$130;
		{
			if( *(int64*)((uint8*)&ENV$ + 1296ll) != 0ll) goto label$132;
			{
				struct $7ASTNODE* vr$5 = ASTNEWLIT( *(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll) );
				ASTADD( vr$5 );
				DZSTRRESET( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll) );
			}
			label$132:;
			label$131:;
		}
		label$130:;
		label$129:;
		int64 vr$8 = CSTMTSEPARATOR( 0ll );
		if( vr$8 != 0ll) goto label$134;
		{
			ERRREPORT( 3ll, 0ll, (char*)0ull );
			HSKIPUNTIL( 257ll, -1ll, 0ll, 0ll );
		}
		label$134:;
		label$133:;
	}
	goto label$127;
	label$128:;
	{
		int64 vr$9 = CSTMTSEPARATOR( 0ll );
		if( vr$9 != 0ll) goto label$136;
		{
			ISSINGLELINE$1 = -1ll;
		}
		label$136:;
		label$135:;
	}
	label$127:;
	label$137:;
	{
		if( ISSINGLELINE$1 != 0ll) goto label$141;
		{
			struct $7ASTNODE* vr$11 = ASTNEWDBG( 114ll, *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll), *(char**)((uint8*)&ENV$ + 896ll) );
			ASTADD( vr$11 );
		}
		label$141:;
		label$140:;
		CASMCODE(  );
		CCOMMENT( 1028ll );
		if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$143;
		{
			if( *(int64*)((uint8*)&ENV$ + 1296ll) != 0ll) goto label$145;
			{
				struct $7ASTNODE* vr$13 = ASTNEWLIT( *(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll) );
				ASTADD( vr$13 );
				DZSTRRESET( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 49656ll) );
			}
			label$145:;
			label$144:;
		}
		label$143:;
		label$142:;
		{
			int64 TMP$842$3;
			int64 vr$16 = LEXGETTOKEN( 0ll );
			TMP$842$3 = vr$16;
			if( TMP$842$3 != 257ll) goto label$147;
			label$148:;
			{
				if( ISSINGLELINE$1 == 0ll) goto label$150;
				{
					goto label$138;
				}
				label$150:;
				label$149:;
				LEXSKIPTOKEN( 0ll );
			}
			goto label$146;
			label$147:;
			if( TMP$842$3 != 256ll) goto label$151;
			label$152:;
			{
				goto label$138;
			}
			goto label$146;
			label$151:;
			if( TMP$842$3 != 340ll) goto label$153;
			label$154:;
			{
				goto label$138;
			}
			goto label$146;
			label$153:;
			{
				ERRREPORT( 3ll, 0ll, (char*)0ull );
				HSKIPUNTIL( 257ll, -1ll, 0ll, 0ll );
			}
			label$155:;
			label$146:;
		}
		if( ISSINGLELINE$1 != 0ll) goto label$157;
		{
			struct $7ASTNODE* vr$17 = ASTNEWDBG( 115ll, 0ll, (char*)0ull );
			ASTADD( vr$17 );
		}
		label$157:;
		label$156:;
	}
	label$139:;
	goto label$137;
	label$138:;
	if( ISSINGLELINE$1 != 0ll) goto label$159;
	{
		int64 vr$18 = HMATCH( 340ll, 2048ll );
		if( vr$18 != 0ll) goto label$161;
		{
			ERRREPORT( 45ll, 0ll, (char*)0ull );
		}
		goto label$160;
		label$161:;
		{
			int64 vr$19 = HMATCH( 344ll, 2048ll );
			if( vr$19 != 0ll) goto label$163;
			{
				ERRREPORT( 45ll, 0ll, (char*)0ull );
			}
			label$163:;
			label$162:;
		}
		label$160:;
	}
	label$159:;
	label$158:;
	fb$result$1 = -1ll;
	label$122:;
	return fb$result$1;
}

__attribute__(( constructor )) static void fb_ctor__parserzinlineasm( void )
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

static void HINITINLINEASMKEYWORDS( void )
{
	label$10:;
	if( *(int64*)&INLINEASMKEYWORDS$ != 0ll) goto label$13;
	{
		LISTINIT( (struct $5TLIST*)((uint8*)&INLINEASMKEYWORDS$ + 32ll), 8ll, 8ll, 4294967295ll );
		HASHINIT( (struct $5THASH*)((uint8*)&INLINEASMKEYWORDS$ + 8ll), 800ll, 0ll );
		{
			int64 I$3;
			I$3 = 0ll;
			label$17:;
			{
				HASHADD( (struct $5THASH*)((uint8*)&INLINEASMKEYWORDS$ + 8ll), *(char**)((int64)(char**)INLINEASMKEYWORDSX86$ + (I$3 << (3ll & 63ll))), (void*)18446744073709551615ull, 18446744073709551615ull );
			}
			label$15:;
			I$3 = I$3 + 1ll;
			label$14:;
			if( I$3 <= 555ll) goto label$17;
			label$16:;
		}
		{
			int64 I$3;
			I$3 = 0ll;
			label$21:;
			{
				HASHADD( (struct $5THASH*)((uint8*)&INLINEASMKEYWORDS$ + 8ll), *(char**)((int64)(char**)GLOBALASMKEYWORDSX86$ + (I$3 << (3ll & 63ll))), (void*)18446744073709551615ull, 18446744073709551615ull );
			}
			label$19:;
			I$3 = I$3 + 1ll;
			label$18:;
			if( I$3 <= 176ll) goto label$21;
			label$20:;
		}
		*(int64*)&INLINEASMKEYWORDS$ = -1ll;
	}
	label$13:;
	label$12:;
	label$11:;
}

static void HINITGLOBALASMKEYWORDS( void )
{
	label$22:;
	if( *(int64*)&GLOBALASMKEYWORDS$ != 0ll) goto label$25;
	{
		LISTINIT( (struct $5TLIST*)((uint8*)&GLOBALASMKEYWORDS$ + 32ll), 8ll, 8ll, 4294967295ll );
		HASHINIT( (struct $5THASH*)((uint8*)&GLOBALASMKEYWORDS$ + 8ll), 200ll, 0ll );
		{
			int64 TMP$829$3;
			int64 vr$2 = FBGETCPUFAMILY(  );
			TMP$829$3 = vr$2;
			if( TMP$829$3 == 0ll) goto label$28;
			label$29:;
			if( TMP$829$3 != 1ll) goto label$27;
			label$28:;
			{
				{
					int64 I$5;
					I$5 = 0ll;
					label$33:;
					{
						HASHADD( (struct $5THASH*)((uint8*)&GLOBALASMKEYWORDS$ + 8ll), *(char**)((int64)(char**)GLOBALASMKEYWORDSX86$ + (I$5 << (3ll & 63ll))), (void*)18446744073709551615ull, 18446744073709551615ull );
					}
					label$31:;
					I$5 = I$5 + 1ll;
					label$30:;
					if( I$5 <= 176ll) goto label$33;
					label$32:;
				}
			}
			label$27:;
			label$26:;
		}
		*(int64*)&GLOBALASMKEYWORDS$ = -1ll;
	}
	label$25:;
	label$24:;
	label$23:;
}

static void HASMKEYWORDSEND( struct $15ASMKEYWORDSINFO* INFO$1 )
{
	label$34:;
	if( *(int64*)INFO$1 == 0ll) goto label$37;
	{
		HASHEND( (struct $5THASH*)((uint8*)INFO$1 + 8ll) );
		char** S$2;
		void* vr$5 = LISTGETHEAD( (struct $5TLIST*)((uint8*)INFO$1 + 32ll) );
		S$2 = (char**)vr$5;
		label$38:;
		if( S$2 == (char**)0ull) goto label$39;
		{
			free( *(void**)S$2 );
			void* vr$7 = LISTGETNEXT( (void*)S$2 );
			S$2 = (char**)vr$7;
		}
		goto label$38;
		label$39:;
		LISTEND( (struct $5TLIST*)((uint8*)INFO$1 + 32ll) );
		*(int64*)INFO$1 = 0ll;
	}
	label$37:;
	label$36:;
	label$35:;
}

static int64 HISINLINEASMKEYWORD( char* ID$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$40:;
	HINITINLINEASMKEYWORDS(  );
	void* vr$2 = HASHLOOKUP( (struct $5THASH*)((uint8*)&INLINEASMKEYWORDS$ + 8ll), ID$1 );
	fb$result$1 = (int64)-(vr$2 != (void*)0ull);
	label$41:;
	return fb$result$1;
}

static void HADDASMKEYWORD( struct $15ASMKEYWORDSINFO* INFO$1, char* ID$1 )
{
	label$42:;
	char** S$1;
	void* vr$2 = LISTNEWNODE( (struct $5TLIST*)((uint8*)INFO$1 + 32ll) );
	S$1 = (char**)vr$2;
	int64 vr$3 = fb_StrLen( (void*)ID$1, 0ll );
	void* vr$5 = calloc( (uint64)(vr$3 + 1ll), 1ull );
	*S$1 = (char*)vr$5;
	fb_StrAssign( *(void**)S$1, 0ll, (void*)ID$1, 0ll, 0 );
	HASHADD( (struct $5THASH*)((uint8*)INFO$1 + 8ll), (char*)*S$1, (void*)18446744073709551615ull, 18446744073709551615ull );
	label$43:;
}
