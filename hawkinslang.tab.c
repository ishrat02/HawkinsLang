/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "hawkinslang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// External declarations from lexer
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;

void yyerror(const char *s);

ASTNode *root = NULL;
int syntax_errors = 0;

#line 89 "hawkinslang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "hawkinslang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 5,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 6,              /* FLOAT_LITERAL  */
  YYSYMBOL_HAWKINS = 7,                    /* HAWKINS  */
  YYSYMBOL_PORTAL = 8,                     /* PORTAL  */
  YYSYMBOL_ELEVEN = 9,                     /* ELEVEN  */
  YYSYMBOL_SIGNAL = 10,                    /* SIGNAL  */
  YYSYMBOL_FULL_SIGNAL = 11,               /* FULL_SIGNAL  */
  YYSYMBOL_LETTER = 12,                    /* LETTER  */
  YYSYMBOL_THE_VOID = 13,                  /* THE_VOID  */
  YYSYMBOL_NOTHING = 14,                   /* NOTHING  */
  YYSYMBOL_PRIMARY_GATE = 15,              /* PRIMARY_GATE  */
  YYSYMBOL_SECONDARY_GATE = 16,            /* SECONDARY_GATE  */
  YYSYMBOL_TAKE_COVER = 17,                /* TAKE_COVER  */
  YYSYMBOL_CHOOSE_GATE = 18,               /* CHOOSE_GATE  */
  YYSYMBOL_GATE_CASE = 19,                 /* GATE_CASE  */
  YYSYMBOL_FALLBACK = 20,                  /* FALLBACK  */
  YYSYMBOL_COUNTDOWN = 21,                 /* COUNTDOWN  */
  YYSYMBOL_CLOCK_CHIME = 22,               /* CLOCK_CHIME  */
  YYSYMBOL_INVADE = 23,                    /* INVADE  */
  YYSYMBOL_ESCAPE = 24,                    /* ESCAPE  */
  YYSYMBOL_SLIP = 25,                      /* SLIP  */
  YYSYMBOL_HIVE = 26,                      /* HIVE  */
  YYSYMBOL_THE_BRIDGE = 27,                /* THE_BRIDGE  */
  YYSYMBOL_MR_WHATSIT = 28,                /* MR_WHATSIT  */
  YYSYMBOL_CODENAME = 29,                  /* CODENAME  */
  YYSYMBOL_RADIO_OUT = 30,                 /* RADIO_OUT  */
  YYSYMBOL_RADIO_IN = 31,                  /* RADIO_IN  */
  YYSYMBOL_DANGERIF_ALL_OPEN = 32,         /* DANGERIF_ALL_OPEN  */
  YYSYMBOL_THREATIF_ANY_OPEN = 33,         /* THREATIF_ANY_OPEN  */
  YYSYMBOL_UPSIDE_DOWN = 34,               /* UPSIDE_DOWN  */
  YYSYMBOL_FRIENDSDONTLIE = 35,            /* FRIENDSDONTLIE  */
  YYSYMBOL_LIES = 36,                      /* LIES  */
  YYSYMBOL_SEALED = 37,                    /* SEALED  */
  YYSYMBOL_UNSTABLE = 38,                  /* UNSTABLE  */
  YYSYMBOL_ROOTED = 39,                    /* ROOTED  */
  YYSYMBOL_THE_ABYSS = 40,                 /* THE_ABYSS  */
  YYSYMBOL_GAUGE = 41,                     /* GAUGE  */
  YYSYMBOL_SUMMONED = 42,                  /* SUMMONED  */
  YYSYMBOL_SHUTDOWN = 43,                  /* SHUTDOWN  */
  YYSYMBOL_TO_REAL_WORLD = 44,             /* TO_REAL_WORLD  */
  YYSYMBOL_LIBRARY_IMPORT = 45,            /* LIBRARY_IMPORT  */
  YYSYMBOL_MACRO_DEF = 46,                 /* MACRO_DEF  */
  YYSYMBOL_PLUS = 47,                      /* PLUS  */
  YYSYMBOL_MINUS = 48,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 49,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 50,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 51,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 52,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 53,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 54,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 55,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 56,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 57,                /* MOD_ASSIGN  */
  YYSYMBOL_EQ = 58,                        /* EQ  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_LT = 60,                        /* LT  */
  YYSYMBOL_GT = 61,                        /* GT  */
  YYSYMBOL_LE = 62,                        /* LE  */
  YYSYMBOL_GE = 63,                        /* GE  */
  YYSYMBOL_INCREMENT = 64,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 65,                 /* DECREMENT  */
  YYSYMBOL_BITWISE_AND = 66,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 67,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 68,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 69,               /* BITWISE_NOT  */
  YYSYMBOL_LEFT_SHIFT = 70,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 71,               /* RIGHT_SHIFT  */
  YYSYMBOL_ARROW = 72,                     /* ARROW  */
  YYSYMBOL_DOT = 73,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 74,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 75,                     /* COMMA  */
  YYSYMBOL_COLON = 76,                     /* COLON  */
  YYSYMBOL_LPAREN = 77,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 78,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 79,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 80,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 81,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 82,                  /* RBRACKET  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_program = 84,                   /* program  */
  YYSYMBOL_translation_unit = 85,          /* translation_unit  */
  YYSYMBOL_external_declaration = 86,      /* external_declaration  */
  YYSYMBOL_preprocessor_directive = 87,    /* preprocessor_directive  */
  YYSYMBOL_type_specifier = 88,            /* type_specifier  */
  YYSYMBOL_variable_declaration = 89,      /* variable_declaration  */
  YYSYMBOL_declarator_list = 90,           /* declarator_list  */
  YYSYMBOL_declarator = 91,                /* declarator  */
  YYSYMBOL_initializer_list = 92,          /* initializer_list  */
  YYSYMBOL_function_declaration = 93,      /* function_declaration  */
  YYSYMBOL_function_definition = 94,       /* function_definition  */
  YYSYMBOL_parameter_list = 95,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 96,     /* parameter_declaration  */
  YYSYMBOL_struct_declaration = 97,        /* struct_declaration  */
  YYSYMBOL_union_declaration = 98,         /* union_declaration  */
  YYSYMBOL_typedef_declaration = 99,       /* typedef_declaration  */
  YYSYMBOL_enum_declaration = 100,         /* enum_declaration  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_labeled_statement = 102,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 103,       /* compound_statement  */
  YYSYMBOL_block_item_list = 104,          /* block_item_list  */
  YYSYMBOL_block_item = 105,               /* block_item  */
  YYSYMBOL_expression_statement = 106,     /* expression_statement  */
  YYSYMBOL_selection_statement = 107,      /* selection_statement  */
  YYSYMBOL_switch_case_list = 108,         /* switch_case_list  */
  YYSYMBOL_switch_case = 109,              /* switch_case  */
  YYSYMBOL_constant_expression = 110,      /* constant_expression  */
  YYSYMBOL_iteration_statement = 111,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 112,           /* jump_statement  */
  YYSYMBOL_declaration = 113,              /* declaration  */
  YYSYMBOL_expression = 114,               /* expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 116,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 117,   /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 118,  /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 119,  /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 120,           /* and_expression  */
  YYSYMBOL_equality_expression = 121,      /* equality_expression  */
  YYSYMBOL_relational_expression = 122,    /* relational_expression  */
  YYSYMBOL_shift_expression = 123,         /* shift_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 125, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 126,          /* cast_expression  */
  YYSYMBOL_unary_expression = 127,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 128,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 129,       /* primary_expression  */
  YYSYMBOL_argument_expression_list = 130  /* argument_expression_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,   101,   103,   119,   120,   121,   122,   123,
     124,   125,   126,   131,   133,   139,   140,   141,   142,   143,
     144,   149,   159,   161,   174,   176,   183,   190,   199,   201,
     212,   216,   223,   227,   231,   238,   240,   250,   259,   265,
     270,   278,   284,   285,   286,   287,   288,   289,   293,   299,
     304,   313,   315,   323,   325,   338,   339,   343,   344,   345,
     349,   351,   353,   362,   364,   376,   382,   390,   393,   396,
     399,   402,   406,   410,   412,   418,   422,   430,   431,   432,
     437,   439,   444,   452,   458,   459,   467,   468,   470,   472,
     474,   476,   481,   482,   487,   488,   493,   494,   499,   500,
     505,   506,   511,   512,   514,   519,   520,   521,   522,   523,
     527,   528,   529,   533,   534,   535,   539,   540,   541,   542,
     546,   547,   557,   558,   559,   560,   561,   563,   571,   572,
     578,   583,   587,   589,   591,   592,   596,   597,   601,   605,
     610,   611,   612,   613,   614,   615,   619,   620
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LITERAL", "INTEGER_LITERAL", "FLOAT_LITERAL", "HAWKINS",
  "PORTAL", "ELEVEN", "SIGNAL", "FULL_SIGNAL", "LETTER", "THE_VOID",
  "NOTHING", "PRIMARY_GATE", "SECONDARY_GATE", "TAKE_COVER", "CHOOSE_GATE",
  "GATE_CASE", "FALLBACK", "COUNTDOWN", "CLOCK_CHIME", "INVADE", "ESCAPE",
  "SLIP", "HIVE", "THE_BRIDGE", "MR_WHATSIT", "CODENAME", "RADIO_OUT",
  "RADIO_IN", "DANGERIF_ALL_OPEN", "THREATIF_ANY_OPEN", "UPSIDE_DOWN",
  "FRIENDSDONTLIE", "LIES", "SEALED", "UNSTABLE", "ROOTED", "THE_ABYSS",
  "GAUGE", "SUMMONED", "SHUTDOWN", "TO_REAL_WORLD", "LIBRARY_IMPORT",
  "MACRO_DEF", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "EQ", "NE", "LT", "GT", "LE", "GE", "INCREMENT", "DECREMENT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "ARROW", "DOT", "SEMICOLON", "COMMA", "COLON", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "$accept",
  "program", "translation_unit", "external_declaration",
  "preprocessor_directive", "type_specifier", "variable_declaration",
  "declarator_list", "declarator", "initializer_list",
  "function_declaration", "function_definition", "parameter_list",
  "parameter_declaration", "struct_declaration", "union_declaration",
  "typedef_declaration", "enum_declaration", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "switch_case_list", "switch_case", "constant_expression",
  "iteration_statement", "jump_statement", "declaration", "expression",
  "assignment_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     165,  -272,  -272,  -272,  -272,  -272,    11,    33,    43,   108,
      80,    81,   109,   135,   165,  -272,  -272,    54,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,    37,    52,    69,  -272,   147,
     102,  -272,   524,  -272,  -272,   -38,   180,    22,  -272,    62,
     115,   120,   146,   142,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,   569,  -272,  -272,   588,   569,   569,   505,   149,  -272,
     216,   231,   217,   218,   219,    44,   110,    86,   114,   157,
    -272,    91,    60,  -272,   524,   282,   215,  -272,   290,   220,
     221,   222,  -272,   223,   524,  -272,   505,  -272,  -272,  -272,
       6,   224,   -22,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,  -272,  -272,   291,
     295,    45,   524,   149,   225,    10,  -272,   247,  -272,  -272,
    -272,  -272,   226,   524,  -272,  -272,   231,  -272,   217,   218,
     219,    44,   110,   110,    86,    86,    86,    86,   114,   114,
     157,   157,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,    -5,   -58,   248,   -11,   298,    -4,
    -272,     2,   229,   232,   524,   227,   233,   236,   403,   234,
     240,   302,   238,   124,  -272,  -272,   290,  -272,  -272,  -272,
    -272,   325,  -272,  -272,  -272,  -272,  -272,  -272,    92,  -272,
    -272,   524,  -272,  -272,   237,  -272,  -272,  -272,   108,    15,
     403,   524,   524,   168,   403,   460,   524,   296,  -272,  -272,
    -272,   243,   524,  -272,   171,  -272,  -272,  -272,  -272,   524,
    -272,  -272,  -272,  -272,    38,    61,   403,  -272,   460,   460,
      74,   242,  -272,   121,  -272,    18,   149,   403,   241,  -272,
     524,   524,   403,   524,   249,   524,  -272,   305,   228,   137,
     138,  -272,   139,  -272,   149,   403,    42,   256,    -8,  -272,
     403,   403,   251,  -272,  -272,  -272,   -16,   403,  -272,  -272,
    -272,  -272,  -272,    42,    42,    42,    42,   403,   403,   205,
     205,  -272,  -272,   403
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     8,     0,     7,     6,
       5,     9,    10,    11,    12,     0,     0,     0,    19,     0,
       0,    13,     0,     1,     4,    24,     0,     0,    22,     0,
       0,     0,     0,     0,   136,   139,   137,   138,   145,   141,
     142,     0,   143,   144,     0,     0,     0,     0,    14,    84,
      86,    92,    94,    96,    98,   100,   102,   105,   110,   113,
     116,   120,   122,   128,     0,     0,     0,    21,     0,     0,
       0,     0,    40,     0,     0,   125,     0,   126,   123,   124,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,     0,
       0,     0,     0,    25,     0,     0,    23,     0,    34,    38,
      39,    41,     0,     0,   140,    85,    93,   120,    95,    97,
      99,   101,   103,   104,   106,   107,   108,   109,   111,   112,
     114,   115,   117,   118,   119,    87,    88,    89,    90,    91,
     133,   132,   130,   146,     0,     0,    26,     0,     0,     0,
      35,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    51,     0,    83,    56,    47,
      42,     0,    53,    43,    44,    45,    46,    55,     0,   127,
     121,     0,   129,   131,     0,    31,    33,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    77,
      78,     0,     0,    80,     0,    52,    54,    58,   147,     0,
      36,    30,    32,    50,     0,     0,     0,    49,     0,     0,
       0,     0,    81,     0,    79,     0,    28,     0,     0,    48,
       0,     0,     0,     0,     0,     0,    27,    60,     0,     0,
       0,    73,     0,    82,    29,     0,     0,     0,     0,    63,
       0,     0,     0,    61,    72,    71,     0,     0,    62,    64,
      75,    76,    74,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,  -272,   319,  -272,     1,    55,  -272,   263,  -272,
    -272,  -272,  -272,   134,  -272,  -272,  -272,  -272,  -170,  -272,
     -75,  -271,  -189,  -174,  -272,  -272,    83,  -178,  -272,  -272,
    -124,   -32,   -86,  -272,   258,   259,   257,   260,   264,   174,
     101,   170,   172,   -72,   131,  -272,  -272,  -272
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    15,    16,   186,   187,    37,    38,   245,
      19,    20,   169,   170,    21,    22,    23,    24,   188,   189,
     190,   191,   192,   193,   194,   268,   269,   276,   195,   196,
     218,   198,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   164
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    17,   226,   197,   128,   -20,   288,   135,   217,   -20,
      29,   266,   267,     1,    74,    17,   293,    93,    25,     2,
       3,     4,     5,    28,   203,    92,   155,   156,   157,   158,
     159,   283,   284,   285,   286,   163,    26,   152,   153,   154,
     233,   238,   123,    75,   237,   274,    27,   275,    44,    45,
      46,    47,    92,    93,    92,    18,   134,    35,    91,    48,
     287,   200,    36,   205,   250,   251,   249,   197,   127,    18,
     201,   208,   278,   202,   209,    49,    50,   257,   210,    51,
      52,    53,   261,    30,   -20,    31,    54,   132,   167,   231,
     165,   239,   206,   255,   127,   273,    77,    78,   256,   226,
     280,   281,    99,   100,   226,   289,   290,   291,   292,    55,
      56,     1,    32,    93,    39,   228,   247,     2,     3,     4,
       5,    28,    57,   162,   117,   118,   168,    44,    45,    46,
      47,    40,   119,   120,   232,    33,    93,   121,    48,   248,
      79,   122,   213,   112,   113,   114,   115,   116,    41,    93,
      42,   224,   252,   197,    49,    50,   105,   106,    51,    52,
      53,   107,   108,   197,   197,    54,   227,    93,     1,   197,
     101,   102,   103,   104,     2,     3,     4,     5,     6,   234,
     235,    43,    85,    76,   240,    87,    88,    89,    55,    56,
     243,     7,     8,     9,    10,    80,    93,   246,   223,   254,
      81,    57,   144,   145,   146,   147,   109,   110,   111,   168,
      11,    12,    93,    93,    93,   270,   271,   272,   259,   260,
      82,   262,    83,   264,    93,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,    93,   236,   244,    93,   266,   267,    94,
     171,    45,    46,    47,   285,   286,     2,     3,     4,     5,
      28,    48,   172,    95,   137,   173,   174,   175,   176,   177,
     178,   179,   180,   142,   143,   148,   149,    49,    50,   150,
     151,    51,    52,    53,    96,    98,    97,   124,    54,   181,
     182,   183,   125,    35,   160,   129,   130,   131,   161,   127,
     204,   207,   133,   214,   199,   221,   211,   166,   219,   212,
     215,    55,    56,   216,   220,   222,   229,   242,   241,   253,
     258,   184,   265,   263,    57,   282,   127,   185,   171,    45,
      46,    47,   277,    34,     2,     3,     4,     5,    28,    48,
     172,   126,   230,   173,   174,   175,   176,   177,   178,   179,
     180,   279,   136,   139,   138,    49,    50,   140,     0,    51,
      52,    53,   141,     0,     0,     0,    54,   181,   182,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,   184,
       0,     0,    57,     0,   127,   225,   171,    45,    46,    47,
       0,     0,     2,     3,     4,     5,    28,    48,   172,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,     0,
       0,     0,     0,    49,    50,     0,     0,    51,    52,    53,
       0,     0,     0,     0,    54,   181,   182,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    45,    46,    47,    55,    56,     2,
       3,     4,     5,    28,    48,     0,     0,   184,     0,     0,
      57,     0,   127,     0,     0,     0,     0,     0,     0,     0,
      49,    50,     0,     0,    51,    52,    53,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,    90,    45,
      46,    47,     0,     0,     2,     3,     4,     5,    28,    48,
       0,     0,     0,     0,    55,    56,     0,    44,    45,    46,
      47,     0,     0,     0,   184,    49,    50,    57,    48,    51,
      52,    53,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,    49,    50,     0,     0,    51,    52,
      53,     0,     0,     0,     0,    54,     0,     0,     0,    55,
      56,     0,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    57,    48,     0,     0,     0,     0,    55,    56,
       0,    44,    45,    46,    47,     0,     0,     0,     0,    49,
      50,    57,    48,    51,    52,    53,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,    49,    50,
       0,     0,    51,    52,    53,     0,     0,     0,     0,    54,
       0,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86
};

static const yytype_int16 yycheck[] =
{
      32,     0,   191,   127,    79,     3,   277,    93,   178,     3,
       9,    19,    20,     3,    52,    14,   287,    75,     7,     9,
      10,    11,    12,    13,    82,    57,   112,   113,   114,   115,
     116,    47,    48,    49,    50,   121,     3,   109,   110,   111,
     210,   215,    74,    81,   214,     3,     3,     5,     3,     4,
       5,     6,    84,    75,    86,     0,    78,     3,    57,    14,
      76,   133,     8,    74,   238,   239,   236,   191,    79,    14,
      75,    75,    80,    78,    78,    30,    31,   247,    76,    34,
      35,    36,   252,     3,    78,     4,    41,    86,    78,    74,
     122,   215,   167,    75,    79,   265,    74,    75,    80,   288,
     270,   271,    58,    59,   293,   283,   284,   285,   286,    64,
      65,     3,     3,    75,    77,   201,    78,     9,    10,    11,
      12,    13,    77,    78,    64,    65,   125,     3,     4,     5,
       6,    79,    72,    73,   209,     0,    75,    77,    14,    78,
      78,    81,   174,    52,    53,    54,    55,    56,    79,    75,
       3,   183,    78,   277,    30,    31,    70,    71,    34,    35,
      36,    47,    48,   287,   288,    41,    74,    75,     3,   293,
      60,    61,    62,    63,     9,    10,    11,    12,    13,   211,
     212,    79,    51,     3,   216,    54,    55,    56,    64,    65,
     222,    26,    27,    28,    29,    80,    75,   229,    74,    78,
      80,    77,   101,   102,   103,   104,    49,    50,    51,   208,
      45,    46,    75,    75,    75,    78,    78,    78,   250,   251,
      74,   253,    80,   255,    75,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    75,    76,    74,    75,    19,    20,    33,
       3,     4,     5,     6,    49,    50,     9,    10,    11,    12,
      13,    14,    15,    32,   133,    18,    19,    20,    21,    22,
      23,    24,    25,    99,   100,   105,   106,    30,    31,   107,
     108,    34,    35,    36,    67,    66,    68,     5,    41,    42,
      43,    44,    77,     3,     3,    74,    74,    74,     3,    79,
      52,     3,    78,    76,    78,     3,    77,    82,    74,    77,
      77,    64,    65,    77,    74,    77,    79,    74,    22,    77,
      79,    74,    17,    74,    77,    74,    79,    80,     3,     4,
       5,     6,    76,    14,     9,    10,    11,    12,    13,    14,
      15,    78,   208,    18,    19,    20,    21,    22,    23,    24,
      25,   268,    94,    96,    95,    30,    31,    97,    -1,    34,
      35,    36,    98,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    79,    80,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    64,    65,     9,
      10,    11,    12,    13,    14,    -1,    -1,    74,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    64,    65,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    74,    30,    31,    77,    14,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    64,
      65,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    14,    -1,    -1,    -1,    -1,    64,    65,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    30,
      31,    77,    14,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    13,    26,    27,    28,
      29,    45,    46,    84,    85,    86,    87,    88,    89,    93,
      94,    97,    98,    99,   100,     7,     3,     3,    13,    88,
       3,     4,     3,     0,    86,     3,     8,    90,    91,    77,
      79,    79,     3,    79,     3,     4,     5,     6,    14,    30,
      31,    34,    35,    36,    41,    64,    65,    77,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    52,    81,     3,    74,    75,    78,
      80,    80,    74,    80,    77,   127,    77,   127,   127,   127,
       3,    88,   114,    75,    33,    32,    67,    68,    66,    58,
      59,    60,    61,    62,    63,    70,    71,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    64,    65,    72,
      73,    77,    81,   114,     5,    77,    91,    79,   103,    74,
      74,    74,    88,    78,    78,   115,   117,   127,   118,   119,
     120,   121,   122,   122,   123,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   115,   115,   115,   115,   115,
       3,     3,    78,   115,   130,   114,    82,    78,    88,    95,
      96,     3,    15,    18,    19,    20,    21,    22,    23,    24,
      25,    42,    43,    44,    74,    80,    88,    89,   101,   102,
     103,   104,   105,   106,   107,   111,   112,   113,   114,    78,
     126,    75,    78,    82,    52,    74,   103,     3,    75,    78,
      76,    77,    77,   114,    76,    77,    77,   101,   113,    74,
      74,     3,    77,    74,   114,    80,   105,    74,   115,    79,
      96,    74,   103,   101,   114,   114,    76,   101,   106,   113,
     114,    22,    74,   114,    74,    92,   114,    78,    78,   101,
     106,   106,    78,    77,    78,    75,    80,   101,    79,   114,
     114,   101,   114,    74,   114,    17,    19,    20,   108,   109,
      78,    78,    78,   101,     3,     5,   110,    76,    80,   109,
     101,   101,    74,    47,    48,    49,    50,    76,   104,   110,
     110,   110,   110,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    89,    90,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    95,    95,    96,    97,    98,
      99,   100,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   122,   122,   122,   122,
     123,   123,   123,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   130
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     4,     8,     1,     3,
       7,     6,     7,     6,     5,     1,     3,     2,     5,     5,
       4,     5,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     1,
       5,     7,     7,     1,     2,     4,     3,     3,     3,     3,
       3,     1,     1,     5,     7,     7,     7,     2,     2,     3,
       2,     3,     5,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     4,     1,     2,     2,     2,     2,     4,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: translation_unit  */
