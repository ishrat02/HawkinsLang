%{
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
%}

%union {
    int ival;
    float fval;
    char *sval;
    ASTNode *node;
}

/* Token declarations */
%token <sval> IDENTIFIER STRING_LITERAL
%token <ival> INTEGER_LITERAL
%token <fval> FLOAT_LITERAL

/* Keywords */
%token HAWKINS PORTAL
%token ELEVEN SIGNAL FULL_SIGNAL LETTER THE_VOID
%token NOTHING
%token PRIMARY_GATE SECONDARY_GATE TAKE_COVER
%token CHOOSE_GATE GATE_CASE FALLBACK
%token COUNTDOWN CLOCK_CHIME INVADE
%token ESCAPE SLIP
%token HIVE THE_BRIDGE MR_WHATSIT CODENAME
%token RADIO_OUT RADIO_IN
%token DANGERIF_ALL_OPEN THREATIF_ANY_OPEN UPSIDE_DOWN
%token FRIENDSDONTLIE LIES
%token SEALED UNSTABLE ROOTED THE_ABYSS
%token GAUGE SUMMONED SHUTDOWN TO_REAL_WORLD
%token LIBRARY_IMPORT MACRO_DEF

/* Operators */
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token EQ NE LT GT LE GE
%token INCREMENT DECREMENT
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT
%token LEFT_SHIFT RIGHT_SHIFT
%token ARROW DOT

/* Delimiters */
%token SEMICOLON COMMA COLON
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

/* Operator precedence and associativity */
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left THREATIF_ANY_OPEN
%left DANGERIF_ALL_OPEN
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left EQ NE
%left LT GT LE GE
%left LEFT_SHIFT RIGHT_SHIFT
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right UPSIDE_DOWN BITWISE_NOT
%right INCREMENT DECREMENT
%left LPAREN RPAREN LBRACKET RBRACKET DOT ARROW

/* Non-terminal types */
%type <node> program translation_unit external_declaration
%type <node> function_definition function_declaration variable_declaration
%type <node> preprocessor_directive struct_declaration union_declaration typedef_declaration enum_declaration
%type <node> type_specifier declarator_list declarator initializer_list
%type <node> parameter_list parameter_declaration
%type <node> statement compound_statement 
%type <node> expression_statement selection_statement iteration_statement jump_statement labeled_statement declaration
%type <node> expression assignment_expression logical_or_expression logical_and_expression
%type <node> inclusive_or_expression exclusive_or_expression and_expression
%type <node> equality_expression relational_expression shift_expression
%type <node> additive_expression multiplicative_expression cast_expression
%type <node> unary_expression postfix_expression primary_expression
%type <node> argument_expression_list block_item block_item_list constant_expression switch_case switch_case_list

%%

/* Grammar Rules */

program
    : translation_unit
        { root = $1; }
    ;

translation_unit
    : external_declaration 
        { $$ = $1; }
    | translation_unit external_declaration
        { 
            if ($1 == NULL) {
                $$ = $2;
            } else {
                ASTNode *p = $1;
                while (p->next != NULL) {
                     p = p->next;
                }
                p->next = $2;
                $$ = $1;
            }
        }
    ;

external_declaration
    : function_definition { $$ = $1; }
    | function_declaration { $$ = $1; }
    | variable_declaration { $$ = $1; }
    | preprocessor_directive { $$ = $1; }
    | struct_declaration { $$ = $1; }
    | union_declaration { $$ = $1; }
    | typedef_declaration { $$ = $1; }
    | enum_declaration { $$ = $1; }
    ;

/* Preprocessor directives */
preprocessor_directive
    : LIBRARY_IMPORT STRING_LITERAL
        { $$ = create_node(NODE_PROGRAM, $2); /* TODO: specialized node */ }
    | MACRO_DEF IDENTIFIER expression
        { $$ = create_node(NODE_PROGRAM, $2); }
    ;

/* Type specifiers */
type_specifier
    : ELEVEN            { $$ = create_node(NODE_TYPE, "int"); }
    | SIGNAL            { $$ = create_node(NODE_TYPE, "float"); }
    | FULL_SIGNAL       { $$ = create_node(NODE_TYPE, "double"); }
    | LETTER            { $$ = create_node(NODE_TYPE, "char"); }
    | THE_VOID          { $$ = create_node(NODE_TYPE, "void"); }
    | IDENTIFIER        { $$ = create_node(NODE_TYPE, $1); } 
    ;

