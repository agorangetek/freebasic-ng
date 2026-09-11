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
typedef int64 $6AST_OP;
typedef int64 $15IRVREGTYPE_ENUM;
typedef int64 $11FB_DATATYPE;
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
typedef int64 $12IR_REGFAMILY;
struct $6IRVREG;
struct $9IRTACVREG;
struct $5IRTAC;
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
struct $8REGCLASS;
typedef int64 (*tmp$85)( struct $8REGCLASS*, struct $6IRVREG*, struct $6IRVREG*, uint64 );
typedef int64 (*tmp$86)( struct $8REGCLASS*, int64, struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$87)( struct $8REGCLASS*, int64 );
typedef int64 (*tmp$88)( struct $8REGCLASS*, int64 );
typedef void (*tmp$89)( struct $8REGCLASS*, int64, struct $6IRVREG*, struct $6IRVREG* );
typedef int64 (*tmp$90)( struct $8REGCLASS* );
typedef struct $6IRVREG* (*tmp$91)( struct $8REGCLASS*, int64, struct $6IRVREG** );
typedef void (*tmp$92)( struct $8REGCLASS* );
struct $7REG_REG;
struct $7REG_REG {
	int64 NUM;
	struct $7REG_REG* PREV;
};
__FB_STATIC_ASSERT( sizeof( struct $7REG_REG ) == 16 );
typedef int64 $12REG_SIZEMASK;
struct $10REG_REGCTX {
	struct $7REG_REG* FREETAIL;
	struct $7REG_REG* USEDTAIL;
	int64 FREETB;
	struct $7REG_REG REGTB[8];
	$12REG_SIZEMASK SIZETB[8];
	uint64 NEXTTB[8];
};
__FB_STATIC_ASSERT( sizeof( struct $10REG_REGCTX ) == 280 );
struct $10REG_STKCTX {
	int64 REGTB[8];
	int64 FREGS;
};
__FB_STATIC_ASSERT( sizeof( struct $10REG_STKCTX ) == 72 );
struct $8REGCLASS {
	tmp$85 ENSURE;
	tmp$85 _ALLOCATE;
	tmp$86 ALLOCATEREG;
	tmp$87 FREE;
	tmp$88 ISFREE;
	tmp$89 SETOWNER;
	tmp$90 GETMAXREGS;
	tmp$90 GETFIRST;
	tmp$88 GETNEXT;
	tmp$91 GETVREG;
	tmp$88 GETREALREG;
	tmp$92 CLEAR;
	tmp$92 DUMP;
	int64 CLASS;
	int64 ISSTACK;
	int64 REGS;
	struct $6IRVREG* VREGTB[8];
	struct $6IRVREG* VAUXPARENT[8];
	struct $10REG_REGCTX REGCTX;
	struct $10REG_STKCTX STKCTX;
};
__FB_STATIC_ASSERT( sizeof( struct $8REGCLASS ) == 608 );
typedef int64 (*tmp$40)( void );
typedef void (*tmp$39)( void );
typedef int64 $14IR_OPTIONVALUE;
typedef int64 (*tmp$41)( $14IR_OPTIONVALUE );
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
typedef void (*tmp$44)( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
typedef char* (*tmp$45)( void );
typedef void (*tmp$102)( struct $8FBSYMBOL*, int64, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
typedef int64 $10IR_EMITOPT;
typedef void (*tmp$100)( int64, int64, int64, int64* );
typedef struct $6IRVREG* (*tmp$73)( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
typedef int64 $11AST_OPFLAGS;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
typedef uint64 (*tmp$77)( struct $6IRVREG* );
typedef int64 (*tmp$42)( int64, int64 );
typedef void (*tmp$46)( struct $6IRVREG*, struct $6IRVREG* );
typedef void (*tmp$101)( int64, int64, int64*, int64* );
void fb_MemSwap( void*, void*, int64 );
void free( void* );
FBSTRING* fb_StrAssign( void*, int64, void*, int64, int32 );
void fb_StrDelete( FBSTRING* );
FBSTRING* fb_StrConcat( FBSTRING*, void*, int64, void*, int64 );
FBSTRING* fb_StrConcatAssign( void*, int64, void*, int64, int32 );
FBSTRING* fb_LongintToStr( int64 );
static void fb_ctor__irztac( void ) __attribute__(( constructor ));
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTWARN( int64, char*, $12FB_ERRMSGOPT, char* );
struct $8FBSYMBOL* SYMBADDANDALLOCATETEMPVAR( int64 );
int64 SYMBPROCCALCBYTESTOPOP( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBALLOCFLOATCONST( double, int64 );
void SYMBGETREALTYPE( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
char* ZSTRDUP( char* );
char* HESCAPE( char*, int64 );
char* HESCAPEW( uint32*, int64 );
void FLISTINIT( struct $6TFLIST*, int64, int64 );
void FLISTEND( struct $6TFLIST* );
void* FLISTNEWITEM( struct $6TFLIST* );
void FLISTRESET( struct $6TFLIST* );
void* FLISTGETHEAD( struct $6TFLIST* );
void* FLISTGETNEXT( void* );
int64 EMITINIT( void );
void EMITEND( void );
struct $8REGCLASS* EMITGETREGCLASS( int64 );
void EMITCOMMENT( char* );
void EMITASM( char* );
typedef int64 $19EMIT_NODECLASS_ENUM;
struct $12EMIT_BOPNODE {
	int64 OP;
	struct $6IRVREG* DVREG;
	struct $6IRVREG* SVREG;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_BOPNODE ) == 24 );
struct $12EMIT_UOPNODE {
	int64 OP;
	struct $6IRVREG* DVREG;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_UOPNODE ) == 16 );
struct $12EMIT_RELNODE {
	int64 OP;
	struct $6IRVREG* RVREG;
	struct $8FBSYMBOL* LABEL;
	struct $6IRVREG* DVREG;
	struct $6IRVREG* SVREG;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_RELNODE ) == 40 );
struct $12EMIT_STKNODE {
	int64 OP;
	struct $6IRVREG* VREG;
	int64 EXTRA;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_STKNODE ) == 24 );
struct $12EMIT_BRCNODE {
	int64 OP;
	struct $6IRVREG* VREG;
	struct $8FBSYMBOL* SYM;
	int64 EXTRA;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_BRCNODE ) == 32 );
struct $12EMIT_SOPNODE {
	int64 OP;
	struct $8FBSYMBOL* SYM;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_SOPNODE ) == 16 );
struct $12EMIT_LITNODE {
	int64 ISASM;
	char* TEXT;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_LITNODE ) == 16 );
struct $12EMIT_JTBNODE {
	struct $8FBSYMBOL* TBSYM;
	uint64* VALUES;
	struct $8FBSYMBOL** LABELS;
	int64 LABELCOUNT;
	struct $8FBSYMBOL* DEFLABEL;
	uint64 BIAS;
	uint64 SPAN;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_JTBNODE ) == 56 );
struct $12EMIT_MEMNODE {
	int64 OP;
	struct $6IRVREG* DVREG;
	struct $6IRVREG* SVREG;
	int64 BYTES;
	int64 EXTRA;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_MEMNODE ) == 40 );
