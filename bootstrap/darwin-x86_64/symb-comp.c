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
typedef FBSTRING* (*tmp$29)( void*, int64* );
typedef uint32* (*tmp$30)( void*, int64* );
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
struct $18SYMBDEFAULTMEMBERS {
	struct $8FBSYMBOL* DEFCTOR;
	struct $8FBSYMBOL* DTOR1;
	struct $8FBSYMBOL* DTOR0;
	struct $8FBSYMBOL* COPYCTOR;
	struct $8FBSYMBOL* COPYCTORCONST;
	struct $8FBSYMBOL* COPYLETOPCONST;
};
__FB_STATIC_ASSERT( sizeof( struct $18SYMBDEFAULTMEMBERS ) == 48 );
typedef int64 $11AST_OPFLAGS;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
struct $11FB_SYMBNEST {
	struct $8FBSYMBOL* SYM;
	struct $10FBSYMBOLTB* SYMTB;
	struct $8FBHASHTB* HASHTB;
	struct $8FBSYMBOL* NS;
};
__FB_STATIC_ASSERT( sizeof( struct $11FB_SYMBNEST ) == 32 );
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $8FBARRAY1I10FBARRAYDIME {
	struct $10FBARRAYDIM* DATA;
	struct $10FBARRAYDIM* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1I10FBARRAYDIME ) == 72 );
struct $7FBARRAYI10FBARRAYDIME {
	struct $10FBARRAYDIM* DATA;
	struct $10FBARRAYDIM* PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $7FBARRAYI10FBARRAYDIME ) == 240 );
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
int32 fb_StrCompare( void*, int64, void*, int64 );
static void fb_ctor__symbzcomp( void ) __attribute__(( constructor ));
void* XCALLOCATE( int32 );
void* LISTNEWNODE( struct $5TLIST* );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
void ERRREPORT( int64, int64, char* );
int64 STACKNEW( struct $6TSTACK*, int64, int64, int64 );
int64 STACKFREE( struct $6TSTACK* );
void* STACKPUSH( struct $6TSTACK* );
void STACKPOP( struct $6TSTACK* );
void* STACKGETTOS( struct $6TSTACK* );
void ASTDELNODE( struct $7ASTNODE* );
void ASTPROCBEGIN( struct $8FBSYMBOL*, int64 );
int64 ASTPROCEND( int64 );
struct $7ASTNODE* ASTADD( struct $7ASTNODE* );
struct $7ASTNODE* ASTBUILDBRANCH( struct $7ASTNODE*, struct $8FBSYMBOL*, int64, int64 );
struct $7ASTNODE* ASTNEWNOP( void );
struct $7ASTNODE* ASTNEWASSIGN( struct $7ASTNODE*, struct $7ASTNODE*, $9AST_OPOPT );
typedef int64 $11AST_CONVOPT;
struct $7ASTNODE* ASTNEWCONV( int64, struct $8FBSYMBOL*, struct $7ASTNODE*, $11AST_CONVOPT, int64* );
struct $7ASTNODE* ASTNEWBOP( int64, struct $7ASTNODE*, struct $7ASTNODE*, struct $8FBSYMBOL*, $9AST_OPOPT );
struct $7ASTNODE* ASTNEWCONSTI( int64, int64, struct $8FBSYMBOL* );
struct $7ASTNODE* ASTNEWVAR( struct $8FBSYMBOL*, int64, int64, struct $8FBSYMBOL* );
struct $7ASTNODE* ASTNEWDEREF( struct $7ASTNODE*, int64, struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* ASTNEWADDROF( struct $7ASTNODE* );
struct $7ASTNODE* ASTNEWBRANCH( int64, struct $8FBSYMBOL*, struct $7ASTNODE* );
struct $7ASTNODE* ASTNEWLABEL( struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* ASTNEWMEM( int64, struct $7ASTNODE*, struct $7ASTNODE*, int64, int64 );
struct $7ASTNODE* ASTTYPEINIBEGIN( int64, struct $8FBSYMBOL*, int64, int64 );
void ASTTYPEINIEND( struct $7ASTNODE*, int64 );
struct $7ASTNODE* ASTTYPEINIADDASSIGN( struct $7ASTNODE*, struct $7ASTNODE*, struct $8FBSYMBOL*, int64, struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* ASTTYPEINISCOPEBEGIN( struct $7ASTNODE*, struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* ASTTYPEINISCOPEEND( struct $7ASTNODE*, struct $8FBSYMBOL* );
void ASTTYPEINICOPYELEMENTS( struct $7ASTNODE*, struct $7ASTNODE*, int64 );
void ASTTYPEINIREPLACEELEMENT( struct $7ASTNODE*, int64, struct $7ASTNODE* );
struct $7ASTNODE* ASTBUILDVARDEREF( struct $8FBSYMBOL* );
struct $7ASTNODE* ASTBUILDVARINC( struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( struct $8FBSYMBOL*, struct $7ASTNODE*, int64 );
struct $7ASTNODE* _Z19ASTBUILDDEREFADDROFP7ASTNODExlP8FBSYMBOLS2_( struct $7ASTNODE*, int64, int64, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
struct $7ASTNODE* ASTBUILDVARFIELD( struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
struct $7ASTNODE* ASTBUILDFORBEGIN( struct $7ASTNODE*, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64, int64 );
struct $7ASTNODE* ASTBUILDFOREND( struct $7ASTNODE*, struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $7ASTNODE* );
struct $7ASTNODE* ASTBUILDPROCADDROF( struct $8FBSYMBOL* );
void SYMBPROCCHECKOVERRIDDEN( struct $8FBSYMBOL*, int64 );
int64 SYMBPROCGETVTABLEINDEX( struct $8FBSYMBOL* );
typedef int64 $10FB_SYMBOPT;
struct $8FBSYMBOL* SYMBADDLABEL( char*, $10FB_SYMBOPT );
struct $8FBSYMBOL* SYMBADDVAR( char*, char*, int64, struct $8FBSYMBOL*, int64, int64, struct $7FBARRAYI10FBARRAYDIME*, $13FB_SYMBATTRIB, $10FB_SYMBOPT );
struct $8FBSYMBOL* SYMBADDTEMPVAR( int64, struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBSTRUCTBEGIN( struct $10FBSYMBOLTB*, struct $8FBHASHTB*, struct $8FBSYMBOL*, char*, char*, int64, int64, int64, $13FB_SYMBATTRIB, int64 );
struct $8FBSYMBOL* SYMBADDFIELD( struct $8FBSYMBOL*, char*, int64, struct $7FBARRAYI10FBARRAYDIME*, int64, struct $8FBSYMBOL*, int64, int64, $13FB_SYMBATTRIB );
void SYMBSTRUCTEND( struct $8FBSYMBOL*, int64 );
struct $8FBSYMBOL* SYMBADDPROCPARAM( struct $8FBSYMBOL*, char*, int64, struct $8FBSYMBOL*, int64, int64, $13FB_SYMBATTRIB, $13FB_PROCATTRIB );
struct $8FBSYMBOL* SYMBADDOPERATOR( struct $8FBSYMBOL*, $6AST_OP, char*, int64, struct $8FBSYMBOL*, $13FB_SYMBATTRIB, $13FB_PROCATTRIB, int64, $10FB_SYMBOPT );
struct $8FBSYMBOL* SYMBADDCTOR( struct $8FBSYMBOL*, char*, $13FB_SYMBATTRIB, $13FB_PROCATTRIB, int64, $10FB_SYMBOPT );
struct $8FBSYMBOL* SYMBPREADDPROC( char* );
void SYMBADDPROCINSTANCEPARAM( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBALLOCSTRCONST( char*, int64 );
int64 SYMBGETREALSIZE( struct $8FBSYMBOL* );
void SYMBHASHLISTADD( struct $8FBHASHTB* );
void SYMBHASHLISTADDBEFORE( struct $8FBHASHTB*, struct $8FBHASHTB* );
void SYMBHASHLISTDEL( struct $8FBHASHTB* );
void SYMBNESTBEGIN( struct $8FBSYMBOL*, int64 );
void SYMBNESTEND( int64 );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
void SYMBUDTALLOCEXT( struct $8FBSYMBOL* );
void SYMBIMPLEMENTDEFAULTMEMBERS( struct $18SYMBDEFAULTMEMBERS*, struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBGETCOMPCTORHEAD( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBGETCOMPDEFCTOR( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBGETCOMPDTOR1( struct $8FBSYMBOL* );
void SYMBCHECKCOMPLETOP( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
int64 OPTIMIZEPUREABSTRACTTYPES( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETFIRSTFIELD( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETNEXTINITABLEFIELD( struct $8FBSYMBOL* );
void SYMBHASHLISTINSERTNAMESPACE( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
void SYMBHASHLISTREMOVENAMESPACE( struct $8FBSYMBOL* );
struct $7ASTNODE* RTLARRAYREDIMTO( struct $7ASTNODE*, struct $7ASTNODE*, int64, struct $8FBSYMBOL* );
static struct $8FBSYMBOL* SYMBGETCOMPCOPYCTOR( struct $8FBSYMBOL* );
static struct $8FBSYMBOL* HDECLAREPROC( struct $8FBSYMBOL*, $6AST_OP, int64, $13FB_SYMBATTRIB, $13FB_PROCATTRIB, $11FB_FUNCMODE );
static void HSETMINIMUMVTABLESIZE( struct $8FBSYMBOL* );
static void HREBUILDRTTI( struct $8FBSYMBOL* );
static int64 HBUILDRTTI( struct $8FBSYMBOL* );
static void HBUILDVTABLE( struct $8FBSYMBOL* );
static void HPROCBEGIN( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void HPROCEND( void );
static void HADDCTORBODY( struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
static void HASSIGNDYNAMICARRAY( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void HASSIGNLIST( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static struct $8FBSYMBOL* HCOPYUNIONFIELDS( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void HADDLETOPBODY( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static int64 HHASBYREFSELFPARAM( struct $8FBSYMBOL*, int64, struct $8FBSYMBOL* );
static void HINSERTNESTED( struct $8FBSYMBOL*, struct $8FBHASHTB*, struct $8FBSYMBOL* );
static void HREMOVENESTED( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void HINSERTIMPORTED( struct $8FBSYMBOL* );
static void HREMOVEIMPORTED( struct $8FBSYMBOL* );
void SYMBCOMPDELFROMIMPORTLIST( struct $8FBSYMBOL* );
void SYMBCOMPDELFROMEXPORTLIST( struct $8FBSYMBOL* );
extern struct $10AST_OPINFO AST_OPTB$[122];
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

void SYMBCOMPINIT( void )
{
	label$10:;
	{
		int64 I$2;
		I$2 = 0ll;
		label$15:;
		{
			*(struct $8FBSYMBOL**)((uint8*)((uint8*)&SYMB$ + (I$2 << (3ll & 63ll))) + 198208ll) = (struct $8FBSYMBOL*)0ull;
		}
		label$13:;
		I$2 = I$2 + 1ll;
		label$12:;
		if( I$2 <= 121ll) goto label$15;
		label$14:;
	}
	STACKNEW( (struct $6TSTACK*)((uint8*)&SYMB$ + 197048ll), 16ll, 32ll, 0ll );
	label$11:;
}

void SYMBCOMPEND( void )
{
	label$16:;
	STACKFREE( (struct $6TSTACK*)((uint8*)&SYMB$ + 197048ll) );
	label$17:;
}

void SYMBUDTALLOCEXT( struct $8FBSYMBOL* UDT$1 )
{
	label$18:;
	if( *(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) != (struct $12FB_STRUCTEXT*)0ull) goto label$21;
	{
		void* vr$1 = XCALLOCATE( 320 );
		*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) = (struct $12FB_STRUCTEXT*)vr$1;
	}
	label$21:;
	label$20:;
	label$19:;
}

void SYMBUDTDECLAREDEFAULTMEMBERS( struct $18SYMBDEFAULTMEMBERS* DEFAULT$1, struct $8FBSYMBOL* UDT$1, $11FB_FUNCMODE MODE$1 )
{
	label$112:;
	int64 MISSING_BASE_DEFCTOR$1;
	if( *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) == (struct $8FBSYMBOL*)0ull) goto label$115;
	{
		struct $8FBSYMBOL* vr$3 = SYMBGETCOMPDEFCTOR( *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) );
		struct $8FBSYMBOL* vr$7 = SYMBGETCOMPCTORHEAD( *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) );
		MISSING_BASE_DEFCTOR$1 = (int64)-(vr$3 == (struct $8FBSYMBOL*)0ull) & (int64)-(vr$7 != (struct $8FBSYMBOL*)0ull);
	}
	goto label$114;
	label$115:;
	{
		MISSING_BASE_DEFCTOR$1 = 0ll;
	}
	label$114:;
	*(struct $8FBSYMBOL**)DEFAULT$1 = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 24ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 32ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 40ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 8ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 16ll) = (struct $8FBSYMBOL*)0ull;
	struct $8FBSYMBOL* vr$25 = SYMBGETCOMPCTORHEAD( UDT$1 );
	if( (((int64)-(((int64)*(int32*)((uint8*)UDT$1 + 208ll) & 8ll) != 0ll) | (int64)-(((int64)*(int32*)((uint8*)UDT$1 + 208ll) & 4096ll) != 0ll)) & (int64)-(vr$25 == (struct $8FBSYMBOL*)0ull)) == 0ll) goto label$117;
	{
		if( MISSING_BASE_DEFCTOR$1 == 0ll) goto label$119;
		{
			ERRREPORT( 186ll, 0ll, (char*)0ull );
		}
		goto label$118;
		label$119:;
		{
			struct $8FBSYMBOL* vr$28 = HDECLAREPROC( UDT$1, -1ll, 2147483648ll, 8388608ll, 5ll, MODE$1 );
			*(struct $8FBSYMBOL**)DEFAULT$1 = vr$28;
		}
		label$118:;
	}
	label$117:;
	label$116:;
	if( ((int64)*(int32*)((uint8*)UDT$1 + 208ll) & 8ll) == 0ll) goto label$121;
	{
		SYMBUDTALLOCEXT( UDT$1 );
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 56ll) != (struct $8FBSYMBOL*)0ull) goto label$123;
		{
			struct $8FBSYMBOL* vr$35 = HDECLAREPROC( UDT$1, 0ll, 532ll, 8388608ll, 17ll, MODE$1 );
			*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 40ll) = vr$35;
			SYMBPROCCHECKOVERRIDDEN( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 40ll), -1ll );
		}
		label$123:;
		label$122:;
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 24ll) != (struct $8FBSYMBOL*)0ull) goto label$125;
		{
			if( MISSING_BASE_DEFCTOR$1 == 0ll) goto label$127;
			{
				ERRREPORT( 188ll, 0ll, (char*)0ull );
			}
			goto label$126;
			label$127:;
			{
				struct $8FBSYMBOL* vr$40 = HDECLAREPROC( UDT$1, -1ll, 532ll, 8388608ll, 5ll, MODE$1 );
				*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 32ll) = vr$40;
			}
			label$126:;
		}
		label$125:;
		label$124:;
		if( ((int64)-(*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 48ll) != (struct $8FBSYMBOL*)0ull) & (int64)-(*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 16ll) == (struct $8FBSYMBOL*)0ull)) == 0ll) goto label$129;
		{
			if( MISSING_BASE_DEFCTOR$1 == 0ll) goto label$131;
			{
				ERRREPORT( 187ll, 0ll, (char*)0ull );
			}
			goto label$130;
			label$131:;
			{
				struct $8FBSYMBOL* vr$49 = HDECLAREPROC( UDT$1, -1ll, 20ll, 8388608ll, 5ll, MODE$1 );
				*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 24ll) = vr$49;
			}
			label$130:;
		}
		label$129:;
		label$128:;
	}
	label$121:;
	label$120:;
	if( ((int64)*(int32*)((uint8*)UDT$1 + 208ll) & 16ll) == 0ll) goto label$133;
	{
		SYMBUDTALLOCEXT( UDT$1 );
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 32ll) != (struct $8FBSYMBOL*)0ull) goto label$135;
		{
			struct $8FBSYMBOL* vr$56 = HDECLAREPROC( UDT$1, -1ll, 2147483648ll, 8388608ll, 8ll, MODE$1 );
			*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 8ll) = vr$56;
			if( (int64)*(int16*)((uint8*)UDT$1 + 74ll) != 4ll) goto label$137;
			{
				struct $8FBSYMBOL* vr$60 = HDECLAREPROC( UDT$1, -1ll, 2147483648ll, 8388608ll, 4096ll, MODE$1 );
				*(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 16ll) = vr$60;
			}
			label$137:;
			label$136:;
			SYMBPROCCHECKOVERRIDDEN( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 8ll), -1ll );
		}
		label$135:;
		label$134:;
	}
	label$133:;
	label$132:;
	label$113:;
}

void SYMBIMPLEMENTDEFAULTMEMBERS( struct $18SYMBDEFAULTMEMBERS* DEFAULT$1, struct $8FBSYMBOL* UDT$1 )
{
	label$138:;
	if( *(struct $8FBSYMBOL**)DEFAULT$1 == (struct $8FBSYMBOL*)0ull) goto label$141;
	{
		HADDCTORBODY( UDT$1, *(struct $8FBSYMBOL**)DEFAULT$1, 0ll );
	}
	label$141:;
	label$140:;
	if( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 40ll) == (struct $8FBSYMBOL*)0ull) goto label$143;
	{
		HADDLETOPBODY( UDT$1, *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 40ll) );
	}
	label$143:;
	label$142:;
	if( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 32ll) == (struct $8FBSYMBOL*)0ull) goto label$145;
	{
		HADDCTORBODY( UDT$1, *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 32ll), -1ll );
	}
	label$145:;
	label$144:;
	if( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 24ll) == (struct $8FBSYMBOL*)0ull) goto label$147;
	{
		HADDCTORBODY( UDT$1, *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 24ll), -1ll );
	}
	label$147:;
	label$146:;
	if( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 8ll) == (struct $8FBSYMBOL*)0ull) goto label$149;
	{
		HADDCTORBODY( UDT$1, *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 8ll), 0ll );
	}
	label$149:;
	label$148:;
	if( *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 16ll) == (struct $8FBSYMBOL*)0ull) goto label$151;
	{
		HADDCTORBODY( UDT$1, *(struct $8FBSYMBOL**)((uint8*)DEFAULT$1 + 16ll), 0ll );
	}
	label$151:;
	label$150:;
	label$139:;
}

