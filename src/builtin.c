#include "builtin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


struct builtin
{
    const char *name;
    int (*func)(char **args) ;
};

static int builtin_cd(char **args);
static int builtin_pwd(char **args);
static int builtin_exit(char **args);
static int builtin_help(char **args);

static const struct builtin builtins[] =
{
    {"cd" , builtin_cd} ,
    {"pwd" , builtin_pwd} ,
    {"exit" , builtin_exit} ,
    {"help" , builtin_help} ,
};

static size_t num_builtins(void){
    return sizeof(builtins) / sizeof(builtins[0]);
}

static int builtin_cd(char **args){
    char *path = args[1];
    if(path == NULL){
        path = getenv("HOME") ;
        if(path == NULL){
            fprintf(stderr , "home error");
            return 1;
        }
    }
    if(chdir(path) != 0){
        perror("cd");
        return BUILTIN_CONTINUE;
    }
    return BUILTIN_EXIT;
}
static int builtin_pwd(char **args){
    char buf[PATH_MAX];
    if(getcwd(buf , sizeof(buf)) == NULL ){
        perror("pwd");
        return BUILTIN_CONTINUE;
    }
    printf("%s\n" , buf);
    return BUILTIN_EXIT;
}
static int builtin_exit(char **args){
    return BUILTIN_CONTINUE;
}
static int builtin_help(char **args){

    return BUILTIN_CONTINUE;
}
int run_builtin(char **args){
    if(args == NULL || args[0] == NULL){
        return BUILTIN_NONE;
    }
    for(size_t i = 0 ; i < num_builtins() ; i++){
        if(strcmp(args[0] , builtins[i].name) == 0 ){
            return builtins[i].func(args);
        }
    }
    return BUILTIN_NONE;
}