struct $12EMIT_DBGNODE {
	int64 OP;
	struct $8FBSYMBOL* SYM;
	int64 LNUM;
	char* FILENAME;
	int64 POS;
};
__FB_STATIC_ASSERT( sizeof( struct $12EMIT_DBGNODE ) == 40 );
struct $9EMIT_NODE {
	$19EMIT_NODECLASS_ENUM CLASS;
	$10IR_EMITOPT OPTIONS;
	union {
		struct $12EMIT_BOPNODE BOP;
		struct $12EMIT_UOPNODE UOP;
		struct $12EMIT_RELNODE REL;
		struct $12EMIT_STKNODE STK;
		struct $12EMIT_BRCNODE BRC;
		struct $12EMIT_SOPNODE SOP;
		struct $12EMIT_LITNODE LIT;
		struct $12EMIT_JTBNODE JTB;
		struct $12EMIT_MEMNODE MEM;
		struct $12EMIT_DBGNODE DBG;
	};
	int64 REGFREETB[2];
};
__FB_STATIC_ASSERT( sizeof( struct $9EMIT_NODE ) == 88 );
struct $9EMIT_NODE* EMITJMPTB( struct $8FBSYMBOL*, uint64*, struct $8FBSYMBOL**, int64, struct $8FBSYMBOL*, uint64, uint64 );
struct $9EMIT_NODE* EMITCALL( struct $8FBSYMBOL*, int64 );
struct $9EMIT_NODE* EMITCALLPTR( struct $6IRVREG*, int64 );
struct $9EMIT_NODE* EMITJUMP( struct $8FBSYMBOL* );
struct $9EMIT_NODE* EMITJUMPPTR( struct $6IRVREG* );
struct $9EMIT_NODE* EMITLABEL( struct $8FBSYMBOL* );
struct $9EMIT_NODE* EMITRET( int64 );
struct $9EMIT_NODE* EMITBRANCH( int64, struct $8FBSYMBOL* );
struct $9EMIT_NODE* EMITXCHGTOS( struct $6IRVREG* );
struct $9EMIT_NODE* EMITMOV( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITSTORE( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITLOAD( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITADD( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITSUB( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITMUL( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITDIV( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITINTDIV( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITMOD( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITSHL( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITSHR( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITAND( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITOR( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITXOR( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITEQV( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITIMP( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITADDROF( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITDEREF( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITGT( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITLT( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITEQ( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITNE( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITLE( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITGE( struct $6IRVREG*, struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, $10IR_EMITOPT );
struct $9EMIT_NODE* EMITATN2( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITPOW( struct $6IRVREG*, struct $6IRVREG* );
struct $9EMIT_NODE* EMITNEG( struct $6IRVREG* );
struct $9EMIT_NODE* EMITNOT( struct $6IRVREG* );
struct $9EMIT_NODE* EMITABS( struct $6IRVREG* );
struct $9EMIT_NODE* EMITHADD( struct $6IRVREG* );
struct $9EMIT_NODE* EMITSGN( struct $6IRVREG* );
struct $9EMIT_NODE* EMITFIX( struct $6IRVREG* );
struct $9EMIT_NODE* EMITFRAC( struct $6IRVREG* );
struct $9EMIT_NODE* EMITCONVFD2FS( struct $6IRVREG* );
struct $9EMIT_NODE* EMITSWZREP( struct $6IRVREG* );
struct $9EMIT_NODE* EMITSIN( struct $6IRVREG* );
struct $9EMIT_NODE* EMITASIN( struct $6IRVREG* );
struct $9EMIT_NODE* EMITCOS( struct $6IRVREG* );
struct $9EMIT_NODE* EMITACOS( struct $6IRVREG* );
struct $9EMIT_NODE* EMITTAN( struct $6IRVREG* );
struct $9EMIT_NODE* EMITATAN( struct $6IRVREG* );
struct $9EMIT_NODE* EMITSQRT( struct $6IRVREG* );
struct $9EMIT_NODE* EMITRSQRT( struct $6IRVREG* );
struct $9EMIT_NODE* EMITRCP( struct $6IRVREG* );
struct $9EMIT_NODE* EMITLOG( struct $6IRVREG* );
struct $9EMIT_NODE* EMITEXP( struct $6IRVREG* );
struct $9EMIT_NODE* EMITFLOOR( struct $6IRVREG* );
struct $9EMIT_NODE* EMITSTACKALIGN( int64 );
struct $9EMIT_NODE* EMITPUSH( struct $6IRVREG* );
struct $9EMIT_NODE* EMITPOP( struct $6IRVREG* );
struct $9EMIT_NODE* EMITPUSHUDT( struct $6IRVREG*, int64 );
struct $9EMIT_NODE* EMITPOPST0( void );
struct $9EMIT_NODE* EMITMEMMOVE( struct $6IRVREG*, struct $6IRVREG*, int64 );
struct $9EMIT_NODE* EMITMEMSWAP( struct $6IRVREG*, struct $6IRVREG*, int64 );
struct $9EMIT_NODE* EMITMEMFILL( struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
struct $9EMIT_NODE* EMITSTKCLEAR( int64, int64 );
struct $9EMIT_NODE* EMITDBGLINEBEGIN( struct $8FBSYMBOL*, int64, char* );
struct $9EMIT_NODE* EMITDBGLINEEND( struct $8FBSYMBOL*, int64 );
struct $9EMIT_NODE* EMITDBGSCOPEBEGIN( struct $8FBSYMBOL* );
struct $9EMIT_NODE* EMITDBGSCOPEEND( struct $8FBSYMBOL* );
void EMITVARINIBEGIN( struct $8FBSYMBOL* );
void EMITVARINII( int64, int64 );
void EMITVARINIF( int64, double );
void EMITVARINIOFS( char*, int64 );
void EMITVARINISTR( char*, int64 );
void EMITVARINIWSTR( char* );
void EMITVARINIPAD( int64, int64 );
void EMITFBCTINFBEGIN( void );
void EMITFBCTINFSTRING( char* );
void EMITFBCTINFEND( void );
static void HFLUSHUOP( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHCOMP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void HFLUSHSTORE( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHLOAD( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHCONVERT( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHCALL( int64, struct $8FBSYMBOL*, int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHBRANCH( int64, struct $8FBSYMBOL* );
static void HFLUSHSTACK( int64, struct $6IRVREG*, struct $6IRVREG*, int64 );
static void HFLUSHADDR( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HFLUSHMEM( int64, struct $6IRVREG*, struct $6IRVREG*, int64, void* );
static void HFLUSHDBG( int64, struct $8FBSYMBOL*, int64, char* );
static void HFLUSHLIT( int64, char* );
static void HFREEIDX( struct $6IRVREG*, int64 );
static void HFREEREG( struct $6IRVREG*, int64 );
static void HFREEPRESERVEDREGS( void );
static void _FLUSH( void );
static void _INIT( void );
static void _END( void );
static int64 _EMITBEGIN( void );
static void _EMITEND( void );
static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE );
static void HLOADIDX( struct $6IRVREG* );
static void HRELINK( struct $6IRVREG*, struct $9IRTACVREG* );
static void _EMIT( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, int64, char* );
static void _PROCBEGIN( struct $8FBSYMBOL* );
static void _PROCEND( struct $8FBSYMBOL* );
static void _PROCALLOCARG( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _PROCALLOCLOCAL( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static char* _PROCGETFRAMEREGNAME( void );
static void _SCOPEBEGIN( struct $8FBSYMBOL* );
static void _SCOPEEND( struct $8FBSYMBOL* );
static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* );
static void _EMITLABEL( struct $8FBSYMBOL* );
static void _EMITRETURN( int64 );
static void _EMITPROCBEGIN( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _EMITPROCEND( struct $8FBSYMBOL*, struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _EMITSCOPEBEGIN( struct $8FBSYMBOL* );
static void _EMITSCOPEEND( struct $8FBSYMBOL* );
static void _EMITBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void _EMITUOP( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITCONVERT( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSTORE( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSPILLREGS( void );
static void _EMITLOAD( struct $6IRVREG* );
static void _EMITLOADRES( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSTACK( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITPUSHARG( struct $8FBSYMBOL*, struct $6IRVREG*, int64, int64, struct $6IRVREG* );
static void _EMITADDR( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITLABELNF( struct $8FBSYMBOL* );
static void _EMITCALL( struct $8FBSYMBOL*, int64, struct $6IRVREG*, int64 );
static void _EMITCALLPTR( struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITSTACKALIGN( int64 );
static void _EMITJUMPPTR( struct $6IRVREG* );
static void _EMITBRANCH( int64, struct $8FBSYMBOL* );
static void _EMITJMPTB( struct $6IRVREG*, struct $8FBSYMBOL*, uint64*, struct $8FBSYMBOL**, int64, struct $8FBSYMBOL*, uint64, uint64 );
static void _EMITMEM( int64, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITMACRO( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITDECL( struct $8FBSYMBOL* );
static void _EMITDBG( int64, struct $8FBSYMBOL*, int64, char* );
static void _EMITCOMMENT( char* );
static void _EMITASMLINE( struct $9ASTASMTOK* );
static void _EMITVARINIBEGIN( struct $8FBSYMBOL* );
static void _EMITVARINIEND( struct $8FBSYMBOL* );
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
static struct $6IRVREG* HNEWVR( int64, struct $8FBSYMBOL*, int64 );
static struct $6IRVREG* _ALLOCVREG( int64, struct $8FBSYMBOL* );
static struct $6IRVREG* _ALLOCVRIMM( int64, struct $8FBSYMBOL*, int64 );
static struct $6IRVREG* _ALLOCVRIMMF( int64, struct $8FBSYMBOL*, double );
static struct $6IRVREG* _ALLOCVRVAR( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
static struct $6IRVREG* _ALLOCVRIDX( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64, int64, struct $6IRVREG* );
static struct $6IRVREG* _ALLOCVRPTR( int64, struct $8FBSYMBOL*, int64, struct $6IRVREG* );
static struct $6IRVREG* _ALLOCVROFS( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64 );
static void _SETVREGDATATYPE( struct $6IRVREG*, int64, struct $8FBSYMBOL* );
static void HRENAME( struct $6IRVREG*, struct $6IRVREG* );
static void HREUSE( struct $5IRTAC* );
static int64 HPRESERVEREG( struct $6IRVREG* );
static void HPRESERVEREGS( struct $6IRVREG* );
static void HLOADPOINTER( struct $6IRVREG* );
static void HLOADRESULT( struct $8FBSYMBOL*, struct $6IRVREG* );
static void HSPILLREGS( void );
static uint64 _GETDISTANCE( struct $6IRVREG* );
static void _LOADVR( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _STOREVR( struct $6IRVREG*, struct $6IRVREG* );
static void _XCHGTOS( int64 );
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
typedef struct $6IRVREG* (*tmp$74)( int64, struct $8FBSYMBOL*, struct $8FBSYMBOL*, int64, int64, struct $6IRVREG* );
typedef struct $6IRVREG* (*tmp$75)( int64, struct $8FBSYMBOL*, int64, struct $6IRVREG* );
typedef void (*tmp$76)( struct $6IRVREG*, int64, struct $8FBSYMBOL* );
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
extern struct $7IR_VTBL IRTAC_VTBL$;
typedef int64 $6IR_OPT;
struct $5IRCTX {
	struct $7IR_VTBL VTBL;
	$6IR_OPT OPTIONS;
};
__FB_STATIC_ASSERT( sizeof( struct $5IRCTX ) == 552 );
extern struct $5IRCTX IR$;
struct $12AST_PROC_CTX {
	struct $7ASTNODE* HEAD;
	struct $7ASTNODE* TAIL;
	struct $7ASTNODE* CURR;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_PROC_CTX ) == 24 );
struct $12AST_CALL_CTX {
	struct $5TLIST TMPSTRLIST;
};
__FB_STATIC_ASSERT( sizeof( struct $12AST_CALL_CTX ) == 64 );
struct $16AST_GLOBINST_CTX {
	struct $5TLIST LIST;
	int64 CTORCNT;
	int64 DTORCNT;
};
__FB_STATIC_ASSERT( sizeof( struct $16AST_GLOBINST_CTX ) == 80 );
struct $16AST_DATASTMT_CTX {
	struct $8FBSYMBOL* DESC;
	struct $8FBSYMBOL* LASTSYM;
	struct $8FBSYMBOL* FIRSTSYM;
	struct $8FBSYMBOL* LASTLBL;
};
__FB_STATIC_ASSERT( sizeof( struct $16AST_DATASTMT_CTX ) == 32 );
struct $23AST_DTORLIST_SCOPESTACK {
	int64* COOKIES;
	int64 COUNT;
	int64 ROOM;
};
__FB_STATIC_ASSERT( sizeof( struct $23AST_DTORLIST_SCOPESTACK ) == 24 );
struct $6ASTCTX {
	struct $5TLIST ASTTB;
	struct $12AST_PROC_CTX PROC;
	struct $12AST_CALL_CTX CALL;
	struct $16AST_GLOBINST_CTX GLOBINST;
	struct $16AST_DATASTMT_CTX DATA;
	struct $7ASTNODE* CURRBLOCK;
	int64 DOEMIT;
	int64 TYPEINICOUNT;
	int64 BITFIELDCOUNT;
	struct $5TLIST DTORLIST;
	struct $23AST_DTORLIST_SCOPESTACK DTORLISTSCOPES;
	int64 DTORLISTCOOKIES;
	int64 FLUSHDTORLIST;
	struct $5TLIST ASMTOKLIST;
	int64 HIDEWARNINGSLEVEL;
};
__FB_STATIC_ASSERT( sizeof( struct $6ASTCTX ) == 472 );
extern struct $6ASTCTX AST$;
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
typedef void (*tmp$103)( int64, int64 );
typedef char* (*tmp$104)( int64 );
typedef char* (*tmp$105)( int64, int64 );
struct $9EMIT_VTBL {
	tmp$40 INIT;
	tmp$39 END;
	tmp$41 GETOPTIONVALUE;
	tmp$40 OPEN;
	tmp$39 CLOSE;
	tmp$42 ISREGPRESERVED;
	tmp$42 GETFREEPRESERVEDREG;
	tmp$100 GETARGREG;
	tmp$101 GETRESULTREG;
	tmp$45 PROCGETFRAMEREGNAME;
	tmp$43 PROCBEGIN;
	tmp$43 PROCEND;
	tmp$44 PROCHEADER;
	tmp$102 PROCFOOTER;
	tmp$44 PROCALLOCARG;
	tmp$44 PROCALLOCLOCAL;
	tmp$43 PROCALLOCSTATICVARS;
	tmp$43 SCOPEBEGIN;
	tmp$43 SCOPEEND;
	tmp$103 SETSECTION;
	tmp$104 GETTYPESTRING;
	tmp$105 GETSECTIONSTRING;
};
__FB_STATIC_ASSERT( sizeof( struct $9EMIT_VTBL ) == 176 );
struct $7EMITCTX {
	int64 INITED;
	int64 POS;
	struct $8REGCLASS* REGTB[2];
	struct $6TFLIST NODETB;
	struct $6TFLIST VREGTB;
	struct $9EMIT_NODE* CURNODE;
	int64 REGUSEDTB[2];
	int64 LASTSECTION;
	int64 LASTPRIORITY;
	struct $9EMIT_VTBL VTBL;
	void** OPFNTB;
};
__FB_STATIC_ASSERT( sizeof( struct $7EMITCTX ) == 480 );
extern struct $7EMITCTX EMIT$;
struct $8FBARRAY1IPvE {
	void** DATA;
	void** PTR;
	int64 SIZE;
	int64 ELEMENT_LEN;
	int64 DIMENSIONS;
	int64 FLAGS;
	struct $16__FB_ARRAYDIMTB$ DIMTB[1];
};
__FB_STATIC_ASSERT( sizeof( struct $8FBARRAY1IPvE ) == 72 );
static struct $8FBARRAY1IPvE tmp$106$;
struct $9IRTAC_CTX {
	struct $6TFLIST TACTB;
	int64 TACCNT;
	struct $5IRTAC* TACIDX;
	struct $6TFLIST VREGTB;
};
__FB_STATIC_ASSERT( sizeof( struct $9IRTAC_CTX ) == 240 );
static struct $9IRTAC_CTX CTX$;
static struct $8REGCLASS* REGTB$[2];
struct $7IR_VTBL IRTAC_VTBL$ = { (tmp$39)&_INIT, (tmp$39)&_END, (tmp$40)&_EMITBEGIN, (tmp$39)&_EMITEND, (tmp$41)&_GETOPTIONVALUE, (tmp$42)0ull, (tmp$43)&_PROCBEGIN, (tmp$43)&_PROCEND, (tmp$44)&_PROCALLOCARG, (tmp$44)&_PROCALLOCLOCAL, (tmp$45)&_PROCGETFRAMEREGNAME, (tmp$43)&_SCOPEBEGIN, (tmp$43)&_SCOPEEND, (tmp$43)&_PROCALLOCSTATICVARS, (tmp$46)&_EMITCONVERT, (tmp$43)&_EMITLABEL, (tmp$43)&_EMITLABELNF, (tmp$47)&_EMITRETURN, (tmp$44)&_EMITPROCBEGIN, (tmp$48)&_EMITPROCEND, (tmp$49)&_EMITPUSHARG, (tmp$50)&_EMITASMLINE, (tmp$51)&_EMITCOMMENT, (tmp$52)&_EMITBOP, (tmp$53)&_EMITUOP, (tmp$46)&_EMITSTORE, (tmp$39)&_EMITSPILLREGS, (tmp$54)&_EMITLOAD, (tmp$46)&_EMITLOADRES, (tmp$53)&_EMITSTACK, (tmp$53)&_EMITADDR, (tmp$55)&_EMITCALL, (tmp$56)&_EMITCALLPTR, (tmp$47)&_EMITSTACKALIGN, (tmp$54)&_EMITJUMPPTR, (tmp$57)&_EMITBRANCH, (tmp$58)&_EMITJMPTB, (tmp$59)&_EMITMEM, (tmp$60)&_EMITMACRO, (tmp$43)&_EMITSCOPEBEGIN, (tmp$43)&_EMITSCOPEEND, (tmp$43)&_EMITDECL, (tmp$61)&_EMITDBG, (tmp$43)&_EMITVARINIBEGIN, (tmp$43)&_EMITVARINIEND, (tmp$62)&_EMITVARINII, (tmp$63)&_EMITVARINIF, (tmp$64)&_EMITVARINIOFS, (tmp$65)&_EMITVARINISTR, (tmp$66)&_EMITVARINIWSTR, (tmp$67)&_EMITVARINIPAD, (tmp$68)&_EMITVARINISCOPEBEGIN, (tmp$39)&_EMITVARINISCOPEEND, (tmp$39)&_EMITFBCTINFBEGIN, (tmp$69)&_EMITFBCTINFSTRING, (tmp$39)&_EMITFBCTINFEND, (tmp$70)&_ALLOCVREG, (tmp$71)&_ALLOCVRIMM, (tmp$72)&_ALLOCVRIMMF, (tmp$73)&_ALLOCVRVAR, (tmp$74)&_ALLOCVRIDX, (tmp$75)&_ALLOCVRPTR, (tmp$73)&_ALLOCVROFS, (tmp$76)&_SETVREGDATATYPE, (tmp$77)&_GETDISTANCE, (tmp$53)&_LOADVR, (tmp$46)&_STOREVR, (tmp$47)&_XCHGTOS };

__attribute__(( constructor )) static void fb_ctor__irztac( void )
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

static void _INIT( void )
{
	label$10:;
	*(struct $5IRTAC**)((uint8*)&CTX$ + 120ll) = (struct $5IRTAC*)0ull;
	*(int64*)((uint8*)&CTX$ + 112ll) = 0ll;
	FLISTINIT( (struct $6TFLIST*)&CTX$, 2048ll, 256ll );
	FLISTINIT( (struct $6TFLIST*)((uint8*)&CTX$ + 128ll), 6144ll, 120ll );
	EMITINIT(  );
	{
		int64 I$2;
		I$2 = 0ll;
		label$15:;
		{
			struct $8REGCLASS* vr$2 = EMITGETREGCLASS( I$2 );
			*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (I$2 << (3ll & 63ll))) = vr$2;
		}
		label$13:;
		I$2 = I$2 + 1ll;
		label$12:;
		if( I$2 <= 1ll) goto label$15;
		label$14:;
	}
	label$11:;
}

static void _END( void )
{
	label$16:;
	EMITEND(  );
	FLISTEND( (struct $6TFLIST*)((uint8*)&CTX$ + 128ll) );
	FLISTEND( (struct $6TFLIST*)&CTX$ );
	*(struct $5IRTAC**)((uint8*)&CTX$ + 120ll) = (struct $5IRTAC*)0ull;
	*(int64*)((uint8*)&CTX$ + 112ll) = 0ll;
	label$17:;
}

static int64 _EMITBEGIN( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$18:;
	int64 vr$1 = (*(tmp$40*)((uint8*)&EMIT$ + 320ll))(  );
	fb$result$1 = vr$1;
	label$19:;
	return fb$result$1;
}

static void _EMITEND( void )
{
	label$20:;
	(*(tmp$39*)((uint8*)&EMIT$ + 328ll))(  );
	label$21:;
}

static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE OPT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$22:;
	int64 vr$1 = (*(tmp$41*)((uint8*)&EMIT$ + 312ll))( OPT$1 );
	fb$result$1 = vr$1;
	label$23:;
	return fb$result$1;
}

static void HLOADIDX( struct $6IRVREG* VREG$1 )
{
	label$24:;
	struct $6IRVREG* VI$1;
	if( VREG$1 != (struct $6IRVREG*)0ull) goto label$27;
	{
		goto label$25;
	}
	label$27:;
	label$26:;
	{
		$15IRVREGTYPE_ENUM TMP$108$2;
		TMP$108$2 = *($15IRVREGTYPE_ENUM*)VREG$1;
		if( TMP$108$2 == 2ll) goto label$30;
		label$31:;
		if( TMP$108$2 != 3ll) goto label$29;
		label$30:;
		{
		}
		goto label$28;
		label$29:;
		{
			goto label$25;
		}
		label$32:;
		label$28:;
	}
	VI$1 = *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll);
	if( VI$1 != (struct $6IRVREG*)0ull) goto label$34;
	{
		goto label$25;
	}
	label$34:;
	label$33:;
	if( *(int64*)VI$1 != 0ll) goto label$36;
	{
		goto label$25;
	}
	label$36:;
	label$35:;
	(*(tmp$85*)*(struct $8REGCLASS**)REGTB$)( *(struct $8REGCLASS**)REGTB$, VI$1, (struct $6IRVREG*)0ull, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
	label$25:;
}

static void HRELINK( struct $6IRVREG* VREG$1, struct $9IRTACVREG* TVREG$1 )
{
	label$37:;
	if( *(struct $9IRTACVREG**)((uint8*)VREG$1 + 96ll) != (struct $9IRTACVREG*)0ull) goto label$40;
	{
		*(struct $9IRTACVREG**)((uint8*)VREG$1 + 96ll) = TVREG$1;
	}
	goto label$39;
	label$40:;
	{
		*(struct $9IRTACVREG**)((uint8*)*(struct $9IRTACVREG**)((uint8*)VREG$1 + 104ll) + 16ll) = TVREG$1;
	}
	label$39:;
	*(struct $9IRTACVREG**)((uint8*)VREG$1 + 104ll) = TVREG$1;
	label$38:;
}

static void _EMIT( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* EX1$1, int64 EX2$1, char* EX3$1 )
{
	label$41:;
	static struct $5IRTAC* T$1;
	void* vr$1 = FLISTNEWITEM( (struct $6TFLIST*)&CTX$ );
	T$1 = (struct $5IRTAC*)vr$1;
	*(int64*)T$1 = *(int64*)((uint8*)&CTX$ + 112ll);
	*($6AST_OP*)((uint8*)T$1 + 8ll) = OP$1;
	*(struct $6IRVREG**)((uint8*)T$1 + 88ll) = V1$1;
	*(struct $6IRVREG**)((uint8*)T$1 + 96ll) = (struct $6IRVREG*)0ull;
	*(struct $9IRTACVREG**)((uint8*)T$1 + 104ll) = (struct $9IRTACVREG*)0ull;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$44;
	{
		HRELINK( V1$1, (struct $9IRTACVREG*)((uint8*)T$1 + 88ll) );
		*(struct $5IRTAC**)((uint8*)V1$1 + 112ll) = T$1;
		if( *(struct $6IRVREG**)((uint8*)V1$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$46;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 112ll) = *(struct $6IRVREG**)((uint8*)V1$1 + 80ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 120ll) = V1$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 128ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)V1$1 + 80ll), (struct $9IRTACVREG*)((uint8*)T$1 + 112ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)V1$1 + 80ll) + 112ll) = T$1;
		}
		label$46:;
		label$45:;
		if( *(struct $6IRVREG**)((uint8*)V1$1 + 88ll) == (struct $6IRVREG*)0ull) goto label$48;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 136ll) = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 144ll) = V1$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 152ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)V1$1 + 88ll), (struct $9IRTACVREG*)((uint8*)T$1 + 136ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)V1$1 + 88ll) + 112ll) = T$1;
		}
		label$48:;
		label$47:;
	}
	label$44:;
	label$43:;
	*(struct $6IRVREG**)((uint8*)T$1 + 160ll) = V2$1;
	*(struct $6IRVREG**)((uint8*)T$1 + 168ll) = (struct $6IRVREG*)0ull;
	*(struct $9IRTACVREG**)((uint8*)T$1 + 176ll) = (struct $9IRTACVREG*)0ull;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$50;
	{
		HRELINK( V2$1, (struct $9IRTACVREG*)((uint8*)T$1 + 160ll) );
		*(struct $5IRTAC**)((uint8*)V2$1 + 112ll) = T$1;
		if( *(struct $6IRVREG**)((uint8*)V2$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$52;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 184ll) = *(struct $6IRVREG**)((uint8*)V2$1 + 80ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 192ll) = V2$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 200ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)V2$1 + 80ll), (struct $9IRTACVREG*)((uint8*)T$1 + 184ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)V2$1 + 80ll) + 112ll) = T$1;
		}
		label$52:;
		label$51:;
		if( *(struct $6IRVREG**)((uint8*)V2$1 + 88ll) == (struct $6IRVREG*)0ull) goto label$54;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 208ll) = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 216ll) = V2$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 224ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)V2$1 + 88ll), (struct $9IRTACVREG*)((uint8*)T$1 + 208ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)V2$1 + 88ll) + 112ll) = T$1;
		}
		label$54:;
		label$53:;
	}
	label$50:;
	label$49:;
	*(struct $6IRVREG**)((uint8*)T$1 + 16ll) = VR$1;
	*(struct $6IRVREG**)((uint8*)T$1 + 24ll) = (struct $6IRVREG*)0ull;
	*(struct $9IRTACVREG**)((uint8*)T$1 + 32ll) = (struct $9IRTACVREG*)0ull;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$56;
	{
		HRELINK( VR$1, (struct $9IRTACVREG*)((uint8*)T$1 + 16ll) );
		*(struct $5IRTAC**)((uint8*)VR$1 + 112ll) = T$1;
		if( *(struct $6IRVREG**)((uint8*)VR$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$58;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 40ll) = *(struct $6IRVREG**)((uint8*)VR$1 + 80ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 48ll) = VR$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 56ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)VR$1 + 80ll), (struct $9IRTACVREG*)((uint8*)T$1 + 40ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)VR$1 + 80ll) + 112ll) = T$1;
		}
		label$58:;
		label$57:;
		if( *(struct $6IRVREG**)((uint8*)VR$1 + 88ll) == (struct $6IRVREG*)0ull) goto label$60;
		{
			*(struct $6IRVREG**)((uint8*)T$1 + 64ll) = *(struct $6IRVREG**)((uint8*)VR$1 + 88ll);
			*(struct $6IRVREG**)((uint8*)T$1 + 72ll) = VR$1;
			*(struct $9IRTACVREG**)((uint8*)T$1 + 80ll) = (struct $9IRTACVREG*)0ull;
			HRELINK( *(struct $6IRVREG**)((uint8*)VR$1 + 88ll), (struct $9IRTACVREG*)((uint8*)T$1 + 64ll) );
			*(struct $5IRTAC**)((uint8*)*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) + 112ll) = T$1;
		}
		label$60:;
		label$59:;
	}
	label$56:;
	label$55:;
	*(struct $8FBSYMBOL**)((uint8*)T$1 + 232ll) = EX1$1;
	*(int64*)((uint8*)T$1 + 240ll) = EX2$1;
	*(char**)((uint8*)T$1 + 248ll) = EX3$1;
	*(int64*)((uint8*)&CTX$ + 112ll) = *(int64*)((uint8*)&CTX$ + 112ll) + 1ll;
	label$42:;
}

static void _PROCBEGIN( struct $8FBSYMBOL* PROC$1 )
{
	label$61:;
	(*(tmp$43*)((uint8*)&EMIT$ + 376ll))( PROC$1 );
	label$62:;
}

static void _PROCEND( struct $8FBSYMBOL* PROC$1 )
{
	label$63:;
	(*(tmp$43*)((uint8*)&EMIT$ + 384ll))( PROC$1 );
	label$64:;
}

static void _PROCALLOCARG( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* SYM$1 )
{
	label$65:;
	(*(tmp$44*)((uint8*)&EMIT$ + 408ll))( PROC$1, SYM$1 );
	label$66:;
}

static void _PROCALLOCLOCAL( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* SYM$1 )
{
	label$67:;
	(*(tmp$44*)((uint8*)&EMIT$ + 416ll))( PROC$1, SYM$1 );
	label$68:;
}

static char* _PROCGETFRAMEREGNAME( void )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$69:;
	char* vr$1 = (*(tmp$45*)((uint8*)&EMIT$ + 368ll))(  );
	fb$result$1 = vr$1;
	label$70:;
	return fb$result$1;
}

static void _SCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	label$71:;
	(*(tmp$43*)((uint8*)&EMIT$ + 432ll))( S$1 );
	label$72:;
}

static void _SCOPEEND( struct $8FBSYMBOL* S$1 )
{
	label$73:;
	(*(tmp$43*)((uint8*)&EMIT$ + 440ll))( S$1 );
	label$74:;
}

static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* HEAD_SYM$1 )
{
	label$75:;
	(*(tmp$43*)((uint8*)&EMIT$ + 424ll))( HEAD_SYM$1 );
	label$76:;
}

static void _EMITLABEL( struct $8FBSYMBOL* LABEL$1 )
{
	label$77:;
	_FLUSH(  );
	EMITLABEL( LABEL$1 );
	label$78:;
}

static void _EMITRETURN( int64 BYTESTOPOP$1 )
{
	label$79:;
	_FLUSH(  );
	EMITRET( BYTESTOPOP$1 );
	label$80:;
}

static void _EMITPROCBEGIN( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1 )
{
	label$81:;
	static int64 CLASS_$1;
	_FLUSH(  );
	{
		CLASS_$1 = 0ll;
		label$86:;
		{
			(*(tmp$92*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) + 88ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) );
		}
		label$84:;
		CLASS_$1 = CLASS_$1 + 1ll;
		label$83:;
		if( CLASS_$1 <= 1ll) goto label$86;
		label$85:;
	}
	(*(tmp$44*)((uint8*)&EMIT$ + 392ll))( PROC$1, INITLABEL$1 );
	label$82:;
}

static void _EMITPROCEND( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1, struct $8FBSYMBOL* EXITLABEL$1 )
{
	label$87:;
	_FLUSH(  );
	int64 vr$0 = SYMBPROCCALCBYTESTOPOP( PROC$1 );
	(*(tmp$102*)((uint8*)&EMIT$ + 400ll))( PROC$1, vr$0, INITLABEL$1, EXITLABEL$1 );
	label$88:;
}

static void _EMITSCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	label$89:;
	_FLUSH(  );
	label$90:;
}

static void _EMITSCOPEEND( struct $8FBSYMBOL* S$1 )
{
	label$91:;
	_FLUSH(  );
	label$92:;
}

static void _EMITBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* LABEL$1, $10IR_EMITOPT OPTIONS$1 )
{
	label$93:;
	_EMIT( OP$1, V1$1, V2$1, VR$1, LABEL$1, OPTIONS$1, (char*)0ull );
	label$94:;
}

static void _EMITUOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$95:;
	_EMIT( OP$1, V1$1, (struct $6IRVREG*)0ull, VR$1, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$96:;
}

static void _EMITCONVERT( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$97:;
	{
		int64 TMP$109$2;
		$12FB_DATACLASS TMP$110$2;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$99;
		TMP$109$2 = 24ll;
		goto label$857;
		label$99:;
		TMP$109$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$857:;
		TMP$110$2 = *($12FB_DATACLASS*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$109$2 * 56ll));
		if( TMP$110$2 != 0ll) goto label$101;
		label$102:;
		{
			if( (*(int64*)((uint8*)V1$1 + 8ll) & 511ll) != 1ll) goto label$104;
			{
				_EMIT( 85ll, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
			}
			goto label$103;
			label$104:;
			{
				_EMIT( 83ll, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
			}
			label$103:;
		}
		goto label$100;
		label$101:;
		if( TMP$110$2 != 1ll) goto label$105;
		label$106:;
		{
			_EMIT( 84ll, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
		}
		label$105:;
		label$100:;
	}
	label$98:;
}

static void _EMITSTORE( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$107:;
	_EMIT( 0ll, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$108:;
}

static void _EMITSPILLREGS( void )
{
	label$109:;
	_EMIT( 88ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$110:;
}

static void _EMITLOAD( struct $6IRVREG* V1$1 )
{
	label$111:;
	_EMIT( 86ll, V1$1, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$112:;
}

static void _EMITLOADRES( struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$113:;
	_EMIT( 87ll, V1$1, (struct $6IRVREG*)0ull, VR$1, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$114:;
}

static void _EMITSTACK( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$115:;
	_EMIT( OP$1, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$116:;
}

static void _EMITPUSHARG( struct $8FBSYMBOL* PARAM$1, struct $6IRVREG* VR$1, int64 UDTLEN$1, int64 LEVEL$1, struct $6IRVREG* LREG$1 )
{
	label$117:;
	if( LREG$1 == (struct $6IRVREG*)0ull) goto label$120;
	{
		int64 VR_DCLASS$2;
		int64 VR_DTYPE$2;
		int64 VR_TYP$2;
		int64 REG1$2;
		REG1$2 = -1ll;
		if( VR$1 == (struct $6IRVREG*)0ull) goto label$122;
		{
			int64 TMP$111$3;
			VR_TYP$2 = *(int64*)VR$1;
			if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$123;
			TMP$111$3 = 24ll;
			goto label$858;
			label$123:;
			TMP$111$3 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
			label$858:;
			VR_DTYPE$2 = TMP$111$3;
			if( VR_DTYPE$2 != 24ll) goto label$125;
			{
				VR_DTYPE$2 = 9ll;
			}
			label$125:;
			label$124:;
			VR_DCLASS$2 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$2 * 56ll));
		}
		goto label$121;
		label$122:;
		{
			VR_TYP$2 = -1ll;
			VR_DTYPE$2 = 2147483648ll;
			VR_DCLASS$2 = -1ll;
		}
		label$121:;
		(*(tmp$100*)((uint8*)&EMIT$ + 352ll))( VR_DCLASS$2, VR_TYP$2, *(int64*)((uint8*)PARAM$1 + 136ll), &REG1$2 );
		if( REG1$2 == -1ll) goto label$127;
		{
			int64 TMP$112$3;
			*(int64*)((uint8*)LREG$1 + 24ll) = REG1$2;
			if( *(int64*)VR$1 != 4ll) goto label$129;
			{
				*($11FB_DATATYPE*)((uint8*)LREG$1 + 8ll) = *($11FB_DATATYPE*)((uint8*)VR$1 + 8ll);
			}
			label$129:;
			label$128:;
			if( (VR_DTYPE$2 & 480ll) == 0ll) goto label$130;
			TMP$112$3 = 24ll;
			goto label$859;
			label$130:;
			TMP$112$3 = VR_DTYPE$2 & 31ll;
			label$859:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$2 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$2 << (3ll & 63ll))), LREG$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$112$3 * 56ll)) + 8ll) );
			_EMITSTACK( 89ll, VR$1, LREG$1 );
			goto label$118;
		}
		label$127:;
		label$126:;
	}
	label$120:;
	label$119:;
	if( UDTLEN$1 != 0ll) goto label$132;
	{
		_EMITSTACK( 89ll, VR$1, (struct $6IRVREG*)0ull );
	}
	goto label$131;
	label$132:;
	{
		_EMIT( 91ll, VR$1, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, UDTLEN$1, (char*)0ull );
	}
	label$131:;
	label$118:;
}

static void _EMITADDR( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$133:;
	_EMIT( OP$1, V1$1, (struct $6IRVREG*)0ull, VR$1, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$134:;
}

static void _EMITLABELNF( struct $8FBSYMBOL* L$1 )
{
	label$135:;
	_EMIT( 101ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, L$1, 0ll, (char*)0ull );
	label$136:;
}

static void _EMITCALL( struct $8FBSYMBOL* PROC$1, int64 BYTESTOPOP$1, struct $6IRVREG* VR$1, int64 LEVEL$1 )
{
	label$137:;
	_EMIT( 103ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, VR$1, PROC$1, BYTESTOPOP$1, (char*)0ull );
	label$138:;
}

static void _EMITCALLPTR( struct $8FBSYMBOL* PROC$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1, int64 BYTESTOPOP$1, int64 LEVEL$1 )
{
	label$139:;
	_EMIT( 104ll, V1$1, (struct $6IRVREG*)0ull, VR$1, PROC$1, BYTESTOPOP$1, (char*)0ull );
	label$140:;
}

static void _EMITSTACKALIGN( int64 BYTES$1 )
{
	label$141:;
	_EMIT( 92ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, BYTES$1, (char*)0ull );
	label$142:;
}

static void _EMITJUMPPTR( struct $6IRVREG* V1$1 )
{
	label$143:;
	_EMIT( 105ll, V1$1, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	label$144:;
}

static void _EMITBRANCH( int64 OP$1, struct $8FBSYMBOL* LABEL$1 )
{
	label$145:;
	_EMIT( OP$1, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, LABEL$1, 0ll, (char*)0ull );
	label$146:;
}

static void _EMITJMPTB( struct $6IRVREG* V1$1, struct $8FBSYMBOL* TBSYM$1, uint64* VALUES$1, struct $8FBSYMBOL** LABELS$1, int64 LABELCOUNT$1, struct $8FBSYMBOL* DEFLABEL$1, uint64 BIAS$1, uint64 SPAN$1 )
{
	label$147:;
	_FLUSH(  );
	EMITJMPTB( TBSYM$1, VALUES$1, LABELS$1, LABELCOUNT$1, DEFLABEL$1, BIAS$1, SPAN$1 );
	label$148:;
}

static void _EMITMEM( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$149:;
	_EMIT( OP$1, V1$1, V2$1, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)0ull, BYTES$1, (char*)FILLCHAR$1 );
	label$150:;
}

static void _EMITMACRO( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1 )
{
	label$151:;
	label$152:;
}

static void _EMITDECL( struct $8FBSYMBOL* SYM$1 )
{
	label$153:;
	label$154:;
}

static void _EMITDBG( int64 OP$1, struct $8FBSYMBOL* PROC$1, int64 EX$1, char* FILENAME$1 )
{
	label$155:;
	_EMIT( OP$1, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, PROC$1, EX$1, FILENAME$1 );
	label$156:;
}

static void _EMITCOMMENT( char* TEXT$1 )
{
	label$157:;
	char* vr$0 = ZSTRDUP( TEXT$1 );
	_EMIT( 118ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)vr$0, 0ll, (char*)0ull );
	label$158:;
}

static void _EMITASMLINE( struct $9ASTASMTOK* ASMTOKENHEAD$1 )
{
	label$159:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	struct $9ASTASMTOK* N$1;
	N$1 = ASMTOKENHEAD$1;
	label$161:;
	if( N$1 == (struct $9ASTASMTOK*)0ull) goto label$162;
	{
		{
			$14AST_ASMTOKTYPE TMP$113$3;
			TMP$113$3 = *($14AST_ASMTOKTYPE*)N$1;
			if( TMP$113$3 != 0ll) goto label$164;
			label$165:;
			{
				FBSTRING TMP$114$4;
				__builtin_memset( &TMP$114$4, 0, 24ll );
				FBSTRING* vr$6 = fb_StrConcat( &TMP$114$4, (void*)&LN$1, -1ll, *(void**)((uint8*)N$1 + 8ll), 0ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$6, -1ll, 0 );
			}
			goto label$163;
			label$164:;
			if( TMP$113$3 != 1ll) goto label$166;
			label$167:;
			{
				FBSTRING TMP$115$4;
				char* vr$9 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) );
				__builtin_memset( &TMP$115$4, 0, 24ll );
				FBSTRING* vr$13 = fb_StrConcat( &TMP$115$4, (void*)&LN$1, -1ll, (void*)vr$9, 0ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$13, -1ll, 0 );
				int64 OFS$4;
				OFS$4 = *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) + 88ll);
				if( OFS$4 == 0ll) goto label$169;
				{
					if( OFS$4 <= 0ll) goto label$171;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"+", 2ll, 0 );
					}
					label$171:;
					label$170:;
					FBSTRING* vr$18 = fb_LongintToStr( OFS$4 );
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$18, -1ll, 0 );
				}
				label$169:;
				label$168:;
			}
			label$166:;
			label$163:;
		}
		N$1 = *(struct $9ASTASMTOK**)((uint8*)N$1 + 16ll);
	}
	goto label$161;
	label$162:;
	char* vr$21 = ZSTRDUP( (char*)*(char**)&LN$1 );
	_EMIT( 119ll, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $6IRVREG*)0ull, (struct $8FBSYMBOL*)vr$21, 0ll, (char*)0ull );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$160:;
}

