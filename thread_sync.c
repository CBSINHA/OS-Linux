//semaphors and mutex
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
int sv=10;
//sem_t s;//semaphore
pthread_mutex_t m;
void *myt1(void *args){
//sem_wait(&s);//to execute entry code(P)
pthread_mutex_lock(&m);
printf("\n inside t1 the initial value of sv is %d",sv);
int temp;
temp=sv;
temp++;
printf("\n inside t1 the value of temp is %d",temp);
sleep(1);
sv=temp;
printf("\n inside t1 the final value of sv is %d",sv);
//sem_post(&s);//to execute exit code(V)
pthread_mutex_unlock(&m);
}
void *myt2(void *args){
//sem_wait(&s);
pthread_mutex_lock(&m);
printf("\n inside t2 the initial value of sv is %d",sv);
int temp;
temp=sv;
temp--;
printf("\n inside t2 the value of temp is %d",temp);
sleep(1);
sv=temp;
printf("\n inside t2 the final value of sv is %d",sv);
//sem_post(&s);
pthread_mutex_unlock(&m);
}
int main(){
/*sem_init(&s,0,1);//reference of the semaphore variable;0 for thread/other numberfor
process(2 for 2 processes);semaphore variable initialization-initially true(this is
binary semaphore)*/
pthread_mutex_init(&m,NULL);
pthread_t t1,t2;
pthread_create(&t1,NULL,myt1,NULL);
pthread_create(&t2,NULL,myt2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("\n The final value of my SV is %d",sv);
}