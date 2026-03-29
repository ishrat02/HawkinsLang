/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HAWKINSLANG_TAB_H_INCLUDED
# define YY_YY_HAWKINSLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    INTEGER_LITERAL = 260,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 261,           /* FLOAT_LITERAL  */
    HAWKINS = 262,                 /* HAWKINS  */
    PORTAL = 263,                  /* PORTAL  */
    ELEVEN = 264,                  /* ELEVEN  */
    SIGNAL = 265,                  /* SIGNAL  */
    FULL_SIGNAL = 266,             /* FULL_SIGNAL  */
    LETTER = 267,                  /* LETTER  */
    THE_VOID = 268,                /* THE_VOID  */
    NOTHING = 269,                 /* NOTHING  */
    PRIMARY_GATE = 270,            /* PRIMARY_GATE  */
    SECONDARY_GATE = 271,          /* SECONDARY_GATE  */
    TAKE_COVER = 272,              /* TAKE_COVER  */
    CHOOSE_GATE = 273,             /* CHOOSE_GATE  */
    GATE_CASE = 274,               /* GATE_CASE  */
    FALLBACK = 275,                /* FALLBACK  */
    COUNTDOWN = 276,               /* COUNTDOWN  */
    CLOCK_CHIME = 277,             /* CLOCK_CHIME  */
    INVADE = 278,                  /* INVADE  */
    ESCAPE = 279,                  /* ESCAPE  */
    SLIP = 280,                    /* SLIP  */
    HIVE = 281,                    /* HIVE  */
    THE_BRIDGE = 282,              /* THE_BRIDGE  */
    MR_WHATSIT = 283,              /* MR_WHATSIT  */
    CODENAME = 284,                /* CODENAME  */
    RADIO_OUT = 285,               /* RADIO_OUT  */
    RADIO_IN = 286,                /* RADIO_IN  */
    DANGERIF_ALL_OPEN = 287,       /* DANGERIF_ALL_OPEN  */
    THREATIF_ANY_OPEN = 288,       /* THREATIF_ANY_OPEN  */
    UPSIDE_DOWN = 289,             /* UPSIDE_DOWN  */
    FRIENDSDONTLIE = 290,          /* FRIENDSDONTLIE  */
    LIES = 291,                    /* LIES  */
    SEALED = 292,                  /* SEALED  */
    UNSTABLE = 293,                /* UNSTABLE  */
    ROOTED = 294,                  /* ROOTED  */
    THE_ABYSS = 295,               /* THE_ABYSS  */
    GAUGE = 296,                   /* GAUGE  */
    SUMMONED = 297,                /* SUMMONED  */
    SHUTDOWN = 298,                /* SHUTDOWN  */
    TO_REAL_WORLD = 299,           /* TO_REAL_WORLD  */
    LIBRARY_IMPORT = 300,          /* LIBRARY_IMPORT  */
    MACRO_DEF = 301,               /* MACRO_DEF  */
    PLUS = 302,                    /* PLUS  */
    MINUS = 303,                   /* MINUS  */
    MULTIPLY = 304,                /* MULTIPLY  */
    DIVIDE = 305,                  /* DIVIDE  */
    MODULO = 306,                  /* MODULO  */
    ASSIGN = 307,                  /* ASSIGN  */
    PLUS_ASSIGN = 308,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 309,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 310,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 311,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 312,              /* MOD_ASSIGN  */
    EQ = 313,                      /* EQ  */
    NE = 314,                      /* NE  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    INCREMENT = 319,               /* INCREMENT  */
    DECREMENT = 320,               /* DECREMENT  */
    BITWISE_AND = 321,             /* BITWISE_AND  */
    BITWISE_OR = 322,              /* BITWISE_OR  */
    BITWISE_XOR = 323,             /* BITWISE_XOR  */
    BITWISE_NOT = 324,             /* BITWISE_NOT  */
    LEFT_SHIFT = 325,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 326,             /* RIGHT_SHIFT  */
    ARROW = 327,                   /* ARROW  */
    DOT = 328,                     /* DOT  */
    SEMICOLON = 329,               /* SEMICOLON  */
    COMMA = 330,                   /* COMMA  */
    COLON = 331,                   /* COLON  */
    LPAREN = 332,                  /* LPAREN  */
    RPAREN = 333,                  /* RPAREN  */
    LBRACE = 334,                  /* LBRACE  */
    RBRACE = 335,                  /* RBRACE  */
    LBRACKET = 336,                /* LBRACKET  */
    RBRACKET = 337                 /* RBRACKET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "hawkinslang.y"

    int ival;
    float fval;
    char *sval;
    ASTNode *node;

#line 153 "hawkinslang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HAWKINSLANG_TAB_H_INCLUDED  */
