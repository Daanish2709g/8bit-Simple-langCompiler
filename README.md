# 8bit-Simple-langCompiler

This is a simple compiler for a language called SimpleLang, targeting an 8-bit CPU. 

## Files

- `lexer.c`: Contains the lexer for tokenizing the input.
- `parser.c`: Contains the parser for parsing the tokenized input.
- `ast.c`: Contains functions to generate assembly code.
- `main.c`: The main entry point for the compiler.

## Compilation

To compile the code, use:

Run the compiler: ./simplelang


output.asm: 
/*
 * Sample input for the SimpleLang compiler.
 * This expression will be tokenized and parsed:
 
 * 3 + 5 - 2 * 4 / 2

3 + 5 - 2 * 4 / 2



## 

```bash
gcc main.c -o simplelang
