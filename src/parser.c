#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "token.h"
#include "core.h"

bool parser_init(Parser *parser, char *filepath) {
    parser->items = malloc(sizeof(*parser->items) * 256);
    if (parser->items == NULL) {
        ERROR("Could not allocate memory for parser.");
        return false;
    }

    parser->len = 0;
    parser->size = 0;
    parser->pos = 0;

    parser->filepath = filepath;
    return true;
}

void parser_destroy(Parser *parser) {
    free(parser->items);
    parser->len = 0;
    parser->size = 0;
    parser->pos = 0;
    parser->filepath = NULL;
}

Token parser_get_token(Parser *parser) {
    return parser->items[parser->pos];
}

Token parser_next_token(Parser *parser) {
    return parser->items[parser->pos + 1];
}

void parser_advance(Parser *parser) {
    parser->pos++;
}

bool parser_complete(Parser *parser) {
    return parser->pos >= (parser->len - 1);
}

void parser_log(Parser parser) {
    printf("Parser Log:\n"
    "  len  - %ld\n" 
    "  size - %ld\n"
    "  pos  - %ld\n", parser.len, parser.size, parser.pos);
}

void parser_log_tokens(Parser parser) {
    printf("Tokens found: %ld\n", parser.len);
    for (size_t i = 0; i < parser.len; ++i) {
        printf(CORE_GREY"...."CORE_END);
        token_log(parser.items[i]);
    }
}

void parser_log_ntokens(Parser parser, size_t n) {
    n = parser.len > n ? n : parser.len;

    printf("Tokens found: %ld\n", parser.len);
    for (size_t i = 0; i < n; ++i) {
        printf(CORE_DOTS);
        token_log(parser.items[i]);
    }
    if (parser.len > n) printf("(...)\n");
}