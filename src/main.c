#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//user must free on success
char* read_line(void){ 
    char *buf = NULL;
    size_t cap = 0;
    ssize_t n = getline(&buf , &cap , stdin);
    if(n == -1){
        free(buf);
        return NULL;
    }
    if(buf[n-1] == '\n'){
        buf[n-1] = '\0';
    }
    
    return buf;
}
char **split_line(char *line){
    char *token = strtok(line , " \t");
    size_t num_of_tokens = 0;
    size_t cap =8;
    char **arr = malloc(cap * sizeof(char *)) ;
    if(arr == NULL){
        return NULL;
    }
    while(token != NULL){
        if(num_of_tokens + 1 >=cap){
            cap = cap * 2 ;
            char **tmp = realloc(arr , cap * sizeof(char *));
            if(tmp == NULL){
                return NULL;
            }
            arr = tmp; 
        }
        arr[num_of_tokens] = token ;
        num_of_tokens ++;
        token = strtok(NULL , " \t");
    }
    arr[num_of_tokens] = NULL;
    return arr;
}
int main(void){
    char *line = NULL;
    while(1){
        printf("%s" , "mysh> ");
        fflush(stdout) ;
        line = read_line();
        if(line == NULL){
            printf("\n");
            break ;
        }
        if(line[0] == '\0'){
            free(line);
            continue;
        }
        else{
            char **tokens = split_line(line);
            int count =0;
            for(int i = 0 ; tokens[i] != NULL ; i++){
                count ++;
            }
            printf("%d\n" ,count);
            for(int i = 0 ; tokens[i] != NULL ; i++){
                printf("[%d] %s\n",i,tokens[i]);
            }
            free(tokens);
            free(line);
        }
    }
    return 0;
}