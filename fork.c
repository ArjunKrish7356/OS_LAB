#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>

void main(){
    printf("Parent process (PID %d) is creating process...",getpid());
    
    for(int i=0;i<5;i++){
        pid_t p= fork();

        if(p==-1){
            perror("failed");
            exit(EXIT_FAILURE);
        }
        else if(p==0){
            printf("Child Process (CHILD PID %d) created by process (PARENT %d)",getpid(),getppid());
            printf("\n");
            exit(EXIT_SUCCESS);
        }
    }
}