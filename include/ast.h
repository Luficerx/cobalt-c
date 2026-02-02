#ifndef AST_H
#define AST_H

#include <stdbool.h>
#include "parser.h"
#include "token.h"

typedef enum ASTType {
    T_STMT,
    // T_EXPR,
    // T_CALL,

    // T_DECLARATION,
    // T_ASSIGNMENT,

    T_BINARY,

    T_NUMBER,
    // T_STRING,
    // T_HEXADECIMAL,
    // T_IDENTIFIER,
} ASTType;

typedef struct ASTNode {
    ASTType type;
    
    struct ASTNode *l;
    struct ASTNode *r;
    
    char *op;

    union {
        int number;
    } value;

} ASTNode;

ASTNode *ast_astify(Parser *parser);
ASTNode *ast_expr(Parser *parser);
ASTNode *ast_or(Parser *parser);
ASTNode *ast_and(Parser *parser);
ASTNode *ast_equal(Parser *parser);
ASTNode *ast_comp(Parser *parser);
ASTNode *ast_factor(Parser *parser);
ASTNode *ast_term(Parser *parser);
ASTNode *ast_binary(char *op, ASTNode *l, ASTNode *r);
ASTNode *ast_node(ASTNode *l, ASTNode *r);
ASTNode *ast_number(int number);

void ast_free(ASTNode *root);

bool ast_expect(Token token, TokenKind kind);

void ast_log(ASTNode *node, int level);

#endif //AST_H