static void _EMITVARINIBEGIN( struct $8FBSYMBOL* SYM$1 )
{
	label$172:;
	EMITVARINIBEGIN( SYM$1 );
	label$173:;
}

static void _EMITVARINIEND( struct $8FBSYMBOL* SYM$1 )
{
	label$174:;
	label$175:;
}

static void _EMITVARINII( struct $8FBSYMBOL* SYM$1, int64 VALUE$1 )
{
	label$176:;
	int64 REALTYPE$1;
	__builtin_memset( &REALTYPE$1, 0, 8ll );
	struct $8FBSYMBOL* REALSUBTYPE$1;
	__builtin_memset( &REALSUBTYPE$1, 0, 8ll );
	SYMBGETREALTYPE( SYM$1, &REALTYPE$1, &REALSUBTYPE$1 );
	EMITVARINII( REALTYPE$1, VALUE$1 );
	label$177:;
}

static void _EMITVARINIF( struct $8FBSYMBOL* SYM$1, double VALUE$1 )
{
	label$178:;
	int64 REALTYPE$1;
	__builtin_memset( &REALTYPE$1, 0, 8ll );
	struct $8FBSYMBOL* REALSUBTYPE$1;
	__builtin_memset( &REALSUBTYPE$1, 0, 8ll );
	SYMBGETREALTYPE( SYM$1, &REALTYPE$1, &REALSUBTYPE$1 );
	EMITVARINIF( REALTYPE$1, VALUE$1 );
	label$179:;
}

static void _EMITVARINIOFS( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* RHS$1, int64 OFS$1 )
{
	label$180:;
	char* vr$0 = SYMBGETMANGLEDNAME( RHS$1 );
	EMITVARINIOFS( vr$0, OFS$1 );
	label$181:;
}

static void _EMITVARINISTR( int64 TOTLGT$1, char* LITSTR$1, int64 LITLGT$1, int64 NOTERM$1 )
{
	label$182:;
	char* S$1;
	__builtin_memset( &S$1, 0, 8ll );
	if( TOTLGT$1 != 0ll) goto label$185;
	{
		EMITVARINII( 2ll, 0ll );
		goto label$183;
	}
	label$185:;
	label$184:;
	if( LITLGT$1 <= TOTLGT$1) goto label$187;
	{
		ERRREPORTWARN( 9ll, (char*)0ull, 1ll, (char*)0ull );
		char* vr$1 = HESCAPE( (char*)LITSTR$1, TOTLGT$1 );
		S$1 = vr$1;
	}
	goto label$186;
	label$187:;
	{
		char* vr$2 = HESCAPE( (char*)LITSTR$1, 0ll );
		S$1 = vr$2;
	}
	label$186:;
	EMITVARINISTR( S$1, NOTERM$1 );
	if( LITLGT$1 >= TOTLGT$1) goto label$189;
	{
		int64 TMP$117$2;
		if( NOTERM$1 == 0ll) goto label$190;
		TMP$117$2 = 32ll;
		goto label$860;
		label$190:;
		TMP$117$2 = 0ll;
		label$860:;
		EMITVARINIPAD( TOTLGT$1 - LITLGT$1, TMP$117$2 );
	}
	label$189:;
	label$188:;
	label$183:;
}

static void _EMITVARINIWSTR( int64 TOTLGT$1, uint32* LITSTR$1, int64 LITLGT$1 )
{
	label$191:;
	char* S$1;
	__builtin_memset( &S$1, 0, 8ll );
	int64 WCLEN$1;
	__builtin_memset( &WCLEN$1, 0, 8ll );
	if( TOTLGT$1 != 0ll) goto label$194;
	{
		EMITVARINII( *(int64*)((uint8*)&ENV$ + 568ll), 0ll );
		goto label$192;
	}
	label$194:;
	label$193:;
	if( LITLGT$1 <= TOTLGT$1) goto label$196;
	{
		ERRREPORTWARN( 9ll, (char*)0ull, 1ll, (char*)0ull );
		char* vr$2 = HESCAPEW( (uint32*)LITSTR$1, TOTLGT$1 );
		S$1 = vr$2;
	}
	goto label$195;
	label$196:;
	{
		char* vr$3 = HESCAPEW( (uint32*)LITSTR$1, 0ll );
		S$1 = vr$3;
	}
	label$195:;
	WCLEN$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 400ll);
	EMITVARINIWSTR( S$1 );
	if( LITLGT$1 >= TOTLGT$1) goto label$198;
	{
		EMITVARINIPAD( (TOTLGT$1 - LITLGT$1) * WCLEN$1, 0ll );
	}
	label$198:;
	label$197:;
	label$192:;
}

static void _EMITVARINIPAD( int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$199:;
	EMITVARINIPAD( BYTES$1, FILLCHAR$1 );
	label$200:;
}

static void _EMITVARINISCOPEBEGIN( struct $8FBSYMBOL* SYM$1, int64 IS_ARRAY$1 )
{
	label$201:;
	label$202:;
}

static void _EMITVARINISCOPEEND( void )
{
	label$203:;
	label$204:;
}

static void _EMITFBCTINFBEGIN( void )
{
	label$205:;
	EMITFBCTINFBEGIN(  );
	label$206:;
}

static void _EMITFBCTINFSTRING( char* S$1 )
{
	label$207:;
	EMITFBCTINFSTRING( S$1 );
	label$208:;
}

static void _EMITFBCTINFEND( void )
{
	label$209:;
	EMITFBCTINFEND(  );
	label$210:;
}

