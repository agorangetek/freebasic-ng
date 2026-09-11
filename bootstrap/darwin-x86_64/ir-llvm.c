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
struct $17IRLLVMVARINISCOPE {
	int8 IS_ARRAY;
};
__FB_STATIC_ASSERT( sizeof( struct $17IRLLVMVARINISCOPE ) == 1 );
struct $13IRLLVMCONTEXT {
	int64 INDENT;
	int64 LINENUM;
	FBSTRING VARINI;
	int64 VARINISCOPELEVEL;
	struct $17IRLLVMVARINISCOPE VARINISCOPES[128];
	FBSTRING CTORS;
	FBSTRING DTORS;
	int64 CTORCOUNT;
	int64 DTORCOUNT;
	FBSTRING FBCTINF;
	int64 FBCTINF_LEN;
	int64 SECTION;
	FBSTRING HEAD_TXT;
	FBSTRING BODY_TXT;
	FBSTRING FOOT_TXT;
};
__FB_STATIC_ASSERT( sizeof( struct $13IRLLVMCONTEXT ) == 352 );
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
struct $7BUILTIN {
	char* DECL;
	int64 USED;
};
__FB_STATIC_ASSERT( sizeof( struct $7BUILTIN ) == 16 );
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
typedef int64 $10IR_EMITOPT;
typedef int64 $11AST_OPFLAGS;
struct $10AST_OPINFO {
	$13AST_NODECLASS CLASS;
	$11AST_OPFLAGS FLAGS;
	char* ID;
	$6AST_OP SELFOP;
};
__FB_STATIC_ASSERT( sizeof( struct $10AST_OPINFO ) == 32 );
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
FBSTRING* fb_LongintToStr( int64 );
FBSTRING* fb_ULongintToStr( uint64 );
FBSTRING* fb_DoubleToStr( double );
FBSTRING* fb_StrFill2( int64, FBSTRING* );
int64 fb_StrLen( void*, int64 );
FBSTRING* fb_CHR( int32, ... );
FBSTRING* fb_HEXEx_l( uint64, int32 );
FBSTRING* fb_LEFT( FBSTRING*, int64 );
FBSTRING* fb_RIGHT( FBSTRING*, int64 );
static void fb_ctor__irzllvm( void ) __attribute__(( constructor ));
void LISTDELNODE( struct $5TLIST*, void* );
void* LISTGETTAIL( struct $5TLIST* );
void* LISTGETPREV( void* );
static void _ZN11TSTRSETITEMaSERKS_( struct $11TSTRSETITEM*, struct $11TSTRSETITEM* );
typedef int64 $12FB_ERRMSGOPT;
void ERRREPORTEX( int64, char*, int64, $12FB_ERRMSGOPT, char* );
void ERRREPORT( int64, int64, char* );
int64 FBGETOPTION( int64 );
int64 FBIS64BIT( void );
int64 FBGETCPUFAMILY( void );
int64 ASTGETINVERSELOGOP( int64 );
FBSTRING* ASTDUMPOPTOSTR( $6AST_OP );
void _Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
int64 SYMBPROCRETURNSONSTACK( struct $8FBSYMBOL* );
void SYMBGETREALTYPE( struct $8FBSYMBOL*, int64*, struct $8FBSYMBOL** );
int64 SYMBISDATADESC( struct $8FBSYMBOL* );
char* SYMBUNIQUEID( boolean );
char* SYMBUNIQUELABEL( void );
char* SYMBGETMANGLEDNAME( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETFIRSTFIELD( struct $8FBSYMBOL* );
struct $8FBSYMBOL* SYMBUDTGETNEXTFIELD( struct $8FBSYMBOL* );
int64 SYMBGETSTRLENGTH( struct $8FBSYMBOL* );
int64 SYMBGETWSTRLENGTH( struct $8FBSYMBOL* );
void SYMBFOREACHGLOBAL( int64, tmp$43 );
int64 HFILEEXISTS( char* );
char* HUNESCAPE( char*, int64* );
uint32* HUNESCAPEW( uint32*, int64* );
FBSTRING* HREPLACE( char*, char*, char* );
int64 HCHARNEEDSESCAPING( int64, int64 );
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
static void _ZN13IRLLVMCONTEXTC1Ev( struct $13IRLLVMCONTEXT* );
static void _ZN13IRLLVMCONTEXTaSERKS_( struct $13IRLLVMCONTEXT*, struct $13IRLLVMCONTEXT* );
static void _ZN13IRLLVMCONTEXTD1Ev( struct $13IRLLVMCONTEXT* );
static FBSTRING* HEMITTYPE( int64, struct $8FBSYMBOL* );
static void HEMITSTRUCT( struct $8FBSYMBOL* );
static void _EMITDBG( int64, struct $8FBSYMBOL*, int64, char* );
static FBSTRING* HVREGTOSTR( struct $6IRVREG* );
static void HEMITCONVERT( struct $6IRVREG*, struct $6IRVREG* );
static void HEMITSTORE( struct $6IRVREG*, struct $6IRVREG* );
static void HEMITBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void _INIT( void );
static void _END( void );
static void HWRITELINE( FBSTRING* );
static void HINTERNALCOMMAND( FBSTRING* );
static void HASTCOMMAND( FBSTRING* );
static void HWRITELABEL( char* );
static FBSTRING* HSYMNAME( struct $8FBSYMBOL* );
static FBSTRING* VREGPRETTY( struct $6IRVREG* );
static FBSTRING* HEMITPARAMNAME( struct $8FBSYMBOL* );
static FBSTRING* HEMITPROCCALLCONV( struct $8FBSYMBOL* );
static FBSTRING* HEMITPROCHEADER( struct $8FBSYMBOL*, int64, int64 );
static FBSTRING* HGETUDTNAME( struct $8FBSYMBOL* );
static void HEMITUDT( struct $8FBSYMBOL* );
static void HBUILDSTRLIT( FBSTRING*, int64, char*, int64 );
static void HBUILDWSTRLIT( FBSTRING*, int64, uint32*, int64 );
static FBSTRING* HEMITSTRLITTYPE( int64 );
static FBSTRING* HEMITSYMTYPE( struct $8FBSYMBOL* );
static void HEMITVARIABLE( struct $8FBSYMBOL* );
static void HMAYBEEMITGLOBALVAR( struct $8FBSYMBOL* );
static void HMAYBEEMITPROCPROTO( struct $8FBSYMBOL* );
static void HEMITCTORDTORARRAYELEMENT( struct $8FBSYMBOL*, FBSTRING* );
static void HADDGLOBALCTORDTOR( struct $8FBSYMBOL* );
static int64 _EMITBEGIN( void );
static void _EMITEND( void );
static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE );
static int64 _SUPPORTSOP( int64, int64 );
static void _PROCBEGIN( struct $8FBSYMBOL* );
static void _PROCEND( struct $8FBSYMBOL* );
static void _PROCALLOCARG( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _PROCALLOCLOCAL( struct $8FBSYMBOL*, struct $8FBSYMBOL* );
static void _SCOPEBEGIN( struct $8FBSYMBOL* );
static void _SCOPEEND( struct $8FBSYMBOL* );
static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* );
static void _SETVREGDATATYPE( struct $6IRVREG*, int64, struct $8FBSYMBOL* );
static void HADDOFFSET( struct $6IRVREG*, int64, struct $8FBSYMBOL*, int64 );
static void HPREPAREADDRESS( struct $6IRVREG* );
static void HLOADVREG( struct $6IRVREG* );
static FBSTRING* HEMITINT( int64, struct $8FBSYMBOL*, int64 );
static FBSTRING* HEMITLONG( int64 );
static FBSTRING* HEMITFLOAT( double );
static int64 HISFIXLENSTR( struct $8FBSYMBOL* );
static void _EMITLABEL( struct $8FBSYMBOL* );
static char* HGETBOPCODE( int64, int64 );
static void HLOADOPERANDSANDWRITEBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, int64, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void _EMITBOP( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG*, struct $8FBSYMBOL*, $10IR_EMITOPT );
static void HBUILTINUOP( int64, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITUOP( int64, struct $6IRVREG*, struct $6IRVREG* );
static char* HGETCONVOPCODE( int64, int64 );
static void _EMITCONVERT( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSTORE( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITSPILLREGS( void );
static void _EMITLOAD( struct $6IRVREG* );
static void _EMITLOADRES( struct $6IRVREG*, struct $6IRVREG* );
static void _EMITADDR( int64, struct $6IRVREG*, struct $6IRVREG* );
static void HDOCALL( char*, struct $8FBSYMBOL*, int64, struct $6IRVREG*, int64 );
static void _EMITCALL( struct $8FBSYMBOL*, int64, struct $6IRVREG*, int64 );
static void _EMITCALLPTR( struct $8FBSYMBOL*, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITJUMPPTR( struct $6IRVREG* );
static void _EMITBRANCH( int64, struct $8FBSYMBOL* );
static void _EMITJMPTB( struct $6IRVREG*, struct $8FBSYMBOL*, uint64*, struct $8FBSYMBOL**, int64, struct $8FBSYMBOL*, uint64, uint64 );
static void _EMITMEM( int64, struct $6IRVREG*, struct $6IRVREG*, int64, int64 );
static void _EMITMACRO( int64, struct $6IRVREG*, struct $6IRVREG*, struct $6IRVREG* );
static void _EMITDECL( struct $8FBSYMBOL* );
static void _EMITCOMMENT( char* );
static void _EMITASMLINE( struct $9ASTASMTOK* );
static void _EMITVARINIBEGIN( struct $8FBSYMBOL* );
static void _EMITVARINIEND( struct $8FBSYMBOL* );
static void HVARINIELEMENTTYPE( struct $8FBSYMBOL* );
static void HVARINISEPARATOR( void );
static void _EMITVARINII( struct $8FBSYMBOL*, int64 );
static void _EMITVARINIF( struct $8FBSYMBOL*, double );
static void HMAYBEADDCONV( FBSTRING*, int64, struct $8FBSYMBOL*, FBSTRING*, int64, struct $8FBSYMBOL*, FBSTRING* );
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
extern struct $7IR_VTBL IRLLVM_VTBL$;
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
static struct $7BUILTIN BUILTINS$[18] = { { (char*)"declare void @llvm.memset.p0i8.i32(i8*, i8, i32, i32, i1) nounwind" }, { (char*)"declare void @llvm.memmove.p0i8.p0i8.i32(i8*, i8*, i32, i32, i1) nounwind" }, { (char*)"declare float  @llvm.sin.f32(float ) nounwind" }, { (char*)"declare double @llvm.sin.f64(double) nounwind" }, { (char*)"declare float  @llvm.cos.f32(float ) nounwind" }, { (char*)"declare double @llvm.cos.f64(double) nounwind" }, { (char*)"declare float  @llvm.exp.f32(float ) nounwind" }, { (char*)"declare double @llvm.exp.f64(double) nounwind" }, { (char*)"declare float  @llvm.log.f32(float ) nounwind" }, { (char*)"declare double @llvm.log.f64(double) nounwind" }, { (char*)"declare float  @llvm.sqrt.f32(float ) nounwind" }, { (char*)"declare double @llvm.sqrt.f64(double) nounwind" }, { (char*)"declare float  @llvm.floor.f32(float ) nounwind" }, { (char*)"declare double @llvm.floor.f64(double) nounwind" }, { (char*)"declare float  @llvm.fabs.f32(float ) nounwind" }, { (char*)"declare double @llvm.fabs.f64(double) nounwind" }, { (char*)"declare float  @llvm.nearbyint.f32(float ) nounwind" }, { (char*)"declare double @llvm.nearbyint.f64(double) nounwind" } };
static struct $13IRLLVMCONTEXT CTX$;
static char* DTYPENAME$[26] = { (char*)"i8", (char*)"i8", (char*)"i8", (char*)"i8", (char*)"i8", (char*)"i16", (char*)"i16", (char*)0ull, (char*)0ull, (char*)0ull, (char*)0ull, (char*)"i32", (char*)"i32", (char*)"i64", (char*)"i64", (char*)"float", (char*)"double", (char*)"%FBSTRING", (char*)"i8", (char*)"%struct.va_list", (char*)0ull, (char*)0ull, (char*)0ull, (char*)"i8", (char*)0ull };
struct $7IR_VTBL IRLLVM_VTBL$ = { (tmp$39)&_INIT, (tmp$39)&_END, (tmp$40)&_EMITBEGIN, (tmp$39)&_EMITEND, (tmp$41)&_GETOPTIONVALUE, (tmp$42)&_SUPPORTSOP, (tmp$43)&_PROCBEGIN, (tmp$43)&_PROCEND, (tmp$44)&_PROCALLOCARG, (tmp$44)&_PROCALLOCLOCAL, (tmp$45)0ull, (tmp$43)&_SCOPEBEGIN, (tmp$43)&_SCOPEEND, (tmp$43)&_PROCALLOCSTATICVARS, (tmp$46)&_EMITCONVERT, (tmp$43)&_EMITLABEL, (tmp$43)&_EMITLABEL, (tmp$47)0ull, (tmp$44)&_EMITPROCBEGIN, (tmp$48)&_EMITPROCEND, (tmp$49)&IRHLEMITPUSHARG, (tmp$50)&_EMITASMLINE, (tmp$51)&_EMITCOMMENT, (tmp$52)&_EMITBOP, (tmp$53)&_EMITUOP, (tmp$46)&_EMITSTORE, (tmp$39)&_EMITSPILLREGS, (tmp$54)&_EMITLOAD, (tmp$46)&_EMITLOADRES, (tmp$53)0ull, (tmp$53)&_EMITADDR, (tmp$55)&_EMITCALL, (tmp$56)&_EMITCALLPTR, (tmp$47)0ull, (tmp$54)&_EMITJUMPPTR, (tmp$57)&_EMITBRANCH, (tmp$58)&_EMITJMPTB, (tmp$59)&_EMITMEM, (tmp$60)&_EMITMACRO, (tmp$43)&_EMITSCOPEBEGIN, (tmp$43)&_EMITSCOPEEND, (tmp$43)&_EMITDECL, (tmp$61)&_EMITDBG, (tmp$43)&_EMITVARINIBEGIN, (tmp$43)&_EMITVARINIEND, (tmp$62)&_EMITVARINII, (tmp$63)&_EMITVARINIF, (tmp$64)&_EMITVARINIOFS, (tmp$65)&_EMITVARINISTR, (tmp$66)&_EMITVARINIWSTR, (tmp$67)&_EMITVARINIPAD, (tmp$68)&_EMITVARINISCOPEBEGIN, (tmp$39)&_EMITVARINISCOPEEND, (tmp$39)&_EMITFBCTINFBEGIN, (tmp$69)&_EMITFBCTINFSTRING, (tmp$39)&_EMITFBCTINFEND, (tmp$70)&IRHLALLOCVREG, (tmp$71)&IRHLALLOCVRIMM, (tmp$72)&IRHLALLOCVRIMMF, (tmp$73)&IRHLALLOCVRVAR, (tmp$74)&IRHLALLOCVRIDX, (tmp$75)&IRHLALLOCVRPTR, (tmp$73)&IRHLALLOCVROFS, (tmp$76)&_SETVREGDATATYPE, (tmp$77)0ull, (tmp$53)0ull, (tmp$46)0ull, (tmp$47)0ull };

__attribute__(( constructor )) static void fb_ctor__irzllvm( void )
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

static void _ZN13IRLLVMCONTEXTC1Ev( struct $13IRLLVMCONTEXT* THIS$1 )
{
	__builtin_memset( (int64*)THIS$1, 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 8ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 16ll), 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 40ll), 0, 8ll );
	__builtin_memset( (struct $17IRLLVMVARINISCOPE*)((uint8*)THIS$1 + 48ll), 0, 128ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 176ll), 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 200ll), 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 224ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 232ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 240ll), 0, 24ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 264ll), 0, 8ll );
	__builtin_memset( (int64*)((uint8*)THIS$1 + 272ll), 0, 8ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 280ll), 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 304ll), 0, 24ll );
	__builtin_memset( (FBSTRING*)((uint8*)THIS$1 + 328ll), 0, 24ll );
	label$10:;
	label$11:;
}

static void _ZN13IRLLVMCONTEXTaSERKS_( struct $13IRLLVMCONTEXT* THIS$1, struct $13IRLLVMCONTEXT* __FB_RHS__$1 )
{
	int64 TMP$116$1;
	struct $17IRLLVMVARINISCOPE* TMP$117$1;
	struct $17IRLLVMVARINISCOPE* TMP$118$1;
	label$12:;
	*(int64*)THIS$1 = *(int64*)__FB_RHS__$1;
	*(int64*)((uint8*)THIS$1 + 8ll) = *(int64*)((uint8*)__FB_RHS__$1 + 8ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 16ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 16ll), -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 40ll) = *(int64*)((uint8*)__FB_RHS__$1 + 40ll);
	TMP$117$1 = (struct $17IRLLVMVARINISCOPE*)((uint8*)THIS$1 + 48ll);
	TMP$118$1 = (struct $17IRLLVMVARINISCOPE*)((uint8*)__FB_RHS__$1 + 48ll);
	TMP$116$1 = 0ll;
	label$14:;
	__builtin_memcpy( TMP$117$1, TMP$118$1, 1 );
	TMP$117$1 = (struct $17IRLLVMVARINISCOPE*)((uint8*)TMP$117$1 + 1ll);
	TMP$118$1 = (struct $17IRLLVMVARINISCOPE*)((uint8*)TMP$118$1 + 1ll);
	TMP$116$1 = TMP$116$1 + 1ll;
	if( TMP$116$1 != 128ll) goto label$14;
	fb_StrAssign( (void*)((uint8*)THIS$1 + 176ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 176ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 200ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 200ll), -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 224ll) = *(int64*)((uint8*)__FB_RHS__$1 + 224ll);
	*(int64*)((uint8*)THIS$1 + 232ll) = *(int64*)((uint8*)__FB_RHS__$1 + 232ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 240ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 240ll), -1ll, 0 );
	*(int64*)((uint8*)THIS$1 + 264ll) = *(int64*)((uint8*)__FB_RHS__$1 + 264ll);
	*(int64*)((uint8*)THIS$1 + 272ll) = *(int64*)((uint8*)__FB_RHS__$1 + 272ll);
	fb_StrAssign( (void*)((uint8*)THIS$1 + 280ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 280ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 304ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 304ll), -1ll, 0 );
	fb_StrAssign( (void*)((uint8*)THIS$1 + 328ll), -1ll, (void*)((uint8*)__FB_RHS__$1 + 328ll), -1ll, 0 );
	label$13:;
}

static void _ZN13IRLLVMCONTEXTD1Ev( struct $13IRLLVMCONTEXT* THIS$1 )
{
	label$17:;
	label$18:;
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 328ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 304ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 280ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 240ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 200ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 176ll) );
	fb_StrDelete( (FBSTRING*)((uint8*)THIS$1 + 16ll) );
}

static void _INIT( void )
{
	label$19:;
	IRHLINIT(  );
	*($6IR_OPT*)((uint8*)&IR$ + 544ll) = *(int64*)((uint8*)&IR$ + 544ll) | 131074ll;
	int64 vr$1 = FBIS64BIT(  );
	if( vr$1 == 0ll) goto label$22;
	{
		*(char**)((int64)(char**)DTYPENAME$ + 64ll) = *(char**)((int64)(char**)DTYPENAME$ + 104ll);
		*(char**)((int64)(char**)DTYPENAME$ + 72ll) = *(char**)((int64)(char**)DTYPENAME$ + 112ll);
	}
	goto label$21;
	label$22:;
	{
		*(char**)((int64)(char**)DTYPENAME$ + 64ll) = *(char**)((int64)(char**)DTYPENAME$ + 88ll);
		*(char**)((int64)(char**)DTYPENAME$ + 72ll) = *(char**)((int64)(char**)DTYPENAME$ + 96ll);
	}
	label$21:;
	label$20:;
}

static void _END( void )
{
	label$23:;
	IRHLEND(  );
	label$24:;
}

static void HWRITELINE( FBSTRING* LN$1 )
{
	int64 TMP$128$1;
	label$25:;
	if( *(int64*)&CTX$ <= 0ll) goto label$27;
	int64 vr$0 = fb_StrLen( (void*)LN$1, -1ll );
	TMP$128$1 = (int64)-(vr$0 > 0ll);
	goto label$756;
	label$27:;
	TMP$128$1 = 0ll;
	label$756:;
	if( TMP$128$1 == 0ll) goto label$29;
	{
		FBSTRING TMP$130$2;
		FBSTRING* vr$2 = fb_StrAllocTempDescZEx( (char*)"\x09", 1ll );
		FBSTRING* vr$3 = fb_StrFill2( *(int64*)&CTX$, (FBSTRING*)vr$2 );
		__builtin_memset( &TMP$130$2, 0, 24ll );
		FBSTRING* vr$6 = fb_StrConcat( &TMP$130$2, (void*)vr$3, -1ll, (void*)LN$1, -1ll );
		fb_StrAssign( (void*)LN$1, -1ll, (void*)vr$6, -1ll, 0 );
	}
	label$29:;
	label$28:;
	fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x0A", 2ll, 0 );
	{
		uint64 TMP$132$2;
		TMP$132$2 = *(uint64*)((uint8*)&CTX$ + 272ll);
		goto label$31;
		label$32:;
		{
			FBSTRING TMP$133$3;
			__builtin_memset( &TMP$133$3, 0, 24ll );
			FBSTRING* vr$10 = fb_StrConcat( &TMP$133$3, (void*)((uint8*)&CTX$ + 280ll), -1ll, (void*)LN$1, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 280ll), -1ll, (void*)vr$10, -1ll, 0 );
		}
		goto label$30;
		label$33:;
		{
			FBSTRING TMP$134$3;
			__builtin_memset( &TMP$134$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$134$3, (void*)((uint8*)&CTX$ + 304ll), -1ll, (void*)LN$1, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 304ll), -1ll, (void*)vr$15, -1ll, 0 );
		}
		goto label$30;
		label$34:;
		{
			FBSTRING TMP$135$3;
			__builtin_memset( &TMP$135$3, 0, 24ll );
			FBSTRING* vr$20 = fb_StrConcat( &TMP$135$3, (void*)((uint8*)&CTX$ + 328ll), -1ll, (void*)LN$1, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 328ll), -1ll, (void*)vr$20, -1ll, 0 );
		}
		goto label$30;
		label$31:;
		static const void* tmp$596[3ll] = {
			&&label$32,
			&&label$33,
			&&label$34,
		};
		if( TMP$132$2 > 2ull ) goto label$30;
		goto *tmp$596[TMP$132$2 - 0ull];
		label$30:;
	}
	label$26:;
}

static void HINTERNALCOMMAND( FBSTRING* MESSAGE$1 )
{
	FBSTRING TMP$137$1;
	FBSTRING TMP$138$1;
	label$35:;
	__builtin_memset( &TMP$138$1, 0, 24ll );
	__builtin_memset( &TMP$137$1, 0, 24ll );
	FBSTRING* vr$3 = fb_StrConcat( &TMP$137$1, (void*)"; ", 3ll, (void*)MESSAGE$1, -1ll );
	fb_StrAssign( (void*)&TMP$138$1, -1ll, (void*)vr$3, -1ll, 0 );
	HWRITELINE( &TMP$138$1 );
	fb_StrDelete( (FBSTRING*)&TMP$138$1 );
	label$36:;
}

static void HASTCOMMAND( FBSTRING* MESSAGE$1 )
{
	FBSTRING TMP$139$1;
	label$37:;
	__builtin_memset( &TMP$139$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$139$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$139$1 );
	fb_StrDelete( (FBSTRING*)&TMP$139$1 );
	HINTERNALCOMMAND( MESSAGE$1 );
	label$38:;
}

static void HWRITELABEL( char* ID$1 )
{
	FBSTRING TMP$141$1;
	FBSTRING TMP$142$1;
	label$39:;
	*(int64*)&CTX$ = *(int64*)&CTX$ + -1ll;
	__builtin_memset( &TMP$142$1, 0, 24ll );
	__builtin_memset( &TMP$141$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$141$1, (void*)ID$1, 0ll, (void*)":", 2ll );
	fb_StrAssign( (void*)&TMP$142$1, -1ll, (void*)vr$4, -1ll, 0 );
	HWRITELINE( &TMP$142$1 );
	fb_StrDelete( (FBSTRING*)&TMP$142$1 );
	*(int64*)&CTX$ = *(int64*)&CTX$ + 1ll;
	label$40:;
}

static FBSTRING* HSYMNAME( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$41:;
	if( *(char**)((uint8*)SYM$1 + 40ll) == (char*)0ull) goto label$44;
	{
		fb_StrAssign( (void*)&fb$result$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll, 0 );
	}
	goto label$43;
	label$44:;
	{
		fb_StrAssign( (void*)&fb$result$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll, 0 );
	}
	label$43:;
	label$42:;
	FBSTRING* vr$7 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$7;
}

