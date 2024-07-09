#include<stdio.h>
#include<dirent.h>

void main(){
    DIR * dir =opendir(".");
    if(dir){
        struct dirent *entry;
        printf("Current directory contents. \n");
        while((entry=readdir(dir))!=NULL){
            printf("%s\n",entry->d_name);
        }
        closedir(dir);
    }   
}