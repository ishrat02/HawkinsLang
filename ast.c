#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* create_node(NodeType type, char *val) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->val = val ? strdup(val) : NULL;
    node->left = NULL;
    node->right = NULL;
    node->third = NULL;
    node->fourth = NULL;
    node->next = NULL;
    return node;
}

ASTNode* create_binary_node(NodeType type, char *op, ASTNode *left, ASTNode *right) {
    ASTNode *node = create_node(type, op);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_unary_node(NodeType type, char *op, ASTNode *child) {
    ASTNode *node = create_node(type, op);
    node->left = child;
    return node;
}

ASTNode* create_if_node(ASTNode *cond, ASTNode *then_block, ASTNode *else_block) {
    ASTNode *node = create_node(NODE_IF, "primary_gate");
    node->left = cond;
    node->right = then_block;
    node->third = else_block;
    return node;
}

ASTNode* create_while_node(ASTNode *cond, ASTNode *body) {
    ASTNode *node = create_node(NODE_WHILE, "clock_chime");
    node->left = cond;
    node->right = body;
    return node;
}

ASTNode* create_for_node(ASTNode *init, ASTNode *cond, ASTNode *incr, ASTNode *body) {
    ASTNode *node = create_node(NODE_FOR, "countdown");
    node->left = init;
    node->right = cond;
    node->third = incr;
    node->fourth = body;
    return node;
}

ASTNode* create_func_def(ASTNode *ret_type, char *name, ASTNode *params, ASTNode *body) {
    ASTNode *node = create_node(NODE_FUNCTION_DEF, name);
    node->left = ret_type;
    node->right = params;
    node->third = body;
    return node;
}

// Helper to print indentation
void print_indent(int level) {
    for (int i = 0; i < level; i++) printf("    ");
}

void generate_c_code_recursive(ASTNode *node, int indent) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
            generate_c_code_recursive(node->left, indent); // Includes
            generate_c_code_recursive(node->right, indent); // Globals/Funcs
            break;

        case NODE_FUNCTION_DEF:
            printf("\n");
            print_indent(indent);
            // Return type
            generate_c_code_recursive(node->left, 0);
            printf(" %s(", node->val);
            // Parameters
            generate_c_code_recursive(node->right, 0);
            printf(") ");
            // Body
            generate_c_code_recursive(node->third, indent);
            printf("\n");
            break;

        case NODE_BLOCK:
            printf("{\n");
            ASTNode *stmt = node->left;
            while (stmt) {
                generate_c_code_recursive(stmt, indent + 1);
                
                // Add semicolon for expression statements
                if (stmt->type == NODE_ASSIGN || stmt->type == NODE_FUNC_CALL || 
                    stmt->type == NODE_UNARY_OP || stmt->type == NODE_BINARY_OP) {
                    printf(";\n");
                }
                
                stmt = stmt->next;
            }
            print_indent(indent);
            printf("}");
            break;

        case NODE_VAR_DECL:
            print_indent(indent);
            generate_c_code_recursive(node->left, 0); // Type
            printf(" ");
            
            ASTNode *decl = node->right;
            while (decl) {
                // decl is NODE_IDENTIFIER, possibly with initializer in right child
                printf("%s", decl->val);
                if (decl->right) {
                    printf(" = ");
                    generate_c_code_recursive(decl->right, 0);
                }
                decl = decl->next;
                if (decl) printf(", ");
            }
            printf(";\n");
            break;

        case NODE_EXPRESSION: // Generic wrapper if needed, but usually handled by specific ops
        case NODE_BINARY_OP:
            printf("(");
            generate_c_code_recursive(node->left, 0);
            printf(" %s ", node->val);
            generate_c_code_recursive(node->right, 0);
            printf(")");
            break;

        case NODE_ASSIGN:
            generate_c_code_recursive(node->left, 0);
            printf(" %s ", node->val);
            generate_c_code_recursive(node->right, 0);
            break;

        case NODE_IF:
            print_indent(indent);
            printf("if (");
            generate_c_code_recursive(node->left, 0);
            printf(") ");
            generate_c_code_recursive(node->right, indent);
            if (node->third) {
                printf(" else ");
                generate_c_code_recursive(node->third, indent);
            }
            printf("\n");
            break;
            
        case NODE_WHILE:
            print_indent(indent);
            printf("while (");
            generate_c_code_recursive(node->left, 0);
            printf(") ");
            generate_c_code_recursive(node->right, indent);
            printf("\n");
            break;

        case NODE_DO_WHILE:
            print_indent(indent);
            printf("do ");
            generate_c_code_recursive(node->right, indent); // Body
            printf(" while (");
            generate_c_code_recursive(node->left, 0); // Condition
            printf(");\n");
            break;

        case NODE_SWITCH:
            print_indent(indent);
            printf("switch (");
            generate_c_code_recursive(node->left, 0);
            printf(") ");
            generate_c_code_recursive(node->right, indent);
            printf("\n");
            break;

        case NODE_CASE:
            print_indent(indent); // Case usually aligns with switch or indented? standard C style:
            printf("case ");
            generate_c_code_recursive(node->left, 0);
            printf(":\n");
            generate_c_code_recursive(node->right, indent + 1);
            break;

        case NODE_DEFAULT:
            print_indent(indent);
            printf("default:\n");
            generate_c_code_recursive(node->left, indent + 1);
            break;

        case NODE_FOR:
            print_indent(indent);
            printf("for (");
            generate_c_code_recursive(node->left, 0); // init
            printf("; ");
            generate_c_code_recursive(node->right, 0); // cond
            printf("; ");
            generate_c_code_recursive(node->third, 0); // incr
            printf(") ");
            generate_c_code_recursive(node->fourth, indent);
            printf("\n");
            break;

        case NODE_RETURN:
            print_indent(indent);
            printf("return");
            if (node->left) {
                printf(" ");
                generate_c_code_recursive(node->left, 0);
            }
            printf(";\n");
            break;
                    case NODE_UNARY_OP:
            if (strcmp(node->val, "sizeof") == 0) {
                printf("sizeof(");
                generate_c_code_recursive(node->left, 0);
                printf(")");
            } else if (strcmp(node->val, "p++") == 0) {
                printf("(");
                generate_c_code_recursive(node->left, 0);
                printf("++)");
            } else if (strcmp(node->val, "p--") == 0) {
                printf("(");
                generate_c_code_recursive(node->left, 0);
                printf("--)");
            } else {
                printf("(%s", node->val);
                generate_c_code_recursive(node->left, 0);
                printf(")");
            }
            break;

        case NODE_FUNC_CALL:
            // Don't print indent if it's part of an expression, do if it's a statement? 
            // Simplified: we will just print. If it's a standalone statement, caller might handle newline/semicolon, 
            // or we might need a STATEMENT_WRAPPER.
            // For now, assume expressions don't print newlines/semicolons, validation does.
            printf("%s(", node->val);
            ASTNode *arg = node->left;
            while (arg) {
                generate_c_code_recursive(arg, 0);
                arg = arg->next;
                if (arg) printf(", ");
            }
            printf(")");
            break;

        case NODE_IDENTIFIER:
            printf("%s", node->val);
            break;
            
        case NODE_LITERAL_INT:
        case NODE_LITERAL_FLOAT:
        case NODE_LITERAL_STRING:
             printf("%s", node->val);
             break;

        case NODE_TYPE:
            if (strcmp(node->val, "eleven") == 0) printf("int");
            else if (strcmp(node->val, "signal") == 0) printf("float");
            else if (strcmp(node->val, "full_signal") == 0) printf("double");
            else if (strcmp(node->val, "letter") == 0) printf("char");
            else if (strcmp(node->val, "the_void") == 0) printf("void");
            else printf("%s", node->val);
            break;

        case NODE_PARAMETER:
            generate_c_code_recursive(node->left, 0); // Type
            printf(" %s", node->val);
            break;

        case NODE_STRUCT_DEF:
            printf("\nstruct %s {\n", node->val);
            // In a real compiler, we would print members here. 
            // The parser simpler version didn't capture members fully yet structure-wise in the example above,
            // but let's assume valid C syntax is needed.
            printf("    // members...\n"); 
            printf("};\n");
            break;

        case NODE_UNION_DEF:
            printf("\nunion %s {\n", node->val);
            printf("    // members...\n");
            printf("};\n");
            break;

        case NODE_ENUM_DEF:
            printf("\nenum %s {\n", node->val);
             printf("    // enumerators...\n");
            printf("};\n");
            break;

        case NODE_TYPEDEF:
            printf("typedef ");
            generate_c_code_recursive(node->left, 0);
            printf(" %s;\n", node->val);
            break;
            
        case NODE_BREAK:
            print_indent(indent);
            printf("break;\n");
            break;

        case NODE_CONTINUE:
            print_indent(indent);
            printf("continue;\n");
            break;

        // ... Handle other cases ...
        default:
             if (node && node->val) printf("/* Unknown Node: %s */", node->val);
             break;
    }
    
    // Handle next sibling if it exists? 
    // Usually 'next' is handled by the parent (like BLOCK or PARAM_LIST) iterating over the list.
    // So we don't recurse on 'next' here generally, unless it's a top-level list.
}