static FBSTRING* VREGPRETTY( struct $6IRVREG* V$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$45:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	{
		$15IRVREGTYPE_ENUM TMP$143$2;
		TMP$143$2 = *($15IRVREGTYPE_ENUM*)V$1;
		if( TMP$143$2 != 0ll) goto label$48;
		label$49:;
		{
			int64 TMP$144$3;
			if( (*(int64*)((uint8*)V$1 + 8ll) & 480ll) == 0ll) goto label$50;
			TMP$144$3 = 24ll;
			goto label$757;
			label$50:;
			TMP$144$3 = *(int64*)((uint8*)V$1 + 8ll) & 31ll;
			label$757:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$144$3 * 56ll)) != 1ll) goto label$52;
			{
				FBSTRING* vr$9 = fb_DoubleToStr( *(double*)((uint8*)V$1 + 48ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$9, -1ll, 0 );
			}
			goto label$51;
			label$52:;
			{
				FBSTRING* vr$12 = fb_LongintToStr( *(int64*)((uint8*)V$1 + 48ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$12, -1ll, 0 );
			}
			label$51:;
		}
		goto label$47;
		label$48:;
		if( TMP$143$2 != 4ll) goto label$53;
		label$54:;
		{
			if( *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) == (struct $8FBSYMBOL*)0ull) goto label$56;
			{
				FBSTRING* vr$16 = HSYMNAME( *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$16, -1ll, 0 );
			}
			goto label$55;
			label$56:;
			{
				FBSTRING TMP$146$4;
				FBSTRING* vr$19 = fb_LongintToStr( *(int64*)((uint8*)V$1 + 24ll) );
				__builtin_memset( &TMP$146$4, 0, 24ll );
				FBSTRING* vr$22 = fb_StrConcat( &TMP$146$4, (void*)"vr", 3ll, (void*)vr$19, -1ll );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$22, -1ll, 0 );
			}
			label$55:;
		}
		goto label$47;
		label$53:;
		{
			if( *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) == (struct $8FBSYMBOL*)0ull) goto label$59;
			{
				FBSTRING* vr$26 = HSYMNAME( *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$26, -1ll, 0 );
			}
			label$59:;
			label$58:;
		}
		label$57:;
		label$47:;
	}
	if( *(struct $6IRVREG**)((uint8*)V$1 + 80ll) == (struct $6IRVREG*)0ull) goto label$61;
	{
		FBSTRING TMP$148$2;
		int64 vr$30 = fb_StrLen( (void*)&S$1, -1ll );
		if( vr$30 <= 0ll) goto label$63;
		{
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"+", 2ll, 0 );
		}
		label$63:;
		label$62:;
		FBSTRING* vr$33 = VREGPRETTY( *(struct $6IRVREG**)((uint8*)V$1 + 80ll) );
		__builtin_memset( &TMP$148$2, 0, 24ll );
		FBSTRING* vr$37 = fb_StrConcat( &TMP$148$2, (void*)&S$1, -1ll, (void*)vr$33, -1ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$37, -1ll, 0 );
	}
	label$61:;
	label$60:;
	if( *(int64*)((uint8*)V$1 + 64ll) == 0ll) goto label$65;
	{
		FBSTRING TMP$149$2;
		FBSTRING TMP$150$2;
		FBSTRING* vr$41 = fb_LongintToStr( *(int64*)((uint8*)V$1 + 64ll) );
		__builtin_memset( &TMP$149$2, 0, 24ll );
		FBSTRING* vr$44 = fb_StrConcat( &TMP$149$2, (void*)"+", 2ll, (void*)vr$41, -1ll );
		__builtin_memset( &TMP$150$2, 0, 24ll );
		FBSTRING* vr$48 = fb_StrConcat( &TMP$150$2, (void*)&S$1, -1ll, (void*)vr$44, -1ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$48, -1ll, 0 );
	}
	label$65:;
	label$64:;
	if( *(int64*)((uint8*)V$1 + 72ll) == 0ll) goto label$67;
	{
		FBSTRING TMP$152$2;
		FBSTRING TMP$153$2;
		FBSTRING* vr$52 = fb_LongintToStr( *(int64*)((uint8*)V$1 + 72ll) );
		__builtin_memset( &TMP$152$2, 0, 24ll );
		FBSTRING* vr$55 = fb_StrConcat( &TMP$152$2, (void*)"*", 2ll, (void*)vr$52, -1ll );
		__builtin_memset( &TMP$153$2, 0, 24ll );
		FBSTRING* vr$59 = fb_StrConcat( &TMP$153$2, (void*)&S$1, -1ll, (void*)vr$55, -1ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$59, -1ll, 0 );
	}
	label$67:;
	label$66:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$46:;
	FBSTRING* vr$65 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$65;
}

static FBSTRING* HEMITPARAMNAME( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING TMP$155$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$68:;
	char* vr$1 = SYMBGETMANGLEDNAME( SYM$1 );
	__builtin_memset( &TMP$155$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$155$1, (void*)vr$1, 0ll, (void*)"$", 2ll );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$4, -1ll, 0 );
	label$69:;
	FBSTRING* vr$7 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$7;
}

static FBSTRING* HEMITPROCCALLCONV( struct $8FBSYMBOL* PROC$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$70:;
	int64 vr$1 = FBGETCPUFAMILY(  );
	if( vr$1 == 0ll) goto label$73;
	{
		goto label$71;
	}
	label$73:;
	label$72:;
	{
		uint64 TMP$156$2;
		TMP$156$2 = *(uint64*)((uint8*)PROC$1 + 152ll);
		goto label$75;
		label$76:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"x86_stdcallcc ", 15ll, 0 );
		}
		goto label$74;
		label$77:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"x86_thiscall ", 14ll, 0 );
		}
		goto label$74;
		label$78:;
		{
			fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"x86_fastcall ", 14ll, 0 );
		}
		goto label$74;
		label$75:;
		static const void* tmp$597[6ll] = {
			&&label$76,
			&&label$76,
			&&label$74,
			&&label$76,
			&&label$77,
			&&label$78,
		};
		if( (TMP$156$2 - 1ull) > 5ull ) goto label$74;
		goto *tmp$597[TMP$156$2 - 1ull];
		label$74:;
	}
	label$71:;
	FBSTRING* vr$7 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$7;
}

static FBSTRING* HEMITPROCHEADER( struct $8FBSYMBOL* PROC$1, int64 IS_PROTO$1, int64 IS_TYPE$1 )
{
	FBSTRING TMP$160$1;
	struct $8FBSYMBOL* TMP$167$1;
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$79:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	int64 DTYPE$1;
	struct $8FBSYMBOL* SUBTYPE$1;
	FBSTRING* vr$2 = HEMITPROCCALLCONV( PROC$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$2, -1ll, 0 );
	FBSTRING* vr$7 = HEMITTYPE( *(int64*)((uint8*)PROC$1 + 160ll) & 511ll, *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 168ll) );
	__builtin_memset( &TMP$160$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$160$1, (void*)&LN$1, -1ll, (void*)vr$7, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$11, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	if( IS_TYPE$1 != 0ll) goto label$82;
	{
		FBSTRING TMP$162$2;
		char* vr$14 = SYMBGETMANGLEDNAME( PROC$1 );
		__builtin_memset( &TMP$162$2, 0, 24ll );
		FBSTRING* vr$18 = fb_StrConcat( &TMP$162$2, (void*)&LN$1, -1ll, (void*)vr$14, 0ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$18, -1ll, 0 );
	}
	label$82:;
	label$81:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"( ", 3ll, 0 );
	struct $8FBSYMBOL* HIDDEN$1;
	HIDDEN$1 = (struct $8FBSYMBOL*)0ull;
	int64 vr$21 = SYMBPROCRETURNSONSTACK( PROC$1 );
	if( vr$21 == 0ll) goto label$84;
	{
		if( IS_PROTO$1 == 0ll) goto label$86;
		{
			FBSTRING TMP$164$3;
			HIDDEN$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 64ll);
			FBSTRING* vr$40 = HEMITTYPE( ((((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 32505856ll), HIDDEN$1 );
			__builtin_memset( &TMP$164$3, 0, 24ll );
			FBSTRING* vr$44 = fb_StrConcat( &TMP$164$3, (void*)&LN$1, -1ll, (void*)vr$40, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$44, -1ll, 0 );
		}
		goto label$85;
		label$86:;
		{
			FBSTRING TMP$165$3;
			HIDDEN$1 = *(struct $8FBSYMBOL**)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll);
			FBSTRING* vr$66 = HEMITTYPE( ((((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)HIDDEN$1 + 56ll) & 511ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)HIDDEN$1 + 64ll) );
			__builtin_memset( &TMP$165$3, 0, 24ll );
			FBSTRING* vr$70 = fb_StrConcat( &TMP$165$3, (void*)&LN$1, -1ll, (void*)vr$66, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$70, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
			FBSTRING* vr$73 = HEMITPARAMNAME( HIDDEN$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$73, -1ll, 0 );
		}
		label$85:;
		if( (int64)*(int16*)((uint8*)PROC$1 + 120ll) <= 0ll) goto label$88;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$88:;
		label$87:;
	}
	label$84:;
	label$83:;
	struct $8FBSYMBOL* PARAM$1;
	if( *(int64*)((uint8*)PROC$1 + 152ll) != 4ll) goto label$89;
	TMP$167$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 144ll);
	goto label$758;
	label$89:;
	TMP$167$1 = *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 136ll);
	label$758:;
	PARAM$1 = TMP$167$1;
	label$90:;
	if( PARAM$1 == (struct $8FBSYMBOL*)0ull) goto label$91;
	{
		struct $8FBSYMBOL* TMP$171$2;
		if( *(int64*)((uint8*)PARAM$1 + 96ll) != 4ll) goto label$93;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"...", 4ll, 0 );
		}
		goto label$92;
		label$93:;
		{
			_Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( PARAM$1, &DTYPE$1, &SUBTYPE$1 );
			FBSTRING* vr$85 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$85, -1ll, 0 );
			if( IS_PROTO$1 != 0ll) goto label$95;
			{
				FBSTRING TMP$169$4;
				FBSTRING TMP$170$4;
				FBSTRING* vr$88 = HEMITPARAMNAME( *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 104ll) );
				__builtin_memset( &TMP$169$4, 0, 24ll );
				FBSTRING* vr$91 = fb_StrConcat( &TMP$169$4, (void*)" ", 2ll, (void*)vr$88, -1ll );
				__builtin_memset( &TMP$170$4, 0, 24ll );
				FBSTRING* vr$95 = fb_StrConcat( &TMP$170$4, (void*)&LN$1, -1ll, (void*)vr$91, -1ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$95, -1ll, 0 );
			}
			label$95:;
			label$94:;
		}
		label$92:;
		if( *(int64*)((uint8*)PROC$1 + 152ll) != 4ll) goto label$96;
		TMP$171$2 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 304ll);
		goto label$759;
		label$96:;
		TMP$171$2 = *(struct $8FBSYMBOL**)((uint8*)PARAM$1 + 312ll);
		label$759:;
		PARAM$1 = TMP$171$2;
		if( PARAM$1 == (struct $8FBSYMBOL*)0ull) goto label$98;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$98:;
		label$97:;
	}
	goto label$90;
	label$91:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" )", 3ll, 0 );
	if( IS_TYPE$1 != 0ll) goto label$100;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" nounwind", 10ll, 0 );
		if( (*(int64*)((uint8*)PROC$1 + 16ll) & 128ll) == 0ll) goto label$102;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" naked", 7ll, 0 );
		}
		label$102:;
		label$101:;
	}
	label$100:;
	label$99:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&LN$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$80:;
	FBSTRING* vr$110 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$110;
}

static FBSTRING* HGETUDTNAME( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$103:;
	struct $8FBSYMBOL* NS$1;
	NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)SYM$1 + 248ll);
	FBSTRING S$1;
	fb_StrInit( (void*)&S$1, -1ll, (void*)"%", 2ll, 0 );
	label$105:;
	if( NS$1 == (struct $8FBSYMBOL*)((uint8*)&SYMB$ + 196704ll)) goto label$106;
	{
		FBSTRING TMP$176$2;
		__builtin_memset( &TMP$176$2, 0, 24ll );
		FBSTRING* vr$9 = fb_StrConcat( &TMP$176$2, (void*)&S$1, -1ll, *(void**)((uint8*)NS$1 + 32ll), 0ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$9, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)".", 2ll, 0 );
		NS$1 = *(struct $8FBSYMBOL**)*(struct $8FBHASHTB**)((uint8*)NS$1 + 248ll);
	}
	goto label$105;
	label$106:;
	if( *(char**)((uint8*)SYM$1 + 40ll) == (char*)0ull) goto label$108;
	{
		FBSTRING TMP$177$2;
		__builtin_memset( &TMP$177$2, 0, 24ll );
		FBSTRING* vr$19 = fb_StrConcat( &TMP$177$2, (void*)&S$1, -1ll, *(void**)((uint8*)SYM$1 + 40ll), 0ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$19, -1ll, 0 );
	}
	goto label$107;
	label$108:;
	{
		FBSTRING TMP$178$2;
		__builtin_memset( &TMP$178$2, 0, 24ll );
		FBSTRING* vr$25 = fb_StrConcat( &TMP$178$2, (void*)&S$1, -1ll, *(void**)((uint8*)SYM$1 + 32ll), 0ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$25, -1ll, 0 );
	}
	label$107:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$104:;
	FBSTRING* vr$31 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$31;
}

static void HEMITUDT( struct $8FBSYMBOL* S$1 )
{
	label$109:;
	if( S$1 != (struct $8FBSYMBOL*)0ull) goto label$112;
	{
		goto label$110;
	}
	label$112:;
	label$111:;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 67108864ll) == 0ll) goto label$114;
	{
		goto label$110;
	}
	label$114:;
	label$113:;
	int64 OLDSECTION$1;
	OLDSECTION$1 = *(int64*)((uint8*)&CTX$ + 272ll);
	if( (*(int64*)((uint8*)S$1 + 8ll) & 128ll) != 0ll) goto label$116;
	{
		*(int64*)((uint8*)&CTX$ + 272ll) = 0ll;
	}
	label$116:;
	label$115:;
	{
		uint64 TMP$179$2;
		TMP$179$2 = *(uint64*)S$1;
		goto label$118;
		label$119:;
		{
			FBSTRING TMP$181$3;
			FBSTRING TMP$182$3;
			FBSTRING TMP$183$3;
			*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 67108864ll;
			__builtin_memset( &TMP$183$3, 0, 24ll );
			FBSTRING* vr$9 = HEMITTYPE( 10ll, (struct $8FBSYMBOL*)0ull );
			FBSTRING* vr$10 = HGETUDTNAME( S$1 );
			__builtin_memset( &TMP$181$3, 0, 24ll );
			FBSTRING* vr$13 = fb_StrConcat( &TMP$181$3, (void*)vr$10, -1ll, (void*)" = type ", 9ll );
			__builtin_memset( &TMP$182$3, 0, 24ll );
			FBSTRING* vr$16 = fb_StrConcat( &TMP$182$3, (void*)vr$13, -1ll, (void*)vr$9, -1ll );
			fb_StrAssign( (void*)&TMP$183$3, -1ll, (void*)vr$16, -1ll, 0 );
			HWRITELINE( &TMP$183$3 );
			fb_StrDelete( (FBSTRING*)&TMP$183$3 );
		}
		goto label$117;
		label$120:;
		{
			HEMITSTRUCT( S$1 );
		}
		goto label$117;
		label$118:;
		static const void* tmp$598[2ll] = {
			&&label$119,
			&&label$120,
		};
		if( (TMP$179$2 - 9ull) > 1ull ) goto label$117;
		goto *tmp$598[TMP$179$2 - 9ull];
		label$117:;
	}
	*(int64*)((uint8*)&CTX$ + 272ll) = OLDSECTION$1;
	label$110:;
}

static void HBUILDSTRLIT( FBSTRING* LN$1, int64 WANTEDLENGTH$1, char* Z$1, int64 LENGTH$1 )
{
	label$121:;
	int64 CH$1;
	if( LENGTH$1 <= WANTEDLENGTH$1) goto label$124;
	{
		LENGTH$1 = WANTEDLENGTH$1;
	}
	label$124:;
	label$123:;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$184$2;
		TMP$184$2 = LENGTH$1 + -1ll;
		goto label$125;
		label$128:;
		{
			CH$1 = (int64)*(uint8*)((uint8*)Z$1 + I$2);
			int64 vr$3 = HCHARNEEDSESCAPING( CH$1, 34ll );
			if( vr$3 == 0ll) goto label$130;
			{
				FBSTRING TMP$187$4;
				FBSTRING* vr$4 = fb_HEXEx_l( (uint64)CH$1, 2 );
				__builtin_memset( &TMP$187$4, 0, 24ll );
				FBSTRING* vr$7 = fb_StrConcat( &TMP$187$4, (void*)"\x5C", 2ll, (void*)vr$4, -1ll );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$7, -1ll, 0 );
			}
			goto label$129;
			label$130:;
			{
				FBSTRING* vr$8 = fb_CHR( 1, CH$1 );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$8, -1ll, 0 );
			}
			label$129:;
		}
		label$126:;
		I$2 = I$2 + 1ll;
		label$125:;
		if( I$2 <= TMP$184$2) goto label$128;
		label$127:;
	}
	label$131:;
	if( LENGTH$1 >= WANTEDLENGTH$1) goto label$132;
	{
		fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x5C" "00", 4ll, 0 );
		LENGTH$1 = LENGTH$1 + 1ll;
	}
	goto label$131;
	label$132:;
	label$122:;
}

static void HBUILDWSTRLIT( FBSTRING* LN$1, int64 WANTEDLENGTH$1, uint32* W$1, int64 LENGTH$1 )
{
	label$133:;
	uint64 CH$1;
	uint64 WCHARSIZE$1;
	WCHARSIZE$1 = *(uint64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + 400ll);
	if( LENGTH$1 <= WANTEDLENGTH$1) goto label$136;
	{
		LENGTH$1 = WANTEDLENGTH$1;
	}
	label$136:;
	label$135:;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$189$2;
		TMP$189$2 = LENGTH$1 + -1ll;
		goto label$137;
		label$140:;
		{
			CH$1 = (uint64)*(uint32*)((uint8*)W$1 + (I$2 << (2ll & 63ll)));
			int64 vr$4 = HCHARNEEDSESCAPING( (int64)CH$1, 34ll );
			if( vr$4 == 0ll) goto label$142;
			{
				if( WCHARSIZE$1 < 1ull) goto label$144;
				{
					FBSTRING TMP$190$5;
					FBSTRING* vr$6 = fb_HEXEx_l( CH$1 & 255ull, 2 );
					__builtin_memset( &TMP$190$5, 0, 24ll );
					FBSTRING* vr$9 = fb_StrConcat( &TMP$190$5, (void*)"\x5C", 2ll, (void*)vr$6, -1ll );
					fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$9, -1ll, 0 );
				}
				label$144:;
				label$143:;
				if( WCHARSIZE$1 < 2ull) goto label$146;
				{
					FBSTRING TMP$191$5;
					FBSTRING* vr$12 = fb_HEXEx_l( (CH$1 >> (8ll & 63ll)) & 255ull, 2 );
					__builtin_memset( &TMP$191$5, 0, 24ll );
					FBSTRING* vr$15 = fb_StrConcat( &TMP$191$5, (void*)"\x5C", 2ll, (void*)vr$12, -1ll );
					fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$15, -1ll, 0 );
				}
				label$146:;
				label$145:;
				if( WCHARSIZE$1 < 4ull) goto label$148;
				{
					FBSTRING TMP$192$5;
					FBSTRING TMP$193$5;
					FBSTRING* vr$18 = fb_HEXEx_l( (CH$1 >> (16ll & 63ll)) & 255ull, 2 );
					__builtin_memset( &TMP$192$5, 0, 24ll );
					FBSTRING* vr$21 = fb_StrConcat( &TMP$192$5, (void*)"\x5C", 2ll, (void*)vr$18, -1ll );
					fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$21, -1ll, 0 );
					FBSTRING* vr$24 = fb_HEXEx_l( (CH$1 >> (24ll & 63ll)) & 255ull, 2 );
					__builtin_memset( &TMP$193$5, 0, 24ll );
					FBSTRING* vr$27 = fb_StrConcat( &TMP$193$5, (void*)"\x5C", 2ll, (void*)vr$24, -1ll );
					fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$27, -1ll, 0 );
				}
				label$148:;
				label$147:;
			}
			goto label$141;
			label$142:;
			{
				FBSTRING* vr$28 = fb_CHR( 1, (int64)CH$1 );
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)vr$28, -1ll, 0 );
				{
					int64 J$5;
					J$5 = 2ll;
					int64 TMP$194$5;
					TMP$194$5 = (int64)WCHARSIZE$1;
					goto label$149;
					label$152:;
					{
						fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x5C" "00", 4ll, 0 );
					}
					label$150:;
					J$5 = J$5 + 1ll;
					label$149:;
					if( J$5 <= TMP$194$5) goto label$152;
					label$151:;
				}
			}
			label$141:;
		}
		label$138:;
		I$2 = I$2 + 1ll;
		label$137:;
		if( I$2 <= TMP$189$2) goto label$140;
		label$139:;
	}
	label$153:;
	if( LENGTH$1 >= WANTEDLENGTH$1) goto label$154;
	{
		{
			int64 J$3;
			J$3 = 1ll;
			int64 TMP$195$3;
			TMP$195$3 = (int64)WCHARSIZE$1;
			goto label$155;
			label$158:;
			{
				fb_StrConcatByref( (void*)LN$1, -1ll, (void*)"\x5C" "00", 4ll, 0 );
			}
			label$156:;
			J$3 = J$3 + 1ll;
			label$155:;
			if( J$3 <= TMP$195$3) goto label$158;
			label$157:;
		}
		LENGTH$1 = LENGTH$1 + 1ll;
	}
	goto label$153;
	label$154:;
	label$134:;
}

static FBSTRING* HEMITSTRLITTYPE( int64 LENGTH$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$159:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"[", 2ll, 0 );
	FBSTRING* vr$2 = fb_LongintToStr( LENGTH$1 );
	fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)" x i8]", 7ll, 0 );
	label$160:;
	FBSTRING* vr$6 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$6;
}

static FBSTRING* HEMITSYMTYPE( struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$161:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	int64 DTYPE$1;
	DTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 262144ll) == 0ll) goto label$164;
	{
		FBSTRING* vr$16 = HEMITTYPE( (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$16, -1ll, 0 );
	}
	goto label$163;
	label$164:;
	{
		{
			if( DTYPE$1 == 18ll) goto label$167;
			label$168:;
			if( DTYPE$1 == 4ll) goto label$167;
			label$169:;
			if( DTYPE$1 != 7ll) goto label$166;
			label$167:;
			{
				FBSTRING* vr$19 = HEMITSTRLITTYPE( *(int64*)((uint8*)SYM$1 + 80ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$19, -1ll, 0 );
			}
			goto label$165;
			label$166:;
			{
				FBSTRING* vr$22 = HEMITTYPE( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$22, -1ll, 0 );
			}
			label$170:;
			label$165:;
		}
	}
	label$163:;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 16388ll) == 0ll) goto label$172;
	{
	}
	goto label$171;
	label$172:;
	{
		{
			$12FB_SYMBCLASS TMP$198$3;
			TMP$198$3 = *($12FB_SYMBCLASS*)SYM$1;
			if( TMP$198$3 == 1ll) goto label$175;
			label$176:;
			if( TMP$198$3 != 12ll) goto label$174;
			label$175:;
			{
				{
					int64 I$5;
					I$5 = *(int64*)((uint8*)SYM$1 + 104ll) + -1ll;
					goto label$177;
					label$180:;
					{
						FBSTRING TMP$201$6;
						FBSTRING TMP$202$6;
						FBSTRING TMP$203$6;
						FBSTRING TMP$204$6;
						int64 ELEMENTS$6;
						ELEMENTS$6 = (*(int64*)((uint8*)((uint8*)*(struct $10FBARRAYDIM**)((uint8*)SYM$1 + 112ll) + (I$5 << (4ll & 63ll))) + 8ll) - *(int64*)((uint8*)*(struct $10FBARRAYDIM**)((uint8*)SYM$1 + 112ll) + (I$5 << (4ll & 63ll)))) + 1ll;
						__builtin_memset( &TMP$202$6, 0, 24ll );
						FBSTRING* vr$40 = fb_StrConcat( &TMP$202$6, (void*)" x ", 4ll, (void*)&S$1, -1ll );
						__builtin_memset( &TMP$203$6, 0, 24ll );
						FBSTRING* vr$43 = fb_StrConcat( &TMP$203$6, (void*)vr$40, -1ll, (void*)"]", 2ll );
						FBSTRING* vr$44 = fb_LongintToStr( ELEMENTS$6 );
						__builtin_memset( &TMP$201$6, 0, 24ll );
						FBSTRING* vr$47 = fb_StrConcat( &TMP$201$6, (void*)"[", 2ll, (void*)vr$44, -1ll );
						__builtin_memset( &TMP$204$6, 0, 24ll );
						FBSTRING* vr$50 = fb_StrConcat( &TMP$204$6, (void*)vr$47, -1ll, (void*)vr$43, -1ll );
						fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$50, -1ll, 0 );
					}
					label$178:;
					I$5 = I$5 + -1ll;
					label$177:;
					if( I$5 >= 0ll) goto label$180;
					label$179:;
				}
			}
			label$174:;
			label$173:;
		}
	}
	label$171:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$162:;
	FBSTRING* vr$57 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$57;
}

