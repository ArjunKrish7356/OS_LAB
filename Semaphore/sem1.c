#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define max_thread 2
int counter=0;
//sem_t semaphore;

void* increment(void * args){
    for(int i=0;i<1000;i++){
        //sem_wait(&semaphore);
        counter++;
        printf("Counter value : %d ",counter);
        //sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

void main(){
    //sem_init(&semaphore,0,1);
    pthread_t threads[max_thread];

    for(int i=0;i<max_thread;i++){
        pthread_create(&threads[i],NULL,increment,NULL);
    }

    for(int i=0;i<max_thread;i++){
        pthread_join(threads[i],NULL);
    }
    //sem_destroy(&semaphore);
}