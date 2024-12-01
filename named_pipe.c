#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
char buff[1000];
char *fifo="/tmp/myfifo";
mkfifo(fifo,0666);
int fd;
fd=open(fifo,O_WRONLY);
char msg[]="Hello named pipe nigga!";
write(fd,msg,sizeof(msg));
close(fd);
fd=open(fifo,O_RDONLY);
read(fd,buff,sizeof(buff));
printf("Received the message: %s",buff);
close(fd);
return 0;
}
