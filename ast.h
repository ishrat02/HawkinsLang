#ifndef AST_H
#define AST_H

typedef enum {
    NODE_PROGRAM,
    NODE_FUNCTION_DEF,
    NODE_VAR_DECL,
    NODE_CONST_DECL,
    NODE_STRUCT_DEF,
    NODE_UNION_DEF,
    NODE_ENUM_DEF,
    NODE_TYPEDEF,
    NODE_BLOCK,
    NODE_IF,
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_FOR,
    NODE_WHILE,
    NODE_DO_WHILE,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_RETURN,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_ASSIGN,
    NODE_FUNC_CALL,
    NODE_IDENTIFIER,
    NODE_LITERAL_INT,
    NODE_LITERAL_FLOAT,
    NODE_LITERAL_STRING,
    NODE_LITERAL_CHAR,
    NODE_TYPE,
    NODE_PARAMETER,
    NODE_EMPTY
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char *val;              // For identifiers, literals, operators
    struct ASTNode *left;   // Child 1 (or condition, or type)
    struct ASTNode *right;  // Child 2 (or body, or name)
    struct ASTNode *third;  // Child 3 (e.g., for loop update, else block)
    struct ASTNode *fourth; // Child 4 (e.g., for loop body) - generalized next
    struct ASTNode *next;   // For lists (statements, params)
} ASTNode;

// Node creation functions
ASTNode* create_node(NodeType type, char *val);
ASTNode* create_binary_node(NodeType type, char *op, ASTNode *left, ASTNode *right);
ASTNode* create_unary_node(NodeType type, char *op, ASTNode *child);
ASTNode* create_if_node(ASTNode *cond, ASTNode *then_block, ASTNode *else_block);
ASTNode* create_while_node(ASTNode *cond, ASTNode *body);
ASTNode* create_for_node(ASTNode *init, ASTNode *cond, ASTNode *incr, ASTNode *body);
ASTNode* create_func_def(ASTNode *ret_type, char *name, ASTNode *params, ASTNode *body);
void free_ast(ASTNode *node);

// Code generation
void generate_c_code(ASTNode *node);

// Optimization
void optimize_ast(ASTNode *node);

// Intermediate Code Generation (TAC)
void generate_tac(ASTNode *node);

#endif