static void HEMITVARIABLE( struct $8FBSYMBOL* SYM$1 )
{
	label$181:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	int64 IS_GLOBAL$1;
	int64 LENGTH$1;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 1024ll) == 0ll) goto label$184;
	{
		if( (*(int64*)((uint8*)SYM$1 + 24ll) & 2ll) != 0ll) goto label$186;
		{
			fb_StrDelete( (FBSTRING*)&LN$1 );
			goto label$182;
		}
		label$186:;
		label$185:;
		{
			int64 TMP$205$3;
			TMP$205$3 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
			if( TMP$205$3 == 4ll) goto label$189;
			label$190:;
			if( TMP$205$3 != 7ll) goto label$188;
			label$189:;
			{
				FBSTRING TMP$207$4;
				char* vr$8 = SYMBGETMANGLEDNAME( SYM$1 );
				__builtin_memset( &TMP$207$4, 0, 24ll );
				FBSTRING* vr$11 = fb_StrConcat( &TMP$207$4, (void*)vr$8, 0ll, (void*)" = ", 4ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$11, -1ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"private constant ", 18ll, 0 );
				FBSTRING* vr$14 = HEMITSYMTYPE( SYM$1 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$14, -1ll, 0 );
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" c\x22", 4ll, 0 );
				if( (*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) != 7ll) goto label$192;
				{
					int64 TMP$210$5;
					int64 vr$19 = SYMBGETWSTRLENGTH( SYM$1 );
					LENGTH$1 = vr$19 + 1ll;
					TMP$210$5 = 0ll;
					uint32* vr$23 = HUNESCAPEW( *(uint32**)((uint8*)SYM$1 + 96ll), &TMP$210$5 );
					HBUILDWSTRLIT( &LN$1, LENGTH$1, vr$23, LENGTH$1 );
				}
				goto label$191;
				label$192:;
				{
					int64 TMP$211$5;
					int64 vr$25 = SYMBGETSTRLENGTH( SYM$1 );
					LENGTH$1 = vr$25 + 1ll;
					TMP$211$5 = 0ll;
					char* vr$29 = HUNESCAPE( *(char**)((uint8*)SYM$1 + 96ll), &TMP$211$5 );
					HBUILDSTRLIT( &LN$1, LENGTH$1, vr$29, LENGTH$1 );
				}
				label$191:;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
				HWRITELINE( &LN$1 );
			}
			goto label$187;
			label$188:;
			{
			}
			label$193:;
			label$187:;
		}
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$182;
	}
	label$184:;
	label$183:;
	if( ((int64)-(*(struct $7ASTNODE**)((uint8*)SYM$1 + 96ll) != (struct $7ASTNODE*)0ull) & ((int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 128ll) == 0ll) | (int64)-((*(int64*)((uint8*)SYM$1 + 8ll) & 2ll) != 0ll))) == 0ll) goto label$195;
	{
		if( (*(int64*)((uint8*)SYM$1 + 8ll) & 128ll) != 0ll) goto label$197;
		{
			if( (*(int64*)((uint8*)SYM$1 + 24ll) & 2ll) != 0ll) goto label$199;
			{
				if( (*(int64*)((uint8*)SYM$1 + 8ll) & 32ll) != 0ll) goto label$201;
				{
					fb_StrDelete( (FBSTRING*)&LN$1 );
					goto label$182;
				}
				label$201:;
				label$200:;
			}
			label$199:;
			label$198:;
		}
		label$197:;
		label$196:;
		IRHLFLUSHSTATICINITIALIZER( SYM$1 );
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$182;
	}
	label$195:;
	label$194:;
	if( (*(int64*)((uint8*)SYM$1 + 8ll) & 16388ll) == 0ll) goto label$203;
	{
		fb_StrDelete( (FBSTRING*)&LN$1 );
		goto label$182;
	}
	label$203:;
	label$202:;
	IS_GLOBAL$1 = *(int64*)((uint8*)SYM$1 + 8ll) & 59ll;
	char* vr$57 = SYMBGETMANGLEDNAME( SYM$1 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$57, 0ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = ", 4ll, 0 );
	if( IS_GLOBAL$1 == 0ll) goto label$205;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"global", 7ll, 0 );
	}
	goto label$204;
	label$205:;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"alloca", 7ll, 0 );
	}
	label$204:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$63 = HEMITSYMTYPE( SYM$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$63, -1ll, 0 );
	if( IS_GLOBAL$1 == 0ll) goto label$207;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" zeroinitializer", 17ll, 0 );
	}
	label$207:;
	label$206:;
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$182:;
}

static void HMAYBEEMITGLOBALVAR( struct $8FBSYMBOL* SYM$1 )
{
	label$208:;
	int64 vr$0 = SYMBISDATADESC( SYM$1 );
	if( vr$0 != 0ll) goto label$211;
	{
		HEMITVARIABLE( SYM$1 );
	}
	label$211:;
	label$210:;
	label$209:;
}

static void HMAYBEEMITPROCPROTO( struct $8FBSYMBOL* S$1 )
{
	FBSTRING TMP$216$1;
	FBSTRING TMP$217$1;
	label$212:;
	if( ((int64)-((*(int64*)((uint8*)S$1 + 24ll) & 16384ll) != 0ll) | (int64)-((*(int64*)((uint8*)S$1 + 24ll) & 2ll) == 0ll)) == 0ll) goto label$215;
	{
		goto label$213;
	}
	label$215:;
	label$214:;
	char* vr$7 = SYMBGETMANGLEDNAME( S$1 );
	if( vr$7 != (char*)0ull) goto label$217;
	{
		goto label$213;
	}
	label$217:;
	label$216:;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 128ll) == 0ll) goto label$219;
	{
		goto label$213;
	}
	label$219:;
	label$218:;
	int64 OLDSECTION$1;
	OLDSECTION$1 = *(int64*)((uint8*)&CTX$ + 272ll);
	*(int64*)((uint8*)&CTX$ + 272ll) = 0ll;
	__builtin_memset( &TMP$217$1, 0, 24ll );
	FBSTRING* vr$11 = HEMITPROCHEADER( S$1, -1ll, 0ll );
	__builtin_memset( &TMP$216$1, 0, 24ll );
	FBSTRING* vr$14 = fb_StrConcat( &TMP$216$1, (void*)"declare ", 9ll, (void*)vr$11, -1ll );
	fb_StrAssign( (void*)&TMP$217$1, -1ll, (void*)vr$14, -1ll, 0 );
	HWRITELINE( &TMP$217$1 );
	fb_StrDelete( (FBSTRING*)&TMP$217$1 );
	*(int64*)((uint8*)&CTX$ + 272ll) = OLDSECTION$1;
	label$213:;
}

static void HEMITSTRUCT( struct $8FBSYMBOL* S$1 )
{
	label$220:;
	struct $8FBSYMBOL* FLD$1;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 134217728ll) == 0ll) goto label$223;
	{
		goto label$221;
	}
	label$223:;
	label$222:;
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 134217728ll;
	struct $8FBSYMBOL* vr$5 = SYMBUDTGETFIRSTFIELD( S$1 );
	FLD$1 = vr$5;
	label$224:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$225;
	{
		HEMITUDT( *(struct $8FBSYMBOL**)((uint8*)FLD$1 + 64ll) );
		struct $8FBSYMBOL* vr$7 = SYMBUDTGETNEXTFIELD( FLD$1 );
		FLD$1 = vr$7;
	}
	goto label$224;
	label$225:;
	if( (*(int64*)((uint8*)S$1 + 24ll) & 67108864ll) == 0ll) goto label$227;
	{
		goto label$221;
	}
	label$227:;
	label$226:;
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) | 67108864ll;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	if( *(char**)((uint8*)S$1 + 32ll) == (char*)0ull) goto label$229;
	{
		FBSTRING* vr$15 = HGETUDTNAME( S$1 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$15, -1ll, 0 );
	}
	goto label$228;
	label$229:;
	{
		FBSTRING TMP$218$2;
		FBSTRING TMP$219$2;
		char* vr$17 = SYMBUNIQUEID( (boolean)0ll );
		__builtin_memset( &TMP$218$2, 0, 24ll );
		FBSTRING* vr$20 = fb_StrConcat( &TMP$218$2, (void*)"%", 2ll, (void*)vr$17, 0ll );
		__builtin_memset( &TMP$219$2, 0, 24ll );
		FBSTRING* vr$24 = fb_StrConcat( &TMP$219$2, (void*)&LN$1, -1ll, (void*)vr$20, -1ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$24, -1ll, 0 );
	}
	label$228:;
	int64 PACKED$1;
	PACKED$1 = (int64)-((int64)*(uint8*)((uint8*)S$1 + 213ll) == 1ll);
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = type ", 9ll, 0 );
	if( PACKED$1 == 0ll) goto label$231;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"<", 2ll, 0 );
		label$231:;
	}
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"{ ", 3ll, 0 );
	struct $8FBSYMBOL* vr$32 = SYMBUDTGETFIRSTFIELD( S$1 );
	FLD$1 = vr$32;
	label$232:;
	if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$233;
	{
		if( (*(int64*)((uint8*)FLD$1 + 8ll) & 4ll) != 0ll) goto label$235;
		{
			FBSTRING* vr$35 = HEMITSYMTYPE( FLD$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$35, -1ll, 0 );
		}
		label$235:;
		label$234:;
		struct $8FBSYMBOL* vr$37 = SYMBUDTGETNEXTFIELD( FLD$1 );
		FLD$1 = vr$37;
		if( FLD$1 == (struct $8FBSYMBOL*)0ull) goto label$237;
		{
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$237:;
		label$236:;
	}
	goto label$232;
	label$233:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" }", 3ll, 0 );
	if( PACKED$1 == 0ll) goto label$239;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)">", 2ll, 0 );
		label$239:;
	}
	HWRITELINE( &LN$1 );
	*($12FB_SYMBSTATS*)((uint8*)S$1 + 24ll) = *(int64*)((uint8*)S$1 + 24ll) & -134217729ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$221:;
}

static void HEMITCTORDTORARRAYELEMENT( struct $8FBSYMBOL* PROC$1, FBSTRING* S$1 )
{
	FBSTRING TMP$225$1;
	FBSTRING TMP$227$1;
	label$240:;
	int64 vr$0 = fb_StrLen( (void*)S$1, -1ll );
	if( vr$0 <= 0ll) goto label$243;
	{
		fb_StrConcatByref( (void*)S$1, -1ll, (void*)", ", 3ll, 0 );
	}
	label$243:;
	label$242:;
	fb_StrConcatByref( (void*)S$1, -1ll, (void*)"{ i32, void ()* } { i32 ", 25ll, 0 );
	FBSTRING* vr$3 = fb_LongintToStr( *(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 112ll) );
	__builtin_memset( &TMP$225$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$225$1, (void*)S$1, -1ll, (void*)vr$3, -1ll );
	fb_StrAssign( (void*)S$1, -1ll, (void*)vr$6, -1ll, 0 );
	fb_StrConcatByref( (void*)S$1, -1ll, (void*)", void ()* ", 12ll, 0 );
	char* vr$7 = SYMBGETMANGLEDNAME( PROC$1 );
	__builtin_memset( &TMP$227$1, 0, 24ll );
	FBSTRING* vr$10 = fb_StrConcat( &TMP$227$1, (void*)S$1, -1ll, (void*)vr$7, 0ll );
	fb_StrAssign( (void*)S$1, -1ll, (void*)vr$10, -1ll, 0 );
	fb_StrConcatByref( (void*)S$1, -1ll, (void*)" }", 3ll, 0 );
	label$241:;
}

static void HADDGLOBALCTORDTOR( struct $8FBSYMBOL* PROC$1 )
{
	label$244:;
	if( (*(int64*)((uint8*)PROC$1 + 24ll) & 16384ll) == 0ll) goto label$247;
	{
		goto label$245;
	}
	label$247:;
	label$246:;
	if( (*(int64*)((uint8*)PROC$1 + 24ll) & 65536ll) == 0ll) goto label$249;
	{
		*(int64*)((uint8*)&CTX$ + 224ll) = *(int64*)((uint8*)&CTX$ + 224ll) + 1ll;
		HEMITCTORDTORARRAYELEMENT( PROC$1, (FBSTRING*)((uint8*)&CTX$ + 176ll) );
	}
	goto label$248;
	label$249:;
	if( (*(int64*)((uint8*)PROC$1 + 24ll) & 131072ll) == 0ll) goto label$250;
	{
		*(int64*)((uint8*)&CTX$ + 232ll) = *(int64*)((uint8*)&CTX$ + 232ll) + 1ll;
		HEMITCTORDTORARRAYELEMENT( PROC$1, (FBSTRING*)((uint8*)&CTX$ + 200ll) );
	}
	label$250:;
	label$248:;
	label$245:;
}

static int64 _EMITBEGIN( void )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$251:;
	int64 vr$2 = HFILEEXISTS( (char*)((uint8*)&ENV$ + 928ll) );
	if( vr$2 == 0ll) goto label$254;
	{
		FBSTRING* vr$4 = fb_StrAllocTempDescZ( (char*)((uint8*)&ENV$ + 928ll) );
		fb_FileKill( (FBSTRING*)vr$4 );
	}
	label$254:;
	label$253:;
	int32 vr$5 = fb_FileFree(  );
	*(int64*)((uint8*)&ENV$ + 920ll) = (int64)vr$5;
	FBSTRING* vr$9 = fb_StrAllocTempDescZ( (char*)((uint8*)&ENV$ + 928ll) );
	int32 vr$10 = fb_FileOpen( (FBSTRING*)vr$9, 0u, 3u, 0u, (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0 );
	if( (int64)vr$10 == 0ll) goto label$256;
	{
		fb$result$1 = 0ll;
		goto label$252;
	}
	label$256:;
	label$255:;
	*(int64*)&CTX$ = 0ll;
	fb_StrAssign( (void*)((uint8*)&CTX$ + 176ll), -1ll, (void*)"", 1ll, 0 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 200ll), -1ll, (void*)"", 1ll, 0 );
	*(int64*)((uint8*)&CTX$ + 224ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 232ll) = 0ll;
	fb_StrAssign( (void*)((uint8*)&CTX$ + 280ll), -1ll, (void*)"", 1ll, 0 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 304ll), -1ll, (void*)"", 1ll, 0 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 328ll), -1ll, (void*)"", 1ll, 0 );
	*(int64*)((uint8*)&CTX$ + 8ll) = 0ll;
	*(int64*)((uint8*)&CTX$ + 272ll) = 0ll;
	{
		int64 I$2;
		I$2 = 0ll;
		label$260:;
		{
			*(int64*)(((int64)(struct $7BUILTIN*)BUILTINS$ + (I$2 << (4ll & 63ll))) + 8ll) = 0ll;
		}
		label$258:;
		I$2 = I$2 + 1ll;
		label$257:;
		if( I$2 <= 17ll) goto label$260;
		label$259:;
	}
	if( *(int64*)((uint8*)&ENV$ + 296ll) == 0ll) goto label$262;
	{
		_EMITDBG( 114ll, (struct $8FBSYMBOL*)0ull, 0ll, (char*)0ull );
	}
	label$262:;
	label$261:;
	int64 vr$19 = FBIS64BIT(  );
	if( vr$19 == 0ll) goto label$264;
	{
		FBSTRING TMP$229$2;
		__builtin_memset( &TMP$229$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$229$2, -1ll, (void*)"%FBSTRING = type { i8*, i64, i64 }", 35ll, 0 );
		HWRITELINE( &TMP$229$2 );
		fb_StrDelete( (FBSTRING*)&TMP$229$2 );
	}
	goto label$263;
	label$264:;
	{
		FBSTRING TMP$231$2;
		__builtin_memset( &TMP$231$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$231$2, -1ll, (void*)"%FBSTRING = type { i8*, i32, i32 }", 35ll, 0 );
		HWRITELINE( &TMP$231$2 );
		fb_StrDelete( (FBSTRING*)&TMP$231$2 );
	}
	label$263:;
	*(int64*)((uint8*)&CTX$ + 272ll) = 1ll;
	fb$result$1 = -1ll;
	label$252:;
	return fb$result$1;
}

static void _EMITEND( void )
{
	FBSTRING TMP$233$1;
	FBSTRING TMP$234$1;
	label$265:;
	*(int64*)((uint8*)&CTX$ + 272ll) = 0ll;
	{
		int64 I$2;
		I$2 = 0ll;
		label$270:;
		{
			if( *(int64*)(((int64)(struct $7BUILTIN*)BUILTINS$ + (I$2 << (4ll & 63ll))) + 8ll) == 0ll) goto label$272;
			{
				FBSTRING TMP$232$4;
				__builtin_memset( &TMP$232$4, 0, 24ll );
				fb_StrAssign( (void*)&TMP$232$4, -1ll, *(void**)((int64)(struct $7BUILTIN*)BUILTINS$ + (I$2 << (4ll & 63ll))), 0ll, 0 );
				HWRITELINE( &TMP$232$4 );
				fb_StrDelete( (FBSTRING*)&TMP$232$4 );
			}
			label$272:;
			label$271:;
		}
		label$268:;
		I$2 = I$2 + 1ll;
		label$267:;
		if( I$2 <= 17ll) goto label$270;
		label$269:;
	}
	__builtin_memset( &TMP$233$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$233$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$233$1 );
	fb_StrDelete( (FBSTRING*)&TMP$233$1 );
	SYMBFOREACHGLOBAL( 3ll, (tmp$43)&HMAYBEEMITPROCPROTO );
	__builtin_memset( &TMP$234$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$234$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$234$1 );
	fb_StrDelete( (FBSTRING*)&TMP$234$1 );
	SYMBFOREACHGLOBAL( 1ll, (tmp$43)&HMAYBEEMITGLOBALVAR );
	IRFOREACHDATASTMT( (tmp$43)&HEMITVARIABLE );
	SYMBFOREACHGLOBAL( 3ll, (tmp$43)&HADDGLOBALCTORDTOR );
	if( *(int64*)((uint8*)&CTX$ + 224ll) <= 0ll) goto label$274;
	{
		FBSTRING TMP$237$2;
		FBSTRING TMP$238$2;
		FBSTRING TMP$239$2;
		FBSTRING TMP$240$2;
		FBSTRING TMP$241$2;
		__builtin_memset( &TMP$241$2, 0, 24ll );
		__builtin_memset( &TMP$238$2, 0, 24ll );
		FBSTRING* vr$19 = fb_StrConcat( &TMP$238$2, (void*)" x { i32, void ()* }] [", 24ll, (void*)((uint8*)&CTX$ + 176ll), -1ll );
		__builtin_memset( &TMP$239$2, 0, 24ll );
		FBSTRING* vr$22 = fb_StrConcat( &TMP$239$2, (void*)vr$19, -1ll, (void*)"]", 2ll );
		FBSTRING* vr$23 = fb_LongintToStr( *(int64*)((uint8*)&CTX$ + 224ll) );
		__builtin_memset( &TMP$237$2, 0, 24ll );
		FBSTRING* vr$26 = fb_StrConcat( &TMP$237$2, (void*)"@llvm.global_ctors = appending global [", 40ll, (void*)vr$23, -1ll );
		__builtin_memset( &TMP$240$2, 0, 24ll );
		FBSTRING* vr$29 = fb_StrConcat( &TMP$240$2, (void*)vr$26, -1ll, (void*)vr$22, -1ll );
		fb_StrAssign( (void*)&TMP$241$2, -1ll, (void*)vr$29, -1ll, 0 );
		HWRITELINE( &TMP$241$2 );
		fb_StrDelete( (FBSTRING*)&TMP$241$2 );
	}
	label$274:;
	label$273:;
	if( *(int64*)((uint8*)&CTX$ + 232ll) <= 0ll) goto label$276;
	{
		FBSTRING TMP$243$2;
		FBSTRING TMP$244$2;
		FBSTRING TMP$245$2;
		FBSTRING TMP$246$2;
		FBSTRING TMP$247$2;
		__builtin_memset( &TMP$247$2, 0, 24ll );
		__builtin_memset( &TMP$244$2, 0, 24ll );
		FBSTRING* vr$37 = fb_StrConcat( &TMP$244$2, (void*)" x { i32, void ()* }] [", 24ll, (void*)((uint8*)&CTX$ + 200ll), -1ll );
		__builtin_memset( &TMP$245$2, 0, 24ll );
		FBSTRING* vr$40 = fb_StrConcat( &TMP$245$2, (void*)vr$37, -1ll, (void*)"]", 2ll );
		FBSTRING* vr$41 = fb_LongintToStr( *(int64*)((uint8*)&CTX$ + 232ll) );
		__builtin_memset( &TMP$243$2, 0, 24ll );
		FBSTRING* vr$44 = fb_StrConcat( &TMP$243$2, (void*)"@llvm.global_dtors = appending global [", 40ll, (void*)vr$41, -1ll );
		__builtin_memset( &TMP$246$2, 0, 24ll );
		FBSTRING* vr$47 = fb_StrConcat( &TMP$246$2, (void*)vr$44, -1ll, (void*)vr$40, -1ll );
		fb_StrAssign( (void*)&TMP$247$2, -1ll, (void*)vr$47, -1ll, 0 );
		HWRITELINE( &TMP$247$2 );
		fb_StrDelete( (FBSTRING*)&TMP$247$2 );
	}
	label$276:;
	label$275:;
	*(int64*)((uint8*)&CTX$ + 272ll) = 2ll;
	int32 vr$53 = fb_FilePutStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0ll, (void*)((uint8*)&CTX$ + 280ll), -1ll );
	if( (int64)vr$53 == 0ll) goto label$278;
	{
	}
	label$278:;
	label$277:;
	int32 vr$57 = fb_FilePutStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0ll, (void*)((uint8*)&CTX$ + 304ll), -1ll );
	if( (int64)vr$57 == 0ll) goto label$280;
	{
	}
	label$280:;
	label$279:;
	int32 vr$61 = fb_FilePutStrLarge( (int32)*(int64*)((uint8*)&ENV$ + 920ll), 0ll, (void*)((uint8*)&CTX$ + 328ll), -1ll );
	if( (int64)vr$61 == 0ll) goto label$282;
	{
	}
	label$282:;
	label$281:;
	int32 vr$64 = fb_FileClose( (int32)*(int64*)((uint8*)&ENV$ + 920ll) );
	if( (int64)vr$64 == 0ll) goto label$284;
	{
	}
	label$284:;
	label$283:;
	*(int64*)((uint8*)&ENV$ + 920ll) = 0ll;
	label$266:;
}

static int64 _GETOPTIONVALUE( $14IR_OPTIONVALUE OPT$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$285:;
	{
		if( OPT$1 != 1ll) goto label$288;
		label$289:;
		{
			fb$result$1 = 0ll;
			goto label$286;
		}
		goto label$287;
		label$288:;
		{
			ERRREPORTEX( 21ll, (char*)"_GETOPTIONVALUE", 0ll, 1ll, (char*)0ull );
		}
		label$290:;
		label$287:;
	}
	label$286:;
	return fb$result$1;
}

static int64 _SUPPORTSOP( int64 OP$1, int64 DTYPE$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$291:;
	{
		uint64 TMP$249$2;
		TMP$249$2 = (uint64)OP$1;
		goto label$294;
		label$295:;
		{
			fb$result$1 = 0ll;
		}
		goto label$293;
		label$296:;
		{
			int64 TMP$250$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$297;
			TMP$250$3 = 24ll;
			goto label$760;
			label$297:;
			TMP$250$3 = DTYPE$1 & 31ll;
			label$760:;
			fb$result$1 = (int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$250$3 * 56ll)) == 1ll);
		}
		goto label$293;
		label$298:;
		{
			fb$result$1 = -1ll;
		}
		goto label$293;
		label$294:;
		static const void* tmp$599[17ll] = {
			&&label$296,
			&&label$295,
			&&label$298,
			&&label$295,
			&&label$298,
			&&label$295,
			&&label$295,
			&&label$295,
			&&label$298,
			&&label$298,
			&&label$295,
			&&label$295,
			&&label$298,
			&&label$298,
			&&label$298,
			&&label$295,
			&&label$295,
		};
		if( (TMP$249$2 - 57ull) > 16ull ) goto label$298;
		goto *tmp$599[TMP$249$2 - 57ull];
		label$293:;
	}
	label$292:;
	return fb$result$1;
}

