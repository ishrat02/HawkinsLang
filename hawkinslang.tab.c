
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "hawkinslang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External declarations from lexer
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;

void yyerror(const char *s);

// Symbol table for semantic analysis
typedef struct Symbol {
    char name[100];
    char type[50];
    int line_declared;
    struct Symbol *next;
} Symbol;

Symbol *symbol_table = NULL;

// Function to add symbol to table
void add_symbol(const char *name, const char *type, int line) {
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    strcpy(sym->name, name);
    strcpy(sym->type, type);
    sym->line_declared = line;
    sym->next = symbol_table;
    symbol_table = sym;
    printf("✓ Symbol added: %s (type: %s, line: %d)\n", name, type, line);
}

// Function to lookup symbol
Symbol* lookup_symbol(const char *name) {
    Symbol *sym = symbol_table;
    while (sym != NULL) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

int syntax_errors = 0;


/* Line 189 of yacc.c  */
#line 123 "hawkinslang.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     INTEGER_LITERAL = 260,
     FLOAT_LITERAL = 261,
     HAWKINS = 262,
     PORTAL = 263,
     ELEVEN = 264,
     SIGNAL = 265,
     FULL_SIGNAL = 266,
     LETTER = 267,
     THE_VOID = 268,
     NOTHING = 269,
     PRIMARY_GATE = 270,
     SECONDARY_GATE = 271,
     TAKE_COVER = 272,
     CHOOSE_GATE = 273,
     GATE_CASE = 274,
     FALLBACK = 275,
     COUNTDOWN = 276,
     CLOCK_CHIME = 277,
     INVADE = 278,
     ESCAPE = 279,
     SLIP = 280,
     HIVE = 281,
     THE_BRIDGE = 282,
     MR_WHATSIT = 283,
     CODENAME = 284,
     RADIO_OUT = 285,
     RADIO_IN = 286,
     DANGERIF_ALL_OPEN = 287,
     THREATIF_ANY_OPEN = 288,
     UPSIDE_DOWN = 289,
     FRIENDSDONTLIE = 290,
     LIES = 291,
     SEALED = 292,
     UNSTABLE = 293,
     ROOTED = 294,
     THE_ABYSS = 295,
     GAUGE = 296,
     SUMMONED = 297,
     SHUTDOWN = 298,
     TO_REAL_WORLD = 299,
     LIBRARY_IMPORT = 300,
     MACRO_DEF = 301,
     PLUS = 302,
     MINUS = 303,
     MULTIPLY = 304,
     DIVIDE = 305,
     MODULO = 306,
     ASSIGN = 307,
     PLUS_ASSIGN = 308,
     MINUS_ASSIGN = 309,
     MULT_ASSIGN = 310,
     DIV_ASSIGN = 311,
     MOD_ASSIGN = 312,
     EQ = 313,
     NE = 314,
     LT = 315,
     GT = 316,
     LE = 317,
     GE = 318,
     INCREMENT = 319,
     DECREMENT = 320,
     BITWISE_AND = 321,
     BITWISE_OR = 322,
     BITWISE_XOR = 323,
     BITWISE_NOT = 324,
     LEFT_SHIFT = 325,
     RIGHT_SHIFT = 326,
     ARROW = 327,
     DOT = 328,
     SEMICOLON = 329,
     COMMA = 330,
     COLON = 331,
     LPAREN = 332,
     RPAREN = 333,
     LBRACE = 334,
     RBRACE = 335,
     LBRACKET = 336,
     RBRACKET = 337
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 50 "hawkinslang.y"

    int ival;
    float fval;
    char *sval;



/* Line 214 of yacc.c  */
#line 249 "hawkinslang.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 261 "hawkinslang.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  313

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   337

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    29,    33,    35,    37,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    62,
      64,    69,    71,    75,    77,    81,    86,    95,    97,   101,
     109,   116,   124,   131,   137,   139,   143,   146,   148,   155,
     157,   160,   164,   171,   176,   183,   185,   189,   193,   199,
     202,   206,   208,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   230,   236,   244,   255,   268,   276,   278,   281,
     286,   290,   292,   294,   301,   309,   315,   323,   326,   329,
     332,   336,   340,   346,   349,   355,   361,   363,   367,   369,
     373,   375,   377,   379,   381,   383,   385,   387,   391,   393,
     397,   399,   403,   405,   409,   411,   415,   417,   421,   425,
     427,   431,   435,   439,   443,   445,   449,   453,   455,   459,
     463,   465,   469,   473,   477,   479,   482,   485,   488,   493,
     498,   500,   502,   504,   506,   508,   510,   512,   517,   521,
     526,   530,   534,   537,   540,   542,   544,   546,   548,   550,
     552,   554,   558,   560
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      84,     0,    -1,    85,    -1,    86,    -1,    85,    86,    -1,
      97,    -1,    96,    -1,    92,    -1,    87,    -1,   100,    -1,
     103,    -1,   104,    -1,   105,    -1,    45,    88,    -1,    46,
       3,   118,    -1,     4,    -1,     3,    -1,    60,     3,    61,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,     3,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    -1,    90,    -1,    91,    89,    93,    74,    -1,    94,
      -1,    93,    75,    94,    -1,     3,    -1,     3,    52,   118,
      -1,     3,    81,     5,    82,    -1,     3,    81,     5,    82,
      52,    79,    95,    80,    -1,   118,    -1,    95,    75,   118,
      -1,    89,     8,     3,    77,    98,    78,    74,    -1,    89,
       8,     3,    77,    78,    74,    -1,    89,     8,     3,    77,
      98,    78,   107,    -1,    89,     8,     3,    77,    78,   107,
      -1,    13,     7,    77,    78,   107,    -1,    99,    -1,    98,
      75,    99,    -1,    89,     3,    -1,    89,    -1,    26,     3,
      79,   101,    80,    74,    -1,   102,    -1,   101,   102,    -1,
      89,    93,    74,    -1,    27,     3,    79,   101,    80,    74,
      -1,    28,    89,     3,    74,    -1,    29,     3,    79,   106,
      80,    74,    -1,     3,    -1,     3,    52,     5,    -1,   106,
      75,     3,    -1,   106,    75,     3,    52,     5,    -1,    79,
      80,    -1,    79,   108,    80,    -1,   109,    -1,   108,   109,
      -1,   110,    -1,   107,    -1,   111,    -1,   115,    -1,   116,
      -1,    92,    -1,   117,    -1,    74,    -1,   118,    74,    -1,
      15,    77,   118,    78,   109,    -1,    15,    77,   118,    78,
     109,    17,   109,    -1,    15,    77,   118,    78,   109,    16,
      77,   118,    78,   109,    -1,    15,    77,   118,    78,   109,
      16,    77,   118,    78,   109,    17,   109,    -1,    18,    77,
     118,    78,    79,   112,    80,    -1,   113,    -1,   112,   113,
      -1,    19,   114,    76,   108,    -1,    20,    76,   108,    -1,
       5,    -1,     3,    -1,    21,    77,   110,   110,    78,   109,
      -1,    21,    77,   110,   110,   118,    78,   109,    -1,    22,
      77,   118,    78,   109,    -1,    23,   109,    22,    77,   118,
      78,    74,    -1,    24,    74,    -1,    25,    74,    -1,    44,
      74,    -1,    44,   118,    74,    -1,    42,     3,    74,    -1,
      43,    77,   118,    78,    74,    -1,     3,    76,    -1,    30,
      77,   135,    78,    74,    -1,    31,    77,   135,    78,    74,
      -1,   119,    -1,   118,    75,   119,    -1,   121,    -1,   131,
     120,   119,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,   122,    -1,   121,    33,   122,
      -1,   123,    -1,   122,    32,   123,    -1,   124,    -1,   123,
      67,   124,    -1,   125,    -1,   124,    68,   125,    -1,   126,
      -1,   125,    66,   126,    -1,   127,    -1,   126,    58,   127,
      -1,   126,    59,   127,    -1,   128,    -1,   127,    60,   128,
      -1,   127,    61,   128,    -1,   127,    62,   128,    -1,   127,
      63,   128,    -1,   129,    -1,   128,    70,   129,    -1,   128,
      71,   129,    -1,   130,    -1,   129,    47,   130,    -1,   129,
      48,   130,    -1,   131,    -1,   130,    49,   131,    -1,   130,
      50,   131,    -1,   130,    51,   131,    -1,   133,    -1,    64,
     131,    -1,    65,   131,    -1,   132,   131,    -1,    41,    77,
      89,    78,    -1,    41,    77,   131,    78,    -1,    47,    -1,
      48,    -1,    34,    -1,    69,    -1,    49,    -1,    66,    -1,
     134,    -1,   133,    81,   118,    82,    -1,   133,    77,    78,
      -1,   133,    77,   135,    78,    -1,   133,    73,     3,    -1,
     133,    72,     3,    -1,   133,    64,    -1,   133,    65,    -1,
       3,    -1,     5,    -1,     6,    -1,     4,    -1,    35,    -1,
      36,    -1,    14,    -1,    77,   118,    78,    -1,   119,    -1,
     135,    75,   119,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   120,   121,   125,   126,   127,   128,   129,
     130,   131,   132,   137,   139,   144,   145,   146,   151,   152,
     153,   154,   155,   156,   160,   161,   162,   163,   166,   168,
     173,   178,   179,   183,   185,   187,   189,   194,   195,   200,
     205,   213,   218,   223,   231,   232,   236,   238,   243,   251,
     252,   256,   261,   270,   279,   287,   288,   289,   290,   295,
     297,   302,   303,   307,   308,   309,   310,   311,   312,   313,
     317,   318,   323,   325,   327,   329,   331,   336,   337,   341,
     342,   346,   347,   352,   354,   356,   358,   364,   366,   368,
     370,   372,   374,   376,   382,   384,   390,   391,   395,   396,
     400,   401,   402,   403,   404,   405,   409,   410,   414,   415,
     419,   420,   424,   425,   429,   430,   434,   435,   436,   440,
     441,   442,   443,   444,   448,   449,   450,   454,   455,   456,
     460,   461,   462,   463,   467,   468,   469,   470,   471,   472,
     476,   477,   478,   479,   480,   481,   485,   486,   487,   489,
     491,   492,   493,   494,   498,   505,   506,   507,   508,   509,
     510,   511,   515,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "HAWKINS", "PORTAL", "ELEVEN",
  "SIGNAL", "FULL_SIGNAL", "LETTER", "THE_VOID", "NOTHING", "PRIMARY_GATE",
  "SECONDARY_GATE", "TAKE_COVER", "CHOOSE_GATE", "GATE_CASE", "FALLBACK",
  "COUNTDOWN", "CLOCK_CHIME", "INVADE", "ESCAPE", "SLIP", "HIVE",
  "THE_BRIDGE", "MR_WHATSIT", "CODENAME", "RADIO_OUT", "RADIO_IN",
  "DANGERIF_ALL_OPEN", "THREATIF_ANY_OPEN", "UPSIDE_DOWN",
  "FRIENDSDONTLIE", "LIES", "SEALED", "UNSTABLE", "ROOTED", "THE_ABYSS",
  "GAUGE", "SUMMONED", "SHUTDOWN", "TO_REAL_WORLD", "LIBRARY_IMPORT",
  "MACRO_DEF", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "EQ", "NE", "LT", "GT", "LE", "GE", "INCREMENT", "DECREMENT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "ARROW", "DOT", "SEMICOLON", "COMMA", "COLON", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "$accept",
  "program", "translation_unit", "external_declaration",
  "preprocessor_directive", "string_or_identifier", "type_specifier",
  "storage_class_specifier", "optional_storage_class",
  "variable_declaration", "declarator_list", "declarator",
  "initializer_list", "function_declaration", "function_definition",
  "parameter_list", "parameter_declaration", "struct_declaration",
  "struct_member_list", "struct_member", "union_declaration",
  "typedef_declaration", "enum_declaration", "enumerator_list",
  "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "switch_case_list",
  "switch_case", "constant_expression", "iteration_statement",
  "jump_statement", "io_statement", "expression", "assignment_expression",
  "assignment_operator", "logical_or_expression", "logical_and_expression",
  "bitwise_or_expression", "bitwise_xor_expression",
  "bitwise_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "argument_expression_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   102,   103,   104,   105,   106,   106,   106,   106,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   126,   126,   126,   127,
     127,   127,   127,   127,   128,   128,   128,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   135
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       4,     1,     3,     1,     3,     4,     8,     1,     3,     7,
       6,     7,     6,     5,     1,     3,     2,     1,     6,     1,
       2,     3,     6,     4,     6,     1,     3,     3,     5,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     7,    10,    12,     7,     1,     2,     4,
       3,     1,     1,     6,     7,     5,     7,     2,     2,     2,
       3,     3,     5,     2,     5,     5,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    18,    19,    20,    21,    22,     0,     0,     0,
       0,    24,    25,    26,    27,     0,     0,     0,     2,     3,
       8,     0,    29,     0,     7,     6,     5,     9,    10,    11,
      12,     0,     0,     0,    22,     0,     0,    16,    15,     0,
      13,     0,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   157,   155,   156,   160,   142,   158,   159,
       0,   140,   141,   144,     0,     0,   145,   143,     0,    14,
      96,    98,   106,   108,   110,   112,   114,   116,   119,   124,
     127,   130,     0,   134,   146,     0,    33,     0,    31,     0,
       0,     0,    49,     0,    53,    55,     0,    17,     0,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,   137,   152,
     153,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      28,    43,     0,     0,    50,     0,     0,     0,     0,   154,
       0,     0,   161,    97,   107,   130,   109,   111,   113,   115,
     117,   118,   120,   121,   122,   123,   125,   126,   128,   129,
     131,   132,   133,    99,   151,   150,   148,   162,     0,     0,
       0,    47,     0,    44,    34,     0,    32,   154,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
      70,    59,    68,    64,    28,    61,    63,    65,    66,    67,
      69,     0,    51,    48,    52,    56,    57,    54,   138,   139,
       0,   149,   147,    40,    42,    46,     0,     0,    35,    93,
       0,     0,     0,     0,     0,    87,    88,     0,     0,     0,
       0,    89,     0,    60,    62,    71,     0,   163,    45,    39,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,    90,    58,     0,    28,     0,     0,    28,     0,     0,
       0,     0,     0,    37,    72,     0,    28,     0,    85,     0,
      94,    95,    92,     0,    36,     0,    28,     0,     0,     0,
      77,    83,    28,     0,    38,     0,    73,    82,    81,     0,
      28,    76,    78,    84,    86,     0,    28,    28,    28,    28,
      74,    28,    75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    40,    90,    22,    23,   202,
      87,    88,   272,    25,    26,   182,   183,    27,    91,    92,
      28,    29,    30,    96,   203,   204,   205,   206,   207,   289,
     290,   299,   208,   209,   210,   211,    70,   127,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   178
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -284
static const yytype_int16 yypact[] =
{
     786,  -284,  -284,  -284,  -284,  -284,     7,    19,    25,    71,
      32,  -284,  -284,  -284,  -284,     5,    68,    94,   786,  -284,
    -284,   123,  -284,    71,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,    61,    78,   109,  -284,   133,   128,  -284,  -284,   143,
    -284,   693,  -284,  -284,   178,   188,    24,    71,    71,   140,
     199,   158,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
     144,  -284,  -284,  -284,   693,   693,  -284,  -284,   693,   145,
    -284,   190,   192,   159,   165,   168,    27,    44,    85,   114,
      66,    57,   693,    -4,  -284,   160,   -48,   100,  -284,   156,
     188,    28,  -284,    41,  -284,   186,   -62,  -284,   560,  -284,
    -284,   -32,   693,   693,   693,   693,   693,   693,   693,   693,
     693,   693,   693,   693,   693,   693,   693,   693,   693,   693,
     693,  -284,  -284,  -284,  -284,  -284,  -284,   693,  -284,  -284,
    -284,   233,   236,   474,   693,    46,   693,   238,  -284,   188,
     293,  -284,   110,   179,  -284,   181,   247,   255,   197,   194,
     198,   200,  -284,  -284,   192,  -284,   159,   165,   168,    27,
      44,    44,    85,    85,    85,    85,   114,   114,    66,    66,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,   -30,   -63,
     -53,   256,   -12,  -284,   145,   195,  -284,   203,   204,   205,
     206,   207,   427,   211,   212,   210,   216,   277,   217,   599,
    -284,  -284,  -284,  -284,   360,  -284,  -284,  -284,  -284,  -284,
    -284,   112,  -284,  -284,  -284,  -284,   237,  -284,  -284,  -284,
     693,  -284,  -284,  -284,  -284,  -284,    71,   -50,   249,  -284,
     693,   693,   646,   693,   266,  -284,  -284,   693,   693,   228,
     693,  -284,   122,  -284,  -284,  -284,   299,  -284,  -284,  -284,
    -284,   230,     1,    21,   646,    23,   235,    50,    51,  -284,
      52,  -284,  -284,   693,   427,   231,   513,   427,   693,   239,
     245,   246,   -33,   145,   184,   185,   427,    67,  -284,   104,
    -284,  -284,  -284,   693,  -284,   244,   427,    59,   250,   -13,
    -284,  -284,   427,   248,   145,   693,  -284,  -284,  -284,   262,
     427,  -284,  -284,  -284,  -284,   105,   427,   129,   427,   226,
     308,   427,  -284
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -284,  -284,  -284,   321,  -284,  -284,     2,  -284,  -284,    16,
     253,   208,  -284,  -284,  -284,  -284,   118,  -284,   297,   -21,
    -284,  -284,  -284,  -284,   -88,  -283,  -189,  -222,  -284,  -284,
      60,  -284,  -284,  -284,  -284,   -41,   -97,  -284,  -284,   243,
     251,   263,   242,   254,   102,   -22,    98,    99,   668,  -284,
    -284,  -284,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -81
static const yytype_int16 yytable[] =
{
      69,   141,    21,   234,   136,   153,   287,   288,    37,    38,
     254,    35,   102,   147,    31,   244,    24,   307,   148,   222,
      21,   223,    32,   309,   249,    45,   140,   101,    33,   140,
     173,     1,   266,   137,    24,    36,   177,     2,     3,     4,
       5,    34,   283,   102,     1,   220,   152,   284,   221,     1,
       2,     3,     4,     5,    34,     2,     3,     4,     5,    34,
     129,   130,   297,   226,   298,    39,   227,   301,   131,   132,
     144,    41,   144,   133,     1,   274,   102,   134,   278,   264,
       2,     3,     4,     5,    34,   108,   109,   291,   162,   163,
     164,   165,   224,   179,    42,   184,   102,   296,   102,   265,
     150,   267,    89,   303,   110,   111,   112,   113,   143,   121,
     122,   123,   124,   125,   126,   118,   119,   120,   244,   310,
     244,   145,   312,   247,   180,   220,   220,   102,   269,   270,
     271,    44,   187,    53,    54,    55,    49,   181,    46,   250,
     177,   177,   102,    56,   188,   292,    51,   189,   -80,   -80,
     190,   191,   192,   193,   194,   114,   115,    47,   242,   195,
     196,   116,   117,    57,    58,    59,    11,    12,    13,    14,
      60,   197,   198,   199,   138,   139,    61,    62,    63,   102,
     102,    85,   293,   308,   212,   139,   245,   102,    48,   252,
     253,    86,   255,    64,    65,    66,   261,   102,    67,   260,
     285,   286,    95,   200,   287,   288,    68,    50,   140,   -80,
     160,   161,   166,   167,    94,   168,   169,   257,   258,    97,
     102,    98,   273,   103,   104,   277,   105,   279,   181,   187,
      53,    54,    55,   106,   107,   140,   174,   135,   146,   175,
      56,   188,   294,   185,   189,   -79,   -79,   190,   191,   192,
     193,   194,   215,   213,   305,   214,   195,   196,   216,   225,
      57,    58,    59,    11,    12,    13,    14,    60,   197,   198,
     199,   217,   -23,    61,    62,    63,   218,   228,   219,   229,
     239,   230,   231,   232,   233,   235,   236,   237,   256,   246,
      64,    65,    66,   238,   240,    67,   187,    53,    54,    55,
     200,   251,   259,    68,   262,   140,   -79,    56,   188,   263,
     275,   189,   268,   280,   190,   191,   192,   193,   194,   281,
     282,   295,   304,   195,   196,   311,   300,    57,    58,    59,
      11,    12,    13,    14,    60,   197,   198,   199,   306,    43,
      61,    62,    63,   142,   248,    93,   154,   186,   158,   302,
       0,     0,     0,     0,     0,   156,     0,    64,    65,    66,
       0,   159,    67,   187,    53,    54,    55,   200,   157,     0,
      68,     0,   140,   201,    56,   188,     0,     0,   189,     0,
       0,   190,   191,   192,   193,   194,     0,     0,     0,     0,
     195,   196,     0,     0,    57,    58,    59,    11,    12,    13,
      14,    60,   197,   198,   199,     0,     0,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,    67,
     187,    53,    54,    55,   200,     0,     0,    68,     0,   140,
     243,    56,   188,     0,     0,   189,     0,     0,   190,   191,
     192,   193,   194,     0,     0,     0,     0,   195,   196,     0,
       0,    57,    58,    59,    11,    12,    13,    14,    60,   197,
     198,   199,     0,     0,    61,    62,    63,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,    64,    65,    66,     0,     0,    67,     0,     0,     0,
       0,   200,     0,     0,    68,     0,   140,     0,    57,    58,
      59,     0,     0,     0,     0,    60,    52,    53,    54,    55,
       0,    61,    62,    63,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,    67,     0,     0,     0,    57,    58,    59,
       0,    68,   176,     0,    60,     0,     0,     0,     0,     0,
      61,    62,    63,   149,    53,    54,    55,     0,     0,     2,
       3,     4,     5,    34,    56,     0,     0,    64,    65,    66,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
      68,   276,     0,     0,    57,    58,    59,     0,     0,     0,
       0,    60,    52,    53,    54,    55,     0,    61,    62,    63,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,    67,
       0,     0,     0,    57,    58,    59,     0,    68,     0,     0,
      60,     0,     0,     0,     0,     0,    61,    62,    63,    52,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,    64,    65,    66,     0,     0,    67,     0,
       0,     0,     0,   241,     0,     0,    68,     0,     0,     0,
      57,    58,    59,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,    61,    62,    63,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      64,    65,    66,     0,     0,    67,     0,     0,     0,     0,
     200,     0,     0,    68,     0,     0,     0,    57,    58,    59,
       0,     0,    99,   100,    60,     0,     0,     0,     0,     0,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,    64,    65,    66,
       0,     0,    67,     0,     0,     0,   151,     0,     0,     0,
      68,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   170,   171,   172,     1,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,     0,     0,     0,
       0,    15,    16
};

static const yytype_int16 yycheck[] =
{
      41,    89,     0,   192,    52,   102,    19,    20,     3,     4,
     232,     9,    75,    75,     7,   204,     0,   300,    80,    82,
      18,    74,     3,   306,    74,    23,    79,    68,     3,    79,
     127,     3,   254,    81,    18,     3,   133,     9,    10,    11,
      12,    13,    75,    75,     3,    75,    78,    80,    78,     3,
       9,    10,    11,    12,    13,     9,    10,    11,    12,    13,
      64,    65,     3,    75,     5,    60,    78,    80,    72,    73,
      91,     3,    93,    77,     3,   264,    75,    81,   267,    78,
       9,    10,    11,    12,    13,    58,    59,   276,   110,   111,
     112,   113,   180,   134,     0,   136,    75,   286,    75,    78,
      98,    78,    78,   292,    60,    61,    62,    63,    80,    52,
      53,    54,    55,    56,    57,    49,    50,    51,   307,   308,
     309,    80,   311,   220,    78,    75,    75,    75,    78,    78,
      78,     8,     3,     4,     5,     6,     3,   135,    77,   227,
     237,   238,    75,    14,    15,    78,     3,    18,    19,    20,
      21,    22,    23,    24,    25,    70,    71,    79,   199,    30,
      31,    47,    48,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    74,    75,    47,    48,    49,    75,
      75,     3,    78,    78,    74,    75,    74,    75,    79,   230,
     231,     3,   233,    64,    65,    66,    74,    75,    69,   240,
      16,    17,     3,    74,    19,    20,    77,    79,    79,    80,
     108,   109,   114,   115,    74,   116,   117,   237,   238,    61,
      75,    77,   263,    33,    32,   266,    67,   268,   226,     3,
       4,     5,     6,    68,    66,    79,     3,    77,    52,     3,
      14,    15,   283,     5,    18,    19,    20,    21,    22,    23,
      24,    25,     5,    74,   295,    74,    30,    31,     3,     3,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    74,    78,    47,    48,    49,    78,    82,    78,    76,
       3,    77,    77,    77,    77,    74,    74,    77,    22,    52,
      64,    65,    66,    77,    77,    69,     3,     4,     5,     6,
      74,    52,    74,    77,     5,    79,    80,    14,    15,    79,
      79,    18,    77,    74,    21,    22,    23,    24,    25,    74,
      74,    77,    74,    30,    31,    17,    76,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    76,    18,
      47,    48,    49,    90,   226,    48,   103,   139,   106,   289,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    64,    65,    66,
      -1,   107,    69,     3,     4,     5,     6,    74,   105,    -1,
      77,    -1,    79,    80,    14,    15,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    69,
       3,     4,     5,     6,    74,    -1,    -1,    77,    -1,    79,
      80,    14,    15,    -1,    -1,    18,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    -1,    79,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
      -1,    47,    48,    49,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    69,    -1,    -1,    -1,    34,    35,    36,
      -1,    77,    78,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,     3,     4,     5,     6,    -1,    47,    48,    49,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    69,
      -1,    -1,    -1,    34,    35,    36,    -1,    77,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,    34,    35,    36,
      -1,    -1,    64,    65,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      77,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     3,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    13,    26,    27,    28,
      29,    37,    38,    39,    40,    45,    46,    84,    85,    86,
      87,    89,    90,    91,    92,    96,    97,   100,   103,   104,
     105,     7,     3,     3,    13,    89,     3,     3,     4,    60,
      88,     3,     0,    86,     8,    89,    77,    79,    79,     3,
      79,     3,     3,     4,     5,     6,    14,    34,    35,    36,
      41,    47,    48,    49,    64,    65,    66,    69,    77,   118,
     119,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,     3,     3,    93,    94,    78,
      89,   101,   102,   101,    74,     3,   106,    61,    77,   131,
     131,   118,    75,    33,    32,    67,    68,    66,    58,    59,
      60,    61,    62,    63,    70,    71,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   120,   131,    64,
      65,    72,    73,    77,    81,    77,    52,    81,    74,    75,
      79,   107,    93,    80,   102,    80,    52,    75,    80,     3,
      89,   131,    78,   119,   122,   131,   123,   124,   125,   126,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   119,     3,     3,    78,   119,   135,   118,
      78,    89,    98,    99,   118,     5,    94,     3,    15,    18,
      21,    22,    23,    24,    25,    30,    31,    42,    43,    44,
      74,    80,    92,   107,   108,   109,   110,   111,   115,   116,
     117,   118,    74,    74,    74,     5,     3,    74,    78,    78,
      75,    78,    82,    74,   107,     3,    75,    78,    82,    76,
      77,    77,    77,    77,   109,    74,    74,    77,    77,     3,
      77,    74,   118,    80,   109,    74,    52,   119,    99,    74,
     107,    52,   118,   118,   110,   118,    22,   135,   135,    74,
     118,    74,     5,    79,    78,    78,   110,    78,    77,    78,
      78,    78,    95,   118,   109,    79,    78,   118,   109,   118,
      74,    74,    74,    75,    80,    16,    17,    19,    20,   112,
     113,   109,    78,    78,   118,    77,   109,     3,     5,   114,
      76,    80,   113,   109,    74,   118,    76,   108,    78,   108,
     109,    17,   109
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 116 "hawkinslang.y"
    { printf("\n✓ Program parsed successfully!\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 138 "hawkinslang.y"
    { printf("✓ Library import directive recognized\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 140 "hawkinslang.y"
    { printf("✓ Macro definition recognized: %s\n", (yyvsp[(2) - (3)].sval)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 151 "hawkinslang.y"
    { (yyval.sval) = strdup("eleven"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 152 "hawkinslang.y"
    { (yyval.sval) = strdup("signal"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 153 "hawkinslang.y"
    { (yyval.sval) = strdup("full_signal"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 154 "hawkinslang.y"
    { (yyval.sval) = strdup("letter"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 155 "hawkinslang.y"
    { (yyval.sval) = strdup("the_void"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 156 "hawkinslang.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 174 "hawkinslang.y"
    { printf("✓ Variable declaration recognized (type: %s)\n", (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 184 "hawkinslang.y"
    { add_symbol((yyvsp[(1) - (1)].sval), "variable", line_num); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 186 "hawkinslang.y"
    { add_symbol((yyvsp[(1) - (3)].sval), "variable", line_num); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 188 "hawkinslang.y"
    { add_symbol((yyvsp[(1) - (4)].sval), "array", line_num); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 190 "hawkinslang.y"
    { add_symbol((yyvsp[(1) - (8)].sval), "array", line_num); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 201 "hawkinslang.y"
    { 
            printf("✓ Function declaration: %s (return type: %s)\n", (yyvsp[(3) - (7)].sval), (yyvsp[(1) - (7)].sval));
            add_symbol((yyvsp[(3) - (7)].sval), "function", line_num);
        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 206 "hawkinslang.y"
    { 
            printf("✓ Function declaration: %s (return type: %s, no parameters)\n", (yyvsp[(3) - (6)].sval), (yyvsp[(1) - (6)].sval));
            add_symbol((yyvsp[(3) - (6)].sval), "function", line_num);
        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 214 "hawkinslang.y"
    { 
            printf("✓ Function definition: %s (return type: %s)\n", (yyvsp[(3) - (7)].sval), (yyvsp[(1) - (7)].sval));
            add_symbol((yyvsp[(3) - (7)].sval), "function", line_num);
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 219 "hawkinslang.y"
    { 
            printf("✓ Function definition: %s (return type: %s, no parameters)\n", (yyvsp[(3) - (6)].sval), (yyvsp[(1) - (6)].sval));
            add_symbol((yyvsp[(3) - (6)].sval), "function", line_num);
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 224 "hawkinslang.y"
    { 
            printf("✓ Main function (hawkins) definition recognized\n");
            add_symbol("hawkins", "main_function", line_num);
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 237 "hawkinslang.y"
    { printf("  Parameter: %s (type: %s)\n", (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].sval)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 244 "hawkinslang.y"
    { 
            printf("✓ Structure declaration: %s\n", (yyvsp[(2) - (6)].sval));
            add_symbol((yyvsp[(2) - (6)].sval), "struct", line_num);
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 262 "hawkinslang.y"
    { 
            printf("✓ Union declaration: %s\n", (yyvsp[(2) - (6)].sval));
            add_symbol((yyvsp[(2) - (6)].sval), "union", line_num);
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 271 "hawkinslang.y"
    { 
            printf("✓ Typedef declaration: %s\n", (yyvsp[(3) - (4)].sval));
            add_symbol((yyvsp[(3) - (4)].sval), "typedef", line_num);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 280 "hawkinslang.y"
    { 
            printf("✓ Enumeration declaration: %s\n", (yyvsp[(2) - (6)].sval));
            add_symbol((yyvsp[(2) - (6)].sval), "enum", line_num);
        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 296 "hawkinslang.y"
    { printf("  Empty compound statement\n"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 298 "hawkinslang.y"
    { printf("  Compound statement\n"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 324 "hawkinslang.y"
    { printf("✓ If statement recognized\n"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 326 "hawkinslang.y"
    { printf("✓ If-else statement recognized\n"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 328 "hawkinslang.y"
    { printf("✓ If-elseif statement recognized\n"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 330 "hawkinslang.y"
    { printf("✓ If-elseif-else statement recognized\n"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 332 "hawkinslang.y"
    { printf("✓ Switch statement recognized\n"); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 353 "hawkinslang.y"
    { printf("✓ For loop recognized\n"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 355 "hawkinslang.y"
    { printf("✓ For loop recognized\n"); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 357 "hawkinslang.y"
    { printf("✓ While loop recognized\n"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 359 "hawkinslang.y"
    { printf("✓ Do-while loop recognized\n"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 365 "hawkinslang.y"
    { printf("✓ Break statement\n"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 367 "hawkinslang.y"
    { printf("✓ Continue statement\n"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 369 "hawkinslang.y"
    { printf("✓ Return statement (void)\n"); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 371 "hawkinslang.y"
    { printf("✓ Return statement\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 373 "hawkinslang.y"
    { printf("✓ Goto statement to label: %s\n", (yyvsp[(2) - (3)].sval)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 375 "hawkinslang.y"
    { printf("✓ Exit statement\n"); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 377 "hawkinslang.y"
    { printf("✓ Label: %s\n", (yyvsp[(1) - (2)].sval)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 383 "hawkinslang.y"
    { printf("✓ Output statement (radio_out)\n"); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 385 "hawkinslang.y"
    { printf("✓ Input statement (radio_in)\n"); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 488 "hawkinslang.y"
    { printf("  Function call (no arguments)\n"); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 490 "hawkinslang.y"
    { printf("  Function call with arguments\n"); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 499 "hawkinslang.y"
    { 
            Symbol *sym = lookup_symbol((yyvsp[(1) - (1)].sval));
            if (sym == NULL) {
                printf("⚠ Warning: Identifier '%s' used before declaration (line %d)\n", (yyvsp[(1) - (1)].sval), line_num);
            }
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2235 "hawkinslang.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 519 "hawkinslang.y"


void yyerror(const char *s) {
    fprintf(stderr, "✗ Syntax error at line %d: %s\n", line_num, s);
    syntax_errors++;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file.hwk>\n", argv[0]);
        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }
    
    yyin = input_file;
    
    printf("================================================================\n");
    printf("          HAWKINSLANG BISON PARSER - SYNTAX ANALYSIS           \n");
    printf("================================================================\n");
    printf("Input File: %s\n", argv[1]);
    printf("================================================================\n\n");
    
    int result = yyparse();
    
    printf("\n================================================================\n");
    printf("                    SYMBOL TABLE                                \n");
    printf("================================================================\n");
    
    Symbol *sym = symbol_table;
    if (sym == NULL) {
        printf("(No symbols declared)\n");
    } else {
        while (sym != NULL) {
            printf("Symbol: %-20s Type: %-15s Line: %d\n", sym->name, sym->type, sym->line_declared);
            sym = sym->next;
        }
    }
    
    printf("\n================================================================\n");
    printf("                    PARSING RESULT                              \n");
    printf("================================================================\n");
    
    if (result == 0 && syntax_errors == 0) {
        printf("✓ Status: PARSING SUCCESSFUL\n");
        printf("  No syntax errors found.\n");
    } else {
        printf("✗ Status: PARSING FAILED\n");
        printf("  Total syntax errors: %d\n", syntax_errors);
    }
    printf("================================================================\n");
    
    fclose(input_file);
    
    // Free symbol table
    sym = symbol_table;
    while (sym != NULL) {
        Symbol *next = sym->next;
        free(sym);
        sym = next;
    }
    
    return (result != 0 || syntax_errors > 0);
}