#line 97 "hawkinslang.y"
        { root = (yyvsp[0].node); }
#line 1498 "hawkinslang.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 102 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1504 "hawkinslang.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 104 "hawkinslang.y"
        { 
            if ((yyvsp[-1].node) == NULL) {
                (yyval.node) = (yyvsp[0].node);
            } else {
                ASTNode *p = (yyvsp[-1].node);
                while (p->next != NULL) {
                     p = p->next;
                }
                p->next = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-1].node);
            }
        }
#line 1521 "hawkinslang.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 119 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1527 "hawkinslang.tab.c"
    break;

  case 6: /* external_declaration: function_declaration  */
#line 120 "hawkinslang.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1533 "hawkinslang.tab.c"
    break;

  case 7: /* external_declaration: variable_declaration  */
#line 121 "hawkinslang.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1539 "hawkinslang.tab.c"
    break;

  case 8: /* external_declaration: preprocessor_directive  */
#line 122 "hawkinslang.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1545 "hawkinslang.tab.c"
    break;

  case 9: /* external_declaration: struct_declaration  */
#line 123 "hawkinslang.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1551 "hawkinslang.tab.c"
    break;

  case 10: /* external_declaration: union_declaration  */
#line 124 "hawkinslang.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1557 "hawkinslang.tab.c"
    break;

  case 11: /* external_declaration: typedef_declaration  */