void SYMBUDTIMPLEMENTDEFAULTMEMBERS( struct $18SYMBDEFAULTMEMBERS* DEFAULT$1, struct $8FBSYMBOL* UDT$1 )
{
	label$152:;
	if( (*(int64*)((uint8*)UDT$1 + 24ll) & 4194304ll) == 0ll) goto label$155;
	{
		SYMBUDTALLOCEXT( UDT$1 );
		HSETMINIMUMVTABLESIZE( UDT$1 );
		if( UDT$1 == *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199248ll)) goto label$157;
		{
			int64 IRET$3;
			int64 vr$2 = HBUILDRTTI( UDT$1 );
			IRET$3 = vr$2;
			HBUILDVTABLE( UDT$1 );
			if( IRET$3 != 0ll) goto label$159;
			{
				goto label$153;
				label$159:;
			}
		}
		label$157:;
		label$156:;
	}
	label$155:;
	label$154:;
	SYMBIMPLEMENTDEFAULTMEMBERS( DEFAULT$1, UDT$1 );
	label$153:;
}

int64 SYMBCOMPISTRIVIAL( struct $8FBSYMBOL* SYM$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$170:;
	struct $8FBSYMBOL* vr$1 = SYMBGETCOMPCOPYCTOR( SYM$1 );
	struct $8FBSYMBOL* vr$3 = SYMBGETCOMPDTOR1( SYM$1 );
	fb$result$1 = ((int64)-(vr$1 == (struct $8FBSYMBOL*)0ull) & (int64)-(vr$3 == (struct $8FBSYMBOL*)0ull)) & (int64)-((*(int64*)((uint8*)SYM$1 + 24ll) & 4194304ll) == 0ll);
	label$171:;
	return fb$result$1;
}

