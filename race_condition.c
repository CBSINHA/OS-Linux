#include<stdio.h>
#include<pthread.h>
#define THREADS 13
#define ITERATIONS 10000
int sharedVar=0;
void* increment(void* args){
for(int i=0;i<=ITERATIONS;i++) sharedVar++;
}
int main(){
pthread_t id[THREADS];
for(int i=0;i<THREADS;i++){
pthread_create(&id[i],NULL,increment,NULL);
}
for(int i=0;i<THREADS;i++){
pthread_join(id[i],NULL);
}
printf("Value of shared variable expected:%d\n",THREADS*ITERATIONS);
printf("Actual output value of sharedVar:%d\n",sharedVar);
return 0;
}
