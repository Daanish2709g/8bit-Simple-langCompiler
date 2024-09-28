#include "lexer.c"
#include "parser.c"
#include "ast.c"

int main() {
    const char* input = "3 + 5 - 2 * 4 / 2"; // Sample input
    lex(input);
    print_tokens();

    Parser parser;
    parser.current_token = tokens;
    parse_expression(&parser);

    generateAssembly("output.asm"); // Output assembly file
    return 0;
}
