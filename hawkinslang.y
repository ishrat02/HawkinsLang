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
%type <node> statement compound_statement statement_list
%type <node> expression_statement selection_statement iteration_statement jump_statement labeled_statement declaration
%type <node> expression assignment_expression logical_or_expression logical_and_expression
%type <node> inclusive_or_expression exclusive_or_expression and_expression
%type <node> equality_expression relational_expression shift_expression
%type <node> additive_expression multiplicative_expression cast_expression
%type <node> unary_expression postfix_expression primary_expression
%type <node> argument_expression_list

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
            ASTNode *p = $1;
            while (p->next != NULL) p = p->next;
            p->next = $2;
            $$ = $1;
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
            $$ = create_node(NODE_VAR_DECL, NULL); // Placeholder wrapper
            $$->left = $1;
            $$->right = $2;
        }
    ;

declarator_list
    : declarator
        { $$ = $1; }
    | declarator_list COMMA declarator
        { 
            ASTNode *p = $1;
            while(p->next) p = p->next;
            p->next = $3;
            $$ = $1;
        }
    ;

declarator
    : IDENTIFIER
        { $$ = create_node(NODE_IDENTIFIER, $1); }
    | IDENTIFIER ASSIGN expression
        { 
            $$ = create_node(NODE_ASSIGN, $1); 
            $$->right = $3; 
        }
    | IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET
        { 
             char buf[64]; sprintf(buf, "%s[%d]", $1, $3);
             $$ = create_node(NODE_IDENTIFIER, strdup(buf));
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
             // Goto label definition
             $$ = create_node(NODE_IDENTIFIER, $1); // Simplified
             // In C AST, usually separate Label type. For now, treating as ID.
        }
    ;

compound_statement
    : LBRACE RBRACE
        { $$ = create_node(NODE_BLOCK, NULL); }
    | LBRACE statement_list RBRACE
        { 
            $$ = create_node(NODE_BLOCK, NULL);
            $$->left = $2;
        }
    ;

statement_list
    : statement
        { $$ = $1; }
    | statement_list statement
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

expression_statement
    : SEMICOLON { $$ = NULL; }
    | expression SEMICOLON { $$ = $1; }
    ;

selection_statement
    : PRIMARY_GATE LPAREN expression RPAREN statement
        { $$ = create_if_node($3, $5, NULL); }
    | PRIMARY_GATE LPAREN expression RPAREN statement TAKE_COVER statement
        { $$ = create_if_node($3, $5, $7); }
    | PRIMARY_GATE LPAREN expression RPAREN statement SECONDARY_GATE LPAREN expression RPAREN statement
        { 
            // if (e1) s1 else if (e2) s2
            // -> if (e1) s1 else { if (e2) s2 }
            ASTNode *nested_if = create_if_node($8, $10, NULL);
            $$ = create_if_node($3, $5, nested_if);
        }
    | CHOOSE_GATE LPAREN expression RPAREN statement
        { 
            $$ = create_node(NODE_SWITCH, "switch");
            $$->left = $3;
            $$->right = $5;
        }
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
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression THREATIF_ANY_OPEN logical_and_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "||", $1, $3); }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression DANGERIF_ALL_OPEN equality_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "&&", $1, $3); }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "==", $1, $3); }
    | equality_expression NE relational_expression
        { $$ = create_binary_node(NODE_BINARY_OP, "!=", $1, $3); }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LT additive_expression { $$ = create_binary_node(NODE_BINARY_OP, "<", $1, $3); }
    | relational_expression GT additive_expression { $$ = create_binary_node(NODE_BINARY_OP, ">", $1, $3); }
    | relational_expression LE additive_expression { $$ = create_binary_node(NODE_BINARY_OP, "<=", $1, $3); }
    | relational_expression GE additive_expression { $$ = create_binary_node(NODE_BINARY_OP, ">=", $1, $3); }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression { $$ = create_binary_node(NODE_BINARY_OP, "+", $1, $3); }
    | additive_expression MINUS multiplicative_expression { $$ = create_binary_node(NODE_BINARY_OP, "-", $1, $3); }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression MULTIPLY unary_expression { $$ = create_binary_node(NODE_BINARY_OP, "*", $1, $3); }
    | multiplicative_expression DIVIDE unary_expression { $$ = create_binary_node(NODE_BINARY_OP, "/", $1, $3); }
    | multiplicative_expression MODULO unary_expression { $$ = create_binary_node(NODE_BINARY_OP, "%", $1, $3); }
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
    | FRIENDSDONTLIE { $$ = create_node(NODE_LITERAL_INT, "true"); }
    | LIES { $$ = create_node(NODE_LITERAL_INT, "false"); }
    | NOTHING { $$ = create_node(NODE_LITERAL_INT, "NULL"); }
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

    if (syntax_errors == 0) {
        printf("\nRunning Optimizations (Constant Folding)...\n");
        optimize_ast(root);

        printf("\nGenerating Intermediate Code (3-Address Code)...\n");
        printf("==============================================\n");
        // Simple TAC generation (this is a conceptual demonstration)
        // In a real compiler, we would use a more robust TAC structure.
        // For now, let's just inspect the tree nodes.
        // (Function not fully implemented in ast.c perfectly for all cases, but structure exists)
        
        printf("\nGenerating C Code...\n");
        printf("====================\n\n");
        generate_c_code(root);
    }

    return 0;
}


statement_list
    : statement
    | statement_list statement
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | variable_declaration
    | io_statement
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