void SYMBSETCOMPCTORHEAD( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$172:;
	if( *(int64*)SYM$1 != 10ll) goto label$175;
	{
		SYMBUDTALLOCEXT( SYM$1 );
		if( *(struct $8FBSYMBOL**)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) != (struct $8FBSYMBOL*)0ull) goto label$177;
		{
			*(struct $8FBSYMBOL**)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) = PROC$1;
		}
		label$177:;
		label$176:;
	}
	label$175:;
	label$174:;
	label$173:;
}

void SYMBCHECKCOMPCTOR( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$178:;
	if( *(int64*)SYM$1 != 10ll) goto label$181;
	{
		{
			int16 TMP$92$3;
			TMP$92$3 = *(int16*)((uint8*)PROC$1 + 120ll);
			if( (int64)TMP$92$3 != 1ll) goto label$183;
			label$184:;
			{
				*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 8ll) = PROC$1;
			}
			goto label$182;
			label$183:;
			if( (int64)TMP$92$3 != 2ll) goto label$185;
			label$186:;
			{
				if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 16ll) != (struct $8FBSYMBOL*)0ull) goto label$188;
				{
					int64 vr$8 = HHASBYREFSELFPARAM( PROC$1, 20ll, SYM$1 );
					if( vr$8 == 0ll) goto label$190;
					{
						*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 16ll) = PROC$1;
					}
					label$190:;
					label$189:;
				}
				label$188:;
				label$187:;
				if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 24ll) != (struct $8FBSYMBOL*)0ull) goto label$192;
				{
					int64 vr$13 = HHASBYREFSELFPARAM( PROC$1, 532ll, SYM$1 );
					if( vr$13 == 0ll) goto label$194;
					{
						*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 24ll) = PROC$1;
					}
					label$194:;
					label$193:;
				}
				label$192:;
				label$191:;
			}
			label$185:;
			label$182:;
		}
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 8ll) != (struct $8FBSYMBOL*)0ull) goto label$196;
		{
			if( (int64)*(int16*)((uint8*)PROC$1 + 122ll) != ((int64)*(int16*)((uint8*)PROC$1 + 120ll) + -1ll)) goto label$198;
			{
				*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 8ll) = PROC$1;
			}
			label$198:;
			label$197:;
		}
		label$196:;
		label$195:;
	}
	label$181:;
	label$180:;
	label$179:;
}

void SYMBSETCOMPDTOR1( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$199:;
	if( *(int64*)SYM$1 != 10ll) goto label$202;
	{
		SYMBUDTALLOCEXT( SYM$1 );
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 32ll) != (struct $8FBSYMBOL*)0ull) goto label$204;
		{
			*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 32ll) = PROC$1;
		}
		label$204:;
		label$203:;
	}
	label$202:;
	label$201:;
	label$200:;
}

void SYMBSETCOMPDTOR0( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$205:;
	if( *(int64*)SYM$1 != 10ll) goto label$208;
	{
		SYMBUDTALLOCEXT( SYM$1 );
		if( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 40ll) != (struct $8FBSYMBOL*)0ull) goto label$210;
		{
			*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 40ll) = PROC$1;
		}
		label$210:;
		label$209:;
	}
	label$208:;
	label$207:;
	label$206:;
}

struct $8FBSYMBOL* SYMBGETCOMPCTORHEAD( struct $8FBSYMBOL* SYM$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$211:;
	if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$214;
	{
		if( *(int64*)SYM$1 != 10ll) goto label$216;
		{
			if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$218;
			{
				fb$result$1 = *(struct $8FBSYMBOL**)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll);
			}
			label$218:;
			label$217:;
		}
		label$216:;
		label$215:;
	}
	label$214:;
	label$213:;
	label$212:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBGETCOMPDEFCTOR( struct $8FBSYMBOL* SYM$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$219:;
	if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$222;
	{
		if( *(int64*)SYM$1 != 10ll) goto label$224;
		{
			if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$226;
			{
				fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 8ll);
			}
			label$226:;
			label$225:;
		}
		label$224:;
		label$223:;
	}
	label$222:;
	label$221:;
	label$220:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBGETCOMPDTOR1( struct $8FBSYMBOL* SYM$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$231:;
	if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$234;
	{
		if( *(int64*)SYM$1 != 10ll) goto label$236;
		{
			if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$238;
			{
				fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 32ll);
			}
			label$238:;
			label$237:;
		}
		label$236:;
		label$235:;
	}
	label$234:;
	label$233:;
	label$232:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBGETCOMPDTOR0( struct $8FBSYMBOL* SYM$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$239:;
	if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$242;
	{
		if( *(int64*)SYM$1 != 10ll) goto label$244;
		{
			if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$246;
			{
				fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 40ll);
			}
			label$246:;
			label$245:;
		}
		label$244:;
		label$243:;
	}
	label$242:;
	label$241:;
	label$240:;
	return fb$result$1;
}

void SYMBCHECKCOMPLETOP( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$247:;
	if( *(int64*)SYM$1 != 10ll) goto label$250;
	{
		int64 vr$1 = HHASBYREFSELFPARAM( PROC$1, 20ll, SYM$1 );
		if( vr$1 == 0ll) goto label$252;
		{
			SYMBUDTALLOCEXT( SYM$1 );
			*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 48ll) = PROC$1;
		}
		label$252:;
		label$251:;
		int64 vr$4 = HHASBYREFSELFPARAM( PROC$1, 532ll, SYM$1 );
		if( vr$4 == 0ll) goto label$254;
		{
			SYMBUDTALLOCEXT( SYM$1 );
			*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 56ll) = PROC$1;
		}
		label$254:;
		label$253:;
	}
	label$250:;
	label$249:;
	label$248:;
}

int64 SYMBCOMPHASCOPYLETOPS( struct $8FBSYMBOL* UDT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$255:;
	if( *(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$258;
	{
		fb$result$1 = (int64)-(*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 48ll) != (struct $8FBSYMBOL*)0ull) | (int64)-(*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 56ll) != (struct $8FBSYMBOL*)0ull);
	}
	label$258:;
	label$257:;
	label$256:;
	return fb$result$1;
}

struct $8FBSYMBOL* SYMBGETCOMPOPOVLHEAD( struct $8FBSYMBOL* SYM$1, $6AST_OP OP$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$259:;
	if( (*(int64*)(((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) + 8ll) & 1ll) == 0ll) goto label$262;
	{
		{
			$12FB_SYMBCLASS TMP$93$3;
			TMP$93$3 = *($12FB_SYMBCLASS*)SYM$1;
			if( TMP$93$3 != 10ll) goto label$264;
			label$265:;
			{
				if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) != (struct $12FB_STRUCTEXT*)0ull) goto label$267;
				{
					fb$result$1 = (struct $8FBSYMBOL*)0ull;
					goto label$260;
				}
				label$267:;
				label$266:;
				fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + (OP$1 << (3ll & 63ll))) + 64ll);
			}
			goto label$263;
			label$264:;
			if( TMP$93$3 != 9ll) goto label$268;
			label$269:;
			{
				fb$result$1 = (struct $8FBSYMBOL*)0ull;
			}
			goto label$263;
			label$268:;
			if( TMP$93$3 != 11ll) goto label$270;
			label$271:;
			{
			}
			label$270:;
			label$263:;
		}
	}
	goto label$261;
	label$262:;
	{
		fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)((uint8*)&SYMB$ + (OP$1 << (3ll & 63ll))) + 198208ll);
	}
	label$261:;
	label$260:;
	return fb$result$1;
}

void SYMBSETCOMPOPOVLHEAD( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* PROC$1 )
{
	label$272:;
	$6AST_OP OP$1;
	OP$1 = *($6AST_OP*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 80ll);
	if( (*(int64*)(((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) + 8ll) & 1ll) == 0ll) goto label$275;
	{
		if( *(int64*)SYM$1 != 10ll) goto label$277;
		{
			SYMBUDTALLOCEXT( SYM$1 );
			*(struct $8FBSYMBOL**)((uint8*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + (OP$1 << (3ll & 63ll))) + 64ll) = PROC$1;
		}
		label$277:;
		label$276:;
		if( OP$1 != 0ll) goto label$279;
		{
			SYMBCHECKCOMPLETOP( SYM$1, PROC$1 );
		}
		label$279:;
		label$278:;
	}
	goto label$274;
	label$275:;
	{
		*(struct $8FBSYMBOL**)((uint8*)((uint8*)&SYMB$ + (OP$1 << (3ll & 63ll))) + 198208ll) = PROC$1;
	}
	label$274:;
	label$273:;
}

int64 SYMBCOMPADDVIRTUAL( struct $8FBSYMBOL* UDT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$280:;
	SYMBUDTALLOCEXT( UDT$1 );
	HSETMINIMUMVTABLESIZE( UDT$1 );
	fb$result$1 = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll);
	*(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll) = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll) + 1ll;
	label$281:;
	return fb$result$1;
}

