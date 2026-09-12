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
struct $7TLISTTB;
struct $7TLISTTB {
	struct $7TLISTTB* NEXT;
	void* NODETB;
	int64 NODES;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
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
typedef FBSTRING* (*tmp$28)( void );
struct $7SYMBDEF {
	char* NAME;
	char* VALUE;
	int64 FLAGS;
	tmp$28 PROC;
};
__FB_STATIC_ASSERT( sizeof( struct $7SYMBDEF ) == 32 );
typedef int64 $15FB_DEFINE_FLAGS;
struct $11FB_DEFPARAM;
struct $11FB_DEFPARAM {
	char* NAME;
	int64 NUM;
	struct $11FB_DEFPARAM* NEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $11FB_DEFPARAM ) == 24 );
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
struct $9SYMBMACRO {
	char* NAME;
	$15FB_DEFINE_FLAGS FLAGS;
	tmp$29 PROCZ;
	tmp$30 PROCW;
	int64 NPARAMS;
	char* PARAMS[5];
};
__FB_STATIC_ASSERT( sizeof( struct $9SYMBMACRO ) == 80 );
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
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
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
typedef int64 $7FB_LANG;
typedef int64 $10FB_BACKEND;
typedef int64 $12FB_ASMSYNTAX;
typedef int64 $9FB_ERRMSG;
struct $21SYMB_DEF_UNIQUEID_ELM;
struct $21SYMB_DEF_UNIQUEID_ELM {
	char* NAME;
	struct $21SYMB_DEF_UNIQUEID_ELM* PREV;
};
__FB_STATIC_ASSERT( sizeof( struct $21SYMB_DEF_UNIQUEID_ELM ) == 16 );
struct $23SYMB_DEF_UNIQUEID_STACK {
	struct $21SYMB_DEF_UNIQUEID_ELM* TOP;
};
__FB_STATIC_ASSERT( sizeof( struct $23SYMB_DEF_UNIQUEID_STACK ) == 8 );
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
#define fb_D2UL( value ) ((uint64)__builtin_nearbyint( value ))
int32 fb_ArrayErase( struct $7FBARRAYIvE* );
void fb_ArrayStrErase( struct $7FBARRAYIvE* );
void* malloc( uint64 );
void* calloc( uint64, uint64 );
void free( void* );
FBSTRING* fb_StrInit( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
uint32* fb_WstrAssign( uint32*, int64, uint32* );
void fb_StrDelete( FBSTRING* );
void fb_WstrDelete( uint32* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
uint32* fb_WstrConcatWA( uint32*, void*, int64 );
uint32* fb_WstrConcatAW( void*, int64, uint32* );
int32 fb_StrCompare( void*, int64, void*, int64 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrAllocTempResult( FBSTRING* );
FBSTRING* fb_StrAllocTempDescZ( char* );
FBSTRING* fb_StrAllocTempDescZEx( char*, int64 );
uint32* fb_WstrAlloc( int64 );
FBSTRING* fb_LongintToStr( int64 );
FBSTRING* fb_ULongintToStr( uint64 );
FBSTRING* fb_WstrToStr( uint32* );
FBSTRING* fb_StrMid( FBSTRING*, int64, int64 );
uint32* fb_WstrMid( uint32*, int64, int64 );
int64 fb_StrLen( void*, int64 );
int64 fb_WstrLen( uint32* );
FBSTRING* fb_TRIM( FBSTRING* );
boolean fb_VALBOOL( FBSTRING* );
int32 fb_VALINT( FBSTRING* );
uint64 fb_VALULNG( FBSTRING* );
FBSTRING* fb_StrUcase2( FBSTRING*, int32 );
FBSTRING* fb_GetEnviron( FBSTRING* );
static void fb_ctor__symbzdefine( void ) __attribute__(( constructor ));
void* XALLOCATE( int32 );
void LISTINIT( struct $5TLIST*, int64, int64, $10LIST_FLAGS );
void LISTEND( struct $5TLIST* );
void* LISTNEWNODE( struct $5TLIST* );
void LISTDELNODE( struct $5TLIST*, void* );
void HASHINIT( struct $5THASH*, int64, int64 );
void HASHEND( struct $5THASH* );
uint64 HASHHASH( char* );
void* HASHLOOKUP( struct $5THASH*, char* );
void* HASHLOOKUPEX( struct $5THASH*, char*, uint64 );
struct $8HASHITEM* HASHADD( struct $5THASH*, char*, void*, uint64 );
void HASHDEL( struct $5THASH*, struct $8HASHITEM*, uint64 );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
void ERRREPORT( int64, int64, char* );
int64 FBGETOPTION( int64 );
int64 FBIS64BIT( void );
int64 FBGETCPUFAMILY( void );
int64 FBISHOSTBIGENDIAN( void );
FBSTRING* FBGETLANGNAME( $7FB_LANG );
FBSTRING* FBGETBACKENDNAME( $10FB_BACKEND );
void ASTDELTREE( struct $7ASTNODE* );
int64 ASTISCONSTANT( struct $7ASTNODE* );
FBSTRING* ASTCONSTFLUSHTOSTR( struct $7ASTNODE* );
uint32* ASTCONSTFLUSHTOWSTR( struct $7ASTNODE* );
struct $7ASTNODE* ASTOPTIMIZETREE( struct $7ASTNODE* );
struct $8FBSYMBOL* SYMBADDDEFINE( char*, char*, int64, int64, tmp$28, $15FB_DEFINE_FLAGS );
struct $8FBSYMBOL* SYMBADDDEFINEMACRO( char*, struct $9FB_DEFTOK*, int64, struct $11FB_DEFPARAM*, $15FB_DEFINE_FLAGS );
struct $11FB_DEFPARAM* SYMBADDDEFINEPARAM( struct $11FB_DEFPARAM*, char* );
struct $9FB_DEFTOK* SYMBDELDEFINETOK( struct $9FB_DEFTOK* );
char* SYMBGETCONSTSTRASSTR( struct $8FBSYMBOL* );
uint32* SYMBGETCONSTSTRASWSTR( struct $8FBSYMBOL* );
typedef int64 $10FB_SYMBOPT;
struct $8FBSYMBOL* SYMBNEWSYMBOL( $10FB_SYMBOPT, struct $8FBSYMBOL*, struct $10FBSYMBOLTB*, struct $8FBHASHTB*, $12FB_SYMBCLASS, char*, char*, int64, struct $8FBSYMBOL*, $13FB_SYMBATTRIB, $13FB_PROCATTRIB );
void SYMBFREESYMBOL( struct $8FBSYMBOL* );
char* SYMBUNIQUEID( boolean );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
void SYMBMANGLERESETABBREV( void );
typedef int64 $12FB_MANGLEOPT;
void SYMBMANGLETYPE( FBSTRING*, int64, struct $8FBSYMBOL*, $12FB_MANGLEOPT );
FBSTRING* SYMBTYPETOSTR( int64, struct $8FBSYMBOL*, int64, int64 );
char* SYMBGETFULLPROCNAME( struct $8FBSYMBOL* );
void HUCASE( char*, char* );
void DZSTRASSIGN( struct $8DZSTRING*, char* );
void DZSTRASSIGNW( struct $8DZSTRING*, uint32* );
void DZSTRCONCATASSIGN( struct $8DZSTRING*, char* );
void DWSTRASSIGN( struct $8DWSTRING*, uint32* );
void DWSTRASSIGNA( struct $8DWSTRING*, char* );
void DWSTRCONCATASSIGN( struct $8DWSTRING*, uint32* );
void DWSTRCONCATASSIGNA( struct $8DWSTRING*, char* );
void ZSTRASSIGN( char**, char* );
void ZSTRASSIGNW( char**, uint32* );
FBSTRING* HREPLACE( char*, char*, char* );
uint32* HREPLACEW( uint32*, uint32*, uint32* );
char* HREPLACECHAR( char*, int64, int64 );
int64 HSTR2LONG( FBSTRING*, int32* );
int64 HWSTR2LONG( uint32*, int32* );
int64 HSTR2TOK( char*, struct $7FBARRAYI8FBSTRINGE* );
int64 HSTR2ARGS( char*, struct $7FBARRAYI8FBSTRINGE* );
int64 HWSTR2ARGS( uint32*, struct $7FBARRAYI8DWSTRINGE* );
FBSTRING* FBGETINPUTFILEPARENTDIR( void );
void LEXINIT( $17LEX_TKCTX_CONTEXT );
void LEXPUSHCTX( void );
void LEXPOPCTX( void );
typedef int64 $8LEXCHECK;
int64 LEXGETTOKEN( $8LEXCHECK );
int64 LEXGETCLASS( $8LEXCHECK );
void LEXSKIPTOKEN( $8LEXCHECK );
void CTYPEOF( int64*, struct $8FBSYMBOL**, int64*, int64*, struct $8FBSYMBOL** );
struct $8FBSYMBOL* CIDENTIFIERORUDTMEMBER( struct $8FBSYMBOL**, struct $10FBSYMCHAIN* );
struct $7ASTNODE* CEXPRESSION( void );
void CUDTTYPEMEMBER( int64*, struct $8FBSYMBOL**, int64*, int64*, struct $8FBSYMBOL** );
void HSKIPUNTIL( int64, int64, $8LEXCHECK, int64 );
double fb_Now( void );
FBSTRING* fb_StrFormat( double, FBSTRING* );
static FBSTRING* HDEFFILE_CB( void );
static FBSTRING* HDEFPATH_CB( void );
static FBSTRING* HDEFFUNCTION_CB( void );
static FBSTRING* HDEFLINE_CB( void );
static double UNIXTIMETODATESERIAL( int64 );
static boolean HCHECKSOURCEDATEEPOCH( FBSTRING* );
static double HGETCOMPILETIME( void );
static FBSTRING* HDEFDATE_CB( void );
static FBSTRING* HDEFDATEISO_CB( void );
static FBSTRING* HDEFTIME_CB( void );
static FBSTRING* HDEFMULTITHREAD_CB( void );
static FBSTRING* HDEFOPTBYVAL_CB( void );
static FBSTRING* HDEFOPTDYNAMIC_CB( void );
static FBSTRING* HDEFOPTESCAPE_CB( void );
static FBSTRING* HDEFOPTEXPLICIT_CB( void );
static FBSTRING* HDEFOPTPRIVATE_CB( void );
static FBSTRING* HDEFOPTPROFILE_CB( void );
static FBSTRING* HDEFOPTGOSUB_CB( void );
static FBSTRING* HDEFGUI_CB( void );
static FBSTRING* HDEFOPTIMIZE_CB( void );
static FBSTRING* HDEFPROFILE_CB( void );
static FBSTRING* HDEFOUTEXE_CB( void );
static FBSTRING* HDEFOUTLIB_CB( void );
static FBSTRING* HDEFOUTDLL_CB( void );
static FBSTRING* HDEFOUTOBJ_CB( void );
static FBSTRING* HDEFDEBUG_CB( void );
static FBSTRING* HDEFERR_CB( void );
static FBSTRING* HDEFLANG_CB( void );
static FBSTRING* HDEFBACKEND_CB( void );
static FBSTRING* HDEFFPU_CB( void );
static FBSTRING* HDEFFPMODE_CB( void );
static FBSTRING* HDEFGCC_CB( void );
static FBSTRING* HDEFASM_CB( void );
static char* HMACRO_GETARGZ( struct $11LEXPP_ARGTB*, int64 );
static uint32* HMACRO_GETARGW( struct $11LEXPP_ARGTB*, int64 );
static void HARGAPPENDLFCHAR( void );
static void HARGINSERTARGA( char* );
static void HARGINSERTARGW( uint32* );
static FBSTRING* HMACRO_EVALZ( char*, int64* );
static uint32* HMACRO_EVALW( uint32*, int64* );
static FBSTRING* HDEFUNIQUEIDPUSH_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFUNIQUEID_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFUNIQUEIDPOP_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFARGCOUNT_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFARGEXTRACT_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFARGLISTEXPANDZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFARGLISTEXPANDW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFARGLEFT_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFARGRIGHT_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFJOINZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFJOINW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFQUOTEZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFQUOTEW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFUNQUOTEZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFUNQUOTEW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFEVALZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFEVALW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFIIFZ_CB( struct $11LEXPP_ARGTB*, int64* );
static uint32* HDEFIIFW_CB( struct $11LEXPP_ARGTB*, int64* );
static FBSTRING* HDEFQUERYSYMZ_CB( struct $11LEXPP_ARGTB*, int64* );
static void HRESETDEFHASH( void );
static void HDELDEFINEPARAMS( struct $8FBSYMBOL* );
static void HDELDEFINETOKENS( struct $8FBSYMBOL* );
typedef int64 $11AST_OPFLAGS;
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
typedef int64 $13FB_COMPTARGET;
typedef int64 $10FB_CPUTYPE;
typedef int64 $10FB_FPUTYPE;
typedef int64 $9FB_FPMODE;
typedef int64 $17FB_VECTORIZELEVEL;
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
typedef int64 $8FB_TOKEN;
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
struct $6PP_CTX {
	struct $8FBSYMBOL KWDNS;
	struct $5TLIST ARGTBLIST;
	int64 LEVEL;
	int64 SKIPPING;
	int64 INVOKING;
};
__FB_STATIC_ASSERT( sizeof( struct $6PP_CTX ) == 408 );
extern struct $6PP_CTX PP$;
static struct $7SYMBDEF DEFTB$[40] = { { (char*)"__FB_VERSION__", (char*)"1.22.3", 1ll, (tmp$28)0ull }, { (char*)"__FB_BUILD_DATE__", (char*)"09-12-2026", 1ll, (tmp$28)0ull }, { (char*)"__FB_BUILD_DATE_ISO__", (char*)"2026-09-12", 1ll, (tmp$28)0ull }, { (char*)"__FB_VER_MAJOR__", (char*)"1", 0ll, (tmp$28)0ull }, { (char*)"__FB_VER_MINOR__", (char*)"22", 0ll, (tmp$28)0ull }, { (char*)"__FB_VER_PATCH__", (char*)"3", 0ll, (tmp$28)0ull }, { (char*)"__FB_SIGNATURE__", (char*)"FreeBASIC 1.22.3", 1ll, (tmp$28)0ull }, { (char*)"__FB_BUILD_SHA1__", (char*)"", 1ll, (tmp$28)0ull }, { (char*)"__FB_BUILD_FORK_ID__", (char*)"", 1ll, (tmp$28)0ull }, { (char*)"__FB_MT__", (char*)0ull, 0ll, (tmp$28)&HDEFMULTITHREAD_CB }, { (char*)"__FILE__", (char*)0ull, 1ll, (tmp$28)&HDEFFILE_CB }, { (char*)"__FILE_NQ__", (char*)0ull, 0ll, (tmp$28)&HDEFFILE_CB }, { (char*)"__FUNCTION__", (char*)0ull, 1ll, (tmp$28)&HDEFFUNCTION_CB }, { (char*)"__FUNCTION_NQ__", (char*)0ull, 0ll, (tmp$28)&HDEFFUNCTION_CB }, { (char*)"__LINE__", (char*)0ull, 0ll, (tmp$28)&HDEFLINE_CB }, { (char*)"__DATE__", (char*)0ull, 1ll, (tmp$28)&HDEFDATE_CB }, { (char*)"__DATE_ISO__", (char*)0ull, 1ll, (tmp$28)&HDEFDATEISO_CB }, { (char*)"__TIME__", (char*)0ull, 1ll, (tmp$28)&HDEFTIME_CB }, { (char*)"__PATH__", (char*)0ull, 1ll, (tmp$28)&HDEFPATH_CB }, { (char*)"__FB_OPTION_BYVAL__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTBYVAL_CB }, { (char*)"__FB_OPTION_DYNAMIC__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTDYNAMIC_CB }, { (char*)"__FB_OPTION_ESCAPE__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTESCAPE_CB }, { (char*)"__FB_OPTION_EXPLICIT__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTEXPLICIT_CB }, { (char*)"__FB_OPTION_PRIVATE__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTPRIVATE_CB }, { (char*)"__FB_OPTION_GOSUB__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTGOSUB_CB }, { (char*)"__FB_OPTION_PROFILE__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTPROFILE_CB }, { (char*)"__FB_OUT_EXE__", (char*)0ull, 0ll, (tmp$28)&HDEFOUTEXE_CB }, { (char*)"__FB_OUT_LIB__", (char*)0ull, 0ll, (tmp$28)&HDEFOUTLIB_CB }, { (char*)"__FB_OUT_DLL__", (char*)0ull, 0ll, (tmp$28)&HDEFOUTDLL_CB }, { (char*)"__FB_OUT_OBJ__", (char*)0ull, 0ll, (tmp$28)&HDEFOUTOBJ_CB }, { (char*)"__FB_DEBUG__", (char*)0ull, 0ll, (tmp$28)&HDEFDEBUG_CB }, { (char*)"__FB_ERR__", (char*)0ull, 0ll, (tmp$28)&HDEFERR_CB }, { (char*)"__FB_LANG__", (char*)0ull, 1ll, (tmp$28)&HDEFLANG_CB }, { (char*)"__FB_BACKEND__", (char*)0ull, 1ll, (tmp$28)&HDEFBACKEND_CB }, { (char*)"__FB_FPU__", (char*)0ull, 1ll, (tmp$28)&HDEFFPU_CB }, { (char*)"__FB_FPMODE__", (char*)0ull, 1ll, (tmp$28)&HDEFFPMODE_CB }, { (char*)"__FB_GCC__", (char*)0ull, 0ll, (tmp$28)&HDEFGCC_CB }, { (char*)"__FB_GUI__", (char*)0ull, 0ll, (tmp$28)&HDEFGUI_CB }, { (char*)"__FB_OPTIMIZE__", (char*)0ull, 0ll, (tmp$28)&HDEFOPTIMIZE_CB }, { (char*)"__FB_PROFILE__", (char*)0ull, 0ll, (tmp$28)&HDEFPROFILE_CB } };
static struct $9SYMBMACRO MACROTB$[14] = { { (char*)"__FB_UNIQUEID_PUSH__", 0ll, (tmp$29)&HDEFUNIQUEIDPUSH_CB, (tmp$30)0ull, 1ll, { (char*)"ID" } }, { (char*)"__FB_UNIQUEID__", 0ll, (tmp$29)&HDEFUNIQUEID_CB, (tmp$30)0ull, 1ll, { (char*)"ID" } }, { (char*)"__FB_UNIQUEID_POP__", 0ll, (tmp$29)&HDEFUNIQUEIDPOP_CB, (tmp$30)0ull, 1ll, { (char*)"ID" } }, { (char*)"__FB_ARG_COUNT__", 4ll, (tmp$29)&HDEFARGCOUNT_CB, (tmp$30)0ull, 1ll, { (char*)"ARGS" } }, { (char*)"__FB_ARG_EXTRACT__", 4ll, (tmp$29)&HDEFARGEXTRACT_CB, (tmp$30)0ull, 2ll, { (char*)"ARGNUM", (char*)"ARGS" } }, { (char*)"__FB_ARG_LEFTOF__", 4ll, (tmp$29)&HDEFARGLEFT_CB, (tmp$30)0ull, 3ll, { (char*)"ARG", (char*)"SEP", (char*)"RET" } }, { (char*)"__FB_ARG_RIGHTOF__", 4ll, (tmp$29)&HDEFARGRIGHT_CB, (tmp$30)0ull, 3ll, { (char*)"ARG", (char*)"SEP", (char*)"RET" } }, { (char*)"__FB_JOIN__", 0ll, (tmp$29)&HDEFJOINZ_CB, (tmp$30)&HDEFJOINW_CB, 2ll, { (char*)"L", (char*)"R" } }, { (char*)"__FB_QUOTE__", 0ll, (tmp$29)&HDEFQUOTEZ_CB, (tmp$30)&HDEFQUOTEW_CB, 1ll, { (char*)"ARG" } }, { (char*)"__FB_UNQUOTE__", 0ll, (tmp$29)&HDEFUNQUOTEZ_CB, (tmp$30)&HDEFUNQUOTEW_CB, 1ll, { (char*)"ARG" } }, { (char*)"__FB_EVAL__", 0ll, (tmp$29)&HDEFEVALZ_CB, (tmp$30)&HDEFEVALW_CB, 1ll, { (char*)"ARG" } }, { (char*)"__FB_IIF__", 0ll, (tmp$29)&HDEFIIFZ_CB, (tmp$30)&HDEFIIFW_CB, 3ll, { (char*)"CMPEXPR", (char*)"TEXPR", (char*)"FEXPR" } }, { (char*)"__FB_QUERY_SYMBOL__", 0ll, (tmp$29)&HDEFQUERYSYMZ_CB, (tmp$30)0ull, 2ll, { (char*)"WHAT", (char*)"SYM" } }, { (char*)"__FB_ARG_LISTEXPAND__", 4ll, (tmp$29)&HDEFARGLISTEXPANDZ_CB, (tmp$30)&HDEFARGLISTEXPANDW_CB, 3ll, { (char*)"MACRONAME", (char*)"MACROARGCOUNT", (char*)"ARGS" } } };

void SYMBDEFINEINIT( int64 ISMAIN$1 )
{
	FBSTRING TMP$268$1;
	FBSTRING TMP$269$1;
	FBSTRING TMP$270$1;
	label$549:;
	FBSTRING VALUE$1;
	__builtin_memset( &VALUE$1, 0, 24ll );
	char* DEF$1;
	LISTINIT( (struct $5TLIST*)((uint8*)&SYMB$ + 197344ll), 500ll, 24ll, 6ll );
	LISTINIT( (struct $5TLIST*)((uint8*)&SYMB$ + 197408ll), 1000ll, 32ll, 6ll );
	HASHINIT( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll), 16ll, -1ll );
	{
		int64 I$2;
		I$2 = 0ll;
		label$554:;
		{
			fb_StrAssign( (void*)&VALUE$1, -1ll, *(void**)(((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))) + 8ll), 0ll, 0 );
			if( *(char**)(((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))) + 8ll) == (char*)0ull) goto label$556;
			{
				if( (*(int64*)(((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))) + 16ll) & 1ll) == 0ll) goto label$558;
				{
					FBSTRING TMP$264$5;
					FBSTRING TMP$265$5;
					__builtin_memset( &TMP$264$5, 0, 24ll );
					FBSTRING* vr$12 = fb_StrConcat( &TMP$264$5, (void*)"\x22", 2ll, (void*)&VALUE$1, -1ll );
					__builtin_memset( &TMP$265$5, 0, 24ll );
					FBSTRING* vr$15 = fb_StrConcat( &TMP$265$5, (void*)vr$12, -1ll, (void*)"\x22", 2ll );
					fb_StrAssign( (void*)&VALUE$1, -1ll, (void*)vr$15, -1ll, 0 );
				}
				label$558:;
				label$557:;
			}
			label$556:;
			label$555:;
			int64 vr$20 = fb_StrLen( (void*)&VALUE$1, -1ll );
			SYMBADDDEFINE( *(char**)((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))), (char*)*(char**)&VALUE$1, vr$20, 0ll, *(tmp$28*)(((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))) + 24ll), *($15FB_DEFINE_FLAGS*)(((int64)(struct $7SYMBDEF*)DEFTB$ + (I$2 << (5ll & 63ll))) + 16ll) );
		}
		label$552:;
		I$2 = I$2 + 1ll;
		label$551:;
		if( I$2 <= 39ll) goto label$554;
		label$553:;
	}
	__builtin_memset( &TMP$270$1, 0, 24ll );
	FBSTRING* vr$24 = fb_StrAllocTempDescZ( (char*)*(char**)((uint8*)&ENV$ + 560ll) );
	FBSTRING* vr$25 = fb_StrUcase2( (FBSTRING*)vr$24, 0 );
	__builtin_memset( &TMP$268$1, 0, 24ll );
	FBSTRING* vr$28 = fb_StrConcat( &TMP$268$1, (void*)"__FB_", 6ll, (void*)vr$25, -1ll );
	__builtin_memset( &TMP$269$1, 0, 24ll );
	FBSTRING* vr$31 = fb_StrConcat( &TMP$269$1, (void*)vr$28, -1ll, (void*)"__", 3ll );
	fb_StrAssign( (void*)&TMP$270$1, -1ll, (void*)vr$31, -1ll, 0 );
	SYMBADDDEFINE( (char*)*(char**)&TMP$270$1, (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	fb_StrDelete( (FBSTRING*)&TMP$270$1 );
	if( *(int64*)((uint8*)&ENV$ + 216ll) != 12ll) goto label$560;
	{
		SYMBADDDEFINE( (char*)"__FB_LINUX__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$560:;
	label$559:;
	if( (*(int64*)((uint8*)&ENV$ + 592ll) & 1ll) == 0ll) goto label$562;
	{
		SYMBADDDEFINE( (char*)"__FB_UNIX__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	goto label$561;
	label$562:;
	{
		SYMBADDDEFINE( (char*)"__FB_PCOS__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$561:;
	int64 vr$35 = FBIS64BIT(  );
	if( vr$35 == 0ll) goto label$564;
	{
		SYMBADDDEFINE( (char*)"__FB_64BIT__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$564:;
	label$563:;
	{
		int64 TMP$275$2;
		int64 vr$36 = FBGETCPUFAMILY(  );
		TMP$275$2 = vr$36;
		if( TMP$275$2 == 2ll) goto label$567;
		label$568:;
		if( TMP$275$2 != 3ll) goto label$566;
		label$567:;
		{
			SYMBADDDEFINE( (char*)"__FB_ARM__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
		}
		goto label$565;
		label$566:;
		if( TMP$275$2 == 0ll) goto label$570;
		label$571:;
		if( TMP$275$2 != 1ll) goto label$569;
		label$570:;
		{
			SYMBADDDEFINE( (char*)"__FB_X86__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
			SYMBADDDEFINE( (char*)"__FB_ASM__", (char*)0ull, 0ll, 0ll, (tmp$28)&HDEFASM_CB, 1ll );
		}
		goto label$565;
		label$569:;
		if( TMP$275$2 == 4ll) goto label$573;
		label$574:;
		if( TMP$275$2 == 5ll) goto label$573;
		label$575:;
		if( TMP$275$2 != 6ll) goto label$572;
		label$573:;
		{
			SYMBADDDEFINE( (char*)"__FB_PPC__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
		}
		label$572:;
		label$565:;
	}
	int64 vr$37 = FBISHOSTBIGENDIAN(  );
	if( vr$37 == 0ll) goto label$577;
	{
		SYMBADDDEFINE( (char*)"__FB_BIGENDIAN__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$577:;
	label$576:;
	if( ISMAIN$1 == 0ll) goto label$579;
	{
		SYMBADDDEFINE( (char*)"__FB_MAIN__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$579:;
	label$578:;
	if( *(int64*)((uint8*)&ENV$ + 232ll) < 1ll) goto label$581;
	{
		SYMBADDDEFINE( (char*)"__FB_SSE__", (char*)0ull, 0ll, 0ll, (tmp$28)0ull, 0ll );
	}
	label$581:;
	label$580:;
	FBSTRING* vr$38 = fb_LongintToStr( *(int64*)((uint8*)&ENV$ + 248ll) );
	fb_StrAssign( (void*)&VALUE$1, -1ll, (void*)vr$38, -1ll, 0 );
	int64 vr$41 = fb_StrLen( (void*)&VALUE$1, -1ll );
	SYMBADDDEFINE( (char*)"__FB_VECTORIZE__", (char*)*(char**)&VALUE$1, vr$41, 0ll, (tmp$28)0ull, 0ll );
	*(int64*)((uint8*)&SYMB$ + 197496ll) = 0ll;
	HASHINIT( (struct $5THASH*)((uint8*)&SYMB$ + 197504ll), 32ll, 0ll );
	{
		int64 I$2;
		I$2 = 0ll;
		label$585:;
		{
			struct $11FB_DEFPARAM* FIRSTPARAM$3;
			struct $11FB_DEFPARAM* vr$44 = SYMBADDDEFINEPARAM( (struct $11FB_DEFPARAM*)0ull, *(char**)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 40ll) );
			FIRSTPARAM$3 = vr$44;
			struct $11FB_DEFPARAM* LASTPARAM$3;
			LASTPARAM$3 = FIRSTPARAM$3;
			{
				int64 J$4;
				J$4 = 1ll;
				int64 TMP$284$4;
				TMP$284$4 = *(int64*)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 32ll) + -1ll;
				goto label$586;
				label$589:;
				{
					struct $11FB_DEFPARAM* vr$51 = SYMBADDDEFINEPARAM( LASTPARAM$3, *(char**)((uint8*)((uint8*)((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + (J$4 << (3ll & 63ll))) + 40ll) );
					LASTPARAM$3 = vr$51;
				}
				label$587:;
				J$4 = J$4 + 1ll;
				label$586:;
				if( J$4 <= TMP$284$4) goto label$589;
				label$588:;
			}
			struct $8FBSYMBOL* SYM$3;
			struct $8FBSYMBOL* vr$57 = SYMBADDDEFINEMACRO( *(char**)((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)), (struct $9FB_DEFTOK*)0ull, *(int64*)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 32ll), FIRSTPARAM$3, *(int64*)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 8ll) | 8ll );
			SYM$3 = vr$57;
			*(tmp$29*)((uint8*)SYM$3 + 136ll) = *(tmp$29*)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 16ll);
			*(tmp$30*)((uint8*)SYM$3 + 144ll) = *(tmp$30*)(((int64)(struct $9SYMBMACRO*)MACROTB$ + (I$2 * 80ll)) + 24ll);
		}
		label$583:;
		I$2 = I$2 + 1ll;
		label$582:;
		if( I$2 <= 13ll) goto label$585;
		label$584:;
	}
	fb_StrDelete( (FBSTRING*)&VALUE$1 );
	label$550:;
}

void SYMBDEFINEEND( void )
{
	label$590:;
	HASHEND( (struct $5THASH*)((uint8*)&SYMB$ + 197504ll) );
	*(int64*)((uint8*)&SYMB$ + 197496ll) = 0ll;
	HASHEND( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll) );
	LISTEND( (struct $5TLIST*)((uint8*)&SYMB$ + 197344ll) );
	LISTEND( (struct $5TLIST*)((uint8*)&SYMB$ + 197408ll) );
	label$591:;
}

struct $8FBSYMBOL* SYMBADDDEFINE( char* SYMBOL$1, char* TEXT$1, int64 LGT$1, int64 ISARGLESS$1, tmp$28 PROC$1, $15FB_DEFINE_FLAGS FLAGS$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$592:;
	struct $8FBSYMBOL* SYM$1;
	fb$result$1 = (struct $8FBSYMBOL*)0ull;
	struct $8FBSYMBOL* vr$2 = SYMBNEWSYMBOL( 32ll, (struct $8FBSYMBOL*)0ull, (struct $10FBSYMBOLTB*)0ull, (struct $8FBHASHTB*)((uint8*)&SYMB$ + 196824ll), 5ll, SYMBOL$1, (char*)0ull, 4ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll );
	SYM$1 = vr$2;
	if( SYM$1 != (struct $8FBSYMBOL*)0ull) goto label$595;
	{
		goto label$593;
	}
	label$595:;
	label$594:;
	void* vr$5 = XALLOCATE( (int32)(LGT$1 + 1ll) );
	*(char**)((uint8*)SYM$1 + 112ll) = (char*)vr$5;
	fb_StrAssign( *(void**)((uint8*)SYM$1 + 112ll), 0ll, (void*)TEXT$1, 0ll, 0 );
	*(int64*)((uint8*)SYM$1 + 80ll) = LGT$1;
	*(int64*)((uint8*)SYM$1 + 96ll) = 0ll;
	*(struct $11FB_DEFPARAM**)((uint8*)SYM$1 + 104ll) = (struct $11FB_DEFPARAM*)0ull;
	*(int64*)((uint8*)SYM$1 + 120ll) = ISARGLESS$1;
	*(tmp$28*)((uint8*)SYM$1 + 136ll) = PROC$1;
	*($15FB_DEFINE_FLAGS*)((uint8*)SYM$1 + 128ll) = FLAGS$1;
	fb$result$1 = SYM$1;
	label$593:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBADDDEFINEW( char* SYMBOL$1, uint32* TEXT$1, int64 LGT$1, int64 ISARGLESS$1, tmp$28 PROC$1, $15FB_DEFINE_FLAGS FLAGS$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$596:;
	struct $8FBSYMBOL* SYM$1;
	fb$result$1 = (struct $8FBSYMBOL*)0ull;
	struct $8FBSYMBOL* vr$2 = SYMBNEWSYMBOL( 32ll, (struct $8FBSYMBOL*)0ull, (struct $10FBSYMBOLTB*)0ull, (struct $8FBHASHTB*)((uint8*)&SYMB$ + 196824ll), 5ll, (char*)SYMBOL$1, (char*)0ull, 7ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll );
	SYM$1 = vr$2;
	if( SYM$1 != (struct $8FBSYMBOL*)0ull) goto label$599;
	{
		goto label$597;
	}
	label$599:;
	label$598:;
	void* vr$6 = XALLOCATE( (int32)((LGT$1 << (2ll & 63ll)) + 4ll) );
	*(uint32**)((uint8*)SYM$1 + 112ll) = (uint32*)vr$6;
	fb_WstrAssign( *(uint32**)((uint8*)SYM$1 + 112ll), 0ll, (uint32*)TEXT$1 );
	*(int64*)((uint8*)SYM$1 + 80ll) = LGT$1;
	*(int64*)((uint8*)SYM$1 + 96ll) = 0ll;
	*(struct $11FB_DEFPARAM**)((uint8*)SYM$1 + 104ll) = (struct $11FB_DEFPARAM*)0ull;
	*(int64*)((uint8*)SYM$1 + 120ll) = ISARGLESS$1;
	*(tmp$28*)((uint8*)SYM$1 + 136ll) = PROC$1;
	*($15FB_DEFINE_FLAGS*)((uint8*)SYM$1 + 128ll) = FLAGS$1;
	fb$result$1 = SYM$1;
	label$597:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBADDDEFINEMACRO( char* SYMBOL$1, struct $9FB_DEFTOK* TOKHEAD$1, int64 PARAMS$1, struct $11FB_DEFPARAM* PARAMHEAD$1, $15FB_DEFINE_FLAGS FLAGS$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$600:;
	struct $8FBSYMBOL* SYM$1;
	fb$result$1 = (struct $8FBSYMBOL*)0ull;
	struct $8FBSYMBOL* vr$2 = SYMBNEWSYMBOL( 32ll, (struct $8FBSYMBOL*)0ull, (struct $10FBSYMBOLTB*)0ull, (struct $8FBHASHTB*)((uint8*)&SYMB$ + 196824ll), 5ll, SYMBOL$1, (char*)0ull, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll );
	SYM$1 = vr$2;
	if( SYM$1 != (struct $8FBSYMBOL*)0ull) goto label$603;
	{
		goto label$601;
	}
	label$603:;
	label$602:;
	*(struct $9FB_DEFTOK**)((uint8*)SYM$1 + 112ll) = TOKHEAD$1;
	*(int64*)((uint8*)SYM$1 + 96ll) = PARAMS$1;
	*(struct $11FB_DEFPARAM**)((uint8*)SYM$1 + 104ll) = PARAMHEAD$1;
	*(int64*)((uint8*)SYM$1 + 120ll) = 0ll;
	*(tmp$29*)((uint8*)SYM$1 + 136ll) = (tmp$29)0ull;
	*(tmp$30*)((uint8*)SYM$1 + 144ll) = (tmp$30)0ull;
	*($15FB_DEFINE_FLAGS*)((uint8*)SYM$1 + 128ll) = FLAGS$1;
	fb$result$1 = SYM$1;
	label$601:;
	return fb$result$1;
}

struct $11FB_DEFPARAM* SYMBADDDEFINEPARAM( struct $11FB_DEFPARAM* LASTPARAM$1, char* ID$1 )
{
	struct $11FB_DEFPARAM* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$610:;
	static struct $11FB_DEFPARAM* PARAM$1;
	static uint64 INDEX$1;
	fb$result$1 = (struct $11FB_DEFPARAM*)0ull;
	void* vr$2 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197344ll) );
	PARAM$1 = (struct $11FB_DEFPARAM*)vr$2;
	if( LASTPARAM$1 == (struct $11FB_DEFPARAM*)0ull) goto label$613;
	{
		*(struct $11FB_DEFPARAM**)((uint8*)LASTPARAM$1 + 16ll) = PARAM$1;
	}
	goto label$612;
	label$613:;
	{
		if( *(int64*)((uint8*)&SYMB$ + 197496ll) <= 0ll) goto label$615;
		{
			HRESETDEFHASH(  );
		}
		label$615:;
		label$614:;
	}
	label$612:;
	int64 vr$4 = fb_StrLen( (void*)ID$1, 0ll );
	void* vr$7 = XALLOCATE( (int32)(vr$4 + 1ll) );
	*(char**)PARAM$1 = (char*)vr$7;
	HUCASE( ID$1, *(char**)PARAM$1 );
	uint64 vr$11 = HASHHASH( (char*)*(char**)PARAM$1 );
	INDEX$1 = vr$11;
	void* vr$14 = HASHLOOKUPEX( (struct $5THASH*)((uint8*)&SYMB$ + 197504ll), (char*)*(char**)PARAM$1, INDEX$1 );
	if( vr$14 == (void*)0ull) goto label$617;
	{
		if( *(char**)PARAM$1 == (char*)0ull) goto label$619;
		{
			free( *(void**)PARAM$1 );
		}
		label$619:;
		label$618:;
		LISTDELNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197344ll), (void*)PARAM$1 );
		fb$result$1 = (struct $11FB_DEFPARAM*)0ull;
		goto label$611;
	}
	label$617:;
	label$616:;
	struct $8HASHITEM* vr$20 = HASHADD( (struct $5THASH*)((uint8*)&SYMB$ + 197504ll), (char*)*(char**)PARAM$1, (void*)PARAM$1, INDEX$1 );
	*(struct $8HASHITEM**)((uint8*)((uint8*)((uint8*)&SYMB$ + 197344ll) + (*(int64*)((uint8*)&SYMB$ + 197496ll) << (4ll & 63ll))) + 184ll) = vr$20;
	*(uint64*)((uint8*)((uint8*)((uint8*)&SYMB$ + 197344ll) + (*(int64*)((uint8*)&SYMB$ + 197496ll) << (4ll & 63ll))) + 192ll) = INDEX$1;
	*(int64*)((uint8*)PARAM$1 + 8ll) = *(int64*)((uint8*)&SYMB$ + 197496ll);
	*(struct $11FB_DEFPARAM**)((uint8*)PARAM$1 + 16ll) = (struct $11FB_DEFPARAM*)0ull;
	*(int64*)((uint8*)&SYMB$ + 197496ll) = *(int64*)((uint8*)&SYMB$ + 197496ll) + 1ll;
	fb$result$1 = PARAM$1;
	label$611:;
	return fb$result$1;
}

struct $9FB_DEFTOK* SYMBADDDEFINETOK( struct $9FB_DEFTOK* LASTTOK$1, $14FB_DEFTOK_TYPE DTYPE$1 )
{
	struct $9FB_DEFTOK* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$620:;
	static struct $9FB_DEFTOK* T$1;
	fb$result$1 = (struct $9FB_DEFTOK*)0ull;
	void* vr$2 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197408ll) );
	T$1 = (struct $9FB_DEFTOK*)vr$2;
	if( LASTTOK$1 == (struct $9FB_DEFTOK*)0ull) goto label$623;
	{
		*(struct $9FB_DEFTOK**)((uint8*)LASTTOK$1 + 24ll) = T$1;
	}
	label$623:;
	label$622:;
	*(struct $9FB_DEFTOK**)((uint8*)T$1 + 16ll) = LASTTOK$1;
	*(struct $9FB_DEFTOK**)((uint8*)T$1 + 24ll) = (struct $9FB_DEFTOK*)0ull;
	*($14FB_DEFTOK_TYPE*)T$1 = DTYPE$1;
	{
		uint64 TMP$286$2;
		TMP$286$2 = (uint64)DTYPE$1;
		goto label$625;
		label$626:;
		{
			*(char**)((uint8*)T$1 + 8ll) = (char*)0ull;
		}
		goto label$624;
		label$627:;
		{
			*(uint32**)((uint8*)T$1 + 8ll) = (uint32*)0ull;
		}
		goto label$624;
		label$625:;
		static const void* tmp$287[2ll] = {
			&&label$626,
			&&label$627,
		};
		if( (TMP$286$2 - 2ull) > 1ull ) goto label$624;
		goto *tmp$287[TMP$286$2 - 2ull];
		label$624:;
	}
	fb$result$1 = T$1;
	label$621:;
	return fb$result$1;
}

struct $9FB_DEFTOK* SYMBDELDEFINETOK( struct $9FB_DEFTOK* TOK$1 )
{
	struct $9FB_DEFTOK* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$628:;
	if( *(struct $9FB_DEFTOK**)((uint8*)TOK$1 + 16ll) == (struct $9FB_DEFTOK*)0ull) goto label$631;
	{
		*(struct $9FB_DEFTOK**)((uint8*)*(struct $9FB_DEFTOK**)((uint8*)TOK$1 + 16ll) + 24ll) = (struct $9FB_DEFTOK*)0ull;
		fb$result$1 = *(struct $9FB_DEFTOK**)((uint8*)TOK$1 + 16ll);
	}
	goto label$630;
	label$631:;
	{
		fb$result$1 = (struct $9FB_DEFTOK*)0ull;
	}
	label$630:;
	{
		$14FB_DEFTOK_TYPE TMP$288$2;
		TMP$288$2 = *($14FB_DEFTOK_TYPE*)TOK$1;
		if( TMP$288$2 != 2ll) goto label$633;
		label$634:;
		{
			if( *(char**)((uint8*)TOK$1 + 8ll) == (char*)0ull) goto label$636;
			{
				free( *(void**)((uint8*)TOK$1 + 8ll) );
			}
			label$636:;
			label$635:;
		}
		goto label$632;
		label$633:;
		if( TMP$288$2 != 3ll) goto label$637;
		label$638:;
		{
			if( *(uint32**)((uint8*)TOK$1 + 8ll) == (uint32*)0ull) goto label$640;
			{
				free( *(void**)((uint8*)TOK$1 + 8ll) );
			}
			label$640:;
			label$639:;
		}
		label$637:;
		label$632:;
	}
	LISTDELNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197408ll), (void*)TOK$1 );
	label$629:;
	return fb$result$1;
}

int64 SYMBDELDEFINE( struct $8FBSYMBOL* S$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$651:;
	fb$result$1 = 0ll;
	if( S$1 != (struct $8FBSYMBOL*)0ull) goto label$654;
	{
		goto label$652;
	}
	label$654:;
	label$653:;
	if( *(int64*)((uint8*)S$1 + 96ll) != 0ll) goto label$656;
	{
		if( (*(int64*)((uint8*)S$1 + 56ll) & 511ll) == 7ll) goto label$658;
		{
			if( *(char**)((uint8*)S$1 + 112ll) == (char*)0ull) goto label$660;
			{
				free( *(void**)((uint8*)S$1 + 112ll) );
			}
			label$660:;
			label$659:;
		}
		goto label$657;
		label$658:;
		{
			if( *(uint32**)((uint8*)S$1 + 112ll) == (uint32*)0ull) goto label$662;
			{
				free( *(void**)((uint8*)S$1 + 112ll) );
			}
			label$662:;
			label$661:;
		}
		label$657:;
	}
	goto label$655;
	label$656:;
	{
		HDELDEFINETOKENS( S$1 );
	}
	label$655:;
	HDELDEFINEPARAMS( S$1 );
	SYMBFREESYMBOL( S$1 );
	fb$result$1 = -1ll;
	label$652:;
	return fb$result$1;
}

__attribute__(( constructor )) static void fb_ctor__symbzdefine( void )
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

static FBSTRING* HDEFFILE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$10:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)((uint8*)&ENV$ + 632ll), 261ll, 0 );
	label$11:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFPATH_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$12:;
	FBSTRING* vr$1 = FBGETINPUTFILEPARENTDIR(  );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$13:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFFUNCTION_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$14:;
	if( (*(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)&PARSER$ + 216ll) + 24ll) & 4096ll) == 0ll) goto label$17;
	{
		fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"__FB_MAINPROC__", 16ll, 0 );
	}
	goto label$16;
	label$17:;
	if( (*(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)&PARSER$ + 216ll) + 24ll) & 8192ll) == 0ll) goto label$18;
	{
		fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"__FB_MODLEVELPROC__", 20ll, 0 );
	}
	goto label$16;
	label$18:;
	{
		char* vr$7 = SYMBGETFULLPROCNAME( *(struct $8FBSYMBOL**)((uint8*)&PARSER$ + 216ll) );
		fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$7, 0ll, 0 );
	}
	label$16:;
	label$15:;
	FBSTRING* vr$10 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$10;
}

