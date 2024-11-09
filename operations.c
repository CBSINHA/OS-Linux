#include<stdio.h>
#include<limits.h>
#include<pthread.h>
void* average(void* arg){
int* arr=(int*)arg;
int sum=0;
size_t size=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<10;i++){
sum+=arr[i];
}
printf("Average of the entered numbers: %d\n",sum/10);
return NULL;
}
void* maximum(void* arg){
int* arr=(int*)arg;
int max=INT_MIN;
size_t size=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<10;i++){
if(max<arr[i])
max=arr[i];
}
printf("Max:%d\n",max);
return NULL;
}
void* minimum(void* arg){
int* arr=(int*)arg;
int min=INT_MAX;
size_t size=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<10;i++){
if(min>arr[i])
min=arr[i];
}
printf("Min:%d\n",min);
return NULL;
}
int main(){
int arr[10];
pthread_t thread1,thread2,thread3;
printf("Enter 10 numbers:");
for(int i=0;i<10;i++){
scanf("%d",&arr[i]);
}
pthread_create(&thread1,NULL,average,(void*)arr);
pthread_create(&thread2,NULL,maximum,(void*)arr);
pthread_create(&thread3,NULL,minimum,(void*)arr);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
return 0;
}
