#include "lexer.c"

typedef struct {
    Token* current_token;
} Parser;

void advance(Parser* parser) {
    parser->current_token++;
}

void parse_expression(Parser* parser) {
    if (parser->current_token->type == TOKEN_INTEGER) {
        printf("Parsed integer: %s\n", parser->current_token->value);
        advance(parser);
    }
    
    while (parser->current_token->type == TOKEN_PLUS || 
           parser->current_token->type == TOKEN_MINUS ||
           parser->current_token->type == TOKEN_MULTIPLY ||
           parser->current_token->type == TOKEN_DIVIDE) {
        printf("Parsed operator: %s\n", parser->current_token->value);
        advance(parser);
        
        if (parser->current_token->type == TOKEN_INTEGER) {
            printf("Parsed integer: %s\n", parser->current_token->value);
            advance(parser);
        }
    }
}
