#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define SIZE 10
int in=0,out=0;
sem_t empty,full;
pthread_mutex_t mutex;
int Buffer[SIZE];
void* producer(void* args){
int item;
while(1){
item=rand()%100;
sem_wait(&empty);
pthread_mutex_lock(&mutex);
Buffer[in]=item;
printf("Produced:%d\n",item);
in++;
pthread_mutex_unlock(&mutex);
sem_post(&full);
sleep(1);
}
}
void* consumer(void* args){
int item;
while(1){
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=Buffer[out];
printf("Consumed:%d",item);
out++;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
sleep(1);
}
}
int main(){
sem_init(&empty,0,SIZE);
sem_init(&full,0,0);
pthread_mutex_init(&mutex,NULL);
pthread_t p,c;
pthread_create(&p,NULL,producer,NULL);
pthread_create(&c,NULL,consumer,NULL);
pthread_join(p,NULL);
pthread_join(c,NULL);
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutex);
return 0;
}
