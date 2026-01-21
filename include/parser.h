#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>
#include <stdbool.h>

#include "token.h"

typedef struct Parser {
    Token *items;
    size_t size;
    size_t len;
    size_t pos;
} Parser;

typedef enum PrecedenceOps {
    PO_POSTFIX,        // x++  x--  ()  []  .  ->
    PO_UNARY,          // ++x  --x  +x  -x  !  ~  *  &  sizeof
    PO_MUL_DIV_MOD,    // *  /  %
    PO_ADD_SUB,        // +  -

    PO_SHIFT,          // <<  >>

    PO_RELATIONAL,     // <  <=  >  >=

    PO_EQUALITY,       // ==  !=

    PO_BIT_AND,        // &
    
    PO_BIT_XOR,        // ^
    
    PO_BIT_OR,         // |
    
    PO_LOGICAL_AND,    // &&
    
    PO_LOGICAL_OR,     // ||
    
    PO_TERNARY,        // ? :
    PO_ASSIGNMENT,     // =  +=  -=  *=  /=  etc.
    
    PO_COMMA,          // ,
} PrecedenceOps;

/*
    Set default fields for the `Parser` struct and allocates `n` bytes to `Parser.items`.
    Initial size is determined by `sizeof(*parser->items) * 256` and grows bigger if needed.
    
    Returns `false` if `malloc` failed to return a valid pointer.
*/
bool parser_init(Parser *parser);

// Free the memory allocated in `Parser.items` and set the rest of the fields to 0.
void parser_destroy(Parser *parser);

/*
    Checks if the current token is the expected one.
    If not found returns `false` and sets the error message.
*/
bool parser_expect_token(Parser *parser, TokenKind expected);

// Get the current token in the list.
Token parser_get_token(Parser *parser);

// Get the next token in the list.
Token parser_next_token(Parser *parser);

// Print basic information about `Parser` struct.
void parser_log(Parser parser);

// Print all tokens in `Parser.items`
void parser_log_tokens(Parser parser);

// Print `n` amount of tokens in `Parser.items`
void parser_log_ntokens(Parser parser, size_t n);

#endif // PARSER_H