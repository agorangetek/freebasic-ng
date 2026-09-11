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
struct $10TFLISTITEM;
struct $10TFLISTITEM {
	struct $10TFLISTITEM* NEXT;
};
#define __FB_STATIC_ASSERT( expr ) extern int __$fb_structsizecheck[(expr) ? 1 : -1]
__FB_STATIC_ASSERT( sizeof( struct $10TFLISTITEM ) == 8 );
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
typedef int64 $10FB_BACKEND;
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
struct $5TPOOL {
	int64 CHUNKS;
	int64 CHUNKSIZE;
	struct $5TLIST* CHUNKTB;
};
__FB_STATIC_ASSERT( sizeof( struct $5TPOOL ) == 24 );
struct $16__FB_ARRAYDIMTB$ {
	int64 ELEMENTS;
	int64 LBOUND;
	int64 UBOUND;
};
__FB_STATIC_ASSERT( sizeof( struct $16__FB_ARRAYDIMTB$ ) == 24 );
struct $8FBARRAY1IPcE {
	char** DATA;
	char** PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1IPcE ) == 72 );
typedef int64 $12FB_MANGLEOPT;
typedef int64 $19FB_CVA_LIST_TYPEDEF;
struct $11TSTRSETITEM {
	FBSTRING S;
	int64 USERDATA;
	struct $8HASHITEM* HASHITEM;
};
__FB_STATIC_ASSERT( sizeof( struct $11TSTRSETITEM ) == 40 );
struct $13FB_MANGLEABBR {
	int64 IDX;
	int64 DTYPE;
	struct $8FBSYMBOL* SUBTYPE;
};
__FB_STATIC_ASSERT( sizeof( struct $13FB_MANGLEABBR ) == 24 );
struct $8FBARRAY1IP8FBSYMBOLE {
	struct $8FBSYMBOL** DATA;
	struct $8FBSYMBOL** PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1IP8FBSYMBOLE ) == 72 );
typedef int64 $13FB_COMPTARGET;
typedef char* (*tmp$45)( void );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
FBSTRING* fb_StrConcatByref( void*, int64, void*, int64, int32 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_UIntToStr( uint32 );
FBSTRING* fb_LongintToStr( int64 );
int64 fb_StrLen( void*, int64 );
FBSTRING* fb_CHR( int32, ... );
static void fb_ctor__symbzmangling( void ) __attribute__(( constructor ));
void* XALLOCATE( int32 );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
int64 FBIS64BIT( void );
int64 FBGETCPUFAMILY( void );
void* POOLNEWITEM( struct $5TPOOL*, int64 );
void POOLDELITEM( struct $5TPOOL*, void* );
void SYMBGETDESCTYPEARRAYDTYPE( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
int64 SYMBPROCCALCSTDCALLSUFFIXN( struct $8FBSYMBOL* );
int64 SYMBHASDTOR( struct $8FBSYMBOL* );
$19FB_CVA_LIST_TYPEDEF SYMBGETVALISTTYPE( int64, struct $8FBSYMBOL* );
char* SYMBUNIQUEID( boolean );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
void SYMBMANGLERESETABBREV( void );
char* HMANGLEBUILTINTYPE( int64, int64* );
void SYMBMANGLETYPE( FBSTRING*, int64, struct $8FBSYMBOL*, $12FB_MANGLEOPT );
void SYMBMANGLEPARAM( FBSTRING*, struct $8FBSYMBOL* );
char* HHEXUINT( uint64 );
char* HREPLACECHAR( char*, int64, int64 );
void FLISTINIT( struct $6TFLIST*, int64, int64 );
void FLISTEND( struct $6TFLIST* );
void* FLISTNEWITEM( struct $6TFLIST* );
void FLISTRESET( struct $6TFLIST* );
void* FLISTGETHEAD( struct $6TFLIST* );
void* FLISTGETNEXT( void* );
static int64 HDOCPPMANGLING( struct $8FBSYMBOL* );
static void HMANGLEPROC( struct $8FBSYMBOL* );
static void HMANGLEVARIABLE( struct $8FBSYMBOL* );
static void HGETPROCPARAMSTYPECODE( FBSTRING*, struct $8FBSYMBOL*, int64 );
static void HMANGLENAMESPACE( FBSTRING*, struct $8FBSYMBOL*, int64, int64 );
static void SYMBSETMANGLEDID( struct $8FBSYMBOL*, FBSTRING* );
static void HMANGLEUDTID( FBSTRING*, struct $8FBSYMBOL* );
static int64 HABBREVFIND( int64, struct $8FBSYMBOL* );
static struct $13FB_MANGLEABBR* HABBREVADD( int64, struct $8FBSYMBOL* );
static void HABBREVGET( FBSTRING*, int64 );
static int64 HADDUNDERSCORE( void );
static char* HGETOPERATORNAME( struct $8FBSYMBOL* );
typedef void (*tmp$39)( void );
typedef int64 (*tmp$40)( void );
typedef int64 $14IR_OPTIONVALUE;
typedef int64 (*tmp$41)( $14IR_OPTIONVALUE );
typedef int64 (*tmp$42)( int64, int64 );
typedef void (*tmp$43)( struct $8FBSYMBOL* );
typedef void (*tmp$44)( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
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
typedef void (*tmp$46)( struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$47)( int64 );
typedef void (*tmp$48)( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
typedef void (*tmp$49)( struct $8FBSYMBOL*, struct $6IRVREG*, int64, int64, struct $6IRVREG* );
typedef void (*tmp$50)( struct $9ASTASMTOK* );
typedef void (*tmp$51)( char* );
typedef int64 $10IR_EMITOPT;
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
typedef int64 $6IR_OPT;
struct $5IRCTX {
	struct $7IR_VTBL VTBL;
	$6IR_OPT OPTIONS;
};
__FB_STATIC_ASSERT( sizeof( struct $5IRCTX ) == 552 );
extern struct $5IRCTX IR$;
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
struct $12FB_MANGLECTX {
	struct $6TFLIST FLIST;
	int64 CNT;
	char TEMPSTR[17];
	int64 UNIQUEIDCOUNT;
	int64 UNIQUELABELCOUNT;
	int64 PROFILELABELCOUNT;
};
__FB_STATIC_ASSERT( sizeof( struct $12FB_MANGLECTX ) == 168 );
static struct $12FB_MANGLECTX CTX$;

void SYMBMANGLEINIT( void )
{
	label$10:;
	FLISTINIT( (struct $6TFLIST*)&CTX$, 96ll, 24ll );
	*(int64*)((uint8*)&CTX$ + 112ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 144ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 152ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 160ll) = 0ll;
	label$11:;
}

void SYMBMANGLEEND( void )
{
	label$12:;
	FLISTEND( (struct $6TFLIST*)&CTX$ );
	label$13:;
}

char* SYMBUNIQUEID( boolean VALIDFBNAME$1 )
{
	int64 TMP$85$1;
	int64 TMP$86$1;
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$14:;
	if( *(int64*)((uint8*)&ENV$ + 208ll) == 1ll) goto label$16;
	TMP$85$1 = (int64)-(*(int64*)((uint8*)&ENV$ + 208ll) == 2ll);
	goto label$20;
	label$16:;
	TMP$85$1 = -1ll;
	label$20:;
	if( TMP$85$1 == 0ll) goto label$17;
	TMP$86$1 = (int64)-((int64)-VALIDFBNAME$1 == 0ll);
	goto label$21;
	label$17:;
	TMP$86$1 = 0ll;
	label$21:;
	if( TMP$86$1 == 0ll) goto label$19;
	{
		FBSTRING TMP$88$2;
		fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)"tmp$", 5ll, 0 );
		FBSTRING* vr$5 = fb_LongintToStr( *(int64*)((uint8*)&CTX$ + 144ll) );
		__builtin_memset( &TMP$88$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$88$2, (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$5, -1ll );
		fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$9, -1ll, 0 );
	}
	goto label$18;
	label$19:;
	{
		FBSTRING TMP$90$2;
		fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)"Lt_", 4ll, 0 );
		char* vr$12 = HHEXUINT( *(uint64*)((uint8*)&CTX$ + 144ll) );
		__builtin_memset( &TMP$90$2, 0, 24ll );
		FBSTRING* vr$16 = fb_StrConcat( &TMP$90$2, (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$12, 0ll );
		fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$16, -1ll, 0 );
	}
	label$18:;
	*(int64*)((uint8*)&CTX$ + 144ll) = *(int64*)((uint8*)&CTX$ + 144ll) + 1ll;
	fb$result$1 = (char*)((uint8*)&CTX$ + 120ll);
	label$15:;
	return fb$result$1;
}

