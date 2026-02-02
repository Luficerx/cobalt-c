#include <stdio.h>

#include "core.h"
#include "lexer.h"
#include "parser.h"
#include "ast.h"

int main(int argc, char **argv) {
    char *file;
    
    Lexer lexer = {0};
    Parser parser = {0};

    file = array_shift_arg(argc, argv);
    
    if (!argc) {
        ERROR("No file was provided.");
        return 1;
    }

    file = array_shift_arg(argc, argv);

    if (!lexer_init(&lexer, file)) { return 1; }
    if (!parser_init(&parser, file)) { return 1; }

    if (!lexer_tokenize(&lexer, &parser)) { return 1; }

    while (!parser_complete(&parser)) {
        ASTNode *root = ast_astify(&parser);
        ast_log(root, 0);
        printf("======================================================\n");
        ast_free(root);
    }

    lexer_destroy(&lexer);
    parser_destroy(&parser);
    
    return 0;
}