#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

void main(){
    char data[100];
    int fd = open("test1.txt",O_CREAT|O_WRONLY,0644);
    int wrt= write(fd,"hiiii",5);
    close(fd);

    fd = open("test1.txt",O_RDONLY);
    int rd =read(fd,data,sizeof(data));
    printf("%s",data);
    close(fd);
}