static void _PROCBEGIN( struct $8FBSYMBOL* PROC$1 )
{
	label$299:;
	*(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 32ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll);
	label$300:;
}

static void _PROCEND( struct $8FBSYMBOL* PROC$1 )
{
	label$301:;
	*(int64*)((uint8*)*(struct $10FB_PROCEXT**)((uint8*)PROC$1 + 208ll) + 40ll) = *(int64*)((uint8*)*(struct $9LEX_TKCTX**)((uint8*)&LEX$ + 844696ll) + 16752ll);
	label$302:;
}

static void _PROCALLOCARG( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING TMP$252$1;
	FBSTRING TMP$253$1;
	FBSTRING TMP$255$1;
	FBSTRING TMP$257$1;
	FBSTRING TMP$258$1;
	FBSTRING TMP$259$1;
	label$303:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	__builtin_memset( &TMP$253$1, 0, 24ll );
	FBSTRING* vr$2 = HSYMNAME( SYM$1 );
	__builtin_memset( &TMP$252$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$252$1, (void*)"paramvar ", 10ll, (void*)vr$2, -1ll );
	fb_StrAssign( (void*)&TMP$253$1, -1ll, (void*)vr$5, -1ll, 0 );
	HASTCOMMAND( &TMP$253$1 );
	fb_StrDelete( (FBSTRING*)&TMP$253$1 );
	int64 DTYPE$1;
	__builtin_memset( &DTYPE$1, 0, 8ll );
	struct $8FBSYMBOL* SUBTYPE$1;
	__builtin_memset( &SUBTYPE$1, 0, 8ll );
	SYMBGETREALTYPE( SYM$1, &DTYPE$1, &SUBTYPE$1 );
	char* vr$13 = SYMBGETMANGLEDNAME( SYM$1 );
	__builtin_memset( &TMP$255$1, 0, 24ll );
	FBSTRING* vr$16 = fb_StrConcat( &TMP$255$1, (void*)vr$13, 0ll, (void*)" = alloca ", 11ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$16, -1ll, 0 );
	FBSTRING* vr$18 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$18, -1ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)"store ", 7ll, 0 );
	FBSTRING* vr$22 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$22, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$25 = HEMITPARAMNAME( SYM$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$25, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
	char* vr$28 = SYMBGETMANGLEDNAME( SYM$1 );
	FBSTRING* vr$38 = HEMITTYPE( (((DTYPE$1 & 31ll) | ((DTYPE$1 & 480ll) + 32ll)) | ((DTYPE$1 & 261632ll) << (1ll & 63ll))) | (DTYPE$1 & 32505856ll), SUBTYPE$1 );
	__builtin_memset( &TMP$257$1, 0, 24ll );
	FBSTRING* vr$41 = fb_StrConcat( &TMP$257$1, (void*)vr$38, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$258$1, 0, 24ll );
	FBSTRING* vr$44 = fb_StrConcat( &TMP$258$1, (void*)vr$41, -1ll, (void*)vr$28, 0ll );
	__builtin_memset( &TMP$259$1, 0, 24ll );
	FBSTRING* vr$48 = fb_StrConcat( &TMP$259$1, (void*)&LN$1, -1ll, (void*)vr$44, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$48, -1ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$304:;
}

static void _PROCALLOCLOCAL( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* SYM$1 )
{
	FBSTRING TMP$261$1;
	FBSTRING TMP$262$1;
	label$305:;
	__builtin_memset( &TMP$262$1, 0, 24ll );
	FBSTRING* vr$1 = HSYMNAME( SYM$1 );
	__builtin_memset( &TMP$261$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$261$1, (void*)"localvar ", 10ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$262$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$262$1 );
	fb_StrDelete( (FBSTRING*)&TMP$262$1 );
	HEMITVARIABLE( SYM$1 );
	label$306:;
}

static void _SCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	label$307:;
	label$308:;
}

static void _SCOPEEND( struct $8FBSYMBOL* S$1 )
{
	label$309:;
	label$310:;
}

static void _PROCALLOCSTATICVARS( struct $8FBSYMBOL* HEAD_SYM$1 )
{
	label$311:;
	label$312:;
}

static void _SETVREGDATATYPE( struct $6IRVREG* V$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	label$313:;
	struct $6IRVREG* TEMP0$1;
	if( ((int64)-(*(int64*)((uint8*)V$1 + 8ll) != DTYPE$1) | (int64)-(*(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) != SUBTYPE$1)) == 0ll) goto label$316;
	{
		struct $6IRVREG* vr$5 = IRHLALLOCVREG( DTYPE$1, SUBTYPE$1 );
		TEMP0$1 = vr$5;
		HEMITCONVERT( TEMP0$1, V$1 );
		__builtin_memcpy( V$1, TEMP0$1, 120 );
	}
	label$316:;
	label$315:;
	label$314:;
}

static void HADDOFFSET( struct $6IRVREG* V$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, int64 OFS$1 )
{
	label$317:;
	struct $6IRVREG* VOFFSET$1;
	struct $6IRVREG* vr$0 = IRHLALLOCVREG( 8ll, (struct $8FBSYMBOL*)0ull );
	VOFFSET$1 = vr$0;
	HEMITCONVERT( VOFFSET$1, V$1 );
	if( OFS$1 == 0ll) goto label$320;
	{
		struct $6IRVREG* VIMMOFFSET$2;
		struct $6IRVREG* vr$1 = IRHLALLOCVRIMM( 8ll, (struct $8FBSYMBOL*)0ull, OFS$1 );
		VIMMOFFSET$2 = vr$1;
		struct $6IRVREG* VNEWOFFSET$2;
		struct $6IRVREG* vr$2 = IRHLALLOCVREG( 8ll, (struct $8FBSYMBOL*)0ull );
		VNEWOFFSET$2 = vr$2;
		HEMITBOP( 28ll, VOFFSET$1, VIMMOFFSET$2, VNEWOFFSET$2, (struct $8FBSYMBOL*)0ull, 0ll );
		VOFFSET$1 = VNEWOFFSET$2;
	}
	label$320:;
	label$319:;
	_SETVREGDATATYPE( VOFFSET$1, DTYPE$1, SUBTYPE$1 );
	__builtin_memcpy( V$1, VOFFSET$1, 120 );
	label$318:;
}

static void HPREPAREADDRESS( struct $6IRVREG* V$1 )
{
	label$321:;
	$11FB_DATATYPE ADDRDTYPE$1;
	ADDRDTYPE$1 = *($11FB_DATATYPE*)((uint8*)V$1 + 8ll);
	struct $8FBSYMBOL* ADDRSUBTYPE$1;
	ADDRSUBTYPE$1 = *(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll);
	int64 OFS$1;
	OFS$1 = *(int64*)((uint8*)V$1 + 64ll);
	struct $6IRVREG* VIDX$1;
	VIDX$1 = *(struct $6IRVREG**)((uint8*)V$1 + 80ll);
	struct $8FBSYMBOL* SYM$1;
	SYM$1 = *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll);
	if( *(int64*)V$1 != 5ll) goto label$324;
	{
	}
	goto label$323;
	label$324:;
	{
		ADDRDTYPE$1 = (((ADDRDTYPE$1 & 31ll) | ((ADDRDTYPE$1 & 480ll) + 32ll)) | ((ADDRDTYPE$1 & 261632ll) << (1ll & 63ll))) | (ADDRDTYPE$1 & 32505856ll);
	}
	label$323:;
	if( *(int64*)V$1 != 3ll) goto label$326;
	{
		__builtin_memcpy( V$1, VIDX$1, 120 );
	}
	goto label$325;
	label$326:;
	{
		*($15IRVREGTYPE_ENUM*)V$1 = 4ll;
		*(int64*)((uint8*)V$1 + 24ll) = -1ll;
		*(int64*)((uint8*)V$1 + 64ll) = 0ll;
		*(struct $6IRVREG**)((uint8*)V$1 + 80ll) = (struct $6IRVREG*)0ull;
		if( SYM$1 == (struct $8FBSYMBOL*)0ull) goto label$328;
		{
			SYMBGETREALTYPE( SYM$1, (int64*)((uint8*)V$1 + 8ll), (struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) );
			*($11FB_DATATYPE*)((uint8*)V$1 + 8ll) = (((*(int64*)((uint8*)V$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)V$1 + 8ll) & 480ll) + 32ll)) | ((*(int64*)((uint8*)V$1 + 8ll) & 261632ll) << (1ll & 63ll))) | (*(int64*)((uint8*)V$1 + 8ll) & 32505856ll);
			_SETVREGDATATYPE( V$1, ADDRDTYPE$1, ADDRSUBTYPE$1 );
		}
		goto label$327;
		label$328:;
		{
			*($11FB_DATATYPE*)((uint8*)V$1 + 8ll) = ADDRDTYPE$1;
			*(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) = ADDRSUBTYPE$1;
		}
		label$327:;
	}
	label$325:;
	if( ((int64)-(VIDX$1 != (struct $6IRVREG*)0ull) | (int64)-(OFS$1 != 0ll)) == 0ll) goto label$330;
	{
		HADDOFFSET( V$1, ADDRDTYPE$1, ADDRSUBTYPE$1, OFS$1 );
	}
	label$330:;
	label$329:;
	label$322:;
}

static void HLOADVREG( struct $6IRVREG* V$1 )
{
	label$331:;
	{
		$15IRVREGTYPE_ENUM TMP$263$2;
		TMP$263$2 = *($15IRVREGTYPE_ENUM*)V$1;
		if( TMP$263$2 == 4ll) goto label$335;
		label$336:;
		if( TMP$263$2 != 0ll) goto label$334;
		label$335:;
		{
		}
		goto label$333;
		label$334:;
		if( TMP$263$2 != 5ll) goto label$337;
		label$338:;
		{
			HPREPAREADDRESS( V$1 );
		}
		goto label$333;
		label$337:;
		{
			FBSTRING TMP$265$3;
			FBSTRING TMP$266$3;
			FBSTRING TMP$267$3;
			FBSTRING TMP$268$3;
			FBSTRING TMP$269$3;
			HPREPAREADDRESS( V$1 );
			struct $6IRVREG* TEMP0$3;
			struct $6IRVREG* vr$16 = IRHLALLOCVREG( (((*(int64*)((uint8*)V$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)V$1 + 8ll) & 480ll) + -32ll)) | (((*(int64*)((uint8*)V$1 + 8ll) & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (*(int64*)((uint8*)V$1 + 8ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) );
			TEMP0$3 = vr$16;
			FBSTRING S$3;
			FBSTRING* vr$17 = HVREGTOSTR( TEMP0$3 );
			__builtin_memset( &TMP$265$3, 0, 24ll );
			FBSTRING* vr$20 = fb_StrConcat( &TMP$265$3, (void*)vr$17, -1ll, (void*)" = load ", 9ll );
			fb_StrInit( (void*)&S$3, -1ll, (void*)vr$20, -1ll, 0 );
			FBSTRING* vr$37 = HEMITTYPE( (((*(int64*)((uint8*)V$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)V$1 + 8ll) & 480ll) + -32ll)) | (((*(int64*)((uint8*)V$1 + 8ll) & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (*(int64*)((uint8*)V$1 + 8ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) );
			__builtin_memset( &TMP$266$3, 0, 24ll );
			FBSTRING* vr$40 = fb_StrConcat( &TMP$266$3, (void*)vr$37, -1ll, (void*)", ", 3ll );
			__builtin_memset( &TMP$267$3, 0, 24ll );
			FBSTRING* vr$44 = fb_StrConcat( &TMP$267$3, (void*)&S$3, -1ll, (void*)vr$40, -1ll );
			fb_StrAssign( (void*)&S$3, -1ll, (void*)vr$44, -1ll, 0 );
			FBSTRING* vr$48 = HEMITTYPE( *(int64*)((uint8*)V$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll) );
			__builtin_memset( &TMP$268$3, 0, 24ll );
			FBSTRING* vr$51 = fb_StrConcat( &TMP$268$3, (void*)vr$48, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$269$3, 0, 24ll );
			FBSTRING* vr$55 = fb_StrConcat( &TMP$269$3, (void*)&S$3, -1ll, (void*)vr$51, -1ll );
			fb_StrAssign( (void*)&S$3, -1ll, (void*)vr$55, -1ll, 0 );
			FBSTRING* vr$57 = HVREGTOSTR( V$1 );
			fb_StrConcatAssign( (void*)&S$3, -1ll, (void*)vr$57, -1ll, 0 );
			HWRITELINE( &S$3 );
			__builtin_memcpy( V$1, TEMP0$3, 120 );
			fb_StrDelete( (FBSTRING*)&S$3 );
		}
		label$339:;
		label$333:;
	}
	label$332:;
}

static FBSTRING* HEMITTYPE( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$340:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	int64 PTRCOUNT$1;
	PTRCOUNT$1 = (DTYPE$1 & 480ll) >> (5ll & 63ll);
	DTYPE$1 = DTYPE$1 & 31ll;
	{
		uint64 TMP$270$2;
		TMP$270$2 = (uint64)DTYPE$1;
		goto label$343;
		label$344:;
		{
			if( PTRCOUNT$1 != 0ll) goto label$346;
			{
				fb_StrAssign( (void*)&S$1, -1ll, (void*)"void", 5ll, 0 );
			}
			goto label$345;
			label$346:;
			{
				fb_StrAssign( (void*)&S$1, -1ll, *(void**)DTYPENAME$, 0ll, 0 );
			}
			label$345:;
		}
		goto label$342;
		label$347:;
		{
			if( SUBTYPE$1 == (struct $8FBSYMBOL*)0ull) goto label$349;
			{
				HEMITUDT( SUBTYPE$1 );
				FBSTRING* vr$7 = HGETUDTNAME( SUBTYPE$1 );
				fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$7, -1ll, 0 );
			}
			goto label$348;
			label$349:;
			if( DTYPE$1 != 10ll) goto label$350;
			{
				int64 TMP$272$4;
				if( (DTYPE$1 & 480ll) == 0ll) goto label$351;
				TMP$272$4 = 24ll;
				goto label$761;
				label$351:;
				TMP$272$4 = DTYPE$1 & 31ll;
				label$761:;
				fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$272$4 * 56ll)) + 32ll) << (3ll & 63ll))), 0ll, 0 );
			}
			goto label$348;
			label$350:;
			{
				fb_StrAssign( (void*)&S$1, -1ll, *(void**)DTYPENAME$, 0ll, 0 );
			}
			label$348:;
		}
		goto label$342;
		label$352:;
		{
			PTRCOUNT$1 = PTRCOUNT$1 + -1ll;
			FBSTRING* vr$16 = HEMITPROCHEADER( SUBTYPE$1, -1ll, -1ll );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$16, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"*", 2ll, 0 );
		}
		goto label$342;
		label$353:;
		{
			int64 TMP$273$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$354;
			TMP$273$3 = 24ll;
			goto label$762;
			label$354:;
			TMP$273$3 = DTYPE$1 & 31ll;
			label$762:;
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (*(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$273$3 * 56ll)) + 32ll) << (3ll & 63ll))), 0ll, 0 );
		}
		goto label$342;
		label$355:;
		{
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + 24ll), 0ll, 0 );
		}
		goto label$342;
		label$356:;
		{
			fb_StrAssign( (void*)&S$1, -1ll, *(void**)((int64)(char**)DTYPENAME$ + (DTYPE$1 << (3ll & 63ll))), 0ll, 0 );
		}
		goto label$342;
		label$343:;
		static const void* tmp$600[23ll] = {
			&&label$344,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$353,
			&&label$356,
			&&label$356,
			&&label$353,
			&&label$356,
			&&label$356,
			&&label$347,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$356,
			&&label$355,
			&&label$356,
			&&label$347,
			&&label$356,
			&&label$352,
		};
		if( TMP$270$2 > 22ull ) goto label$356;
		goto *tmp$600[TMP$270$2 - 0ull];
		label$342:;
	}
	if( PTRCOUNT$1 <= 0ll) goto label$358;
	{
		FBSTRING* vr$27 = fb_StrAllocTempDescZEx( (char*)"*", 1ll );
		FBSTRING* vr$28 = fb_StrFill2( PTRCOUNT$1, (FBSTRING*)vr$27 );
		fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$28, -1ll, 0 );
	}
	label$358:;
	label$357:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$341:;
	FBSTRING* vr$34 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$34;
}

static FBSTRING* HEMITINT( int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, int64 VALUE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$359:;
	FBSTRING S$1;
	__builtin_memset( &S$1, 0, 24ll );
	{
		if( DTYPE$1 == 8ll) goto label$363;
		label$364:;
		if( DTYPE$1 == 9ll) goto label$363;
		label$365:;
		if( DTYPE$1 == 11ll) goto label$363;
		label$366:;
		if( DTYPE$1 == 12ll) goto label$363;
		label$367:;
		if( DTYPE$1 != 10ll) goto label$362;
		label$363:;
		{
			FBSTRING* vr$2 = fb_LongintToStr( VALUE$1 );
			fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$2, -1ll, 0 );
		}
		goto label$361;
		label$362:;
		{
			if( (DTYPE$1 & 480ll) == 0ll) goto label$370;
			{
				fb_StrAssign( (void*)&S$1, -1ll, (void*)"inttoptr ", 10ll, 0 );
			}
			goto label$369;
			label$370:;
			{
				fb_StrAssign( (void*)&S$1, -1ll, (void*)"trunc ", 7ll, 0 );
			}
			label$369:;
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)"(", 2ll, 0 );
			FBSTRING* vr$8 = HEMITTYPE( 8ll, (struct $8FBSYMBOL*)0ull );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$8, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)" ", 2ll, 0 );
			FBSTRING* vr$11 = fb_LongintToStr( VALUE$1 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$11, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)" to ", 5ll, 0 );
			FBSTRING* vr$14 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)vr$14, -1ll, 0 );
			fb_StrConcatAssign( (void*)&S$1, -1ll, (void*)")", 2ll, 0 );
		}
		label$368:;
		label$361:;
	}
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)&S$1, -1ll, 0 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$360:;
	FBSTRING* vr$21 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$21;
}

static FBSTRING* HEMITLONG( int64 VALUE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$371:;
	FBSTRING* vr$1 = fb_LongintToStr( VALUE$1 );
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)vr$1, -1ll, 0 );
	label$372:;
	FBSTRING* vr$4 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$4;
}

static FBSTRING* HEMITFLOAT( double VALUE$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$373:;
	fb_StrAssign( (void*)&fb$result$1, -1ll, (void*)"0x", 3ll, 0 );
	FBSTRING* vr$2 = fb_HEXEx_l( *(uint64*)&VALUE$1, 16 );
	fb_StrConcatAssign( (void*)&fb$result$1, -1ll, (void*)vr$2, -1ll, 0 );
	label$374:;
	FBSTRING* vr$5 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$5;
}

static int64 HISFIXLENSTR( struct $8FBSYMBOL* SYM$1 )
{
	int64 fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$375:;
	if( *(int64*)SYM$1 != 1ll) goto label$378;
	{
		{
			int64 TMP$280$3;
			TMP$280$3 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
			if( TMP$280$3 == 18ll) goto label$381;
			label$382:;
			if( TMP$280$3 == 4ll) goto label$381;
			label$383:;
			if( TMP$280$3 != 7ll) goto label$380;
			label$381:;
			{
				fb$result$1 = -1ll;
				goto label$376;
			}
			label$380:;
			label$379:;
		}
	}
	label$378:;
	label$377:;
	fb$result$1 = 0ll;
	goto label$376;
	label$376:;
	return fb$result$1;
}

static FBSTRING* HVREGTOSTR( struct $6IRVREG* V$1 )
{
	FBSTRING fb$result$1;
	__builtin_memset( &fb$result$1, 0, 24ll );
	label$384:;
	{
		uint64 TMP$281$2;
		TMP$281$2 = *(uint64*)V$1;
		goto label$387;
		label$388:;
		{
			int64 TMP$282$3;
			int64 TMP$283$3;
			if( (*(int64*)((uint8*)V$1 + 8ll) & 480ll) == 0ll) goto label$389;
			TMP$282$3 = 24ll;
			goto label$763;
			label$389:;
			TMP$282$3 = *(int64*)((uint8*)V$1 + 8ll) & 31ll;
			label$763:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$282$3 * 56ll)) != 1ll) goto label$391;
			{
				FBSTRING* vr$8 = HEMITFLOAT( *(double*)((uint8*)V$1 + 48ll) );
				fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$8, -1ll, 0 );
				goto label$385;
			}
			label$391:;
			label$390:;
			if( (*(int64*)((uint8*)V$1 + 8ll) & 480ll) == 0ll) goto label$392;
			TMP$283$3 = 24ll;
			goto label$764;
			label$392:;
			TMP$283$3 = *(int64*)((uint8*)V$1 + 8ll) & 31ll;
			label$764:;
			if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$283$3 * 56ll)) + 8ll) != 8ll) goto label$394;
			{
				FBSTRING* vr$16 = HEMITLONG( *(int64*)((uint8*)V$1 + 48ll) );
				fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$16, -1ll, 0 );
				goto label$385;
			}
			label$394:;
			label$393:;
			FBSTRING* vr$21 = HEMITINT( *(int64*)((uint8*)V$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V$1 + 16ll), *(int64*)((uint8*)V$1 + 48ll) );
			fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$21, -1ll, 0 );
			goto label$385;
		}
		goto label$386;
		label$395:;
		{
			if( *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll) != (struct $8FBSYMBOL*)0ull) goto label$397;
			{
				FBSTRING TMP$285$4;
				FBSTRING* vr$25 = fb_LongintToStr( *(int64*)((uint8*)V$1 + 24ll) );
				__builtin_memset( &TMP$285$4, 0, 24ll );
				FBSTRING* vr$28 = fb_StrConcat( &TMP$285$4, (void*)"%vr", 4ll, (void*)vr$25, -1ll );
				fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$28, -1ll, 0 );
				goto label$385;
			}
			label$397:;
			label$396:;
		}
		goto label$386;
		label$387:;
		static const void* tmp$601[5ll] = {
			&&label$388,
			&&label$386,
			&&label$386,
			&&label$386,
			&&label$395,
		};
		if( TMP$281$2 > 4ull ) goto label$386;
		goto *tmp$601[TMP$281$2 - 0ull];
		label$386:;
	}
	struct $8FBSYMBOL* SYM$1;
	SYM$1 = *(struct $8FBSYMBOL**)((uint8*)V$1 + 56ll);
	int64 vr$31 = HISFIXLENSTR( SYM$1 );
	if( vr$31 == 0ll) goto label$399;
	{
		FBSTRING TMP$288$2;
		FBSTRING TMP$289$2;
		FBSTRING S$2;
		fb_StrInit( (void*)&S$2, -1ll, (void*)"bitcast (", 10ll, 0 );
		FBSTRING* vr$33 = HEMITSYMTYPE( SYM$1 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)vr$33, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)"* ", 3ll, 0 );
		char* vr$36 = SYMBGETMANGLEDNAME( SYM$1 );
		__builtin_memset( &TMP$288$2, 0, 24ll );
		FBSTRING* vr$40 = fb_StrConcat( &TMP$288$2, (void*)&S$2, -1ll, (void*)vr$36, 0ll );
		fb_StrAssign( (void*)&S$2, -1ll, (void*)vr$40, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)" to ", 5ll, 0 );
		FBSTRING* vr$60 = HEMITTYPE( ((((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)SYM$1 + 56ll) & 511ll) & 32505856ll), (struct $8FBSYMBOL*)0ull );
		__builtin_memset( &TMP$289$2, 0, 24ll );
		FBSTRING* vr$64 = fb_StrConcat( &TMP$289$2, (void*)&S$2, -1ll, (void*)vr$60, -1ll );
		fb_StrAssign( (void*)&S$2, -1ll, (void*)vr$64, -1ll, 0 );
		fb_StrConcatAssign( (void*)&S$2, -1ll, (void*)")", 2ll, 0 );
		fb_StrInit( (void*)&fb$result$1, -1ll, (void*)&S$2, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&S$2 );
		goto label$385;
		fb_StrDelete( (FBSTRING*)&S$2 );
	}
	label$399:;
	label$398:;
	char* vr$71 = SYMBGETMANGLEDNAME( SYM$1 );
	fb_StrInit( (void*)&fb$result$1, -1ll, (void*)vr$71, 0ll, 0 );
	goto label$385;
	label$385:;
	FBSTRING* vr$74 = fb_StrAllocTempResult( (FBSTRING*)&fb$result$1 );
	return vr$74;
}