char* SYMBUNIQUELABEL( void )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$22:;
	{
		$10FB_BACKEND TMP$91$2;
		TMP$91$2 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
		if( TMP$91$2 == 1ll) goto label$26;
		label$27:;
		if( TMP$91$2 != 2ll) goto label$25;
		label$26:;
		{
			FBSTRING TMP$93$3;
			fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)"label$", 7ll, 0 );
			FBSTRING* vr$2 = fb_LongintToStr( *(int64*)((uint8*)&CTX$ + 152ll) );
			__builtin_memset( &TMP$93$3, 0, 24ll );
			FBSTRING* vr$6 = fb_StrConcat( &TMP$93$3, (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$2, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$6, -1ll, 0 );
			*(int64*)((uint8*)&CTX$ + 152ll) = *(int64*)((uint8*)&CTX$ + 152ll) + 1ll;
		}
		goto label$24;
		label$25:;
		{
			FBSTRING TMP$96$3;
			if( *(int64*)((uint8*)&ENV$ + 216ll) != 10ll) goto label$30;
			{
				fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)"L_", 3ll, 0 );
			}
			goto label$29;
			label$30:;
			{
				fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)".L_", 4ll, 0 );
			}
			label$29:;
			char* vr$11 = HHEXUINT( *(uint64*)((uint8*)&CTX$ + 144ll) );
			__builtin_memset( &TMP$96$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$96$3, (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$11, 0ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$15, -1ll, 0 );
			*(int64*)((uint8*)&CTX$ + 144ll) = *(int64*)((uint8*)&CTX$ + 144ll) + 1ll;
		}
		label$28:;
		label$24:;
	}
	fb$result$1 = (char*)((uint8*)&CTX$ + 120ll);
	label$23:;
	return fb$result$1;
}

char* SYMBMAKEPROFILELABELNAME( void )
{
	FBSTRING TMP$98$1;
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$31:;
	char* vr$1 = HHEXUINT( *(uint64*)((uint8*)&CTX$ + 160ll) );
	__builtin_memset( &TMP$98$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$98$1, (void*)"LP_", 4ll, (void*)vr$1, 0ll );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 120ll), 17ll, (void*)vr$4, -1ll, 0 );
	*(int64*)((uint8*)&CTX$ + 160ll) = *(int64*)((uint8*)&CTX$ + 160ll) + 1ll;
	fb$result$1 = (char*)((uint8*)&CTX$ + 120ll);
	label$32:;
	return fb$result$1;
}

char* SYMBGETDBGNAME( struct $8FBSYMBOL* SYM$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$33:;
	int64 vr$1 = HDOCPPMANGLING( SYM$1 );
	if( vr$1 == 0ll) goto label$36;
	{
		{
			uint64 TMP$99$3;
			TMP$99$3 = *(uint64*)SYM$1;
			goto label$38;
			label$39:;
			{
				char* RES$4;
				RES$4 = *(char**)((uint8*)SYM$1 + 40ll);
				if( RES$4 != (char*)0ull) goto label$41;
				{
					RES$4 = *(char**)((uint8*)SYM$1 + 32ll);
				}
				label$41:;
				label$40:;
				fb$result$1 = RES$4;
				goto label$34;
			}
			goto label$37;
			label$42:;
			{
				char* vr$5 = SYMBGETMANGLEDNAME( SYM$1 );
				fb$result$1 = vr$5;
				goto label$34;
			}
			goto label$37;
			label$38:;
			static const void* tmp$100[4ll] = {
				&&label$39,
				&&label$39,
				&&label$39,
				&&label$39,
			};
			if( (TMP$99$3 - 8ull) > 3ull ) goto label$42;
			goto *tmp$100[TMP$99$3 - 8ull];
			label$37:;
		}
	}
	label$36:;
	label$35:;
	if( ((int64)-(*(int64*)SYM$1 == 10ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 8192ll) != 0ll)) == 0ll) goto label$44;
	{
		if( *(char**)((uint8*)SYM$1 + 40ll) == (char*)0ull) goto label$46;
		{
			fb$result$1 = *(char**)((uint8*)SYM$1 + 40ll);
			goto label$34;
		}
		label$46:;
		label$45:;
	}
	label$44:;
	label$43:;
	fb$result$1 = *(char**)((uint8*)SYM$1 + 32ll);
	label$34:;
	return fb$result$1;
}

void SYMBSETNAME( struct $8FBSYMBOL* S$1, char* NAME_$1 )
{
	label$47:;
	int64 SLEN$1;
	if( *(char**)((uint8*)S$1 + 32ll) == (char*)0ull) goto label$50;
	{
		POOLDELITEM( (struct $5TPOOL*)((uint8*)&SYMB$ + 197184ll), *(void**)((uint8*)S$1 + 32ll) );
	}
	label$50:;
	label$49:;
	int64 vr$3 = fb_StrLen( (void*)NAME_$1, 0ll );
	SLEN$1 = vr$3;
	if( SLEN$1 != 0ll) goto label$52;
	{
		*(char**)((uint8*)S$1 + 32ll) = (char*)0ull;
	}
	goto label$51;
	label$52:;
	{
		void* vr$7 = POOLNEWITEM( (struct $5TPOOL*)((uint8*)&SYMB$ + 197184ll), SLEN$1 + 1ll );
		*(char**)((uint8*)S$1 + 32ll) = (char*)vr$7;
		fb_StrAssign( *(void**)((uint8*)S$1 + 32ll), 0ll, (void*)NAME_$1, 0ll, 0 );
	}
	label$51:;
	label$48:;
}

char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* SYM$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$65:;
	if( *(char**)((uint8*)SYM$1 + 48ll) == (char*)0ull) goto label$68;
	{
		fb$result$1 = *(char**)((uint8*)SYM$1 + 48ll);
		goto label$66;
	}
	label$68:;
	label$67:;
	{
		uint64 TMP$108$2;
		TMP$108$2 = *(uint64*)SYM$1;
		goto label$70;
		label$71:;
		{
			HMANGLEPROC( SYM$1 );
		}
		goto label$69;
		label$72:;
		{
			FBSTRING MANGLED$3;
			__builtin_memset( &MANGLED$3, 0, 24ll );
			HMANGLENAMESPACE( &MANGLED$3, *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll), -1ll, 0ll );
			HMANGLEUDTID( &MANGLED$3, SYM$1 );
			if( *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll) == (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$74;
			{
				fb_StrConcatAssign( (void*)&MANGLED$3, -1ll, (void*)"E", 2ll, 0 );
			}
			label$74:;
			label$73:;
			SYMBSETMANGLEDID( SYM$1, &MANGLED$3 );
			fb_StrDelete( (FBSTRING*)&MANGLED$3 );
		}
		goto label$69;
		label$75:;
		{
			HMANGLEVARIABLE( SYM$1 );
		}
		goto label$69;
		label$76:;
		{
			fb$result$1 = *(char**)((uint8*)SYM$1 + 40ll);
			goto label$66;
		}
		goto label$69;
		label$70:;
		static const void* tmp$110[14ll] = {
			&&label$75,
			&&label$76,
			&&label$71,
			&&label$76,
			&&label$76,
			&&label$76,
			&&label$76,
			&&label$72,
			&&label$72,
			&&label$72,
			&&label$72,
			&&label$76,
			&&label$76,
			&&label$72,
		};
		if( (TMP$108$2 - 1ull) > 13ull ) goto label$76;
		goto *tmp$110[TMP$108$2 - 1ull];
		label$69:;
	}
	SYMBMANGLERESETABBREV(  );
	{
		$10FB_BACKEND TMP$109$2;
		TMP$109$2 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
		if( TMP$109$2 == 1ll) goto label$79;
		label$80:;
		if( TMP$109$2 != 2ll) goto label$78;
		label$79:;
		{
			if( (*(int64*)((uint8*)&ENV$ + 1448ll) & 524288ll) == 0ll) goto label$82;
			{
				HREPLACECHAR( *(char**)((uint8*)SYM$1 + 48ll), 46ll, 36ll );
			}
			label$82:;
			label$81:;
		}
		label$78:;
		label$77:;
	}
	fb$result$1 = *(char**)((uint8*)SYM$1 + 48ll);
	label$66:;
	return fb$result$1;
}

void SYMBMANGLERESETABBREV( void )
{
	label$83:;
	FLISTRESET( (struct $6TFLIST*)&CTX$ );
	*(int64*)((uint8*)&CTX$ + 112ll) = 0ll;
	label$84:;
}