/* Variable declarations */
variable_declaration
    : type_specifier declarator_list SEMICOLON
        { 
            // Correct the AST structure: NODE_VAR_DECL -> left: type, right: declarators
            $$ = create_node(NODE_VAR_DECL, NULL);
            $$->left = $1;
            $$->right = $2;
        }
    ;

declarator_list
    : declarator
        { $$ = $1; }
    | declarator_list COMMA declarator
        { 
            // Chain declarators
            ASTNode *p = $1;
            while(p->next != NULL) {
                 p = p->next;
            }
            p->next = $3;
            $$ = $1;
        }
    ;

declarator
    : IDENTIFIER
        { $$ = create_node(NODE_IDENTIFIER, $1); }
    | IDENTIFIER ASSIGN expression
        { 
            // In a declaration like 'eleven i = 0;', the declarator needs to carry the assignment
            // We'll treat this as an identifier node that HAS an assignment attached
            $$ = create_node(NODE_IDENTIFIER, $1); 
            $$->right = $3; // Store initializer in right child
        }
    | IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET
        { 
             char buf[64]; sprintf(buf, "%s", $1);
             $$ = create_node(NODE_IDENTIFIER, strdup(buf));
             // Array dimension could be stored in meta-data or a child
             // Simplified: Treating as identifier for now
        }
    | IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET ASSIGN LBRACE initializer_list RBRACE
        {
             char buf[64]; sprintf(buf, "%s", $1);
             $$ = create_node(NODE_IDENTIFIER, strdup(buf));
             // Array init: simplified
        }
    ;

initializer_list
    : expression
        { $$ = $1; }
    | initializer_list COMMA expression
        { 
             ASTNode *p = $1;
             while(p->next) p = p->next;
             p->next = $3;
             $$ = $1;
        }
    ;

/* Function declarations and definitions */
function_declaration
    : type_specifier PORTAL IDENTIFIER LPAREN parameter_list RPAREN SEMICOLON
        { 
            $$ = create_func_def($1, $3, $5, NULL);
        }
    | type_specifier PORTAL IDENTIFIER LPAREN RPAREN SEMICOLON
        { 
             $$ = create_func_def($1, $3, NULL, NULL);
        }
    ;

function_definition
    : type_specifier PORTAL IDENTIFIER LPAREN parameter_list RPAREN compound_statement
        { 
             $$ = create_func_def($1, $3, $5, $7);
        }
    | type_specifier PORTAL IDENTIFIER LPAREN RPAREN compound_statement
        { 
             $$ = create_func_def($1, $3, NULL, $6);
        }
    | THE_VOID HAWKINS LPAREN RPAREN compound_statement
        { 
             $$ = create_func_def(create_node(NODE_TYPE, "void"), "main", NULL, $5);
        }
    ;

parameter_list
    : parameter_declaration
        { $$ = $1; }
    | parameter_list COMMA parameter_declaration
        { 
            ASTNode *p = $1;
            while(p->next) p = p->next;
            p->next = $3;
            $$ = $1;
        }
    ;

parameter_declaration
    : type_specifier IDENTIFIER
        { 
            $$ = create_node(NODE_PARAMETER, $2);
            $$->left = $1;
        }
    ;

/* Struct declaration */
struct_declaration
    : HIVE IDENTIFIER LBRACE RBRACE SEMICOLON
        { $$ = create_node(NODE_STRUCT_DEF, $2); }
    /* Simplified for demo - need member list in real implementation */
    ;

union_declaration
    : THE_BRIDGE IDENTIFIER LBRACE RBRACE SEMICOLON
        { $$ = create_node(NODE_UNION_DEF, $2); }
    ;

typedef_declaration
    : MR_WHATSIT type_specifier IDENTIFIER SEMICOLON
        { 
            $$ = create_node(NODE_TYPEDEF, $3);
            $$->left = $2;
        }
    ;

