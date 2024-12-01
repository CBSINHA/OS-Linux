#include<stdio.h>
#include<dirent.h>
int main(){
DIR *dir;
struct dirent *begin;
dir=opendir(".");
if(dir){
while((begin=readdir(dir))!=NULL){
printf("%s\n",begin->d_name);
}
}
return 0;
}
