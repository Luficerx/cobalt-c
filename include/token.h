#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

typedef enum TokenKind {
    // Literals & Identifiers
    TK_IDENTIFIER, // variable_name, function_name
    TK_KEYWORD,    // const, static, private
    TK_NUMBER_LIT, // 69, 420
    TK_STRING_LIT, // "Hello World"
    TK_HEX_LIT,    // 0x181818 (Tsoding background color theme)
    TK_STRAY,      // Stray '/'

    // Delimiters
    TK_LSBRACE,   // [
    TK_RSBRACE,   // ]
    TK_LPAREN,    // (
    TK_RPAREN,    // )
    TK_LCBRACE,   // {
    TK_RCBRACE,   // }
    TK_SEMICOLON, // ;
    TK_COLON,     // :
    TK_PIPE,      // |
    TK_COMMA,     // ,
    TK_DOT,       // .
    
    // Arithmetic
    TK_ADD,       // +
    TK_SUB,       // -
    TK_STAR,      // *
    TK_SLASH,     // /
    TK_MOD,       // %
    
    TK_RSHIFT,    // >>
    TK_LSHIFT,    // <<

    // Comparisson
    TK_GREATER,   // >
    TK_LESSER,    // <
    
    // Assignment
    TK_ASSIGN_OP, // =
    
    // Logical()
    TK_EQUALS,    // ==
    TK_NEQUALS,   // !=
    TK_GEQUALS,   // >=
    TK_LEQUALS,   // <=
    TK_MULT_OP,   // *=
    TK_DIV_OP,    // /=
    TK_AND_OP,    // &&
    TK_OR_OP,     // ||
    
    TK_QMARK,     // ?
    TK_NOT,       // !

    // OTHER
    TK_AT,        // @
    TK_HASH,      // #
    TK_DSIGN,     // $
    TK_AMPER,     // &
    TK_XOR,       // ^

    // SPECIAL
    TK_INC_OP,    // ++
    TK_DEC_OP,    // --
    TK_EOF,       // End of File

} TokenKind;

typedef enum TokenMode {
    TM_NONE,
    
    TM_STRING_LIT,
    TM_NUMBER_LIT,

    // HEXADECIMAL
    TM_HEX_LIT,

    // SINGLE COMMENT
    TM_COMMENT,

    // MULTI COMMENT
    TM_MCOMMENT,

    // Anything that we don't know yet what it is.
    TM_GENERIC,
} TokenMode;

typedef struct Token {
    TokenKind kind;
    char *lexeme;
    size_t line;
    size_t column;
} Token;

/*
    Retuns the string of the enum field in `TokenKind` enum.
    `TK_IDENTIFIER → 'IDENTIFIER'`
    `TK_KEYWORD → 'KEYWORD'`
*/
const char *token_get_name(TokenKind kind);

/*
    Returns a string with the literal representation of a token.
    
    - TK_ADD → "+"
    - TK_SUB → "-"
    - TK_MOD → "%"

    For other tokens that do not fit the criteria of literal, instead
    this function calls `token_get_name()` and then returns that string.
*/
const char *token_get_literal(TokenKind kind);

// Print the kind and the lexeme of the token.
void token_log(Token token);

#endif // TOKEN_H