#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
struct Message{
int type;
char msg[1000];
};
int id;
key_t key=1224;
id=msgget(key,0666|IPC_CREAT);
struct Message message;
strcpy(message.msg,"Heylo niggs we studying message queues!");
message.type=1;
msgsnd(id,&message,sizeof(message),0);
printf("MEssage sent!");
msgrcv(id,&message,sizeof(message),1,0);
printf("Message received from the queue: %s\n",message.msg);
return 0;
}