enum_declaration
    : CODENAME IDENTIFIER LBRACE RBRACE SEMICOLON
        { $$ = create_node(NODE_ENUM_DEF, $2); }
    ;

/* Statements */
statement
    : compound_statement { $$ = $1; }
    | expression_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    | labeled_statement { $$ = $1; }
    ;

labeled_statement
    : GATE_CASE expression COLON statement
        { 
             $$ = create_node(NODE_CASE, "case");
             $$->left = $2;
             $$->right = $4;
        }
    | FALLBACK COLON statement
        {
             $$ = create_node(NODE_DEFAULT, "default");
             $$->left = $3;
        }
    | IDENTIFIER COLON statement
        {
             // Goto label definition - simplified, assumes next stmt gets linked implicitly
             // or creates a label node
             $$ = create_node(NODE_IDENTIFIER, $1);
        }
    ;

compound_statement
    : LBRACE RBRACE
        { $$ = create_node(NODE_BLOCK, NULL); }
    | LBRACE block_item_list RBRACE
        { 
            $$ = create_node(NODE_BLOCK, NULL);
            $$->left = $2;
        }
    ;

block_item_list
    : block_item
        { $$ = $1; }
    | block_item_list block_item
        {
            if ($1 == NULL) $$ = $2;
            else {
                ASTNode *p = $1;
                while(p->next) p = p->next;
                p->next = $2;
                $$ = $1;
            }
        }
    ;

block_item
    : declaration { $$ = $1; }
    | statement { $$ = $1; }
    ;

expression_statement
    : SEMICOLON { $$ = NULL; }
    | expression SEMICOLON { $$ = $1; }
    | declaration { $$ = $1; }  /* Allow declarations where expressions are expected for C99 style */
    ;

selection_statement
    : PRIMARY_GATE LPAREN expression RPAREN statement
        { $$ = create_if_node($3, $5, NULL); }
    | PRIMARY_GATE LPAREN expression RPAREN statement TAKE_COVER statement
        { $$ = create_if_node($3, $5, $7); }
    | CHOOSE_GATE LPAREN expression RPAREN LBRACE switch_case_list RBRACE
        { 
            $$ = create_node(NODE_SWITCH, "switch");
            $$->left = $3;
            $$->right = $6;
        }
    ;

switch_case_list
    : switch_case
        { $$ = $1; }
    | switch_case_list switch_case
        {
            ASTNode *p = $1;
            if (p) {
                while(p->next) p = p->next;
                p->next = $2;
            }
            $$ = $1;
        }
    ;

switch_case
    : GATE_CASE constant_expression COLON block_item_list
        { 
             $$ = create_node(NODE_CASE, "case");
             $$->left = $2;
             $$->right = $4;
        }
    | FALLBACK COLON block_item_list
        {
             $$ = create_node(NODE_DEFAULT, "default");
             $$->left = $3;
        }
    ;

constant_expression
    : constant_expression PLUS constant_expression {
         $$ = create_binary_node(NODE_BINARY_OP, "+", $1, $3);
    }
    | constant_expression MINUS constant_expression {
         $$ = create_binary_node(NODE_BINARY_OP, "-", $1, $3);
    }
    | constant_expression MULTIPLY constant_expression {
         $$ = create_binary_node(NODE_BINARY_OP, "*", $1, $3);
    }
    | constant_expression DIVIDE constant_expression {
         $$ = create_binary_node(NODE_BINARY_OP, "/", $1, $3);
    }
    | INTEGER_LITERAL { 
         char buf[32]; sprintf(buf, "%d", $1);
         $$ = create_node(NODE_LITERAL_INT, strdup(buf)); 
    }
    | IDENTIFIER { $$ = create_node(NODE_IDENTIFIER, $1); }
    ;

iteration_statement
    : CLOCK_CHIME LPAREN expression RPAREN statement
        { $$ = create_while_node($3, $5); }
    | INVADE statement CLOCK_CHIME LPAREN expression RPAREN SEMICOLON
        { 
            $$ = create_node(NODE_DO_WHILE, "do_while");
            $$->left = $5; // Condition
            $$->right = $2; // Body
        }
    | COUNTDOWN LPAREN expression_statement expression_statement expression RPAREN statement
        { 
            $$ = create_for_node($3, $4, $5, $7);
        }
    | COUNTDOWN LPAREN declaration expression_statement expression RPAREN statement
        {
             // For loop with declaration: for (int i=0; ...
             $$ = create_for_node($3, $4, $5, $7);
        }
    ;