char* HMANGLEBUILTINTYPE( int64 DTYPE$1, int64* ADD_ABBREV$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$107:;
	*ADD_ABBREV$1 = 0ll;
	if( DTYPE$1 != 17ll) goto label$110;
	{
		*ADD_ABBREV$1 = -1ll;
		fb$result$1 = (char*)"8FBSTRING";
		goto label$108;
	}
	label$110:;
	label$109:;
	int64 vr$3 = FBIS64BIT(  );
	if( (vr$3 & (int64)-((*(int64*)((uint8*)&ENV$ + 592ll) & 1ll) == 0ll)) == 0ll) goto label$112;
	{
		if( (DTYPE$1 & 32505856ll) == 0ll) goto label$114;
		{
			DTYPE$1 = (DTYPE$1 & 32505856ll) >> (20ll & 63ll);
			{
				if( DTYPE$1 != 8ll) goto label$116;
				label$117:;
				{
					fb$result$1 = (char*)"l";
					goto label$108;
				}
				goto label$115;
				label$116:;
				if( DTYPE$1 != 9ll) goto label$118;
				label$119:;
				{
					fb$result$1 = (char*)"m";
					goto label$108;
				}
				label$118:;
				label$115:;
			}
		}
		goto label$113;
		label$114:;
		{
			{
				if( DTYPE$1 != 8ll) goto label$121;
				label$122:;
				{
					*ADD_ABBREV$1 = -1ll;
					fb$result$1 = (char*)"u7INTEGER";
					goto label$108;
				}
				goto label$120;
				label$121:;
				if( DTYPE$1 != 9ll) goto label$123;
				label$124:;
				{
					*ADD_ABBREV$1 = -1ll;
					fb$result$1 = (char*)"u8UINTEGER";
					goto label$108;
				}
				label$123:;
				label$120:;
			}
		}
		label$113:;
	}
	goto label$111;
	label$112:;
	{
		{
			if( DTYPE$1 != 8ll) goto label$126;
			label$127:;
			{
				fb$result$1 = (char*)"l";
				goto label$108;
			}
			goto label$125;
			label$126:;
			if( DTYPE$1 != 9ll) goto label$128;
			label$129:;
			{
				fb$result$1 = (char*)"m";
				goto label$108;
			}
			label$128:;
			label$125:;
		}
	}
	label$111:;
	if( (DTYPE$1 & 32505856ll) == 0ll) goto label$131;
	{
		DTYPE$1 = (DTYPE$1 & 32505856ll) >> (20ll & 63ll);
	}
	label$131:;
	label$130:;
	static char* TYPECODES$1[26] = { (char*)"v", (char*)"b", (char*)"a", (char*)"h", (char*)"c", (char*)"s", (char*)"t", (char*)"w", (char*)0ull, (char*)0ull, (char*)0ull, (char*)"i", (char*)"j", (char*)"x", (char*)"y", (char*)"f", (char*)"d", (char*)0ull, (char*)0ull, (char*)"c", (char*)0ull, (char*)0ull, (char*)0ull, (char*)0ull, (char*)0ull };
	static struct $8FBARRAY1IPcE tmp$119$1 = { (char**)TYPECODES$1, (char**)TYPECODES$1, 208ll, 8ll, 1ll, 49ll, { { 26ll, 0ll, 25ll } } };
	fb$result$1 = *(char**)((int64)(char**)TYPECODES$1 + (DTYPE$1 << (3ll & 63ll)));
	label$108:;
	return fb$result$1;
}

void SYMBMANGLETYPE( FBSTRING* MANGLED$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, $12FB_MANGLEOPT OPTIONS$1 )
{
	int64 TMP$134$1;
	label$132:;
	struct $8FBSYMBOL* NS$1;
	int64 ADD_ABBREV$1;
	int64 IDX$1;
	int64 vr$0 = HABBREVFIND( DTYPE$1, SUBTYPE$1 );
	IDX$1 = vr$0;
	if( IDX$1 == -1ll) goto label$135;
	{
		HABBREVGET( MANGLED$1, IDX$1 );
		goto label$133;
	}
	label$135:;
	label$134:;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$136;
	TMP$134$1 = 24ll;
	goto label$188;
	label$136:;
	TMP$134$1 = DTYPE$1 & 31ll;
	label$188:;
	if( TMP$134$1 != 23ll) goto label$138;
	{
		DTYPE$1 = ((DTYPE$1 & -2147483649ll) & -512ll) | 20ll;
	}
	label$138:;
	label$137:;
	if( (DTYPE$1 & 524288ll) == 0ll) goto label$140;
	{
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"R", 2ll, 0 );
		SYMBMANGLETYPE( MANGLED$1, DTYPE$1 & -524289ll, SUBTYPE$1, (OPTIONS$1 | 4ll) | 1ll );
		HABBREVADD( DTYPE$1, SUBTYPE$1 );
		goto label$133;
	}
	label$140:;
	label$139:;
	if( (DTYPE$1 & 512ll) == 0ll) goto label$142;
	{
		if( (OPTIONS$1 & 1ll) == 0ll) goto label$144;
		{
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"K", 2ll, 0 );
		}
		label$144:;
		label$143:;
		SYMBMANGLETYPE( MANGLED$1, DTYPE$1 & -513ll, SUBTYPE$1, OPTIONS$1 );
		if( (OPTIONS$1 & 1ll) == 0ll) goto label$146;
		{
			HABBREVADD( DTYPE$1, SUBTYPE$1 );
		}
		label$146:;
		label$145:;
		goto label$133;
	}
	label$142:;
	label$141:;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$148;
	{
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"P", 2ll, 0 );
		SYMBMANGLETYPE( MANGLED$1, (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + -32ll)) | (((DTYPE$1 & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (DTYPE$1 & 32505856ll), SUBTYPE$1, (OPTIONS$1 | 2ll) | 1ll );
		HABBREVADD( DTYPE$1, SUBTYPE$1 );
		goto label$133;
	}
	label$148:;
	label$147:;
	if( (DTYPE$1 & 32505856ll) == 0ll) goto label$150;
	{
		if( (DTYPE$1 & 31ll) != 20ll) goto label$152;
		{
			if( ((DTYPE$1 & 32505856ll) >> (20ll & 63ll)) != 19ll) goto label$154;
			{
				{
					$19FB_CVA_LIST_TYPEDEF TMP$138$5;
					$19FB_CVA_LIST_TYPEDEF vr$31 = SYMBGETVALISTTYPE( DTYPE$1, SUBTYPE$1 );
					TMP$138$5 = vr$31;
					if( TMP$138$5 != 3ll) goto label$156;
					label$157:;
					{
						if( (OPTIONS$1 & 6ll) == 0ll) goto label$159;
						{
							fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"A1_", 4ll, 0 );
						}
						goto label$158;
						label$159:;
						{
							fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"P", 2ll, 0 );
						}
						label$158:;
						DTYPE$1 = DTYPE$1 & -32505857ll;
					}
					goto label$155;
					label$156:;
					if( TMP$138$5 == 4ll) goto label$161;
					label$162:;
					if( TMP$138$5 != 5ll) goto label$160;
					label$161:;
					{
						fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"St", 3ll, 0 );
						DTYPE$1 = DTYPE$1 & -32505857ll;
					}
					label$160:;
					label$155:;
				}
			}
			label$154:;
			label$153:;
		}
		label$152:;
		label$151:;
	}
	label$150:;
	label$149:;
	{
		int64 TMP$141$2;
		TMP$141$2 = DTYPE$1 & 31ll;
		if( TMP$141$2 == 20ll) goto label$165;
		label$166:;
		if( TMP$141$2 != 10ll) goto label$164;
		label$165:;
		{
			NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SUBTYPE$1 + 248ll);
			if( NS$1 != (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$168;
			{
				HMANGLEUDTID( MANGLED$1, SUBTYPE$1 );
			}
			goto label$167;
			label$168:;
			{
				if( (OPTIONS$1 & 8ll) != 0ll) goto label$170;
				{
					fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"N", 2ll, 0 );
				}
				label$170:;
				label$169:;
				SYMBMANGLETYPE( MANGLED$1, *(int64*)((uint8*)NS$1 + 56ll), NS$1, 8ll );
				HMANGLEUDTID( MANGLED$1, SUBTYPE$1 );
				if( (OPTIONS$1 & 8ll) != 0ll) goto label$172;
				{
					fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"E", 2ll, 0 );
				}
				label$172:;
				label$171:;
			}
			label$167:;
			HABBREVADD( DTYPE$1, SUBTYPE$1 );
		}
		goto label$163;
		label$164:;
		if( TMP$141$2 != 21ll) goto label$173;
		label$174:;
		{
			if( SUBTYPE$1 != (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$176;
			{
				goto label$133;
			}
			label$176:;
			label$175:;
			NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SUBTYPE$1 + 248ll);
			if( NS$1 == (struct $8FBSYMBOL*)0ull) goto label$178;
			{
				SYMBMANGLETYPE( MANGLED$1, 21ll, NS$1, 0ll );
			}
			label$178:;
			label$177:;
			HMANGLEUDTID( MANGLED$1, SUBTYPE$1 );
			HABBREVADD( DTYPE$1, SUBTYPE$1 );
		}
		goto label$163;
		label$173:;
		if( TMP$141$2 != 22ll) goto label$179;
		label$180:;
		{
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"F", 2ll, 0 );
			if( (*(int64*)((uint8*)SUBTYPE$1 + 16ll) & 2048ll) == 0ll) goto label$182;
			{
				fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"R", 2ll, 0 );
			}
			label$182:;
			label$181:;
			if( (*(int64*)((uint8*)SUBTYPE$1 + 56ll) & 512ll) == 0ll) goto label$184;
			{
				fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"K", 2ll, 0 );
			}
			label$184:;
			label$183:;
			SYMBMANGLETYPE( MANGLED$1, *(int64*)((uint8*)SUBTYPE$1 + 56ll), *(struct $8FBSYMBOL**)((uint8*)SUBTYPE$1 + 64ll), 0ll );
			HGETPROCPARAMSTYPECODE( MANGLED$1, SUBTYPE$1, 0ll );
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"E", 2ll, 0 );
			HABBREVADD( DTYPE$1, SUBTYPE$1 );
		}
		goto label$163;
		label$179:;
		{
			FBSTRING TMP$144$3;
			char* vr$52 = HMANGLEBUILTINTYPE( DTYPE$1, &ADD_ABBREV$1 );
			__builtin_memset( &TMP$144$3, 0, 24ll );
			FBSTRING* vr$55 = fb_StrConcat( &TMP$144$3, (void*)MANGLED$1, -1ll, (void*)vr$52, 0ll );
			fb_StrAssign( (void*)MANGLED$1, -1ll, (void*)vr$55, -1ll, 0 );
			if( ADD_ABBREV$1 == 0ll) goto label$187;
			{
				HABBREVADD( DTYPE$1, SUBTYPE$1 );
			}
			label$187:;
			label$186:;
		}
		label$185:;
		label$163:;
	}
	label$133:;
}

