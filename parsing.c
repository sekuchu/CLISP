#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// lazna readline funkcija
char* readline(char* prompt){
  fgets(prompt, stdout);
  fputs(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

// filler za praznu funkcija
char* add_history(char *unused) {}

#else 
#include<editline/readline.h>
#include<editline/history.h>
#endif

int main(int argc, char *argv[])
{
  // dodamo parsere
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* Clisp = mpc_new("clisp");

  // definisemo parsere za odredjenim pravilima
  mpca_lang(MPCA_LANG_DEFAULT,
  "                                                         \
    number   : /-?[0-9]+/ ;                                 \
    operator : '+' | '-' | '*' | '/' | \"add\" | \"sub\" ;  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;      \
    clisp    : /^/ <operator> <expr>+ /$/ ;                 \
  ",
  Number, Operator, Expr, Clisp);

  puts("CLISP version 0.0.0.1");
  puts("Press CTRL + C to exit");

  while (1) {

    char* input = readline("clisp> ");
    add_history(input);

    // probaj parsirati user input
    mpc_result_t r;
    if(mpc_parse("<stdin>", input, Clisp, &r)) {
      // ako uspije parsirati
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output); 
    }
    else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }





    free(input);
  }

  // ocistimo i oslobodimo parsere
  mpc_cleanup(4, Number, Operator, Expr, Clisp);

  return 0;
}