int64 SYMBCOMPGETABSTRACTCOUNT( struct $8FBSYMBOL* UDT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$282:;
	if( *(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$285;
	{
		fb$result$1 = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 312ll);
	}
	label$285:;
	label$284:;
	label$283:;
	return fb$result$1;
}

int64 OPTIMIZEPUREABSTRACTTYPES( struct $8FBSYMBOL* UDT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$286:;
	if( *(int64*)((uint8*)&ENV$ + 552ll) == 0ll) goto label$289;
	{
		if( *(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$291;
		{
			int64 TMP$94$3;
			int64 ABSTRACTCOUNT$3;
			ABSTRACTCOUNT$3 = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 312ll);
			if( ABSTRACTCOUNT$3 <= 0ll) goto label$292;
			TMP$94$3 = (int64)-((ABSTRACTCOUNT$3 + 2ll) == *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll));
			goto label$295;
			label$292:;
			TMP$94$3 = 0ll;
			label$295:;
			if( TMP$94$3 == 0ll) goto label$294;
			{
				fb$result$1 = -1ll;
				goto label$287;
			}
			label$294:;
			label$293:;
		}
		label$291:;
		label$290:;
	}
	label$289:;
	label$288:;
	fb$result$1 = 0ll;
	goto label$287;
	label$287:;
	return fb$result$1;
}

void SYMBNESTBEGIN( struct $8FBSYMBOL* SYM$1, int64 INSERT_CHAIN$1 )
{
	label$330:;
	struct $11FB_SYMBNEST* N$1;
	struct $8FBHASHTB* HASHTB$1;
	struct $10FBSYMBOLTB* SYMBTB$1;
	void* vr$1 = STACKPUSH( (struct $6TSTACK*)((uint8*)&SYMB$ + 197048ll) );
	N$1 = (struct $11FB_SYMBNEST*)vr$1;
	*(struct $8FBSYMBOL**)N$1 = SYM$1;
	*(struct $10FBSYMBOLTB**)((uint8*)N$1 + 8ll) = *(struct $10FBSYMBOLTB**)((uint8*)&SYMB$ + 197040ll);
	*(struct $8FBHASHTB**)((uint8*)N$1 + 16ll) = *(struct $8FBHASHTB**)((uint8*)&SYMB$ + 197032ll);
	if( *(int64*)SYM$1 != 3ll) goto label$333;
	{
		SYMBTB$1 = (struct $10FBSYMBOLTB*)((uint8*)SYM$1 + 96ll);
		HASHTB$1 = (struct $8FBHASHTB*)0ull;
	}
	goto label$332;
	label$333:;
	{
		SYMBTB$1 = (struct $10FBSYMBOLTB*)((uint8*)SYM$1 + 96ll);
		HASHTB$1 = (struct $8FBHASHTB*)((uint8*)SYM$1 + 120ll);
	}
	label$332:;
	*(struct $10FBSYMBOLTB**)((uint8*)&SYMB$ + 197040ll) = SYMBTB$1;
	if( HASHTB$1 == (struct $8FBHASHTB*)0ull) goto label$335;
	{
		*(struct $8FBSYMBOL**)((uint8*)N$1 + 24ll) = *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 197024ll);
		*(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 197024ll) = SYM$1;
		*(struct $8FBHASHTB**)((uint8*)&SYMB$ + 197032ll) = HASHTB$1;
		if( *(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$337;
		{
			void* vr$15 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197272ll) );
			*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) = (struct $13FBNAMESPC_EXT*)vr$15;
		}
		label$337:;
		label$336:;
		*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) + 1ll;
		if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) == 1ll) goto label$339;
		{
			SYMBHASHLISTREMOVENAMESPACE( SYM$1 );
		}
		label$339:;
		label$338:;
		SYMBHASHLISTADD( HASHTB$1 );
		if( INSERT_CHAIN$1 == 0ll) goto label$341;
		{
			HINSERTNESTED( SYM$1, HASHTB$1, *(struct $8FBSYMBOL**)((uint8*)N$1 + 24ll) );
		}
		label$341:;
		label$340:;
		HINSERTIMPORTED( SYM$1 );
	}
	label$335:;
	label$334:;
	label$331:;
}

void SYMBNESTEND( int64 REMOVE_CHAIN$1 )
{
	label$342:;
	struct $11FB_SYMBNEST* N$1;
	struct $8FBHASHTB* HASHTB$1;
	struct $8FBSYMBOL* SYM$1;
	void* vr$1 = STACKGETTOS( (struct $6TSTACK*)((uint8*)&SYMB$ + 197048ll) );
	N$1 = (struct $11FB_SYMBNEST*)vr$1;
	SYM$1 = *(struct $8FBSYMBOL**)N$1;
	if( *(int64*)SYM$1 != 3ll) goto label$345;
	{
		HASHTB$1 = (struct $8FBHASHTB*)0ull;
	}
	goto label$344;
	label$345:;
	{
		HASHTB$1 = (struct $8FBHASHTB*)((uint8*)SYM$1 + 120ll);
	}
	label$344:;
	*(struct $10FBSYMBOLTB**)((uint8*)&SYMB$ + 197040ll) = *(struct $10FBSYMBOLTB**)((uint8*)N$1 + 8ll);
	if( HASHTB$1 == (struct $8FBHASHTB*)0ull) goto label$347;
	{
		HREMOVEIMPORTED( SYM$1 );
		if( REMOVE_CHAIN$1 == 0ll) goto label$349;
		{
			HREMOVENESTED( SYM$1, *(struct $8FBSYMBOL**)((uint8*)N$1 + 24ll) );
		}
		label$349:;
		label$348:;
		*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) + -1ll;
		SYMBHASHLISTDEL( HASHTB$1 );
		if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 32ll) == 0ll) goto label$351;
		{
			SYMBHASHLISTINSERTNAMESPACE( SYM$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 104ll) );
		}
		label$351:;
		label$350:;
		*(struct $8FBHASHTB**)((uint8*)&SYMB$ + 197032ll) = *(struct $8FBHASHTB**)((uint8*)N$1 + 16ll);
		*(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 197024ll) = *(struct $8FBSYMBOL**)((uint8*)N$1 + 24ll);
	}
	label$347:;
	label$346:;
	STACKPOP( (struct $6TSTACK*)((uint8*)&SYMB$ + 197048ll) );
	label$343:;
}

void SYMBCOMPADDTOIMPORTLIST( struct $8FBSYMBOL* IMP_$1 )
{
	label$352:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 120ll);
	if( *(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$355;
	{
		void* vr$3 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197272ll) );
		*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) = (struct $13FBNAMESPC_EXT*)vr$3;
	}
	label$355:;
	label$354:;
	if( *(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 8ll) == (struct $8FBSYMBOL*)0ull) goto label$357;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 8ll) + 112ll) = IMP_$1;
	}
	goto label$356;
	label$357:;
	{
		*(struct $8FBSYMBOL**)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) = IMP_$1;
	}
	label$356:;
	*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 104ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 8ll);
	*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 8ll) = IMP_$1;
	label$353:;
}

void SYMBCOMPDELFROMIMPORTLIST( struct $8FBSYMBOL* IMP_$1 )
{
	label$358:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 120ll);
	if( *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 104ll) != (struct $8FBSYMBOL*)0ull) goto label$361;
	{
		*(struct $8FBSYMBOL**)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll);
	}
	goto label$360;
	label$361:;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 104ll) + 112ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll);
	}
	label$360:;
	if( *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll) != (struct $8FBSYMBOL*)0ull) goto label$363;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 8ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 104ll);
	}
	goto label$362;
	label$363:;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll) + 104ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 104ll);
	}
	label$362:;
	label$359:;
}

void SYMBCOMPADDTOEXPORTLIST( struct $8FBSYMBOL* IMP_$1 )
{
	label$364:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 96ll);
	if( *(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$367;
	{
		void* vr$3 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197272ll) );
		*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) = (struct $13FBNAMESPC_EXT*)vr$3;
	}
	label$367:;
	label$366:;
	if( *(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 24ll) == (struct $8FBSYMBOL*)0ull) goto label$369;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 24ll) + 136ll) = IMP_$1;
	}
	goto label$368;
	label$369:;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 16ll) = IMP_$1;
	}
	label$368:;
	*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 128ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 24ll);
	*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 136ll) = (struct $8FBSYMBOL*)0ull;
	*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 24ll) = IMP_$1;
	label$365:;
}

void SYMBCOMPDELFROMEXPORTLIST( struct $8FBSYMBOL* IMP_$1 )
{
	label$370:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 96ll);
	if( *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 128ll) != (struct $8FBSYMBOL*)0ull) goto label$373;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 16ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 136ll);
	}
	goto label$372;
	label$373:;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 128ll) + 136ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 136ll);
	}
	label$372:;
	if( *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 136ll) != (struct $8FBSYMBOL*)0ull) goto label$375;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 24ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 128ll);
	}
	goto label$374;
	label$375:;
	{
		*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 136ll) + 128ll) = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 128ll);
	}
	label$374:;
	label$371:;
}

void SYMBCOMPDELIMPORTLIST( struct $8FBSYMBOL* SYM$1 )
{
	label$376:;
	if( *(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$379;
	{
		goto label$377;
	}
	label$379:;
	label$378:;
	struct $8FBSYMBOL* EXP_$1;
	EXP_$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) + 16ll);
	label$380:;
	if( EXP_$1 == (struct $8FBSYMBOL*)0ull) goto label$381;
	{
		SYMBCOMPDELFROMIMPORTLIST( EXP_$1 );
		struct $8FBSYMBOL* NXT$2;
		NXT$2 = *(struct $8FBSYMBOL**)((uint8*)EXP_$1 + 136ll);
		SYMBCOMPDELFROMEXPORTLIST( EXP_$1 );
		*(struct $8FBSYMBOL**)((uint8*)EXP_$1 + 96ll) = (struct $8FBSYMBOL*)0ull;
		EXP_$1 = NXT$2;
	}
	goto label$380;
	label$381:;
	label$377:;
}