static FBSTRING* HDEFLINE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$19:;
	FBSTRING* vr$2 = fb_LongintToStr( *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$20:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static double UNIXTIMETODATESERIAL( int64 DAT$1 )
{
	double fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$21:;
	fb$result$1 = ((double)DAT$1 / 0x1.518p+16) + 0x1.8F84p+14;
	goto label$22;
	label$22:;
	return fb$result$1;
}

static boolean HCHECKSOURCEDATEEPOCH( FBSTRING* S$1 )
{
	boolean fb$result$1;
	__builtin_memset( &fb$result$1, 0, 1ll );
	label$23:;
	FBSTRING TMP$1;
	__builtin_memset( &TMP$1, 0, 24ll );
	double VALUE$1;
	__builtin_memset( &VALUE$1, 0, 8ll );
	FBSTRING* vr$3 = fb_TRIM( (FBSTRING*)S$1 );
	fb_StrAssign( (void*)&TMP$1, -1ll, (void*)vr$3, -1ll, 0 );
	int64 vr$6 = fb_StrLen( (void*)&TMP$1, -1ll );
	if( vr$6 != 0ll) goto label$26;
	{
		fb$result$1 = (boolean)0ll;
		fb_StrDelete( (FBSTRING*)&TMP$1 );
		goto label$24;
	}
	label$26:;
	label$25:;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$97$2;
		int64 vr$9 = fb_StrLen( (void*)&TMP$1, -1ll );
		TMP$97$2 = vr$9 + -1ll;
		goto label$27;
		label$30:;
		{
			if( ((int64)-((int64)*(uint8*)((uint8*)*(char**)S$1 + I$2) < 48ll) | (int64)-((int64)*(uint8*)((uint8*)*(char**)S$1 + I$2) > 57ll)) == 0ll) goto label$32;
			{
				fb$result$1 = (boolean)0ll;
				fb_StrDelete( (FBSTRING*)&TMP$1 );
				goto label$24;
			}
			label$32:;
			label$31:;
		}
		label$28:;
		I$2 = I$2 + 1ll;
		label$27:;
		if( I$2 <= TMP$97$2) goto label$30;
		label$29:;
	}
	uint64 vr$22 = fb_VALULNG( (FBSTRING*)S$1 );
	VALUE$1 = (double)vr$22;
	if( fb_D2UL( VALUE$1 ) <= 253402300799ull) goto label$34;
	{
		fb$result$1 = (boolean)0ll;
		fb_StrDelete( (FBSTRING*)&TMP$1 );
		goto label$24;
	}
	label$34:;
	label$33:;
	fb$result$1 = (boolean)1ll;
	fb_StrDelete( (FBSTRING*)&TMP$1 );
	goto label$24;
	fb_StrDelete( (FBSTRING*)&TMP$1 );
	label$24:;
	return fb$result$1;
}