void SYMBMANGLEPARAM( FBSTRING* MANGLED$1, struct $8FBSYMBOL* PARAM$1 )
{
	label$189:;
	{
		uint64 TMP$145$2;
		TMP$145$2 = *(uint64*)((uint8*)PARAM$1 + 96ll);
		goto label$192;
		label$193:;
		{
			SYMBMANGLETYPE( MANGLED$1, *(int64*)((uint8*)PARAM$1 + 56ll), *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 64ll), 0ll );
		}
		goto label$191;
		label$194:;
		{
			SYMBMANGLETYPE( MANGLED$1, *(int64*)((uint8*)PARAM$1 + 56ll) | 524288ll, *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 64ll), 0ll );
		}
		goto label$191;
		label$195:;
		{
			SYMBMANGLETYPE( MANGLED$1, 524308ll, *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 128ll), 1ll );
		}
		goto label$191;
		label$196:;
		{
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"z", 2ll, 0 );
		}
		goto label$191;
		label$192:;
		static const void* tmp$147[4ll] = {
			&&label$193,
			&&label$194,
			&&label$195,
			&&label$196,
		};
		if( (TMP$145$2 - 1ull) > 3ull ) goto label$191;
		goto *tmp$147[TMP$145$2 - 1ull];
		label$191:;
	}
	label$190:;
}

__attribute__(( constructor )) static void fb_ctor__symbzmangling( void )
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

static void SYMBSETMANGLEDID( struct $8FBSYMBOL* SYM$1, FBSTRING* MANGLED$1 )
{
	label$53:;
	int64 vr$0 = fb_StrLen( (void*)MANGLED$1, -1ll );
	void* vr$3 = XALLOCATE( (int32)(vr$0 + 1ll) );
	*(char**)((uint8*)SYM$1 + 48ll) = (char*)vr$3;
	fb_StrAssign( *(void**)((uint8*)SYM$1 + 48ll), 0ll, (void*)MANGLED$1, -1ll, 0 );
	label$54:;
}

static void HMANGLEUDTID( FBSTRING* MANGLED$1, struct $8FBSYMBOL* SYM$1 )
{
	label$55:;
	int64 ARRAYDTYPE$1;
	struct $8FBSYMBOL* ARRAYSUBTYPE$1;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 128ll) == 0ll) goto label$58;
	{
		static int64 LOCALUDTCOUNTER$2 = 1ll;
		FBSTRING TMP$2;
		__builtin_memset( &TMP$2, 0, 24ll );
		if( *(char**)((uint8*)SYM$1 + 40ll) == (char*)0ull) goto label$60;
		{
			fb_StrAssign( (void*)&TMP$2, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
		}
		goto label$59;
		label$60:;
		{
			fb_StrAssign( (void*)&TMP$2, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
		}
		label$59:;
		fb_StrConcatAssign( (void*)&TMP$2, -1ll, (void*)"$", 2ll, 0 );
		FBSTRING* vr$9 = fb_LongintToStr( LOCALUDTCOUNTER$2 );
		fb_StrConcatAssign( (void*)&TMP$2, -1ll, (void*)vr$9, -1ll, 0 );
		int64 vr$12 = fb_StrLen( (void*)&TMP$2, -1ll );
		FBSTRING* vr$13 = fb_LongintToStr( vr$12 );
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$13, -1ll, 0 );
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)&TMP$2, -1ll, 0 );
		LOCALUDTCOUNTER$2 = LOCALUDTCOUNTER$2 + 1ll;
		fb_StrDelete( (FBSTRING*)&TMP$2 );
	}
	goto label$57;
	label$58:;
	{
		if( *(char**)((uint8*)SYM$1 + 40ll) == (char*)0ull) goto label$62;
		{
			FBSTRING TMP$102$3;
			FBSTRING TMP$103$3;
			int64 vr$19 = fb_StrLen( *(void**)((uint8*)SYM$1 + 40ll), 0ll );
			FBSTRING* vr$20 = fb_LongintToStr( vr$19 );
			__builtin_memset( &TMP$102$3, 0, 24ll );
			FBSTRING* vr$23 = fb_StrConcat( &TMP$102$3, (void*)MANGLED$1, -1ll, (void*)vr$20, -1ll );
			fb_StrAssign( (void*)MANGLED$1, -1ll, (void*)vr$23, -1ll, 0 );
			__builtin_memset( &TMP$103$3, 0, 24ll );
			FBSTRING* vr$27 = fb_StrConcat( &TMP$103$3, (void*)MANGLED$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll );
			fb_StrAssign( (void*)MANGLED$1, -1ll, (void*)vr$27, -1ll, 0 );
		}
		goto label$61;
		label$62:;
		{
			FBSTRING TMP$104$3;
			FBSTRING TMP$105$3;
			int64 vr$29 = fb_StrLen( *(void**)((uint8*)SYM$1 + 32ll), 0ll );
			FBSTRING* vr$30 = fb_LongintToStr( vr$29 );
			__builtin_memset( &TMP$104$3, 0, 24ll );
			FBSTRING* vr$33 = fb_StrConcat( &TMP$104$3, (void*)MANGLED$1, -1ll, (void*)vr$30, -1ll );
			fb_StrAssign( (void*)MANGLED$1, -1ll, (void*)vr$33, -1ll, 0 );
			__builtin_memset( &TMP$105$3, 0, 24ll );
			FBSTRING* vr$37 = fb_StrConcat( &TMP$105$3, (void*)MANGLED$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll );
			fb_StrAssign( (void*)MANGLED$1, -1ll, (void*)vr$37, -1ll, 0 );
		}
		label$61:;
	}
	label$57:;
	if( ((int64)-(*(int64*)SYM$1 == 10ll) & (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 8192ll) != 0ll)) == 0ll) goto label$64;
	{
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"I", 2ll, 0 );
		SYMBGETDESCTYPEARRAYDTYPE( SYM$1, &ARRAYDTYPE$1, &ARRAYSUBTYPE$1 );
		SYMBMANGLETYPE( MANGLED$1, ARRAYDTYPE$1, ARRAYSUBTYPE$1, 1ll );
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"E", 2ll, 0 );
	}
	label$64:;
	label$63:;
	label$56:;
}

static int64 HABBREVFIND( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$85:;
	struct $13FB_MANGLEABBR* N$1;
	if( *(int64*)((uint8*)&CTX$ + 112ll) != 0ll) goto label$88;
	{
		fb$result$1 = -1ll;
		goto label$86;
	}
	label$88:;
	label$87:;
	void* vr$2 = FLISTGETHEAD( (struct $6TFLIST*)&CTX$ );
	N$1 = (struct $13FB_MANGLEABBR*)vr$2;
	label$89:;
	if( N$1 == (struct $13FB_MANGLEABBR*)0ull) goto label$90;
	{
		if( *(struct $8FBSYMBOL**)((uint8*)N$1 + 16ll) != SUBTYPE$1) goto label$92;
		{
			if( *(int64*)((uint8*)N$1 + 8ll) != DTYPE$1) goto label$94;
			{
				fb$result$1 = *(int64*)N$1;
				goto label$86;
			}
			label$94:;
			label$93:;
		}
		label$92:;
		label$91:;
		void* vr$6 = FLISTGETNEXT( (void*)N$1 );
		N$1 = (struct $13FB_MANGLEABBR*)vr$6;
	}
	goto label$89;
	label$90:;
	fb$result$1 = -1ll;
	label$86:;
	return fb$result$1;
}

static struct $13FB_MANGLEABBR* HABBREVADD( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	struct $13FB_MANGLEABBR* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$95:;
	struct $13FB_MANGLEABBR* N$1;
	void* vr$2 = FLISTNEWITEM( (struct $6TFLIST*)&CTX$ );
	N$1 = (struct $13FB_MANGLEABBR*)vr$2;
	*(int64*)N$1 = *(int64*)((uint8*)&CTX$ + 112ll);
	*(int64*)((uint8*)N$1 + 8ll) = DTYPE$1;
	*(struct $8FBSYMBOL**)((uint8*)N$1 + 16ll) = SUBTYPE$1;
	*(int64*)((uint8*)&CTX$ + 112ll) = *(int64*)((uint8*)&CTX$ + 112ll) + 1ll;
	fb$result$1 = N$1;
	label$96:;
	return fb$result$1;
}