static void _EMITLABEL( struct $8FBSYMBOL* LABEL$1 )
{
	FBSTRING TMP$291$1;
	FBSTRING TMP$292$1;
	FBSTRING TMP$294$1;
	FBSTRING TMP$295$1;
	label$400:;
	__builtin_memset( &TMP$292$1, 0, 24ll );
	FBSTRING* vr$1 = HSYMNAME( LABEL$1 );
	__builtin_memset( &TMP$291$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$291$1, (void*)"label ", 7ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$292$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$292$1 );
	fb_StrDelete( (FBSTRING*)&TMP$292$1 );
	__builtin_memset( &TMP$295$1, 0, 24ll );
	char* vr$9 = SYMBGETMANGLEDNAME( LABEL$1 );
	__builtin_memset( &TMP$294$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$294$1, (void*)"br label %", 11ll, (void*)vr$9, 0ll );
	fb_StrAssign( (void*)&TMP$295$1, -1ll, (void*)vr$12, -1ll, 0 );
	HWRITELINE( &TMP$295$1 );
	fb_StrDelete( (FBSTRING*)&TMP$295$1 );
	char* vr$16 = SYMBGETMANGLEDNAME( LABEL$1 );
	HWRITELABEL( vr$16 );
	label$401:;
}

static char* HGETBOPCODE( int64 OP$1, int64 DTYPE$1 )
{
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$402:;
	{
		uint64 TMP$296$2;
		TMP$296$2 = (uint64)OP$1;
		goto label$405;
		label$406:;
		{
			int64 TMP$297$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$407;
			TMP$297$3 = 24ll;
			goto label$765;
			label$407:;
			TMP$297$3 = DTYPE$1 & 31ll;
			label$765:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$297$3 * 56ll)) != 1ll) goto label$409;
			{
				fb$result$1 = (char*)"fadd";
			}
			goto label$408;
			label$409:;
			{
				fb$result$1 = (char*)"add";
			}
			label$408:;
		}
		goto label$404;
		label$410:;
		{
			int64 TMP$300$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$411;
			TMP$300$3 = 24ll;
			goto label$766;
			label$411:;
			TMP$300$3 = DTYPE$1 & 31ll;
			label$766:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$300$3 * 56ll)) != 1ll) goto label$413;
			{
				fb$result$1 = (char*)"fsub";
			}
			goto label$412;
			label$413:;
			{
				fb$result$1 = (char*)"sub";
			}
			label$412:;
		}
		goto label$404;
		label$414:;
		{
			int64 TMP$303$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$415;
			TMP$303$3 = 24ll;
			goto label$767;
			label$415:;
			TMP$303$3 = DTYPE$1 & 31ll;
			label$767:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$303$3 * 56ll)) != 1ll) goto label$417;
			{
				fb$result$1 = (char*)"fmul";
			}
			goto label$416;
			label$417:;
			{
				fb$result$1 = (char*)"mul";
			}
			label$416:;
		}
		goto label$404;
		label$418:;
		{
			fb$result$1 = (char*)"fdiv";
		}
		goto label$404;
		label$419:;
		{
			fb$result$1 = (char*)"sdiv";
		}
		goto label$404;
		label$420:;
		{
			int64 TMP$308$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$421;
			TMP$308$3 = 24ll;
			goto label$768;
			label$421:;
			TMP$308$3 = DTYPE$1 & 31ll;
			label$768:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$308$3 * 56ll)) != 1ll) goto label$423;
			{
				fb$result$1 = (char*)"frem";
			}
			goto label$422;
			label$423:;
			{
				fb$result$1 = (char*)"srem";
			}
			label$422:;
		}
		goto label$404;
		label$424:;
		{
			fb$result$1 = (char*)"shl";
		}
		goto label$404;
		label$425:;
		{
			fb$result$1 = (char*)"ashr";
		}
		goto label$404;
		label$426:;
		{
			fb$result$1 = (char*)"and";
		}
		goto label$404;
		label$427:;
		{
			fb$result$1 = (char*)"or";
		}
		goto label$404;
		label$428:;
		{
			fb$result$1 = (char*)"xor";
		}
		goto label$404;
		label$429:;
		{
			int64 TMP$316$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$430;
			TMP$316$3 = 24ll;
			goto label$769;
			label$430:;
			TMP$316$3 = DTYPE$1 & 31ll;
			label$769:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$316$3 * 56ll)) != 1ll) goto label$432;
			{
				fb$result$1 = (char*)"fcmp oeq";
			}
			goto label$431;
			label$432:;
			{
				fb$result$1 = (char*)"icmp eq";
			}
			label$431:;
		}
		goto label$404;
		label$433:;
		{
			int64 TMP$319$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$434;
			TMP$319$3 = 24ll;
			goto label$770;
			label$434:;
			TMP$319$3 = DTYPE$1 & 31ll;
			label$770:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$319$3 * 56ll)) != 1ll) goto label$436;
			{
				fb$result$1 = (char*)"fcmp one";
			}
			goto label$435;
			label$436:;
			{
				fb$result$1 = (char*)"icmp ne";
			}
			label$435:;
		}
		goto label$404;
		label$437:;
		{
			int64 TMP$322$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$438;
			TMP$322$3 = 24ll;
			goto label$771;
			label$438:;
			TMP$322$3 = DTYPE$1 & 31ll;
			label$771:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$322$3 * 56ll)) != 1ll) goto label$440;
			{
				fb$result$1 = (char*)"fcmp ogt";
			}
			goto label$439;
			label$440:;
			{
				fb$result$1 = (char*)"icmp sgt";
			}
			label$439:;
		}
		goto label$404;
		label$441:;
		{
			int64 TMP$325$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$442;
			TMP$325$3 = 24ll;
			goto label$772;
			label$442:;
			TMP$325$3 = DTYPE$1 & 31ll;
			label$772:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$325$3 * 56ll)) != 1ll) goto label$444;
			{
				fb$result$1 = (char*)"fcmp olt";
			}
			goto label$443;
			label$444:;
			{
				fb$result$1 = (char*)"icmp slt";
			}
			label$443:;
		}
		goto label$404;
		label$445:;
		{
			int64 TMP$328$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$446;
			TMP$328$3 = 24ll;
			goto label$773;
			label$446:;
			TMP$328$3 = DTYPE$1 & 31ll;
			label$773:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$328$3 * 56ll)) != 1ll) goto label$448;
			{
				fb$result$1 = (char*)"fcmp oge";
			}
			goto label$447;
			label$448:;
			{
				fb$result$1 = (char*)"icmp sge";
			}
			label$447:;
		}
		goto label$404;
		label$449:;
		{
			int64 TMP$331$3;
			if( (DTYPE$1 & 480ll) == 0ll) goto label$450;
			TMP$331$3 = 24ll;
			goto label$774;
			label$450:;
			TMP$331$3 = DTYPE$1 & 31ll;
			label$774:;
			if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$331$3 * 56ll)) != 1ll) goto label$452;
			{
				fb$result$1 = (char*)"fcmp ole";
			}
			goto label$451;
			label$452:;
			{
				fb$result$1 = (char*)"icmp sle";
			}
			label$451:;
		}
		goto label$404;
		label$453:;
		{
			fb$result$1 = (char*)"eqv";
		}
		goto label$404;
		label$454:;
		{
			fb$result$1 = (char*)"imp";
		}
		goto label$404;
		label$405:;
		static const void* tmp$602[23ll] = {
			&&label$406,
			&&label$410,
			&&label$414,
			&&label$418,
			&&label$419,
			&&label$420,
			&&label$426,
			&&label$427,
			&&label$404,
			&&label$404,
			&&label$428,
			&&label$453,
			&&label$454,
			&&label$424,
			&&label$425,
			&&label$404,
			&&label$404,
			&&label$429,
			&&label$437,
			&&label$441,
			&&label$433,
			&&label$445,
			&&label$449,
		};
		if( (TMP$296$2 - 28ull) > 22ull ) goto label$404;
		goto *tmp$602[TMP$296$2 - 28ull];
		label$404:;
	}
	label$403:;
	return fb$result$1;
}

static void HLOADOPERANDSANDWRITEBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, int64 DTYPE$1, struct $8FBSYMBOL* SUBTYPE$1, $10IR_EMITOPT OPTIONS$1 )
{
	FBSTRING TMP$336$1;
	label$455:;
	HLOADVREG( V1$1 );
	HLOADVREG( V2$1 );
	_SETVREGDATATYPE( V1$1, DTYPE$1, SUBTYPE$1 );
	_SETVREGDATATYPE( V2$1, DTYPE$1, SUBTYPE$1 );
	if( (OPTIONS$1 & 1ll) == 0ll) goto label$458;
	{
		int64 vr$1 = ASTGETINVERSELOGOP( OP$1 );
		OP$1 = vr$1;
	}
	label$458:;
	label$457:;
	FBSTRING LN$1;
	FBSTRING* vr$2 = HVREGTOSTR( VR$1 );
	fb_StrInit( (void*)&LN$1, -1ll, (void*)vr$2, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = ", 4ll, 0 );
	char* vr$5 = HGETBOPCODE( OP$1, DTYPE$1 );
	__builtin_memset( &TMP$336$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$336$1, (void*)&LN$1, -1ll, (void*)vr$5, 0ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$9, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$12 = HEMITTYPE( DTYPE$1, SUBTYPE$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$12, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$15 = HVREGTOSTR( V1$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$15, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
	FBSTRING* vr$18 = HVREGTOSTR( V2$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$18, -1ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$456:;
}

static void HEMITBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* LABEL$1, $10IR_EMITOPT OPTIONS$1 )
{
	label$459:;
	if( LABEL$1 == (struct $8FBSYMBOL*)0ull) goto label$462;
	{
		FBSTRING TMP$338$2;
		FBSTRING TMP$340$2;
		FBSTRING TMP$341$2;
		struct $6IRVREG* vr$0 = IRHLALLOCVREG( 8ll, (struct $8FBSYMBOL*)0ull );
		VR$1 = vr$0;
		HLOADOPERANDSANDWRITEBOP( OP$1, V1$1, V2$1, VR$1, *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll), OPTIONS$1 );
		FBSTRING FALSELABEL$2;
		char* vr$3 = SYMBUNIQUELABEL(  );
		fb_StrInit( (void*)&FALSELABEL$2, -1ll, (void*)vr$3, 0ll, 0 );
		FBSTRING LN$2;
		FBSTRING* vr$5 = HVREGTOSTR( VR$1 );
		__builtin_memset( &TMP$338$2, 0, 24ll );
		FBSTRING* vr$8 = fb_StrConcat( &TMP$338$2, (void*)"br i1 ", 7ll, (void*)vr$5, -1ll );
		fb_StrInit( (void*)&LN$2, -1ll, (void*)vr$8, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)", ", 3ll, 0 );
		char* vr$11 = SYMBGETMANGLEDNAME( LABEL$1 );
		__builtin_memset( &TMP$340$2, 0, 24ll );
		FBSTRING* vr$14 = fb_StrConcat( &TMP$340$2, (void*)"label %", 8ll, (void*)vr$11, 0ll );
		__builtin_memset( &TMP$341$2, 0, 24ll );
		FBSTRING* vr$18 = fb_StrConcat( &TMP$341$2, (void*)&LN$2, -1ll, (void*)vr$14, -1ll );
		fb_StrAssign( (void*)&LN$2, -1ll, (void*)vr$18, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)", ", 3ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)"label %", 8ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)&FALSELABEL$2, -1ll, 0 );
		HWRITELINE( &LN$2 );
		HWRITELABEL( (char*)*(char**)&FALSELABEL$2 );
		fb_StrDelete( (FBSTRING*)&LN$2 );
		fb_StrDelete( (FBSTRING*)&FALSELABEL$2 );
		goto label$460;
		fb_StrDelete( (FBSTRING*)&LN$2 );
		fb_StrDelete( (FBSTRING*)&FALSELABEL$2 );
	}
	label$462:;
	label$461:;
	int64 ISSELF$1;
	ISSELF$1 = 0ll;
	struct $6IRVREG V1ORIG$1;
	__builtin_memset( &V1ORIG$1, 0, 120ll );
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$464;
	{
		ISSELF$1 = -1ll;
		struct $6IRVREG* vr$32 = IRHLALLOCVREG( *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll) );
		VR$1 = vr$32;
		__builtin_memcpy( &V1ORIG$1, V1$1, 120 );
	}
	label$464:;
	label$463:;
	HLOADOPERANDSANDWRITEBOP( OP$1, V1$1, V2$1, VR$1, *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll), OPTIONS$1 );
	if( (*(int64*)(((int64)(struct $10AST_OPINFO*)AST_OPTB$ + (OP$1 << (5ll & 63ll))) + 8ll) & 8ll) == 0ll) goto label$466;
	{
		FBSTRING TMP$344$2;
		struct $6IRVREG* VTEMP$2;
		struct $6IRVREG* vr$40 = IRHLALLOCVREG( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
		VTEMP$2 = vr$40;
		FBSTRING LN$2;
		FBSTRING* vr$41 = HVREGTOSTR( VTEMP$2 );
		fb_StrInit( (void*)&LN$2, -1ll, (void*)vr$41, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)" = sext ", 9ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)"i1 ", 4ll, 0 );
		FBSTRING* vr$45 = HVREGTOSTR( VR$1 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)vr$45, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)" to ", 5ll, 0 );
		FBSTRING* vr$50 = HEMITTYPE( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
		__builtin_memset( &TMP$344$2, 0, 24ll );
		FBSTRING* vr$54 = fb_StrConcat( &TMP$344$2, (void*)&LN$2, -1ll, (void*)vr$50, -1ll );
		fb_StrAssign( (void*)&LN$2, -1ll, (void*)vr$54, -1ll, 0 );
		HWRITELINE( &LN$2 );
		__builtin_memcpy( VR$1, VTEMP$2, 120 );
		fb_StrDelete( (FBSTRING*)&LN$2 );
	}
	label$466:;
	label$465:;
	if( ISSELF$1 == 0ll) goto label$468;
	{
		HEMITSTORE( &V1ORIG$1, VR$1 );
	}
	label$468:;
	label$467:;
	label$460:;
}

static void _EMITBOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1, struct $8FBSYMBOL* LABEL$1, $10IR_EMITOPT OPTIONS$1 )
{
	FBSTRING TMP$345$1;
	FBSTRING TMP$346$1;
	FBSTRING TMP$347$1;
	FBSTRING TMP$348$1;
	label$469:;
	FBSTRING BOPDUMP$1;
	FBSTRING* vr$0 = VREGPRETTY( V2$1 );
	FBSTRING* vr$1 = ASTDUMPOPTOSTR( OP$1 );
	FBSTRING* vr$2 = VREGPRETTY( V1$1 );
	__builtin_memset( &TMP$345$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$345$1, (void*)vr$2, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$346$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$346$1, (void*)vr$5, -1ll, (void*)vr$1, -1ll );
	__builtin_memset( &TMP$347$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$347$1, (void*)vr$8, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$348$1, 0, 24ll );
	FBSTRING* vr$14 = fb_StrConcat( &TMP$348$1, (void*)vr$11, -1ll, (void*)vr$0, -1ll );
	fb_StrInit( (void*)&BOPDUMP$1, -1ll, (void*)vr$14, -1ll, 0 );
	if( LABEL$1 == (struct $8FBSYMBOL*)0ull) goto label$472;
	{
		FBSTRING TMP$350$2;
		FBSTRING TMP$351$2;
		__builtin_memset( &TMP$351$2, 0, 24ll );
		__builtin_memset( &TMP$350$2, 0, 24ll );
		FBSTRING* vr$20 = fb_StrConcat( &TMP$350$2, (void*)"branchbop ", 11ll, (void*)&BOPDUMP$1, -1ll );
		fb_StrAssign( (void*)&TMP$351$2, -1ll, (void*)vr$20, -1ll, 0 );
		HASTCOMMAND( &TMP$351$2 );
		fb_StrDelete( (FBSTRING*)&TMP$351$2 );
	}
	goto label$471;
	label$472:;
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$473;
	{
		FBSTRING TMP$353$2;
		FBSTRING TMP$354$2;
		__builtin_memset( &TMP$354$2, 0, 24ll );
		__builtin_memset( &TMP$353$2, 0, 24ll );
		FBSTRING* vr$28 = fb_StrConcat( &TMP$353$2, (void*)"selfbop ", 9ll, (void*)&BOPDUMP$1, -1ll );
		fb_StrAssign( (void*)&TMP$354$2, -1ll, (void*)vr$28, -1ll, 0 );
		HASTCOMMAND( &TMP$354$2 );
		fb_StrDelete( (FBSTRING*)&TMP$354$2 );
	}
	goto label$471;
	label$473:;
	{
		FBSTRING TMP$356$2;
		FBSTRING TMP$357$2;
		__builtin_memset( &TMP$357$2, 0, 24ll );
		__builtin_memset( &TMP$356$2, 0, 24ll );
		FBSTRING* vr$36 = fb_StrConcat( &TMP$356$2, (void*)"bop ", 5ll, (void*)&BOPDUMP$1, -1ll );
		fb_StrAssign( (void*)&TMP$357$2, -1ll, (void*)vr$36, -1ll, 0 );
		HASTCOMMAND( &TMP$357$2 );
		fb_StrDelete( (FBSTRING*)&TMP$357$2 );
	}
	label$471:;
	HEMITBOP( OP$1, V1$1, V2$1, VR$1, LABEL$1, OPTIONS$1 );
	fb_StrDelete( (FBSTRING*)&BOPDUMP$1 );
	label$470:;
}

static void HBUILTINUOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$474:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	HLOADVREG( V1$1 );
	FBSTRING* vr$1 = HVREGTOSTR( VR$1 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$1, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = call ", 9ll, 0 );
	if( *(int64*)((uint8*)V1$1 + 8ll) != 15ll) goto label$477;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"float @llvm.", 13ll, 0 );
		{
			if( OP$1 != 57ll) goto label$479;
			label$480:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 232ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"fabs", 5ll, 0 );
			}
			goto label$478;
			label$479:;
			if( OP$1 != 59ll) goto label$481;
			label$482:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 40ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"sin", 4ll, 0 );
			}
			goto label$478;
			label$481:;
			if( OP$1 != 61ll) goto label$483;
			label$484:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 72ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"cos", 4ll, 0 );
			}
			goto label$478;
			label$483:;
			if( OP$1 != 70ll) goto label$485;
			label$486:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 104ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"exp", 4ll, 0 );
			}
			goto label$478;
			label$485:;
			if( OP$1 != 69ll) goto label$487;
			label$488:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 136ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"log", 4ll, 0 );
			}
			goto label$478;
			label$487:;
			if( OP$1 != 66ll) goto label$489;
			label$490:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 168ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"sqrt", 5ll, 0 );
			}
			goto label$478;
			label$489:;
			if( OP$1 != 71ll) goto label$491;
			label$492:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 200ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"floor", 6ll, 0 );
			}
			goto label$478;
			label$491:;
			{
			}
			label$493:;
			label$478:;
		}
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)".f32(float ", 12ll, 0 );
	}
	goto label$476;
	label$477:;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"double @llvm.", 14ll, 0 );
		{
			if( OP$1 != 57ll) goto label$495;
			label$496:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 248ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"fabs", 5ll, 0 );
			}
			goto label$494;
			label$495:;
			if( OP$1 != 59ll) goto label$497;
			label$498:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 56ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"sin", 4ll, 0 );
			}
			goto label$494;
			label$497:;
			if( OP$1 != 61ll) goto label$499;
			label$500:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 88ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"cos", 4ll, 0 );
			}
			goto label$494;
			label$499:;
			if( OP$1 != 70ll) goto label$501;
			label$502:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 120ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"exp", 4ll, 0 );
			}
			goto label$494;
			label$501:;
			if( OP$1 != 69ll) goto label$503;
			label$504:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 152ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"log", 4ll, 0 );
			}
			goto label$494;
			label$503:;
			if( OP$1 != 66ll) goto label$505;
			label$506:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 184ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"sqrt", 5ll, 0 );
			}
			goto label$494;
			label$505:;
			if( OP$1 != 71ll) goto label$507;
			label$508:;
			{
				*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 216ll) = -1ll;
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"floor", 6ll, 0 );
			}
			goto label$494;
			label$507:;
			{
			}
			label$509:;
			label$494:;
		}
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)".f64(double ", 13ll, 0 );
	}
	label$476:;
	FBSTRING* vr$23 = HVREGTOSTR( V1$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$23, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)")", 2ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$475:;
}

static void _EMITUOP( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	FBSTRING TMP$370$1;
	FBSTRING TMP$371$1;
	label$510:;
	FBSTRING UOPDUMP$1;
	FBSTRING* vr$0 = VREGPRETTY( V1$1 );
	FBSTRING* vr$1 = ASTDUMPOPTOSTR( OP$1 );
	__builtin_memset( &TMP$370$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$370$1, (void*)vr$1, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$371$1, 0, 24ll );
	FBSTRING* vr$7 = fb_StrConcat( &TMP$371$1, (void*)vr$4, -1ll, (void*)vr$0, -1ll );
	fb_StrInit( (void*)&UOPDUMP$1, -1ll, (void*)vr$7, -1ll, 0 );
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$513;
	{
		FBSTRING TMP$373$2;
		FBSTRING TMP$374$2;
		__builtin_memset( &TMP$374$2, 0, 24ll );
		__builtin_memset( &TMP$373$2, 0, 24ll );
		FBSTRING* vr$13 = fb_StrConcat( &TMP$373$2, (void*)"selfuop ", 9ll, (void*)&UOPDUMP$1, -1ll );
		fb_StrAssign( (void*)&TMP$374$2, -1ll, (void*)vr$13, -1ll, 0 );
		HASTCOMMAND( &TMP$374$2 );
		fb_StrDelete( (FBSTRING*)&TMP$374$2 );
	}
	goto label$512;
	label$513:;
	{
		FBSTRING TMP$376$2;
		FBSTRING TMP$377$2;
		__builtin_memset( &TMP$377$2, 0, 24ll );
		__builtin_memset( &TMP$376$2, 0, 24ll );
		FBSTRING* vr$21 = fb_StrConcat( &TMP$376$2, (void*)"uop ", 5ll, (void*)&UOPDUMP$1, -1ll );
		fb_StrAssign( (void*)&TMP$377$2, -1ll, (void*)vr$21, -1ll, 0 );
		HASTCOMMAND( &TMP$377$2 );
		fb_StrDelete( (FBSTRING*)&TMP$377$2 );
	}
	label$512:;
	{
		if( OP$1 != 55ll) goto label$515;
		label$516:;
		{
			struct $6IRVREG V1ORIG$3;
			__builtin_memset( &V1ORIG$3, 0, 120ll );
			int64 ISSELF$3;
			ISSELF$3 = 0ll;
			if( VR$1 != (struct $6IRVREG*)0ull) goto label$518;
			{
				ISSELF$3 = -1ll;
				struct $6IRVREG* vr$28 = IRHLALLOCVREG( *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll) );
				VR$1 = vr$28;
				__builtin_memcpy( &V1ORIG$3, V1$1, 120 );
			}
			label$518:;
			label$517:;
			struct $6IRVREG* ZERO$3;
			struct $6IRVREG* vr$30 = IRHLALLOCVRIMM( 8ll, (struct $8FBSYMBOL*)0ull, 0ll );
			ZERO$3 = vr$30;
			HEMITBOP( 29ll, ZERO$3, V1$1, VR$1, (struct $8FBSYMBOL*)0ull, 0ll );
			if( ISSELF$3 == 0ll) goto label$520;
			{
				HEMITSTORE( &V1ORIG$3, VR$1 );
			}
			label$520:;
			label$519:;
		}
		goto label$514;
		label$515:;
		if( OP$1 != 52ll) goto label$521;
		label$522:;
		{
			struct $6IRVREG* MINUSONE$3;
			struct $6IRVREG* vr$32 = IRHLALLOCVRIMM( 8ll, (struct $8FBSYMBOL*)0ull, -1ll );
			MINUSONE$3 = vr$32;
			HEMITBOP( 38ll, V1$1, MINUSONE$3, VR$1, (struct $8FBSYMBOL*)0ull, 0ll );
		}
		goto label$514;
		label$521:;
		{
			HBUILTINUOP( OP$1, V1$1, VR$1 );
		}
		label$523:;
		label$514:;
	}
	fb_StrDelete( (FBSTRING*)&UOPDUMP$1 );
	label$511:;
}