static double HGETCOMPILETIME( void )
{
	double fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$35:;
	static int64 USAGE$1 = 0ll;
	static double SOURCE_DATE_EPOCH$1 = 0x0p+0;
	if( USAGE$1 != 0ll) goto label$38;
	{
		FBSTRING RET$2;
		__builtin_memset( &RET$2, 0, 24ll );
		USAGE$1 = 1ll;
		FBSTRING* vr$2 = fb_StrAllocTempDescZEx( (char*)"SOURCE_DATE_EPOCH", 17ll );
		FBSTRING* vr$3 = fb_GetEnviron( (FBSTRING*)vr$2 );
		fb_StrAssign( (void*)&RET$2, -1ll, (void*)vr$3, -1ll, 0 );
		int64 vr$6 = fb_StrLen( (void*)&RET$2, -1ll );
		if( vr$6 <= 0ll) goto label$40;
		{
			boolean vr$8 = HCHECKSOURCEDATEEPOCH( &RET$2 );
			if( vr$8 == (boolean)0ll) goto label$42;
			{
				uint64 vr$10 = fb_VALULNG( (FBSTRING*)&RET$2 );
				double vr$11 = UNIXTIMETODATESERIAL( (int64)vr$10 );
				SOURCE_DATE_EPOCH$1 = vr$11;
				USAGE$1 = 2ll;
			}
			goto label$41;
			label$42:;
			{
				ERRREPORTEX( 328ll, (char*)0ull, 0ll, 1ll, (char*)0ull );
			}
			label$41:;
		}
		label$40:;
		label$39:;
		fb_StrDelete( (FBSTRING*)&RET$2 );
	}
	label$38:;
	label$37:;
	if( USAGE$1 != 2ll) goto label$44;
	{
		fb$result$1 = SOURCE_DATE_EPOCH$1;
	}
	goto label$43;
	label$44:;
	{
		double vr$13 = fb_Now(  );
		fb$result$1 = vr$13;
	}
	label$43:;
	label$36:;
	return fb$result$1;
}

static FBSTRING* HDEFDATE_CB( void )
{
	FBSTRING TMP$100$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$45:;
	__builtin_memset( &TMP$100$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$100$1, -1ll, (void*)"mm-dd-yyyy", 11ll, 0 );
	double vr$4 = HGETCOMPILETIME(  );
	FBSTRING* vr$5 = fb_StrFormat( vr$4, (FBSTRING*)&TMP$100$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$5, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&TMP$100$1 );
	label$46:;
	FBSTRING* vr$9 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$9;
}

static FBSTRING* HDEFDATEISO_CB( void )
{
	FBSTRING TMP$102$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$47:;
	__builtin_memset( &TMP$102$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$102$1, -1ll, (void*)"yyyy-mm-dd", 11ll, 0 );
	double vr$4 = HGETCOMPILETIME(  );
	FBSTRING* vr$5 = fb_StrFormat( vr$4, (FBSTRING*)&TMP$102$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$5, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&TMP$102$1 );
	label$48:;
	FBSTRING* vr$9 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$9;
}

static FBSTRING* HDEFTIME_CB( void )
{
	FBSTRING TMP$104$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$49:;
	__builtin_memset( &TMP$104$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$104$1, -1ll, (void*)"hh:nn:ss", 9ll, 0 );
	double vr$4 = HGETCOMPILETIME(  );
	FBSTRING* vr$5 = fb_StrFormat( vr$4, (FBSTRING*)&TMP$104$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$5, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&TMP$104$1 );
	label$50:;
	FBSTRING* vr$9 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$9;
}