static void HABBREVGET( FBSTRING* MANGLED$1, int64 IDX$1 )
{
	label$97:;
	fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"S", 2ll, 0 );
	if( IDX$1 <= 0ll) goto label$100;
	{
		if( IDX$1 > 10ll) goto label$102;
		{
			FBSTRING* vr$2 = fb_CHR( 1, (int64)((uint64)(IDX$1 + -1ll) + 48ull) );
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$2, -1ll, 0 );
		}
		goto label$101;
		label$102:;
		if( IDX$1 > 33ll) goto label$103;
		{
			FBSTRING* vr$5 = fb_CHR( 1, (int64)((uint64)(IDX$1 + -11ll) + 65ull) );
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$5, -1ll, 0 );
		}
		goto label$101;
		label$103:;
		{
			FBSTRING* vr$7 = fb_CHR( 1, IDX$1 / 33ll );
			fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$7, -1ll, 0 );
			IDX$1 = IDX$1 % 33ll;
			if( IDX$1 > 10ll) goto label$105;
			{
				FBSTRING* vr$11 = fb_CHR( 1, (int64)((uint64)(IDX$1 + -1ll) + 48ull) );
				fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$11, -1ll, 0 );
			}
			goto label$104;
			label$105:;
			if( IDX$1 > 33ll) goto label$106;
			{
				FBSTRING* vr$14 = fb_CHR( 1, (int64)((uint64)(IDX$1 + -11ll) + 65ull) );
				fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)vr$14, -1ll, 0 );
			}
			label$106:;
			label$104:;
		}
		label$101:;
	}
	label$100:;
	label$99:;
	fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"_", 2ll, 0 );
	label$98:;
}

static int64 HADDUNDERSCORE( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$197:;
	{
		$10FB_BACKEND TMP$148$2;
		TMP$148$2 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
		if( TMP$148$2 == 1ll) goto label$201;
		label$202:;
		if( TMP$148$2 != 2ll) goto label$200;
		label$201:;
		{
			fb$result$1 = 0ll;
		}
		goto label$199;
		label$200:;
		{
			fb$result$1 = *(int64*)((uint8*)&ENV$ + 608ll);
		}
		label$203:;
		label$199:;
	}
	label$198:;
	return fb$result$1;
}

static int64 HDOCPPMANGLING( struct $8FBSYMBOL* SYM$1 )
{
	int64 TMP$149$1;
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$204:;
	if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 4ll) goto label$207;
	{
		fb$result$1 = -1ll;
		goto label$205;
	}
	label$207:;
	label$206:;
	if( (*(int64*)((uint8*)SYM$1 + 24ll) & 2080ll) == 0ll) goto label$209;
	{
		fb$result$1 = 0ll;
		goto label$205;
	}
	label$209:;
	label$208:;
	if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 6ll) goto label$210;
	TMP$149$1 = (int64)-(*(char**)((uint8*)SYM$1 + 40ll) != (char*)0ull);
	goto label$465;
	label$210:;
	TMP$149$1 = 0ll;
	label$465:;
	if( TMP$149$1 == 0ll) goto label$212;
	{
		{
			$10FB_BACKEND TMP$150$3;
			TMP$150$3 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
			if( TMP$150$3 == 1ll) goto label$215;
			label$216:;
			if( TMP$150$3 != 2ll) goto label$214;
			label$215:;
			{
			}
			goto label$213;
			label$214:;
			{
				if( (*(int64*)((uint8*)SYM$1 + 8ll) & 8388608ll) != 0ll) goto label$219;
				{
					fb$result$1 = 0ll;
					goto label$205;
				}
				label$219:;
				label$218:;
			}
			label$217:;
			label$213:;
		}
	}
	label$212:;
	label$211:;
	if( *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll) == (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$221;
	{
		fb$result$1 = -1ll;
		goto label$205;
	}
	label$221:;
	label$220:;
	if( *(int64*)SYM$1 != 3ll) goto label$223;
	{
		if( (*(int64*)((uint8*)SYM$1 + 16ll) & 1ll) == 0ll) goto label$225;
		{
			fb$result$1 = -1ll;
			goto label$205;
		}
		label$225:;
		label$224:;
	}
	label$223:;
	label$222:;
	fb$result$1 = 0ll;
	label$205:;
	return fb$result$1;
}

static void HMANGLENAMESPACE( FBSTRING* MANGLED$1, struct $8FBSYMBOL* NS$1, int64 DOHASHING$1, int64 ISCONST$1 )
{
	label$226:;
	static struct $8FBSYMBOL* NSSTK$1[64];
	static struct $8FBARRAY1IP8FBSYMBOLE tmp$151$1 = { (struct $8FBSYMBOL**)NSSTK$1, (struct $8FBSYMBOL**)NSSTK$1, 512ll, 8ll, 1ll, 49ll, { { 64ll, 0ll, 63ll } } };
	int64 TOS$1;
	if( NS$1 != (struct $8FBSYMBOL*)0ull) goto label$229;
	{
		goto label$227;
	}
	label$229:;
	label$228:;
	if( NS$1 != (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$231;
	{
		goto label$227;
	}
	label$231:;
	label$230:;
	if( DOHASHING$1 == 0ll) goto label$233;
	{
		FBSTRING UNUSED$2;
		__builtin_memset( &UNUSED$2, 0, 24ll );
		SYMBMANGLETYPE( &UNUSED$2, *(int64*)((uint8*)NS$1 + 56ll), NS$1, 0ll );
		fb_StrDelete( (FBSTRING*)&UNUSED$2 );
	}
	label$233:;
	label$232:;
	TOS$1 = -1ll;
	label$234:;
	{
		TOS$1 = TOS$1 + 1ll;
		*(struct $8FBSYMBOL**)((int64)(struct $8FBSYMBOL**)NSSTK$1 + (TOS$1 << (3ll & 63ll))) = NS$1;
		NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)NS$1 + 248ll);
	}
	label$236:;
	if( NS$1 != (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$234;
	label$235:;
	fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"N", 2ll, 0 );
	if( ISCONST$1 == 0ll) goto label$238;
	{
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"K", 2ll, 0 );
	}
	label$238:;
	label$237:;
	label$239:;
	{
		NS$1 = *(struct $8FBSYMBOL**)((int64)(struct $8FBSYMBOL**)NSSTK$1 + (TOS$1 << (3ll & 63ll)));
		HMANGLEUDTID( MANGLED$1, NS$1 );
		TOS$1 = TOS$1 + -1ll;
	}
	label$241:;
	if( TOS$1 >= 0ll) goto label$239;
	label$240:;
	label$227:;
}

