#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "ast.h"
#include "parser.h"
#include "token.h"

ASTNode *ast_astify(Parser *parser) {
    ASTNode *root = ast_expr(parser);
    parser_advance(parser);
    return root;
}

ASTNode *ast_expr(Parser *parser) {
    ASTNode *left = ast_term(parser);
    
    Token t = parser_get_token(parser);
    
    while (t.kind == TK_ADD || t.kind == TK_SUB) {
        t = parser_get_token(parser);
        parser_advance(parser);
        ASTNode *right = ast_term(parser);
        left = ast_binary(t.lexeme, left, right);
    }
    
    return left;
}

ASTNode *ast_term(Parser *parser) {
    ASTNode *left = ast_factor(parser);

    Token t = parser_get_token(parser);

    while (t.kind == TK_STAR || t.kind == TK_SLASH) {
        t = parser_get_token(parser);
        parser_advance(parser);
        ASTNode *right = ast_term(parser);
        left = ast_binary(t.lexeme, left, right);
    }

    return left;
}

ASTNode *ast_factor(Parser *parser) {
    Token t = parser_get_token(parser);
    if (t.kind == TK_NUMBER_LIT) {
        int number = atoi(t.lexeme);
        parser_advance(parser);
        return ast_number(number);
    }

    ERRORF("%s:%d reached end of function %s()", __FILE__, __LINE__, __func__);
    exit(1);
}

ASTNode *ast_node(ASTNode *l, ASTNode *r) {
    ASTNode *node = malloc(sizeof(*node));
    node->type = T_STMT;
    node->l = l;
    node->r = r;
    node->value.number = 0;
    return node;
}

ASTNode *ast_binary(char *op, ASTNode *l, ASTNode *r) {
    ASTNode *node = ast_node(l, r);
    node->type = T_BINARY;
    node->op = op;
    return node;
}

ASTNode *ast_number(int integer) {
    ASTNode *node = ast_node(NULL, NULL);
    node->type = T_NUMBER;
    node->value.number = integer;
    return node;
}

bool ast_expect(Token token, TokenKind kind) {
    return token.kind == kind;
}

void ast_log(ASTNode *node, int level) {
    for (int i = 0; i < level; ++i) {
        printf("    ");
    }

    switch (node->type) {
        case T_STMT:
            if (node->l) ast_log(node, level + 1);
            if (node->r) ast_log(node, level + 1);
            break;

        case T_BINARY:
            if (node->l) ast_log(node, level + 1);
            if (node->r) ast_log(node, level + 1);
            if (node->op) printf("OP: %s\n", node->op);
            break;

        case T_NUMBER:
            printf("NUMBER: %d\n", node->value.number);
            break;
    }
}

void ast_free(ASTNode *root) {
    if (root->l) ast_free(root->l);
    if (root->r) ast_free(root->r);

    free(root);
}