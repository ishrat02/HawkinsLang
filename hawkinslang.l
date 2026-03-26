%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hawkinslang.tab.h"

int line_num = 1;
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [A-Za-z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+"."{DIGIT}+
WHITESPACE  [ \t\r]+

%%

    /* Comments */
"~~".*                      { /* Single-line comment */ }
"<~"([^~]|~[^>])*"~>"      { 
                                /* Multi-line comment */
                                char *p = yytext;
                                while (*p) {
                                    if (*p == '\n') line_num++;
                                    p++;
                                }
                            }

    /* Preprocessor directives */
"#library"                  { return LIBRARY_IMPORT; }
"#MACRO"                    { return MACRO_DEF; }

    /* Keywords - Main and Functions */
"hawkins"                   { return HAWKINS; }
"portal"                    { return PORTAL; }

    /* Data Types */
"eleven"                    { return ELEVEN; }
"signal"                    { return SIGNAL; }
"full_signal"               { return FULL_SIGNAL; }
"letter"                    { return LETTER; }
"the_void"                  { return THE_VOID; }

    /* Constants */
"nothing"                   { return NOTHING; }
"friendsdontlie"            { return FRIENDSDONTLIE; }
"lies"                      { return LIES; }

    /* Control Flow - Conditionals */
"primary_gate"              { return PRIMARY_GATE; }
"secondary_gate"            { return SECONDARY_GATE; }
"take_cover"                { return TAKE_COVER; }
"choose_gate"               { return CHOOSE_GATE; }
"gate_case"                 { return GATE_CASE; }
"fallback"                  { return FALLBACK; }

    /* Control Flow - Loops */
"countdown"                 { return COUNTDOWN; }
"clock_chime"               { return CLOCK_CHIME; }
"invade"                    { return INVADE; }
"escape"                    { return ESCAPE; }
"slip"                      { return SLIP; }

    /* Structured Types */
"hive"                      { return HIVE; }
"the_bridge"                { return THE_BRIDGE; }
"mr_whatsit"                { return MR_WHATSIT; }
"codename"                  { return CODENAME; }

    /* I/O Functions */
"radio_out"                 { return RADIO_OUT; }
"radio_in"                  { return RADIO_IN; }

    /* Logical Operators */
"dangerif_all_open"         { return DANGERIF_ALL_OPEN; }
"threatif_any_open"         { return THREATIF_ANY_OPEN; }
"upside_down"               { return UPSIDE_DOWN; }

    /* Storage Class Specifiers */
"sealed"                    { return SEALED; }
"unstable"                  { return UNSTABLE; }
"rooted"                    { return ROOTED; }
"the_abyss"                 { return THE_ABYSS; }

    /* Other Keywords */
"gauge"                     { return GAUGE; }
"summoned"                  { return SUMMONED; }
"shutdown"                  { return SHUTDOWN; }
"to_real_world"             { return TO_REAL_WORLD; }

    /* Comparison Operators */
"=="                        { return EQ; }
"!="                        { return NE; }
"<="                        { return LE; }
">="                        { return GE; }
"<"                         { return LT; }
">"                         { return GT; }

    /* Arithmetic Operators */
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }
"%"                         { return MODULO; }

    /* Assignment Operators */
"="                         { return ASSIGN; }
"+="                        { return PLUS_ASSIGN; }
"-="                        { return MINUS_ASSIGN; }
"*="                        { return MULT_ASSIGN; }
"/="                        { return DIV_ASSIGN; }
"%="                        { return MOD_ASSIGN; }

    /* Increment/Decrement */
"++"                        { return INCREMENT; }
"--"                        { return DECREMENT; }

    /* Bitwise Operators */
"&"                         { return BITWISE_AND; }
"|"                         { return BITWISE_OR; }
"^"                         { return BITWISE_XOR; }
"~"                         { return BITWISE_NOT; }
"<<"                        { return LEFT_SHIFT; }
">>"                        { return RIGHT_SHIFT; }

    /* Member Access */
"->"                        { return ARROW; }
"."                         { return DOT; }

    /* Delimiters */
";"                         { return SEMICOLON; }
","                         { return COMMA; }
":"                         { return COLON; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
"["                         { return LBRACKET; }
"]"                         { return RBRACKET; }

    /* Identifiers and Literals */
{IDENTIFIER}                { 
                                yylval.sval = strdup(yytext);
                                return IDENTIFIER;
                            }

{INTEGER}                   {
                                yylval.ival = atoi(yytext);
                                return INTEGER_LITERAL;
                            }

{FLOAT}                     {
                                yylval.fval = atof(yytext);
                                return FLOAT_LITERAL;
                            }

\"([^\\\"]|\\.)*\"          {
                                yylval.sval = strdup(yytext);
                                return STRING_LITERAL;
                            }

\'([^\\\']|\\.)?\'          {
                                yylval.ival = yytext[1];
                                return INTEGER_LITERAL; /* Treat char as int */
                            }

    /* Whitespace and Newlines */
{WHITESPACE}                { /* Ignore whitespace */ }
\n                          { line_num++; }

    /* Unrecognized characters */
.                           {
                                fprintf(stderr, "Lexical error at line %d: Unrecognized character '%s'\n", 
                                        line_num, yytext);
                            }

%%
