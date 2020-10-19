/*************************************************************************
    > File Name: 4-7.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 10时52分15秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"
int main(){

	int nfd = dup(STDOUT_FILENO);
	int fd;
	close(STDOUT_FILENO);

	if((fd=open("out.dat",O_WRONLY|O_CREAT,0644))==-1)
		err_exit("open!\n");
	write(nfd,"nfd\n",4);
	write(fd,"fd\n",3);	

	write(STDOUT_FILENO,"stdout\n",7);
	printf("fd = %d\n",fd);
	printf("hello!\n");

	fflush(stdout);
	close(fd);
	return 0;
	
}
