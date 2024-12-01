#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
pid_t pid;
char buff[1000];
int fd[2];
int pipe_pid=pipe(fd);
if(pipe_pid<0) {
printf("pipe() failed!");
exit(1);
}
pid=fork();
if(pid<0){
printf("fork failed!");
exit(1);}
else if(pid==0){
//child
close(fd[1]);
read(fd[0],buff,sizeof(buff));
printf("Message read:%s",buff);
close(fd[0]);
}
else{//parent
close(fd[0]);
char message[]="Hello shashank sinha,you're cooked XD";
write(fd[1],message,sizeof(message));
close(fd[1]);
}
return 0;
}