void generate_c_code(ASTNode *node) {
    if (!node) return;
    printf("// Auto-generated C code from HawkinsLang\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <stdbool.h>\n\n");
    
    // Process the list of external declarations
    ASTNode *current = node;
    while (current) {
        generate_c_code_recursive(current, 0);
        current = current->next;
    }
}

// Optimization: Constant Folding
void optimize_ast(ASTNode *node) {
    if (!node) return;

    // Recurse first (post-order traversal)
    optimize_ast(node->left);
    optimize_ast(node->right);
    optimize_ast(node->third);
    optimize_ast(node->fourth);
    optimize_ast(node->next);

    if (node->type == NODE_BINARY_OP) {
        if (node->left && node->right &&
            node->left->type == NODE_LITERAL_INT &&
            node->right->type == NODE_LITERAL_INT) {
            
            int left_val = atoi(node->left->val);
            int right_val = atoi(node->right->val);
            int result = 0;
            int performed = 1;

            if (strcmp(node->val, "+") == 0) result = left_val + right_val;
            else if (strcmp(node->val, "-") == 0) result = left_val - right_val;
            else if (strcmp(node->val, "*") == 0) result = left_val * right_val;
            else if (strcmp(node->val, "/") == 0 && right_val != 0) result = left_val / right_val;
            else if (strcmp(node->val, "%") == 0 && right_val != 0) result = left_val % right_val;
            else performed = 0;

            if (performed) {
                fprintf(stderr, "✓ Optimized: Constant folding %d %s %d -> %d\n", left_val, node->val, right_val, result);
                char buf[32];
                sprintf(buf, "%d", result);
                
                // Transform current node to LITERAL_INT
                node->type = NODE_LITERAL_INT;
                free(node->val);
                node->val = strdup(buf);
                // Free children (simplified, assumes simple tree)
                // free(node->left->val); free(node->left); 
                // free(node->right->val); free(node->right);
                node->left = NULL;
                node->right = NULL;
            }
        }
    }
}

