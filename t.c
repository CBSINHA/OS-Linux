#include<stdio.h>
#include<pthread.h>
void* number(void* arg){
int* n=(int*)arg;
printf("You entered %d\n",*n);
}
int main(){
pthread_t id;
int num=43443534;
pthread_create(&id,NULL,number,&num);
pthread_join(id,NULL);
return 0;
}

