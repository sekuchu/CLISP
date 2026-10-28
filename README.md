# CLISP: A Lisp Interpreter in C

A lightweight, minimal Common Lisp interpreter implemented in C. This project demonstrates core Lisp concepts—such as symbolic execution, s-expressions, dynamic typing, and garbage collection—built from the ground up in C.

---

## About the Lisp Language

**LISP** (*LISt Processing*), created by John McCarthy in 1958, is the second-oldest high-level programming language still in widespread use. Key characteristics of Lisp include:

* **S-Expressions:** Both code and data share the exact same tree structure (`(operator operand1 operand2 ...)`).
* **Code-as-Data (Homoiconicity):** Lisp programs can read, transform, and evaluate other Lisp expressions effortlessly using macros.
* **REPL-Driven Development:** Designed around the *Read-Eval-Print Loop*, encouraging rapid prototyping and interactive testing.

---

## Features

* **S-Expression Parser:** Parses parenthesized expressions into abstract syntax trees (ASTs).
* **Core Primitive Procedures:** Fundamental operators including `car`, `cdr`, `cons`, `quote`, `eval`, and basic arithmetic.
* **REPL Interface:** Interactive environment built in C to evaluate expressions in real time.
* **Dynamic Memory Management:** Custom allocation and memory tracking for Lisp cells/nodes.

---

## Quick Start

### Build & Run
Compile the interpreter using standard C compilation tools:

```bash
# Compile
cc -std=c99 -Wall parsing.c mpc.c -ledit -lm -o clisp

# Run the REPL
./clisp