static char* HGETCONVOPCODE( int64 LDTYPE$1, int64 RDTYPE$1 )
{
	int64 TMP$378$1;
	int64 TMP$391$1;
	int64 TMP$399$1;
	int64 TMP$400$1;
	int64 TMP$403$1;
	int64 TMP$404$1;
	int64 TMP$406$1;
	char* TMP$409$1;
	char* fb$result$1;
	__builtin_memset( &fb$result$1, 0, 8ll );
	label$524:;
	if( (LDTYPE$1 & 480ll) == 0ll) goto label$526;
	TMP$378$1 = 24ll;
	goto label$775;
	label$526:;
	TMP$378$1 = LDTYPE$1 & 31ll;
	label$775:;
	if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$378$1 * 56ll)) != 1ll) goto label$528;
	{
		int64 TMP$379$2;
		int64 TMP$387$2;
		char* TMP$390$2;
		if( (RDTYPE$1 & 480ll) == 0ll) goto label$529;
		TMP$379$2 = 24ll;
		goto label$776;
		label$529:;
		TMP$379$2 = RDTYPE$1 & 31ll;
		label$776:;
		if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$379$2 * 56ll)) != 1ll) goto label$531;
		{
			int64 TMP$380$3;
			int64 TMP$381$3;
			int64 TMP$382$3;
			int64 TMP$383$3;
			char* TMP$386$3;
			if( (LDTYPE$1 & 480ll) == 0ll) goto label$532;
			TMP$380$3 = 24ll;
			goto label$777;
			label$532:;
			TMP$380$3 = LDTYPE$1 & 31ll;
			label$777:;
			if( (RDTYPE$1 & 480ll) == 0ll) goto label$533;
			TMP$381$3 = 24ll;
			goto label$778;
			label$533:;
			TMP$381$3 = RDTYPE$1 & 31ll;
			label$778:;
			if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$380$3 * 56ll)) + 8ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$381$3 * 56ll)) + 8ll)) goto label$535;
			{
				fb$result$1 = (char*)0ull;
				goto label$525;
			}
			label$535:;
			label$534:;
			if( (LDTYPE$1 & 480ll) == 0ll) goto label$536;
			TMP$382$3 = 24ll;
			goto label$779;
			label$536:;
			TMP$382$3 = LDTYPE$1 & 31ll;
			label$779:;
			if( (RDTYPE$1 & 480ll) == 0ll) goto label$537;
			TMP$383$3 = 24ll;
			goto label$780;
			label$537:;
			TMP$383$3 = RDTYPE$1 & 31ll;
			label$780:;
			if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$382$3 * 56ll)) + 8ll) >= *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$383$3 * 56ll)) + 8ll)) goto label$538;
			TMP$386$3 = (char*)"fptrunc";
			goto label$781;
			label$538:;
			TMP$386$3 = (char*)"fpext";
			label$781:;
			fb$result$1 = TMP$386$3;
			goto label$525;
		}
		label$531:;
		label$530:;
		if( (RDTYPE$1 & 480ll) == 0ll) goto label$539;
		TMP$387$2 = 24ll;
		goto label$782;
		label$539:;
		TMP$387$2 = RDTYPE$1 & 31ll;
		label$782:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$387$2 * 56ll)) + 16ll) == 0ll) goto label$540;
		TMP$390$2 = (char*)"sitofp";
		goto label$783;
		label$540:;
		TMP$390$2 = (char*)"uitofp";
		label$783:;
		fb$result$1 = TMP$390$2;
		goto label$525;
	}
	label$528:;
	label$527:;
	if( (RDTYPE$1 & 480ll) == 0ll) goto label$541;
	TMP$391$1 = 24ll;
	goto label$784;
	label$541:;
	TMP$391$1 = RDTYPE$1 & 31ll;
	label$784:;
	if( *(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$391$1 * 56ll)) != 1ll) goto label$543;
	{
		int64 TMP$392$2;
		char* TMP$395$2;
		if( (LDTYPE$1 & 480ll) == 0ll) goto label$544;
		TMP$392$2 = 24ll;
		goto label$785;
		label$544:;
		TMP$392$2 = LDTYPE$1 & 31ll;
		label$785:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$392$2 * 56ll)) + 16ll) == 0ll) goto label$545;
		TMP$395$2 = (char*)"fptosi";
		goto label$786;
		label$545:;
		TMP$395$2 = (char*)"fptoui";
		label$786:;
		fb$result$1 = TMP$395$2;
		goto label$525;
	}
	label$543:;
	label$542:;
	if( (LDTYPE$1 & 480ll) == 0ll) goto label$547;
	{
		if( (RDTYPE$1 & 480ll) == 0ll) goto label$549;
		{
			fb$result$1 = (char*)"bitcast";
			goto label$525;
		}
		label$549:;
		label$548:;
		fb$result$1 = (char*)"inttoptr";
		goto label$525;
	}
	goto label$546;
	label$547:;
	if( (RDTYPE$1 & 480ll) == 0ll) goto label$550;
	{
		fb$result$1 = (char*)"ptrtoint";
		goto label$525;
	}
	label$550:;
	label$546:;
	if( (LDTYPE$1 & 480ll) == 0ll) goto label$551;
	TMP$399$1 = 24ll;
	goto label$787;
	label$551:;
	TMP$399$1 = LDTYPE$1 & 31ll;
	label$787:;
	if( (RDTYPE$1 & 480ll) == 0ll) goto label$552;
	TMP$400$1 = 24ll;
	goto label$788;
	label$552:;
	TMP$400$1 = RDTYPE$1 & 31ll;
	label$788:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$399$1 * 56ll)) + 8ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$400$1 * 56ll)) + 8ll)) goto label$554;
	{
		int64 TMP$401$2;
		int64 TMP$402$2;
		if( (LDTYPE$1 & 480ll) == 0ll) goto label$555;
		TMP$401$2 = 24ll;
		goto label$789;
		label$555:;
		TMP$401$2 = LDTYPE$1 & 31ll;
		label$789:;
		if( (RDTYPE$1 & 480ll) == 0ll) goto label$556;
		TMP$402$2 = 24ll;
		goto label$790;
		label$556:;
		TMP$402$2 = RDTYPE$1 & 31ll;
		label$790:;
		if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$401$2 * 56ll)) + 40ll) != *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$402$2 * 56ll)) + 40ll)) goto label$558;
		{
			fb$result$1 = (char*)0ull;
			goto label$525;
		}
		label$558:;
		label$557:;
		fb$result$1 = (char*)"bitcast";
		goto label$525;
	}
	label$554:;
	label$553:;
	if( (LDTYPE$1 & 480ll) == 0ll) goto label$559;
	TMP$403$1 = 24ll;
	goto label$791;
	label$559:;
	TMP$403$1 = LDTYPE$1 & 31ll;
	label$791:;
	if( (RDTYPE$1 & 480ll) == 0ll) goto label$560;
	TMP$404$1 = 24ll;
	goto label$792;
	label$560:;
	TMP$404$1 = RDTYPE$1 & 31ll;
	label$792:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$403$1 * 56ll)) + 8ll) >= *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$404$1 * 56ll)) + 8ll)) goto label$562;
	{
		fb$result$1 = (char*)"trunc";
		goto label$525;
	}
	label$562:;
	label$561:;
	if( (LDTYPE$1 & 480ll) == 0ll) goto label$563;
	TMP$406$1 = 24ll;
	goto label$793;
	label$563:;
	TMP$406$1 = LDTYPE$1 & 31ll;
	label$793:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$406$1 * 56ll)) + 16ll) == 0ll) goto label$564;
	TMP$409$1 = (char*)"sext";
	goto label$794;
	label$564:;
	TMP$409$1 = (char*)"zext";
	label$794:;
	fb$result$1 = TMP$409$1;
	goto label$525;
	label$525:;
	return fb$result$1;
}

static void HEMITCONVERT( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	int64 TMP$410$1;
	int64 TMP$411$1;
	FBSTRING TMP$415$1;
	FBSTRING TMP$416$1;
	FBSTRING TMP$417$1;
	FBSTRING TMP$418$1;
	FBSTRING TMP$419$1;
	label$565:;
	if( (*(int64*)((uint8*)V2$1 + 8ll) & 480ll) == 0ll) goto label$567;
	TMP$410$1 = 24ll;
	goto label$795;
	label$567:;
	TMP$410$1 = *(int64*)((uint8*)V2$1 + 8ll) & 31ll;
	label$795:;
	if( (*(int64*)((uint8*)V1$1 + 8ll) & 480ll) == 0ll) goto label$568;
	TMP$411$1 = 24ll;
	goto label$796;
	label$568:;
	TMP$411$1 = *(int64*)((uint8*)V1$1 + 8ll) & 31ll;
	label$796:;
	if( ((int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$410$1 * 56ll)) == 1ll) & (int64)-(*(int64*)((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$411$1 * 56ll)) == 0ll)) == 0ll) goto label$570;
	{
		FBSTRING TMP$412$2;
		struct $6IRVREG* V0$2;
		struct $6IRVREG* vr$15 = IRHLALLOCVREG( *(int64*)((uint8*)V2$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V2$1 + 16ll) );
		V0$2 = vr$15;
		HLOADVREG( V2$1 );
		FBSTRING LN$2;
		FBSTRING* vr$16 = HVREGTOSTR( V0$2 );
		__builtin_memset( &TMP$412$2, 0, 24ll );
		FBSTRING* vr$19 = fb_StrConcat( &TMP$412$2, (void*)vr$16, -1ll, (void*)" = call ", 9ll );
		fb_StrInit( (void*)&LN$2, -1ll, (void*)vr$19, -1ll, 0 );
		if( *(int64*)((uint8*)V2$1 + 8ll) != 15ll) goto label$572;
		{
			*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 264ll) = -1ll;
			fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)"float @llvm.nearbyint.f32(float ", 33ll, 0 );
		}
		goto label$571;
		label$572:;
		{
			*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 280ll) = -1ll;
			fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)"double @llvm.nearbyint.f64(double ", 35ll, 0 );
		}
		label$571:;
		FBSTRING* vr$24 = HVREGTOSTR( V2$1 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)vr$24, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$2, -1ll, (void*)")", 2ll, 0 );
		HWRITELINE( &LN$2 );
		__builtin_memcpy( V2$1, V0$2, 120 );
		fb_StrDelete( (FBSTRING*)&LN$2 );
	}
	label$570:;
	label$569:;
	char* OP$1;
	char* vr$31 = HGETCONVOPCODE( *(int64*)((uint8*)V1$1 + 8ll), *(int64*)((uint8*)V2$1 + 8ll) );
	OP$1 = vr$31;
	if( OP$1 != (char*)0ull) goto label$574;
	{
		__builtin_memcpy( V1$1, V2$1, 120 );
		goto label$566;
	}
	label$574:;
	label$573:;
	struct $6IRVREG* V0$1;
	__builtin_memset( &V0$1, 0, 8ll );
	if( *(int64*)V1$1 != 4ll) goto label$576;
	{
		V0$1 = V1$1;
	}
	goto label$575;
	label$576:;
	{
		struct $6IRVREG* vr$36 = IRHLALLOCVREG( *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll) );
		V0$1 = vr$36;
	}
	label$575:;
	HLOADVREG( V2$1 );
	FBSTRING LN$1;
	FBSTRING* vr$37 = HVREGTOSTR( V0$1 );
	__builtin_memset( &TMP$415$1, 0, 24ll );
	FBSTRING* vr$40 = fb_StrConcat( &TMP$415$1, (void*)vr$37, -1ll, (void*)" = ", 4ll );
	__builtin_memset( &TMP$416$1, 0, 24ll );
	FBSTRING* vr$43 = fb_StrConcat( &TMP$416$1, (void*)vr$40, -1ll, (void*)OP$1, 0ll );
	__builtin_memset( &TMP$417$1, 0, 24ll );
	FBSTRING* vr$46 = fb_StrConcat( &TMP$417$1, (void*)vr$43, -1ll, (void*)" ", 2ll );
	fb_StrInit( (void*)&LN$1, -1ll, (void*)vr$46, -1ll, 0 );
	FBSTRING* vr$50 = HEMITTYPE( *(int64*)((uint8*)V2$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V2$1 + 16ll) );
	__builtin_memset( &TMP$418$1, 0, 24ll );
	FBSTRING* vr$54 = fb_StrConcat( &TMP$418$1, (void*)&LN$1, -1ll, (void*)vr$50, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$54, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$57 = HVREGTOSTR( V2$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$57, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" to ", 5ll, 0 );
	FBSTRING* vr$62 = HEMITTYPE( *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll) );
	__builtin_memset( &TMP$419$1, 0, 24ll );
	FBSTRING* vr$66 = fb_StrConcat( &TMP$419$1, (void*)&LN$1, -1ll, (void*)vr$62, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$66, -1ll, 0 );
	HWRITELINE( &LN$1 );
	if( *(int64*)V1$1 == 4ll) goto label$578;
	{
		HEMITSTORE( V1$1, V0$1 );
	}
	label$578:;
	label$577:;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$566:;
}