static FBSTRING* HDEFMULTITHREAD_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$51:;
	FBSTRING* vr$1 = fb_LongintToStr( *(int64*)((uint8*)&ENV$ + 472ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$52:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFOPTBYVAL_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$53:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1528ll) == 1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$54:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTDYNAMIC_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$55:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1568ll) == -1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$56:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTESCAPE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$57:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1560ll) == -1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$58:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTEXPLICIT_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$59:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1536ll) == -1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$60:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTPRIVATE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$61:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1544ll) == 0ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$62:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTPROFILE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$63:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1552ll) == -1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$64:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTGOSUB_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$65:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 1576ll) == -1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$66:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFGUI_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$67:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 520ll) == 1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$68:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOPTIMIZE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$69:;
	int64 vr$1 = FBGETOPTION( 8ll );
	FBSTRING* vr$2 = fb_LongintToStr( vr$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$70:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFPROFILE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$71:;
	int64 vr$1 = FBGETOPTION( 24ll );
	FBSTRING* vr$2 = fb_LongintToStr( vr$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$72:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOUTEXE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$73:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 192ll) == 0ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$74:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOUTLIB_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$75:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 192ll) == 1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$76:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOUTDLL_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$77:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 192ll) == 2ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$78:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFOUTOBJ_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$79:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 192ll) == 3ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$80:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFDEBUG_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$81:;
	FBSTRING* vr$1 = fb_LongintToStr( *(int64*)((uint8*)&ENV$ + 288ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$82:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFERR_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$83:;
	int64 RES$1;
	RES$1 = 0ll;
	if( *(int64*)((uint8*)&ENV$ + 312ll) == 0ll) goto label$86;
	{
		RES$1 = 1ll;
	}
	label$86:;
	label$85:;
	if( *(int64*)((uint8*)&ENV$ + 320ll) == 0ll) goto label$88;
	{
		RES$1 = RES$1 | 2ll;
	}
	label$88:;
	label$87:;
	if( *(int64*)((uint8*)&ENV$ + 328ll) == 0ll) goto label$90;
	{
		RES$1 = RES$1 | 4ll;
	}
	label$90:;
	label$89:;
	if( *(int64*)((uint8*)&ENV$ + 344ll) == 0ll) goto label$92;
	{
		RES$1 = RES$1 | 8ll;
	}
	label$92:;
	label$91:;
	if( *(int64*)((uint8*)&ENV$ + 360ll) == 0ll) goto label$94;
	{
		RES$1 = RES$1 | 16ll;
	}
	label$94:;
	label$93:;
	if( *(int64*)((uint8*)&ENV$ + 304ll) == 0ll) goto label$96;
	{
		RES$1 = RES$1 | 32ll;
	}
	label$96:;
	label$95:;
	if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$98;
	{
		RES$1 = RES$1 | 64ll;
	}
	label$98:;
	label$97:;
	if( *(int64*)((uint8*)&ENV$ + 288ll) == 0ll) goto label$100;
	{
		RES$1 = RES$1 | 128ll;
	}
	label$100:;
	label$99:;
	if( *(int64*)((uint8*)&ENV$ + 336ll) == 0ll) goto label$102;
	{
		RES$1 = RES$1 | 256ll;
	}
	label$102:;
	label$101:;
	if( *(int64*)((uint8*)&ENV$ + 368ll) == 0ll) goto label$104;
	{
		RES$1 = RES$1 | 512ll;
	}
	label$104:;
	label$103:;
	if( *(int64*)((uint8*)&ENV$ + 352ll) == 0ll) goto label$106;
	{
		RES$1 = RES$1 | 1024ll;
	}
	label$106:;
	label$105:;
	FBSTRING* vr$11 = fb_LongintToStr( RES$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$11, -1ll, 0 );
	label$84:;
	FBSTRING* vr$14 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$14;
}

static FBSTRING* HDEFLANG_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$107:;
	FBSTRING* vr$1 = FBGETLANGNAME( *($7FB_LANG*)((uint8*)&ENV$ + 272ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$108:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFBACKEND_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$109:;
	FBSTRING* vr$1 = FBGETBACKENDNAME( *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$110:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HDEFFPU_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$111:;
	{
		int64 TMP$105$2;
		int64 vr$1 = FBGETOPTION( 5ll );
		TMP$105$2 = vr$1;
		if( TMP$105$2 != 0ll) goto label$114;
		label$115:;
		{
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"x87", 4ll, 0 );
			goto label$112;
		}
		goto label$113;
		label$114:;
		if( TMP$105$2 != 1ll) goto label$116;
		label$117:;
		{
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"sse", 4ll, 0 );
			goto label$112;
		}
		goto label$113;
		label$116:;
		if( TMP$105$2 != 2ll) goto label$118;
		label$119:;
		{
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"neon", 5ll, 0 );
			goto label$112;
		}
		goto label$113;
		label$118:;
		{
		}
		label$120:;
		label$113:;
	}
	label$112:;
	FBSTRING* vr$6 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$6;
}

static FBSTRING* HDEFFPMODE_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$121:;
	{
		int64 TMP$109$2;
		int64 vr$1 = FBGETOPTION( 6ll );
		TMP$109$2 = vr$1;
		if( TMP$109$2 != 0ll) goto label$124;
		label$125:;
		{
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"precise", 8ll, 0 );
			goto label$122;
		}
		goto label$123;
		label$124:;
		if( TMP$109$2 != 1ll) goto label$126;
		label$127:;
		{
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"fast", 5ll, 0 );
			goto label$122;
		}
		goto label$123;
		label$126:;
		{
		}
		label$128:;
		label$123:;
	}
	label$122:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFGCC_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$129:;
	FBSTRING* vr$2 = fb_LongintToStr( (int64)-(*(int64*)((uint8*)&ENV$ + 208ll) == 1ll) );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$130:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static FBSTRING* HDEFASM_CB( void )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$131:;
	{
		$12FB_ASMSYNTAX TMP$112$2;
		TMP$112$2 = *($12FB_ASMSYNTAX*)((uint8*)&ENV$ + 264ll);
		if( TMP$112$2 != 0ll) goto label$134;
		label$135:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"intel", 6ll, 0 );
		}
		goto label$133;
		label$134:;
		if( TMP$112$2 != 1ll) goto label$136;
		label$137:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"att", 4ll, 0 );
		}
		label$136:;
		label$133:;
	}
	label$132:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static char* HMACRO_GETARGZ( struct $11LEXPP_ARGTB* ARGTB$1, int64 NUM$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$138:;
	char* RES$1;
	RES$1 = (char*)0ull;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$141;
	{
		char* DT$2;
		DT$2 = *(char**)((uint8*)ARGTB$1 + (NUM$1 * 24ll));
		if( DT$2 != (char*)0ull) goto label$143;
		{
			fb$result$1 = (char*)0ull;
			goto label$139;
		}
		label$143:;
		label$142:;
		ZSTRASSIGN( &RES$1, DT$2 );
	}
	goto label$140;
	label$141:;
	{
		uint32* DT$2;
		DT$2 = *(uint32**)((uint8*)ARGTB$1 + (NUM$1 * 24ll));
		if( DT$2 != (uint32*)0ull) goto label$145;
		{
			fb$result$1 = (char*)0ull;
			goto label$139;
		}
		label$145:;
		label$144:;
		ZSTRASSIGNW( &RES$1, DT$2 );
	}
	label$140:;
	fb$result$1 = RES$1;
	label$139:;
	return fb$result$1;
}

static uint32* HMACRO_GETARGW( struct $11LEXPP_ARGTB* ARGTB$1, int64 NUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$146:;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)0ull );
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$149;
	{
		char* DT$2;
		DT$2 = *(char**)((uint8*)ARGTB$1 + (NUM$1 * 24ll));
		if( DT$2 != (char*)0ull) goto label$151;
		{
			fb$result$1 = (uint32*)0ull;
			goto label$147;
		}
		label$151:;
		label$150:;
		DWSTRCONCATASSIGNA( &RES$1, (char*)DT$2 );
	}
	goto label$148;
	label$149:;
	{
		uint32* DT$2;
		DT$2 = *(uint32**)((uint8*)ARGTB$1 + (NUM$1 * 24ll));
		if( DT$2 != (uint32*)0ull) goto label$153;
		{
			fb$result$1 = (uint32*)0ull;
			goto label$147;
		}
		label$153:;
		label$152:;
		DWSTRCONCATASSIGN( &RES$1, (uint32*)DT$2 );
	}
	label$148:;
	fb$result$1 = *(uint32**)&RES$1;
	label$147:;
	return fb$result$1;
}

static void HARGAPPENDLFCHAR( void )
{
	label$154:;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$157;
	{
		DZSTRCONCATASSIGN( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (char*)"\x0A" );
		*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + 1ll;
	}
	goto label$156;
	label$157:;
	{
		DWSTRCONCATASSIGNA( (struct $8DWSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (char*)"\x0A" );
		*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + 1ll;
	}
	label$156:;
	label$155:;
}

static void HARGINSERTARGA( char* ARG$1 )
{
	label$158:;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$161;
	{
		DZSTRASSIGN( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (char*)ARG$1 );
		*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		int64 vr$5 = fb_StrLen( (void*)ARG$1, 0ll );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + vr$5;
	}
	goto label$160;
	label$161:;
	{
		DWSTRASSIGNA( (struct $8DWSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (char*)ARG$1 );
		*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		int64 vr$13 = fb_StrLen( (void*)ARG$1, 0ll );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + vr$13;
	}
	label$160:;
	label$159:;
}

static void HARGINSERTARGW( uint32* ARG$1 )
{
	label$162:;
	if( *(int64*)((uint8*)&ENV$ + 912ll) != 0ll) goto label$165;
	{
		DZSTRASSIGNW( (struct $8DZSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (uint32*)ARG$1 );
		*(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(char**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		int64 vr$5 = fb_WstrLen( (uint32*)ARG$1 );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + vr$5;
	}
	goto label$164;
	label$165:;
	{
		DWSTRASSIGN( (struct $8DWSTRING*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll), (uint32*)ARG$1 );
		*(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16808ll) = *(uint32**)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16816ll);
		int64 vr$13 = fb_WstrLen( (uint32*)ARG$1 );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16800ll) + vr$13;
	}
	label$164:;
	label$163:;
}

static FBSTRING* HMACRO_EVALZ( char* ARG$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$166:;
	struct $8DZSTRING RES$1;
	__builtin_memset( &RES$1, 0, 24ll );
	DZSTRASSIGN( &RES$1, (char*)0ull );
	if( *(int64*)((uint8*)&ENV$ + 1296ll) < 16ll) goto label$169;
	{
		*ERRNUM$1 = 27ll;
		fb_StrInit( (void*)&fb$result$1, -1ll, *(void**)&RES$1, 0ll, 0 );
		goto label$167;
	}
	label$169:;
	label$168:;
	if( ARG$1 == (char*)0ull) goto label$171;
	{
		LEXPUSHCTX(  );
		LEXINIT( 2ll );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + 1ll;
		HARGINSERTARGA( ARG$1 );
		HARGAPPENDLFCHAR(  );
		struct $7ASTNODE* EXPR$2;
		struct $7ASTNODE* vr$8 = CEXPRESSION(  );
		EXPR$2 = vr$8;
		$9FB_ERRMSG ERRMSG$2;
		ERRMSG$2 = 0ll;
		if( EXPR$2 == (struct $7ASTNODE*)0ull) goto label$173;
		{
			struct $7ASTNODE* vr$9 = ASTOPTIMIZETREE( EXPR$2 );
			EXPR$2 = vr$9;
			if( *(int64*)EXPR$2 != 16ll) goto label$175;
			{
				FBSTRING TMP$116$4;
				int64 TMP$117$4;
				__builtin_memset( &TMP$116$4, 0, 24ll );
				FBSTRING* vr$12 = ASTCONSTFLUSHTOSTR( EXPR$2 );
				fb_StrAssign( (void*)&TMP$116$4, -1ll, (void*)vr$12, -1ll, 0 );
				DZSTRASSIGN( &RES$1, (char*)*(char**)&TMP$116$4 );
				fb_StrDelete( (FBSTRING*)&TMP$116$4 );
				int64 vr$16 = LEXGETTOKEN( 0ll );
				if( vr$16 == 257ll) goto label$176;
				int64 vr$17 = LEXGETTOKEN( 0ll );
				TMP$117$4 = (int64)-(vr$17 == 256ll);
				goto label$663;
				label$176:;
				TMP$117$4 = -1ll;
				label$663:;
				if( ~TMP$117$4 == 0ll) goto label$178;
				{
					ERRMSG$2 = 17ll;
				}
				label$178:;
				label$177:;
			}
			goto label$174;
			label$175:;
			int64 vr$20 = ASTISCONSTANT( EXPR$2 );
			if( vr$20 == 0ll) goto label$179;
			{
				int64 TMP$118$4;
				char* vr$22 = SYMBGETCONSTSTRASSTR( *(struct $8FBSYMBOL**)((uint8*)EXPR$2 + 24ll) );
				DZSTRASSIGN( &RES$1, (char*)vr$22 );
				int64 vr$24 = LEXGETTOKEN( 0ll );
				if( vr$24 == 257ll) goto label$180;
				int64 vr$25 = LEXGETTOKEN( 0ll );
				TMP$118$4 = (int64)-(vr$25 == 256ll);
				goto label$664;
				label$180:;
				TMP$118$4 = -1ll;
				label$664:;
				if( ~TMP$118$4 == 0ll) goto label$182;
				{
					ERRMSG$2 = 17ll;
				}
				label$182:;
				label$181:;
				ASTDELTREE( EXPR$2 );
			}
			goto label$174;
			label$179:;
			{
				ASTDELTREE( EXPR$2 );
				ERRMSG$2 = 11ll;
				DZSTRASSIGN( &RES$1, (char*)"\x00" );
			}
			label$174:;
		}
		goto label$172;
		label$173:;
		{
			ERRMSG$2 = 17ll;
		}
		label$172:;
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + -1ll;
		LEXPOPCTX(  );
		if( ERRMSG$2 == 0ll) goto label$184;
		{
			ERRREPORTEX( ERRMSG$2, (char*)ARG$1, 0ll, 1ll, (char*)0ull );
			HSKIPUNTIL( 257ll, -1ll, 0ll, 0ll );
		}
		label$184:;
		label$183:;
	}
	label$171:;
	label$170:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, *(void**)&RES$1, 0ll, 0 );
	label$167:;
	FBSTRING* vr$34 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$34;
}

static uint32* HMACRO_EVALW( uint32* ARG$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$185:;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)0ull );
	if( *(int64*)((uint8*)&ENV$ + 1296ll) < 16ll) goto label$188;
	{
		*ERRNUM$1 = 27ll;
		fb$result$1 = *(uint32**)&RES$1;
		goto label$186;
	}
	label$188:;
	label$187:;
	if( ARG$1 == (uint32*)0ull) goto label$190;
	{
		LEXPUSHCTX(  );
		LEXINIT( 2ll );
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + 1ll;
		HARGINSERTARGW( ARG$1 );
		HARGAPPENDLFCHAR(  );
		struct $7ASTNODE* EXPR$2;
		struct $7ASTNODE* vr$5 = CEXPRESSION(  );
		EXPR$2 = vr$5;
		$9FB_ERRMSG ERRMSG$2;
		ERRMSG$2 = 0ll;
		if( EXPR$2 == (struct $7ASTNODE*)0ull) goto label$192;
		{
			struct $7ASTNODE* vr$6 = ASTOPTIMIZETREE( EXPR$2 );
			EXPR$2 = vr$6;
			if( *(int64*)EXPR$2 != 16ll) goto label$194;
			{
				int64 TMP$120$4;
				uint32* vr$8 = ASTCONSTFLUSHTOWSTR( EXPR$2 );
				DWSTRASSIGN( &RES$1, (uint32*)vr$8 );
				int64 vr$9 = LEXGETTOKEN( 0ll );
				if( vr$9 == 257ll) goto label$195;
				int64 vr$10 = LEXGETTOKEN( 0ll );
				TMP$120$4 = (int64)-(vr$10 == 256ll);
				goto label$665;
				label$195:;
				TMP$120$4 = -1ll;
				label$665:;
				if( ~TMP$120$4 == 0ll) goto label$197;
				{
					ERRMSG$2 = 17ll;
				}
				label$197:;
				label$196:;
			}
			goto label$193;
			label$194:;
			int64 vr$13 = ASTISCONSTANT( EXPR$2 );
			if( vr$13 == 0ll) goto label$198;
			{
				int64 TMP$121$4;
				uint32* vr$15 = SYMBGETCONSTSTRASWSTR( *(struct $8FBSYMBOL**)((uint8*)EXPR$2 + 24ll) );
				DWSTRASSIGN( &RES$1, (uint32*)vr$15 );
				int64 vr$16 = LEXGETTOKEN( 0ll );
				if( vr$16 == 257ll) goto label$199;
				int64 vr$17 = LEXGETTOKEN( 0ll );
				TMP$121$4 = (int64)-(vr$17 == 256ll);
				goto label$666;
				label$199:;
				TMP$121$4 = -1ll;
				label$666:;
				if( ~TMP$121$4 == 0ll) goto label$201;
				{
					ERRMSG$2 = 17ll;
				}
				label$201:;
				label$200:;
				ASTDELTREE( EXPR$2 );
			}
			goto label$193;
			label$198:;
			{
				ASTDELTREE( EXPR$2 );
				ERRMSG$2 = 11ll;
				DWSTRASSIGN( &RES$1, (uint32*)L"\x00000000\x00000000" );
			}
			label$193:;
		}
		goto label$191;
		label$192:;
		{
			ERRMSG$2 = 17ll;
		}
		label$191:;
		*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + -1ll;
		LEXPOPCTX(  );
		if( ERRMSG$2 == 0ll) goto label$203;
		{
			FBSTRING TMP$123$3;
			__builtin_memset( &TMP$123$3, 0, 24ll );
			FBSTRING* vr$24 = fb_WstrToStr( (uint32*)ARG$1 );
			fb_StrAssign( (void*)&TMP$123$3, -1ll, (void*)vr$24, -1ll, 0 );
			ERRREPORTEX( ERRMSG$2, (char*)*(char**)&TMP$123$3, 0ll, 1ll, (char*)0ull );
			fb_StrDelete( (FBSTRING*)&TMP$123$3 );
			HSKIPUNTIL( 257ll, -1ll, 0ll, 0ll );
		}
		label$203:;
		label$202:;
	}
	label$190:;
	label$189:;
	fb$result$1 = *(uint32**)&RES$1;
	label$186:;
	return fb$result$1;
}