static void HMANGLEVARIABLE( struct $8FBSYMBOL* SYM$1 )
{
	label$242:;
	static FBSTRING ID$1;
	static int64 VARCOUNTER$1;
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	char* P$1;
	int64 DOCPP$1;
	int64 ISGLOBAL$1;
	if( (int64)*(uint16*)((uint8*)SYM$1 + 72ll) <= 0ll) goto label$245;
	{
		DOCPP$1 = 0ll;
	}
	goto label$244;
	label$245:;
	{
		int64 vr$3 = HDOCPPMANGLING( SYM$1 );
		DOCPP$1 = vr$3;
	}
	label$244:;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 59ll) == 0ll) goto label$247;
	{
		if( *(int64*)((uint8*)&ENV$ + 208ll) != 3ll) goto label$249;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"@", 2ll, 0 );
		}
		label$249:;
		label$248:;
		int64 vr$7 = HADDUNDERSCORE(  );
		if( vr$7 == 0ll) goto label$251;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_", 2ll, 0 );
		}
		label$251:;
		label$250:;
		{
			$13FB_COMPTARGET TMP$153$3;
			TMP$153$3 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
			if( TMP$153$3 == 0ll) goto label$254;
			label$255:;
			if( TMP$153$3 != 1ll) goto label$253;
			label$254:;
			{
				if( (*(int64*)((uint8*)SYM$1 + 8ll) & 512ll) == 0ll) goto label$257;
				{
					fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_imp__", 7ll, 0 );
				}
				label$257:;
				label$256:;
			}
			label$253:;
			label$252:;
		}
		if( DOCPP$1 == 0ll) goto label$259;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_Z", 3ll, 0 );
			if( (*(int64*)((uint8*)SYM$1 + 24ll) & 256ll) == 0ll) goto label$261;
			{
				fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"TS", 3ll, 0 );
			}
			goto label$260;
			label$261:;
			if( (*(int64*)((uint8*)SYM$1 + 24ll) & 1024ll) == 0ll) goto label$262;
			{
				fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"TV", 3ll, 0 );
			}
			label$262:;
			label$260:;
		}
		label$259:;
		label$258:;
	}
	goto label$246;
	label$247:;
	{
		if( *(int64*)((uint8*)&ENV$ + 208ll) != 3ll) goto label$264;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"%", 2ll, 0 );
		}
		label$264:;
		label$263:;
	}
	label$246:;
	if( DOCPP$1 == 0ll) goto label$266;
	{
		HMANGLENAMESPACE( &MANGLED$1, *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll), 0ll, 0ll );
	}
	label$266:;
	label$265:;
	if( (*(int64*)((uint8*)SYM$1 + 24ll) & 1280ll) == 0ll) goto label$268;
	{
		fb_StrAssign( (void*)&ID$1, -1ll, (void*)"", 1ll, 0 );
	}
	goto label$267;
	label$268:;
	if( (*(int64*)((uint8*)SYM$1 + 24ll) & 512ll) == 0ll) goto label$269;
	{
		fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
	}
	goto label$267;
	label$269:;
	{
		ISGLOBAL$1 = (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 57ll) != 0ll);
		if( (ISGLOBAL$1 | DOCPP$1) == 0ll) goto label$271;
		{
			if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 0ll) goto label$273;
			{
				fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
				{
					$10FB_BACKEND TMP$159$5;
					TMP$159$5 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
					if( TMP$159$5 == 1ll) goto label$276;
					label$277:;
					if( TMP$159$5 == 2ll) goto label$276;
					label$278:;
					if( TMP$159$5 != 4ll) goto label$275;
					label$276:;
					{
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)"$", 2ll, 0 );
					}
					label$275:;
					label$274:;
				}
			}
			goto label$272;
			label$273:;
			{
				fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
			}
			label$272:;
			if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1048576ll) == 0ll) goto label$280;
			{
				int64 TMP$160$4;
				FBSTRING TMP$161$4;
				TMP$160$4 = 0ll;
				char* vr$41 = HMANGLEBUILTINTYPE( *(int64*)((uint8*)SYM$1 + 56ll) & 511ll, &TMP$160$4 );
				__builtin_memset( &TMP$161$4, 0, 24ll );
				FBSTRING* vr$44 = fb_StrConcat( &TMP$161$4, (void*)&ID$1, -1ll, (void*)vr$41, 0ll );
				fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$44, -1ll, 0 );
				{
					$10FB_BACKEND TMP$162$5;
					TMP$162$5 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
					if( TMP$162$5 == 1ll) goto label$283;
					label$284:;
					if( TMP$162$5 != 2ll) goto label$282;
					label$283:;
					{
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)"$", 2ll, 0 );
					}
					label$282:;
					label$281:;
				}
			}
			label$280:;
			label$279:;
		}
		goto label$270;
		label$271:;
		{
			{
				$10FB_BACKEND TMP$163$4;
				TMP$163$4 = *($10FB_BACKEND*)((uint8*)&ENV$ + 208ll);
				if( TMP$163$4 == 1ll) goto label$287;
				label$288:;
				if( TMP$163$4 != 2ll) goto label$286;
				label$287:;
				{
					int64 vr$48 = SYMBHASDTOR( SYM$1 );
					if( ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) != 0ll) & vr$48) == 0ll) goto label$290;
					{
						char* vr$50 = SYMBUNIQUEID( (boolean)0ll );
						fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$50, 0ll, 0 );
					}
					goto label$289;
					label$290:;
					{
						if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 0ll) goto label$292;
						{
							FBSTRING TMP$166$7;
							fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
							fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)"$", 2ll, 0 );
							if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1048576ll) == 0ll) goto label$294;
							{
								int64 TMP$164$8;
								FBSTRING TMP$165$8;
								TMP$164$8 = 0ll;
								char* vr$59 = HMANGLEBUILTINTYPE( *(int64*)((uint8*)SYM$1 + 56ll) & 511ll, &TMP$164$8 );
								__builtin_memset( &TMP$165$8, 0, 24ll );
								FBSTRING* vr$62 = fb_StrConcat( &TMP$165$8, (void*)&ID$1, -1ll, (void*)vr$59, 0ll );
								fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$62, -1ll, 0 );
								fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)"$", 2ll, 0 );
							}
							label$294:;
							label$293:;
							FBSTRING* vr$65 = fb_UIntToStr( (uint32)*(uint16*)((uint8*)SYM$1 + 72ll) );
							__builtin_memset( &TMP$166$7, 0, 24ll );
							FBSTRING* vr$68 = fb_StrConcat( &TMP$166$7, (void*)&ID$1, -1ll, (void*)vr$65, -1ll );
							fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$68, -1ll, 0 );
						}
						goto label$291;
						label$292:;
						{
							fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
						}
						label$291:;
					}
					label$289:;
				}
				goto label$285;
				label$286:;
				if( TMP$163$4 != 3ll) goto label$295;
				label$296:;
				{
					if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 0ll) goto label$298;
					{
						fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
						if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1048576ll) == 0ll) goto label$300;
						{
							int64 TMP$167$7;
							FBSTRING TMP$168$7;
							TMP$167$7 = 0ll;
							char* vr$78 = HMANGLEBUILTINTYPE( *(int64*)((uint8*)SYM$1 + 56ll) & 511ll, &TMP$167$7 );
							__builtin_memset( &TMP$168$7, 0, 24ll );
							FBSTRING* vr$81 = fb_StrConcat( &TMP$168$7, (void*)&ID$1, -1ll, (void*)vr$78, 0ll );
							fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$81, -1ll, 0 );
						}
						label$300:;
						label$299:;
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)".", 2ll, 0 );
						FBSTRING* vr$82 = fb_LongintToStr( VARCOUNTER$1 );
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)vr$82, -1ll, 0 );
						VARCOUNTER$1 = VARCOUNTER$1 + 1ll;
					}
					goto label$297;
					label$298:;
					{
						fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
					}
					label$297:;
				}
				goto label$285;
				label$295:;
				if( TMP$163$4 != 4ll) goto label$301;
				label$302:;
				{
					if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 0ll) goto label$304;
					{
						fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
						if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1048576ll) == 0ll) goto label$306;
						{
							int64 TMP$169$7;
							FBSTRING TMP$170$7;
							TMP$169$7 = 0ll;
							char* vr$93 = HMANGLEBUILTINTYPE( *(int64*)((uint8*)SYM$1 + 56ll) & 511ll, &TMP$169$7 );
							__builtin_memset( &TMP$170$7, 0, 24ll );
							FBSTRING* vr$96 = fb_StrConcat( &TMP$170$7, (void*)&ID$1, -1ll, (void*)vr$93, 0ll );
							fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$96, -1ll, 0 );
						}
						label$306:;
						label$305:;
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)".", 2ll, 0 );
						FBSTRING* vr$97 = fb_LongintToStr( VARCOUNTER$1 );
						fb_StrConcatAssign( (void*)&ID$1, -1ll, (void*)vr$97, -1ll, 0 );
						VARCOUNTER$1 = VARCOUNTER$1 + 1ll;
					}
					goto label$303;
					label$304:;
					if( (*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) == 0ll) goto label$307;
					{
						char* vr$101 = SYMBUNIQUEID( (boolean)0ll );
						fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$101, 0ll, 0 );
					}
					goto label$303;
					label$307:;
					{
						fb_StrAssign( (void*)&ID$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
					}
					label$303:;
				}
				goto label$285;
				label$301:;
				{
					if( (*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) == 0ll) goto label$310;
					{
						char* vr$105 = SYMBUNIQUEID( (boolean)0ll );
						fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$105, 0ll, 0 );
					}
					goto label$309;
					label$310:;
					{
						char* vr$106 = (*(tmp$45*)((uint8*)&IR$ + 80ll))(  );
						fb_StrAssign( (void*)&ID$1, -1ll, (void*)vr$106, 0ll, 0 );
					}
					label$309:;
				}
				label$308:;
				label$285:;
			}
		}
		label$270:;
	}
	label$267:;
	int64 vr$107 = fb_StrLen( (void*)&ID$1, -1ll );
	if( vr$107 <= 0ll) goto label$312;
	{
		if( DOCPP$1 == 0ll) goto label$314;
		{
			int64 vr$108 = fb_StrLen( (void*)&ID$1, -1ll );
			FBSTRING* vr$109 = fb_LongintToStr( vr$108 );
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)vr$109, -1ll, 0 );
		}
		label$314:;
		label$313:;
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)&ID$1, -1ll, 0 );
	}
	label$312:;
	label$311:;
	if( DOCPP$1 == 0ll) goto label$316;
	{
		if( *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll) == (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$318;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"E", 2ll, 0 );
		}
		label$318:;
		label$317:;
	}
	label$316:;
	label$315:;
	SYMBSETMANGLEDID( SYM$1, &MANGLED$1 );
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	label$243:;
}

static void HGETPROCPARAMSTYPECODE( FBSTRING* MANGLED$1, struct $8FBSYMBOL* SYM$1, int64 IS_REAL_PROC$1 )
{
	label$319:;
	struct $8FBSYMBOL* PARAM$1;
	PARAM$1 = *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 136ll);
	if( PARAM$1 == (struct $8FBSYMBOL*)0ull) goto label$322;
	{
		if( (IS_REAL_PROC$1 & (int64)-((*(int64*)((uint8*)PARAM$1 + 8ll) & 524288ll) != 0ll)) == 0ll) goto label$324;
		{
			PARAM$1 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 312ll);
		}
		label$324:;
		label$323:;
	}
	label$322:;
	label$321:;
	if( PARAM$1 != (struct $8FBSYMBOL*)0ull) goto label$326;
	{
		fb_StrConcatByref( (void*)MANGLED$1, -1ll, (void*)"v", 2ll, 0 );
		goto label$320;
	}
	label$326:;
	label$325:;
	label$327:;
	{
		SYMBMANGLEPARAM( MANGLED$1, PARAM$1 );
		PARAM$1 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 312ll);
	}
	label$329:;
	if( PARAM$1 != (struct $8FBSYMBOL*)0ull) goto label$327;
	label$328:;
	label$320:;
}

