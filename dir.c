#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
int main(){
DIR *dir;
struct dirent *begin;
dir=opendir(".");
if(dir){
while((begin=readdir(dir))!=NULL){
printf("%s\n",begin->d_name);
}
}
sleep(3);
printf("..........ooeeaaaeeeooeeeaaaeee");
return 0;
}