void SYMBCOMPRTTIINIT( void )
{
	label$382:;
	struct $8FBSYMBOL* RTTITYPE$1;
	struct $8FBSYMBOL* OBJTYPE$1;
	struct $8FBSYMBOL* OBJRTTI$1;
	struct $8FBSYMBOL* CTOR$1;
	static struct $10FBARRAYDIM DTB$1[1];
	static struct $8FBARRAY1I10FBARRAYDIME tmp$95$1 = { (struct $10FBARRAYDIM*)DTB$1, (struct $10FBARRAYDIM*)DTB$1, 16ll, 16ll, 1ll, 49ll, { { 1ll, 0ll, 0ll } } };
	struct $8FBSYMBOL* vr$0 = SYMBSTRUCTBEGIN( (struct $10FBSYMBOLTB*)0ull, (struct $8FBHASHTB*)0ull, (struct $8FBSYMBOL*)0ull, (char*)"fb_RTTI$", (char*)"fb_RTTI$", 0ll, 0ll, 0ll, 0ll, 0ll );
	RTTITYPE$1 = vr$0;
	*(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199240ll) = RTTITYPE$1;
	SYMBADDFIELD( RTTITYPE$1, (char*)"stdlibvtable", 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$95$1, 32ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll, 0ll );
	SYMBADDFIELD( RTTITYPE$1, (char*)"id", 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$95$1, 36ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll, 0ll );
	SYMBADDFIELD( RTTITYPE$1, (char*)"rttibase", 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$95$1, 52ll, RTTITYPE$1, 0ll, 0ll, 0ll );
	SYMBSTRUCTEND( RTTITYPE$1, 0ll );
	char* PTYPENAME$1;
	if( *(int64*)((uint8*)&ENV$ + 272ll) != 3ll) goto label$385;
	{
		PTYPENAME$1 = (char*)"__OBJECT";
	}
	goto label$384;
	label$385:;
	{
		PTYPENAME$1 = (char*)"OBJECT";
	}
	label$384:;
	struct $8FBSYMBOL* vr$1 = SYMBSTRUCTBEGIN( (struct $10FBSYMBOLTB*)0ull, (struct $8FBHASHTB*)0ull, (struct $8FBSYMBOL*)0ull, PTYPENAME$1, (char*)"fb_Object$", 0ll, 0ll, 0ll, 0ll, 0ll );
	OBJTYPE$1 = vr$1;
	*(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199248ll) = OBJTYPE$1;
	*($12FB_SYMBSTATS*)((uint8*)OBJTYPE$1 + 24ll) = *(int64*)((uint8*)OBJTYPE$1 + 24ll) | 4194304ll;
	*($12FB_SYMBSTATS*)((uint8*)OBJTYPE$1 + 24ll) = *(int64*)((uint8*)OBJTYPE$1 + 24ll) | 262144ll;
	SYMBNESTBEGIN( OBJTYPE$1, 0ll );
	SYMBADDFIELD( OBJTYPE$1, (char*)"vptr$", 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$95$1, 32ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll, 0ll );
	$11FB_FUNCMODE MODE$1;
	MODE$1 = 3ll;
	struct $8FBSYMBOL* vr$8 = SYMBPREADDPROC( (char*)0ull );
	CTOR$1 = vr$8;
	SYMBADDPROCINSTANCEPARAM( OBJTYPE$1, CTOR$1 );
	SYMBADDCTOR( CTOR$1, (char*)0ull, 0ll, 7ll, MODE$1, 0ll );
	struct $8FBSYMBOL* vr$9 = SYMBPREADDPROC( (char*)0ull );
	CTOR$1 = vr$9;
	SYMBADDPROCINSTANCEPARAM( OBJTYPE$1, CTOR$1 );
	SYMBADDPROCPARAM( CTOR$1, (char*)"__FB_RHS__", 532ll, OBJTYPE$1, 0ll, 2ll, 0ll, 0ll );
	SYMBADDCTOR( CTOR$1, (char*)0ull, 0ll, 7ll, MODE$1, 0ll );
	SYMBSTRUCTEND( OBJTYPE$1, -1ll );
	struct $8FBSYMBOL* vr$10 = SYMBADDVAR( (char*)0ull, (char*)"__fb_ZTS6Object", 20ll, *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199240ll), 0ll, 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$95$1, 17ll, 1ll );
	OBJRTTI$1 = vr$10;
	SYMBUDTALLOCEXT( OBJTYPE$1 );
	*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)OBJTYPE$1 + 240ll) + 304ll) = OBJRTTI$1;
	label$383:;
}

void SYMBCOMPRTTIEND( void )
{
	label$386:;
	label$387:;
}

static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM* THIS$1, struct $11TSTRSETITEM* __FB_RHS__$1 )
{
	label$4:;
	fb_StrAssign( (void*)THIS$1, -1ll, (void*)__FB_RHS__$1, -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 24ll) = *(int64*)((uint8*)__FB_RHS__$1 + 24ll);
	*(struct $8HASHITEM**)((uint8*)THIS$1 + 32ll) = *(struct $8HASHITEM**)((uint8*)__FB_RHS__$1 + 32ll);
	label$5:;
}

static struct $8FBSYMBOL* HDECLAREPROC( struct $8FBSYMBOL* UDT$1, $6AST_OP OP$1, int64 RHSDTYPE$1, $13FB_SYMBATTRIB ATTRIB$1, $13FB_PROCATTRIB PATTRIB$1, $11FB_FUNCMODE MODE$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$22:;
	struct $8FBSYMBOL* PROC$1;
	SYMBNESTBEGIN( UDT$1, -1ll );
	struct $8FBSYMBOL* vr$1 = SYMBPREADDPROC( (char*)0ull );
	PROC$1 = vr$1;
	SYMBADDPROCINSTANCEPARAM( UDT$1, PROC$1 );
	if( RHSDTYPE$1 == 2147483648ll) goto label$25;
	{
		SYMBADDPROCPARAM( PROC$1, (char*)"__FB_RHS__", RHSDTYPE$1, UDT$1, 0ll, 2ll, 0ll, 0ll );
	}
	label$25:;
	label$24:;
	ATTRIB$1 = ATTRIB$1 | 64ll;
	PATTRIB$1 = PATTRIB$1 | 2ll;
	if( OP$1 != -1ll) goto label$27;
	{
		struct $8FBSYMBOL* vr$4 = SYMBADDCTOR( PROC$1, (char*)0ull, ATTRIB$1, PATTRIB$1, MODE$1, 4ll );
		PROC$1 = vr$4;
	}
	goto label$26;
	label$27:;
	{
		struct $8FBSYMBOL* vr$5 = SYMBADDOPERATOR( PROC$1, OP$1, (char*)0ull, 0ll, (struct $8FBSYMBOL*)0ull, ATTRIB$1, PATTRIB$1, MODE$1, 4ll );
		PROC$1 = vr$5;
	}
	label$26:;
	SYMBNESTEND( -1ll );
	fb$result$1 = PROC$1;
	label$23:;
	return fb$result$1;
}

static void HSETMINIMUMVTABLESIZE( struct $8FBSYMBOL* UDT$1 )
{
	label$28:;
	if( *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll) != 0ll) goto label$31;
	{
		*(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll) = 2ll;
	}
	label$31:;
	label$30:;
	label$29:;
}

static void HREBUILDRTTI( struct $8FBSYMBOL* UDT$1 )
{
	label$32:;
	struct $7ASTNODE* INITREE$1;
	struct $7ASTNODE* RTTIBASE$1;
	struct $8FBSYMBOL* RTTI$1;
	struct $8FBSYMBOL* FLD$1;
	if( UDT$1 == (struct $8FBSYMBOL*)0ull) goto label$35;
	{
		FLD$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 296ll);
		if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$37;
		{
			*($12FB_SYMBSTATS*)((uint8*)FLD$1 + 24ll) = *(int64*)((uint8*)FLD$1 + 24ll) & -268435457ll;
		}
		label$37:;
		label$36:;
		RTTI$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 304ll);
		if( RTTI$1 == (struct $8FBSYMBOL*)0ull) goto label$39;
		{
			*($12FB_SYMBSTATS*)((uint8*)RTTI$1 + 24ll) = *(int64*)((uint8*)RTTI$1 + 24ll) & -268435457ll;
			struct $7ASTNODE* vr$10 = ASTTYPEINIBEGIN( 20ll, *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199240ll), 0ll, 0ll );
			INITREE$1 = vr$10;
			ASTTYPEINISCOPEBEGIN( INITREE$1, RTTI$1, 0ll );
			struct $8FBSYMBOL* vr$11 = SYMBUDTGETFIRSTFIELD( *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199240ll) );
			FLD$1 = vr$11;
			struct $7ASTNODE* vr$12 = ASTNEWCONSTI( 0ll, 32ll, (struct $8FBSYMBOL*)0ull );
			ASTTYPEINIADDASSIGN( INITREE$1, vr$12, FLD$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
			struct $8FBSYMBOL* vr$13 = SYMBUDTGETNEXTINITABLEFIELD( FLD$1 );
			FLD$1 = vr$13;
			char* vr$14 = SYMBGETMANGLEDNAME( UDT$1 );
			struct $8FBSYMBOL* vr$15 = SYMBALLOCSTRCONST( vr$14, -1ll );
			struct $7ASTNODE* vr$16 = ASTNEWVAR( vr$15, 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
			struct $7ASTNODE* vr$17 = ASTNEWADDROF( vr$16 );
			ASTTYPEINIADDASSIGN( INITREE$1, vr$17, FLD$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
			struct $8FBSYMBOL* vr$18 = SYMBUDTGETNEXTINITABLEFIELD( FLD$1 );
			FLD$1 = vr$18;
			if( *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) == (struct $8FBSYMBOL*)0ull) goto label$41;
			{
				struct $7ASTNODE* vr$24 = ASTNEWVAR( *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) + 240ll) + 304ll), 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
				struct $7ASTNODE* vr$25 = ASTNEWADDROF( vr$24 );
				RTTIBASE$1 = vr$25;
			}
			goto label$40;
			label$41:;
			{
				struct $7ASTNODE* vr$26 = ASTNEWCONSTI( 0ll, 32ll, (struct $8FBSYMBOL*)0ull );
				RTTIBASE$1 = vr$26;
			}
			label$40:;
			ASTTYPEINIADDASSIGN( INITREE$1, RTTIBASE$1, FLD$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
			ASTTYPEINISCOPEEND( INITREE$1, RTTI$1 );
			ASTTYPEINIEND( INITREE$1, -1ll );
			*(struct $7ASTNODE**)((uint8*)RTTI$1 + 96ll) = INITREE$1;
		}
		label$39:;
		label$38:;
	}
	label$35:;
	label$34:;
	label$33:;
}