static FBSTRING* HDEFUNIQUEIDPUSH_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$204:;
	if( *(int64*)((uint8*)&PP$ + 392ll) == 0ll) goto label$207;
	{
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$205;
	}
	label$207:;
	label$206:;
	char* ID$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ID$1 = vr$2;
	if( ID$1 != (char*)0ull) goto label$209;
	{
		*ERRNUM$1 = 1ll;
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$205;
	}
	label$209:;
	label$208:;
	struct $23SYMB_DEF_UNIQUEID_STACK* STK$1;
	void* vr$6 = HASHLOOKUP( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll), (char*)ID$1 );
	STK$1 = (struct $23SYMB_DEF_UNIQUEID_STACK*)vr$6;
	if( STK$1 != (struct $23SYMB_DEF_UNIQUEID_STACK*)0ull) goto label$211;
	{
		void* vr$7 = calloc( 8ull, 1ull );
		STK$1 = (struct $23SYMB_DEF_UNIQUEID_STACK*)vr$7;
		HASHADD( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll), (char*)ID$1, (void*)STK$1, 18446744073709551615ull );
	}
	goto label$210;
	label$211:;
	{
		if( ID$1 == (char*)0ull) goto label$213;
		{
			free( (void*)ID$1 );
		}
		label$213:;
		label$212:;
	}
	label$210:;
	struct $21SYMB_DEF_UNIQUEID_ELM* ELM$1;
	void* vr$9 = malloc( 16ull );
	ELM$1 = (struct $21SYMB_DEF_UNIQUEID_ELM*)vr$9;
	char* UID$1;
	char* vr$10 = SYMBUNIQUEID( (boolean)1ll );
	UID$1 = vr$10;
	int64 vr$11 = fb_StrLen( (void*)UID$1, 0ll );
	void* vr$13 = malloc( (uint64)(vr$11 + 1ll) );
	*(char**)ELM$1 = (char*)vr$13;
	fb_StrAssign( *(void**)ELM$1, 0ll, (void*)UID$1, 0ll, 0 );
	*(struct $21SYMB_DEF_UNIQUEID_ELM**)((uint8*)ELM$1 + 8ll) = *(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1;
	*(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 = ELM$1;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
	label$205:;
	FBSTRING* vr$21 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$21;
}

static FBSTRING* HDEFUNIQUEID_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$214:;
	if( *(int64*)((uint8*)&PP$ + 392ll) == 0ll) goto label$217;
	{
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$215;
	}
	label$217:;
	label$216:;
	char* ID$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ID$1 = vr$2;
	if( ID$1 != (char*)0ull) goto label$219;
	{
		*ERRNUM$1 = 1ll;
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$215;
	}
	label$219:;
	label$218:;
	struct $23SYMB_DEF_UNIQUEID_STACK* STK$1;
	void* vr$6 = HASHLOOKUP( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll), (char*)ID$1 );
	STK$1 = (struct $23SYMB_DEF_UNIQUEID_STACK*)vr$6;
	if( ID$1 == (char*)0ull) goto label$221;
	{
		free( (void*)ID$1 );
	}
	label$221:;
	label$220:;
	if( STK$1 == (struct $23SYMB_DEF_UNIQUEID_STACK*)0ull) goto label$223;
	{
		if( *(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 == (struct $21SYMB_DEF_UNIQUEID_ELM*)0ull) goto label$225;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, *(void**)*(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1, 0ll, 0 );
			goto label$215;
		}
		label$225:;
		label$224:;
	}
	label$223:;
	label$222:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
	label$215:;
	FBSTRING* vr$13 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$13;
}

static FBSTRING* HDEFUNIQUEIDPOP_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$226:;
	if( *(int64*)((uint8*)&PP$ + 392ll) == 0ll) goto label$229;
	{
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$227;
	}
	label$229:;
	label$228:;
	char* ID$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ID$1 = vr$2;
	if( ID$1 != (char*)0ull) goto label$231;
	{
		*ERRNUM$1 = 1ll;
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
		goto label$227;
	}
	label$231:;
	label$230:;
	struct $23SYMB_DEF_UNIQUEID_STACK* STK$1;
	void* vr$6 = HASHLOOKUP( (struct $5THASH*)((uint8*)&SYMB$ + 197472ll), (char*)ID$1 );
	STK$1 = (struct $23SYMB_DEF_UNIQUEID_STACK*)vr$6;
	if( ID$1 == (char*)0ull) goto label$233;
	{
		free( (void*)ID$1 );
	}
	label$233:;
	label$232:;
	if( STK$1 == (struct $23SYMB_DEF_UNIQUEID_STACK*)0ull) goto label$235;
	{
		if( *(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 == (struct $21SYMB_DEF_UNIQUEID_ELM*)0ull) goto label$237;
		{
			free( *(void**)*(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 );
			*(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 = *(struct $21SYMB_DEF_UNIQUEID_ELM**)((uint8*)*(struct $21SYMB_DEF_UNIQUEID_ELM**)STK$1 + 8ll);
		}
		goto label$236;
		label$237:;
		{
			*ERRNUM$1 = 17ll;
		}
		label$236:;
	}
	goto label$234;
	label$235:;
	{
		*ERRNUM$1 = 17ll;
	}
	label$234:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"", 1ll, 0 );
	label$227:;
	FBSTRING* vr$17 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$17;
}

static FBSTRING* HDEFARGCOUNT_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$238:;
	if( ARGTB$1 == (struct $11LEXPP_ARGTB*)0ull) goto label$241;
	{
		FBSTRING* vr$2 = fb_LongintToStr( *(int64*)((uint8*)ARGTB$1 + 768ll) );
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
		goto label$239;
	}
	label$241:;
	label$240:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"0", 2ll, 0 );
	label$239:;
	FBSTRING* vr$6 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$6;
}

static FBSTRING* HDEFARGEXTRACT_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$242:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* NUMSTR$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	NUMSTR$1 = vr$2;
	if( NUMSTR$1 == (char*)0ull) goto label$245;
	{
		FBSTRING VARSTR$2;
		FBSTRING* vr$3 = HMACRO_EVALZ( NUMSTR$1, ERRNUM$1 );
		fb_StrInit( (void*)&VARSTR$2, -1ll, (void*)vr$3, -1ll, 0 );
		int32 INDEX$2;
		__builtin_memset( &INDEX$2, 0, 4ll );
		int64 vr$8 = HSTR2LONG( &VARSTR$2, &INDEX$2 );
		if( vr$8 == 0ll) goto label$247;
		{
			if( (int64)INDEX$2 < 0ll) goto label$249;
			{
				uint32 NUMVARARGS$4;
				NUMVARARGS$4 = (uint32)(*(int64*)((uint8*)ARGTB$1 + 768ll) + -1ll);
				if( (int64)INDEX$2 >= (int64)NUMVARARGS$4) goto label$251;
				{
					char* ARGSTRING$5;
					char* vr$15 = HMACRO_GETARGZ( ARGTB$1, 1ll );
					ARGSTRING$5 = vr$15;
					struct $7FBARRAYI8FBSTRINGE VARARGS$5;
					*(FBSTRING**)&VARARGS$5 = (FBSTRING*)0ull;
					*(FBSTRING**)((uint8*)&VARARGS$5 + 8ll) = (FBSTRING*)0ull;
					*(int64*)((uint8*)&VARARGS$5 + 16ll) = 0ll;
					*(int64*)((uint8*)&VARARGS$5 + 24ll) = 24ll;
					*(int64*)((uint8*)&VARARGS$5 + 32ll) = 0ll;
					*(int64*)((uint8*)&VARARGS$5 + 40ll) = 8ll;
					__builtin_memset( (void*)((uint8*)&VARARGS$5 + 48ll), 0, 192ll );
					int64 vr$18 = HSTR2ARGS( (char*)ARGSTRING$5, &VARARGS$5 );
					if( vr$18 <= 0ll) goto label$253;
					{
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)(((int64)INDEX$2 * 24ll) + *(int64*)&VARARGS$5), -1ll, 0 );
					}
					label$253:;
					label$252:;
					if( ARGSTRING$5 == (char*)0ull) goto label$255;
					{
						free( (void*)ARGSTRING$5 );
					}
					label$255:;
					label$254:;
					fb_ArrayStrErase( (struct $7FBARRAYIvE*)&VARARGS$5 );
				}
				label$251:;
				label$250:;
			}
			goto label$248;
			label$249:;
			{
				*ERRNUM$1 = 17ll;
			}
			label$248:;
		}
		goto label$246;
		label$247:;
		{
			*ERRNUM$1 = 17ll;
		}
		label$246:;
		if( NUMSTR$1 == (char*)0ull) goto label$257;
		{
			free( (void*)NUMSTR$1 );
		}
		label$257:;
		label$256:;
		fb_StrDelete( (FBSTRING*)&VARSTR$2 );
	}
	goto label$244;
	label$245:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$244:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	goto label$243;
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$243:;
	FBSTRING* vr$34 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$34;
}

static FBSTRING* HDEFARGLISTEXPANDZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	int64 TMP$125$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$258:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* MACRONAMESTR$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	MACRONAMESTR$1 = vr$2;
	char* NUMSTR$1;
	char* vr$3 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	NUMSTR$1 = vr$3;
	if( MACRONAMESTR$1 == (char*)0ull) goto label$260;
	TMP$125$1 = (int64)-(NUMSTR$1 != (char*)0ull);
	goto label$667;
	label$260:;
	TMP$125$1 = 0ll;
	label$667:;
	if( TMP$125$1 == 0ll) goto label$262;
	{
		FBSTRING VARSTR$2;
		FBSTRING* vr$5 = HMACRO_EVALZ( NUMSTR$1, ERRNUM$1 );
		fb_StrInit( (void*)&VARSTR$2, -1ll, (void*)vr$5, -1ll, 0 );
		int32 ARGCOUNT$2;
		__builtin_memset( &ARGCOUNT$2, 0, 4ll );
		int32 INDEX$2;
		__builtin_memset( &INDEX$2, 0, 4ll );
		int32 INDEX2$2;
		INDEX2$2 = 0;
		int64 vr$11 = HSTR2LONG( &VARSTR$2, &ARGCOUNT$2 );
		if( vr$11 == 0ll) goto label$264;
		{
			int32 NUMVARARGS$3;
			NUMVARARGS$3 = (int32)(*(int64*)((uint8*)ARGTB$1 + 768ll) + -2ll);
			int32 MAXVARARGS$3;
			if( (int64)NUMVARARGS$3 <= 0ll) goto label$266;
			{
				char* ARGSTR$4;
				char* vr$16 = HMACRO_GETARGZ( ARGTB$1, 2ll );
				ARGSTR$4 = vr$16;
				struct $7FBARRAYI8FBSTRINGE VARARGS$4;
				*(FBSTRING**)&VARARGS$4 = (FBSTRING*)0ull;
				*(FBSTRING**)((uint8*)&VARARGS$4 + 8ll) = (FBSTRING*)0ull;
				*(int64*)((uint8*)&VARARGS$4 + 16ll) = 0ll;
				*(int64*)((uint8*)&VARARGS$4 + 24ll) = 24ll;
				*(int64*)((uint8*)&VARARGS$4 + 32ll) = 0ll;
				*(int64*)((uint8*)&VARARGS$4 + 40ll) = 8ll;
				__builtin_memset( (void*)((uint8*)&VARARGS$4 + 48ll), 0, 192ll );
				if( (int64)ARGCOUNT$2 != 0ll) goto label$268;
				{
					FBSTRING TMP$127$5;
					FBSTRING TMP$128$5;
					FBSTRING TMP$129$5;
					__builtin_memset( &TMP$127$5, 0, 24ll );
					FBSTRING* vr$21 = fb_StrConcat( &TMP$127$5, (void*)MACRONAMESTR$1, 0ll, (void*)"(", 2ll );
					__builtin_memset( &TMP$128$5, 0, 24ll );
					FBSTRING* vr$25 = fb_StrConcat( &TMP$128$5, (void*)&RES$1, -1ll, (void*)vr$21, -1ll );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$25, -1ll, 0 );
					__builtin_memset( &TMP$129$5, 0, 24ll );
					FBSTRING* vr$30 = fb_StrConcat( &TMP$129$5, (void*)&RES$1, -1ll, (void*)ARGSTR$4, 0ll );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$30, -1ll, 0 );
					fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)")", 2ll, 0 );
				}
				goto label$267;
				label$268:;
				{
					int64 vr$34 = HSTR2ARGS( (char*)ARGSTR$4, &VARARGS$4 );
					NUMVARARGS$3 = (int32)(vr$34 + -1ll);
					if( (int64)ARGCOUNT$2 >= 0ll) goto label$270;
					{
						{
							INDEX$2 = 0;
							int32 TMP$131$7;
							TMP$131$7 = NUMVARARGS$3;
							int32 TMP$132$7;
							TMP$132$7 = (int32)-(int64)ARGCOUNT$2;
							int64 TMP$133$7;
							TMP$133$7 = (int64)-((int64)TMP$132$7 >= 0ll);
							goto label$271;
							label$274:;
							{
								FBSTRING TMP$134$8;
								FBSTRING TMP$135$8;
								if( (int64)INDEX$2 <= 0ll) goto label$276;
								{
									fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)"\x0A", 2ll, 0 );
								}
								label$276:;
								label$275:;
								__builtin_memset( &TMP$134$8, 0, 24ll );
								FBSTRING* vr$47 = fb_StrConcat( &TMP$134$8, (void*)MACRONAMESTR$1, 0ll, (void*)"(", 2ll );
								__builtin_memset( &TMP$135$8, 0, 24ll );
								FBSTRING* vr$51 = fb_StrConcat( &TMP$135$8, (void*)&RES$1, -1ll, (void*)vr$47, -1ll );
								fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$51, -1ll, 0 );
								{
									INDEX2$2 = INDEX$2;
									int32 TMP$136$9;
									TMP$136$9 = NUMVARARGS$3;
									goto label$277;
									label$280:;
									{
										fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)(((int64)INDEX2$2 * 24ll) + *(int64*)&VARARGS$4), -1ll, 0 );
										if( (int64)INDEX2$2 == (int64)NUMVARARGS$3) goto label$282;
										{
											fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)",", 2ll, 0 );
										}
										label$282:;
										label$281:;
									}
									label$278:;
									INDEX2$2 = (int32)((int64)INDEX2$2 + 1ll);
									label$277:;
									if( (int64)INDEX2$2 <= (int64)TMP$136$9) goto label$280;
									label$279:;
								}
								fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)")", 2ll, 0 );
							}
							label$272:;
							INDEX$2 = (int32)((int64)INDEX$2 + (int64)TMP$132$7);
							label$271:;
							if( TMP$133$7 != 0ll) goto label$283;
							if( (int64)INDEX$2 >= (int64)TMP$131$7) goto label$274;
							goto label$273;
							label$283:;
							if( (int64)INDEX$2 <= (int64)TMP$131$7) goto label$274;
							label$273:;
						}
					}
					goto label$269;
					label$270:;
					{
						{
							INDEX$2 = 0;
							int32 TMP$138$7;
							TMP$138$7 = NUMVARARGS$3;
							int32 TMP$139$7;
							TMP$139$7 = ARGCOUNT$2;
							int64 TMP$140$7;
							TMP$140$7 = (int64)-((int64)TMP$139$7 >= 0ll);
							goto label$284;
							label$287:;
							{
								FBSTRING TMP$141$8;
								FBSTRING TMP$142$8;
								int64 TMP$143$8;
								if( (int64)INDEX$2 <= 0ll) goto label$289;
								{
									fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)"\x0A", 2ll, 0 );
								}
								label$289:;
								label$288:;
								__builtin_memset( &TMP$141$8, 0, 24ll );
								FBSTRING* vr$81 = fb_StrConcat( &TMP$141$8, (void*)MACRONAMESTR$1, 0ll, (void*)"(", 2ll );
								__builtin_memset( &TMP$142$8, 0, 24ll );
								FBSTRING* vr$85 = fb_StrConcat( &TMP$142$8, (void*)&RES$1, -1ll, (void*)vr$81, -1ll );
								fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$85, -1ll, 0 );
								if( (int64)ARGCOUNT$2 <= ((int64)NUMVARARGS$3 - (int64)INDEX$2)) goto label$290;
								TMP$143$8 = (int64)NUMVARARGS$3;
								goto label$668;
								label$290:;
								TMP$143$8 = ((int64)INDEX$2 + (int64)ARGCOUNT$2) + -1ll;
								label$668:;
								MAXVARARGS$3 = (int32)TMP$143$8;
								{
									INDEX2$2 = INDEX$2;
									int32 TMP$144$9;
									TMP$144$9 = MAXVARARGS$3;
									goto label$291;
									label$294:;
									{
										fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)(((int64)INDEX2$2 * 24ll) + *(int64*)&VARARGS$4), -1ll, 0 );
										if( (int64)INDEX2$2 == (int64)MAXVARARGS$3) goto label$296;
										{
											fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)",", 2ll, 0 );
										}
										label$296:;
										label$295:;
									}
									label$292:;
									INDEX2$2 = (int32)((int64)INDEX2$2 + 1ll);
									label$291:;
									if( (int64)INDEX2$2 <= (int64)TMP$144$9) goto label$294;
									label$293:;
								}
								fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)")", 2ll, 0 );
							}
							label$285:;
							INDEX$2 = (int32)((int64)INDEX$2 + (int64)TMP$139$7);
							label$284:;
							if( TMP$140$7 != 0ll) goto label$297;
							if( (int64)INDEX$2 >= (int64)TMP$138$7) goto label$287;
							goto label$286;
							label$297:;
							if( (int64)INDEX$2 <= (int64)TMP$138$7) goto label$287;
							label$286:;
						}
					}
					label$269:;
				}
				label$267:;
				if( ARGSTR$4 == (char*)0ull) goto label$299;
				{
					free( (void*)ARGSTR$4 );
				}
				label$299:;
				label$298:;
				fb_ArrayStrErase( (struct $7FBARRAYIvE*)&VARARGS$4 );
			}
			goto label$265;
			label$266:;
			{
				*ERRNUM$1 = 1ll;
			}
			label$265:;
		}
		label$264:;
		label$263:;
		fb_StrDelete( (FBSTRING*)&VARSTR$2 );
	}
	goto label$261;
	label$262:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$261:;
	if( NUMSTR$1 == (char*)0ull) goto label$301;
	{
		free( (void*)NUMSTR$1 );
	}
	label$301:;
	label$300:;
	if( MACRONAMESTR$1 == (char*)0ull) goto label$303;
	{
		free( (void*)MACRONAMESTR$1 );
	}
	label$303:;
	label$302:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	goto label$259;
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$259:;
	FBSTRING* vr$128 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$128;
}