static struct $6IRVREG* HNEWVR( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, int64 VTYPE$1 )
{
	int64 TMP$118$1;
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$211:;
	struct $6IRVREG* V$1;
	void* vr$2 = FLISTNEWITEM( (struct $6TFLIST*)((uint8*)&CTX$ + 128ll) );
	V$1 = (struct $6IRVREG*)vr$2;
	*($15IRVREGTYPE_ENUM*)V$1 = VTYPE$1;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$213;
	TMP$118$1 = 24ll;
	goto label$861;
	label$213:;
	TMP$118$1 = DTYPE$1 & 31ll;
	label$861:;
	*($11FB_DATATYPE*)((uint8*)V$1 + 8ll) = TMP$118$1;
	*(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) = SUBTYPE$1;
	*(int64*)((uint8*)V$1 + 24ll) = -1ll;
	if( *(int64*)((uint8*)&ENV$ + 232ll) != 0ll) goto label$215;
	{
		*($12IR_REGFAMILY*)((uint8*)V$1 + 32ll) = 0ll;
	}
	goto label$214;
	label$215:;
	{
		*($12IR_REGFAMILY*)((uint8*)V$1 + 32ll) = 1ll;
	}
	label$214:;
	*(int64*)((uint8*)V$1 + 40ll) = 0ll;
	*(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) = (struct $8FBSYMBOL*)0ull;
	*(int64*)((uint8*)V$1 + 64ll) = 0ll;
	*(int64*)((uint8*)V$1 + 72ll) = 0ll;
	*(struct $6IRVREG**)((uint8*)V$1 + 80ll) = (struct $6IRVREG*)0ull;
	*(struct $6IRVREG**)((uint8*)V$1 + 88ll) = (struct $6IRVREG*)0ull;
	*(struct $9IRTACVREG**)((uint8*)V$1 + 96ll) = (struct $9IRTACVREG*)0ull;
	*(struct $9IRTACVREG**)((uint8*)V$1 + 104ll) = (struct $9IRTACVREG*)0ull;
	*(struct $5IRTAC**)((uint8*)V$1 + 112ll) = (struct $5IRTAC*)0ull;
	fb$result$1 = V$1;
	label$212:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVREG( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$216:;
	struct $6IRVREG* VR$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 4ll );
	VR$1 = vr$2;
	if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$219;
	{
		struct $6IRVREG* vr$6 = HNEWVR( 8ll, (struct $8FBSYMBOL*)0ull, 4ll );
		*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) = vr$6;
	}
	label$219:;
	label$218:;
	fb$result$1 = VR$1;
	label$217:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVRIMM( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, int64 VALUE$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$220:;
	struct $6IRVREG* VR$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 0ll );
	VR$1 = vr$2;
	if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$223;
	{
		*(int64*)((uint8*)VR$1 + 48ll) = VALUE$1 & 4294967295ll;
		struct $6IRVREG* vr$8 = HNEWVR( 8ll, (struct $8FBSYMBOL*)0ull, 0ll );
		*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) = vr$8;
		*(int64*)((uint8*)*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) + 48ll) = (int64)((uint64)VALUE$1 >> (32ll & 63ll));
	}
	goto label$222;
	label$223:;
	{
		*(int64*)((uint8*)VR$1 + 48ll) = VALUE$1;
	}
	label$222:;
	fb$result$1 = VR$1;
	label$221:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVRIMMF( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, double VALUE$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$224:;
	struct $6IRVREG* VR$1;
	struct $8FBSYMBOL* S$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	if( (*(int64*)((uint8*)&IR$ + 544ll) & 2ll) == 0ll) goto label$227;
	{
		struct $6IRVREG* vr$3 = HNEWVR( DTYPE$1, SUBTYPE$1, 0ll );
		VR$1 = vr$3;
		*(double*)((uint8*)VR$1 + 48ll) = VALUE$1;
	}
	goto label$226;
	label$227:;
	{
		struct $8FBSYMBOL* vr$5 = SYMBALLOCFLOATCONST( VALUE$1, DTYPE$1 );
		S$1 = vr$5;
		struct $6IRVREG* vr$7 = (*(tmp$73*)((uint8*)&IR$ + 472ll))( DTYPE$1, SUBTYPE$1, S$1, *(int64*)((uint8*)S$1 + 88ll) );
		VR$1 = vr$7;
	}
	label$226:;
	fb$result$1 = VR$1;
	label$225:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVRVAR( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, struct $8FBSYMBOL* SYMBOL$1, int64 OFS$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$228:;
	struct $6IRVREG* VR$1;
	struct $6IRVREG* VA$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 1ll );
	VR$1 = vr$2;
	*(struct $8FBSYMBOL**)((uint8*)VR$1 + 56ll) = SYMBOL$1;
	*(int64*)((uint8*)VR$1 + 64ll) = OFS$1;
	if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$231;
	{
		struct $6IRVREG* vr$8 = HNEWVR( 8ll, (struct $8FBSYMBOL*)0ull, 1ll );
		VA$1 = vr$8;
		*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) = VA$1;
		*(int64*)((uint8*)VA$1 + 64ll) = OFS$1 + 4ll;
	}
	label$231:;
	label$230:;
	fb$result$1 = VR$1;
	label$229:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVRIDX( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, struct $8FBSYMBOL* SYMBOL$1, int64 OFS$1, int64 MULT$1, struct $6IRVREG* VIDX$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$232:;
	struct $6IRVREG* VR$1;
	struct $6IRVREG* VA$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 2ll );
	VR$1 = vr$2;
	*(struct $8FBSYMBOL**)((uint8*)VR$1 + 56ll) = SYMBOL$1;
	*(int64*)((uint8*)VR$1 + 64ll) = OFS$1;
	*(int64*)((uint8*)VR$1 + 72ll) = MULT$1;
	*(struct $6IRVREG**)((uint8*)VR$1 + 80ll) = VIDX$1;
	if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$235;
	{
		struct $6IRVREG* vr$10 = HNEWVR( 8ll, (struct $8FBSYMBOL*)0ull, 2ll );
		VA$1 = vr$10;
		*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) = VA$1;
		*(int64*)((uint8*)VA$1 + 64ll) = OFS$1 + 4ll;
	}
	label$235:;
	label$234:;
	fb$result$1 = VR$1;
	label$233:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVRPTR( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, int64 OFS$1, struct $6IRVREG* VIDX$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$236:;
	struct $6IRVREG* VR$1;
	struct $6IRVREG* VA$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 3ll );
	VR$1 = vr$2;
	*(int64*)((uint8*)VR$1 + 64ll) = OFS$1;
	*(int64*)((uint8*)VR$1 + 72ll) = 1ll;
	*(struct $6IRVREG**)((uint8*)VR$1 + 80ll) = VIDX$1;
	if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$239;
	{
		struct $6IRVREG* vr$9 = HNEWVR( 8ll, (struct $8FBSYMBOL*)0ull, 3ll );
		VA$1 = vr$9;
		*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) = VA$1;
		*(int64*)((uint8*)VA$1 + 64ll) = OFS$1 + 4ll;
	}
	label$239:;
	label$238:;
	fb$result$1 = VR$1;
	label$237:;
	return fb$result$1;
}

static struct $6IRVREG* _ALLOCVROFS( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, struct $8FBSYMBOL* SYMBOL$1, int64 OFS$1 )
{
	struct $6IRVREG* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$240:;
	struct $6IRVREG* VR$1;
	DTYPE$1 = DTYPE$1 & 511ll;
	struct $6IRVREG* vr$2 = HNEWVR( DTYPE$1, SUBTYPE$1, 5ll );
	VR$1 = vr$2;
	*(struct $8FBSYMBOL**)((uint8*)VR$1 + 56ll) = SYMBOL$1;
	*(int64*)((uint8*)VR$1 + 64ll) = OFS$1;
	fb$result$1 = VR$1;
	label$241:;
	return fb$result$1;
}

static void _SETVREGDATATYPE( struct $6IRVREG* VREG$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	label$242:;
	DTYPE$1 = DTYPE$1 & 511ll;
	if( VREG$1 == (struct $6IRVREG*)0ull) goto label$245;
	{
		int64 TMP$119$2;
		if( (DTYPE$1 & 480ll) == 0ll) goto label$246;
		TMP$119$2 = 24ll;
		goto label$862;
		label$246:;
		TMP$119$2 = DTYPE$1 & 31ll;
		label$862:;
		*($11FB_DATATYPE*)((uint8*)VREG$1 + 8ll) = TMP$119$2;
		*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 16ll) = SUBTYPE$1;
	}
	label$245:;
	label$244:;
	label$243:;
}

static void HRENAME( struct $6IRVREG* VOLD$1, struct $6IRVREG* VNEW$1 )
{
	label$247:;
	struct $9IRTACVREG* T$1;
	struct $6IRVREG* V$1;
	T$1 = *(struct $9IRTACVREG**)((uint8*)VOLD$1 + 96ll);
	label$249:;
	{
		if( *(struct $6IRVREG**)((uint8*)T$1 + 8ll) == (struct $6IRVREG*)0ull) goto label$253;
		{
			if( *(struct $6IRVREG**)((uint8*)*(struct $6IRVREG**)((uint8*)T$1 + 8ll) + 80ll) != VOLD$1) goto label$255;
			{
				*(struct $6IRVREG**)((uint8*)*(struct $6IRVREG**)((uint8*)T$1 + 8ll) + 80ll) = VNEW$1;
			}
			goto label$254;
			label$255:;
			{
				*(struct $6IRVREG**)((uint8*)*(struct $6IRVREG**)((uint8*)T$1 + 8ll) + 88ll) = VNEW$1;
			}
			label$254:;
		}
		label$253:;
		label$252:;
		*(struct $6IRVREG**)T$1 = VNEW$1;
		T$1 = *(struct $9IRTACVREG**)((uint8*)T$1 + 16ll);
	}
	label$251:;
	if( T$1 != (struct $9IRTACVREG*)0ull) goto label$249;
	label$250:;
	*(struct $9IRTACVREG**)((uint8*)VNEW$1 + 96ll) = *(struct $9IRTACVREG**)((uint8*)VOLD$1 + 96ll);
	*(struct $9IRTACVREG**)((uint8*)VNEW$1 + 104ll) = *(struct $9IRTACVREG**)((uint8*)VOLD$1 + 104ll);
	*(struct $5IRTAC**)((uint8*)VNEW$1 + 112ll) = *(struct $5IRTAC**)((uint8*)VOLD$1 + 112ll);
	label$248:;
}

static void HREUSE( struct $5IRTAC* T$1 )
{
	label$256:;
	struct $6IRVREG* V1$1;
	struct $6IRVREG* V2$1;
	struct $6IRVREG* VR$1;
	int64 V1_DTYPE$1;
	int64 V1_DCLASS$1;
	int64 V1_TYP$1;
	int64 V2_DTYPE$1;
	int64 V2_DCLASS$1;
	int64 V2_TYP$1;
	int64 VR_DTYPE$1;
	int64 VR_DCLASS$1;
	int64 VR_TYP$1;
	int64 OP$1;
	OP$1 = *(int64*)((uint8*)T$1 + 8ll);
	V1$1 = *(struct $6IRVREG**)((uint8*)T$1 + 88ll);
	V2$1 = *(struct $6IRVREG**)((uint8*)T$1 + 160ll);
	VR$1 = *(struct $6IRVREG**)((uint8*)T$1 + 16ll);
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$259;
	{
		int64 TMP$120$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$260;
		TMP$120$2 = 24ll;
		goto label$863;
		label$260:;
		TMP$120$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$863:;
		V1_DTYPE$1 = TMP$120$2;
		if( V1_DTYPE$1 != 24ll) goto label$262;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$262:;
		label$261:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$258;
	label$259:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$258:;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$264;
	{
		int64 TMP$121$2;
		V2_TYP$1 = *(int64*)V2$1;
		if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$265;
		TMP$121$2 = 24ll;
		goto label$864;
		label$265:;
		TMP$121$2 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
		label$864:;
		V2_DTYPE$1 = TMP$121$2;
		if( V2_DTYPE$1 != 24ll) goto label$267;
		{
			V2_DTYPE$1 = 9ll;
		}
		label$267:;
		label$266:;
		V2_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V2_DTYPE$1 * 56ll));
	}
	goto label$263;
	label$264:;
	{
		V2_TYP$1 = -1ll;
		V2_DTYPE$1 = 2147483648ll;
		V2_DCLASS$1 = -1ll;
	}
	label$263:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$269;
	{
		int64 TMP$122$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$270;
		TMP$122$2 = 24ll;
		goto label$865;
		label$270:;
		TMP$122$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$865:;
		VR_DTYPE$1 = TMP$122$2;
		if( VR_DTYPE$1 != 24ll) goto label$272;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$272:;
		label$271:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$268;
	label$269:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$268:;
	{
		$13AST_NODECLASS TMP$123$2;
		TMP$123$2 = *($13AST_NODECLASS*)((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll)));
		if( TMP$123$2 != 4ll) goto label$274;
		label$275:;
		{
			if( VR$1 == V1$1) goto label$277;
			{
				int64 TMP$124$4;
				int64 TMP$125$4;
				if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$278;
				TMP$124$4 = 24ll;
				goto label$866;
				label$278:;
				TMP$124$4 = VR_DTYPE$1 & 31ll;
				label$866:;
				if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$279;
				TMP$125$4 = 24ll;
				goto label$867;
				label$279:;
				TMP$125$4 = V1_DTYPE$1 & 31ll;
				label$867:;
				if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$124$4 * 56ll)) + 40ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$125$4 * 56ll)) + 40ll)) goto label$281;
				{
					uint64 vr$29 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( V1$1 );
					if( vr$29 != 2147483647ull) goto label$283;
					{
						HRENAME( VR$1, V1$1 );
					}
					label$283:;
					label$282:;
				}
				label$281:;
				label$280:;
			}
			label$277:;
			label$276:;
		}
		goto label$273;
		label$274:;
		if( TMP$123$2 == 3ll) goto label$285;
		label$286:;
		if( TMP$123$2 != 14ll) goto label$284;
		label$285:;
		{
			int64 V1RENAME$3;
			int64 V2RENAME$3;
			if( VR$1 != (struct $6IRVREG*)0ull) goto label$288;
			{
				goto label$257;
			}
			label$288:;
			label$287:;
			if( V1_DCLASS$1 == V2_DCLASS$1) goto label$290;
			{
				goto label$257;
			}
			label$290:;
			label$289:;
			V1RENAME$3 = 0ll;
			if( VR$1 == V1$1) goto label$292;
			{
				int64 TMP$126$4;
				int64 TMP$127$4;
				if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$293;
				TMP$126$4 = 24ll;
				goto label$868;
				label$293:;
				TMP$126$4 = VR_DTYPE$1 & 31ll;
				label$868:;
				if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$294;
				TMP$127$4 = 24ll;
				goto label$869;
				label$294:;
				TMP$127$4 = V1_DTYPE$1 & 31ll;
				label$869:;
				if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$126$4 * 56ll)) + 40ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$127$4 * 56ll)) + 40ll)) goto label$296;
				{
					uint64 vr$36 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( V1$1 );
					if( vr$36 != 2147483647ull) goto label$298;
					{
						V1RENAME$3 = -1ll;
					}
					label$298:;
					label$297:;
				}
				label$296:;
				label$295:;
			}
			label$292:;
			label$291:;
			V2RENAME$3 = 0ll;
			if( (*(int64*)(((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) + 8ll) & 2ll) == 0ll) goto label$300;
			{
				if( VR$1 == V2$1) goto label$302;
				{
					int64 TMP$128$5;
					int64 TMP$129$5;
					if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$303;
					TMP$128$5 = 24ll;
					goto label$870;
					label$303:;
					TMP$128$5 = VR_DTYPE$1 & 31ll;
					label$870:;
					if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$304;
					TMP$129$5 = 24ll;
					goto label$871;
					label$304:;
					TMP$129$5 = V2_DTYPE$1 & 31ll;
					label$871:;
					if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$128$5 * 56ll)) + 40ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$129$5 * 56ll)) + 40ll)) goto label$306;
					{
						if( V2_TYP$1 == 0ll) goto label$308;
						{
							uint64 vr$45 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( V2$1 );
							if( vr$45 != 2147483647ull) goto label$310;
							{
								V2RENAME$3 = -1ll;
							}
							label$310:;
							label$309:;
						}
						label$308:;
						label$307:;
					}
					label$306:;
					label$305:;
				}
				label$302:;
				label$301:;
			}
			label$300:;
			label$299:;
			if( (V1RENAME$3 & V2RENAME$3) == 0ll) goto label$312;
			{
				if( *(int64*)V1$1 == 4ll) goto label$314;
				{
					V1RENAME$3 = 0ll;
				}
				label$314:;
				label$313:;
			}
			label$312:;
			label$311:;
			if( V1RENAME$3 == 0ll) goto label$316;
			{
				HRENAME( VR$1, V1$1 );
			}
			goto label$315;
			label$316:;
			if( V2RENAME$3 == 0ll) goto label$317;
			{
				{
					fb_MemSwap( (void*)((uint8*)T$1 + 88ll), (void*)((uint8*)T$1 + 160ll), 72ll );
				}
				HRENAME( VR$1, V2$1 );
			}
			label$317:;
			label$315:;
		}
		label$284:;
		label$273:;
	}
	label$257:;
}