#line 125 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1563 "hawkinslang.tab.c"
    break;

  case 12: /* external_declaration: enum_declaration  */
#line 126 "hawkinslang.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1569 "hawkinslang.tab.c"
    break;

  case 13: /* preprocessor_directive: LIBRARY_IMPORT STRING_LITERAL  */
#line 132 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_PROGRAM, (yyvsp[0].sval)); /* TODO: specialized node */ }
#line 1575 "hawkinslang.tab.c"
    break;

  case 14: /* preprocessor_directive: MACRO_DEF IDENTIFIER expression  */
#line 134 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_PROGRAM, (yyvsp[-1].sval)); }
#line 1581 "hawkinslang.tab.c"
    break;

  case 15: /* type_specifier: ELEVEN  */
#line 139 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, "int"); }
#line 1587 "hawkinslang.tab.c"
    break;

  case 16: /* type_specifier: SIGNAL  */
#line 140 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, "float"); }
#line 1593 "hawkinslang.tab.c"
    break;

  case 17: /* type_specifier: FULL_SIGNAL  */
#line 141 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, "double"); }
#line 1599 "hawkinslang.tab.c"
    break;

  case 18: /* type_specifier: LETTER  */
#line 142 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, "char"); }
#line 1605 "hawkinslang.tab.c"
    break;

  case 19: /* type_specifier: THE_VOID  */