/* Selection statements (conditionals) */
selection_statement
    : PRIMARY_GATE LPAREN expression RPAREN statement
        { printf("✓ If statement recognized\n"); }
    | PRIMARY_GATE LPAREN expression RPAREN statement TAKE_COVER statement
        { printf("✓ If-else statement recognized\n"); }
    | PRIMARY_GATE LPAREN expression RPAREN statement SECONDARY_GATE LPAREN expression RPAREN statement
        { printf("✓ If-elseif statement recognized\n"); }
    | PRIMARY_GATE LPAREN expression RPAREN statement SECONDARY_GATE LPAREN expression RPAREN statement TAKE_COVER statement
        { printf("✓ If-elseif-else statement recognized\n"); }
    | CHOOSE_GATE LPAREN expression RPAREN LBRACE switch_case_list RBRACE
        { printf("✓ Switch statement recognized\n"); }
    ;

switch_case_list
    : switch_case
    | switch_case_list switch_case
    ;

switch_case
    : GATE_CASE constant_expression COLON statement_list
    | FALLBACK COLON statement_list
    ;

constant_expression
    : INTEGER_LITERAL
    | IDENTIFIER
    ;

/* Iteration statements (loops) */
iteration_statement
    : COUNTDOWN LPAREN expression_statement expression_statement RPAREN statement
        { printf("✓ For loop recognized\n"); }
    | COUNTDOWN LPAREN expression_statement expression_statement expression RPAREN statement
        { printf("✓ For loop recognized\n"); }
    | CLOCK_CHIME LPAREN expression RPAREN statement
        { printf("✓ While loop recognized\n"); }
    | INVADE statement CLOCK_CHIME LPAREN expression RPAREN SEMICOLON
        { printf("✓ Do-while loop recognized\n"); }
    ;

/* Jump statements */
jump_statement
    : ESCAPE SEMICOLON
        { printf("✓ Break statement\n"); }
    | SLIP SEMICOLON
        { printf("✓ Continue statement\n"); }
    | TO_REAL_WORLD SEMICOLON
        { printf("✓ Return statement (void)\n"); }
    | TO_REAL_WORLD expression SEMICOLON
        { printf("✓ Return statement\n"); }
    | SUMMONED IDENTIFIER SEMICOLON
        { printf("✓ Goto statement to label: %s\n", $2); }
    | SHUTDOWN LPAREN expression RPAREN SEMICOLON
        { printf("✓ Exit statement\n"); }
    | IDENTIFIER COLON
        { printf("✓ Label: %s\n", $1); }
    ;

/* I/O statements */
io_statement
    : RADIO_OUT LPAREN argument_expression_list RPAREN SEMICOLON
        { printf("✓ Output statement (radio_out)\n"); }
    | RADIO_IN LPAREN argument_expression_list RPAREN SEMICOLON
        { printf("✓ Input statement (radio_in)\n"); }
    ;

/* Expressions */
expression
    : assignment_expression
    | expression COMMA assignment_expression
    ;

assignment_expression
    : logical_or_expression
    | unary_expression assignment_operator assignment_expression
    ;

assignment_operator
    : ASSIGN
    | PLUS_ASSIGN
    | MINUS_ASSIGN
    | MULT_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression THREATIF_ANY_OPEN logical_and_expression
    ;

logical_and_expression
    : bitwise_or_expression
    | logical_and_expression DANGERIF_ALL_OPEN bitwise_or_expression
    ;

bitwise_or_expression
    : bitwise_xor_expression
    | bitwise_or_expression BITWISE_OR bitwise_xor_expression
    ;

bitwise_xor_expression
    : bitwise_and_expression
    | bitwise_xor_expression BITWISE_XOR bitwise_and_expression
    ;

bitwise_and_expression
    : equality_expression
    | bitwise_and_expression BITWISE_AND equality_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NE relational_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LT shift_expression
    | relational_expression GT shift_expression
    | relational_expression LE shift_expression
    | relational_expression GE shift_expression
    ;

shift_expression
    : additive_expression
    | shift_expression LEFT_SHIFT additive_expression
    | shift_expression RIGHT_SHIFT additive_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression MULTIPLY unary_expression
    | multiplicative_expression DIVIDE unary_expression
    | multiplicative_expression MODULO unary_expression
    ;

unary_expression
    : postfix_expression
    | INCREMENT unary_expression
    | DECREMENT unary_expression
    | unary_operator unary_expression
    | GAUGE LPAREN type_specifier RPAREN
    | GAUGE LPAREN unary_expression RPAREN
    ;

unary_operator
    : PLUS
    | MINUS
    | UPSIDE_DOWN
    | BITWISE_NOT
    | MULTIPLY  /* pointer dereference */
    | BITWISE_AND  /* address-of */
    ;

postfix_expression
    : primary_expression
    | postfix_expression LBRACKET expression RBRACKET
    | postfix_expression LPAREN RPAREN
        { printf("  Function call (no arguments)\n"); }
    | postfix_expression LPAREN argument_expression_list RPAREN
        { printf("  Function call with arguments\n"); }
    | postfix_expression DOT IDENTIFIER
    | postfix_expression ARROW IDENTIFIER
    | postfix_expression INCREMENT
    | postfix_expression DECREMENT
    ;

primary_expression
    : IDENTIFIER
        { 
            Symbol *sym = lookup_symbol($1);
            if (sym == NULL) {
                printf("⚠ Warning: Identifier '%s' used before declaration (line %d)\n", $1, line_num);
            }
        }
    | INTEGER_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | FRIENDSDONTLIE
    | LIES
    | NOTHING
    | LPAREN expression RPAREN
    ;

argument_expression_list
    : assignment_expression
    | argument_expression_list COMMA assignment_expression
    ;

%%

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