static void _FLUSH( void )
{
	label$318:;
	static int64 OP$1;
	static struct $5IRTAC* T$1;
	static struct $6IRVREG* V1$1;
	static struct $6IRVREG* V2$1;
	static struct $6IRVREG* VR$1;
	if( *(int64*)((uint8*)&CTX$ + 112ll) != 0ll) goto label$321;
	{
		goto label$319;
	}
	label$321:;
	label$320:;
	void* vr$1 = FLISTGETHEAD( (struct $6TFLIST*)&CTX$ );
	T$1 = (struct $5IRTAC*)vr$1;
	label$322:;
	{
		*(struct $5IRTAC**)((uint8*)&CTX$ + 120ll) = T$1;
		HREUSE( T$1 );
		OP$1 = *(int64*)((uint8*)T$1 + 8ll);
		V1$1 = *(struct $6IRVREG**)((uint8*)T$1 + 88ll);
		V2$1 = *(struct $6IRVREG**)((uint8*)T$1 + 160ll);
		VR$1 = *(struct $6IRVREG**)((uint8*)T$1 + 16ll);
		{
			uint64 TMP$130$3;
			TMP$130$3 = *(uint64*)((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll)));
			goto label$326;
			label$327:;
			{
				HFLUSHUOP( OP$1, V1$1, VR$1 );
			}
			goto label$325;
			label$328:;
			{
				HFLUSHBOP( OP$1, V1$1, V2$1, VR$1 );
			}
			goto label$325;
			label$329:;
			{
				HFLUSHCOMP( OP$1, V1$1, V2$1, VR$1, *(struct $8FBSYMBOL**)((uint8*)T$1 + 232ll), *($10IR_EMITOPT*)((uint8*)T$1 + 240ll) );
			}
			goto label$325;
			label$330:;
			{
				HFLUSHSTORE( OP$1, V1$1, V2$1 );
			}
			goto label$325;
			label$331:;
			{
				HFLUSHLOAD( OP$1, V1$1, VR$1 );
			}
			goto label$325;
			label$332:;
			{
				HFLUSHCONVERT( OP$1, V1$1, V2$1 );
			}
			goto label$325;
			label$333:;
			{
				HFLUSHSTACK( OP$1, V1$1, V2$1, *(int64*)((uint8*)T$1 + 240ll) );
			}
			goto label$325;
			label$334:;
			{
				HFLUSHCALL( OP$1, *(struct $8FBSYMBOL**)((uint8*)T$1 + 232ll), *(int64*)((uint8*)T$1 + 240ll), V1$1, VR$1 );
			}
			goto label$325;
			label$335:;
			{
				HFLUSHBRANCH( OP$1, *(struct $8FBSYMBOL**)((uint8*)T$1 + 232ll) );
			}
			goto label$325;
			label$336:;
			{
				HFLUSHADDR( OP$1, V1$1, VR$1 );
			}
			goto label$325;
			label$337:;
			{
				HFLUSHMEM( OP$1, V1$1, V2$1, *(int64*)((uint8*)T$1 + 240ll), *(void**)((uint8*)T$1 + 248ll) );
			}
			goto label$325;
			label$338:;
			{
				HFLUSHDBG( OP$1, *(struct $8FBSYMBOL**)((uint8*)T$1 + 232ll), *(int64*)((uint8*)T$1 + 240ll), *(char**)((uint8*)T$1 + 248ll) );
			}
			goto label$325;
			label$339:;
			{
				HFLUSHLIT( OP$1, *(char**)((uint8*)T$1 + 232ll) );
			}
			goto label$325;
			label$326:;
			static const void* tmp$183[30ll] = {
				&&label$331,
				&&label$330,
				&&label$328,
				&&label$327,
				&&label$332,
				&&label$336,
				&&label$335,
				&&label$325,
				&&label$334,
				&&label$325,
				&&label$333,
				&&label$337,
				&&label$325,
				&&label$329,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$325,
				&&label$339,
				&&label$325,
				&&label$325,
				&&label$338,
			};
			if( (TMP$130$3 - 1ull) > 29ull ) goto label$325;
			goto *tmp$183[TMP$130$3 - 1ull];
			label$325:;
		}
		if( *(int64*)((uint8*)&ENV$ + 232ll) < 1ll) goto label$341;
		{
			if( *(int64*)((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) == 9ll) goto label$343;
			{
				if( VR$1 == (struct $6IRVREG*)0ull) goto label$345;
				{
					if( *(int64*)((uint8*)VR$1 + 32ll) != 0ll) goto label$347;
					{
						*($12IR_REGFAMILY*)((uint8*)VR$1 + 32ll) = 1ll;
						label$347:;
					}
				}
				label$345:;
				label$344:;
			}
			label$343:;
			label$342:;
		}
		label$341:;
		label$340:;
		void* vr$22 = FLISTGETNEXT( (void*)T$1 );
		T$1 = (struct $5IRTAC*)vr$22;
	}
	label$324:;
	if( T$1 != (struct $5IRTAC*)0ull) goto label$322;
	label$323:;
	*(struct $5IRTAC**)((uint8*)&CTX$ + 120ll) = (struct $5IRTAC*)0ull;
	*(int64*)((uint8*)&CTX$ + 112ll) = 0ll;
	FLISTRESET( (struct $6TFLIST*)&CTX$ );
	FLISTRESET( (struct $6TFLIST*)((uint8*)&CTX$ + 128ll) );
	HFREEPRESERVEDREGS(  );
	label$319:;
}

static void HFLUSHBRANCH( int64 OP$1, struct $8FBSYMBOL* LABEL$1 )
{
	label$348:;
	{
		uint64 TMP$131$2;
		TMP$131$2 = (uint64)OP$1;
		goto label$351;
		label$352:;
		{
			EMITLABEL( LABEL$1 );
		}
		goto label$350;
		label$353:;
		{
			EMITJUMP( LABEL$1 );
		}
		goto label$350;
		label$354:;
		{
			EMITCALL( LABEL$1, 0ll );
		}
		goto label$350;
		label$355:;
		{
			EMITRET( 0ll );
		}
		goto label$350;
		label$356:;
		{
			EMITBRANCH( OP$1, LABEL$1 );
		}
		goto label$350;
		label$351:;
		static const void* tmp$184[4ll] = {
			&&label$353,
			&&label$354,
			&&label$352,
			&&label$355,
		};
		if( (TMP$131$2 - 99ull) > 3ull ) goto label$356;
		goto *tmp$184[TMP$131$2 - 99ull];
		label$350:;
	}
	label$349:;
}

static void HFREEPRESERVEDREGS( void )
{
	label$357:;
	static int64 CLASS_$1;
	static int64 REG$1;
	{
		CLASS_$1 = 0ll;
		label$362:;
		{
			int64 vr$1 = (*(tmp$90*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) + 56ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) );
			REG$1 = vr$1;
			label$363:;
			if( REG$1 == -1ll) goto label$364;
			{
				int64 vr$5 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) + 32ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))), REG$1 );
				if( vr$5 != 0ll) goto label$366;
				{
					(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) + 24ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))), REG$1 );
				}
				label$366:;
				label$365:;
				int64 vr$12 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))) + 64ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$1 << (3ll & 63ll))), REG$1 );
				REG$1 = vr$12;
			}
			goto label$363;
			label$364:;
		}
		label$360:;
		CLASS_$1 = CLASS_$1 + 1ll;
		label$359:;
		if( CLASS_$1 <= 1ll) goto label$362;
		label$361:;
	}
	label$358:;
}

static int64 HPRESERVEREG( struct $6IRVREG* VR$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$367:;
	int64 VR_DCLASS$1;
	int64 VR_DTYPE$1;
	int64 VR_TYP$1;
	int64 PRESERVED1$1;
	int64 PRESERVED2$1;
	int64 FREG1$1;
	int64 FREG2$1;
	struct $6IRVREG ORIGVREG$1;
	struct $6IRVREG ORIGVAUX$1;
	struct $6IRVREG DESTVREG$1;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$370;
	{
		int64 TMP$132$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$371;
		TMP$132$2 = 24ll;
		goto label$872;
		label$371:;
		TMP$132$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$872:;
		VR_DTYPE$1 = TMP$132$2;
		if( VR_DTYPE$1 != 24ll) goto label$373;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$373:;
		label$372:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$369;
	label$370:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$369:;
	__builtin_memcpy( &ORIGVREG$1, VR$1, 120 );
	int64 vr$9 = (*(tmp$42*)((uint8*)&EMIT$ + 336ll))( VR_DCLASS$1, *(int64*)((uint8*)VR$1 + 24ll) );
	PRESERVED1$1 = vr$9;
	if( ((int64)-(VR_DTYPE$1 == 13ll) | (int64)-(VR_DTYPE$1 == 14ll)) == 0ll) goto label$375;
	{
		__builtin_memcpy( &ORIGVAUX$1, *(struct $6IRVREG**)((uint8*)VR$1 + 88ll), 120 );
		*(struct $6IRVREG**)((uint8*)&ORIGVREG$1 + 88ll) = &ORIGVAUX$1;
		int64 vr$18 = (*(tmp$42*)((uint8*)&EMIT$ + 336ll))( VR_DCLASS$1, *(int64*)((uint8*)*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) + 24ll) );
		PRESERVED2$1 = vr$18;
	}
	goto label$374;
	label$375:;
	{
		PRESERVED2$1 = -1ll;
	}
	label$374:;
	if( (PRESERVED1$1 & PRESERVED2$1) == 0ll) goto label$377;
	{
		fb$result$1 = -1ll;
		goto label$368;
	}
	label$377:;
	label$376:;
	if( PRESERVED1$1 != 0ll) goto label$379;
	{
		int64 vr$20 = (*(tmp$42*)((uint8*)&EMIT$ + 344ll))( VR_DCLASS$1, VR_DTYPE$1 );
		FREG1$1 = vr$20;
		if( FREG1$1 != -1ll) goto label$381;
		{
			fb$result$1 = 0ll;
			goto label$368;
		}
		label$381:;
		label$380:;
		int64 vr$22 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))) + 16ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), FREG1$1, VR$1, (struct $6IRVREG*)0ull );
		*(int64*)((uint8*)VR$1 + 24ll) = vr$22;
	}
	label$379:;
	label$378:;
	if( PRESERVED2$1 != 0ll) goto label$383;
	{
		int64 vr$26 = (*(tmp$42*)((uint8*)&EMIT$ + 344ll))( 0ll, 8ll );
		FREG2$1 = vr$26;
		if( FREG2$1 != -1ll) goto label$385;
		{
			if( PRESERVED1$1 != 0ll) goto label$387;
			{
				(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))) + 24ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)VR$1 + 24ll) );
				*(int64*)((uint8*)VR$1 + 24ll) = *(int64*)((uint8*)&ORIGVREG$1 + 24ll);
			}
			label$387:;
			label$386:;
			fb$result$1 = 0ll;
			goto label$368;
		}
		label$385:;
		label$384:;
		int64 vr$33 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)REGTB$ + 16ll))( *(struct $8REGCLASS**)REGTB$, FREG2$1, *(struct $6IRVREG**)((uint8*)VR$1 + 88ll), VR$1 );
		*(int64*)((uint8*)*(struct $6IRVREG**)((uint8*)VR$1 + 88ll) + 24ll) = vr$33;
	}
	label$383:;
	label$382:;
	if( ~(PRESERVED1$1 | PRESERVED2$1) == 0ll) goto label$389;
	{
		EMITMOV( VR$1, &ORIGVREG$1 );
	}
	goto label$388;
	label$389:;
	if( PRESERVED1$1 != 0ll) goto label$390;
	{
		if( ((int64)-(VR_DTYPE$1 == 13ll) | (int64)-(VR_DTYPE$1 == 14ll)) == 0ll) goto label$392;
		{
			__builtin_memcpy( &DESTVREG$1, VR$1, 120 );
			*($11FB_DATATYPE*)((uint8*)&DESTVREG$1 + 8ll) = 8ll;
			*(struct $6IRVREG**)((uint8*)&DESTVREG$1 + 88ll) = (struct $6IRVREG*)0ull;
			*($11FB_DATATYPE*)((uint8*)&ORIGVREG$1 + 8ll) = 8ll;
			*(struct $6IRVREG**)((uint8*)&ORIGVREG$1 + 88ll) = (struct $6IRVREG*)0ull;
			EMITMOV( &DESTVREG$1, &ORIGVREG$1 );
		}
		goto label$391;
		label$392:;
		{
			EMITMOV( VR$1, &ORIGVREG$1 );
		}
		label$391:;
	}
	goto label$388;
	label$390:;
	{
		EMITMOV( *(struct $6IRVREG**)((uint8*)VR$1 + 88ll), &ORIGVAUX$1 );
	}
	label$388:;
	if( PRESERVED1$1 != 0ll) goto label$394;
	{
		(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))) + 24ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)&ORIGVREG$1 + 24ll) );
	}
	label$394:;
	label$393:;
	if( PRESERVED2$1 != 0ll) goto label$396;
	{
		(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)REGTB$ + 24ll))( *(struct $8REGCLASS**)REGTB$, *(int64*)((uint8*)&ORIGVAUX$1 + 24ll) );
	}
	label$396:;
	label$395:;
	fb$result$1 = -1ll;
	label$368:;
	return fb$result$1;
}

static void HPRESERVEREGS( struct $6IRVREG* PTRVREG$1 )
{
	label$397:;
	int64 NPREG$1;
	int64 REG$1;
	struct $6IRVREG* VR$1;
	struct $6IRVREG* VAUXPARENT$1;
	{
		int64 CLASS_$2;
		CLASS_$2 = 0ll;
		label$402:;
		{
			NPREG$1 = -1ll;
			if( CLASS_$2 != 0ll) goto label$404;
			{
				if( PTRVREG$1 == (struct $6IRVREG*)0ull) goto label$406;
				{
					{
						$15IRVREGTYPE_ENUM TMP$133$6;
						TMP$133$6 = *($15IRVREGTYPE_ENUM*)PTRVREG$1;
						if( TMP$133$6 != 4ll) goto label$408;
						label$409:;
						{
							NPREG$1 = *(int64*)((uint8*)PTRVREG$1 + 24ll);
						}
						goto label$407;
						label$408:;
						if( TMP$133$6 == 2ll) goto label$411;
						label$412:;
						if( TMP$133$6 != 3ll) goto label$410;
						label$411:;
						{
							PTRVREG$1 = *(struct $6IRVREG**)((uint8*)PTRVREG$1 + 80ll);
							if( PTRVREG$1 == (struct $6IRVREG*)0ull) goto label$414;
							{
								NPREG$1 = *(int64*)((uint8*)PTRVREG$1 + 24ll);
							}
							label$414:;
							label$413:;
						}
						label$410:;
						label$407:;
					}
					PTRVREG$1 = (struct $6IRVREG*)0ull;
				}
				label$406:;
				label$405:;
			}
			label$404:;
			label$403:;
			int64 vr$5 = (*(tmp$90*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 56ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) );
			REG$1 = vr$5;
			label$415:;
			if( REG$1 == -1ll) goto label$416;
			{
				int64 vr$9 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 32ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1 );
				if( ((int64)-(vr$9 == 0ll) & (int64)-(REG$1 != NPREG$1)) == 0ll) goto label$418;
				{
					struct $6IRVREG* vr$17 = (*(tmp$91*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 72ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1, &VAUXPARENT$1 );
					VR$1 = vr$17;
					if( VAUXPARENT$1 == (struct $6IRVREG*)0ull) goto label$420;
					{
						VR$1 = VAUXPARENT$1;
					}
					label$420:;
					label$419:;
					int64 vr$20 = HPRESERVEREG( VR$1 );
					if( vr$20 != 0ll) goto label$422;
					{
						(*(tmp$46*)((uint8*)&IR$ + 528ll))( VR$1, (struct $6IRVREG*)0ull );
					}
					label$422:;
					label$421:;
				}
				label$418:;
				label$417:;
				int64 vr$22 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 64ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1 );
				REG$1 = vr$22;
			}
			goto label$415;
			label$416:;
		}
		label$400:;
		CLASS_$2 = CLASS_$2 + 1ll;
		label$399:;
		if( CLASS_$2 <= 1ll) goto label$402;
		label$401:;
	}
	label$398:;
}

static void HLOADPOINTER( struct $6IRVREG* V1$1 )
{
	label$423:;
	int64 VTYPE$1;
	int64 DTYPE$1;
	int64 DCLASS$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$426;
	{
		int64 TMP$134$2;
		VTYPE$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$427;
		TMP$134$2 = 24ll;
		goto label$873;
		label$427:;
		TMP$134$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$873:;
		DTYPE$1 = TMP$134$2;
		if( DTYPE$1 != 24ll) goto label$429;
		{
			DTYPE$1 = 9ll;
		}
		label$429:;
		label$428:;
		DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (DTYPE$1 * 56ll));
	}
	goto label$425;
	label$426:;
	{
		VTYPE$1 = -1ll;
		DTYPE$1 = 2147483648ll;
		DCLASS$1 = -1ll;
	}
	label$425:;
	HLOADIDX( V1$1 );
	if( VTYPE$1 != 4ll) goto label$431;
	{
		int64 TMP$135$2;
		if( (DTYPE$1 & 480ll) == 0ll) goto label$432;
		TMP$135$2 = 24ll;
		goto label$874;
		label$432:;
		TMP$135$2 = DTYPE$1 & 31ll;
		label$874:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$135$2 * 56ll)) + 8ll) );
	}
	label$431:;
	label$430:;
	label$424:;
}

static void HLOADRESULT( struct $8FBSYMBOL* PROC$1, struct $6IRVREG* VR$1 )
{
	label$433:;
	int64 VTYPE$1;
	int64 DTYPE$1;
	int64 DCLASS$1;
	int64 REG1$1;
	int64 REG2$1;
	struct $6IRVREG* VA$1;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$436;
	{
		if( VR$1 == (struct $6IRVREG*)0ull) goto label$438;
		{
			int64 TMP$136$3;
			VTYPE$1 = *(int64*)VR$1;
			if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$439;
			TMP$136$3 = 24ll;
			goto label$875;
			label$439:;
			TMP$136$3 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
			label$875:;
			DTYPE$1 = TMP$136$3;
			if( DTYPE$1 != 24ll) goto label$441;
			{
				DTYPE$1 = 9ll;
			}
			label$441:;
			label$440:;
			DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (DTYPE$1 * 56ll));
		}
		goto label$437;
		label$438:;
		{
			VTYPE$1 = -1ll;
			DTYPE$1 = 2147483648ll;
			DCLASS$1 = -1ll;
		}
		label$437:;
		(*(tmp$101*)((uint8*)&EMIT$ + 360ll))( DTYPE$1, DCLASS$1, &REG1$1, &REG2$1 );
		if( ((int64)-(DTYPE$1 == 13ll) | (int64)-(DTYPE$1 == 14ll)) == 0ll) goto label$443;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)VR$1 + 88ll);
			int64 vr$13 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))) + 16ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))), REG2$1, VA$1, VR$1 );
			*(int64*)((uint8*)VA$1 + 24ll) = vr$13;
			*($15IRVREGTYPE_ENUM*)VA$1 = 4ll;
		}
		label$443:;
		label$442:;
		int64 vr$19 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))) + 16ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))), REG1$1, VR$1, (struct $6IRVREG*)0ull );
		*(int64*)((uint8*)VR$1 + 24ll) = vr$19;
		*($15IRVREGTYPE_ENUM*)VR$1 = 4ll;
		HFREEREG( VR$1, 0ll );
	}
	goto label$435;
	label$436:;
	{
		int64 TMP$137$2;
		if( (*(int64*)((uint8*)PROC$1 + 160ll) & 480ll) == 0ll) goto label$444;
		TMP$137$2 = 24ll;
		goto label$876;
		label$444:;
		TMP$137$2 = *(int64*)((uint8*)PROC$1 + 160ll) & 31ll;
		label$876:;
		if( ((int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$137$2 * 56ll)) == 1ll) & (int64)-(*(int64*)((uint8*)PROC$1 + 176ll) != 1ll)) == 0ll) goto label$446;
		{
			EMITPOPST0(  );
		}
		label$446:;
		label$445:;
	}
	label$435:;
	label$434:;
}

