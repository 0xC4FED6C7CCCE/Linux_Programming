/*************************************************************************
    > File Name: 4-4.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 09时39分09秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"
int main(){

	int fd1,fd2;
	char buf[6];
	memset(buf,0,6);
	fd1 = open("./file.hole",O_RDONLY);
	fd2 = open("./file.hole",O_RDONLY);
	printf("fd1 = %d, fd2 = %d\n",fd1,fd2);

	lseek(fd1,4,SEEK_SET);
	read(fd2,buf,5);
	printf("fd2 is %s\n",buf);
	read(fd1,buf,5);
	printf("fd1 is %s\n",buf);
	return 0;
}