static void _EMITCONVERT( struct $6IRVREG* V1$1, struct $6IRVREG* V2$1 )
{
	FBSTRING TMP$422$1;
	FBSTRING TMP$423$1;
	FBSTRING TMP$424$1;
	FBSTRING TMP$425$1;
	label$579:;
	__builtin_memset( &TMP$425$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( V1$1 );
	FBSTRING* vr$2 = VREGPRETTY( V2$1 );
	__builtin_memset( &TMP$422$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$422$1, (void*)"conv ", 6ll, (void*)vr$2, -1ll );
	__builtin_memset( &TMP$423$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$423$1, (void*)vr$5, -1ll, (void*)" => ", 5ll );
	__builtin_memset( &TMP$424$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$424$1, (void*)vr$8, -1ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$425$1, -1ll, (void*)vr$11, -1ll, 0 );
	HASTCOMMAND( &TMP$425$1 );
	fb_StrDelete( (FBSTRING*)&TMP$425$1 );
	HEMITCONVERT( V1$1, V2$1 );
	label$580:;
}

static void HEMITSTORE( struct $6IRVREG* L$1, struct $6IRVREG* R$1 )
{
	FBSTRING TMP$426$1;
	FBSTRING TMP$427$1;
	FBSTRING TMP$428$1;
	FBSTRING TMP$429$1;
	label$581:;
	HLOADVREG( R$1 );
	_SETVREGDATATYPE( R$1, *(int64*)((uint8*)L$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll) );
	HPREPAREADDRESS( L$1 );
	FBSTRING LN$1;
	fb_StrInit( (void*)&LN$1, -1ll, (void*)"store ", 7ll, 0 );
	FBSTRING* vr$18 = HEMITTYPE( (((*(int64*)((uint8*)L$1 + 8ll) & 31ll) | ((*(int64*)((uint8*)L$1 + 8ll) & 480ll) + -32ll)) | (((*(int64*)((uint8*)L$1 + 8ll) & 261632ll) >> (1ll & 63ll)) & 261632ll)) | (*(int64*)((uint8*)L$1 + 8ll) & 32505856ll), *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll) );
	__builtin_memset( &TMP$426$1, 0, 24ll );
	FBSTRING* vr$21 = fb_StrConcat( &TMP$426$1, (void*)vr$18, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$427$1, 0, 24ll );
	FBSTRING* vr$25 = fb_StrConcat( &TMP$427$1, (void*)&LN$1, -1ll, (void*)vr$21, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$25, -1ll, 0 );
	FBSTRING* vr$27 = HVREGTOSTR( R$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$27, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
	FBSTRING* vr$32 = HEMITTYPE( *(int64*)((uint8*)L$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)L$1 + 16ll) );
	__builtin_memset( &TMP$428$1, 0, 24ll );
	FBSTRING* vr$35 = fb_StrConcat( &TMP$428$1, (void*)vr$32, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$429$1, 0, 24ll );
	FBSTRING* vr$39 = fb_StrConcat( &TMP$429$1, (void*)&LN$1, -1ll, (void*)vr$35, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$39, -1ll, 0 );
	FBSTRING* vr$41 = HVREGTOSTR( L$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$41, -1ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$582:;
}

static void _EMITSTORE( struct $6IRVREG* L$1, struct $6IRVREG* R$1 )
{
	FBSTRING TMP$431$1;
	FBSTRING TMP$432$1;
	FBSTRING TMP$433$1;
	FBSTRING TMP$434$1;
	label$583:;
	__builtin_memset( &TMP$434$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( R$1 );
	FBSTRING* vr$2 = VREGPRETTY( L$1 );
	__builtin_memset( &TMP$431$1, 0, 24ll );
	FBSTRING* vr$5 = fb_StrConcat( &TMP$431$1, (void*)"store ", 7ll, (void*)vr$2, -1ll );
	__builtin_memset( &TMP$432$1, 0, 24ll );
	FBSTRING* vr$8 = fb_StrConcat( &TMP$432$1, (void*)vr$5, -1ll, (void*)" := ", 5ll );
	__builtin_memset( &TMP$433$1, 0, 24ll );
	FBSTRING* vr$11 = fb_StrConcat( &TMP$433$1, (void*)vr$8, -1ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$434$1, -1ll, (void*)vr$11, -1ll, 0 );
	HASTCOMMAND( &TMP$434$1 );
	fb_StrDelete( (FBSTRING*)&TMP$434$1 );
	HEMITSTORE( L$1, R$1 );
	label$584:;
}

static void _EMITSPILLREGS( void )
{
	label$585:;
	label$586:;
}

static void _EMITLOAD( struct $6IRVREG* V1$1 )
{
	label$587:;
	label$588:;
}

static void _EMITLOADRES( struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	FBSTRING TMP$436$1;
	FBSTRING TMP$437$1;
	FBSTRING TMP$439$1;
	FBSTRING TMP$440$1;
	FBSTRING TMP$441$1;
	FBSTRING TMP$442$1;
	label$589:;
	__builtin_memset( &TMP$437$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( V1$1 );
	__builtin_memset( &TMP$436$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$436$1, (void*)"loadres ", 9ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$437$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$437$1 );
	fb_StrDelete( (FBSTRING*)&TMP$437$1 );
	HLOADVREG( V1$1 );
	_SETVREGDATATYPE( V1$1, *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
	__builtin_memset( &TMP$442$1, 0, 24ll );
	FBSTRING* vr$11 = HVREGTOSTR( V1$1 );
	FBSTRING* vr$14 = HEMITTYPE( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
	__builtin_memset( &TMP$439$1, 0, 24ll );
	FBSTRING* vr$17 = fb_StrConcat( &TMP$439$1, (void*)"ret ", 5ll, (void*)vr$14, -1ll );
	__builtin_memset( &TMP$440$1, 0, 24ll );
	FBSTRING* vr$20 = fb_StrConcat( &TMP$440$1, (void*)vr$17, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$441$1, 0, 24ll );
	FBSTRING* vr$23 = fb_StrConcat( &TMP$441$1, (void*)vr$20, -1ll, (void*)vr$11, -1ll );
	fb_StrAssign( (void*)&TMP$442$1, -1ll, (void*)vr$23, -1ll, 0 );
	HWRITELINE( &TMP$442$1 );
	fb_StrDelete( (FBSTRING*)&TMP$442$1 );
	label$590:;
}

static void _EMITADDR( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1 )
{
	label$591:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	{
		if( OP$1 != 22ll) goto label$594;
		label$595:;
		{
			FBSTRING TMP$444$3;
			FBSTRING TMP$445$3;
			__builtin_memset( &TMP$445$3, 0, 24ll );
			FBSTRING* vr$2 = VREGPRETTY( V1$1 );
			__builtin_memset( &TMP$444$3, 0, 24ll );
			FBSTRING* vr$5 = fb_StrConcat( &TMP$444$3, (void*)"addrof ", 8ll, (void*)vr$2, -1ll );
			fb_StrAssign( (void*)&TMP$445$3, -1ll, (void*)vr$5, -1ll, 0 );
			HASTCOMMAND( &TMP$445$3 );
			fb_StrDelete( (FBSTRING*)&TMP$445$3 );
			HPREPAREADDRESS( V1$1 );
			_SETVREGDATATYPE( V1$1, *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
		}
		goto label$593;
		label$594:;
		if( OP$1 != 77ll) goto label$596;
		label$597:;
		{
			FBSTRING TMP$447$3;
			FBSTRING TMP$448$3;
			__builtin_memset( &TMP$448$3, 0, 24ll );
			FBSTRING* vr$12 = VREGPRETTY( V1$1 );
			__builtin_memset( &TMP$447$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$447$3, (void*)"deref ", 7ll, (void*)vr$12, -1ll );
			fb_StrAssign( (void*)&TMP$448$3, -1ll, (void*)vr$15, -1ll, 0 );
			HASTCOMMAND( &TMP$448$3 );
			fb_StrDelete( (FBSTRING*)&TMP$448$3 );
			HLOADVREG( V1$1 );
		}
		label$596:;
		label$593:;
	}
	__builtin_memcpy( VR$1, V1$1, 120 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$592:;
}

static void HDOCALL( char* PNAME$1, struct $8FBSYMBOL* PROC$1, int64 BYTESTOPOP$1, struct $6IRVREG* VR$1, int64 LEVEL$1 )
{
	FBSTRING TMP$453$1;
	FBSTRING TMP$454$1;
	int64 TMP$455$1;
	label$598:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	struct $9IRCALLARG* ARG$1;
	struct $9IRCALLARG* PREV$1;
	struct $6IRVREG* VARG$1;
	struct $6IRVREG* V0$1;
	if( VR$1 != (struct $6IRVREG*)0ull) goto label$601;
	{
		if( (*(int64*)((uint8*)PROC$1 + 56ll) & 511ll) == 0ll) goto label$603;
		{
			struct $6IRVREG* vr$6 = IRHLALLOCVREG( *(int64*)((uint8*)PROC$1 + 160ll) & 511ll, *(struct $8FBSYMBOL**)((uint8*)PROC$1 + 168ll) );
			VR$1 = vr$6;
		}
		label$603:;
		label$602:;
	}
	label$601:;
	label$600:;
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$605;
	{
		FBSTRING TMP$449$2;
		FBSTRING TMP$450$2;
		if( *(int64*)VR$1 != 4ll) goto label$607;
		{
			V0$1 = VR$1;
		}
		goto label$606;
		label$607:;
		{
			struct $6IRVREG* vr$10 = IRHLALLOCVREG( *(int64*)((uint8*)VR$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)VR$1 + 16ll) );
			V0$1 = vr$10;
		}
		label$606:;
		FBSTRING* vr$11 = HVREGTOSTR( V0$1 );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$11, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" = call ", 9ll, 0 );
		FBSTRING* vr$14 = HEMITPROCCALLCONV( PROC$1 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$14, -1ll, 0 );
		FBSTRING* vr$18 = HEMITTYPE( *(int64*)((uint8*)V0$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V0$1 + 16ll) );
		__builtin_memset( &TMP$449$2, 0, 24ll );
		FBSTRING* vr$21 = fb_StrConcat( &TMP$449$2, (void*)vr$18, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$450$2, 0, 24ll );
		FBSTRING* vr$25 = fb_StrConcat( &TMP$450$2, (void*)&LN$1, -1ll, (void*)vr$21, -1ll );
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$25, -1ll, 0 );
	}
	goto label$604;
	label$605:;
	{
		fb_StrAssign( (void*)&LN$1, -1ll, (void*)"call ", 6ll, 0 );
		FBSTRING* vr$28 = HEMITPROCCALLCONV( PROC$1 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$28, -1ll, 0 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"void ", 6ll, 0 );
	}
	label$604:;
	__builtin_memset( &TMP$453$1, 0, 24ll );
	FBSTRING* vr$33 = fb_StrConcat( &TMP$453$1, (void*)PNAME$1, 0ll, (void*)"( ", 3ll );
	__builtin_memset( &TMP$454$1, 0, 24ll );
	FBSTRING* vr$37 = fb_StrConcat( &TMP$454$1, (void*)&LN$1, -1ll, (void*)vr$33, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$37, -1ll, 0 );
	void* vr$40 = LISTGETTAIL( (struct $5TLIST*)((uint8*)&IRHL$ + 120ll) );
	ARG$1 = (struct $9IRCALLARG*)vr$40;
	label$608:;
	if( ARG$1 == (struct $9IRCALLARG*)0ull) goto label$610;
	TMP$455$1 = (int64)-((struct $9IRCALLARG*)(int64)-(*(int64*)((uint8*)ARG$1 + 16ll) == LEVEL$1) != (struct $9IRCALLARG*)0ull);
	goto label$797;
	label$610:;
	TMP$455$1 = 0ll;
	label$797:;
	if( TMP$455$1 == 0ll) goto label$609;
	{
		FBSTRING TMP$457$2;
		FBSTRING TMP$458$2;
		void* vr$44 = LISTGETPREV( (void*)ARG$1 );
		PREV$1 = (struct $9IRCALLARG*)vr$44;
		VARG$1 = *(struct $6IRVREG**)((uint8*)ARG$1 + 8ll);
		__builtin_memset( &TMP$458$2, 0, 24ll );
		FBSTRING* vr$47 = VREGPRETTY( VARG$1 );
		__builtin_memset( &TMP$457$2, 0, 24ll );
		FBSTRING* vr$50 = fb_StrConcat( &TMP$457$2, (void*)"arg ", 5ll, (void*)vr$47, -1ll );
		fb_StrAssign( (void*)&TMP$458$2, -1ll, (void*)vr$50, -1ll, 0 );
		HINTERNALCOMMAND( &TMP$458$2 );
		fb_StrDelete( (FBSTRING*)&TMP$458$2 );
		HLOADVREG( VARG$1 );
		int64 DTYPE$2;
		__builtin_memset( &DTYPE$2, 0, 8ll );
		struct $8FBSYMBOL* SUBTYPE$2;
		__builtin_memset( &SUBTYPE$2, 0, 8ll );
		if( *(struct $8FBSYMBOL**)ARG$1 == (struct $8FBSYMBOL*)0ull) goto label$612;
		{
			_Z21SYMBGETREALPARAMDTYPEP8FBSYMBOLRlRS0_( *(struct $8FBSYMBOL**)ARG$1, &DTYPE$2, &SUBTYPE$2 );
		}
		goto label$611;
		label$612:;
		{
			DTYPE$2 = *(int64*)((uint8*)VARG$1 + 8ll);
			SUBTYPE$2 = *(struct $8FBSYMBOL**)((uint8*)VARG$1 + 16ll);
		}
		label$611:;
		FBSTRING* vr$62 = HEMITTYPE( DTYPE$2, SUBTYPE$2 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$62, -1ll, 0 );
		_SETVREGDATATYPE( VARG$1, DTYPE$2, SUBTYPE$2 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
		FBSTRING* vr$65 = HVREGTOSTR( VARG$1 );
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$65, -1ll, 0 );
		LISTDELNODE( (struct $5TLIST*)((uint8*)&IRHL$ + 120ll), (void*)ARG$1 );
		if( PREV$1 == (struct $9IRCALLARG*)0ull) goto label$614;
		{
			if( *(int64*)((uint8*)PREV$1 + 16ll) != LEVEL$1) goto label$616;
			{
				fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
			}
			label$616:;
			label$615:;
		}
		label$614:;
		label$613:;
		ARG$1 = PREV$1;
	}
	goto label$608;
	label$609:;
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" )", 3ll, 0 );
	HWRITELINE( &LN$1 );
	if( VR$1 == (struct $6IRVREG*)0ull) goto label$618;
	{
		if( *(int64*)VR$1 == 4ll) goto label$620;
		{
			HEMITSTORE( VR$1, V0$1 );
		}
		label$620:;
		label$619:;
	}
	label$618:;
	label$617:;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$599:;
}

static void _EMITCALL( struct $8FBSYMBOL* PROC$1, int64 BYTESTOPOP$1, struct $6IRVREG* VR$1, int64 LEVEL$1 )
{
	FBSTRING TMP$460$1;
	FBSTRING TMP$461$1;
	FBSTRING TMP$462$1;
	label$621:;
	__builtin_memset( &TMP$462$1, 0, 24ll );
	FBSTRING* vr$1 = HSYMNAME( PROC$1 );
	__builtin_memset( &TMP$460$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$460$1, (void*)"call ", 6ll, (void*)vr$1, -1ll );
	__builtin_memset( &TMP$461$1, 0, 24ll );
	FBSTRING* vr$7 = fb_StrConcat( &TMP$461$1, (void*)vr$4, -1ll, (void*)"()", 3ll );
	fb_StrAssign( (void*)&TMP$462$1, -1ll, (void*)vr$7, -1ll, 0 );
	HASTCOMMAND( &TMP$462$1 );
	fb_StrDelete( (FBSTRING*)&TMP$462$1 );
	char* vr$11 = SYMBGETMANGLEDNAME( PROC$1 );
	HDOCALL( vr$11, PROC$1, BYTESTOPOP$1, VR$1, LEVEL$1 );
	label$622:;
}

static void _EMITCALLPTR( struct $8FBSYMBOL* PROC$1, struct $6IRVREG* V1$1, struct $6IRVREG* VR$1, int64 BYTESTOPOP$1, int64 LEVEL$1 )
{
	FBSTRING TMP$464$1;
	FBSTRING TMP$465$1;
	FBSTRING TMP$466$1;
	label$623:;
	__builtin_memset( &TMP$465$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( V1$1 );
	__builtin_memset( &TMP$464$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$464$1, (void*)"callptr ", 9ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$465$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$465$1 );
	fb_StrDelete( (FBSTRING*)&TMP$465$1 );
	HLOADVREG( V1$1 );
	__builtin_memset( &TMP$466$1, 0, 24ll );
	FBSTRING* vr$9 = HVREGTOSTR( V1$1 );
	fb_StrAssign( (void*)&TMP$466$1, -1ll, (void*)vr$9, -1ll, 0 );
	HDOCALL( (char*)*(char**)&TMP$466$1, PROC$1, BYTESTOPOP$1, VR$1, LEVEL$1 );
	fb_StrDelete( (FBSTRING*)&TMP$466$1 );
	label$624:;
}

static void _EMITJUMPPTR( struct $6IRVREG* V1$1 )
{
	FBSTRING TMP$468$1;
	FBSTRING TMP$469$1;
	FBSTRING TMP$471$1;
	FBSTRING TMP$472$1;
	label$625:;
	__builtin_memset( &TMP$469$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( V1$1 );
	__builtin_memset( &TMP$468$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$468$1, (void*)"jumpptr ", 9ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$469$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$469$1 );
	fb_StrDelete( (FBSTRING*)&TMP$469$1 );
	HLOADVREG( V1$1 );
	__builtin_memset( &TMP$472$1, 0, 24ll );
	FBSTRING* vr$9 = HVREGTOSTR( V1$1 );
	__builtin_memset( &TMP$471$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$471$1, (void*)"goto *", 7ll, (void*)vr$9, -1ll );
	fb_StrAssign( (void*)&TMP$472$1, -1ll, (void*)vr$12, -1ll, 0 );
	HWRITELINE( &TMP$472$1 );
	fb_StrDelete( (FBSTRING*)&TMP$472$1 );
	label$626:;
}

static void _EMITBRANCH( int64 OP$1, struct $8FBSYMBOL* LABEL$1 )
{
	FBSTRING TMP$474$1;
	FBSTRING TMP$475$1;
	FBSTRING TMP$476$1;
	FBSTRING TMP$477$1;
	label$627:;
	__builtin_memset( &TMP$475$1, 0, 24ll );
	FBSTRING* vr$1 = HSYMNAME( LABEL$1 );
	__builtin_memset( &TMP$474$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$474$1, (void*)"goto ", 6ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$475$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$475$1 );
	fb_StrDelete( (FBSTRING*)&TMP$475$1 );
	__builtin_memset( &TMP$477$1, 0, 24ll );
	char* vr$9 = SYMBGETMANGLEDNAME( LABEL$1 );
	__builtin_memset( &TMP$476$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$476$1, (void*)"br label %", 11ll, (void*)vr$9, 0ll );
	fb_StrAssign( (void*)&TMP$477$1, -1ll, (void*)vr$12, -1ll, 0 );
	HWRITELINE( &TMP$477$1 );
	fb_StrDelete( (FBSTRING*)&TMP$477$1 );
	char* vr$16 = SYMBUNIQUELABEL(  );
	HWRITELABEL( vr$16 );
	label$628:;
}

static void _EMITJMPTB( struct $6IRVREG* V1$1, struct $8FBSYMBOL* TBSYM$1, uint64* VALUES$1, struct $8FBSYMBOL** LABELS$1, int64 LABELCOUNT$1, struct $8FBSYMBOL* DEFLABEL$1, uint64 BIAS$1, uint64 SPAN$1 )
{
	FBSTRING TMP$479$1;
	FBSTRING TMP$480$1;
	FBSTRING TMP$482$1;
	FBSTRING TMP$483$1;
	FBSTRING TMP$484$1;
	FBSTRING TMP$491$1;
	label$629:;
	__builtin_memset( &TMP$480$1, 0, 24ll );
	FBSTRING* vr$1 = VREGPRETTY( V1$1 );
	__builtin_memset( &TMP$479$1, 0, 24ll );
	FBSTRING* vr$4 = fb_StrConcat( &TMP$479$1, (void*)"jmptb ", 7ll, (void*)vr$1, -1ll );
	fb_StrAssign( (void*)&TMP$480$1, -1ll, (void*)vr$4, -1ll, 0 );
	HASTCOMMAND( &TMP$480$1 );
	fb_StrDelete( (FBSTRING*)&TMP$480$1 );
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	HLOADVREG( V1$1 );
	FBSTRING DTYPE$1;
	FBSTRING* vr$11 = HEMITTYPE( *(int64*)((uint8*)V1$1 + 8ll), *(struct $8FBSYMBOL**)((uint8*)V1$1 + 16ll) );
	fb_StrInit( (void*)&DTYPE$1, -1ll, (void*)vr$11, -1ll, 0 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)"switch ", 8ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)&DTYPE$1, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" ", 2ll, 0 );
	FBSTRING* vr$17 = HVREGTOSTR( V1$1 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$17, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
	char* vr$20 = SYMBGETMANGLEDNAME( DEFLABEL$1 );
	__builtin_memset( &TMP$482$1, 0, 24ll );
	FBSTRING* vr$23 = fb_StrConcat( &TMP$482$1, (void*)"label %", 8ll, (void*)vr$20, 0ll );
	__builtin_memset( &TMP$483$1, 0, 24ll );
	FBSTRING* vr$26 = fb_StrConcat( &TMP$483$1, (void*)vr$23, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$484$1, 0, 24ll );
	FBSTRING* vr$30 = fb_StrConcat( &TMP$484$1, (void*)&LN$1, -1ll, (void*)vr$26, -1ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$30, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"[", 2ll, 0 );
	HWRITELINE( &LN$1 );
	*(int64*)&CTX$ = *(int64*)&CTX$ + 1ll;
	{
		int64 I$2;
		I$2 = 0ll;
		int64 TMP$485$2;
		TMP$485$2 = LABELCOUNT$1 + -1ll;
		goto label$631;
		label$634:;
		{
			FBSTRING TMP$486$3;
			FBSTRING TMP$487$3;
			FBSTRING TMP$488$3;
			FBSTRING TMP$489$3;
			FBSTRING TMP$490$3;
			FBSTRING* vr$39 = fb_ULongintToStr( *(uint64*)((uint8*)VALUES$1 + (I$2 << (3ll & 63ll))) + BIAS$1 );
			__builtin_memset( &TMP$486$3, 0, 24ll );
			FBSTRING* vr$43 = fb_StrConcat( &TMP$486$3, (void*)&DTYPE$1, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$487$3, 0, 24ll );
			FBSTRING* vr$46 = fb_StrConcat( &TMP$487$3, (void*)vr$43, -1ll, (void*)vr$39, -1ll );
			__builtin_memset( &TMP$488$3, 0, 24ll );
			FBSTRING* vr$49 = fb_StrConcat( &TMP$488$3, (void*)vr$46, -1ll, (void*)", ", 3ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$49, -1ll, 0 );
			char* vr$53 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)LABELS$1 + (I$2 << (3ll & 63ll))) );
			__builtin_memset( &TMP$489$3, 0, 24ll );
			FBSTRING* vr$56 = fb_StrConcat( &TMP$489$3, (void*)"label %", 8ll, (void*)vr$53, 0ll );
			__builtin_memset( &TMP$490$3, 0, 24ll );
			FBSTRING* vr$60 = fb_StrConcat( &TMP$490$3, (void*)&LN$1, -1ll, (void*)vr$56, -1ll );
			fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$60, -1ll, 0 );
			HWRITELINE( &LN$1 );
		}
		label$632:;
		I$2 = I$2 + 1ll;
		label$631:;
		if( I$2 <= TMP$485$2) goto label$634;
		label$633:;
	}
	*(int64*)&CTX$ = *(int64*)&CTX$ + -1ll;
	__builtin_memset( &TMP$491$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$491$1, -1ll, (void*)"]", 2ll, 0 );
	HWRITELINE( &TMP$491$1 );
	fb_StrDelete( (FBSTRING*)&TMP$491$1 );
	fb_StrDelete( (FBSTRING*)&DTYPE$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$630:;
}

static void _EMITMEM( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$635:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)"call void ", 11ll, 0 );
	{
		if( OP$1 != 108ll) goto label$638;
		label$639:;
		{
			FBSTRING TMP$494$3;
			FBSTRING TMP$495$3;
			__builtin_memset( &TMP$495$3, 0, 24ll );
			FBSTRING* vr$3 = VREGPRETTY( V1$1 );
			__builtin_memset( &TMP$494$3, 0, 24ll );
			FBSTRING* vr$6 = fb_StrConcat( &TMP$494$3, (void*)"memfill ", 9ll, (void*)vr$3, -1ll );
			fb_StrAssign( (void*)&TMP$495$3, -1ll, (void*)vr$6, -1ll, 0 );
			HASTCOMMAND( &TMP$495$3 );
			fb_StrDelete( (FBSTRING*)&TMP$495$3 );
		}
		goto label$637;
		label$638:;
		if( OP$1 != 106ll) goto label$640;
		label$641:;
		{
			FBSTRING TMP$498$3;
			FBSTRING TMP$499$3;
			FBSTRING TMP$500$3;
			FBSTRING TMP$501$3;
			__builtin_memset( &TMP$501$3, 0, 24ll );
			FBSTRING* vr$11 = VREGPRETTY( V2$1 );
			FBSTRING* vr$12 = VREGPRETTY( V1$1 );
			__builtin_memset( &TMP$498$3, 0, 24ll );
			FBSTRING* vr$15 = fb_StrConcat( &TMP$498$3, (void*)"memmove ", 9ll, (void*)vr$12, -1ll );
			__builtin_memset( &TMP$499$3, 0, 24ll );
			FBSTRING* vr$18 = fb_StrConcat( &TMP$499$3, (void*)vr$15, -1ll, (void*)" <= ", 5ll );
			__builtin_memset( &TMP$500$3, 0, 24ll );
			FBSTRING* vr$21 = fb_StrConcat( &TMP$500$3, (void*)vr$18, -1ll, (void*)vr$11, -1ll );
			fb_StrAssign( (void*)&TMP$501$3, -1ll, (void*)vr$21, -1ll, 0 );
			HASTCOMMAND( &TMP$501$3 );
			fb_StrDelete( (FBSTRING*)&TMP$501$3 );
		}
		label$640:;
		label$637:;
	}
	HLOADVREG( V1$1 );
	HLOADVREG( V2$1 );
	{
		if( OP$1 != 108ll) goto label$643;
		label$644:;
		{
			*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 8ll) = -1ll;
			_SETVREGDATATYPE( V1$1, 34ll, (struct $8FBSYMBOL*)0ull );
			_SETVREGDATATYPE( V2$1, 8ll, (struct $8FBSYMBOL*)0ull );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"@llvm.memset.p0i8.i32( ", 24ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i8* ", 5ll, 0 );
			FBSTRING* vr$27 = HVREGTOSTR( V1$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$27, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i8 ", 4ll, 0 );
			FBSTRING* vr$31 = fb_LongintToStr( FILLCHAR$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$31, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i32 ", 5ll, 0 );
			FBSTRING* vr$35 = HVREGTOSTR( V2$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$35, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		goto label$642;
		label$643:;
		if( OP$1 != 106ll) goto label$645;
		label$646:;
		{
			*(int64*)((int64)(struct $7BUILTIN*)BUILTINS$ + 24ll) = -1ll;
			_SETVREGDATATYPE( V1$1, 34ll, (struct $8FBSYMBOL*)0ull );
			_SETVREGDATATYPE( V2$1, 34ll, (struct $8FBSYMBOL*)0ull );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"@llvm.memmove.p0i8.p0i8.i32( ", 30ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i8* ", 5ll, 0 );
			FBSTRING* vr$40 = HVREGTOSTR( V1$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$40, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i8* ", 5ll, 0 );
			FBSTRING* vr$44 = HVREGTOSTR( V2$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$44, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i32 ", 5ll, 0 );
			FBSTRING* vr$48 = fb_ULongintToStr( (uint64)BYTES$1 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$48, -1ll, 0 );
			fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", ", 3ll, 0 );
		}
		label$645:;
		label$642:;
	}
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i32 1, i1 false )", 18ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$636:;
}

static void _EMITMACRO( int64 OP$1, struct $6IRVREG* V1$1, struct $6IRVREG* V2$1, struct $6IRVREG* VR$1 )
{
	label$647:;
	label$648:;
}

static void _EMITDECL( struct $8FBSYMBOL* SYM$1 )
{
	label$649:;
	label$650:;
}

static void _EMITDBG( int64 OP$1, struct $8FBSYMBOL* PROC$1, int64 LNUM$1, char* FILENAME$1 )
{
	label$651:;
	if( OP$1 != 114ll) goto label$654;
	{
		if( FILENAME$1 == (char*)0ull) goto label$656;
		{
			FBSTRING TMP$511$3;
			FBSTRING TMP$512$3;
			FBSTRING TMP$513$3;
			FBSTRING TMP$514$3;
			FBSTRING TMP$515$3;
			__builtin_memset( &TMP$515$3, 0, 24ll );
			FBSTRING* vr$1 = HREPLACE( FILENAME$1, (char*)"\x5C", (char*)"\x5C\x5C" );
			FBSTRING* vr$2 = fb_LongintToStr( LNUM$1 );
			__builtin_memset( &TMP$511$3, 0, 24ll );
			FBSTRING* vr$5 = fb_StrConcat( &TMP$511$3, (void*)"#line ", 7ll, (void*)vr$2, -1ll );
			__builtin_memset( &TMP$512$3, 0, 24ll );
			FBSTRING* vr$8 = fb_StrConcat( &TMP$512$3, (void*)vr$5, -1ll, (void*)" \x22", 3ll );
			__builtin_memset( &TMP$513$3, 0, 24ll );
			FBSTRING* vr$11 = fb_StrConcat( &TMP$513$3, (void*)vr$8, -1ll, (void*)vr$1, -1ll );
			__builtin_memset( &TMP$514$3, 0, 24ll );
			FBSTRING* vr$14 = fb_StrConcat( &TMP$514$3, (void*)vr$11, -1ll, (void*)"\x22", 2ll );
			fb_StrAssign( (void*)&TMP$515$3, -1ll, (void*)vr$14, -1ll, 0 );
			HWRITELINE( &TMP$515$3 );
			fb_StrDelete( (FBSTRING*)&TMP$515$3 );
		}
		goto label$655;
		label$656:;
		{
			FBSTRING TMP$516$3;
			FBSTRING TMP$517$3;
			FBSTRING TMP$518$3;
			FBSTRING TMP$519$3;
			FBSTRING TMP$520$3;
			__builtin_memset( &TMP$520$3, 0, 24ll );
			FBSTRING* vr$20 = HREPLACE( (char*)((uint8*)&ENV$ + 632ll), (char*)"\x5C", (char*)"\x5C\x5C" );
			FBSTRING* vr$21 = fb_LongintToStr( LNUM$1 );
			__builtin_memset( &TMP$516$3, 0, 24ll );
			FBSTRING* vr$24 = fb_StrConcat( &TMP$516$3, (void*)"#line ", 7ll, (void*)vr$21, -1ll );
			__builtin_memset( &TMP$517$3, 0, 24ll );
			FBSTRING* vr$27 = fb_StrConcat( &TMP$517$3, (void*)vr$24, -1ll, (void*)" \x22", 3ll );
			__builtin_memset( &TMP$518$3, 0, 24ll );
			FBSTRING* vr$30 = fb_StrConcat( &TMP$518$3, (void*)vr$27, -1ll, (void*)vr$20, -1ll );
			__builtin_memset( &TMP$519$3, 0, 24ll );
			FBSTRING* vr$33 = fb_StrConcat( &TMP$519$3, (void*)vr$30, -1ll, (void*)"\x22", 2ll );
			fb_StrAssign( (void*)&TMP$520$3, -1ll, (void*)vr$33, -1ll, 0 );
			HWRITELINE( &TMP$520$3 );
			fb_StrDelete( (FBSTRING*)&TMP$520$3 );
		}
		label$655:;
		*(int64*)((uint8*)&CTX$ + 8ll) = LNUM$1;
	}
	label$654:;
	label$653:;
	label$652:;
}

static void _EMITCOMMENT( char* TEXT$1 )
{
	FBSTRING TMP$521$1;
	FBSTRING TMP$522$1;
	label$657:;
	__builtin_memset( &TMP$522$1, 0, 24ll );
	__builtin_memset( &TMP$521$1, 0, 24ll );
	FBSTRING* vr$3 = fb_StrConcat( &TMP$521$1, (void*)"; ", 3ll, (void*)TEXT$1, 0ll );
	fb_StrAssign( (void*)&TMP$522$1, -1ll, (void*)vr$3, -1ll, 0 );
	HWRITELINE( &TMP$522$1 );
	fb_StrDelete( (FBSTRING*)&TMP$522$1 );
	label$658:;
}

static void _EMITASMLINE( struct $9ASTASMTOK* ASMTOKENHEAD$1 )
{
	label$659:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	struct $9ASTASMTOK* N$1;
	N$1 = ASMTOKENHEAD$1;
	label$661:;
	if( N$1 == (struct $9ASTASMTOK*)0ull) goto label$662;
	{
		{
			$14AST_ASMTOKTYPE TMP$523$3;
			TMP$523$3 = *($14AST_ASMTOKTYPE*)N$1;
			if( TMP$523$3 != 0ll) goto label$664;
			label$665:;
			{
				FBSTRING TMP$524$4;
				__builtin_memset( &TMP$524$4, 0, 24ll );
				FBSTRING* vr$6 = fb_StrConcat( &TMP$524$4, (void*)&LN$1, -1ll, *(void**)((uint8*)N$1 + 8ll), 0ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$6, -1ll, 0 );
			}
			goto label$663;
			label$664:;
			if( TMP$523$3 != 1ll) goto label$666;
			label$667:;
			{
				FBSTRING TMP$525$4;
				char* vr$9 = SYMBGETMANGLEDNAME( *(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) );
				__builtin_memset( &TMP$525$4, 0, 24ll );
				FBSTRING* vr$13 = fb_StrConcat( &TMP$525$4, (void*)&LN$1, -1ll, (void*)vr$9, 0ll );
				fb_StrAssign( (void*)&LN$1, -1ll, (void*)vr$13, -1ll, 0 );
				int64 OFS$4;
				OFS$4 = *(int64*)((uint8*)*(struct $8FBSYMBOL**)((uint8*)N$1 + 8ll) + 88ll);
				if( OFS$4 == 0ll) goto label$669;
				{
					if( OFS$4 <= 0ll) goto label$671;
					{
						fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"+", 2ll, 0 );
					}
					label$671:;
					label$670:;
					FBSTRING* vr$18 = fb_LongintToStr( OFS$4 );
					fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$18, -1ll, 0 );
				}
				label$669:;
				label$668:;
			}
			label$666:;
			label$663:;
		}
		N$1 = *(struct $9ASTASMTOK**)((uint8*)N$1 + 16ll);
	}
	goto label$661;
	label$662:;
	HWRITELINE( &LN$1 );
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$660:;
}

static void _EMITVARINIBEGIN( struct $8FBSYMBOL* SYM$1 )
{
	label$672:;
	char* vr$0 = SYMBGETMANGLEDNAME( SYM$1 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$0, 0ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" = global ", 11ll, 0 );
	FBSTRING* vr$3 = HEMITSYMTYPE( SYM$1 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$3, -1ll, 0 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" ", 2ll, 0 );
	*(int64*)((uint8*)&CTX$ + 40ll) = 0ll;
	*(int8*)((uint8*)&CTX$ + 48ll) = (int8)0;
	label$673:;
}

static void _EMITVARINIEND( struct $8FBSYMBOL* SYM$1 )
{
	label$674:;
	HWRITELINE( (FBSTRING*)((uint8*)&CTX$ + 16ll) );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"", 1ll, 0 );
	label$675:;
}