// Intermediate Code Generation (TAC) simulation
int temp_counter = 0;
int label_counter = 0;

char* new_temp() {
    char* buf = malloc(16);
    sprintf(buf, "t%d", temp_counter++);
    return buf;
}

char* new_label() {
    char* buf = malloc(16);
    sprintf(buf, "L%d", label_counter++);
    return buf;
}

char* generate_tac_expr(ASTNode *node) {
    if (!node) return NULL;
    
    if (node->type == NODE_LITERAL_INT || node->type == NODE_LITERAL_FLOAT || 
        node->type == NODE_IDENTIFIER || node->type == NODE_LITERAL_STRING) {
        return strdup(node->val);
    }
    
    if (node->type == NODE_BINARY_OP) {
        char *left = generate_tac_expr(node->left);
        char *right = generate_tac_expr(node->right);
        char *temp = new_temp();
        fprintf(stderr, "%s = %s %s %s\n", temp, left, node->val, right);
        return temp;
    }

    if (node->type == NODE_UNARY_OP) {
        char *child = generate_tac_expr(node->left);
        char *temp = new_temp();
        if (strcmp(node->val, "p++") == 0) {
            fprintf(stderr, "%s = %s\n", temp, child); // Capture current value
            fprintf(stderr, "%s = %s + 1\n", child, child); // Increment variable
        } else if (strcmp(node->val, "p--") == 0) {
            fprintf(stderr, "%s = %s\n", temp, child);
            fprintf(stderr, "%s = %s - 1\n", child, child);
        } else {
            fprintf(stderr, "%s = %s %s\n", temp, node->val, child);
        }
        return temp;
    }
    
    if (node->type == NODE_FUNC_CALL) {
        // Handle arguments list (node->left)
        ASTNode *arg = node->left;
        int arg_count = 0;
        char *arg_temps[20]; // Simple limit
        
        while (arg && arg_count < 20) {
            arg_temps[arg_count++] = generate_tac_expr(arg);
            arg = arg->next;
        }
        
        // Push arguments (in reverse or order depending on convention, simple here)
        for (int i = 0; i < arg_count; i++) {
             fprintf(stderr, "param %s\n", arg_temps[i]);
        }
        
        char *temp = new_temp();
        fprintf(stderr, "%s = call %s, %d\n", temp, node->val, arg_count);
        return temp;
    }
    
    if (node->type == NODE_ASSIGN) {
        char *rhs = generate_tac_expr(node->right);
        // Assuming left is identifier for now
        char *lhs = node->val ? node->val : (node->left ? node->left->val : "unknown"); 
        fprintf(stderr, "%s = %s\n", lhs, rhs);
        return strdup(lhs);
    }
    
    // Default fallback
    return "unknown";
}