#line 143 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, "void"); }
#line 1611 "hawkinslang.tab.c"
    break;

  case 20: /* type_specifier: IDENTIFIER  */
#line 144 "hawkinslang.y"
                        { (yyval.node) = create_node(NODE_TYPE, (yyvsp[0].sval)); }
#line 1617 "hawkinslang.tab.c"
    break;

  case 21: /* variable_declaration: type_specifier declarator_list SEMICOLON  */
#line 150 "hawkinslang.y"
        { 
            // Correct the AST structure: NODE_VAR_DECL -> left: type, right: declarators
            (yyval.node) = create_node(NODE_VAR_DECL, NULL);
            (yyval.node)->left = (yyvsp[-2].node);
            (yyval.node)->right = (yyvsp[-1].node);
        }
#line 1628 "hawkinslang.tab.c"
    break;

  case 22: /* declarator_list: declarator  */
#line 160 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1634 "hawkinslang.tab.c"
    break;

  case 23: /* declarator_list: declarator_list COMMA declarator  */
#line 162 "hawkinslang.y"
        { 
            // Chain declarators
            ASTNode *p = (yyvsp[-2].node);
            while(p->next != NULL) {
                 p = p->next;
            }
            p->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-2].node);
        }
#line 1648 "hawkinslang.tab.c"
    break;

  case 24: /* declarator: IDENTIFIER  */
#line 175 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval)); }
#line 1654 "hawkinslang.tab.c"
    break;

  case 25: /* declarator: IDENTIFIER ASSIGN expression  */
#line 177 "hawkinslang.y"
        { 
            // In a declaration like 'eleven i = 0;', the declarator needs to carry the assignment
            // We'll treat this as an identifier node that HAS an assignment attached
            (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[-2].sval)); 
            (yyval.node)->right = (yyvsp[0].node); // Store initializer in right child
        }
#line 1665 "hawkinslang.tab.c"
    break;

  case 26: /* declarator: IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET  */
