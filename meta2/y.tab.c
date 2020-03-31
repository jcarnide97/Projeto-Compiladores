/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y" /* yacc.c:339  */

	/*
		Gonçalo Manuel Oliveira e Sousa			2016244072
		João Filipe Carnide de Jesus Nunes		2017247442
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>

	typedef enum {
		node_raiz,
		node_var, 
		node_metodos, 
		node_statements, 
		node_operators, 
		node_terminais, 
		node_id
	} node_type;

	typedef struct node * no;
	typedef struct node {
		char * valor;
		char * s_type;
		node_type type;
		int num_node;
		no pai;
		no filho;
		no irmao;
	} node;

	int conta;
	no raiz;
	no aux;
	int flag_erro = 0;
	extern int flag;

	int yylex(void);
    void yyerror(const char *s);
	int yylex_destroy();

	no cria_node(node_type type, char * valor, char * s_type) {
		no novo = malloc(sizeof(node));
		novo->s_type = (char *)malloc(1 + strlen(s_type) * sizeof(char));
		strcpy(novo->s_type, s_type);
		novo->valor = (char *)malloc(1 + strlen(valor) * sizeof(char));
		strcpy(novo->valor, valor);
		novo->type = type;
		novo->num_node = 0;
		novo->pai = NULL;
		novo->filho = NULL;
		novo->irmao = NULL;
		return novo;
	}

	void atribuir_tipo(no novo, char * type) {
		no aux = novo->irmao;
		while (aux != NULL) {
			aux = aux->irmao;
		}
		strcpy(aux->filho->s_type, type);
	}

	void adicionar_node(no pai, no novo) {
		if (novo == NULL) {
			return ;
		}
		pai->filho = novo;
		pai->num_node++;
		novo->pai = pai;
	}

	void adicionar_irmao(no node_a, no node_b) {
		if (node_a == NULL || node_b == NULL) {
			return ;
		}
		no aux;
		aux = node_a;
		while (aux->irmao != NULL) {
			aux = aux->irmao;
		}
		aux->irmao = node_b;
		if (node_a->pai != NULL) {
			node_b->pai = node_a->pai;
			node_b->pai->num_node++;
		}
	}

	int conta_filhos(no raiz){
		int conta = 0;
		no aux;
		aux = raiz;
		while (aux != NULL) {
			aux = aux->filho;
			conta++;
		}
		return conta;
	}

	int conta_irmaos(no raiz) {
		int conta = 0;
		no aux;
		aux = raiz;
		while (aux != NULL) {
			aux = aux->irmao;
			conta++;
		}
		return conta;
	}

	void arvore(no raiz, int pontos) {
		if (raiz == NULL) {
			return ;
		}
		int i = 0;
		no aux;
		if (raiz->type == node_raiz) {
			printf("%s\n", raiz->s_type);
		}
		else {
			while (i < pontos) {
				printf("..");
				i++;
			}
			if (strcmp(raiz->valor,"") != 0) {
				printf("%s(%s)\n", raiz->s_type, raiz->valor);
			}
			else {
				printf("%s\n", raiz->s_type);
			}
		}
		aux = raiz->filho;
		while (aux != NULL) {
			no aux_free = aux;
			arvore(aux, pontos+1);
			aux = aux->irmao;
			free(aux_free->valor);
			free(aux_free->s_type);
			free(aux_free);
		}
	}

#line 210 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ASSIGN = 259,
    STAR = 260,
    COMMA = 261,
    DIV = 262,
    EQ = 263,
    GE = 264,
    GT = 265,
    LBRACE = 266,
    LE = 267,
    LPAR = 268,
    LSQ = 269,
    LT = 270,
    MINUS = 271,
    MOD = 272,
    NE = 273,
    NOT = 274,
    OR = 275,
    PLUS = 276,
    RBRACE = 277,
    RPAR = 278,
    RSQ = 279,
    SEMICOLON = 280,
    ARROW = 281,
    LSHIFT = 282,
    RSHIFT = 283,
    XOR = 284,
    CLASS = 285,
    DOTLENGTH = 286,
    ELSE = 287,
    IF = 288,
    PRINT = 289,
    PARSEINT = 290,
    PUBLIC = 291,
    RETURN = 292,
    STATIC = 293,
    STRING = 294,
    VOID = 295,
    WHILE = 296,
    ID = 297,
    INTLIT = 298,
    REALLIT = 299,
    BOOLLIT = 300,
    STRLIT = 301,
    INT = 302,
    DOUBLE = 303,
    BOOL = 304,
    RESERVED = 305
  };
#endif
/* Tokens.  */
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define LBRACE 266
#define LE 267
#define LPAR 268
#define LSQ 269
#define LT 270
#define MINUS 271
#define MOD 272
#define NE 273
#define NOT 274
#define OR 275
#define PLUS 276
#define RBRACE 277
#define RPAR 278
#define RSQ 279
#define SEMICOLON 280
#define ARROW 281
#define LSHIFT 282
#define RSHIFT 283
#define XOR 284
#define CLASS 285
#define DOTLENGTH 286
#define ELSE 287
#define IF 288
#define PRINT 289
#define PARSEINT 290
#define PUBLIC 291
#define RETURN 292
#define STATIC 293
#define STRING 294
#define VOID 295
#define WHILE 296
#define ID 297
#define INTLIT 298
#define REALLIT 299
#define BOOLLIT 300
#define STRLIT 301
#define INT 302
#define DOUBLE 303
#define BOOL 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 145 "jucompiler.y" /* yacc.c:355  */

	char * id;
	struct node * node;