static int64 HBUILDRTTI( struct $8FBSYMBOL* UDT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$42:;
	static struct $10FBARRAYDIM DTB$1[1];
	static struct $8FBARRAY1I10FBARRAYDIME tmp$87$1 = { (struct $10FBARRAYDIM*)DTB$1, (struct $10FBARRAYDIM*)DTB$1, 16ll, 16ll, 1ll, 49ll, { { 1ll, 0ll, 0ll } } };
	struct $7ASTNODE* INITREE$1;
	struct $18SYMBDEFAULTMEMBERS DEFAULT$1;
	struct $8FBSYMBOL* RTTI$1;
	struct $8FBSYMBOL* BASEUDT$1;
	SYMBNESTBEGIN( UDT$1, -1ll );
	struct $8FBSYMBOL* vr$1 = SYMBADDVAR( (char*)0ull, (char*)0ull, 20ll, *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199240ll), 0ll, 0ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$87$1, 8390659ll, 1ll );
	RTTI$1 = vr$1;
	*($12FB_SYMBSTATS*)((uint8*)RTTI$1 + 24ll) = *(int64*)((uint8*)RTTI$1 + 24ll) | 256ll;
	SYMBNESTEND( -1ll );
	*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 304ll) = RTTI$1;
	int64 vr$7 = OPTIMIZEPUREABSTRACTTYPES( UDT$1 );
	if( vr$7 == 0ll) goto label$45;
	{
		*($12FB_SYMBSTATS*)((uint8*)RTTI$1 + 24ll) = *(int64*)((uint8*)RTTI$1 + 24ll) | 268435456ll;
		struct $7ASTNODE* vr$11 = ASTNEWNOP(  );
		*(struct $7ASTNODE**)((uint8*)RTTI$1 + 96ll) = vr$11;
		fb$result$1 = 0ll;
		goto label$43;
	}
	goto label$44;
	label$45:;
	{
		HREBUILDRTTI( UDT$1 );
		BASEUDT$1 = UDT$1;
		label$46:;
		if( *(struct $8FBSYMBOL**)((uint8*)BASEUDT$1 + 176ll) == (struct $8FBSYMBOL*)0ull) goto label$47;
		{
			int64 TMP$88$3;
			BASEUDT$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)BASEUDT$1 + 176ll) + 64ll);
			int64 vr$16 = OPTIMIZEPUREABSTRACTTYPES( BASEUDT$1 );
			if( vr$16 != 0ll) goto label$49;
			{
				goto label$47;
			}
			label$49:;
			label$48:;
			RTTI$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 304ll);
			if( RTTI$1 == (struct $8FBSYMBOL*)0ull) goto label$50;
			TMP$88$3 = (int64)-((struct $8FBSYMBOL*)(int64)-((*(int64*)((uint8*)RTTI$1 + 24ll) & 268435456ll) != 0ll) != (struct $8FBSYMBOL*)0ull);
			goto label$388;
			label$50:;
			TMP$88$3 = 0ll;
			label$388:;
			if( TMP$88$3 == 0ll) goto label$52;
			{
				if( BASEUDT$1 == *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199248ll)) goto label$54;
				{
					INITREE$1 = *(struct $7ASTNODE**)((uint8*)RTTI$1 + 96ll);
					if( INITREE$1 == (struct $7ASTNODE*)0ull) goto label$56;
					{
						ASTDELNODE( INITREE$1 );
						*(struct $7ASTNODE**)((uint8*)RTTI$1 + 96ll) = (struct $7ASTNODE*)0ull;
					}
					label$56:;
					label$55:;
					HREBUILDRTTI( BASEUDT$1 );
					*(struct $8FBSYMBOL**)&DEFAULT$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 8ll);
					*(struct $8FBSYMBOL**)((uint8*)&DEFAULT$1 + 24ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 16ll);
					*(struct $8FBSYMBOL**)((uint8*)&DEFAULT$1 + 32ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 24ll);
					*(struct $8FBSYMBOL**)((uint8*)&DEFAULT$1 + 40ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 56ll);
					*(struct $8FBSYMBOL**)((uint8*)&DEFAULT$1 + 8ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 32ll);
					*(struct $8FBSYMBOL**)((uint8*)&DEFAULT$1 + 16ll) = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)BASEUDT$1 + 240ll) + 40ll);
					SYMBIMPLEMENTDEFAULTMEMBERS( &DEFAULT$1, BASEUDT$1 );
				}
				label$54:;
				label$53:;
			}
			label$52:;
			label$51:;
		}
		goto label$46;
		label$47:;
		fb$result$1 = -1ll;
		goto label$43;
	}
	label$44:;
	label$43:;
	return fb$result$1;
}

static void HBUILDVTABLE( struct $8FBSYMBOL* UDT$1 )
{
	label$57:;
	static struct $10FBARRAYDIM DTB$1[1];
	static struct $8FBARRAY1I10FBARRAYDIME tmp$89$1 = { (struct $10FBARRAYDIM*)DTB$1, (struct $10FBARRAYDIM*)DTB$1, 16ll, 16ll, 1ll, 49ll, { { 1ll, 0ll, 0ll } } };
	struct $7ASTNODE* INITREE$1;
	struct $7ASTNODE* BASEVTABLEINITREE$1;
	struct $8FBSYMBOL* MEMBER$1;
	struct $8FBSYMBOL* RTTI$1;
	struct $8FBSYMBOL* VTABLE$1;
	int64 I$1;
	int64 BASEVTABLEELEMENTS$1;
	SYMBNESTBEGIN( UDT$1, -1ll );
	*(int64*)((int64)(struct $10FBARRAYDIM*)DTB$1 + 8ll) = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 288ll) + -1ll;
	struct $8FBSYMBOL* vr$3 = SYMBADDVAR( (char*)0ull, (char*)0ull, 32ll, (struct $8FBSYMBOL*)0ull, 0ll, 1ll, (struct $7FBARRAYI10FBARRAYDIME*)&tmp$89$1, 8390659ll, 1ll );
	VTABLE$1 = vr$3;
	*($12FB_SYMBSTATS*)((uint8*)VTABLE$1 + 24ll) = *(int64*)((uint8*)VTABLE$1 + 24ll) | 1024ll;
	SYMBNESTEND( -1ll );
	int64 vr$7 = OPTIMIZEPUREABSTRACTTYPES( UDT$1 );
	if( vr$7 == 0ll) goto label$60;
	{
		*($12FB_SYMBSTATS*)((uint8*)VTABLE$1 + 24ll) = *(int64*)((uint8*)VTABLE$1 + 24ll) | 268435456ll;
	}
	label$60:;
	label$59:;
	int64 vr$13 = OPTIMIZEPUREABSTRACTTYPES( *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) );
	if( vr$13 == 0ll) goto label$62;
	{
		BASEVTABLEELEMENTS$1 = 0ll;
	}
	goto label$61;
	label$62:;
	{
		BASEVTABLEELEMENTS$1 = *(int64*)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) + 240ll) + 288ll);
	}
	label$61:;
	if( BASEVTABLEELEMENTS$1 <= 2ll) goto label$64;
	{
		BASEVTABLEINITREE$1 = *(struct $7ASTNODE**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) + 240ll) + 296ll) + 96ll);
	}
	goto label$63;
	label$64:;
	{
		BASEVTABLEINITREE$1 = (struct $7ASTNODE*)0ull;
	}
	label$63:;
	struct $7ASTNODE* vr$23 = ASTTYPEINIBEGIN( 32ll, (struct $8FBSYMBOL*)0ull, 0ll, 0ll );
	INITREE$1 = vr$23;
	ASTTYPEINISCOPEBEGIN( INITREE$1, VTABLE$1, -1ll );
	struct $7ASTNODE* vr$24 = ASTNEWCONSTI( 0ll, 32ll, (struct $8FBSYMBOL*)0ull );
	ASTTYPEINIADDASSIGN( INITREE$1, vr$24, VTABLE$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
	RTTI$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 304ll);
	struct $7ASTNODE* vr$27 = ASTNEWVAR( RTTI$1, 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$28 = ASTNEWADDROF( vr$27 );
	ASTTYPEINIADDASSIGN( INITREE$1, vr$28, VTABLE$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
	I$1 = 2ll;
	if( BASEVTABLEINITREE$1 == (struct $7ASTNODE*)0ull) goto label$66;
	{
		ASTTYPEINICOPYELEMENTS( INITREE$1, BASEVTABLEINITREE$1, 2ll );
		I$1 = (I$1 + BASEVTABLEELEMENTS$1) + -2ll;
	}
	label$66:;
	label$65:;
	label$67:;
	if( I$1 > *(int64*)((int64)(struct $10FBARRAYDIM*)DTB$1 + 8ll)) goto label$68;
	{
		struct $7ASTNODE* vr$31 = ASTNEWCONSTI( 0ll, 32ll, (struct $8FBSYMBOL*)0ull );
		ASTTYPEINIADDASSIGN( INITREE$1, vr$31, VTABLE$1, 2147483648ll, (struct $8FBSYMBOL*)0ull, 0ll );
		I$1 = I$1 + 1ll;
	}
	goto label$67;
	label$68:;
	ASTTYPEINISCOPEEND( INITREE$1, VTABLE$1 );
	ASTTYPEINIEND( INITREE$1, -1ll );
	*(struct $7ASTNODE**)((uint8*)VTABLE$1 + 96ll) = INITREE$1;
	MEMBER$1 = *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 104ll);
	label$69:;
	if( MEMBER$1 == (struct $8FBSYMBOL*)0ull) goto label$70;
	{
		if( *(int64*)MEMBER$1 != 3ll) goto label$72;
		{
			int64 vr$36 = SYMBPROCGETVTABLEINDEX( MEMBER$1 );
			I$1 = vr$36;
			if( ((int64)-(I$1 > 0ll) & (int64)-((*(int64*)((uint8*)MEMBER$1 + 16ll) & 512ll) == 0ll)) == 0ll) goto label$74;
			{
				struct $7ASTNODE* vr$42 = ASTBUILDPROCADDROF( MEMBER$1 );
				ASTTYPEINIREPLACEELEMENT( INITREE$1, I$1, vr$42 );
			}
			label$74:;
			label$73:;
		}
		label$72:;
		label$71:;
		MEMBER$1 = *(struct $8FBSYMBOL**)((uint8*)MEMBER$1 + 312ll);
	}
	goto label$69;
	label$70:;
	*(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)UDT$1 + 240ll) + 296ll) = VTABLE$1;
	label$58:;
}

static void HPROCBEGIN( struct $8FBSYMBOL* UDT$1, struct $8FBSYMBOL* PROC$1 )
{
	label$75:;
	SYMBNESTBEGIN( UDT$1, -1ll );
	ASTPROCBEGIN( PROC$1, 0ll );
	label$76:;
}

static void HPROCEND( void )
{
	label$77:;
	ASTPROCEND( 0ll );
	SYMBNESTEND( -1ll );
	label$78:;
}