static void HFLUSHCALL( int64 OP$1, struct $8FBSYMBOL* PROC$1, int64 BYTESTOPOP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$447:;
	{
		if( OP$1 != 103ll) goto label$450;
		label$451:;
		{
			HPRESERVEREGS( (struct $6IRVREG*)0ull );
			EMITCALL( PROC$1, BYTESTOPOP$1 );
			HLOADRESULT( PROC$1, VR$1 );
		}
		goto label$449;
		label$450:;
		if( OP$1 != 104ll) goto label$452;
		label$453:;
		{
			HPRESERVEREGS( V1$1 );
			HLOADPOINTER( V1$1 );
			EMITCALLPTR( V1$1, BYTESTOPOP$1 );
			HFREEREG( V1$1, 0ll );
			HLOADRESULT( PROC$1, VR$1 );
		}
		goto label$449;
		label$452:;
		if( OP$1 != 105ll) goto label$454;
		label$455:;
		{
			HLOADPOINTER( V1$1 );
			EMITJUMPPTR( V1$1 );
			HFREEREG( V1$1, 0ll );
		}
		goto label$449;
		label$454:;
		{
		}
		label$456:;
		label$449:;
	}
	label$448:;
}

static void HFLUSHSTACK( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1, int64 EX$1 )
{
	label$457:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static struct $6IRVREG* VA$1;
	if( OP$1 != 92ll) goto label$460;
	{
		EMITSTACKALIGN( EX$1 );
		goto label$458;
	}
	label$460:;
	label$459:;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$462;
	{
		int64 TMP$138$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$463;
		TMP$138$2 = 24ll;
		goto label$877;
		label$463:;
		TMP$138$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$877:;
		V1_DTYPE$1 = TMP$138$2;
		if( V1_DTYPE$1 != 24ll) goto label$465;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$465:;
		label$464:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$461;
	label$462:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$461:;
	HLOADIDX( V1$1 );
	HLOADIDX( VR$1 );
	if( V1_TYP$1 != 4ll) goto label$467;
	{
		int64 TMP$139$2;
		if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$469;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V1_DTYPE$1 = 8ll;
		}
		label$469:;
		label$468:;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$470;
		TMP$139$2 = 24ll;
		goto label$878;
		label$470:;
		TMP$139$2 = V1_DTYPE$1 & 31ll;
		label$878:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$139$2 * 56ll)) + 8ll) );
	}
	label$467:;
	label$466:;
	{
		if( OP$1 != 89ll) goto label$472;
		label$473:;
		{
			if( VR$1 == (struct $6IRVREG*)0ull) goto label$475;
			{
				EMITLOAD( VR$1, V1$1 );
			}
			goto label$474;
			label$475:;
			{
				EMITPUSH( V1$1 );
			}
			label$474:;
		}
		goto label$471;
		label$472:;
		if( OP$1 != 91ll) goto label$476;
		label$477:;
		{
			EMITPUSHUDT( V1$1, EX$1 );
		}
		goto label$471;
		label$476:;
		if( OP$1 != 90ll) goto label$478;
		label$479:;
		{
			EMITPOP( V1$1 );
		}
		label$478:;
		label$471:;
	}
	HFREEREG( V1$1, 0ll );
	label$458:;
}

static void HFLUSHUOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$480:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 VR_TYP$1;
	static int64 VR_DTYPE$1;
	static int64 VR_DCLASS$1;
	static struct $6IRVREG* VA$1;
	static int64 V1VECTOR$1;
	V1VECTOR$1 = *(int64*)((uint8*)V1$1 + 40ll);
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$483;
	{
		int64 TMP$140$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$484;
		TMP$140$2 = 24ll;
		goto label$879;
		label$484:;
		TMP$140$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$879:;
		V1_DTYPE$1 = TMP$140$2;
		if( V1_DTYPE$1 != 24ll) goto label$486;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$486:;
		label$485:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$482;
	label$483:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$482:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$488;
	{
		int64 TMP$141$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$489;
		TMP$141$2 = 24ll;
		goto label$880;
		label$489:;
		TMP$141$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$880:;
		VR_DTYPE$1 = TMP$141$2;
		if( VR_DTYPE$1 != 24ll) goto label$491;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$491:;
		label$490:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$487;
	label$488:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$487:;
	HLOADIDX( V1$1 );
	HLOADIDX( VR$1 );
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$493;
	{
		if( V1$1 == VR$1) goto label$495;
		{
			int64 TMP$142$3;
			if( ((int64)-(VR_DTYPE$1 == 13ll) | (int64)-(VR_DTYPE$1 == 14ll)) == 0ll) goto label$497;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)VR$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VA$1, VR$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				VR_DTYPE$1 = 8ll;
			}
			label$497:;
			label$496:;
			if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$498;
			TMP$142$3 = 24ll;
			goto label$881;
			label$498:;
			TMP$142$3 = VR_DTYPE$1 & 31ll;
			label$881:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VR$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$142$3 * 56ll)) + 8ll) );
		}
		label$495:;
		label$494:;
	}
	label$493:;
	label$492:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$500;
	{
		int64 TMP$143$2;
		if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$502;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V1_DTYPE$1 = 8ll;
		}
		label$502:;
		label$501:;
		if( OP$1 != 76ll) goto label$504;
		{
			*(int64*)((uint8*)V1$1 + 40ll) = 0ll;
		}
		label$504:;
		label$503:;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$505;
		TMP$143$2 = 24ll;
		goto label$882;
		label$505:;
		TMP$143$2 = V1_DTYPE$1 & 31ll;
		label$882:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$143$2 * 56ll)) + 8ll) );
		if( OP$1 != 76ll) goto label$507;
		{
			*(int64*)((uint8*)V1$1 + 40ll) = V1VECTOR$1;
		}
		label$507:;
		label$506:;
	}
	label$500:;
	label$499:;
	{
		uint64 TMP$144$2;
		TMP$144$2 = (uint64)OP$1;
		goto label$509;
		label$510:;
		{
			EMITNEG( V1$1 );
		}
		goto label$508;
		label$511:;
		{
			EMITNOT( V1$1 );
		}
		goto label$508;
		label$512:;
		{
			EMITHADD( V1$1 );
			*(int64*)((uint8*)V1$1 + 40ll) = 0ll;
		}
		goto label$508;
		label$513:;
		{
			EMITABS( V1$1 );
		}
		goto label$508;
		label$514:;
		{
			EMITSGN( V1$1 );
		}
		goto label$508;
		label$515:;
		{
			EMITFIX( V1$1 );
		}
		goto label$508;
		label$516:;
		{
			EMITFRAC( V1$1 );
		}
		goto label$508;
		label$517:;
		{
			EMITCONVFD2FS( V1$1 );
		}
		goto label$508;
		label$518:;
		{
			EMITSIN( V1$1 );
		}
		goto label$508;
		label$519:;
		{
			EMITASIN( V1$1 );
		}
		goto label$508;
		label$520:;
		{
			EMITCOS( V1$1 );
		}
		goto label$508;
		label$521:;
		{
			EMITACOS( V1$1 );
		}
		goto label$508;
		label$522:;
		{
			EMITTAN( V1$1 );
		}
		goto label$508;
		label$523:;
		{
			EMITATAN( V1$1 );
		}
		goto label$508;
		label$524:;
		{
			EMITSQRT( V1$1 );
		}
		goto label$508;
		label$525:;
		{
			EMITRSQRT( V1$1 );
		}
		goto label$508;
		label$526:;
		{
			EMITRCP( V1$1 );
		}
		goto label$508;
		label$527:;
		{
			EMITLOG( V1$1 );
		}
		goto label$508;
		label$528:;
		{
			EMITEXP( V1$1 );
		}
		goto label$508;
		label$529:;
		{
			EMITFLOOR( V1$1 );
		}
		goto label$508;
		label$530:;
		{
			EMITSWZREP( V1$1 );
		}
		goto label$508;
		label$509:;
		static const void* tmp$185[25ll] = {
			&&label$511,
			&&label$508,
			&&label$508,
			&&label$510,
			&&label$512,
			&&label$513,
			&&label$514,
			&&label$518,
			&&label$519,
			&&label$520,
			&&label$521,
			&&label$522,
			&&label$523,
			&&label$508,
			&&label$524,
			&&label$525,
			&&label$526,
			&&label$527,
			&&label$528,
			&&label$529,
			&&label$515,
			&&label$516,
			&&label$508,
			&&label$517,
			&&label$530,
		};
		if( (TMP$144$2 - 52ull) > 24ull ) goto label$508;
		goto *tmp$185[TMP$144$2 - 52ull];
		label$508:;
	}
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$532;
	{
		if( V1$1 == VR$1) goto label$534;
		{
			EMITMOV( VR$1, V1$1 );
		}
		label$534:;
		label$533:;
	}
	label$532:;
	label$531:;
	HFREEREG( V1$1, 0ll );
	HFREEREG( VR$1, 0ll );
	label$481:;
}

static void HFLUSHBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1 )
{
	label$535:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 V2_TYP$1;
	static int64 V2_DTYPE$1;
	static int64 V2_DCLASS$1;
	static int64 VR_TYP$1;
	static int64 VR_DTYPE$1;
	static int64 VR_DCLASS$1;
	static struct $6IRVREG* VA$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$538;
	{
		int64 TMP$145$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$539;
		TMP$145$2 = 24ll;
		goto label$883;
		label$539:;
		TMP$145$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$883:;
		V1_DTYPE$1 = TMP$145$2;
		if( V1_DTYPE$1 != 24ll) goto label$541;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$541:;
		label$540:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$537;
	label$538:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$537:;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$543;
	{
		int64 TMP$146$2;
		V2_TYP$1 = *(int64*)V2$1;
		if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$544;
		TMP$146$2 = 24ll;
		goto label$884;
		label$544:;
		TMP$146$2 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
		label$884:;
		V2_DTYPE$1 = TMP$146$2;
		if( V2_DTYPE$1 != 24ll) goto label$546;
		{
			V2_DTYPE$1 = 9ll;
		}
		label$546:;
		label$545:;
		V2_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V2_DTYPE$1 * 56ll));
	}
	goto label$542;
	label$543:;
	{
		V2_TYP$1 = -1ll;
		V2_DTYPE$1 = 2147483648ll;
		V2_DCLASS$1 = -1ll;
	}
	label$542:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$548;
	{
		int64 TMP$147$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$549;
		TMP$147$2 = 24ll;
		goto label$885;
		label$549:;
		TMP$147$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$885:;
		VR_DTYPE$1 = TMP$147$2;
		if( VR_DTYPE$1 != 24ll) goto label$551;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$551:;
		label$550:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$547;
	label$548:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$547:;
	HLOADIDX( V1$1 );
	HLOADIDX( V2$1 );
	HLOADIDX( VR$1 );
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$553;
	{
		if( V2_TYP$1 == 0ll) goto label$555;
		{
			int64 TMP$148$3;
			if( ((int64)-(V2_DTYPE$1 == 13ll) | (int64)-(V2_DTYPE$1 == 14ll)) == 0ll) goto label$557;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), VA$1, V2$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				V2_DTYPE$1 = 8ll;
			}
			label$557:;
			label$556:;
			if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$558;
			TMP$148$3 = 24ll;
			goto label$886;
			label$558:;
			TMP$148$3 = V2_DTYPE$1 & 31ll;
			label$886:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), V2$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$148$3 * 56ll)) + 8ll) );
		}
		label$555:;
		label$554:;
	}
	goto label$552;
	label$553:;
	{
		int64 TMP$150$2;
		if( V2_TYP$1 != 4ll) goto label$560;
		{
			int64 TMP$149$3;
			if( ((int64)-(V2_DTYPE$1 == 13ll) | (int64)-(V2_DTYPE$1 == 14ll)) == 0ll) goto label$562;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), VA$1, V2$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				V2_DTYPE$1 = 8ll;
			}
			label$562:;
			label$561:;
			if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$563;
			TMP$149$3 = 24ll;
			goto label$887;
			label$563:;
			TMP$149$3 = V2_DTYPE$1 & 31ll;
			label$887:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), V2$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$149$3 * 56ll)) + 8ll) );
		}
		label$560:;
		label$559:;
		if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$565;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V1_DTYPE$1 = 8ll;
		}
		label$565:;
		label$564:;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$566;
		TMP$150$2 = 24ll;
		goto label$888;
		label$566:;
		TMP$150$2 = V1_DTYPE$1 & 31ll;
		label$888:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$150$2 * 56ll)) + 8ll) );
	}
	label$552:;
	{
		uint64 TMP$151$2;
		TMP$151$2 = (uint64)OP$1;
		goto label$568;
		label$569:;
		{
			EMITADD( V1$1, V2$1 );
		}
		goto label$567;
		label$570:;
		{
			EMITSUB( V1$1, V2$1 );
		}
		goto label$567;
		label$571:;
		{
			EMITMUL( V1$1, V2$1 );
		}
		goto label$567;
		label$572:;
		{
			EMITDIV( V1$1, V2$1 );
		}
		goto label$567;
		label$573:;
		{
			EMITINTDIV( V1$1, V2$1 );
		}
		goto label$567;
		label$574:;
		{
			EMITMOD( V1$1, V2$1 );
		}
		goto label$567;
		label$575:;
		{
			EMITSHL( V1$1, V2$1 );
		}
		goto label$567;
		label$576:;
		{
			EMITSHR( V1$1, V2$1 );
		}
		goto label$567;
		label$577:;
		{
			EMITAND( V1$1, V2$1 );
		}
		goto label$567;
		label$578:;
		{
			EMITOR( V1$1, V2$1 );
		}
		goto label$567;
		label$579:;
		{
			EMITXOR( V1$1, V2$1 );
		}
		goto label$567;
		label$580:;
		{
			EMITEQV( V1$1, V2$1 );
		}
		goto label$567;
		label$581:;
		{
			EMITIMP( V1$1, V2$1 );
		}
		goto label$567;
		label$582:;
		{
			EMITATN2( V1$1, V2$1 );
		}
		goto label$567;
		label$583:;
		{
			EMITPOW( V1$1, V2$1 );
		}
		goto label$567;
		label$568:;
		static const void* tmp$186[38ll] = {
			&&label$569,
			&&label$570,
			&&label$571,
			&&label$572,
			&&label$573,
			&&label$574,
			&&label$577,
			&&label$578,
			&&label$567,
			&&label$567,
			&&label$579,
			&&label$580,
			&&label$581,
			&&label$575,
			&&label$576,
			&&label$583,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$567,
			&&label$582,
		};
		if( (TMP$151$2 - 28ull) > 37ull ) goto label$567;
		goto *tmp$186[TMP$151$2 - 28ull];
		label$567:;
	}
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$585;
	{
		if( V1$1 == VR$1) goto label$587;
		{
			int64 TMP$152$3;
			if( ((int64)-(VR_DTYPE$1 == 13ll) | (int64)-(VR_DTYPE$1 == 14ll)) == 0ll) goto label$589;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)VR$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VA$1, VR$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				VR_DTYPE$1 = 8ll;
			}
			label$589:;
			label$588:;
			if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$590;
			TMP$152$3 = 24ll;
			goto label$889;
			label$590:;
			TMP$152$3 = VR_DTYPE$1 & 31ll;
			label$889:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VR$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$152$3 * 56ll)) + 8ll) );
			EMITMOV( VR$1, V1$1 );
		}
		label$587:;
		label$586:;
	}
	label$585:;
	label$584:;
	HFREEREG( V1$1, 0ll );
	HFREEREG( V2$1, 0ll );
	HFREEREG( VR$1, 0ll );
	label$536:;
}