static uint32* HDEFARGLISTEXPANDW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	int64 TMP$146$1;
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$304:;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)L"" );
	struct $8DWSTRING MACRONAMESTR$1;
	__builtin_memset( &MACRONAMESTR$1, 0, 24ll );
	uint32* vr$2 = HMACRO_GETARGW( ARGTB$1, 0ll );
	DWSTRASSIGN( &MACRONAMESTR$1, (uint32*)vr$2 );
	uint32* NUMSTR$1;
	uint32* vr$4 = HMACRO_GETARGW( ARGTB$1, 1ll );
	NUMSTR$1 = vr$4;
	if( *(int64*)((uint8*)&MACRONAMESTR$1 + 8ll) == 0ll) goto label$306;
	TMP$146$1 = (int64)-(NUMSTR$1 != (uint32*)0ull);
	goto label$669;
	label$306:;
	TMP$146$1 = 0ll;
	label$669:;
	if( TMP$146$1 == 0ll) goto label$308;
	{
		uint32* PVARSTR$2;
		uint32* vr$6 = HMACRO_EVALW( NUMSTR$1, ERRNUM$1 );
		PVARSTR$2 = vr$6;
		int32 ARGCOUNT$2;
		__builtin_memset( &ARGCOUNT$2, 0, 4ll );
		int32 INDEX$2;
		__builtin_memset( &INDEX$2, 0, 4ll );
		int32 INDEX2$2;
		INDEX2$2 = 0;
		int64 vr$10 = HWSTR2LONG( PVARSTR$2, &ARGCOUNT$2 );
		if( vr$10 == 0ll) goto label$310;
		{
			int32 NUMVARARGS$3;
			NUMVARARGS$3 = (int32)(*(int64*)((uint8*)ARGTB$1 + 768ll) + -2ll);
			int32 MAXVARARGS$3;
			if( (int64)NUMVARARGS$3 <= 0ll) goto label$312;
			{
				uint32* ARGSTR$4;
				uint32* vr$15 = HMACRO_GETARGW( ARGTB$1, 2ll );
				ARGSTR$4 = vr$15;
				if( (int64)ARGCOUNT$2 != 0ll) goto label$314;
				{
					uint32* TMP$147$5;
					uint32* TMP$148$5;
					DWSTRASSIGN( &RES$1, (uint32*)*(uint32**)&MACRONAMESTR$1 );
					uint32* vr$17 = fb_WstrConcatAW( (void*)"(", 2ll, (uint32*)ARGSTR$4 );
					TMP$147$5 = vr$17;
					uint32* vr$18 = fb_WstrConcatWA( (uint32*)TMP$147$5, (void*)")", 2ll );
					TMP$148$5 = vr$18;
					DWSTRCONCATASSIGN( &RES$1, (uint32*)TMP$148$5 );
					fb_WstrDelete( (uint32*)TMP$148$5 );
					fb_WstrDelete( (uint32*)TMP$147$5 );
				}
				goto label$313;
				label$314:;
				{
					struct $7FBARRAYI8DWSTRINGE VARARGS$5;
					*(struct $8DWSTRING**)&VARARGS$5 = (struct $8DWSTRING*)0ull;
					*(struct $8DWSTRING**)((uint8*)&VARARGS$5 + 8ll) = (struct $8DWSTRING*)0ull;
					*(int64*)((uint8*)&VARARGS$5 + 16ll) = 0ll;
					*(int64*)((uint8*)&VARARGS$5 + 24ll) = 24ll;
					*(int64*)((uint8*)&VARARGS$5 + 32ll) = 0ll;
					*(int64*)((uint8*)&VARARGS$5 + 40ll) = 8ll;
					__builtin_memset( (void*)((uint8*)&VARARGS$5 + 48ll), 0, 192ll );
					int64 vr$21 = HWSTR2ARGS( (uint32*)ARGSTR$4, &VARARGS$5 );
					NUMVARARGS$3 = (int32)(vr$21 + -1ll);
					if( (int64)ARGCOUNT$2 >= 0ll) goto label$316;
					{
						{
							INDEX$2 = 0;
							int32 TMP$149$7;
							TMP$149$7 = NUMVARARGS$3;
							int32 TMP$150$7;
							TMP$150$7 = (int32)-(int64)ARGCOUNT$2;
							int64 TMP$151$7;
							TMP$151$7 = (int64)-((int64)TMP$150$7 >= 0ll);
							goto label$317;
							label$320:;
							{
								if( (int64)INDEX$2 <= 0ll) goto label$322;
								{
									DWSTRCONCATASSIGN( &RES$1, (uint32*)L"\x0000000A" );
								}
								label$322:;
								label$321:;
								DWSTRCONCATASSIGN( &RES$1, (uint32*)*(uint32**)&MACRONAMESTR$1 );
								DWSTRCONCATASSIGN( &RES$1, (uint32*)L"(" );
								{
									INDEX2$2 = INDEX$2;
									int32 TMP$154$9;
									TMP$154$9 = NUMVARARGS$3;
									goto label$323;
									label$326:;
									{
										DWSTRCONCATASSIGN( &RES$1, (uint32*)*(uint32**)(((int64)INDEX2$2 * 24ll) + *(int64*)&VARARGS$5) );
										if( (int64)INDEX2$2 == (int64)NUMVARARGS$3) goto label$328;
										{
											DWSTRCONCATASSIGN( &RES$1, (uint32*)L"," );
										}
										label$328:;
										label$327:;
									}
									label$324:;
									INDEX2$2 = (int32)((int64)INDEX2$2 + 1ll);
									label$323:;
									if( (int64)INDEX2$2 <= (int64)TMP$154$9) goto label$326;
									label$325:;
								}
								DWSTRCONCATASSIGN( &RES$1, (uint32*)L")" );
							}
							label$318:;
							INDEX$2 = (int32)((int64)INDEX$2 + (int64)TMP$150$7);
							label$317:;
							if( TMP$151$7 != 0ll) goto label$329;
							if( (int64)INDEX$2 >= (int64)TMP$149$7) goto label$320;
							goto label$319;
							label$329:;
							if( (int64)INDEX$2 <= (int64)TMP$149$7) goto label$320;
							label$319:;
						}
					}
					goto label$315;
					label$316:;
					{
						{
							INDEX$2 = 0;
							int32 TMP$157$7;
							TMP$157$7 = NUMVARARGS$3;
							int32 TMP$158$7;
							TMP$158$7 = ARGCOUNT$2;
							int64 TMP$159$7;
							TMP$159$7 = (int64)-((int64)TMP$158$7 >= 0ll);
							goto label$330;
							label$333:;
							{
								int64 TMP$160$8;
								if( (int64)INDEX$2 <= 0ll) goto label$335;
								{
									DWSTRCONCATASSIGN( &RES$1, (uint32*)L"\x0000000A" );
								}
								label$335:;
								label$334:;
								DWSTRCONCATASSIGN( &RES$1, (uint32*)*(uint32**)&MACRONAMESTR$1 );
								DWSTRCONCATASSIGN( &RES$1, (uint32*)L"(" );
								if( (int64)ARGCOUNT$2 <= ((int64)NUMVARARGS$3 - (int64)INDEX$2)) goto label$336;
								TMP$160$8 = (int64)NUMVARARGS$3;
								goto label$670;
								label$336:;
								TMP$160$8 = ((int64)INDEX$2 + (int64)ARGCOUNT$2) + -1ll;
								label$670:;
								MAXVARARGS$3 = (int32)TMP$160$8;
								{
									INDEX2$2 = INDEX$2;
									int32 TMP$161$9;
									TMP$161$9 = MAXVARARGS$3;
									goto label$337;
									label$340:;
									{
										DWSTRCONCATASSIGN( &RES$1, (uint32*)*(uint32**)(((int64)INDEX2$2 * 24ll) + *(int64*)&VARARGS$5) );
										if( (int64)INDEX2$2 == (int64)MAXVARARGS$3) goto label$342;
										{
											DWSTRCONCATASSIGN( &RES$1, (uint32*)L"," );
										}
										label$342:;
										label$341:;
									}
									label$338:;
									INDEX2$2 = (int32)((int64)INDEX2$2 + 1ll);
									label$337:;
									if( (int64)INDEX2$2 <= (int64)TMP$161$9) goto label$340;
									label$339:;
								}
								DWSTRCONCATASSIGN( &RES$1, (uint32*)L")" );
							}
							label$331:;
							INDEX$2 = (int32)((int64)INDEX$2 + (int64)TMP$158$7);
							label$330:;
							if( TMP$159$7 != 0ll) goto label$343;
							if( (int64)INDEX$2 >= (int64)TMP$157$7) goto label$333;
							goto label$332;
							label$343:;
							if( (int64)INDEX$2 <= (int64)TMP$157$7) goto label$333;
							label$332:;
						}
					}
					label$315:;
					fb_ArrayErase( (struct $7FBARRAYIvE*)&VARARGS$5 );
				}
				label$313:;
			}
			goto label$311;
			label$312:;
			{
				*ERRNUM$1 = 1ll;
			}
			label$311:;
		}
		label$310:;
		label$309:;
	}
	goto label$307;
	label$308:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$307:;
	fb$result$1 = *(uint32**)&RES$1;
	goto label$305;
	label$305:;
	return fb$result$1;
}

static FBSTRING* HDEFARGLEFT_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$344:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* ARG$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ARG$1 = vr$2;
	char* SEP$1;
	char* vr$3 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	SEP$1 = vr$3;
	char* RET$1;
	char* vr$4 = HMACRO_GETARGZ( ARGTB$1, 2ll );
	RET$1 = vr$4;
	if( ((int64)-(ARG$1 != (char*)0ull) & (int64)-(SEP$1 != (char*)0ull)) == 0ll) goto label$347;
	{
		struct $7FBARRAYI8FBSTRINGE TOKENS$2;
		*(FBSTRING**)&TOKENS$2 = (FBSTRING*)0ull;
		*(FBSTRING**)((uint8*)&TOKENS$2 + 8ll) = (FBSTRING*)0ull;
		*(int64*)((uint8*)&TOKENS$2 + 16ll) = 0ll;
		*(int64*)((uint8*)&TOKENS$2 + 24ll) = 24ll;
		*(int64*)((uint8*)&TOKENS$2 + 32ll) = 0ll;
		*(int64*)((uint8*)&TOKENS$2 + 40ll) = 8ll;
		__builtin_memset( (void*)((uint8*)&TOKENS$2 + 48ll), 0, 192ll );
		int64 NUMTOKS$2;
		int64 vr$10 = HSTR2TOK( (char*)ARG$1, &TOKENS$2 );
		NUMTOKS$2 = vr$10;
		if( NUMTOKS$2 <= 0ll) goto label$349;
		{
			HUCASE( (char*)SEP$1, SEP$1 );
			{
				int64 I$4;
				I$4 = 0ll;
				int64 TMP$162$4;
				TMP$162$4 = NUMTOKS$2 + -1ll;
				goto label$350;
				label$353:;
				{
					FBSTRING* vr$15 = fb_StrUcase2( (FBSTRING*)((I$4 * 24ll) + *(int64*)&TOKENS$2), 0 );
					int32 vr$16 = fb_StrCompare( (void*)vr$15, -1ll, (void*)SEP$1, 0ll );
					if( (int64)vr$16 != 0ll) goto label$355;
					{
						{
							int64 J$7;
							J$7 = 0ll;
							int64 TMP$163$7;
							TMP$163$7 = I$4 + -1ll;
							goto label$356;
							label$359:;
							{
								if( J$7 <= 0ll) goto label$361;
								{
									fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)" ", 2ll, 0 );
								}
								label$361:;
								label$360:;
								fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)((J$7 * 24ll) + *(int64*)&TOKENS$2), -1ll, 0 );
							}
							label$357:;
							J$7 = J$7 + 1ll;
							label$356:;
							if( J$7 <= TMP$163$7) goto label$359;
							label$358:;
						}
						goto label$352;
					}
					label$355:;
					label$354:;
				}
				label$351:;
				I$4 = I$4 + 1ll;
				label$350:;
				if( I$4 <= TMP$162$4) goto label$353;
				label$352:;
			}
			int64 vr$27 = fb_StrLen( (void*)&RES$1, -1ll );
			if( vr$27 != 0ll) goto label$363;
			{
				fb_StrAssign( (void*)&RES$1, -1ll, (void*)RET$1, 0ll, 0 );
			}
			label$363:;
			label$362:;
		}
		goto label$348;
		label$349:;
		{
			*ERRNUM$1 = 17ll;
		}
		label$348:;
		fb_ArrayStrErase( (struct $7FBARRAYIvE*)&TOKENS$2 );
	}
	goto label$346;
	label$347:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$346:;
	if( RET$1 == (char*)0ull) goto label$365;
	{
		free( (void*)RET$1 );
	}
	label$365:;
	label$364:;
	if( SEP$1 == (char*)0ull) goto label$367;
	{
		free( (void*)SEP$1 );
	}
	label$367:;
	label$366:;
	if( ARG$1 == (char*)0ull) goto label$369;
	{
		free( (void*)ARG$1 );
	}
	label$369:;
	label$368:;
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	goto label$345;
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$345:;
	FBSTRING* vr$37 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$37;
}

static FBSTRING* HDEFARGRIGHT_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$370:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* ARG$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ARG$1 = vr$2;
	char* SEP$1;
	char* vr$3 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	SEP$1 = vr$3;
	char* RET$1;
	char* vr$4 = HMACRO_GETARGZ( ARGTB$1, 2ll );
	RET$1 = vr$4;
	if( ((int64)-(ARG$1 != (char*)0ull) & (int64)-(SEP$1 != (char*)0ull)) == 0ll) goto label$373;
	{
		struct $7FBARRAYI8FBSTRINGE TOKENS$2;
		*(FBSTRING**)&TOKENS$2 = (FBSTRING*)0ull;
		*(FBSTRING**)((uint8*)&TOKENS$2 + 8ll) = (FBSTRING*)0ull;
		*(int64*)((uint8*)&TOKENS$2 + 16ll) = 0ll;
		*(int64*)((uint8*)&TOKENS$2 + 24ll) = 24ll;
		*(int64*)((uint8*)&TOKENS$2 + 32ll) = 0ll;
		*(int64*)((uint8*)&TOKENS$2 + 40ll) = 8ll;
		__builtin_memset( (void*)((uint8*)&TOKENS$2 + 48ll), 0, 192ll );
		int64 NUMTOKS$2;
		int64 vr$10 = HSTR2TOK( (char*)ARG$1, &TOKENS$2 );
		NUMTOKS$2 = vr$10;
		if( NUMTOKS$2 <= 0ll) goto label$375;
		{
			HUCASE( (char*)SEP$1, SEP$1 );
			{
				int64 I$4;
				I$4 = 0ll;
				int64 TMP$165$4;
				TMP$165$4 = NUMTOKS$2 + -1ll;
				goto label$376;
				label$379:;
				{
					FBSTRING* vr$15 = fb_StrUcase2( (FBSTRING*)((I$4 * 24ll) + *(int64*)&TOKENS$2), 0 );
					int32 vr$16 = fb_StrCompare( (void*)vr$15, -1ll, (void*)SEP$1, 0ll );
					if( (int64)vr$16 != 0ll) goto label$381;
					{
						{
							int64 J$7;
							J$7 = I$4 + 1ll;
							int64 TMP$166$7;
							TMP$166$7 = NUMTOKS$2 + -1ll;
							goto label$382;
							label$385:;
							{
								int64 vr$21 = fb_StrLen( (void*)&RES$1, -1ll );
								if( vr$21 <= 0ll) goto label$387;
								{
									fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)" ", 2ll, 0 );
								}
								label$387:;
								label$386:;
								fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)((J$7 * 24ll) + *(int64*)&TOKENS$2), -1ll, 0 );
							}
							label$383:;
							J$7 = J$7 + 1ll;
							label$382:;
							if( J$7 <= TMP$166$7) goto label$385;
							label$384:;
						}
						goto label$378;
					}
					label$381:;
					label$380:;
				}
				label$377:;
				I$4 = I$4 + 1ll;
				label$376:;
				if( I$4 <= TMP$165$4) goto label$379;
				label$378:;
			}
			int64 vr$30 = fb_StrLen( (void*)&RES$1, -1ll );
			if( vr$30 != 0ll) goto label$389;
			{
				fb_StrAssign( (void*)&RES$1, -1ll, (void*)RET$1, 0ll, 0 );
			}
			label$389:;
			label$388:;
		}
		goto label$374;
		label$375:;
		{
			*ERRNUM$1 = 17ll;
		}
		label$374:;
		fb_ArrayStrErase( (struct $7FBARRAYIvE*)&TOKENS$2 );
	}
	goto label$372;
	label$373:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$372:;
	if( RET$1 == (char*)0ull) goto label$391;
	{
		free( (void*)RET$1 );
	}
	label$391:;
	label$390:;
	if( SEP$1 == (char*)0ull) goto label$393;
	{
		free( (void*)SEP$1 );
	}
	label$393:;
	label$392:;
	if( ARG$1 == (char*)0ull) goto label$395;
	{
		free( (void*)ARG$1 );
	}
	label$395:;
	label$394:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$371:;
	FBSTRING* vr$39 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$39;
}