static void HADDCTORBODY( struct $8FBSYMBOL* UDT$1, struct $8FBSYMBOL* PROC$1, int64 IS_COPYCTOR$1 )
{
	label$79:;
	HPROCBEGIN( UDT$1, PROC$1 );
	if( IS_COPYCTOR$1 == 0ll) goto label$82;
	{
		struct $7ASTNODE* vr$2 = ASTBUILDVARFIELD( *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)PROC$1 + 144ll) + 104ll), (struct $8FBSYMBOL*)0ull, 0ll );
		struct $7ASTNODE* vr$5 = ASTBUILDVARFIELD( *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)PROC$1 + 136ll) + 104ll), (struct $8FBSYMBOL*)0ull, 0ll );
		struct $7ASTNODE* vr$6 = ASTNEWASSIGN( vr$5, vr$2, 0ll );
		ASTADD( vr$6 );
	}
	label$82:;
	label$81:;
	HPROCEND(  );
	*($12FB_SYMBSTATS*)((uint8*)UDT$1 + 24ll) = *(int64*)((uint8*)UDT$1 + 24ll) | 8388608ll;
	label$80:;
}

static void HASSIGNDYNAMICARRAY( struct $8FBSYMBOL* FLD$1, struct $8FBSYMBOL* THIS_$1, struct $8FBSYMBOL* RHS$1 )
{
	label$85:;
	int64 DTYPE$1;
	struct $8FBSYMBOL* DST$1;
	struct $8FBSYMBOL* SRC$1;
	struct $8FBSYMBOL* LIMIT$1;
	struct $8FBSYMBOL* LOOPLABEL$1;
	struct $8FBSYMBOL* EXITLABEL$1;
	DTYPE$1 = *(int64*)((uint8*)FLD$1 + 56ll);
	struct $7ASTNODE* vr$2 = ASTBUILDVARFIELD( RHS$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$3 = ASTBUILDVARFIELD( THIS_$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$4 = RTLARRAYREDIMTO( vr$3, vr$2, DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll) );
	ASTADD( vr$4 );
	DTYPE$1 = (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll);
	struct $8FBSYMBOL* vr$14 = SYMBADDLABEL( (char*)0ull, 4ll );
	LOOPLABEL$1 = vr$14;
	struct $8FBSYMBOL* vr$15 = SYMBADDLABEL( (char*)0ull, 4ll );
	EXITLABEL$1 = vr$15;
	struct $8FBSYMBOL* vr$17 = SYMBADDTEMPVAR( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll) );
	DST$1 = vr$17;
	struct $8FBSYMBOL* vr$19 = SYMBADDTEMPVAR( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll) );
	SRC$1 = vr$19;
	struct $8FBSYMBOL* vr$21 = SYMBADDTEMPVAR( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll) );
	LIMIT$1 = vr$21;
	struct $7ASTNODE* vr$23 = ASTBUILDVARFIELD( THIS_$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$24 = _Z19ASTBUILDDEREFADDROFP7ASTNODExlP8FBSYMBOLS2_( vr$23, *(int64*)((uint8*)&SYMB$ + 199192ll), DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll), (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$25 = _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( DST$1, vr$24, 64ll );
	ASTADD( vr$25 );
	struct $7ASTNODE* vr$27 = ASTBUILDVARFIELD( RHS$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$28 = _Z19ASTBUILDDEREFADDROFP7ASTNODExlP8FBSYMBOLS2_( vr$27, *(int64*)((uint8*)&SYMB$ + 199192ll), DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll), (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$29 = _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( SRC$1, vr$28, 64ll );
	ASTADD( vr$29 );
	struct $7ASTNODE* vr$30 = ASTBUILDVARFIELD( RHS$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$31 = _Z19ASTBUILDDEREFADDROFP7ASTNODExlP8FBSYMBOLS2_( vr$30, *(int64*)((uint8*)&SYMB$ + 199200ll), 9ll, (struct $8FBSYMBOL*)0ull, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$32 = ASTNEWVAR( SRC$1, 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$33 = ASTNEWBOP( 28ll, vr$32, vr$31, (struct $8FBSYMBOL*)0ull, 1ll );
	struct $7ASTNODE* vr$34 = _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( LIMIT$1, vr$33, 64ll );
	ASTADD( vr$34 );
	struct $7ASTNODE* vr$35 = ASTNEWLABEL( LOOPLABEL$1, -1ll );
	ASTADD( vr$35 );
	struct $7ASTNODE* vr$36 = ASTNEWVAR( LIMIT$1, 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$37 = ASTNEWVAR( SRC$1, 0ll, 2147483648ll, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$38 = ASTNEWBOP( 49ll, vr$37, vr$36, (struct $8FBSYMBOL*)0ull, 1ll );
	struct $7ASTNODE* vr$39 = ASTBUILDBRANCH( vr$38, EXITLABEL$1, -1ll, 0ll );
	ASTADD( vr$39 );
	struct $7ASTNODE* vr$40 = ASTBUILDVARDEREF( SRC$1 );
	struct $7ASTNODE* vr$41 = ASTBUILDVARDEREF( DST$1 );
	struct $7ASTNODE* vr$42 = ASTNEWASSIGN( vr$41, vr$40, 0ll );
	ASTADD( vr$42 );
	struct $7ASTNODE* vr$43 = ASTBUILDVARINC( DST$1, 1ll );
	ASTADD( vr$43 );
	struct $7ASTNODE* vr$44 = ASTBUILDVARINC( SRC$1, 1ll );
	ASTADD( vr$44 );
	struct $7ASTNODE* vr$45 = ASTNEWBRANCH( 99ll, LOOPLABEL$1, (struct $7ASTNODE*)0ull );
	ASTADD( vr$45 );
	struct $7ASTNODE* vr$46 = ASTNEWLABEL( EXITLABEL$1, -1ll );
	ASTADD( vr$46 );
	label$86:;
}

static void HASSIGNLIST( struct $8FBSYMBOL* FLD$1, struct $8FBSYMBOL* THIS_$1, struct $8FBSYMBOL* RHS$1 )
{
	label$87:;
	static struct $8FBSYMBOL* CNT$1;
	static struct $8FBSYMBOL* LABEL$1;
	static struct $8FBSYMBOL* DST$1;
	static struct $8FBSYMBOL* SRC$1;
	static struct $8FBSYMBOL* SUBTYPE$1;
	SUBTYPE$1 = *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll);
	struct $8FBSYMBOL* vr$1 = SYMBADDTEMPVAR( 8ll, (struct $8FBSYMBOL*)0ull );
	CNT$1 = vr$1;
	struct $8FBSYMBOL* vr$2 = SYMBADDLABEL( (char*)0ull, 4ll );
	LABEL$1 = vr$2;
	struct $8FBSYMBOL* vr$20 = SYMBADDTEMPVAR( ((((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 32505856ll), SUBTYPE$1 );
	DST$1 = vr$20;
	struct $8FBSYMBOL* vr$38 = SYMBADDTEMPVAR( ((((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)FLD$1 + 56ll) & 511ll) & 32505856ll), SUBTYPE$1 );
	SRC$1 = vr$38;
	struct $7ASTNODE* vr$39 = ASTBUILDVARFIELD( THIS_$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$40 = ASTNEWADDROF( vr$39 );
	struct $7ASTNODE* vr$41 = _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( DST$1, vr$40, 64ll );
	ASTADD( vr$41 );
	struct $7ASTNODE* vr$42 = ASTBUILDVARFIELD( RHS$1, FLD$1, 0ll );
	struct $7ASTNODE* vr$43 = ASTNEWADDROF( vr$42 );
	struct $7ASTNODE* vr$44 = _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODEl( SRC$1, vr$43, 64ll );
	ASTADD( vr$44 );
	struct $7ASTNODE* vr$45 = ASTBUILDFORBEGIN( (struct $7ASTNODE*)0ull, CNT$1, LABEL$1, 0ll, -1ll );
	ASTADD( vr$45 );
	struct $7ASTNODE* vr$46 = ASTBUILDVARDEREF( SRC$1 );
	struct $7ASTNODE* vr$47 = ASTBUILDVARDEREF( DST$1 );
	struct $7ASTNODE* vr$48 = ASTNEWASSIGN( vr$47, vr$46, 0ll );
	ASTADD( vr$48 );
	struct $7ASTNODE* vr$49 = ASTBUILDVARINC( DST$1, 1ll );
	ASTADD( vr$49 );
	struct $7ASTNODE* vr$50 = ASTBUILDVARINC( SRC$1, 1ll );
	ASTADD( vr$50 );
	struct $7ASTNODE* vr$52 = ASTNEWCONSTI( *(int64*)((uint8*)FLD$1 + 128ll), 8ll, (struct $8FBSYMBOL*)0ull );
	struct $7ASTNODE* vr$53 = ASTBUILDFOREND( (struct $7ASTNODE*)0ull, CNT$1, LABEL$1, vr$52 );
	ASTADD( vr$53 );
	label$88:;
}

static struct $8FBSYMBOL* HCOPYUNIONFIELDS( struct $8FBSYMBOL* THIS_$1, struct $8FBSYMBOL* RHS$1, struct $8FBSYMBOL* BASE_FLD$1 )
{
	int64 TMP$90$1;
	int64 TMP$91$1;
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$89:;
	struct $8FBSYMBOL* FLD$1;
	int64 BYTES$1;
	int64 LGT$1;
	int64 BASE_OFS$1;
	FLD$1 = BASE_FLD$1;
	BYTES$1 = 0ll;
	BASE_OFS$1 = *(int64*)((uint8*)BASE_FLD$1 + 88ll);
	label$91:;
	{
		int64 vr$2 = SYMBGETREALSIZE( FLD$1 );
		LGT$1 = (vr$2 + *(int64*)((uint8*)FLD$1 + 88ll)) - BASE_OFS$1;
		if( LGT$1 <= BYTES$1) goto label$95;
		{
			BYTES$1 = LGT$1;
		}
		label$95:;
		label$94:;
		FLD$1 = *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 312ll);
	}
	label$93:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$96;
	TMP$90$1 = (int64)-((struct $8FBSYMBOL*)(int64)-(*(int64*)FLD$1 == 12ll) != (struct $8FBSYMBOL*)0ull);
	goto label$389;
	label$96:;
	TMP$90$1 = 0ll;
	label$389:;
	if( TMP$90$1 == 0ll) goto label$97;
	TMP$91$1 = (int64)-((*(int64*)((uint8*)FLD$1 + 24ll) & 16777216ll) != 0ll);
	goto label$390;
	label$97:;
	TMP$91$1 = 0ll;
	label$390:;
	if( TMP$91$1 != 0ll) goto label$91;
	label$92:;
	struct $7ASTNODE* vr$13 = ASTBUILDVARFIELD( RHS$1, BASE_FLD$1, 0ll );
	struct $7ASTNODE* vr$14 = ASTBUILDVARFIELD( THIS_$1, BASE_FLD$1, 0ll );
	struct $7ASTNODE* vr$15 = ASTNEWMEM( 106ll, vr$14, vr$13, BYTES$1, 0ll );
	ASTADD( vr$15 );
	fb$result$1 = FLD$1;
	label$90:;
	return fb$result$1;
}

static void HADDLETOPBODY( struct $8FBSYMBOL* UDT$1, struct $8FBSYMBOL* LETPROC$1 )
{
	label$98:;
	struct $8FBSYMBOL* FLD$1;
	struct $8FBSYMBOL* THIS_$1;
	struct $8FBSYMBOL* RHS$1;
	int64 DO_COPY$1;
	HPROCBEGIN( UDT$1, LETPROC$1 );
	THIS_$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)LETPROC$1 + 136ll) + 104ll);
	RHS$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)LETPROC$1 + 144ll) + 104ll);
	FLD$1 = *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 104ll);
	label$100:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$101;
	{
		DO_COPY$1 = (int64)-(*(int64*)FLD$1 == 12ll) & (int64)-((*(int64*)((uint8*)FLD$1 + 8ll) & 8192ll) == 0ll);
		if( *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) == (struct $8FBSYMBOL*)0ull) goto label$103;
		{
			DO_COPY$1 = DO_COPY$1 & ((int64)-(FLD$1 != *(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll)) | (int64)-(*(struct $8FBSYMBOL**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)UDT$1 + 176ll) + 64ll) != *(struct $8FBSYMBOL**)((uint8*)&SYMB$ + 199248ll)));
		}
		label$103:;
		label$102:;
		if( DO_COPY$1 == 0ll) goto label$105;
		{
			if( (*(int64*)((uint8*)FLD$1 + 24ll) & 16777216ll) == 0ll) goto label$107;
			{
				struct $8FBSYMBOL* vr$21 = HCOPYUNIONFIELDS( THIS_$1, RHS$1, FLD$1 );
				FLD$1 = vr$21;
				goto label$100;
			}
			label$107:;
			label$106:;
			if( (*(int64*)((uint8*)FLD$1 + 8ll) & 4ll) == 0ll) goto label$109;
			{
				HASSIGNDYNAMICARRAY( FLD$1, THIS_$1, RHS$1 );
			}
			goto label$108;
			label$109:;
			{
				if( *(int64*)((uint8*)FLD$1 + 104ll) != 0ll) goto label$111;
				{
					struct $7ASTNODE* vr$25 = ASTBUILDVARFIELD( RHS$1, FLD$1, 0ll );
					struct $7ASTNODE* vr$26 = ASTBUILDVARFIELD( THIS_$1, FLD$1, 0ll );
					struct $7ASTNODE* vr$27 = ASTNEWASSIGN( vr$26, vr$25, 0ll );
					ASTADD( vr$27 );
				}
				goto label$110;
				label$111:;
				{
					HASSIGNLIST( FLD$1, THIS_$1, RHS$1 );
				}
				label$110:;
			}
			label$108:;
		}
		label$105:;
		label$104:;
		FLD$1 = *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 312ll);
	}
	goto label$100;
	label$101:;
	HPROCEND(  );
	*($12FB_SYMBSTATS*)((uint8*)UDT$1 + 24ll) = *(int64*)((uint8*)UDT$1 + 24ll) | 8388608ll;
	label$99:;
}