static void HFLUSHCOMP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* LABEL$1, $10IR_EMITOPT OPTIONS$1 )
{
	label$591:;
	static FBSTRING LNAME$1;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 V2_TYP$1;
	static int64 V2_DTYPE$1;
	static int64 V2_DCLASS$1;
	static int64 VR_TYP$1;
	static int64 VR_DTYPE$1;
	static int64 VR_DCLASS$1;
	static struct $6IRVREG* VA$1;
	static int64 DOLOAD$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$594;
	{
		int64 TMP$153$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$595;
		TMP$153$2 = 24ll;
		goto label$890;
		label$595:;
		TMP$153$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$890:;
		V1_DTYPE$1 = TMP$153$2;
		if( V1_DTYPE$1 != 24ll) goto label$597;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$597:;
		label$596:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$593;
	label$594:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$593:;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$599;
	{
		int64 TMP$154$2;
		V2_TYP$1 = *(int64*)V2$1;
		if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$600;
		TMP$154$2 = 24ll;
		goto label$891;
		label$600:;
		TMP$154$2 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
		label$891:;
		V2_DTYPE$1 = TMP$154$2;
		if( V2_DTYPE$1 != 24ll) goto label$602;
		{
			V2_DTYPE$1 = 9ll;
		}
		label$602:;
		label$601:;
		V2_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V2_DTYPE$1 * 56ll));
	}
	goto label$598;
	label$599:;
	{
		V2_TYP$1 = -1ll;
		V2_DTYPE$1 = 2147483648ll;
		V2_DCLASS$1 = -1ll;
	}
	label$598:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$604;
	{
		int64 TMP$155$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$605;
		TMP$155$2 = 24ll;
		goto label$892;
		label$605:;
		TMP$155$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$892:;
		VR_DTYPE$1 = TMP$155$2;
		if( VR_DTYPE$1 != 24ll) goto label$607;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$607:;
		label$606:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$603;
	label$604:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$603:;
	HLOADIDX( V1$1 );
	HLOADIDX( V2$1 );
	HLOADIDX( VR$1 );
	DOLOAD$1 = 0ll;
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$609;
	{
		if( V2_DCLASS$1 != 0ll) goto label$611;
		{
			if( V2_TYP$1 == 0ll) goto label$613;
			{
				if( V1_DCLASS$1 == 1ll) goto label$615;
				{
					DOLOAD$1 = -1ll;
				}
				label$615:;
				label$614:;
			}
			label$613:;
			label$612:;
		}
		label$611:;
		label$610:;
	}
	label$609:;
	label$608:;
	if( ((int64)-(V2_TYP$1 == 4ll) | DOLOAD$1) == 0ll) goto label$617;
	{
		int64 TMP$156$2;
		if( ((int64)-(V2_DTYPE$1 == 13ll) | (int64)-(V2_DTYPE$1 == 14ll)) == 0ll) goto label$619;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), VA$1, V2$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V2_DTYPE$1 = 8ll;
		}
		label$619:;
		label$618:;
		if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$620;
		TMP$156$2 = 24ll;
		goto label$893;
		label$620:;
		TMP$156$2 = V2_DTYPE$1 & 31ll;
		label$893:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), V2$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$156$2 * 56ll)) + 8ll) );
		V2_TYP$1 = 4ll;
	}
	label$617:;
	label$616:;
	DOLOAD$1 = 0ll;
	if( ((int64)-(VR$1 != (struct $6IRVREG*)0ull) & (int64)-(VR$1 == V1$1)) == 0ll) goto label$622;
	{
		DOLOAD$1 = -1ll;
	}
	goto label$621;
	label$622:;
	if( V1_DCLASS$1 != 1ll) goto label$623;
	{
		DOLOAD$1 = -1ll;
	}
	goto label$621;
	label$623:;
	if( V1_TYP$1 != 0ll) goto label$624;
	{
		DOLOAD$1 = -1ll;
	}
	goto label$621;
	label$624:;
	if( ((int64)-(V1_TYP$1 == 5ll) & (int64)-(V2_TYP$1 == 0ll)) == 0ll) goto label$625;
	{
		DOLOAD$1 = -1ll;
	}
	goto label$621;
	label$625:;
	if( V2_TYP$1 == 4ll) goto label$626;
	{
		if( V2_TYP$1 == 0ll) goto label$628;
		{
			DOLOAD$1 = -1ll;
		}
		label$628:;
		label$627:;
	}
	goto label$621;
	label$626:;
	if( V1_TYP$1 != 5ll) goto label$629;
	{
		DOLOAD$1 = -1ll;
	}
	label$629:;
	label$621:;
	if( ((int64)-(V1_TYP$1 == 4ll) | DOLOAD$1) == 0ll) goto label$631;
	{
		int64 TMP$157$2;
		if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$633;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V1_DTYPE$1 = 8ll;
		}
		label$633:;
		label$632:;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$634;
		TMP$157$2 = 24ll;
		goto label$894;
		label$634:;
		TMP$157$2 = V1_DTYPE$1 & 31ll;
		label$894:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$157$2 * 56ll)) + 8ll) );
	}
	label$631:;
	label$630:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$636;
	{
		if( VR$1 == V1$1) goto label$638;
		{
			int64 TMP$158$3;
			if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$639;
			TMP$158$3 = 24ll;
			goto label$895;
			label$639:;
			TMP$158$3 = VR_DTYPE$1 & 31ll;
			label$895:;
			int64 vr$58 = (*(tmp$85*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))) + 8ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VR$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$158$3 * 56ll)) + 8ll) );
			*(int64*)((uint8*)VR$1 + 24ll) = vr$58;
			*($15IRVREGTYPE_ENUM*)VR$1 = 4ll;
		}
		label$638:;
		label$637:;
	}
	label$636:;
	label$635:;
	{
		uint64 TMP$159$2;
		TMP$159$2 = (uint64)OP$1;
		goto label$641;
		label$642:;
		{
			EMITEQ( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$643:;
		{
			EMITNE( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$644:;
		{
			EMITGT( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$645:;
		{
			EMITLT( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$646:;
		{
			EMITLE( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$647:;
		{
			EMITGE( VR$1, LABEL$1, V1$1, V2$1, OPTIONS$1 );
		}
		goto label$640;
		label$641:;
		static const void* tmp$187[6ll] = {
			&&label$642,
			&&label$644,
			&&label$645,
			&&label$643,
			&&label$647,
			&&label$646,
		};
		if( (TMP$159$2 - 45ull) > 5ull ) goto label$640;
		goto *tmp$187[TMP$159$2 - 45ull];
		label$640:;
	}
	HFREEREG( V1$1, 0ll );
	HFREEREG( V2$1, 0ll );
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$649;
	{
		HFREEREG( VR$1, 0ll );
	}
	label$649:;
	label$648:;
	label$592:;
}

static void HSPILLREGS( void )
{
	label$650:;
	struct $6IRVREG* VR$1;
	struct $6IRVREG* VAUXPARENT$1;
	int64 REG$1;
	{
		int64 CLASS_$2;
		CLASS_$2 = 0ll;
		label$655:;
		{
			int64 vr$1 = (*(tmp$90*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 56ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) );
			REG$1 = vr$1;
			label$656:;
			if( REG$1 == -1ll) goto label$657;
			{
				int64 vr$5 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 32ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1 );
				if( vr$5 != 0ll) goto label$659;
				{
					struct $6IRVREG* vr$10 = (*(tmp$91*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 72ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1, &VAUXPARENT$1 );
					VR$1 = vr$10;
					(*(tmp$46*)((uint8*)&IR$ + 528ll))( VR$1, VAUXPARENT$1 );
				}
				label$659:;
				label$658:;
				int64 vr$14 = (*(tmp$88*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))) + 64ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (CLASS_$2 << (3ll & 63ll))), REG$1 );
				REG$1 = vr$14;
			}
			goto label$656;
			label$657:;
		}
		label$653:;
		CLASS_$2 = CLASS_$2 + 1ll;
		label$652:;
		if( CLASS_$2 <= 1ll) goto label$655;
		label$654:;
	}
	label$651:;
}

static void HFLUSHSTORE( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$660:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 V2_TYP$1;
	static int64 V2_DTYPE$1;
	static int64 V2_DCLASS$1;
	static struct $6IRVREG* VA$1;
	if( OP$1 != 88ll) goto label$663;
	{
		HSPILLREGS(  );
		goto label$661;
	}
	label$663:;
	label$662:;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$665;
	{
		int64 TMP$160$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$666;
		TMP$160$2 = 24ll;
		goto label$896;
		label$666:;
		TMP$160$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$896:;
		V1_DTYPE$1 = TMP$160$2;
		if( V1_DTYPE$1 != 24ll) goto label$668;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$668:;
		label$667:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$664;
	label$665:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$664:;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$670;
	{
		int64 TMP$161$2;
		V2_TYP$1 = *(int64*)V2$1;
		if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$671;
		TMP$161$2 = 24ll;
		goto label$897;
		label$671:;
		TMP$161$2 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
		label$897:;
		V2_DTYPE$1 = TMP$161$2;
		if( V2_DTYPE$1 != 24ll) goto label$673;
		{
			V2_DTYPE$1 = 9ll;
		}
		label$673:;
		label$672:;
		V2_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V2_DTYPE$1 * 56ll));
	}
	goto label$669;
	label$670:;
	{
		V2_TYP$1 = -1ll;
		V2_DTYPE$1 = 2147483648ll;
		V2_DCLASS$1 = -1ll;
	}
	label$669:;
	HLOADIDX( V1$1 );
	HLOADIDX( V2$1 );
	if( ((int64)-(V2_TYP$1 == 4ll) | ((int64)-(V2_TYP$1 != 0ll) & (int64)-(V1_DCLASS$1 == 0ll))) == 0ll) goto label$675;
	{
		int64 TMP$162$2;
		if( ((int64)-(V2_DTYPE$1 == 13ll) | (int64)-(V2_DTYPE$1 == 14ll)) == 0ll) goto label$677;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), VA$1, V2$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			V2_DTYPE$1 = 8ll;
		}
		label$677:;
		label$676:;
		if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$678;
		TMP$162$2 = 24ll;
		goto label$898;
		label$678:;
		TMP$162$2 = V2_DTYPE$1 & 31ll;
		label$898:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), V2$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$162$2 * 56ll)) + 8ll) );
	}
	label$675:;
	label$674:;
	EMITSTORE( V1$1, V2$1 );
	HFREEREG( V1$1, 0ll );
	HFREEREG( V2$1, 0ll );
	label$661:;
}

static void HFLUSHLOAD( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$679:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 V1_REG$1;
	static struct $6IRVREG* VA$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$682;
	{
		int64 TMP$163$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$683;
		TMP$163$2 = 24ll;
		goto label$899;
		label$683:;
		TMP$163$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$899:;
		V1_DTYPE$1 = TMP$163$2;
		if( V1_DTYPE$1 != 24ll) goto label$685;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$685:;
		label$684:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$681;
	label$682:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$681:;
	HLOADIDX( V1$1 );
	{
		if( OP$1 != 86ll) goto label$687;
		label$688:;
		{
			int64 TMP$164$3;
			if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$690;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				V1_DTYPE$1 = 8ll;
			}
			label$690:;
			label$689:;
			if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$691;
			TMP$164$3 = 24ll;
			goto label$900;
			label$691:;
			TMP$164$3 = V1_DTYPE$1 & 31ll;
			label$900:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$164$3 * 56ll)) + 8ll) );
		}
		goto label$686;
		label$687:;
		if( OP$1 != 87ll) goto label$692;
		label$693:;
		{
			if( V1_TYP$1 != 4ll) goto label$695;
			{
				if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$697;
				{
					VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
					(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
					int64 vr$27 = (*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
					V1_REG$1 = vr$27;
				}
				goto label$696;
				label$697:;
				{
					int64 TMP$165$5;
					if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$698;
					TMP$165$5 = 24ll;
					goto label$901;
					label$698:;
					TMP$165$5 = V1_DTYPE$1 & 31ll;
					label$901:;
					int64 vr$34 = (*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$165$5 * 56ll)) + 8ll) );
					V1_REG$1 = vr$34;
				}
				label$696:;
			}
			goto label$694;
			label$695:;
			{
				V1_REG$1 = -1ll;
			}
			label$694:;
			static int64 VR_REG$3;
			static int64 VR_REG2$3;
			(*(tmp$101*)((uint8*)&EMIT$ + 360ll))( V1_DTYPE$1, V1_DCLASS$1, &VR_REG$3, &VR_REG2$3 );
			if( VR_REG$3 == V1_REG$1) goto label$700;
			{
				if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$702;
				{
					VA$1 = *(struct $6IRVREG**)((uint8*)VR$1 + 88ll);
					int64 vr$42 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 16ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VR_REG2$3, VA$1, VR$1 );
					*(int64*)((uint8*)VA$1 + 24ll) = vr$42;
					*($15IRVREGTYPE_ENUM*)VA$1 = 4ll;
				}
				label$702:;
				label$701:;
				int64 vr$48 = (*(tmp$86*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 16ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VR_REG$3, VR$1, (struct $6IRVREG*)0ull );
				*(int64*)((uint8*)VR$1 + 24ll) = vr$48;
				*($15IRVREGTYPE_ENUM*)VR$1 = 4ll;
				if( *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)*(struct $7ASTNODE**)((uint8*)&AST$ + 80ll) + 24ll) + 176ll) == 1ll) goto label$704;
				{
					*($12IR_REGFAMILY*)((uint8*)VR$1 + 32ll) = 0ll;
				}
				label$704:;
				label$703:;
				EMITLOAD( VR$1, V1$1 );
				HFREEREG( VR$1, 0ll );
			}
			label$700:;
			label$699:;
		}
		label$692:;
		label$686:;
	}
	HFREEREG( V1$1, 0ll );
	label$680:;
}

static void HFLUSHCONVERT( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	label$705:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 V2_TYP$1;
	static int64 V2_DTYPE$1;
	static int64 V2_DCLASS$1;
	static int64 REUSE$1;
	static struct $6IRVREG* VA$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$708;
	{
		int64 TMP$166$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$709;
		TMP$166$2 = 24ll;
		goto label$902;
		label$709:;
		TMP$166$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$902:;
		V1_DTYPE$1 = TMP$166$2;
		if( V1_DTYPE$1 != 24ll) goto label$711;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$711:;
		label$710:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$707;
	label$708:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$707:;
	if( V2$1 == (struct $6IRVREG*)0ull) goto label$713;
	{
		int64 TMP$167$2;
		V2_TYP$1 = *(int64*)V2$1;
		if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$714;
		TMP$167$2 = 24ll;
		goto label$903;
		label$714:;
		TMP$167$2 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
		label$903:;
		V2_DTYPE$1 = TMP$167$2;
		if( V2_DTYPE$1 != 24ll) goto label$716;
		{
			V2_DTYPE$1 = 9ll;
		}
		label$716:;
		label$715:;
		V2_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V2_DTYPE$1 * 56ll));
	}
	goto label$712;
	label$713:;
	{
		V2_TYP$1 = -1ll;
		V2_DTYPE$1 = 2147483648ll;
		V2_DCLASS$1 = -1ll;
	}
	label$712:;
	HLOADIDX( V1$1 );
	HLOADIDX( V2$1 );
	REUSE$1 = 0ll;
	if( ((int64)-(V1_DCLASS$1 == V2_DCLASS$1) & (int64)-(V2_TYP$1 == 4ll)) == 0ll) goto label$718;
	{
		if( V2_DCLASS$1 != 1ll) goto label$720;
		{
			if( (*(int64*)((uint8*)&IR$ + 544ll) & 1ll) == 0ll) goto label$722;
			{
				*($12IR_REGFAMILY*)((uint8*)V1$1 + 32ll) = *($12IR_REGFAMILY*)((uint8*)V2$1 + 32ll);
				if( *(int64*)((uint8*)V2$1 + 32ll) != 0ll) goto label$724;
				{
					goto label$706;
					label$724:;
				}
			}
			goto label$721;
			label$722:;
			{
				*(int64*)((uint8*)V1$1 + 24ll) = *(int64*)((uint8*)V2$1 + 24ll);
				*(int64*)((uint8*)V2$1 + 24ll) = -1ll;
				*($15IRVREGTYPE_ENUM*)V1$1 = 4ll;
				(*(tmp$89*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 40ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)V1$1 + 24ll), V1$1, (struct $6IRVREG*)0ull );
				goto label$706;
			}
			label$721:;
		}
		label$720:;
		label$719:;
		uint64 vr$27 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( V2$1 );
		if( vr$27 != 2147483647ull) goto label$726;
		{
			{
				int64 TMP$168$4;
				int64 TMP$169$4;
				if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$727;
				TMP$168$4 = 24ll;
				goto label$904;
				label$727:;
				TMP$168$4 = V1_DTYPE$1 & 31ll;
				label$904:;
				TMP$169$4 = *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$168$4 * 56ll)) + 8ll);
				if( TMP$169$4 == 1ll) goto label$730;
				label$731:;
				if( TMP$169$4 != 8ll) goto label$729;
				label$730:;
				{
				}
				goto label$728;
				label$729:;
				{
					{
						int64 TMP$170$6;
						int64 TMP$171$6;
						if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$733;
						TMP$170$6 = 24ll;
						goto label$905;
						label$733:;
						TMP$170$6 = V2_DTYPE$1 & 31ll;
						label$905:;
						TMP$171$6 = *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$170$6 * 56ll)) + 8ll);
						if( TMP$171$6 == 1ll) goto label$736;
						label$737:;
						if( TMP$171$6 != 8ll) goto label$735;
						label$736:;
						{
						}
						goto label$734;
						label$735:;
						{
							REUSE$1 = -1ll;
						}
						label$738:;
						label$734:;
					}
				}
				label$732:;
				label$728:;
			}
		}
		label$726:;
		label$725:;
	}
	label$718:;
	label$717:;
	if( REUSE$1 == 0ll) goto label$740;
	{
		*(int64*)((uint8*)V1$1 + 24ll) = *(int64*)((uint8*)V2$1 + 24ll);
		*($15IRVREGTYPE_ENUM*)V1$1 = 4ll;
		(*(tmp$89*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 40ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)V1$1 + 24ll), V1$1, (struct $6IRVREG*)0ull );
	}
	goto label$739;
	label$740:;
	{
		int64 TMP$173$2;
		if( V2_TYP$1 != 4ll) goto label$742;
		{
			int64 TMP$172$3;
			if( ((int64)-(V2_DTYPE$1 == 13ll) | (int64)-(V2_DTYPE$1 == 14ll)) == 0ll) goto label$744;
			{
				VA$1 = *(struct $6IRVREG**)((uint8*)V2$1 + 88ll);
				(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), VA$1, V2$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
				V2_DTYPE$1 = 8ll;
			}
			label$744:;
			label$743:;
			if( (V2_DTYPE$1 & 480ll) == 0ll) goto label$745;
			TMP$172$3 = 24ll;
			goto label$906;
			label$745:;
			TMP$172$3 = V2_DTYPE$1 & 31ll;
			label$906:;
			(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V2_DCLASS$1 << (3ll & 63ll))), V2$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$172$3 * 56ll)) + 8ll) );
		}
		label$742:;
		label$741:;
		if( ((int64)-(V1_DTYPE$1 == 13ll) | (int64)-(V1_DTYPE$1 == 14ll)) == 0ll) goto label$747;
		{
			VA$1 = *(struct $6IRVREG**)((uint8*)V1$1 + 88ll);
			int64 vr$59 = (*(tmp$85*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 8ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), VA$1, V1$1, *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 456ll) );
			*(int64*)((uint8*)VA$1 + 24ll) = vr$59;
			*($15IRVREGTYPE_ENUM*)VA$1 = 4ll;
			V1_DTYPE$1 = 8ll;
		}
		label$747:;
		label$746:;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$748;
		TMP$173$2 = 24ll;
		goto label$907;
		label$748:;
		TMP$173$2 = V1_DTYPE$1 & 31ll;
		label$907:;
		int64 vr$68 = (*(tmp$85*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))) + 8ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$173$2 * 56ll)) + 8ll) );
		*(int64*)((uint8*)V1$1 + 24ll) = vr$68;
		*($15IRVREGTYPE_ENUM*)V1$1 = 4ll;
	}
	label$739:;
	EMITLOAD( V1$1, V2$1 );
	if( REUSE$1 != 0ll) goto label$750;
	{
		HFREEREG( V2$1, 0ll );
	}
	goto label$749;
	label$750:;
	{
		*(int64*)((uint8*)V2$1 + 24ll) = -1ll;
	}
	label$749:;
	HFREEREG( V1$1, 0ll );
	label$706:;
}

