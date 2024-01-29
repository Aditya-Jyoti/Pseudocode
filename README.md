# Pseudocode

## About

Pseudocode is a simple programming language built using c++. It aims at providing a syntax
that is similar to natural language in order to have code that is readable even to non
programmers. As the name suggests the syntax is similar to common pseudocode principals.

## Project Structure

```
├── build       : The executable for the language.
├── docs        : Documentation for the language.
├── examples    : Example code written in the language.
└── src         : Source code for the interpreter.
    ├── ast     : Defines the nodes of the AST.
    ├── lexer   : Tokenizes input into meaningful pieces.
    ├── parser  : Transforms tokens into an abstract syntax tree (AST).
    ├── std_lib : Built-in functions and standard library.
    └── utils   : Utility functions and classes.
```