jump_statement
    : ESCAPE SEMICOLON { $$ = create_node(NODE_BREAK, NULL); }
    | SLIP SEMICOLON { $$ = create_node(NODE_CONTINUE, NULL); }
    | TO_REAL_WORLD expression SEMICOLON 
        { 
            $$ = create_node(NODE_RETURN, NULL); 
            $$->left = $2;
        }
    | TO_REAL_WORLD SEMICOLON 
        { $$ = create_node(NODE_RETURN, NULL); }
    | SUMMONED IDENTIFIER SEMICOLON
        {
             char buf[128]; sprintf(buf, "goto %s", $2);
             $$ = create_node(NODE_IDENTIFIER, strdup(buf)); // Simplified
        }
    | SHUTDOWN LPAREN expression RPAREN SEMICOLON
        {
             $$ = create_node(NODE_FUNC_CALL, "exit");
             $$->left = $3;
        }
    ;

declaration
    : variable_declaration { $$ = $1; }
    ;


/* Expressions */
expression
    : assignment_expression { $$ = $1; }
    | expression COMMA assignment_expression 
        { 
            // Simplified: return last expr or block? 
            $$ = $3; 
        }
    ;

assignment_expression
    : logical_or_expression { $$ = $1; }
    | unary_expression ASSIGN assignment_expression
        { $$ = create_binary_node(NODE_ASSIGN, "=", $1, $3); }
    | unary_expression PLUS_ASSIGN assignment_expression
        { $$ = create_binary_node(NODE_ASSIGN, "+=", $1, $3); }
    | unary_expression MINUS_ASSIGN assignment_expression
        { $$ = create_binary_node(NODE_ASSIGN, "-=", $1, $3); }
    | unary_expression MULT_ASSIGN assignment_expression
        { $$ = create_binary_node(NODE_ASSIGN, "*=", $1, $3); }
    | unary_expression DIV_ASSIGN assignment_expression
        { $$ = create_binary_node(NODE_ASSIGN, "/=", $1, $3); }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression THREATIF_ANY_OPEN logical_and_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "||", $1, $3); }
    ;

logical_and_expression
    : inclusive_or_expression { $$ = $1; }
    | logical_and_expression DANGERIF_ALL_OPEN inclusive_or_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "&&", $1, $3); }
    ;

inclusive_or_expression
    : exclusive_or_expression { $$ = $1; }
    | inclusive_or_expression BITWISE_OR exclusive_or_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "|", $1, $3); }
    ;

exclusive_or_expression
    : and_expression { $$ = $1; }
    | exclusive_or_expression BITWISE_XOR and_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "^", $1, $3); }
    ;

and_expression
    : equality_expression { $$ = $1; }
    | and_expression BITWISE_AND equality_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "&", $1, $3); }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "==", $1, $3); }
    | equality_expression NE relational_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "!=", $1, $3); }
    ;

relational_expression
    : shift_expression { $$ = $1; }
    | relational_expression LT shift_expression { $$ = create_binary_node(NODE_BINARY_OP, "<", $1, $3); }
    | relational_expression GT shift_expression { $$ = create_binary_node(NODE_BINARY_OP, ">", $1, $3); }
    | relational_expression LE shift_expression { $$ = create_binary_node(NODE_BINARY_OP, "<=", $1, $3); }
    | relational_expression GE shift_expression { $$ = create_binary_node(NODE_BINARY_OP, ">=", $1, $3); }
    ;