static FBSTRING* HDEFJOINZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$396:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* L$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	L$1 = vr$2;
	char* R$1;
	char* vr$3 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	R$1 = vr$3;
	if( ((int64)-(L$1 != (char*)0ull) & (int64)-(R$1 != (char*)0ull)) == 0ll) goto label$399;
	{
		FBSTRING TMP$167$2;
		__builtin_memset( &TMP$167$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$167$2, (void*)L$1, 0ll, (void*)R$1, 0ll );
		fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$9, -1ll, 0 );
	}
	goto label$398;
	label$399:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$398:;
	if( L$1 == (char*)0ull) goto label$401;
	{
		free( (void*)L$1 );
	}
	label$401:;
	label$400:;
	if( R$1 == (char*)0ull) goto label$403;
	{
		free( (void*)R$1 );
	}
	label$403:;
	label$402:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$397:;
	FBSTRING* vr$16 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$16;
}

static uint32* HDEFJOINW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$404:;
	uint32* L$1;
	uint32* vr$1 = HMACRO_GETARGW( ARGTB$1, 0ll );
	L$1 = vr$1;
	uint32* R$1;
	uint32* vr$2 = HMACRO_GETARGW( ARGTB$1, 1ll );
	R$1 = vr$2;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)0ull );
	if( ((int64)-(L$1 != (uint32*)0ull) & (int64)-(R$1 != (uint32*)0ull)) == 0ll) goto label$407;
	{
		DWSTRCONCATASSIGN( &RES$1, (uint32*)L$1 );
		DWSTRCONCATASSIGN( &RES$1, (uint32*)R$1 );
	}
	goto label$406;
	label$407:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$406:;
	fb$result$1 = *(uint32**)&RES$1;
	label$405:;
	return fb$result$1;
}

static FBSTRING* HDEFQUOTEZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$408:;
	char* ARG$1;
	char* vr$1 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	if( ARG$1 == (char*)0ull) goto label$411;
	{
		fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)"$\x22", 3ll, 0 );
		FBSTRING* vr$4 = HREPLACE( ARG$1, (char*)"\x22", (char*)"\x22\x22" );
		fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)vr$4, -1ll, 0 );
		fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)"\x22", 2ll, 0 );
	}
	goto label$410;
	label$411:;
	{
		fb_StrConcatAssign( (void*)&RES$1, -1ll, (void*)"\x22\x22", 3ll, 0 );
	}
	label$410:;
	if( ARG$1 == (char*)0ull) goto label$413;
	{
		free( (void*)ARG$1 );
	}
	label$413:;
	label$412:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$409:;
	FBSTRING* vr$12 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$12;
}

static uint32* HDEFQUOTEW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$414:;
	uint32* ARG$1;
	uint32* vr$1 = HMACRO_GETARGW( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)0ull );
	if( ARG$1 == (uint32*)0ull) goto label$417;
	{
		DWSTRCONCATASSIGN( &RES$1, (uint32*)L"$\x00000022" );
		uint32* vr$2 = HREPLACEW( ARG$1, (uint32*)L"\x00000022", (uint32*)L"\x00000022\x00000022" );
		DWSTRCONCATASSIGN( &RES$1, (uint32*)vr$2 );
		DWSTRCONCATASSIGN( &RES$1, (uint32*)L"\x00000022" );
	}
	goto label$416;
	label$417:;
	{
		DWSTRCONCATASSIGN( &RES$1, (uint32*)L"\x00000022\x00000022" );
	}
	label$416:;
	fb$result$1 = *(uint32**)&RES$1;
	label$415:;
	return fb$result$1;
}

static FBSTRING* HDEFUNQUOTEZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$418:;
	char* ARG$1;
	char* vr$1 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	if( ARG$1 == (char*)0ull) goto label$421;
	{
		int64 TMP$175$2;
		int64 TMP$177$2;
		int64 LENGTH$2;
		int64 vr$3 = fb_StrLen( (void*)ARG$1, 0ll );
		LENGTH$2 = vr$3;
		if( LENGTH$2 < 3ll) goto label$422;
		TMP$175$2 = (int64)-((((int64)-((uint64)(int64)(uint8)*ARG$1 == 36ull) & (int64)-((uint64)(int64)(uint8)*(char*)((uint8*)ARG$1 + 1ll) == 34ull)) & (int64)-((uint64)(int64)(uint8)*(char*)((uint8*)((uint8*)ARG$1 + LENGTH$2) + -1ll) == 34ull)) != 0ll);
		goto label$671;
		label$422:;
		TMP$175$2 = 0ll;
		label$671:;
		if( TMP$175$2 == 0ll) goto label$424;
		{
			FBSTRING TMP$176$3;
			__builtin_memset( &TMP$176$3, 0, 24ll );
			FBSTRING* vr$18 = fb_StrAllocTempDescZ( (char*)ARG$1 );
			FBSTRING* vr$19 = fb_StrMid( (FBSTRING*)vr$18, 3ll, LENGTH$2 + -3ll );
			fb_StrAssign( (void*)&TMP$176$3, -1ll, (void*)vr$19, -1ll, 0 );
			FBSTRING* vr$21 = HREPLACE( (char*)*(char**)&TMP$176$3, (char*)"\x22\x22", (char*)"\x22" );
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$21, -1ll, 0 );
			fb_StrDelete( (FBSTRING*)&TMP$176$3 );
		}
		goto label$423;
		label$424:;
		if( LENGTH$2 < 2ll) goto label$426;
		TMP$177$2 = (int64)-(((int64)-((uint64)(int64)(uint8)*ARG$1 == 34ull) & (int64)-((uint64)(int64)(uint8)*(char*)((uint8*)((uint8*)ARG$1 + LENGTH$2) + -1ll) == 34ull)) != 0ll);
		goto label$672;
		label$426:;
		TMP$177$2 = 0ll;
		label$672:;
		if( TMP$177$2 == 0ll) goto label$425;
		{
			FBSTRING TMP$178$3;
			__builtin_memset( &TMP$178$3, 0, 24ll );
			FBSTRING* vr$34 = fb_StrAllocTempDescZ( (char*)ARG$1 );
			FBSTRING* vr$35 = fb_StrMid( (FBSTRING*)vr$34, 2ll, LENGTH$2 + -2ll );
			fb_StrAssign( (void*)&TMP$178$3, -1ll, (void*)vr$35, -1ll, 0 );
			FBSTRING* vr$37 = HREPLACE( (char*)*(char**)&TMP$178$3, (char*)"\x22\x22", (char*)"\x22" );
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$37, -1ll, 0 );
			fb_StrDelete( (FBSTRING*)&TMP$178$3 );
		}
		goto label$423;
		label$425:;
		{
			fb_StrAssign( (void*)&RES$1, -1ll, (void*)ARG$1, 0ll, 0 );
		}
		label$423:;
	}
	label$421:;
	label$420:;
	if( ARG$1 == (char*)0ull) goto label$428;
	{
		free( (void*)ARG$1 );
	}
	label$428:;
	label$427:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$419:;
	FBSTRING* vr$45 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$45;
}

static uint32* HDEFUNQUOTEW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$429:;
	uint32* ARG$1;
	uint32* vr$1 = HMACRO_GETARGW( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	static struct $8DWSTRING RES$1;
	DWSTRASSIGN( &RES$1, (uint32*)0ull );
	if( ARG$1 == (uint32*)0ull) goto label$432;
	{
		int64 TMP$179$2;
		int64 TMP$181$2;
		int64 LENGTH$2;
		int64 vr$2 = fb_WstrLen( (uint32*)ARG$1 );
		LENGTH$2 = vr$2;
		if( LENGTH$2 < 3ll) goto label$433;
		TMP$179$2 = (int64)-((((int64)-((uint64)(int64)*ARG$1 == 36ull) & (int64)-((uint64)(int64)*(uint32*)((uint8*)ARG$1 + 4ll) == 34ull)) & (int64)-((uint64)(int64)*(uint32*)((uint8*)((uint8*)ARG$1 + (LENGTH$2 << (2ll & 63ll))) + -4ll) == 34ull)) != 0ll);
		goto label$673;
		label$433:;
		TMP$179$2 = 0ll;
		label$673:;
		if( TMP$179$2 == 0ll) goto label$435;
		{
			uint32* TMP$180$3;
			uint32* vr$17 = fb_WstrMid( (uint32*)ARG$1, 3ll, LENGTH$2 + -3ll );
			TMP$180$3 = vr$17;
			uint32* vr$18 = HREPLACEW( TMP$180$3, (uint32*)L"\x00000022\x00000022", (uint32*)L"\x00000022" );
			DWSTRASSIGN( &RES$1, (uint32*)vr$18 );
			fb_WstrDelete( (uint32*)TMP$180$3 );
		}
		goto label$434;
		label$435:;
		if( LENGTH$2 < 2ll) goto label$437;
		TMP$181$2 = (int64)-(((int64)-((uint64)(int64)*ARG$1 == 34ull) & (int64)-((uint64)(int64)*(uint32*)((uint8*)((uint8*)ARG$1 + (LENGTH$2 << (2ll & 63ll))) + -4ll) == 34ull)) != 0ll);
		goto label$674;
		label$437:;
		TMP$181$2 = 0ll;
		label$674:;
		if( TMP$181$2 == 0ll) goto label$436;
		{
			uint32* TMP$182$3;
			uint32* vr$29 = fb_WstrMid( (uint32*)ARG$1, 2ll, LENGTH$2 + -2ll );
			TMP$182$3 = vr$29;
			uint32* vr$30 = HREPLACEW( TMP$182$3, (uint32*)L"\x00000022\x00000022", (uint32*)L"\x00000022" );
			DWSTRASSIGN( &RES$1, (uint32*)vr$30 );
			fb_WstrDelete( (uint32*)TMP$182$3 );
		}
		goto label$434;
		label$436:;
		{
			DWSTRASSIGN( &RES$1, (uint32*)ARG$1 );
		}
		label$434:;
	}
	label$432:;
	label$431:;
	fb$result$1 = *(uint32**)&RES$1;
	label$430:;
	return fb$result$1;
}

static FBSTRING* HDEFEVALZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$438:;
	char* ARG$1;
	char* vr$1 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	FBSTRING RES$1;
	FBSTRING* vr$2 = HMACRO_EVALZ( ARG$1, ERRNUM$1 );
	fb_StrInit( (void*)&RES$1, -1ll, (void*)vr$2, -1ll, 0 );
	if( ARG$1 == (char*)0ull) goto label$441;
	{
		free( (void*)ARG$1 );
	}
	label$441:;
	label$440:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$439:;
	FBSTRING* vr$8 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$8;
}

static uint32* HDEFEVALW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$442:;
	uint32* ARG$1;
	uint32* vr$1 = HMACRO_GETARGW( ARGTB$1, 0ll );
	ARG$1 = vr$1;
	static struct $8DWSTRING RES$1;
	uint32* vr$2 = HMACRO_EVALW( ARG$1, ERRNUM$1 );
	DWSTRASSIGN( &RES$1, (uint32*)vr$2 );
	fb$result$1 = *(uint32**)&RES$1;
	label$443:;
	return fb$result$1;
}

static FBSTRING* HDEFIIFZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$444:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	char* CEXPR$1;
	char* vr$2 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	CEXPR$1 = vr$2;
	char* TEXPR$1;
	char* vr$3 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	TEXPR$1 = vr$3;
	char* FEXPR$1;
	char* vr$4 = HMACRO_GETARGZ( ARGTB$1, 2ll );
	FEXPR$1 = vr$4;
	if( (((int64)-(CEXPR$1 != (char*)0ull) & (int64)-(TEXPR$1 != (char*)0ull)) & (int64)-(FEXPR$1 != (char*)0ull)) == 0ll) goto label$447;
	{
		FBSTRING TMP$183$2;
		FBSTRING VARSTR$2;
		FBSTRING* vr$10 = HMACRO_EVALZ( CEXPR$1, ERRNUM$1 );
		fb_StrInit( (void*)&VARSTR$2, -1ll, (void*)vr$10, -1ll, 0 );
		boolean VALUE$2;
		boolean vr$13 = fb_VALBOOL( (FBSTRING*)&VARSTR$2 );
		VALUE$2 = vr$13;
		boolean vr$15 = fb_VALBOOL( (FBSTRING*)&VARSTR$2 );
		if( vr$15 == (boolean)0ll) goto label$448;
		fb_StrInit( (void*)&TMP$183$2, -1ll, (void*)TEXPR$1, 0ll, 0 );
		goto label$675;
		label$448:;
		fb_StrInit( (void*)&TMP$183$2, -1ll, (void*)FEXPR$1, 0ll, 0 );
		label$675:;
		fb_StrAssign( (void*)&RES$1, -1ll, (void*)&TMP$183$2, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&TMP$183$2 );
		fb_StrDelete( (FBSTRING*)&VARSTR$2 );
	}
	goto label$446;
	label$447:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$446:;
	if( FEXPR$1 == (char*)0ull) goto label$450;
	{
		free( (void*)FEXPR$1 );
	}
	label$450:;
	label$449:;
	if( TEXPR$1 == (char*)0ull) goto label$452;
	{
		free( (void*)TEXPR$1 );
	}
	label$452:;
	label$451:;
	if( CEXPR$1 == (char*)0ull) goto label$454;
	{
		free( (void*)CEXPR$1 );
	}
	label$454:;
	label$453:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$445:;
	FBSTRING* vr$27 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$27;
}

static uint32* HDEFIIFW_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	uint32* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$455:;
	static struct $8DWSTRING RES$1;
	static struct $8DWSTRING WVARSTR$1;
	uint32* CEXPR$1;
	uint32* vr$1 = HMACRO_GETARGW( ARGTB$1, 0ll );
	CEXPR$1 = vr$1;
	uint32* TEXPR$1;
	uint32* vr$2 = HMACRO_GETARGW( ARGTB$1, 1ll );
	TEXPR$1 = vr$2;
	uint32* FEXPR$1;
	uint32* vr$3 = HMACRO_GETARGW( ARGTB$1, 2ll );
	FEXPR$1 = vr$3;
	if( (((int64)-(CEXPR$1 != (uint32*)0ull) & (int64)-(TEXPR$1 != (uint32*)0ull)) & (int64)-(FEXPR$1 != (uint32*)0ull)) == 0ll) goto label$458;
	{
		uint32* TMP$184$2;
		int32 VALUE$2;
		VALUE$2 = 0;
		FBSTRING VARSTR$2;
		__builtin_memset( &VARSTR$2, 0, 24ll );
		uint32* vr$10 = HMACRO_EVALW( CEXPR$1, ERRNUM$1 );
		DWSTRASSIGN( &WVARSTR$1, (uint32*)vr$10 );
		FBSTRING* vr$11 = fb_ULongintToStr( *(uint64*)&WVARSTR$1 );
		fb_StrAssign( (void*)&VARSTR$2, -1ll, (void*)vr$11, -1ll, 0 );
		boolean vr$14 = fb_VALBOOL( (FBSTRING*)&VARSTR$2 );
		if( vr$14 == (boolean)0ll) goto label$459;
		int64 vr$15 = fb_WstrLen( (uint32*)TEXPR$1 );
		uint32* vr$16 = fb_WstrAlloc( vr$15 );
		TMP$184$2 = vr$16;
		uint32* vr$17 = fb_WstrAssign( TMP$184$2, 0ll, (uint32*)TEXPR$1 );
		goto label$676;
		label$459:;
		int64 vr$18 = fb_WstrLen( (uint32*)FEXPR$1 );
		uint32* vr$19 = fb_WstrAlloc( vr$18 );
		TMP$184$2 = vr$19;
		uint32* vr$20 = fb_WstrAssign( TMP$184$2, 0ll, (uint32*)FEXPR$1 );
		label$676:;
		DWSTRASSIGN( &RES$1, (uint32*)TMP$184$2 );
		fb_WstrDelete( (uint32*)TMP$184$2 );
		fb_StrDelete( (FBSTRING*)&VARSTR$2 );
	}
	goto label$457;
	label$458:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$457:;
	fb$result$1 = *(uint32**)&RES$1;
	label$456:;
	return fb$result$1;
}

