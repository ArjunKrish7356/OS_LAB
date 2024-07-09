#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

#define buffersize 5

int buffer[buffersize];
int in=0;
int out=0;

void* producer(void * args){
    int item=1;
    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("produced item : %d",item);
        buffer[in]=item;
        item++;
        in=(in+1)%buffersize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void* consumer(void * args){
        while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item=buffer[out];
        printf("consumed item : %d",item);
        item--;
        in=(in+1)%buffersize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

void main(){
    sem_init(&empty,0,buffersize);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_t consthread,prodthread;
    pthread_create(&prodthread,NULL,producer,NULL);
    pthread_create(&consthread,NULL,consumer,NULL);

    pthread_join(prodthread,NULL);
    pthread_join(consthread,NULL);

    sem_destroy(&full);
    sem_destroy(&empty);

    pthread_mutex_destroy(&mutex);
}