shift_expression
    : additive_expression { $$ = $1; }
    | shift_expression LEFT_SHIFT additive_expression { $$ = create_binary_node(NODE_BINARY_OP, "<<", $1, $3); }
    | shift_expression RIGHT_SHIFT additive_expression { $$ = create_binary_node(NODE_BINARY_OP, ">>", $1, $3); }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression { $$ = create_binary_node(NODE_BINARY_OP, "+", $1, $3); }
    | additive_expression MINUS multiplicative_expression { $$ = create_binary_node(NODE_BINARY_OP, "-", $1, $3); }
    ;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression MULTIPLY cast_expression { $$ = create_binary_node(NODE_BINARY_OP, "*", $1, $3); }
    | multiplicative_expression DIVIDE cast_expression { $$ = create_binary_node(NODE_BINARY_OP, "/", $1, $3); }
    | multiplicative_expression MODULO cast_expression { $$ = create_binary_node(NODE_BINARY_OP, "%", $1, $3); }
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | LPAREN type_specifier RPAREN cast_expression
        { 
             // Simplified cast node
             $$ = create_node(NODE_UNARY_OP, "cast");
             $$->left = $4;
             // type info ignored for now in this simple node structure, or store in val?
        }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | INCREMENT unary_expression { $$ = create_unary_node(NODE_UNARY_OP, "++", $2); }
    | DECREMENT unary_expression { $$ = create_unary_node(NODE_UNARY_OP, "--", $2); }
    | UPSIDE_DOWN unary_expression { $$ = create_unary_node(NODE_UNARY_OP, "!", $2); }
    | GAUGE unary_expression
        { $$ = create_unary_node(NODE_UNARY_OP, "sizeof", $2); }
    | GAUGE LPAREN type_specifier RPAREN
        { 
             ASTNode *sz = create_unary_node(NODE_UNARY_OP, "sizeof", $3);
             $$ = sz;
        }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LPAREN argument_expression_list RPAREN
        { 
            ASTNode *call = create_node(NODE_FUNC_CALL, $1->val); // Simplified, assume ID
            call->left = $3; // Arguments
            $$ = call;
        }
    | postfix_expression LPAREN RPAREN
        { 
            ASTNode *call = create_node(NODE_FUNC_CALL, $1->val);
            $$ = call;
        }
    | postfix_expression LBRACKET expression RBRACKET
        { 
             $$ = create_binary_node(NODE_BINARY_OP, "[]", $1, $3);
        }
    | postfix_expression DOT IDENTIFIER
        { $$ = create_binary_node(NODE_BINARY_OP, ".", $1, create_node(NODE_IDENTIFIER, $3)); }
    | postfix_expression ARROW IDENTIFIER
        { $$ = create_binary_node(NODE_BINARY_OP, "->", $1, create_node(NODE_IDENTIFIER, $3)); }
    | postfix_expression INCREMENT { $$ = create_unary_node(NODE_UNARY_OP, "p++", $1); } // Postfix vs prefix distinction needed in codegen
    | postfix_expression DECREMENT { $$ = create_unary_node(NODE_UNARY_OP, "p--", $1); }
    ;

primary_expression
    : IDENTIFIER { $$ = create_node(NODE_IDENTIFIER, $1); }
    | INTEGER_LITERAL { 
         char buf[32]; sprintf(buf, "%d", $1);
         $$ = create_node(NODE_LITERAL_INT, strdup(buf)); 
      }
    | FLOAT_LITERAL {
         char buf[64]; sprintf(buf, "%f", $1); // Basic float formatting
         $$ = create_node(NODE_LITERAL_FLOAT, strdup(buf));
      }
    | STRING_LITERAL { 
         // String literal already includes quotes from lexer usually, or not?
         // Lexer: \"([^\\\"]|\\.)*\" -> returns full string including quotes
         $$ = create_node(NODE_LITERAL_STRING, $1); 
      }
    | LPAREN expression RPAREN { $$ = $2; }
    | RADIO_OUT { $$ = create_node(NODE_IDENTIFIER, "printf"); }
    | RADIO_IN { $$ = create_node(NODE_IDENTIFIER, "scanf"); }
    | FRIENDSDONTLIE { $$ = create_node(NODE_LITERAL_INT, "1"); }
    | LIES { $$ = create_node(NODE_LITERAL_INT, "0"); }
    | NOTHING { $$ = create_node(NODE_LITERAL_INT, "0"); }
    ;

argument_expression_list
    : assignment_expression { $$ = $1; }
    | argument_expression_list COMMA assignment_expression
        {
             ASTNode *p = $1;
             while(p->next) p = p->next;
             p->next = $3;
             $$ = $1;
        }
    ;

%%

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