static int64 HHASBYREFSELFPARAM( struct $8FBSYMBOL* PROC$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$160:;
	struct $8FBSYMBOL* PARAM$1;
	fb$result$1 = 0ll;
	PARAM$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 144ll);
	if( *(int64*)((uint8*)PARAM$1 + 96ll) == 2ll) goto label$163;
	{
		goto label$161;
	}
	label$163:;
	label$162:;
	if( *(int64*)((uint8*)PARAM$1 + 56ll) != ((DTYPE$1 & -512ll) | 23ll)) goto label$165;
	{
		if( *(uint64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 64ll) + 264ll) != *(uint64*)((uint8*)SUBTYPE$1 + 264ll)) goto label$167;
		{
			int32 vr$14 = fb_StrCompare( *(void**)*(struct $8HASHITEM**)((uint8*)*(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 64ll) + 256ll), 0ll, *(void**)*(struct $8HASHITEM**)((uint8*)SUBTYPE$1 + 256ll), 0ll );
			if( (int64)vr$14 != 0ll) goto label$169;
			{
				fb$result$1 = -1ll;
				goto label$161;
			}
			label$169:;
			label$168:;
		}
		label$167:;
		label$166:;
	}
	label$165:;
	label$164:;
	fb$result$1 = (int64)-(*(int64*)((uint8*)PARAM$1 + 56ll) == DTYPE$1) & (int64)-(*(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 64ll) == SUBTYPE$1);
	label$161:;
	return fb$result$1;
}

static struct $8FBSYMBOL* SYMBGETCOMPCOPYCTOR( struct $8FBSYMBOL* SYM$1 )
{
	struct $8FBSYMBOL* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$227:;
	if( *(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) == (struct $12FB_STRUCTEXT*)0ull) goto label$230;
	{
		fb$result$1 = *(struct $8FBSYMBOL**)((uint8*)*(struct $12FB_STRUCTEXT**)((uint8*)SYM$1 + 240ll) + 16ll);
	}
	label$230:;
	label$229:;
	label$228:;
	return fb$result$1;
}

static void HINSERTNESTED( struct $8FBSYMBOL* SYM$1, struct $8FBHASHTB* LASTTB$1, struct $8FBSYMBOL* BASE_NS$1 )
{
	label$296:;
	struct $8FBHASHTB* HASHTB$1;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll);
	label$298:;
	if( NS$1 == BASE_NS$1) goto label$299;
	{
		HASHTB$1 = (struct $8FBHASHTB*)((uint8*)NS$1 + 120ll);
		if( *(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$301;
		{
			void* vr$6 = LISTNEWNODE( (struct $5TLIST*)((uint8*)&SYMB$ + 197272ll) );
			*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) = (struct $13FBNAMESPC_EXT*)vr$6;
		}
		label$301:;
		label$300:;
		*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) + 1ll;
		if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) == 1ll) goto label$303;
		{
			SYMBHASHLISTREMOVENAMESPACE( NS$1 );
		}
		label$303:;
		label$302:;
		SYMBHASHLISTADDBEFORE( LASTTB$1, HASHTB$1 );
		LASTTB$1 = HASHTB$1;
		NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)NS$1 + 248ll);
	}
	goto label$298;
	label$299:;
	label$297:;
}

static void HREMOVENESTED( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* BASE_NS$1 )
{
	label$304:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll);
	label$306:;
	if( NS$1 == BASE_NS$1) goto label$307;
	{
		*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) + -1ll;
		SYMBHASHLISTDEL( (struct $8FBHASHTB*)((uint8*)NS$1 + 120ll) );
		if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$1 + 168ll) + 32ll) == 0ll) goto label$309;
		{
			SYMBHASHLISTINSERTNAMESPACE( NS$1, *(struct $8FBSYMBOL**)((uint8*)NS$1 + 104ll) );
		}
		label$309:;
		label$308:;
		NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)NS$1 + 248ll);
	}
	goto label$306;
	label$307:;
	label$305:;
}

static void HINSERTIMPORTED( struct $8FBSYMBOL* SYM$1 )
{
	label$310:;
	if( *(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$313;
	{
		goto label$311;
	}
	label$313:;
	label$312:;
	struct $8FBSYMBOL* IMP_$1;
	IMP_$1 = *(struct $8FBSYMBOL**)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll);
	label$314:;
	if( IMP_$1 == (struct $8FBSYMBOL*)0ull) goto label$315;
	{
		struct $8FBSYMBOL* NS$2;
		NS$2 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 96ll);
		if( NS$2 == (struct $8FBSYMBOL*)0ull) goto label$317;
		{
			*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) + 1ll;
			if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) != 1ll) goto label$319;
			{
				SYMBHASHLISTINSERTNAMESPACE( NS$2, *(struct $8FBSYMBOL**)((uint8*)NS$2 + 104ll) );
			}
			label$319:;
			label$318:;
		}
		label$317:;
		label$316:;
		IMP_$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll);
	}
	goto label$314;
	label$315:;
	label$311:;
}

static void HREMOVEIMPORTED( struct $8FBSYMBOL* SYM$1 )
{
	label$320:;
	if( *(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll) != (struct $13FBNAMESPC_EXT*)0ull) goto label$323;
	{
		goto label$321;
	}
	label$323:;
	label$322:;
	struct $8FBSYMBOL* IMP_$1;
	IMP_$1 = *(struct $8FBSYMBOL**)*(struct $13FBNAMESPC_EXT**)((uint8*)SYM$1 + 168ll);
	label$324:;
	if( IMP_$1 == (struct $8FBSYMBOL*)0ull) goto label$325;
	{
		struct $8FBSYMBOL* NS$2;
		NS$2 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 96ll);
		if( NS$2 == (struct $8FBSYMBOL*)0ull) goto label$327;
		{
			*(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) = *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) + -1ll;
			if( *(int64*)((uint8*)*(struct $13FBNAMESPC_EXT**)((uint8*)NS$2 + 168ll) + 32ll) != 0ll) goto label$329;
			{
				SYMBHASHLISTREMOVENAMESPACE( NS$2 );
			}
			label$329:;
			label$328:;
		}
		label$327:;
		label$326:;
		IMP_$1 = *(struct $8FBSYMBOL**)((uint8*)IMP_$1 + 112ll);
	}
	goto label$324;
	label$325:;
	label$321:;
}
