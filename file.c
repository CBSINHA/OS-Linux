#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
char buff[10];
int fd;
fd=open("sample.txt",O_RDWR|O_CREAT|O_APPEND,0777);

write(fd,"hello gaiz",10);
read(fd,buff,7);
write(1,buff,7);
printf("\ndone");
return 0;
}