#line 355 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 372 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   180,   180,   186,   187,   189,   191,   194,   199,   214,
     217,   218,   222,   223,   224,   227,   233,   242,   243,   246,
     251,   257,   258,   265,   269,   270,   272,   281,   298,   299,
     303,   311,   323,   348,   358,   360,   361,   363,   366,   367,
     376,   377,   380,   381,   382,   383,   386,   387,   390,   394,
     398,   399,   403,   404,   413,   419,   423,   427,   428,   431,
     434,   437,   440,   443,   446,   449,   452,   455,   458,   461,
     464,   467,   470,   473,   476,   479,   481,   483,   485,   486,
     488,   489,   490,   492,   495,   496,   499,   500,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ASSIGN", "STAR", "COMMA", "DIV",
  "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD",
  "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ", "SEMICOLON", "ARROW",
  "LSHIFT", "RSHIFT", "XOR", "CLASS", "DOTLENGTH", "ELSE", "IF", "PRINT",
  "PARSEINT", "PUBLIC", "RETURN", "STATIC", "STRING", "VOID", "WHILE",
  "ID", "INTLIT", "REALLIT", "BOOLLIT", "STRLIT", "INT", "DOUBLE", "BOOL",
  "RESERVED", "$accept", "Program", "ProgramScript", "MethodDecl",
  "FieldDecl", "FieldDecl2", "Type", "MethodHeader", "MethodHeader2",
  "FormalParams", "FormalParams2", "MethodBody", "MethodBody2", "VarDecl",
  "VarDecl2", "Statement", "Statement2", "ExprReturn", "Statement3",
  "StatementPrint", "MethodInvocation", "MethodInvocation2",
  "MethodInvocationExpr", "Assignment", "ParseArgs", "Expr",
  "ExprOperations", "Expr2", "ExprLit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -30,     6,     4,   -37,    76,     8,    76,    -7,    18,
      76,    76,   -37,   -37,    23,   -37,   -37,   -37,    11,   -37,
     -37,   -37,    17,    39,    52,    45,    27,   -37,     7,    25,
       7,    53,    78,   146,    60,    92,    94,   203,    96,     1,
      69,    95,    27,    27,   108,   -37,   -37,   -37,   106,    93,
     113,   -37,   134,   119,   -37,   -37,   146,   127,   203,   191,
       2,   151,   236,   236,   236,    35,   -37,   -37,   -37,   125,
     -37,   -37,   -37,   -37,   279,   -37,   -37,   203,   203,   118,
     145,   -37,   -37,   -37,   -37,   132,   152,   -37,   -37,   -37,
     -37,   -37,   143,   -37,   150,   -37,   153,   155,   154,   159,
      -5,    40,   -37,    40,   -37,   -37,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   161,   -37,   162,   167,   168,   136,   166,   158,
      48,   -37,   164,   177,   -37,   203,   -37,   -37,   331,   -37,
     -37,   249,    97,    97,    97,    97,    40,   -37,   249,   306,
      40,   138,   138,   356,   164,   -37,   -37,   203,   -37,   145,
     -37,   -37,   169,   160,   -37,   179,   -37,   168,   -37,   152,
     164,   185,   -37,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     6,     0,     2,     4,     5,     0,    13,
      14,    12,     0,     0,     0,    10,     0,     7,    17,     0,
      17,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
       0,    18,    10,     0,     8,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    86,    87,    88,     0,
      84,    57,    85,    41,    58,    80,    83,     0,     0,     0,
      28,    23,    26,    25,    35,     0,    21,    16,    11,    15,
      39,    30,     0,    47,     0,    46,     0,     0,     0,     0,
      81,    76,    77,    75,    82,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    52,     0,     0,     0,
       0,    19,     0,     0,    56,     0,    79,    78,    64,    61,
      62,    69,    70,    71,    72,    73,    60,    63,    74,    65,
      59,    67,    68,    66,     0,    49,    48,     0,    51,    28,
      27,    20,     0,    31,    36,     0,    33,    52,    29,    21,
       0,     0,    53,    22,    32,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   116,   -37,   -37,   157,    -1,   -37,   183,   -37,
      46,   -37,    73,   -37,    55,   -32,   165,   -37,   -37,   -37,
     -26,   -37,    50,   -24,   -22,   -36,   -27,   -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     131,    27,    41,    42,   128,    43,    57,    69,    44,    94,
      70,   125,   158,    71,    72,    73,    74,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    46,    96,    47,    78,     4,    45,    79,    46,
       1,    47,     3,    22,    79,     5,    45,    45,    46,    46,
      47,    47,    92,    95,    56,    99,   104,    49,    32,    49,
      45,    14,    46,    12,    47,   101,   102,   103,    33,    78,
      15,   122,   123,   126,    97,   107,    48,   108,    79,   -24,
      26,    29,   -42,    24,    19,    20,    21,   115,    30,    25,
      34,    35,    36,    18,    37,    28,   104,    52,    38,    39,
      19,    20,    21,    58,    19,    20,    21,     6,    54,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    19,    20,    21,    -3,   165,
     163,     7,   107,    55,   108,    59,    45,    60,    46,    77,
      47,    80,     8,   114,   115,    82,    83,    81,   118,   124,
      85,   167,   166,    13,   119,   120,    16,    17,    45,   162,
      46,    61,    47,    84,    62,    86,    87,    63,   174,    64,
      29,   -50,    89,   107,    45,   108,    46,    32,    47,    91,
     105,   127,    98,    36,   114,   115,   129,    33,   130,   118,
      65,    66,    67,    68,    61,    32,   132,    62,   -38,   135,
      63,   -42,    64,   133,   157,    33,   134,   136,   159,    34,
      35,    36,   137,    37,   154,   155,    36,    38,    39,   -42,
     156,   160,   170,    65,    66,    67,    68,    34,    35,    36,
     161,    37,   164,   171,    61,    38,    39,    62,   175,    88,
      63,   169,    64,    53,   168,   173,    61,   172,     0,    62,
       0,    90,    63,     0,    64,     0,    36,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    93,    36,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    61,
       0,     0,    62,     0,   107,    63,   108,    64,   110,   111,
       0,   112,     0,     0,   113,   114,   115,     0,     0,     0,
     118,    36,     0,     0,     0,     0,   119,   120,   100,    66,
      67,    68,   106,     0,   107,     0,   108,   109,   110,   111,
       0,   112,     0,     0,   113,   114,   115,   116,     0,   117,
     118,     0,     0,     0,     0,     0,   119,   120,   121,   106,
       0,   107,     0,   108,   109,   110,   111,     0,   112,     0,
       0,   113,   114,   115,   116,     0,     0,   118,     0,     0,
       0,     0,     0,   119,   120,   121,   107,     0,   108,   109,
     110,   111,     0,   112,     0,     0,   113,   114,   115,   116,
       0,     0,   118,     0,     0,     0,     0,     0,   119,   120,
     121,   107,     0,   108,   109,   110,   111,     0,   112,     0,
       0,   113,   114,   115,   116,     0,     0,   118,     0,     0,
       0,     0,     0,   119,   120
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    26,     4,     0,    33,    13,    33,
      30,    33,    42,    14,    13,    11,    42,    43,    42,    43,
      42,    43,    58,    59,    56,    61,    31,    28,     1,    30,
      56,    38,    56,    25,    56,    62,    63,    64,    11,     4,
      22,    77,    78,    79,    42,     5,    39,     7,    13,    22,
      11,     6,    25,    42,    47,    48,    49,    17,    13,    42,
      33,    34,    35,    40,    37,    13,    31,    42,    41,    42,
      47,    48,    49,    13,    47,    48,    49,     1,    25,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    47,    48,    49,    22,   135,
     132,    25,     5,    25,     7,    13,   132,    13,   132,    13,
     132,    42,    36,    16,    17,    42,    43,    22,    21,     1,
      14,   157,   154,     7,    27,    28,    10,    11,   154,   130,
     154,    13,   154,    25,    16,    42,    23,    19,   170,    21,
       6,    23,    23,     5,   170,     7,   170,     1,   170,    22,
      25,     6,     1,    35,    16,    17,    24,    11,     6,    21,
      42,    43,    44,    45,    13,     1,    23,    16,    22,    14,
      19,    25,    21,    23,     6,    11,    23,    23,    42,    33,
      34,    35,    23,    37,    23,    23,    35,    41,    42,    25,
      23,    25,    32,    42,    43,    44,    45,    33,    34,    35,
      42,    37,    25,    24,    13,    41,    42,    16,    23,    52,
      19,    42,    21,    30,   159,   169,    13,   167,    -1,    16,
      -1,    56,    19,    -1,    21,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    13,
      -1,    -1,    16,    -1,     5,    19,     7,    21,     9,    10,
      -1,    12,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      21,    35,    -1,    -1,    -1,    -1,    27,    28,    42,    43,
      44,    45,     3,    -1,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,     3,
      -1,     5,    -1,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,     5,    -1,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,     5,    -1,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    52,    42,     0,    11,     1,    25,    36,    53,
      54,    55,    25,    53,    38,    22,    53,    53,    40,    47,
      48,    49,    57,    58,    42,    42,    11,    62,    13,     6,
      13,    56,     1,    11,    33,    34,    35,    37,    41,    42,
      57,    63,    64,    66,    69,    71,    74,    75,    39,    57,
      59,    60,    42,    59,    25,    25,    66,    67,    13,    13,
      13,    13,    16,    19,    21,    42,    43,    44,    45,    68,
      71,    74,    75,    76,    77,    78,    79,    13,     4,    13,
      42,    22,    63,    63,    25,    14,    42,    23,    56,    23,
      67,    22,    76,    46,    70,    76,     1,    42,     1,    76,
      42,    77,    77,    77,    31,    25,     3,     5,     7,     8,
       9,    10,    12,    15,    16,    17,    18,    20,    21,    27,
      28,    29,    76,    76,     1,    72,    76,     6,    65,    24,
       6,    61,    23,    23,    23,    14,    23,    23,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    23,    23,    23,     6,    73,    42,
      25,    42,    57,    66,    25,    76,    66,    76,    65,    42,
      32,    24,    73,    61,    66,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     2,
       0,     3,     1,     1,     1,     5,     5,     0,     1,     3,
       4,     0,     4,     3,     0,     2,     2,     4,     0,     3,
       3,     5,     7,     5,     3,     2,     5,     2,     0,     2,
       0,     1,     0,     1,     1,     1,     1,     1,     4,     4,
       0,     2,     0,     3,     3,     7,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 180 "jucompiler.y" /* yacc.c:1646  */
    {raiz = cria_node(node_raiz, "", "Program");
																	aux = cria_node(node_id, (yyvsp[-3].id), "Id");
																	adicionar_node(raiz, aux);
																	(yyval.node) = raiz;}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 186 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 187 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 189 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 191 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "MethodDecl");
																	adicionar_node((yyval.node), (yyvsp[-1].node));
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 199 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_var, "", "FieldDecl");
																	adicionar_node((yyval.node), (yyvsp[-3].node));
																	adicionar_irmao((yyvsp[-3].node), cria_node(node_id, (yyvsp[-2].id), "Id"));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			no aux1 = cria_node(node_var, "", "FieldDecl");
																			no aux2 = cria_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->valor, (yyvsp[-3].node)->s_type);
																			adicionar_node(aux1, aux2);
																			adicionar_irmao(aux2, cria_node(node_id, aux->valor, "Id"));
																			adicionar_irmao((yyval.node), aux1);
																			aux = aux->irmao;
																		}
																		free(aux);
																	}}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 214 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; flag_erro = 1;}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 217 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 218 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 222 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, "", "Bool");}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 223 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, "", "Int");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 224 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, "", "Double");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 227 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "MethodHeader");
																	adicionar_node((yyval.node),(yyvsp[-4].node));
																	adicionar_irmao((yyvsp[-4].node), cria_node(node_id, (yyvsp[-3].id), "Id"));
																	aux = cria_node(node_metodos, "", "MethodParams");
																	adicionar_irmao((yyvsp[-4].node), aux);
																	adicionar_node(aux, (yyvsp[-1].node));}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 233 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "MethodHeader");
																	aux = cria_node(node_terminais, "", "Void");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, cria_node(node_id, (yyvsp[-3].id), "Id"));
																	no aux2 = cria_node(node_metodos, "", "MethodParams");
																	adicionar_irmao(aux, aux2);
																	adicionar_node(aux2, (yyvsp[-1].node));}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 242 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 243 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 246 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	aux = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyvsp[-2].node), aux);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 251 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	aux = cria_node(node_metodos, "", "StringArray");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, cria_node(node_id, (yyvsp[0].id), "Id"));}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 257 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 258 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "ParamDecl");
																	aux = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), aux);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 265 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "MethodBody");
																	adicionar_node((yyval.node), (yyvsp[-1].node));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 269 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 270 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 272 "jucompiler.y" /* yacc.c:1646  */
    {if ((yyvsp[-1].node) != NULL){
																		(yyval.node) = (yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																		}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 281 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_metodos, "", "VarDecl");
																	adicionar_node((yyval.node), (yyvsp[-3].node));
																	adicionar_irmao((yyvsp[-3].node), cria_node(node_id, (yyvsp[-2].id), "Id"));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			no aux1 = cria_node(node_metodos, "", "VarDecl");
																			no aux2 = cria_node((yyvsp[-3].node)->type, (yyvsp[-3].node)->valor, (yyvsp[-3].node)->s_type);
																			adicionar_node(aux1, aux2);
																			adicionar_irmao(aux2, cria_node(node_id, aux->valor, "Id"));
																			adicionar_irmao((yyval.node), aux1);
																			aux = aux->irmao;
																		}
																		free(aux);
																	}}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 298 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 299 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_id, (yyvsp[-1].id), "Id");
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 303 "jucompiler.y" /* yacc.c:1646  */
    {if (conta_irmaos((yyvsp[-1].node)) > 1) {
																		aux = cria_node(node_statements, "", "Block");
																		(yyval.node) = aux;
																		adicionar_node(aux, (yyvsp[-1].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[-1].node);
																	}}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 311 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_statements, "", "If");
																	adicionar_node((yyval.node),(yyvsp[-2].node));
																	aux = cria_node(node_statements, "", "Block");
																	if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																		adicionar_irmao((yyvsp[0].node), aux);
																	}
																	else {
																		adicionar_irmao((yyvsp[-2].node), aux);
																		adicionar_node(aux, (yyvsp[0].node));
																		adicionar_irmao(aux, cria_node(node_statements, "", "Block"));
																	}}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 323 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_statements, "", "If");
																	adicionar_node((yyval.node),(yyvsp[-4].node));
																	aux = cria_node(node_statements, "", "Block");
																	if (conta_irmaos((yyvsp[-2].node)) == 1 && (yyvsp[-2].node) != NULL) {
																		adicionar_irmao((yyvsp[-4].node), (yyvsp[-2].node));
																		if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																		}
																		else {
																			adicionar_irmao((yyvsp[-2].node), aux);
																			adicionar_node(aux, (yyvsp[0].node));
																		}
																	}
																	else {
																		adicionar_irmao((yyvsp[-4].node), aux);
																		adicionar_node(aux, (yyvsp[-2].node));
																		if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			adicionar_irmao(aux, (yyvsp[0].node));
																		}
																		else {
																			no aux2 = cria_node(node_statements, "", "Block");
																			adicionar_irmao(aux, aux2);
																			adicionar_node(aux2, (yyvsp[0].node));
																		}
																	}}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 348 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_statements, "", "While");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	if (conta_irmaos((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));
																	}
																	else {
																		aux = cria_node(node_statements, "", "Block");
																		adicionar_irmao((yyvsp[-2].node), aux);
																		adicionar_node(aux, (yyvsp[0].node));
																	}}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 358 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_statements, "", "Return");
																	adicionar_node((yyval.node), (yyvsp[-1].node));}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 360 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 361 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_statements, "", "Print");
																	adicionar_node((yyval.node), (yyvsp[-2].node));}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 363 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL; flag_erro = 1;}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 366 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 367 "jucompiler.y" /* yacc.c:1646  */
    {if ((yyvsp[-1].node) != NULL) {
																		(yyval.node) = (yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 376 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 377 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 380 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 381 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 382 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 383 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 386 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 387 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "StrLit");}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 390 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Call");
																	aux = cria_node(node_id, (yyvsp[-3].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[-1].node));}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 394 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 398 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 399 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
																	adicionar_irmao((yyval.node), (yyvsp[0].node));}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 403 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 404 "jucompiler.y" /* yacc.c:1646  */
    {if((yyvsp[-1].node)!=NULL) {
																		(yyval.node)=(yyvsp[-1].node);
																		adicionar_irmao((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node)=(yyvsp[-1].node);
																	}}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 413 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Assign");
																	aux = cria_node(node_id, (yyvsp[-2].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[0].node));}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 419 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "ParseArgs");
																	aux = cria_node(node_id, (yyvsp[-4].id), "Id");
																	adicionar_node((yyval.node), aux);
																	adicionar_irmao(aux, (yyvsp[-2].node));}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 423 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 427 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 428 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 431 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Add");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Sub");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 437 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Mul");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 440 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Div");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 443 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Mod");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 446 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "And");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 449 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Or");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 452 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Xor");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 455 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Lshift");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 458 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Rshift");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 461 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Eq");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 464 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Ge");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 467 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Gt");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 470 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Le");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 473 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Lt");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 476 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Ne");
																	adicionar_node((yyval.node), (yyvsp[-2].node));
																	adicionar_irmao((yyvsp[-2].node), (yyvsp[0].node));}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 479 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Plus");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 481 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Minus");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 483 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Not");
																	adicionar_node((yyval.node), (yyvsp[0].node));}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 485 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 486 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 488 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 489 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_id, "", "Id");}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 490 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_operators, "", "Length");
																	adicionar_node((yyval.node), cria_node(node_id, "", "Id"));}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 492 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 495 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 496 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 499 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "IntLit");}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 500 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "RealLit");}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 501 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = cria_node(node_terminais, (yyvsp[0].id), "BollLit");}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2314 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 504 "jucompiler.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1], "-l") == 0) {
			flag = 1;
			yylex();
		}
		else if (strcmp(argv[1],"-t") == 0) {
			flag = 2;
			yyparse();
			yylex_destroy();
			if (!flag_erro) {
				arvore(raiz, 0);
			}
		}
		else if (strcmp(argv[1], "-e1") == 0) {
			flag = 0;
			yylex();
		}
		else if (strcmp(argv[1], "-e2") == 0) {
			flag = 0;
			flag_erro = 1;
			yyparse();
			yylex();
		}
	}
	else {
		flag = 0;
		flag_erro = 1;
		yyparse();
		yylex();
	}
}