static void HVARINIELEMENTTYPE( struct $8FBSYMBOL* SYM$1 )
{
	label$676:;
	if( *(int64*)((uint8*)&CTX$ + 40ll) <= 0ll) goto label$679;
	{
		if( (int64)*(int8*)((uint8*)((uint8*)&CTX$ + *(int64*)((uint8*)&CTX$ + 40ll)) + 48ll) == 0ll) goto label$681;
		{
			FBSTRING TMP$527$3;
			FBSTRING TMP$528$3;
			FBSTRING* vr$5 = HEMITTYPE( *(int64*)((uint8*)SYM$1 + 56ll) & 511ll, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
			__builtin_memset( &TMP$527$3, 0, 24ll );
			FBSTRING* vr$8 = fb_StrConcat( &TMP$527$3, (void*)vr$5, -1ll, (void*)" ", 2ll );
			__builtin_memset( &TMP$528$3, 0, 24ll );
			FBSTRING* vr$12 = fb_StrConcat( &TMP$528$3, (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$8, -1ll );
			fb_StrAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$12, -1ll, 0 );
		}
		goto label$680;
		label$681:;
		{
			FBSTRING* vr$14 = HEMITSYMTYPE( SYM$1 );
			fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$14, -1ll, 0 );
			fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" ", 2ll, 0 );
		}
		label$680:;
	}
	label$679:;
	label$678:;
	label$677:;
}

static void HVARINISEPARATOR( void )
{
	label$682:;
	if( *(int64*)((uint8*)&CTX$ + 40ll) <= 0ll) goto label$685;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)", ", 3ll, 0 );
	}
	label$685:;
	label$684:;
	label$683:;
}

static void _EMITVARINII( struct $8FBSYMBOL* SYM$1, int64 VALUE$1 )
{
	int64 TMP$529$1;
	label$686:;
	HVARINIELEMENTTYPE( SYM$1 );
	int64 DTYPE$1;
	DTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	if( ((int64)-(DTYPE$1 == 1ll) & (int64)-(VALUE$1 != 0ll)) == 0ll) goto label$689;
	{
		VALUE$1 = 1ll;
	}
	label$689:;
	label$688:;
	if( (DTYPE$1 & 480ll) == 0ll) goto label$690;
	TMP$529$1 = 24ll;
	goto label$798;
	label$690:;
	TMP$529$1 = DTYPE$1 & 31ll;
	label$798:;
	if( *(int64*)(((int64)(struct $13SYMB_DATATYPE*)SYMB_DTYPETB$ + (TMP$529$1 * 56ll)) + 8ll) != 8ll) goto label$692;
	{
		FBSTRING* vr$8 = HEMITLONG( VALUE$1 );
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$8, -1ll, 0 );
	}
	goto label$691;
	label$692:;
	{
		FBSTRING TMP$530$2;
		FBSTRING* vr$11 = HEMITINT( DTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), VALUE$1 );
		__builtin_memset( &TMP$530$2, 0, 24ll );
		FBSTRING* vr$15 = fb_StrConcat( &TMP$530$2, (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$11, -1ll );
		fb_StrAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$15, -1ll, 0 );
	}
	label$691:;
	HVARINISEPARATOR(  );
	label$687:;
}

static void _EMITVARINIF( struct $8FBSYMBOL* SYM$1, double VALUE$1 )
{
	label$693:;
	HVARINIELEMENTTYPE( SYM$1 );
	FBSTRING* vr$0 = HEMITFLOAT( VALUE$1 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$0, -1ll, 0 );
	HVARINISEPARATOR(  );
	label$694:;
}

static void HMAYBEADDCONV( FBSTRING* S$1, int64 LDTYPE$1, struct $8FBSYMBOL* LSUBTYPE$1, FBSTRING* LTYPE$1, int64 RDTYPE$1, struct $8FBSYMBOL* RSUBTYPE$1, FBSTRING* RTYPE$1 )
{
	FBSTRING TMP$532$1;
	FBSTRING TMP$533$1;
	FBSTRING TMP$534$1;
	FBSTRING TMP$535$1;
	FBSTRING TMP$536$1;
	FBSTRING TMP$537$1;
	FBSTRING TMP$538$1;
	label$695:;
	if( ((int64)-(LDTYPE$1 == RDTYPE$1) & (int64)-(LSUBTYPE$1 == RSUBTYPE$1)) == 0ll) goto label$698;
	{
		goto label$696;
	}
	label$698:;
	label$697:;
	char* OP$1;
	char* vr$3 = HGETCONVOPCODE( LDTYPE$1, RDTYPE$1 );
	OP$1 = vr$3;
	if( OP$1 != (char*)0ull) goto label$700;
	{
		goto label$696;
	}
	label$700:;
	label$699:;
	__builtin_memset( &TMP$532$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$532$1, (void*)OP$1, 0ll, (void*)" (", 3ll );
	__builtin_memset( &TMP$533$1, 0, 24ll );
	FBSTRING* vr$9 = fb_StrConcat( &TMP$533$1, (void*)vr$6, -1ll, (void*)RTYPE$1, -1ll );
	__builtin_memset( &TMP$534$1, 0, 24ll );
	FBSTRING* vr$12 = fb_StrConcat( &TMP$534$1, (void*)vr$9, -1ll, (void*)" ", 2ll );
	__builtin_memset( &TMP$535$1, 0, 24ll );
	FBSTRING* vr$15 = fb_StrConcat( &TMP$535$1, (void*)vr$12, -1ll, (void*)S$1, -1ll );
	__builtin_memset( &TMP$536$1, 0, 24ll );
	FBSTRING* vr$18 = fb_StrConcat( &TMP$536$1, (void*)vr$15, -1ll, (void*)" to ", 5ll );
	__builtin_memset( &TMP$537$1, 0, 24ll );
	FBSTRING* vr$21 = fb_StrConcat( &TMP$537$1, (void*)vr$18, -1ll, (void*)LTYPE$1, -1ll );
	__builtin_memset( &TMP$538$1, 0, 24ll );
	FBSTRING* vr$24 = fb_StrConcat( &TMP$538$1, (void*)vr$21, -1ll, (void*)")", 2ll );
	fb_StrAssign( (void*)S$1, -1ll, (void*)vr$24, -1ll, 0 );
	label$696:;
}

static void _EMITVARINIOFS( struct $8FBSYMBOL* SYM$1, struct $8FBSYMBOL* RHS$1, int64 OFS$1 )
{
	FBSTRING TMP$562$1;
	label$701:;
	HVARINIELEMENTTYPE( SYM$1 );
	FBSTRING S$1;
	char* vr$0 = SYMBGETMANGLEDNAME( RHS$1 );
	fb_StrInit( (void*)&S$1, -1ll, (void*)vr$0, 0ll, 0 );
	int64 SYMDTYPE$1;
	SYMDTYPE$1 = *(int64*)((uint8*)SYM$1 + 56ll) & 511ll;
	FBSTRING SYMTYPE$1;
	FBSTRING* vr$5 = HEMITTYPE( SYMDTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll) );
	fb_StrInit( (void*)&SYMTYPE$1, -1ll, (void*)vr$5, -1ll, 0 );
	int64 PTRDTYPE$1;
	PTRDTYPE$1 = ((((*(int64*)((uint8*)RHS$1 + 56ll) & 511ll) & 31ll) | (((*(int64*)((uint8*)RHS$1 + 56ll) & 511ll) & 480ll) + 32ll)) | (((*(int64*)((uint8*)RHS$1 + 56ll) & 511ll) & 261632ll) << (1ll & 63ll))) | ((*(int64*)((uint8*)RHS$1 + 56ll) & 511ll) & 32505856ll);
	FBSTRING PTRTYPE$1;
	FBSTRING* vr$25 = HEMITTYPE( PTRDTYPE$1, *(struct $8FBSYMBOL**)((uint8*)RHS$1 + 64ll) );
	fb_StrInit( (void*)&PTRTYPE$1, -1ll, (void*)vr$25, -1ll, 0 );
	if( OFS$1 == 0ll) goto label$704;
	{
		FBSTRING TMP$540$2;
		FBSTRING TMP$541$2;
		FBSTRING TMP$542$2;
		FBSTRING TMP$543$2;
		FBSTRING TMP$544$2;
		FBSTRING TMP$545$2;
		FBSTRING TMP$547$2;
		FBSTRING TMP$548$2;
		FBSTRING TMP$549$2;
		FBSTRING TMP$550$2;
		FBSTRING TMP$551$2;
		FBSTRING TMP$552$2;
		FBSTRING TMP$553$2;
		FBSTRING TMP$554$2;
		FBSTRING TMP$556$2;
		FBSTRING TMP$557$2;
		FBSTRING TMP$558$2;
		FBSTRING TMP$559$2;
		FBSTRING TMP$560$2;
		FBSTRING TMP$561$2;
		FBSTRING INTTYPE$2;
		FBSTRING* vr$27 = HEMITTYPE( 9ll, (struct $8FBSYMBOL*)0ull );
		fb_StrInit( (void*)&INTTYPE$2, -1ll, (void*)vr$27, -1ll, 0 );
		__builtin_memset( &TMP$540$2, 0, 24ll );
		FBSTRING* vr$34 = fb_StrConcat( &TMP$540$2, (void*)"ptrtoint (", 11ll, (void*)&PTRTYPE$1, -1ll );
		__builtin_memset( &TMP$541$2, 0, 24ll );
		FBSTRING* vr$37 = fb_StrConcat( &TMP$541$2, (void*)vr$34, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$542$2, 0, 24ll );
		FBSTRING* vr$40 = fb_StrConcat( &TMP$542$2, (void*)vr$37, -1ll, (void*)&S$1, -1ll );
		__builtin_memset( &TMP$543$2, 0, 24ll );
		FBSTRING* vr$43 = fb_StrConcat( &TMP$543$2, (void*)vr$40, -1ll, (void*)" to ", 5ll );
		__builtin_memset( &TMP$544$2, 0, 24ll );
		FBSTRING* vr$46 = fb_StrConcat( &TMP$544$2, (void*)vr$43, -1ll, (void*)&INTTYPE$2, -1ll );
		__builtin_memset( &TMP$545$2, 0, 24ll );
		FBSTRING* vr$49 = fb_StrConcat( &TMP$545$2, (void*)vr$46, -1ll, (void*)")", 2ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$49, -1ll, 0 );
		FBSTRING* vr$51 = fb_LongintToStr( OFS$1 );
		__builtin_memset( &TMP$547$2, 0, 24ll );
		FBSTRING* vr$57 = fb_StrConcat( &TMP$547$2, (void*)"add (", 6ll, (void*)&INTTYPE$2, -1ll );
		__builtin_memset( &TMP$548$2, 0, 24ll );
		FBSTRING* vr$60 = fb_StrConcat( &TMP$548$2, (void*)vr$57, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$549$2, 0, 24ll );
		FBSTRING* vr$63 = fb_StrConcat( &TMP$549$2, (void*)vr$60, -1ll, (void*)&S$1, -1ll );
		__builtin_memset( &TMP$550$2, 0, 24ll );
		FBSTRING* vr$66 = fb_StrConcat( &TMP$550$2, (void*)vr$63, -1ll, (void*)", ", 3ll );
		__builtin_memset( &TMP$551$2, 0, 24ll );
		FBSTRING* vr$69 = fb_StrConcat( &TMP$551$2, (void*)vr$66, -1ll, (void*)&INTTYPE$2, -1ll );
		__builtin_memset( &TMP$552$2, 0, 24ll );
		FBSTRING* vr$72 = fb_StrConcat( &TMP$552$2, (void*)vr$69, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$553$2, 0, 24ll );
		FBSTRING* vr$75 = fb_StrConcat( &TMP$553$2, (void*)vr$72, -1ll, (void*)vr$51, -1ll );
		__builtin_memset( &TMP$554$2, 0, 24ll );
		FBSTRING* vr$78 = fb_StrConcat( &TMP$554$2, (void*)vr$75, -1ll, (void*)")", 2ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$78, -1ll, 0 );
		__builtin_memset( &TMP$556$2, 0, 24ll );
		FBSTRING* vr$85 = fb_StrConcat( &TMP$556$2, (void*)"inttoptr (", 11ll, (void*)&INTTYPE$2, -1ll );
		__builtin_memset( &TMP$557$2, 0, 24ll );
		FBSTRING* vr$88 = fb_StrConcat( &TMP$557$2, (void*)vr$85, -1ll, (void*)" ", 2ll );
		__builtin_memset( &TMP$558$2, 0, 24ll );
		FBSTRING* vr$91 = fb_StrConcat( &TMP$558$2, (void*)vr$88, -1ll, (void*)&S$1, -1ll );
		__builtin_memset( &TMP$559$2, 0, 24ll );
		FBSTRING* vr$94 = fb_StrConcat( &TMP$559$2, (void*)vr$91, -1ll, (void*)" to ", 5ll );
		__builtin_memset( &TMP$560$2, 0, 24ll );
		FBSTRING* vr$97 = fb_StrConcat( &TMP$560$2, (void*)vr$94, -1ll, (void*)&PTRTYPE$1, -1ll );
		__builtin_memset( &TMP$561$2, 0, 24ll );
		FBSTRING* vr$100 = fb_StrConcat( &TMP$561$2, (void*)vr$97, -1ll, (void*)")", 2ll );
		fb_StrAssign( (void*)&S$1, -1ll, (void*)vr$100, -1ll, 0 );
		fb_StrDelete( (FBSTRING*)&INTTYPE$2 );
	}
	label$704:;
	label$703:;
	__builtin_memset( &TMP$562$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$562$1, -1ll, (void*)&PTRTYPE$1, -1ll, 0 );
	HMAYBEADDCONV( &S$1, SYMDTYPE$1, *(struct $8FBSYMBOL**)((uint8*)SYM$1 + 64ll), &SYMTYPE$1, PTRDTYPE$1, *(struct $8FBSYMBOL**)((uint8*)RHS$1 + 64ll), &TMP$562$1 );
	fb_StrDelete( (FBSTRING*)&TMP$562$1 );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)&S$1, -1ll, 0 );
	HVARINISEPARATOR(  );
	fb_StrDelete( (FBSTRING*)&PTRTYPE$1 );
	fb_StrDelete( (FBSTRING*)&SYMTYPE$1 );
	fb_StrDelete( (FBSTRING*)&S$1 );
	label$702:;
}

static void _EMITVARINISTR( int64 VARLENGTH$1, char* LITERAL$1, int64 LITLENGTH$1, int64 NOTERM$1 )
{
	int64 TMP$564$1;
	label$705:;
	if( *(int64*)((uint8*)&CTX$ + 40ll) <= 0ll) goto label$708;
	{
		FBSTRING* vr$0 = HEMITSTRLITTYPE( VARLENGTH$1 );
		fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$0, -1ll, 0 );
		fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" ", 2ll, 0 );
	}
	label$708:;
	label$707:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"c\x22", 3ll, 0 );
	TMP$564$1 = 0ll;
	char* vr$6 = HUNESCAPE( LITERAL$1, &TMP$564$1 );
	HBUILDSTRLIT( (FBSTRING*)((uint8*)&CTX$ + 16ll), VARLENGTH$1 + 1ll, vr$6, LITLENGTH$1 + 1ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"\x22", 2ll, 0 );
	HVARINISEPARATOR(  );
	label$706:;
}

static void _EMITVARINIWSTR( int64 VARLENGTH$1, uint32* LITERAL$1, int64 LITLENGTH$1 )
{
	int64 TMP$565$1;
	label$709:;
	if( *(int64*)((uint8*)&CTX$ + 40ll) <= 0ll) goto label$712;
	{
		FBSTRING* vr$0 = HEMITSTRLITTYPE( VARLENGTH$1 );
		fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$0, -1ll, 0 );
		fb_StrConcatAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" ", 2ll, 0 );
	}
	label$712:;
	label$711:;
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"c\x22", 3ll, 0 );
	TMP$565$1 = 0ll;
	uint32* vr$6 = HUNESCAPEW( LITERAL$1, &TMP$565$1 );
	HBUILDWSTRLIT( (FBSTRING*)((uint8*)&CTX$ + 16ll), VARLENGTH$1 + 1ll, vr$6, LITLENGTH$1 + 1ll );
	fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"\x22", 2ll, 0 );
	HVARINISEPARATOR(  );
	label$710:;
}

static void _EMITVARINIPAD( int64 BYTES$1, int64 FILLCHAR$1 )
{
	label$713:;
	label$714:;
}

static void _EMITVARINISCOPEBEGIN( struct $8FBSYMBOL* SYM$1, int64 IS_ARRAY$1 )
{
	label$715:;
	HVARINIELEMENTTYPE( SYM$1 );
	*(int64*)((uint8*)&CTX$ + 40ll) = *(int64*)((uint8*)&CTX$ + 40ll) + 1ll;
	if( *(int64*)((uint8*)&CTX$ + 40ll) < 128ll) goto label$718;
	{
		ERRREPORT( 21ll, 0ll, (char*)"global variable/array initializer nesting level too deep (MAXVARINISCOPES=128)" );
		*(int64*)((uint8*)&CTX$ + 40ll) = *(int64*)((uint8*)&CTX$ + 40ll) + -1ll;
	}
	label$718:;
	label$717:;
	*(int8*)((uint8*)((uint8*)&CTX$ + *(int64*)((uint8*)&CTX$ + 40ll)) + 48ll) = (int8)IS_ARRAY$1;
	if( IS_ARRAY$1 == 0ll) goto label$720;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"[ ", 3ll, 0 );
	}
	goto label$719;
	label$720:;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)"{ ", 3ll, 0 );
	}
	label$719:;
	label$716:;
}

static void _EMITVARINISCOPEEND( void )
{
	label$721:;
	FBSTRING* vr$1 = fb_RIGHT( (FBSTRING*)((uint8*)&CTX$ + 16ll), 2ll );
	int32 vr$2 = fb_StrCompare( (void*)vr$1, -1ll, (void*)", ", 3ll );
	if( (int64)vr$2 != 0ll) goto label$724;
	{
		int64 vr$5 = fb_StrLen( (void*)((uint8*)&CTX$ + 16ll), -1ll );
		FBSTRING* vr$8 = fb_LEFT( (FBSTRING*)((uint8*)&CTX$ + 16ll), vr$5 + -2ll );
		fb_StrAssign( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)vr$8, -1ll, 0 );
	}
	label$724:;
	label$723:;
	if( (int64)*(int8*)((uint8*)((uint8*)&CTX$ + *(int64*)((uint8*)&CTX$ + 40ll)) + 48ll) == 0ll) goto label$726;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" ]", 3ll, 0 );
	}
	goto label$725;
	label$726:;
	{
		fb_StrConcatByref( (void*)((uint8*)&CTX$ + 16ll), -1ll, (void*)" }", 3ll, 0 );
	}
	label$725:;
	if( *(int64*)((uint8*)&CTX$ + 40ll) <= 0ll) goto label$728;
	{
		*(int64*)((uint8*)&CTX$ + 40ll) = *(int64*)((uint8*)&CTX$ + 40ll) + -1ll;
	}
	label$728:;
	label$727:;
	HVARINISEPARATOR(  );
	label$722:;
}

static void _EMITFBCTINFBEGIN( void )
{
	FBSTRING TMP$572$1;
	label$729:;
	__builtin_memset( &TMP$572$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$572$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$572$1 );
	fb_StrDelete( (FBSTRING*)&TMP$572$1 );
	label$730:;
}

static void _EMITFBCTINFSTRING( char* S$1 )
{
	FBSTRING TMP$573$1;
	FBSTRING TMP$574$1;
	label$731:;
	__builtin_memset( &TMP$573$1, 0, 24ll );
	FBSTRING* vr$2 = fb_StrConcat( &TMP$573$1, (void*)S$1, 0ll, (void*)"\x5C" "00", 4ll );
	__builtin_memset( &TMP$574$1, 0, 24ll );
	FBSTRING* vr$6 = fb_StrConcat( &TMP$574$1, (void*)((uint8*)&CTX$ + 240ll), -1ll, (void*)vr$2, -1ll );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 240ll), -1ll, (void*)vr$6, -1ll, 0 );
	int64 vr$8 = fb_StrLen( (void*)S$1, 0ll );
	*(int64*)((uint8*)&CTX$ + 264ll) = (*(int64*)((uint8*)&CTX$ + 264ll) + vr$8) + 1ll;
	label$732:;
}

static void _EMITFBCTINFEND( void )
{
	label$733:;
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)"@__fbctinf = internal constant ", 32ll, 0 );
	FBSTRING* vr$2 = HEMITSTRLITTYPE( *(int64*)((uint8*)&CTX$ + 264ll) );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$2, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)" c\x22", 4ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)((uint8*)&CTX$ + 240ll), -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"\x22", 2ll, 0 );
	int64 vr$8 = FBGETOPTION( 3ll );
	if( vr$8 != 10ll) goto label$736;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", section \x22__DATA,fbctinf\x22", 27ll, 0 );
	}
	goto label$735;
	label$736:;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", section \x22.fbctinf\x22", 21ll, 0 );
	}
	label$735:;
	HWRITELINE( &LN$1 );
	fb_StrAssign( (void*)&LN$1, -1ll, (void*)"@llvm.used = appending global [1 x i8*] ", 41ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"[", 2ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"i8* bitcast (", 14ll, 0 );
	FBSTRING* vr$15 = HEMITSTRLITTYPE( *(int64*)((uint8*)&CTX$ + 264ll) );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$15, -1ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"* @__fbctinf to i8*)", 21ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"]", 2ll, 0 );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)", section \x22llvm.metadata\x22", 26ll, 0 );
	HWRITELINE( &LN$1 );
	fb_StrAssign( (void*)((uint8*)&CTX$ + 240ll), -1ll, (void*)"", 1ll, 0 );
	*(int64*)((uint8*)&CTX$ + 264ll) = 0ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$734:;
}

static void _EMITPROCBEGIN( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1 )
{
	FBSTRING TMP$586$1;
	FBSTRING TMP$591$1;
	label$737:;
	IRHLEMITPROCBEGIN(  );
	__builtin_memset( &TMP$586$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$586$1, -1ll, (void*)"", 1ll, 0 );
	HWRITELINE( &TMP$586$1 );
	fb_StrDelete( (FBSTRING*)&TMP$586$1 );
	FBSTRING LN$1;
	__builtin_memset( &LN$1, 0, 24ll );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"define ", 8ll, 0 );
	if( (*(int64*)((uint8*)PROC$1 + 8ll) & 256ll) == 0ll) goto label$740;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"dllexport ", 11ll, 0 );
	}
	goto label$739;
	label$740:;
	if( (*(int64*)((uint8*)PROC$1 + 8ll) & 64ll) == 0ll) goto label$741;
	{
		fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)"private ", 9ll, 0 );
	}
	label$741:;
	label$739:;
	FBSTRING* vr$12 = HEMITPROCHEADER( PROC$1, 0ll, 0ll );
	fb_StrConcatAssign( (void*)&LN$1, -1ll, (void*)vr$12, -1ll, 0 );
	HWRITELINE( &LN$1 );
	__builtin_memset( &TMP$591$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$591$1, -1ll, (void*)"{", 2ll, 0 );
	HWRITELINE( &TMP$591$1 );
	fb_StrDelete( (FBSTRING*)&TMP$591$1 );
	*(int64*)&CTX$ = *(int64*)&CTX$ + 1ll;
	fb_StrDelete( (FBSTRING*)&LN$1 );
	label$738:;
}

static void _EMITPROCEND( struct $8FBSYMBOL* PROC$1, struct $8FBSYMBOL* INITLABEL$1, struct $8FBSYMBOL* EXITLABEL$1 )
{
	FBSTRING TMP$595$1;
	label$742:;
	if( (*(int64*)((uint8*)PROC$1 + 56ll) & 511ll) != 0ll) goto label$745;
	{
		FBSTRING TMP$593$2;
		__builtin_memset( &TMP$593$2, 0, 24ll );
		fb_StrAssign( (void*)&TMP$593$2, -1ll, (void*)"ret void", 9ll, 0 );
		HWRITELINE( &TMP$593$2 );
		fb_StrDelete( (FBSTRING*)&TMP$593$2 );
	}
	label$745:;
	label$744:;
	*(int64*)&CTX$ = *(int64*)&CTX$ + -1ll;
	__builtin_memset( &TMP$595$1, 0, 24ll );
	fb_StrAssign( (void*)&TMP$595$1, -1ll, (void*)"}", 2ll, 0 );
	HWRITELINE( &TMP$595$1 );
	fb_StrDelete( (FBSTRING*)&TMP$595$1 );
	IRHLEMITPROCEND(  );
	label$743:;
}

static void _EMITSCOPEBEGIN( struct $8FBSYMBOL* S$1 )
{
	label$746:;
	label$747:;
}

static void _EMITSCOPEEND( struct $8FBSYMBOL* S$1 )
{
	label$748:;
	label$749:;
}

__attribute__(( constructor )) static void _GLOBAL__I( void )
{
	label$751:;
	_ZN13IRLLVMCONTEXTC1Ev( &CTX$ );
	label$752:;
}

__attribute__(( destructor )) static void _GLOBAL__D( void )
{
	label$754:;
	_ZN13IRLLVMCONTEXTD1Ev( &CTX$ );
	label$755:;
}