static void HFLUSHADDR( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$751:;
	static int64 V1_TYP$1;
	static int64 V1_DTYPE$1;
	static int64 V1_DCLASS$1;
	static int64 VR_TYP$1;
	static int64 VR_DTYPE$1;
	static int64 VR_DCLASS$1;
	if( V1$1 == (struct $6IRVREG*)0ull) goto label$754;
	{
		int64 TMP$174$2;
		V1_TYP$1 = *(int64*)V1$1;
		if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$755;
		TMP$174$2 = 24ll;
		goto label$908;
		label$755:;
		TMP$174$2 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
		label$908:;
		V1_DTYPE$1 = TMP$174$2;
		if( V1_DTYPE$1 != 24ll) goto label$757;
		{
			V1_DTYPE$1 = 9ll;
		}
		label$757:;
		label$756:;
		V1_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (V1_DTYPE$1 * 56ll));
	}
	goto label$753;
	label$754:;
	{
		V1_TYP$1 = -1ll;
		V1_DTYPE$1 = 2147483648ll;
		V1_DCLASS$1 = -1ll;
	}
	label$753:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$759;
	{
		int64 TMP$175$2;
		VR_TYP$1 = *(int64*)VR$1;
		if( (*(int64*)((uint8*)VR$1 + 8ll) & 480ll) == 0ll) goto label$760;
		TMP$175$2 = 24ll;
		goto label$909;
		label$760:;
		TMP$175$2 = *(int64*)((uint8*)VR$1 + 8ll) & 31ll;
		label$909:;
		VR_DTYPE$1 = TMP$175$2;
		if( VR_DTYPE$1 != 24ll) goto label$762;
		{
			VR_DTYPE$1 = 9ll;
		}
		label$762:;
		label$761:;
		VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (VR_DTYPE$1 * 56ll));
	}
	goto label$758;
	label$759:;
	{
		VR_TYP$1 = -1ll;
		VR_DTYPE$1 = 2147483648ll;
		VR_DCLASS$1 = -1ll;
	}
	label$758:;
	HLOADIDX( V1$1 );
	HLOADIDX( VR$1 );
	if( V1_TYP$1 != 4ll) goto label$764;
	{
		int64 TMP$176$2;
		if( (V1_DTYPE$1 & 480ll) == 0ll) goto label$765;
		TMP$176$2 = 24ll;
		goto label$910;
		label$765:;
		TMP$176$2 = V1_DTYPE$1 & 31ll;
		label$910:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (V1_DCLASS$1 << (3ll & 63ll))), V1$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$176$2 * 56ll)) + 8ll) );
	}
	label$764:;
	label$763:;
	if( VR_TYP$1 != 4ll) goto label$767;
	{
		int64 TMP$177$2;
		if( (VR_DTYPE$1 & 480ll) == 0ll) goto label$768;
		TMP$177$2 = 24ll;
		goto label$911;
		label$768:;
		TMP$177$2 = VR_DTYPE$1 & 31ll;
		label$911:;
		(*(tmp$85*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), VR$1, (struct $6IRVREG*)0ull, *(uint64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$177$2 * 56ll)) + 8ll) );
	}
	label$767:;
	label$766:;
	{
		if( OP$1 != 22ll) goto label$770;
		label$771:;
		{
			EMITADDROF( VR$1, V1$1 );
		}
		goto label$769;
		label$770:;
		if( OP$1 != 77ll) goto label$772;
		label$773:;
		{
			EMITDEREF( VR$1, V1$1 );
		}
		label$772:;
		label$769:;
	}
	HFREEREG( V1$1, 0ll );
	HFREEREG( VR$1, 0ll );
	label$752:;
}

static void HFLUSHMEM( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, int64 BYTES$1, void* EXTRA$1 )
{
	label$774:;
	HLOADIDX( V1$1 );
	HLOADIDX( V2$1 );
	{
		uint64 TMP$178$2;
		TMP$178$2 = (uint64)OP$1;
		goto label$777;
		label$778:;
		{
			EMITMEMMOVE( V1$1, V2$1, BYTES$1 );
		}
		goto label$776;
		label$779:;
		{
			EMITMEMSWAP( V1$1, V2$1, BYTES$1 );
		}
		goto label$776;
		label$780:;
		{
			EMITMEMFILL( V1$1, V2$1, BYTES$1, (int64)EXTRA$1 );
		}
		goto label$776;
		label$781:;
		{
			EMITSTKCLEAR( BYTES$1, (int64)EXTRA$1 );
		}
		goto label$776;
		label$777:;
		static const void* tmp$188[4ll] = {
			&&label$778,
			&&label$779,
			&&label$780,
			&&label$781,
		};
		if( (TMP$178$2 - 106ull) > 3ull ) goto label$776;
		goto *tmp$188[TMP$178$2 - 106ull];
		label$776:;
	}
	HFREEREG( V1$1, 0ll );
	HFREEREG( V2$1, 0ll );
	label$775:;
}

static void HFLUSHDBG( int64 OP$1, struct $8FBSYMBOL* PROC$1, int64 EX$1, char* FILENAME$1 )
{
	label$782:;
	{
		uint64 TMP$179$2;
		TMP$179$2 = (uint64)OP$1;
		goto label$785;
		label$786:;
		{
			EMITDBGLINEBEGIN( PROC$1, EX$1, FILENAME$1 );
		}
		goto label$784;
		label$787:;
		{
			EMITDBGLINEEND( PROC$1, EX$1 );
		}
		goto label$784;
		label$788:;
		{
			EMITDBGSCOPEBEGIN( (struct $8FBSYMBOL*)EX$1 );
		}
		goto label$784;
		label$789:;
		{
			EMITDBGSCOPEEND( (struct $8FBSYMBOL*)EX$1 );
		}
		goto label$784;
		label$785:;
		static const void* tmp$189[4ll] = {
			&&label$786,
			&&label$787,
			&&label$788,
			&&label$789,
		};
		if( (TMP$179$2 - 114ull) > 3ull ) goto label$784;
		goto *tmp$189[TMP$179$2 - 114ull];
		label$784:;
	}
	label$783:;
}

static void HFLUSHLIT( int64 OP$1, char* TEXT$1 )
{
	label$790:;
	{
		if( OP$1 != 118ll) goto label$793;
		label$794:;
		{
			EMITCOMMENT( TEXT$1 );
		}
		goto label$792;
		label$793:;
		if( OP$1 != 119ll) goto label$795;
		label$796:;
		{
			EMITASM( TEXT$1 );
		}
		label$795:;
		label$792:;
	}
	if( TEXT$1 == (char*)0ull) goto label$798;
	{
		free( (void*)TEXT$1 );
	}
	label$798:;
	label$797:;
	label$791:;
}

static void HFREEIDX( struct $6IRVREG* VREG$1, int64 FORCE$1 )
{
	label$799:;
	struct $6IRVREG* VIDX$1;
	__builtin_memset( &VIDX$1, 0, 8ll );
	if( VREG$1 != (struct $6IRVREG*)0ull) goto label$802;
	{
		goto label$800;
	}
	label$802:;
	label$801:;
	VIDX$1 = *(struct $6IRVREG**)((uint8*)VREG$1 + 80ll);
	if( VIDX$1 == (struct $6IRVREG*)0ull) goto label$804;
	{
		if( *(int64*)((uint8*)VIDX$1 + 24ll) == -1ll) goto label$806;
		{
			HFREEREG( VIDX$1, FORCE$1 );
			*(struct $6IRVREG**)((uint8*)VREG$1 + 80ll) = (struct $6IRVREG*)0ull;
		}
		label$806:;
		label$805:;
	}
	label$804:;
	label$803:;
	label$800:;
}

static void HFREEREG( struct $6IRVREG* VREG$1, int64 FORCE$1 )
{
	label$807:;
	int64 DCLASS$1;
	__builtin_memset( &DCLASS$1, 0, 8ll );
	int64 DIST$1;
	__builtin_memset( &DIST$1, 0, 8ll );
	struct $6IRVREG* VAUX$1;
	__builtin_memset( &VAUX$1, 0, 8ll );
	if( VREG$1 != (struct $6IRVREG*)0ull) goto label$810;
	{
		goto label$808;
	}
	label$810:;
	label$809:;
	HFREEIDX( VREG$1, FORCE$1 );
	if( *(int64*)VREG$1 == 4ll) goto label$812;
	{
		goto label$808;
	}
	label$812:;
	label$811:;
	if( *(int64*)((uint8*)VREG$1 + 24ll) != -1ll) goto label$814;
	{
		goto label$808;
	}
	label$814:;
	label$813:;
	DIST$1 = 2147483647ll;
	if( FORCE$1 != 0ll) goto label$816;
	{
		uint64 vr$5 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( VREG$1 );
		DIST$1 = (int64)vr$5;
	}
	label$816:;
	label$815:;
	if( DIST$1 != 2147483647ll) goto label$818;
	{
		int64 TMP$180$2;
		if( *(struct $6IRVREG**)((uint8*)VREG$1 + 88ll) == (struct $6IRVREG*)0ull) goto label$820;
		{
			VAUX$1 = *(struct $6IRVREG**)((uint8*)VREG$1 + 88ll);
			if( *(int64*)((uint8*)VAUX$1 + 24ll) == -1ll) goto label$822;
			{
				HFREEREG( VAUX$1, -1ll );
			}
			label$822:;
			label$821:;
		}
		label$820:;
		label$819:;
		if( (*(int64*)((uint8*)VREG$1 + 8ll) & 480ll) == 0ll) goto label$823;
		TMP$180$2 = 24ll;
		goto label$912;
		label$823:;
		TMP$180$2 = *(int64*)((uint8*)VREG$1 + 8ll) & 31ll;
		label$912:;
		DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$180$2 * 56ll));
		(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))) + 24ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)VREG$1 + 24ll) );
		*(int64*)((uint8*)VREG$1 + 24ll) = -1ll;
	}
	label$818:;
	label$817:;
	label$808:;
}

static uint64 _GETDISTANCE( struct $6IRVREG* VREG$1 )
{
	uint64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$824:;
	struct $6IRVREG* V$1;
	__builtin_memset( &V$1, 0, 8ll );
	struct $5IRTAC* T$1;
	__builtin_memset( &T$1, 0, 8ll );
	int64 DIST$1;
	__builtin_memset( &DIST$1, 0, 8ll );
	if( VREG$1 != (struct $6IRVREG*)0ull) goto label$827;
	{
		fb$result$1 = 2147483647ull;
		goto label$825;
	}
	label$827:;
	label$826:;
	void* vr$4 = FLISTGETNEXT( *(void**)((uint8*)&CTX$ + 120ll) );
	T$1 = (struct $5IRTAC*)vr$4;
	if( T$1 != (struct $5IRTAC*)0ull) goto label$829;
	{
		fb$result$1 = 2147483647ull;
		goto label$825;
	}
	label$829:;
	label$828:;
	DIST$1 = *(int64*)*(struct $5IRTAC**)((uint8*)VREG$1 + 112ll) - *(int64*)T$1;
	if( DIST$1 >= 0ll) goto label$831;
	{
		fb$result$1 = 2147483647ull;
	}
	goto label$830;
	label$831:;
	{
		fb$result$1 = (uint64)DIST$1;
	}
	label$830:;
	label$825:;
	return fb$result$1;
}

static void _LOADVR( int64 REG$1, struct $6IRVREG* VREG$1, struct $6IRVREG* VAUXPARENT$1 )
{
	label$832:;
	struct $6IRVREG RVREG$1;
	__builtin_memset( &RVREG$1, 0, 120ll );
	if( *(int64*)VREG$1 == 4ll) goto label$835;
	{
		if( VAUXPARENT$1 != (struct $6IRVREG*)0ull) goto label$837;
		{
			*($15IRVREGTYPE_ENUM*)&RVREG$1 = 4ll;
			*($11FB_DATATYPE*)((uint8*)&RVREG$1 + 8ll) = *($11FB_DATATYPE*)((uint8*)VREG$1 + 8ll);
			*(int64*)((uint8*)&RVREG$1 + 24ll) = REG$1;
			*(struct $6IRVREG**)((uint8*)&RVREG$1 + 88ll) = *(struct $6IRVREG**)((uint8*)VREG$1 + 88ll);
			*($12IR_REGFAMILY*)((uint8*)&RVREG$1 + 32ll) = *($12IR_REGFAMILY*)((uint8*)VREG$1 + 32ll);
			EMITLOAD( &RVREG$1, VREG$1 );
		}
		label$837:;
		label$836:;
		HFREEIDX( VREG$1, -1ll );
		*($15IRVREGTYPE_ENUM*)VREG$1 = 4ll;
	}
	label$835:;
	label$834:;
	*(int64*)((uint8*)VREG$1 + 24ll) = REG$1;
	if( ((int64)-(*(int64*)((uint8*)&ENV$ + 232ll) >= 1ll) & (int64)-(VAUXPARENT$1 != (struct $6IRVREG*)0ull)) == 0ll) goto label$839;
	{
		*($12IR_REGFAMILY*)((uint8*)VREG$1 + 32ll) = 1ll;
	}
	label$839:;
	label$838:;
	label$833:;
}

static void _STOREVR( struct $6IRVREG* VREG$1, struct $6IRVREG* VAUXPARENT$1 )
{
	int64 TMP$181$1;
	label$840:;
	struct $6IRVREG ORIGVREG$1;
	struct $6IRVREG ORIGVAUX$1;
	int64 VR_DCLASS$1;
	if( VAUXPARENT$1 == (struct $6IRVREG*)0ull) goto label$843;
	{
		VREG$1 = VAUXPARENT$1;
	}
	label$843:;
	label$842:;
	__builtin_memcpy( &ORIGVREG$1, VREG$1, 120 );
	if( ((int64)-(*(int64*)((uint8*)VREG$1 + 8ll) == 13ll) | (int64)-(*(int64*)((uint8*)VREG$1 + 8ll) == 14ll)) == 0ll) goto label$845;
	{
		__builtin_memcpy( &ORIGVAUX$1, *(struct $6IRVREG**)((uint8*)VREG$1 + 88ll), 120 );
		*(struct $6IRVREG**)((uint8*)&ORIGVREG$1 + 88ll) = &ORIGVAUX$1;
	}
	label$845:;
	label$844:;
	uint64 vr$9 = (*(tmp$77*)((uint8*)&IR$ + 512ll))( VREG$1 );
	if( vr$9 == 2147483647ull) goto label$847;
	{
		*($15IRVREGTYPE_ENUM*)VREG$1 = 1ll;
		struct $8FBSYMBOL* vr$12 = SYMBADDANDALLOCATETEMPVAR( *(int64*)((uint8*)VREG$1 + 8ll) );
		*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) = vr$12;
		*(int64*)((uint8*)VREG$1 + 64ll) = *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)VREG$1 + 56ll) + 88ll);
		*(int64*)((uint8*)VREG$1 + 24ll) = -1ll;
		if( ((int64)-(*(int64*)((uint8*)VREG$1 + 8ll) == 13ll) | (int64)-(*(int64*)((uint8*)VREG$1 + 8ll) == 14ll)) == 0ll) goto label$849;
		{
			*(int64*)((uint8*)*(struct $6IRVREG**)((uint8*)VREG$1 + 88ll) + 24ll) = -1ll;
			*($15IRVREGTYPE_ENUM*)*(struct $6IRVREG**)((uint8*)VREG$1 + 88ll) = 1ll;
			*(int64*)((uint8*)*(struct $6IRVREG**)((uint8*)VREG$1 + 88ll) + 64ll) = *(int64*)((uint8*)VREG$1 + 64ll) + 4ll;
		}
		label$849:;
		label$848:;
		if( *(int64*)((uint8*)&ENV$ + 232ll) < 1ll) goto label$851;
		{
			*($12IR_REGFAMILY*)((uint8*)VREG$1 + 32ll) = 1ll;
		}
		label$851:;
		label$850:;
		EMITSTORE( VREG$1, &ORIGVREG$1 );
	}
	label$847:;
	label$846:;
	if( ((int64)-(*(int64*)((uint8*)&ORIGVREG$1 + 8ll) == 13ll) | (int64)-(*(int64*)((uint8*)&ORIGVREG$1 + 8ll) == 14ll)) == 0ll) goto label$853;
	{
		(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)REGTB$ + 24ll))( *(struct $8REGCLASS**)REGTB$, *(int64*)((uint8*)&ORIGVAUX$1 + 24ll) );
	}
	label$853:;
	label$852:;
	if( (*(int64*)((uint8*)&ORIGVREG$1 + 8ll) & 480ll) == 0ll) goto label$854;
	TMP$181$1 = 24ll;
	goto label$913;
	label$854:;
	TMP$181$1 = *(int64*)((uint8*)&ORIGVREG$1 + 8ll) & 31ll;
	label$913:;
	VR_DCLASS$1 = *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$181$1 * 56ll));
	(*(tmp$87*)((uint8*)*(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))) + 24ll))( *(struct $8REGCLASS**)((int64)(struct $8REGCLASS**)REGTB$ + (VR_DCLASS$1 << (3ll & 63ll))), *(int64*)((uint8*)&ORIGVREG$1 + 24ll) );
	label$841:;
}

static void _XCHGTOS( int64 REG$1 )
{
	label$855:;
	static struct $6IRVREG RVREG$1;
	*($15IRVREGTYPE_ENUM*)&RVREG$1 = 4ll;
	*($11FB_DATATYPE*)((uint8*)&RVREG$1 + 8ll) = 16ll;
	*(int64*)((uint8*)&RVREG$1 + 24ll) = REG$1;
	EMITXCHGTOS( &RVREG$1 );
	label$856:;
}
