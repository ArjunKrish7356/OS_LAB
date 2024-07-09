#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define max_thread 2

sem_t semaphore;
int counter=0;

void * increment(void * args){
    sem_wait(&semaphore);
    for(int i=0;i<1000;i++){
        
        counter++;
        printf("counter increment to : %d ", counter);
        
    }
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void * decrement(void * args){
    sem_wait(&semaphore);
    for(int i=0;i<1000;i++){
        counter--;
        printf("counter decrement to : %d ", counter);
        
    }
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void main(){

    sem_init(&semaphore,0,1);

    pthread_t threadInc,threadDec;
    pthread_create(&threadInc,NULL,increment,NULL);
    pthread_create(&threadDec,NULL,decrement,NULL);

    pthread_join(threadInc,NULL);
    pthread_join(threadDec,NULL);

    sem_destroy(&semaphore);

}