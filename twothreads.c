#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
struct Args{
int a;
int b;
}args;
void* sum_func(void* arg){
struct Args* args=(struct Args*)arg;
printf("Sum of %d and %d is: %d\n",args->a,args->b,args->a+args->b);
}
void* sub_func(void* arg){
struct Args* args=(struct Args*)arg;
printf("Difference of %d and %d is: %d\n",args->a,args->b,args->a-args->b);
int* retVal=(int*)malloc(sizeof(int));
*retVal=69;
pthread_exit(retVal);
}
int main(){
struct Args args;
pthread_t id1,id2;
int* returnVal;
printf("Number 1: ");
scanf("%d",&args.a);
printf("Number 2: ");
scanf("%d",&args.b);
pthread_create(&id1,NULL,sum_func,&args);
pthread_create(&id2,NULL,sub_func,&args);
pthread_join(id1,NULL);
pthread_join(id2,(void**)&returnVal);
printf("Value returned from thread2 is:%d",*returnVal);
printf("DONE");
return 0;
}
