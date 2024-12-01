#include<pthread.h>
#include<stdio.h>
#define THREAD 5
#define ITERATIONS 1000000
int shared=0;
pthread_mutex_t mutex;
//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;//can initialize globally
void* increment(void* args){
for(int i=1;i<=ITERATIONS;i++){
pthread_mutex_lock(&mutex);
shared++;
pthread_mutex_unlock(&mutex);
}
}
int main(){
pthread_mutex_init(&mutex,NULL);//can initialize dynamically like this too globally is static initialization
pthread_t id[THREAD];
for(int i=0;i<THREAD;i++) pthread_create(&id[i],NULL,increment,NULL);
for(int i=0;i<THREAD;i++) pthread_join(id[i],NULL);
pthread_mutex_destroy(&mutex);
printf("Value expected:%d\nValue got as output:%d\n",THREAD*ITERATIONS,shared);
return 0;
}
