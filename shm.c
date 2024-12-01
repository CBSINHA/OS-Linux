#include<sys/ipc.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#define SIZE 100
int main(){
key_t key=1234;
int id;
void* shm;
id=shmget(key,SIZE,0666|IPC_CREAT);
shm=shmat(id,NULL,0);
char msg[]="Hello SHM nig!";
strncpy((char*)shm,msg,sizeof(msg));
printf("The data reveived in shm: %s\n",(char*)shm);
shmdt(shm);
return 0;
}
