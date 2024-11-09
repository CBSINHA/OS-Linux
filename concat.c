#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
struct strings{
char str1[1000];
char str2[500];
};
void* function(void* arg){
struct strings* s1 = (struct strings*)arg;
printf("String 1: %s",s1->str1);
printf("String 2: %s",s1->str2);
strcat(s1->str1,s1->str2);
printf("Concatenated String: %s",s1->str1);
return NULL;
}
int main(){
pthread_t thread;
struct strings s1;
printf("Enter string 1: ");
scanf("%s",s1.str1);
printf("Enter string 2:");
scanf("%s",s1.str2);
pthread_create(&thread,NULL,function,(void*)&s1);
pthread_join(thread,NULL);
return 0;
}
