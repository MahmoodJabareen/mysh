#include <stdio.h>
#include <stdlib.h>
//user must free on success
char* read_line(void){ 
    char *buf = NULL;
    size_t cap = 0;
    ssize_t n = getline(&buf , &cap , stdin);
    if(n == -1){
        free(buf);
        return NULL;
    }
    return buf;
}
int main(int argc , char *argv[]){
    char *line = NULL;
    while(1){
        printf("%s" , "mysh> ");
        fflush(stdout) ;
        line = read_line();
        if(line == NULL){
            break ;
        }
        else{
            printf("you typed: %s" , line);
            free(line);
        }
    }
}