#line 184 "hawkinslang.y"
        { 
             char buf[64]; sprintf(buf, "%s", (yyvsp[-3].sval));
             (yyval.node) = create_node(NODE_IDENTIFIER, strdup(buf));
             // Array dimension could be stored in meta-data or a child
             // Simplified: Treating as identifier for now
        }
#line 1676 "hawkinslang.tab.c"
    break;

  case 27: /* declarator: IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET ASSIGN LBRACE initializer_list RBRACE  */
#line 191 "hawkinslang.y"
        {
             char buf[64]; sprintf(buf, "%s", (yyvsp[-7].sval));
             (yyval.node) = create_node(NODE_IDENTIFIER, strdup(buf));
             // Array init: simplified
        }
#line 1686 "hawkinslang.tab.c"
    break;

  case 28: /* initializer_list: expression  */
#line 200 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1692 "hawkinslang.tab.c"
    break;

  case 29: /* initializer_list: initializer_list COMMA expression  */
#line 202 "hawkinslang.y"
        { 
             ASTNode *p = (yyvsp[-2].node);
             while(p->next) p = p->next;
             p->next = (yyvsp[0].node);
             (yyval.node) = (yyvsp[-2].node);
        }
#line 1703 "hawkinslang.tab.c"
    break;

  case 30: /* function_declaration: type_specifier PORTAL IDENTIFIER LPAREN parameter_list RPAREN SEMICOLON  */
#line 213 "hawkinslang.y"
        { 
            (yyval.node) = create_func_def((yyvsp[-6].node), (yyvsp[-4].sval), (yyvsp[-2].node), NULL);
        }
#line 1711 "hawkinslang.tab.c"
    break;

  case 31: /* function_declaration: type_specifier PORTAL IDENTIFIER LPAREN RPAREN SEMICOLON  */
#line 217 "hawkinslang.y"
        { 
             (yyval.node) = create_func_def((yyvsp[-5].node), (yyvsp[-3].sval), NULL, NULL);
        }
#line 1719 "hawkinslang.tab.c"
    break;

  case 32: /* function_definition: type_specifier PORTAL IDENTIFIER LPAREN parameter_list RPAREN compound_statement  */
#line 224 "hawkinslang.y"
        { 
             (yyval.node) = create_func_def((yyvsp[-6].node), (yyvsp[-4].sval), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1727 "hawkinslang.tab.c"
    break;

  case 33: /* function_definition: type_specifier PORTAL IDENTIFIER LPAREN RPAREN compound_statement  */
#line 228 "hawkinslang.y"
        { 
             (yyval.node) = create_func_def((yyvsp[-5].node), (yyvsp[-3].sval), NULL, (yyvsp[0].node));
        }
#line 1735 "hawkinslang.tab.c"
    break;

  case 34: /* function_definition: THE_VOID HAWKINS LPAREN RPAREN compound_statement  */
#line 232 "hawkinslang.y"
        { 
             (yyval.node) = create_func_def(create_node(NODE_TYPE, "void"), "main", NULL, (yyvsp[0].node));
        }
#line 1743 "hawkinslang.tab.c"
    break;

  case 35: /* parameter_list: parameter_declaration  */
#line 239 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1749 "hawkinslang.tab.c"
    break;

  case 36: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 241 "hawkinslang.y"
        { 
            ASTNode *p = (yyvsp[-2].node);
            while(p->next) p = p->next;
            p->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-2].node);
        }
#line 1760 "hawkinslang.tab.c"
    break;

  case 37: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 251 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_PARAMETER, (yyvsp[0].sval));
            (yyval.node)->left = (yyvsp[-1].node);
        }
#line 1769 "hawkinslang.tab.c"
    break;

  case 38: /* struct_declaration: HIVE IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 260 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_STRUCT_DEF, (yyvsp[-3].sval)); }
#line 1775 "hawkinslang.tab.c"
    break;

  case 39: /* union_declaration: THE_BRIDGE IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 266 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_UNION_DEF, (yyvsp[-3].sval)); }
#line 1781 "hawkinslang.tab.c"
    break;

  case 40: /* typedef_declaration: MR_WHATSIT type_specifier IDENTIFIER SEMICOLON  */
#line 271 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_TYPEDEF, (yyvsp[-1].sval));
            (yyval.node)->left = (yyvsp[-2].node);
        }
#line 1790 "hawkinslang.tab.c"
    break;

  case 41: /* enum_declaration: CODENAME IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 279 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_ENUM_DEF, (yyvsp[-3].sval)); }
#line 1796 "hawkinslang.tab.c"
    break;

  case 42: /* statement: compound_statement  */
#line 284 "hawkinslang.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1802 "hawkinslang.tab.c"
    break;

  case 43: /* statement: expression_statement  */
#line 285 "hawkinslang.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1808 "hawkinslang.tab.c"
    break;

  case 44: /* statement: selection_statement  */
#line 286 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1814 "hawkinslang.tab.c"
    break;

  case 45: /* statement: iteration_statement  */
#line 287 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1820 "hawkinslang.tab.c"
    break;

  case 46: /* statement: jump_statement  */
#line 288 "hawkinslang.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1826 "hawkinslang.tab.c"
    break;

  case 47: /* statement: labeled_statement  */
#line 289 "hawkinslang.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1832 "hawkinslang.tab.c"
    break;

  case 48: /* labeled_statement: GATE_CASE expression COLON statement  */
#line 294 "hawkinslang.y"
        { 
             (yyval.node) = create_node(NODE_CASE, "case");
             (yyval.node)->left = (yyvsp[-2].node);
             (yyval.node)->right = (yyvsp[0].node);
        }
#line 1842 "hawkinslang.tab.c"
    break;

  case 49: /* labeled_statement: FALLBACK COLON statement  */
#line 300 "hawkinslang.y"
        {
             (yyval.node) = create_node(NODE_DEFAULT, "default");
             (yyval.node)->left = (yyvsp[0].node);
        }
#line 1851 "hawkinslang.tab.c"
    break;

  case 50: /* labeled_statement: IDENTIFIER COLON statement  */
#line 305 "hawkinslang.y"
        {
             // Goto label definition - simplified, assumes next stmt gets linked implicitly
             // or creates a label node
             (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[-2].sval));
        }
#line 1861 "hawkinslang.tab.c"
    break;

  case 51: /* compound_statement: LBRACE RBRACE  */
#line 314 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_BLOCK, NULL); }
#line 1867 "hawkinslang.tab.c"
    break;

  case 52: /* compound_statement: LBRACE block_item_list RBRACE  */
#line 316 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_BLOCK, NULL);
            (yyval.node)->left = (yyvsp[-1].node);
        }
#line 1876 "hawkinslang.tab.c"
    break;

  case 53: /* block_item_list: block_item  */
#line 324 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1882 "hawkinslang.tab.c"
    break;

  case 54: /* block_item_list: block_item_list block_item  */
#line 326 "hawkinslang.y"
        {
            if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
            else {
                ASTNode *p = (yyvsp[-1].node);
                while(p->next) p = p->next;
                p->next = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-1].node);
            }
        }
#line 1896 "hawkinslang.tab.c"
    break;

  case 55: /* block_item: declaration  */
#line 338 "hawkinslang.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1902 "hawkinslang.tab.c"
    break;

  case 56: /* block_item: statement  */
#line 339 "hawkinslang.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1908 "hawkinslang.tab.c"
    break;

  case 57: /* expression_statement: SEMICOLON  */