static char* HGETOPERATORNAME( struct $8FBSYMBOL* PROC$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$330:;
	{
		uint64 TMP$171$2;
		TMP$171$2 = *(uint64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 80ll);
		goto label$333;
		label$334:;
		{
			fb$result$1 = (char*)"aS";
		}
		goto label$332;
		label$335:;
		{
			fb$result$1 = (char*)"pl";
		}
		goto label$332;
		label$336:;
		{
			fb$result$1 = (char*)"pL";
		}
		goto label$332;
		label$337:;
		{
			fb$result$1 = (char*)"mi";
		}
		goto label$332;
		label$338:;
		{
			fb$result$1 = (char*)"mI";
		}
		goto label$332;
		label$339:;
		{
			fb$result$1 = (char*)"ml";
		}
		goto label$332;
		label$340:;
		{
			fb$result$1 = (char*)"mL";
		}
		goto label$332;
		label$341:;
		{
			fb$result$1 = (char*)"dv";
		}
		goto label$332;
		label$342:;
		{
			fb$result$1 = (char*)"dV";
		}
		goto label$332;
		label$343:;
		{
			fb$result$1 = (char*)"v24idiv";
		}
		goto label$332;
		label$344:;
		{
			fb$result$1 = (char*)"v28selfidiv";
		}
		goto label$332;
		label$345:;
		{
			fb$result$1 = (char*)"rm";
		}
		goto label$332;
		label$346:;
		{
			fb$result$1 = (char*)"rM";
		}
		goto label$332;
		label$347:;
		{
			fb$result$1 = (char*)"an";
		}
		goto label$332;
		label$348:;
		{
			fb$result$1 = (char*)"aN";
		}
		goto label$332;
		label$349:;
		{
			fb$result$1 = (char*)"or";
		}
		goto label$332;
		label$350:;
		{
			fb$result$1 = (char*)"oR";
		}
		goto label$332;
		label$351:;
		{
			fb$result$1 = (char*)"aa";
		}
		goto label$332;
		label$352:;
		{
			fb$result$1 = (char*)"aA";
		}
		goto label$332;
		label$353:;
		{
			fb$result$1 = (char*)"oo";
		}
		goto label$332;
		label$354:;
		{
			fb$result$1 = (char*)"oO";
		}
		goto label$332;
		label$355:;
		{
			fb$result$1 = (char*)"eo";
		}
		goto label$332;
		label$356:;
		{
			fb$result$1 = (char*)"eO";
		}
		goto label$332;
		label$357:;
		{
			fb$result$1 = (char*)"v23eqv";
		}
		goto label$332;
		label$358:;
		{
			fb$result$1 = (char*)"v27selfeqv";
		}
		goto label$332;
		label$359:;
		{
			fb$result$1 = (char*)"v23imp";
		}
		goto label$332;
		label$360:;
		{
			fb$result$1 = (char*)"v27selfimp";
		}
		goto label$332;
		label$361:;
		{
			fb$result$1 = (char*)"ls";
		}
		goto label$332;
		label$362:;
		{
			fb$result$1 = (char*)"lS";
		}
		goto label$332;
		label$363:;
		{
			fb$result$1 = (char*)"rs";
		}
		goto label$332;
		label$364:;
		{
			fb$result$1 = (char*)"rS";
		}
		goto label$332;
		label$365:;
		{
			fb$result$1 = (char*)"v23pow";
		}
		goto label$332;
		label$366:;
		{
			fb$result$1 = (char*)"v27selfpow";
		}
		goto label$332;
		label$367:;
		{
			fb$result$1 = (char*)"v23cat";
		}
		goto label$332;
		label$368:;
		{
			fb$result$1 = (char*)"v27selfcat";
		}
		goto label$332;
		label$369:;
		{
			fb$result$1 = (char*)"eq";
		}
		goto label$332;
		label$370:;
		{
			fb$result$1 = (char*)"gt";
		}
		goto label$332;
		label$371:;
		{
			fb$result$1 = (char*)"lt";
		}
		goto label$332;
		label$372:;
		{
			fb$result$1 = (char*)"ne";
		}
		goto label$332;
		label$373:;
		{
			fb$result$1 = (char*)"ge";
		}
		goto label$332;
		label$374:;
		{
			fb$result$1 = (char*)"le";
		}
		goto label$332;
		label$375:;
		{
			fb$result$1 = (char*)"co";
		}
		goto label$332;
		label$376:;
		{
			fb$result$1 = (char*)"ng";
		}
		goto label$332;
		label$377:;
		{
			fb$result$1 = (char*)"ps";
		}
		goto label$332;
		label$378:;
		{
			fb$result$1 = (char*)"v13abs";
		}
		goto label$332;
		label$379:;
		{
			fb$result$1 = (char*)"v13fix";
		}
		goto label$332;
		label$380:;
		{
			fb$result$1 = (char*)"v14frac";
		}
		goto label$332;
		label$381:;
		{
			fb$result$1 = (char*)"v13len";
		}
		goto label$332;
		label$382:;
		{
			fb$result$1 = (char*)"v13sgn";
		}
		goto label$332;
		label$383:;
		{
			fb$result$1 = (char*)"v13int";
		}
		goto label$332;
		label$384:;
		{
			fb$result$1 = (char*)"v13exp";
		}
		goto label$332;
		label$385:;
		{
			fb$result$1 = (char*)"v13log";
		}
		goto label$332;
		label$386:;
		{
			fb$result$1 = (char*)"v13sin";
		}
		goto label$332;
		label$387:;
		{
			fb$result$1 = (char*)"v14asin";
		}
		goto label$332;
		label$388:;
		{
			fb$result$1 = (char*)"v13cos";
		}
		goto label$332;
		label$389:;
		{
			fb$result$1 = (char*)"v14acos";
		}
		goto label$332;
		label$390:;
		{
			fb$result$1 = (char*)"v13tan";
		}
		goto label$332;
		label$391:;
		{
			fb$result$1 = (char*)"v13atn";
		}
		goto label$332;
		label$392:;
		{
			fb$result$1 = (char*)"v13sqr";
		}
		goto label$332;
		label$393:;
		{
			fb$result$1 = (char*)"nw";
		}
		goto label$332;
		label$394:;
		{
			fb$result$1 = (char*)"na";
		}
		goto label$332;
		label$395:;
		{
			fb$result$1 = (char*)"dl";
		}
		goto label$332;
		label$396:;
		{
			fb$result$1 = (char*)"da";
		}
		goto label$332;
		label$397:;
		{
			fb$result$1 = (char*)"de";
		}
		goto label$332;
		label$398:;
		{
			fb$result$1 = (char*)"pt";
		}
		goto label$332;
		label$399:;
		{
			fb$result$1 = (char*)"ix";
		}
		goto label$332;
		label$400:;
		{
			fb$result$1 = (char*)"ad";
		}
		goto label$332;
		label$401:;
		{
			if( (int64)*(int16*)((uint8*)PROC$1 + 120ll) != 2ll) goto label$403;
			{
				fb$result$1 = (char*)"v13for";
			}
			goto label$402;
			label$403:;
			{
				fb$result$1 = (char*)"v03for";
			}
			label$402:;
		}
		goto label$332;
		label$404:;
		{
			if( (int64)*(int16*)((uint8*)PROC$1 + 120ll) != 2ll) goto label$406;
			{
				fb$result$1 = (char*)"v14step";
			}
			goto label$405;
			label$406:;
			{
				fb$result$1 = (char*)"v04step";
			}
			label$405:;
		}
		goto label$332;
		label$407:;
		{
			if( (int64)*(int16*)((uint8*)PROC$1 + 120ll) != 3ll) goto label$409;
			{
				fb$result$1 = (char*)"v24next";
			}
			goto label$408;
			label$409:;
			{
				fb$result$1 = (char*)"v14next";
			}
			label$408:;
		}
		goto label$332;
		label$333:;
		static const void* tmp$259[83ll] = {
			&&label$334,
			&&label$336,
			&&label$338,
			&&label$340,
			&&label$342,
			&&label$344,
			&&label$346,
			&&label$348,
			&&label$350,
			&&label$352,
			&&label$354,
			&&label$356,
			&&label$358,
			&&label$360,
			&&label$362,
			&&label$364,
			&&label$366,
			&&label$368,
			&&label$393,
			&&label$394,
			&&label$395,
			&&label$396,
			&&label$400,
			&&label$399,
			&&label$401,
			&&label$404,
			&&label$407,
			&&label$332,
			&&label$335,
			&&label$337,
			&&label$339,
			&&label$341,
			&&label$343,
			&&label$345,
			&&label$347,
			&&label$349,
			&&label$351,
			&&label$353,
			&&label$355,
			&&label$357,
			&&label$359,
			&&label$361,
			&&label$363,
			&&label$365,
			&&label$367,
			&&label$369,
			&&label$370,
			&&label$371,
			&&label$372,
			&&label$373,
			&&label$374,
			&&label$332,
			&&label$375,
			&&label$332,
			&&label$377,
			&&label$376,
			&&label$332,
			&&label$378,
			&&label$382,
			&&label$386,
			&&label$387,
			&&label$388,
			&&label$389,
			&&label$390,
			&&label$391,
			&&label$332,
			&&label$392,
			&&label$332,
			&&label$332,
			&&label$385,
			&&label$384,
			&&label$383,
			&&label$379,
			&&label$380,
			&&label$381,
			&&label$332,
			&&label$332,
			&&label$397,
			&&label$398,
			&&label$393,
			&&label$394,
			&&label$395,
			&&label$396,
		};
		if( TMP$171$2 > 82ull ) goto label$332;
		goto *tmp$259[TMP$171$2 - 0ull];
		label$332:;
	}
	label$331:;
	return fb$result$1;
}

