#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
int option,fd;
char buff[100];
printf("Enter 1 to print 1st half or 2 to print 2nd half");
scanf("%d",&option);
fd=open("sample.txt",O_RDONLY);
int size=lseek(fd,0,SEEK_END);
if(option==1){
lseek(fd,0,SEEK_SET);
read(fd,buff,size/2);
printf("The value read:\n%s",buff);
}
if(option==2){
lseek(fd,size/2,SEEK_SET);
read(fd,buff,size/2);
printf("The value read:\n%s",buff);
}
return 0;
}