#line 343 "hawkinslang.y"
                { (yyval.node) = NULL; }
#line 1914 "hawkinslang.tab.c"
    break;

  case 58: /* expression_statement: expression SEMICOLON  */
#line 344 "hawkinslang.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1920 "hawkinslang.tab.c"
    break;

  case 59: /* expression_statement: declaration  */
#line 345 "hawkinslang.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1926 "hawkinslang.tab.c"
    break;

  case 60: /* selection_statement: PRIMARY_GATE LPAREN expression RPAREN statement  */
#line 350 "hawkinslang.y"
        { (yyval.node) = create_if_node((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 1932 "hawkinslang.tab.c"
    break;

  case 61: /* selection_statement: PRIMARY_GATE LPAREN expression RPAREN statement TAKE_COVER statement  */
#line 352 "hawkinslang.y"
        { (yyval.node) = create_if_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1938 "hawkinslang.tab.c"
    break;

  case 62: /* selection_statement: CHOOSE_GATE LPAREN expression RPAREN LBRACE switch_case_list RBRACE  */
#line 354 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_SWITCH, "switch");
            (yyval.node)->left = (yyvsp[-4].node);
            (yyval.node)->right = (yyvsp[-1].node);
        }
#line 1948 "hawkinslang.tab.c"
    break;

  case 63: /* switch_case_list: switch_case  */
#line 363 "hawkinslang.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1954 "hawkinslang.tab.c"
    break;

  case 64: /* switch_case_list: switch_case_list switch_case  */
#line 365 "hawkinslang.y"
        {
            ASTNode *p = (yyvsp[-1].node);
            if (p) {
                while(p->next) p = p->next;
                p->next = (yyvsp[0].node);
            }
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1967 "hawkinslang.tab.c"
    break;

  case 65: /* switch_case: GATE_CASE constant_expression COLON block_item_list  */
#line 377 "hawkinslang.y"
        { 
             (yyval.node) = create_node(NODE_CASE, "case");
             (yyval.node)->left = (yyvsp[-2].node);
             (yyval.node)->right = (yyvsp[0].node);
        }
#line 1977 "hawkinslang.tab.c"
    break;

  case 66: /* switch_case: FALLBACK COLON block_item_list  */
#line 383 "hawkinslang.y"
        {
             (yyval.node) = create_node(NODE_DEFAULT, "default");
             (yyval.node)->left = (yyvsp[0].node);
        }
#line 1986 "hawkinslang.tab.c"
    break;

  case 67: /* constant_expression: constant_expression PLUS constant_expression  */
#line 390 "hawkinslang.y"
                                                   {
         (yyval.node) = create_binary_node(NODE_BINARY_OP, "+", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1994 "hawkinslang.tab.c"
    break;

  case 68: /* constant_expression: constant_expression MINUS constant_expression  */
#line 393 "hawkinslang.y"
                                                    {
         (yyval.node) = create_binary_node(NODE_BINARY_OP, "-", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2002 "hawkinslang.tab.c"
    break;

  case 69: /* constant_expression: constant_expression MULTIPLY constant_expression  */
#line 396 "hawkinslang.y"
                                                       {
         (yyval.node) = create_binary_node(NODE_BINARY_OP, "*", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2010 "hawkinslang.tab.c"
    break;

  case 70: /* constant_expression: constant_expression DIVIDE constant_expression  */
#line 399 "hawkinslang.y"
                                                     {
         (yyval.node) = create_binary_node(NODE_BINARY_OP, "/", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2018 "hawkinslang.tab.c"
    break;

  case 71: /* constant_expression: INTEGER_LITERAL  */
#line 402 "hawkinslang.y"
                      { 
         char buf[32]; sprintf(buf, "%d", (yyvsp[0].ival));
         (yyval.node) = create_node(NODE_LITERAL_INT, strdup(buf)); 
    }
#line 2027 "hawkinslang.tab.c"
    break;

  case 72: /* constant_expression: IDENTIFIER  */
#line 406 "hawkinslang.y"
                 { (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval)); }
#line 2033 "hawkinslang.tab.c"
    break;

  case 73: /* iteration_statement: CLOCK_CHIME LPAREN expression RPAREN statement  */
#line 411 "hawkinslang.y"
        { (yyval.node) = create_while_node((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2039 "hawkinslang.tab.c"
    break;

  case 74: /* iteration_statement: INVADE statement CLOCK_CHIME LPAREN expression RPAREN SEMICOLON  */
#line 413 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_DO_WHILE, "do_while");
            (yyval.node)->left = (yyvsp[-2].node); // Condition
            (yyval.node)->right = (yyvsp[-5].node); // Body
        }
#line 2049 "hawkinslang.tab.c"
    break;

  case 75: /* iteration_statement: COUNTDOWN LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 419 "hawkinslang.y"
        { 
            (yyval.node) = create_for_node((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 2057 "hawkinslang.tab.c"
    break;

  case 76: /* iteration_statement: COUNTDOWN LPAREN declaration expression_statement expression RPAREN statement  */
#line 423 "hawkinslang.y"
        {
             // For loop with declaration: for (int i=0; ...
             (yyval.node) = create_for_node((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 2066 "hawkinslang.tab.c"
    break;

  case 77: /* jump_statement: ESCAPE SEMICOLON  */
#line 430 "hawkinslang.y"
                       { (yyval.node) = create_node(NODE_BREAK, NULL); }
#line 2072 "hawkinslang.tab.c"
    break;

  case 78: /* jump_statement: SLIP SEMICOLON  */
#line 431 "hawkinslang.y"
                     { (yyval.node) = create_node(NODE_CONTINUE, NULL); }
#line 2078 "hawkinslang.tab.c"
    break;

  case 79: /* jump_statement: TO_REAL_WORLD expression SEMICOLON  */
#line 433 "hawkinslang.y"
        { 
            (yyval.node) = create_node(NODE_RETURN, NULL); 
            (yyval.node)->left = (yyvsp[-1].node);
        }
#line 2087 "hawkinslang.tab.c"
    break;

  case 80: /* jump_statement: TO_REAL_WORLD SEMICOLON  */
#line 438 "hawkinslang.y"
        { (yyval.node) = create_node(NODE_RETURN, NULL); }
#line 2093 "hawkinslang.tab.c"
    break;

  case 81: /* jump_statement: SUMMONED IDENTIFIER SEMICOLON  */
#line 440 "hawkinslang.y"
        {
             char buf[128]; sprintf(buf, "goto %s", (yyvsp[-1].sval));
             (yyval.node) = create_node(NODE_IDENTIFIER, strdup(buf)); // Simplified
        }
#line 2102 "hawkinslang.tab.c"
    break;

  case 82: /* jump_statement: SHUTDOWN LPAREN expression RPAREN SEMICOLON  */
#line 445 "hawkinslang.y"
        {
             (yyval.node) = create_node(NODE_FUNC_CALL, "exit");
             (yyval.node)->left = (yyvsp[-2].node);
        }
#line 2111 "hawkinslang.tab.c"
    break;

  case 83: /* declaration: variable_declaration  */
#line 452 "hawkinslang.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 2117 "hawkinslang.tab.c"
    break;

  case 84: /* expression: assignment_expression  */
#line 458 "hawkinslang.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2123 "hawkinslang.tab.c"
    break;

  case 85: /* expression: expression COMMA assignment_expression  */
#line 460 "hawkinslang.y"
        { 
            // Simplified: return last expr or block? 
            (yyval.node) = (yyvsp[0].node); 
        }
#line 2132 "hawkinslang.tab.c"
    break;

  case 86: /* assignment_expression: logical_or_expression  */
#line 467 "hawkinslang.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2138 "hawkinslang.tab.c"
    break;

  case 87: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 469 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_ASSIGN, "=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2144 "hawkinslang.tab.c"
    break;

  case 88: /* assignment_expression: unary_expression PLUS_ASSIGN assignment_expression  */
#line 471 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_ASSIGN, "+=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2150 "hawkinslang.tab.c"
    break;

  case 89: /* assignment_expression: unary_expression MINUS_ASSIGN assignment_expression  */
#line 473 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_ASSIGN, "-=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2156 "hawkinslang.tab.c"
    break;

  case 90: /* assignment_expression: unary_expression MULT_ASSIGN assignment_expression  */
#line 475 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_ASSIGN, "*=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2162 "hawkinslang.tab.c"
    break;

  case 91: /* assignment_expression: unary_expression DIV_ASSIGN assignment_expression  */
#line 477 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_ASSIGN, "/=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2168 "hawkinslang.tab.c"
    break;

  case 92: /* logical_or_expression: logical_and_expression  */
#line 481 "hawkinslang.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2174 "hawkinslang.tab.c"
    break;

  case 93: /* logical_or_expression: logical_or_expression THREATIF_ANY_OPEN logical_and_expression  */
#line 483 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2180 "hawkinslang.tab.c"
    break;

  case 94: /* logical_and_expression: inclusive_or_expression  */
#line 487 "hawkinslang.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2186 "hawkinslang.tab.c"
    break;

  case 95: /* logical_and_expression: logical_and_expression DANGERIF_ALL_OPEN inclusive_or_expression  */
#line 489 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2192 "hawkinslang.tab.c"
    break;

  case 96: /* inclusive_or_expression: exclusive_or_expression  */
#line 493 "hawkinslang.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2198 "hawkinslang.tab.c"
    break;

  case 97: /* inclusive_or_expression: inclusive_or_expression BITWISE_OR exclusive_or_expression  */
#line 495 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "|", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2204 "hawkinslang.tab.c"
    break;

  case 98: /* exclusive_or_expression: and_expression  */
#line 499 "hawkinslang.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2210 "hawkinslang.tab.c"
    break;

  case 99: /* exclusive_or_expression: exclusive_or_expression BITWISE_XOR and_expression  */
#line 501 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "^", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2216 "hawkinslang.tab.c"
    break;

  case 100: /* and_expression: equality_expression  */
#line 505 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2222 "hawkinslang.tab.c"
    break;

  case 101: /* and_expression: and_expression BITWISE_AND equality_expression  */
#line 507 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2228 "hawkinslang.tab.c"
    break;

  case 102: /* equality_expression: relational_expression  */
#line 511 "hawkinslang.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2234 "hawkinslang.tab.c"
    break;

  case 103: /* equality_expression: equality_expression EQ relational_expression  */
#line 513 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2240 "hawkinslang.tab.c"
    break;

  case 104: /* equality_expression: equality_expression NE relational_expression  */
#line 515 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2246 "hawkinslang.tab.c"
    break;

  case 105: /* relational_expression: shift_expression  */
#line 519 "hawkinslang.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2252 "hawkinslang.tab.c"
    break;

  case 106: /* relational_expression: relational_expression LT shift_expression  */
#line 520 "hawkinslang.y"
                                                { (yyval.node) = create_binary_node(NODE_BINARY_OP, "<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2258 "hawkinslang.tab.c"
    break;

  case 107: /* relational_expression: relational_expression GT shift_expression  */
#line 521 "hawkinslang.y"
                                                { (yyval.node) = create_binary_node(NODE_BINARY_OP, ">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2264 "hawkinslang.tab.c"
    break;

  case 108: /* relational_expression: relational_expression LE shift_expression  */
#line 522 "hawkinslang.y"
                                                { (yyval.node) = create_binary_node(NODE_BINARY_OP, "<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2270 "hawkinslang.tab.c"
    break;

  case 109: /* relational_expression: relational_expression GE shift_expression  */
#line 523 "hawkinslang.y"
                                                { (yyval.node) = create_binary_node(NODE_BINARY_OP, ">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2276 "hawkinslang.tab.c"
    break;

  case 110: /* shift_expression: additive_expression  */
#line 527 "hawkinslang.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2282 "hawkinslang.tab.c"
    break;

  case 111: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 528 "hawkinslang.y"
                                                      { (yyval.node) = create_binary_node(NODE_BINARY_OP, "<<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2288 "hawkinslang.tab.c"
    break;

  case 112: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 529 "hawkinslang.y"
                                                       { (yyval.node) = create_binary_node(NODE_BINARY_OP, ">>", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2294 "hawkinslang.tab.c"
    break;

  case 113: /* additive_expression: multiplicative_expression  */
#line 533 "hawkinslang.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2300 "hawkinslang.tab.c"
    break;

  case 114: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 534 "hawkinslang.y"
                                                         { (yyval.node) = create_binary_node(NODE_BINARY_OP, "+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2306 "hawkinslang.tab.c"
    break;

  case 115: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 535 "hawkinslang.y"
                                                          { (yyval.node) = create_binary_node(NODE_BINARY_OP, "-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2312 "hawkinslang.tab.c"
    break;

  case 116: /* multiplicative_expression: cast_expression  */
#line 539 "hawkinslang.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2318 "hawkinslang.tab.c"
    break;

  case 117: /* multiplicative_expression: multiplicative_expression MULTIPLY cast_expression  */
#line 540 "hawkinslang.y"
                                                         { (yyval.node) = create_binary_node(NODE_BINARY_OP, "*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2324 "hawkinslang.tab.c"
    break;

  case 118: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 541 "hawkinslang.y"
                                                       { (yyval.node) = create_binary_node(NODE_BINARY_OP, "/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2330 "hawkinslang.tab.c"
    break;

  case 119: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 542 "hawkinslang.y"
                                                       { (yyval.node) = create_binary_node(NODE_BINARY_OP, "%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2336 "hawkinslang.tab.c"
    break;

  case 120: /* cast_expression: unary_expression  */
#line 546 "hawkinslang.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2342 "hawkinslang.tab.c"
    break;

  case 121: /* cast_expression: LPAREN type_specifier RPAREN cast_expression  */
#line 548 "hawkinslang.y"
        { 
             // Simplified cast node
             (yyval.node) = create_node(NODE_UNARY_OP, "cast");
             (yyval.node)->left = (yyvsp[0].node);
             // type info ignored for now in this simple node structure, or store in val?
        }
#line 2353 "hawkinslang.tab.c"
    break;

  case 122: /* unary_expression: postfix_expression  */
#line 557 "hawkinslang.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2359 "hawkinslang.tab.c"
    break;

  case 123: /* unary_expression: INCREMENT unary_expression  */
#line 558 "hawkinslang.y"
                                 { (yyval.node) = create_unary_node(NODE_UNARY_OP, "++", (yyvsp[0].node)); }
#line 2365 "hawkinslang.tab.c"
    break;

  case 124: /* unary_expression: DECREMENT unary_expression  */
#line 559 "hawkinslang.y"
                                 { (yyval.node) = create_unary_node(NODE_UNARY_OP, "--", (yyvsp[0].node)); }
#line 2371 "hawkinslang.tab.c"
    break;

  case 125: /* unary_expression: UPSIDE_DOWN unary_expression  */
#line 560 "hawkinslang.y"
                                   { (yyval.node) = create_unary_node(NODE_UNARY_OP, "!", (yyvsp[0].node)); }
#line 2377 "hawkinslang.tab.c"
    break;

  case 126: /* unary_expression: GAUGE unary_expression  */
#line 562 "hawkinslang.y"
        { (yyval.node) = create_unary_node(NODE_UNARY_OP, "sizeof", (yyvsp[0].node)); }
#line 2383 "hawkinslang.tab.c"
    break;

  case 127: /* unary_expression: GAUGE LPAREN type_specifier RPAREN  */
#line 564 "hawkinslang.y"
        { 
             ASTNode *sz = create_unary_node(NODE_UNARY_OP, "sizeof", (yyvsp[-1].node));
             (yyval.node) = sz;
        }
#line 2392 "hawkinslang.tab.c"
    break;

  case 128: /* postfix_expression: primary_expression  */
#line 571 "hawkinslang.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2398 "hawkinslang.tab.c"
    break;

  case 129: /* postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN  */
#line 573 "hawkinslang.y"
        { 
            ASTNode *call = create_node(NODE_FUNC_CALL, (yyvsp[-3].node)->val); // Simplified, assume ID
            call->left = (yyvsp[-1].node); // Arguments
            (yyval.node) = call;
        }
#line 2408 "hawkinslang.tab.c"
    break;

  case 130: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 579 "hawkinslang.y"
        { 
            ASTNode *call = create_node(NODE_FUNC_CALL, (yyvsp[-2].node)->val);
            (yyval.node) = call;
        }
#line 2417 "hawkinslang.tab.c"
    break;

  case 131: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 584 "hawkinslang.y"
        { 
             (yyval.node) = create_binary_node(NODE_BINARY_OP, "[]", (yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 2425 "hawkinslang.tab.c"
    break;

  case 132: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 588 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, ".", (yyvsp[-2].node), create_node(NODE_IDENTIFIER, (yyvsp[0].sval))); }
#line 2431 "hawkinslang.tab.c"
    break;

  case 133: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 590 "hawkinslang.y"
        { (yyval.node) = create_binary_node(NODE_BINARY_OP, "->", (yyvsp[-2].node), create_node(NODE_IDENTIFIER, (yyvsp[0].sval))); }
#line 2437 "hawkinslang.tab.c"
    break;

  case 134: /* postfix_expression: postfix_expression INCREMENT  */
#line 591 "hawkinslang.y"
                                   { (yyval.node) = create_unary_node(NODE_UNARY_OP, "p++", (yyvsp[-1].node)); }
#line 2443 "hawkinslang.tab.c"
    break;

  case 135: /* postfix_expression: postfix_expression DECREMENT  */
#line 592 "hawkinslang.y"
                                   { (yyval.node) = create_unary_node(NODE_UNARY_OP, "p--", (yyvsp[-1].node)); }
#line 2449 "hawkinslang.tab.c"
    break;

  case 136: /* primary_expression: IDENTIFIER  */
#line 596 "hawkinslang.y"
                 { (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval)); }
#line 2455 "hawkinslang.tab.c"
    break;

  case 137: /* primary_expression: INTEGER_LITERAL  */
#line 597 "hawkinslang.y"
                      { 
         char buf[32]; sprintf(buf, "%d", (yyvsp[0].ival));
         (yyval.node) = create_node(NODE_LITERAL_INT, strdup(buf)); 
      }
#line 2464 "hawkinslang.tab.c"
    break;

  case 138: /* primary_expression: FLOAT_LITERAL  */
#line 601 "hawkinslang.y"
                    {
         char buf[64]; sprintf(buf, "%f", (yyvsp[0].fval)); // Basic float formatting
         (yyval.node) = create_node(NODE_LITERAL_FLOAT, strdup(buf));
      }
#line 2473 "hawkinslang.tab.c"
    break;

  case 139: /* primary_expression: STRING_LITERAL  */
#line 605 "hawkinslang.y"
                     { 
         // String literal already includes quotes from lexer usually, or not?
         // Lexer: \"([^\\\"]|\\.)*\" -> returns full string including quotes
         (yyval.node) = create_node(NODE_LITERAL_STRING, (yyvsp[0].sval)); 
      }
#line 2483 "hawkinslang.tab.c"
    break;

  case 140: /* primary_expression: LPAREN expression RPAREN  */
#line 610 "hawkinslang.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2489 "hawkinslang.tab.c"
    break;

  case 141: /* primary_expression: RADIO_OUT  */
#line 611 "hawkinslang.y"
                { (yyval.node) = create_node(NODE_IDENTIFIER, "printf"); }
#line 2495 "hawkinslang.tab.c"
    break;

  case 142: /* primary_expression: RADIO_IN  */
#line 612 "hawkinslang.y"
               { (yyval.node) = create_node(NODE_IDENTIFIER, "scanf"); }
#line 2501 "hawkinslang.tab.c"
    break;

  case 143: /* primary_expression: FRIENDSDONTLIE  */
#line 613 "hawkinslang.y"
                     { (yyval.node) = create_node(NODE_LITERAL_INT, "1"); }
#line 2507 "hawkinslang.tab.c"
    break;

  case 144: /* primary_expression: LIES  */
#line 614 "hawkinslang.y"
           { (yyval.node) = create_node(NODE_LITERAL_INT, "0"); }
#line 2513 "hawkinslang.tab.c"
    break;

  case 145: /* primary_expression: NOTHING  */
#line 615 "hawkinslang.y"
              { (yyval.node) = create_node(NODE_LITERAL_INT, "0"); }
#line 2519 "hawkinslang.tab.c"
    break;

  case 146: /* argument_expression_list: assignment_expression  */
#line 619 "hawkinslang.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2525 "hawkinslang.tab.c"
    break;

  case 147: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 621 "hawkinslang.y"
        {
             ASTNode *p = (yyvsp[-2].node);
             while(p->next) p = p->next;
             p->next = (yyvsp[0].node);
             (yyval.node) = (yyvsp[-2].node);
        }
#line 2536 "hawkinslang.tab.c"
    break;


#line 2540 "hawkinslang.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 629 "hawkinslang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
    syntax_errors++;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("HawkinsLang Compiler\n");
        printf("Enter code (Ctrl+D to end):\n");
    }

    yyparse();

    if (syntax_errors == 0 && root != NULL) {
        fprintf(stderr, "\nRunning Optimizations (Constant Folding)...\n");
        optimize_ast(root);

        fprintf(stderr, "\nGenerating Intermediate Code (3-Address Code)...\n");
        fprintf(stderr, "==============================================\n");
        // Simple TAC generation 
        generate_tac(root);
        
        fprintf(stderr, "\nGenerating C Code...\n");
        fprintf(stderr, "====================\n\n");
        generate_c_code(root);
    } else {
        printf("Compilation failed with %d errors.\n", syntax_errors);
    }

    return 0;
}
