#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>

void main(){
    int shmid;
    key_t key;
    char * ptr,*shm;

    key=ftok("shmfile",'R');

    shmid=shmget(key,1024,0666);

    shm=shmat(shmid,NULL,0);

    ptr=shm;

    printf("%s",ptr);

    shmdt(shm);
}