static void HMANGLEPROC( struct $8FBSYMBOL* SYM$1 )
{
	label$410:;
	FBSTRING MANGLED$1;
	__builtin_memset( &MANGLED$1, 0, 24ll );
	int64 LENGTH$1;
	int64 DOCPP$1;
	int64 ADD_STDCALL_SUFFIX$1;
	int64 QUOTE_MANGLED_NAME$1;
	QUOTE_MANGLED_NAME$1 = 0ll;
	char* ID$1;
	int64 vr$1 = HDOCPPMANGLING( SYM$1 );
	DOCPP$1 = vr$1;
	int64 vr$13 = FBGETCPUFAMILY(  );
	ADD_STDCALL_SUFFIX$1 = (((int64)-(*(int64*)((uint8*)SYM$1 + 152ll) == 1ll) | ((int64)-(*(int64*)((uint8*)SYM$1 + 152ll) == 6ll) & (((int64)-(*(int64*)((uint8*)&ENV$ + 216ll) == 0ll) | (int64)-(*(int64*)((uint8*)&ENV$ + 216ll) == 1ll)) | (int64)-(*(int64*)((uint8*)&ENV$ + 216ll) == 5ll)))) & (int64)-(vr$13 == 0ll)) & ((int64)-(*(int64*)((uint8*)&ENV$ + 208ll) != 1ll) & (int64)-(*(int64*)((uint8*)&ENV$ + 208ll) != 2ll));
	if( *(int64*)((uint8*)&ENV$ + 208ll) != 3ll) goto label$413;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"@", 2ll, 0 );
		if( ADD_STDCALL_SUFFIX$1 == 0ll) goto label$415;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"\x22", 2ll, 0 );
			QUOTE_MANGLED_NAME$1 = -1ll;
		}
		label$415:;
		label$414:;
		{
			$13FB_COMPTARGET TMP$246$3;
			TMP$246$3 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
			if( TMP$246$3 == 0ll) goto label$418;
			label$419:;
			if( TMP$246$3 == 1ll) goto label$418;
			label$420:;
			if( TMP$246$3 != 5ll) goto label$417;
			label$418:;
			{
				if( QUOTE_MANGLED_NAME$1 != 0ll) goto label$422;
				{
					fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"\x22", 2ll, 0 );
					QUOTE_MANGLED_NAME$1 = -1ll;
				}
				label$422:;
				label$421:;
				fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"\x01", 2ll, 0 );
			}
			label$417:;
			label$416:;
		}
	}
	label$413:;
	label$412:;
	int64 vr$24 = HADDUNDERSCORE(  );
	if( vr$24 == 0ll) goto label$424;
	{
		if( *(int64*)((uint8*)SYM$1 + 152ll) != 6ll) goto label$426;
		{
			{
				$13FB_COMPTARGET TMP$248$4;
				TMP$248$4 = *($13FB_COMPTARGET*)((uint8*)&ENV$ + 216ll);
				if( TMP$248$4 == 0ll) goto label$429;
				label$430:;
				if( TMP$248$4 == 1ll) goto label$429;
				label$431:;
				if( TMP$248$4 != 5ll) goto label$428;
				label$429:;
				{
					fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"@", 2ll, 0 );
				}
				goto label$427;
				label$428:;
				{
					fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_", 2ll, 0 );
				}
				label$432:;
				label$427:;
			}
		}
		goto label$425;
		label$426:;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_", 2ll, 0 );
		}
		label$425:;
	}
	label$424:;
	label$423:;
	if( (DOCPP$1 | (int64)-((*(int64*)((uint8*)SYM$1 + 16ll) & 16ll) != 0ll)) == 0ll) goto label$434;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"_Z", 3ll, 0 );
	}
	label$434:;
	label$433:;
	if( DOCPP$1 == 0ll) goto label$436;
	{
		HMANGLENAMESPACE( &MANGLED$1, *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll), -1ll, (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2048ll) != 0ll) );
	}
	label$436:;
	label$435:;
	if( (*(int64*)((uint8*)SYM$1 + 24ll) & 512ll) == 0ll) goto label$438;
	{
		FBSTRING TMP$250$2;
		if( DOCPP$1 == 0ll) goto label$440;
		{
			FBSTRING TMP$249$3;
			int64 vr$43 = fb_StrLen( *(void**)((uint8*)SYM$1 + 40ll), 0ll );
			FBSTRING* vr$44 = fb_LongintToStr( vr$43 );
			__builtin_memset( &TMP$249$3, 0, 24ll );
			FBSTRING* vr$48 = fb_StrConcat( &TMP$249$3, (void*)&MANGLED$1, -1ll, (void*)vr$44, -1ll );
			fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$48, -1ll, 0 );
		}
		label$440:;
		label$439:;
		__builtin_memset( &TMP$250$2, 0, 24ll );
		FBSTRING* vr$54 = fb_StrConcat( &TMP$250$2, (void*)&MANGLED$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll );
		fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$54, -1ll, 0 );
	}
	goto label$437;
	label$438:;
	if( (*(int64*)((uint8*)SYM$1 + 16ll) & 16ll) == 0ll) goto label$441;
	{
		if( *(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)SYM$1 + 208ll) + 80ll) != 27ll) goto label$443;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"cv", 3ll, 0 );
			SYMBMANGLETYPE( &MANGLED$1, *(int64*)((uint8*)SYM$1 + 56ll), *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), 0ll );
		}
		goto label$442;
		label$443:;
		{
			FBSTRING TMP$252$3;
			char* vr$64 = HGETOPERATORNAME( SYM$1 );
			__builtin_memset( &TMP$252$3, 0, 24ll );
			FBSTRING* vr$68 = fb_StrConcat( &TMP$252$3, (void*)&MANGLED$1, -1ll, (void*)vr$64, 0ll );
			fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$68, -1ll, 0 );
		}
		label$442:;
	}
	goto label$437;
	label$441:;
	if( (*(int64*)((uint8*)SYM$1 + 16ll) & 4ll) == 0ll) goto label$444;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"C1", 3ll, 0 );
	}
	goto label$437;
	label$444:;
	if( (*(int64*)((uint8*)SYM$1 + 16ll) & 4096ll) == 0ll) goto label$445;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"D0", 3ll, 0 );
	}
	goto label$437;
	label$445:;
	if( (*(int64*)((uint8*)SYM$1 + 16ll) & 8ll) == 0ll) goto label$446;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"D1", 3ll, 0 );
	}
	goto label$437;
	label$446:;
	{
		FBSTRING TMP$256$2;
		if( (int64)*(int16*)((uint8*)SYM$1 + 74ll) != 0ll) goto label$448;
		{
			ID$1 = *(char**)((uint8*)SYM$1 + 32ll);
		}
		goto label$447;
		label$448:;
		{
			ID$1 = *(char**)((uint8*)SYM$1 + 40ll);
		}
		label$447:;
		if( DOCPP$1 == 0ll) goto label$450;
		{
			int64 vr$83 = fb_StrLen( (void*)ID$1, 0ll );
			LENGTH$1 = vr$83;
			if( (*(int64*)((uint8*)SYM$1 + 16ll) & 32ll) == 0ll) goto label$452;
			{
				LENGTH$1 = LENGTH$1 + 7ll;
			}
			label$452:;
			label$451:;
			FBSTRING* vr$87 = fb_LongintToStr( LENGTH$1 );
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)vr$87, -1ll, 0 );
		}
		label$450:;
		label$449:;
		__builtin_memset( &TMP$256$2, 0, 24ll );
		FBSTRING* vr$92 = fb_StrConcat( &TMP$256$2, (void*)&MANGLED$1, -1ll, (void*)ID$1, 0ll );
		fb_StrAssign( (void*)&MANGLED$1, -1ll, (void*)vr$92, -1ll, 0 );
		if( (*(int64*)((uint8*)SYM$1 + 16ll) & 32ll) == 0ll) goto label$454;
		{
			if( (*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) != 0ll) goto label$456;
			{
				fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"__set__", 8ll, 0 );
			}
			goto label$455;
			label$456:;
			{
				fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"__get__", 8ll, 0 );
			}
			label$455:;
		}
		label$454:;
		label$453:;
	}
	label$437:;
	if( DOCPP$1 == 0ll) goto label$458;
	{
		if( *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll) == (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$460;
		{
			fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"E", 2ll, 0 );
		}
		label$460:;
		label$459:;
		HGETPROCPARAMSTYPECODE( &MANGLED$1, SYM$1, -1ll );
	}
	label$458:;
	label$457:;
	if( ADD_STDCALL_SUFFIX$1 == 0ll) goto label$462;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"@", 2ll, 0 );
		int64 vr$106 = SYMBPROCCALCSTDCALLSUFFIXN( SYM$1 );
		FBSTRING* vr$107 = fb_LongintToStr( vr$106 );
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)vr$107, -1ll, 0 );
	}
	label$462:;
	label$461:;
	if( QUOTE_MANGLED_NAME$1 == 0ll) goto label$464;
	{
		fb_StrConcatAssign( (void*)&MANGLED$1, -1ll, (void*)"\x22", 2ll, 0 );
	}
	label$464:;
	label$463:;
	SYMBSETMANGLEDID( SYM$1, &MANGLED$1 );
	fb_StrDelete( (FBSTRING*)&MANGLED$1 );
	label$411:;
}
