
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 50 "hawkinslang.y"

    int ival;
    float fval;
    char *sval;



/* Line 1676 of yacc.c  */
#line 142 "hawkinslang.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


