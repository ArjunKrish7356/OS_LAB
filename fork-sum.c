#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
    int pipefd[2];
    int res=pipe(pipefd);   

    int num,sum=0,sum2;
    printf("Enter the number upto be summed : ");
    scanf("%d",&num);

    pid_t p=fork();

    if(p==0){
        close(pipefd[0]);
        for(int i=0;i<num/2;i++){
            sum=sum+i;
        }
        write(pipefd[1],&sum,sizeof(sum));
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
    else if(p>0){
        for(int i=num/2;i<=num;i++){
            sum=sum+i;
        }
        wait(NULL);
        read(pipefd[0],&sum2,sizeof(sum2));
        close(pipefd[0]);
        int tsum=sum+sum2;
        printf("Result is : %d",tsum);
    }
}