static FBSTRING* HDEFQUERYSYMZ_CB( struct $11LEXPP_ARGTB* ARGTB$1, int64* ERRNUM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$460:;
	FBSTRING RES$1;
	fb_StrInit( (void*)&RES$1, -1ll, (void*)"", 1ll, 0 );
	if( *(int64*)((uint8*)&ENV$ + 1296ll) < 16ll) goto label$463;
	{
		*ERRNUM$1 = 27ll;
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&RES$1 );
		goto label$461;
	}
	label$463:;
	label$462:;
	char* WEXPR$1;
	char* vr$6 = HMACRO_GETARGZ( ARGTB$1, 0ll );
	WEXPR$1 = vr$6;
	char* SEXPR$1;
	char* vr$7 = HMACRO_GETARGZ( ARGTB$1, 1ll );
	SEXPR$1 = vr$7;
	if( ((int64)-(WEXPR$1 != (char*)0ull) & (int64)-(SEXPR$1 != (char*)0ull)) == 0ll) goto label$465;
	{
		FBSTRING WHATSTR$2;
		FBSTRING* vr$11 = HMACRO_EVALZ( WEXPR$1, ERRNUM$1 );
		fb_StrInit( (void*)&WHATSTR$2, -1ll, (void*)vr$11, -1ll, 0 );
		int32 WHATVALUE$2;
		int32 vr$14 = fb_VALINT( (FBSTRING*)&WHATSTR$2 );
		WHATVALUE$2 = vr$14;
		int64 vr$17 = HSTR2LONG( &WHATSTR$2, &WHATVALUE$2 );
		if( vr$17 == 0ll) goto label$467;
		{
			$11FB_DATATYPE DTYPE$3;
			DTYPE$3 = 2147483648ll;
			int64 IS_FIXLENSTR$3;
			__builtin_memset( &IS_FIXLENSTR$3, 0, 8ll );
			int64 RETRY$3;
			RETRY$3 = 0ll;
			int64 LGT$3;
			__builtin_memset( &LGT$3, 0, 8ll );
			struct $8FBSYMBOL* SYM$3;
			SYM$3 = (struct $8FBSYMBOL*)0ull;
			struct $8FBSYMBOL* SUBTYPE$3;
			SUBTYPE$3 = (struct $8FBSYMBOL*)0ull;
			int32 QUERYVALUE$3;
			QUERYVALUE$3 = (int32)((int64)WHATVALUE$2 & 255ll);
			int32 FILTERVALUE$3;
			FILTERVALUE$3 = (int32)((int64)WHATVALUE$2 & 65280ll);
			$9FB_ERRMSG ERRMSG$3;
			ERRMSG$3 = 0ll;
			LEXPUSHCTX(  );
			LEXINIT( 2ll );
			*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + 1ll;
			HARGINSERTARGA( SEXPR$1 );
			HARGAPPENDLFCHAR(  );
			if( (int64)FILTERVALUE$3 != 0ll) goto label$469;
			{
				{
					if( (int64)QUERYVALUE$3 == 3ll) goto label$472;
					label$473:;
					if( (int64)QUERYVALUE$3 == 4ll) goto label$472;
					label$474:;
					if( (int64)QUERYVALUE$3 == 5ll) goto label$472;
					label$475:;
					if( (int64)QUERYVALUE$3 == 6ll) goto label$472;
					label$476:;
					if( (int64)QUERYVALUE$3 != 7ll) goto label$471;
					label$472:;
					{
						FILTERVALUE$3 = (int32)((int64)FILTERVALUE$3 | 256ll);
					}
					goto label$470;
					label$471:;
					{
						FILTERVALUE$3 = (int32)((int64)FILTERVALUE$3 | 768ll);
					}
					label$477:;
					label$470:;
				}
			}
			label$469:;
			label$468:;
			if( ((int64)FILTERVALUE$3 & 256ll) == 0ll) goto label$479;
			{
				int64 TMP$188$4;
				{
					int64 TMP$185$5;
					int64 vr$43 = LEXGETCLASS( 0ll );
					TMP$185$5 = vr$43;
					if( TMP$185$5 == 0ll) goto label$482;
					label$483:;
					if( TMP$185$5 == 1ll) goto label$482;
					label$484:;
					if( TMP$185$5 == 2ll) goto label$482;
					label$485:;
					if( TMP$185$5 != 5ll) goto label$481;
					label$482:;
					{
						struct $8FBSYMBOL* TMP$186$6;
						TMP$186$6 = (struct $8FBSYMBOL*)0ull;
						struct $8FBSYMBOL* vr$45 = CIDENTIFIERORUDTMEMBER( &TMP$186$6, (struct $10FBSYMCHAIN*)0ull );
						SYM$3 = vr$45;
						if( SYM$3 != (struct $8FBSYMBOL*)0ull) goto label$487;
						{
							RETRY$3 = -1ll;
						}
						label$487:;
						label$486:;
					}
					label$481:;
					label$480:;
				}
				if( SYM$3 == (struct $8FBSYMBOL*)0ull) goto label$489;
				{
					{
						$12FB_SYMBCLASS TMP$187$6;
						TMP$187$6 = *($12FB_SYMBCLASS*)SYM$3;
						if( TMP$187$6 != 6ll) goto label$491;
						label$492:;
						{
							DTYPE$3 = *($11FB_DATATYPE*)((uint8*)SYM$3 + 56ll);
							if( DTYPE$3 != 2147483648ll) goto label$494;
							{
								{
									if( (int64)QUERYVALUE$3 == 0ll) goto label$497;
									label$498:;
									if( (int64)QUERYVALUE$3 != 7ll) goto label$496;
									label$497:;
									{
										LEXSKIPTOKEN( 0ll );
									}
									goto label$495;
									label$496:;
									{
										SYM$3 = (struct $8FBSYMBOL*)0ull;
										RETRY$3 = -1ll;
									}
									label$499:;
									label$495:;
								}
							}
							goto label$493;
							label$494:;
							{
								LEXSKIPTOKEN( 0ll );
							}
							label$493:;
						}
						goto label$490;
						label$491:;
						if( TMP$187$6 != 10ll) goto label$500;
						label$501:;
						{
							LEXSKIPTOKEN( 0ll );
							DTYPE$3 = *($11FB_DATATYPE*)((uint8*)SYM$3 + 56ll);
							SUBTYPE$3 = SYM$3;
							int64 vr$51 = LEXGETTOKEN( 0ll );
							if( vr$51 != 46ll) goto label$503;
							{
								CUDTTYPEMEMBER( (int64*)&DTYPE$3, &SUBTYPE$3, &LGT$3, &IS_FIXLENSTR$3, &SYM$3 );
							}
							label$503:;
							label$502:;
						}
						goto label$490;
						label$500:;
						{
							LEXSKIPTOKEN( 0ll );
							DTYPE$3 = *($11FB_DATATYPE*)((uint8*)SYM$3 + 56ll);
							SUBTYPE$3 = *(struct $8FBSYMBOL**)((uint8*)SYM$3 + 64ll);
						}
						label$504:;
						label$490:;
					}
				}
				label$489:;
				label$488:;
				int64 vr$59 = LEXGETTOKEN( 0ll );
				if( vr$59 == 257ll) goto label$505;
				int64 vr$60 = LEXGETTOKEN( 0ll );
				TMP$188$4 = (int64)-(vr$60 == 256ll);
				goto label$677;
				label$505:;
				TMP$188$4 = -1ll;
				label$677:;
				if( ~TMP$188$4 == 0ll) goto label$507;
				{
					RETRY$3 = -1ll;
				}
				label$507:;
				label$506:;
				if( RETRY$3 == 0ll) goto label$509;
				{
					SYM$3 = (struct $8FBSYMBOL*)0ull;
					LEXPOPCTX(  );
					LEXPUSHCTX(  );
					LEXINIT( 2ll );
					HARGINSERTARGA( SEXPR$1 );
					HARGAPPENDLFCHAR(  );
				}
				label$509:;
				label$508:;
			}
			label$479:;
			label$478:;
			if( ((int64)FILTERVALUE$3 & 512ll) == 0ll) goto label$511;
			{
				if( SYM$3 != (struct $8FBSYMBOL*)0ull) goto label$513;
				{
					CTYPEOF( (int64*)&DTYPE$3, &SUBTYPE$3, &LGT$3, &IS_FIXLENSTR$3, &SYM$3 );
				}
				label$513:;
				label$512:;
			}
			label$511:;
			label$510:;
			{
				if( (int64)QUERYVALUE$3 != 0ll) goto label$515;
				label$516:;
				{
					if( SYM$3 == (struct $8FBSYMBOL*)0ull) goto label$518;
					{
						FBSTRING* vr$72 = fb_LongintToStr( *(int64*)SYM$3 );
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$72, -1ll, 0 );
					}
					goto label$517;
					label$518:;
					if( SUBTYPE$3 == (struct $8FBSYMBOL*)0ull) goto label$519;
					{
						FBSTRING* vr$75 = fb_LongintToStr( *(int64*)SUBTYPE$3 );
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$75, -1ll, 0 );
					}
					goto label$517;
					label$519:;
					{
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)"0", 2ll, 0 );
					}
					label$517:;
				}
				goto label$514;
				label$515:;
				if( (int64)QUERYVALUE$3 != 1ll) goto label$520;
				label$521:;
				{
					FBSTRING* vr$79 = fb_LongintToStr( DTYPE$3 );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$79, -1ll, 0 );
				}
				goto label$514;
				label$520:;
				if( (int64)QUERYVALUE$3 != 2ll) goto label$522;
				label$523:;
				{
					int64 TMP$189$5;
					if( (DTYPE$3 & 480ll) == 0ll) goto label$524;
					TMP$189$5 = 24ll;
					goto label$678;
					label$524:;
					TMP$189$5 = DTYPE$3 & 31ll;
					label$678:;
					FBSTRING* vr$85 = fb_LongintToStr( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$189$5 * 56ll)) );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$85, -1ll, 0 );
				}
				goto label$514;
				label$522:;
				if( (int64)QUERYVALUE$3 == 3ll) goto label$526;
				label$527:;
				if( (int64)QUERYVALUE$3 != 4ll) goto label$525;
				label$526:;
				{
					FBSTRING* vr$89 = SYMBTYPETOSTR( DTYPE$3, SUBTYPE$3, LGT$3, IS_FIXLENSTR$3 );
					FBSTRING* vr$90 = fb_StrUcase2( (FBSTRING*)vr$89, 0 );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$90, -1ll, 0 );
					if( (int64)QUERYVALUE$3 != 4ll) goto label$529;
					{
						HREPLACECHAR( (char*)*(char**)&RES$1, 32ll, 95ll );
						HREPLACECHAR( (char*)*(char**)&RES$1, 46ll, 95ll );
						HREPLACECHAR( (char*)*(char**)&RES$1, 40ll, 95ll );
						HREPLACECHAR( (char*)*(char**)&RES$1, 41ll, 95ll );
						HREPLACECHAR( (char*)*(char**)&RES$1, 42ll, 95ll );
					}
					label$529:;
					label$528:;
				}
				goto label$514;
				label$525:;
				if( (int64)QUERYVALUE$3 != 5ll) goto label$530;
				label$531:;
				{
					if( SYM$3 == (struct $8FBSYMBOL*)0ull) goto label$533;
					{
						SYMBMANGLETYPE( &RES$1, DTYPE$3, SYM$3, 0ll );
						SYMBMANGLERESETABBREV(  );
					}
					goto label$532;
					label$533:;
					if( SUBTYPE$3 == (struct $8FBSYMBOL*)0ull) goto label$534;
					{
						SYMBMANGLETYPE( &RES$1, DTYPE$3, SUBTYPE$3, 0ll );
						SYMBMANGLERESETABBREV(  );
					}
					goto label$532;
					label$534:;
					{
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)"0", 2ll, 0 );
					}
					label$532:;
				}
				goto label$514;
				label$530:;
				if( (int64)QUERYVALUE$3 != 6ll) goto label$535;
				label$536:;
				{
					if( SYM$3 == (struct $8FBSYMBOL*)0ull) goto label$538;
					{
						char* vr$98 = SYMBGETMANGLEDNAME( SYM$3 );
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$98, 0ll, 0 );
					}
					goto label$537;
					label$538:;
					if( SUBTYPE$3 == (struct $8FBSYMBOL*)0ull) goto label$539;
					{
						char* vr$100 = SYMBGETMANGLEDNAME( SUBTYPE$3 );
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$100, 0ll, 0 );
					}
					goto label$537;
					label$539:;
					{
						fb_StrAssign( (void*)&RES$1, -1ll, (void*)"0", 2ll, 0 );
					}
					label$537:;
				}
				goto label$514;
				label$535:;
				if( (int64)QUERYVALUE$3 != 7ll) goto label$540;
				label$541:;
				{
					FBSTRING* vr$105 = fb_LongintToStr( (int64)-(SYM$3 != (struct $8FBSYMBOL*)0ull) );
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)vr$105, -1ll, 0 );
				}
				goto label$514;
				label$540:;
				{
					*ERRNUM$1 = 17ll;
					fb_StrAssign( (void*)&RES$1, -1ll, (void*)"-1", 3ll, 0 );
				}
				label$542:;
				label$514:;
			}
			if( *ERRNUM$1 == 0ll) goto label$544;
			{
				ERRREPORT( *ERRNUM$1, 0ll, (char*)0ull );
				HSKIPUNTIL( 257ll, -1ll, 0ll, 0ll );
			}
			label$544:;
			label$543:;
			*(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16768ll) + -1ll;
			LEXPOPCTX(  );
		}
		goto label$466;
		label$467:;
		{
			*ERRNUM$1 = 17ll;
		}
		label$466:;
		fb_StrDelete( (FBSTRING*)&WHATSTR$2 );
	}
	goto label$464;
	label$465:;
	{
		*ERRNUM$1 = 1ll;
	}
	label$464:;
	if( WEXPR$1 == (char*)0ull) goto label$546;
	{
		free( (void*)WEXPR$1 );
	}
	label$546:;
	label$545:;
	if( SEXPR$1 == (char*)0ull) goto label$548;
	{
		free( (void*)SEXPR$1 );
	}
	label$548:;
	label$547:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&RES$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&RES$1 );
	label$461:;
	FBSTRING* vr$121 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$121;
}

static void HRESETDEFHASH( void )
{
	label$604:;
	int64 I$1;
	__builtin_memset( &I$1, 0, 8ll );
	{
		I$1 = 0ll;
		int64 TMP$285$2;
		TMP$285$2 = *(int64*)((uint8*)&SYMB$ + 197496ll) + -1ll;
		goto label$606;
		label$609:;
		{
			HASHDEL( (struct $5THASH*)((uint8*)&SYMB$ + 197504ll), *(struct $8HASHITEM**)((uint8*)((uint8*)((uint8*)&SYMB$ + 197344ll) + (I$1 << (4ll & 63ll))) + 184ll), *(uint64*)((uint8*)((uint8*)((uint8*)&SYMB$ + 197344ll) + (I$1 << (4ll & 63ll))) + 192ll) );
		}
		label$607:;
		I$1 = I$1 + 1ll;
		label$606:;
		if( I$1 <= TMP$285$2) goto label$609;
		label$608:;
	}
	*(int64*)((uint8*)&SYMB$ + 197496ll) = 0ll;
	label$605:;
}

static void HDELDEFINEPARAMS( struct $8FBSYMBOL* S$1 )
{
	label$641:;
	struct $11FB_DEFPARAM* PARAM$1;
	__builtin_memset( &PARAM$1, 0, 8ll );
	struct $11FB_DEFPARAM* NXT$1;
	__builtin_memset( &NXT$1, 0, 8ll );
	PARAM$1 = *(struct $11FB_DEFPARAM**)((uint8*)S$1 + 104ll);
	label$643:;
	if( PARAM$1 == (struct $11FB_DEFPARAM*)0ull) goto label$644;
	{
		NXT$1 = *(struct $11FB_DEFPARAM**)((uint8*)PARAM$1 + 16ll);
		if( *(char**)PARAM$1 == (char*)0ull) goto label$646;
		{
			free( *(void**)PARAM$1 );
		}
		label$646:;
		label$645:;
		LISTDELNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197344ll), (void*)PARAM$1 );
		PARAM$1 = NXT$1;
	}
	goto label$643;
	label$644:;
	label$642:;
}

static void HDELDEFINETOKENS( struct $8FBSYMBOL* S$1 )
{
	label$647:;
	struct $9FB_DEFTOK* TOK$1;
	__builtin_memset( &TOK$1, 0, 8ll );
	struct $9FB_DEFTOK* NXT$1;
	__builtin_memset( &NXT$1, 0, 8ll );
	TOK$1 = *(struct $9FB_DEFTOK**)((uint8*)S$1 + 112ll);
	label$649:;
	if( TOK$1 == (struct $9FB_DEFTOK*)0ull) goto label$650;
	{
		NXT$1 = *(struct $9FB_DEFTOK**)((uint8*)TOK$1 + 24ll);
		SYMBDELDEFINETOK( TOK$1 );
		TOK$1 = NXT$1;
	}
	goto label$649;
	label$650:;
	label$648:;
}
