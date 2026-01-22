#include <stdio.h>

#include "core.h"
#include "array.h"
#include "lexer.h"
#include "parser.h"

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
    if (!parser_init(&parser)) { return 1; }

    if (!lexer_tokenize(&lexer, &parser)) { return 1; }

    lexer_destroy(&lexer);
    parser_destroy(&parser);
    
    return 0;
}