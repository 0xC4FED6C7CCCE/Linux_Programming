/*************************************************************************
    > File Name: 4-6.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 10时35分48秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"
int main(){
	int fd;
	if((fd=open("./out.dat",O_WRONLY|O_CREAT))==-1)
		err_exit("open!\n");
	if(dup2(fd,STDOUT_FILENO)==-1)
		err_exit("Redirect!\n");
	printf("This is test data for redirect!\n");

	return 0;
}
