#include<stdio.h>
#include<string.h>
#include<pthread.h>
void* func(void* arg){
char* str=(char*)arg;
printf("The received string is: %s",str);
size_t length;
length=strlen(str);
printf("The length of the string is: %zd",length);
return NULL;
}
int main(){
pthread_t thread;
char str[1000];
printf("Enter string:");
scanf("%s",str);
pthread_create(&thread,NULL,func,(void*)str);
pthread_join(thread,NULL);
return 0;
}