void generate_tac(ASTNode *node) {
    if (!node) return;

    if (node->type == NODE_PROGRAM) {
        fprintf(stderr, "\nGenerating Intermediate Code (3-Address Code)...\n");
        fprintf(stderr, "==================================================\n");
    }

    switch (node->type) {
        case NODE_PROGRAM:
            generate_tac(node->right); // Skip includes
            break;

        case NODE_FUNCTION_DEF:
            fprintf(stderr, "\nfunc %s:\n", node->val);
            generate_tac(node->third); // body
            fprintf(stderr, "endfunc\n");
            break;

        case NODE_BLOCK:
            {
                ASTNode *stmt = node->left;
                while (stmt) {
                    generate_tac(stmt);
                    stmt = stmt->next;
                }
            }
            break;
            
        case NODE_VAR_DECL:
            {
                ASTNode *decl = node->right;
                while (decl) {
                    if (decl->right) {
                        // Assignment: variable = initializer
                        char *rhs = generate_tac_expr(decl->right);
                        fprintf(stderr, "%s = %s\n", decl->val, rhs);
                        // In TAC, we don't necessarily need to return the value of a declaration statement
                    } else {
                        // Just declaration, TAC doesn't care much unless it's initialized
                        fprintf(stderr, "%s = uninitialized\n", decl->val);
                    }
                    decl = decl->next;
                }
            }
            break;

        case NODE_ASSIGN:
        case NODE_BINARY_OP: 
        case NODE_UNARY_OP:
        case NODE_FUNC_CALL:
             generate_tac_expr(node);
             break;

        case NODE_IF:
            {
                char *l_true = new_label();
                char *l_false = new_label();
                char *l_end = new_label();
                
                // Condition (Simplified)
                char *cond = generate_tac_expr(node->left);
                fprintf(stderr, "if %s goto %s\n", cond, l_true);
                fprintf(stderr, "goto %s\n", l_false);
                
                fprintf(stderr, "%s:\n", l_true);
                generate_tac(node->right);
                fprintf(stderr, "goto %s\n", l_end);
                
                fprintf(stderr, "%s:\n", l_false);
                if (node->third) {
                    generate_tac(node->third);
                }
                
                fprintf(stderr, "%s:\n", l_end);
            }
            break;
            
        case NODE_WHILE:
             {
                 char *l_start = new_label();
                 char *l_body = new_label();
                 char *l_end = new_label();

                 fprintf(stderr, "%s:\n", l_start);
                 char *cond = generate_tac_expr(node->left);
                 fprintf(stderr, "if %s goto %s\n", cond, l_body);
                 fprintf(stderr, "goto %s\n", l_end);
                 
                 fprintf(stderr, "%s:\n", l_body);
                 generate_tac(node->right);
                 fprintf(stderr, "goto %s\n", l_start);
                 
                 fprintf(stderr, "%s:\n", l_end);
             }
             break;

        case NODE_RETURN:
            if (node->left) {
                char *ret = generate_tac_expr(node->left);
                fprintf(stderr, "return %s\n", ret);
            } else {
                fprintf(stderr, "return\n");
            }
            break;

        default:
            generate_tac(node->left);
            generate_tac(node->right);
            generate_tac(node->third);
            generate_tac(node->fourth);
            break;
    }
    
    if (node->type == NODE_PROGRAM && node->next) {
         generate_tac(node->next);
    } else if (node->type != NODE_PROGRAM && node->next) {
         // Siblings are handled by parent BLOCK usually, but top level funcs need this
         if (node->type == NODE_FUNCTION_DEF || node->type == NODE_VAR_DECL) // check context
             generate_tac(node->next);
    }
}
