#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 64
#define MAX_NUM_TOKENS 100

typedef enum {
    TOKEN_INTEGER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

Token tokens[MAX_NUM_TOKENS];
int token_count = 0;

void add_token(TokenType type, const char* value) {
    tokens[token_count].type = type;
    strncpy(tokens[token_count].value, value, MAX_TOKEN_LENGTH);
    token_count++;
}

void lex(const char* input) {
    const char* p = input;
    while (*p) {
        if (isspace(*p)) {
            p++;
        } else if (isdigit(*p)) {
            char buffer[MAX_TOKEN_LENGTH];
            int len = 0;
            while (isdigit(*p) && len < MAX_TOKEN_LENGTH - 1) {
                buffer[len++] = *p++;
            }
            buffer[len] = '\0';
            add_token(TOKEN_INTEGER, buffer);
        } else if (*p == '+') {
            add_token(TOKEN_PLUS, "+");
            p++;
        } else if (*p == '-') {
            add_token(TOKEN_MINUS, "-");
            p++;
        } else if (*p == '*') {
            add_token(TOKEN_MULTIPLY, "*");
            p++;
        } else if (*p == '/') {
            add_token(TOKEN_DIVIDE, "/");
            p++;
        } else {
            add_token(TOKEN_INVALID, (char[]){*p, '\0'});
            p++;
        }
    }
    add_token(TOKEN_EOF, "");
}

void print_tokens() {
    for (int i = 0; i < token_count; i++) {
        printf("Token: %s, Type: %d\n", tokens[i].value, tokens[i].type);
    }
}
