#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
//#include<semaphore.h>
#define SIZE 5
pthread_mutex_t sticks[SIZE];
//pthread_t philosophers[SIZE];
void* philosopher(void* args){
int id=*(int*)args;
int left=id;
int right=(id+1)%SIZE;
while(1){
printf("philosopher %d is thinking\n",id);
sleep(1);
printf("Philosopher %d is hungry\n",id);
if(id%2==0){
pthread_mutex_lock(&sticks[left]);
pthread_mutex_lock(&sticks[right]);
}
else{
pthread_mutex_lock(&sticks[right]);
pthread_mutex_lock(&sticks[left]);
}
printf("Philosopher %d is eating\n",id);
sleep(2);
pthread_mutex_unlock(&sticks[left]);
pthread_mutex_unlock(&sticks[right]);
printf("Philosopher %d has fininshed eating\n",id);
}
}
int main(){
pthread_t philosophers[SIZE];
int id[SIZE];
for(int i=0;i<SIZE;i++){
pthread_mutex_init(&sticks[i],NULL);
}
for(int i=0;i<SIZE;i++){
id[i]=i;
pthread_create(&philosophers[i],NULL,philosopher,&id[i]);
}
for(int i=0;i<SIZE;i++){
pthread_join(philosophers[i],NULL);
}
for(int i=0;i<SIZE;i++){
pthread_mutex_destroy(&sticks[i]);
}
return 0;
}
