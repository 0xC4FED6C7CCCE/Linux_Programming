/*************************************************************************
    > File Name: 4-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月13日 星期二 22时53分00秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"
int main(){
	char a[]="abcdefghij";
	char b[]="0123456789";
	int fd;
	if((fd=open("file.hole",O_WRONLY|O_CREAT,0644))<0)
		err_exit("Create error!");
	if(write(fd,a,10)!=10)
		err_exit("Write error!");
	if(lseek(fd,40,SEEK_SET)==-1)
		err_exit("Lseek error!");
	if(write(fd,b,10)!=10)
		err_exit("Write error!");
	return 0;
}
