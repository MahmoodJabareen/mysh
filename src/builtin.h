#ifndef BUILTIN_H
#define BUILTIN_H

enum { BUILTIN_NONE = -1, BUILTIN_EXIT = 0, BUILTIN_CONTINUE = 1 };
int run_builtin(char **args) ;

#endif