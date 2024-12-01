#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define THREAD 5
#define ITERATIONS 1000000
int shared=0;
sem_t semaphore;
void* increment(void* args){
for(int i=1;i<=ITERATIONS;i++){
sem_wait(&semaphore);
shared++;
sem_post(&semaphore);
}
}
int main(){
pthread_t id[THREAD];
sem_init(&semaphore,0,1);
for(int i=0;i<THREAD;i++) pthread_create(&id[i],NULL,increment,NULL);
for(int i=0;i<THREAD;i++) pthread_join(id[i],NULL);
sem_destroy(&semaphore);
printf("Value expected:%d\nValue got as output:%d\n",THREAD*ITERATIONS,shared);
return 0;
}
