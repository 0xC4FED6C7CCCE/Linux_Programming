/*************************************************************************
    > File Name: 1-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 12时59分13秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"
int main(){
	int fd;
	char buf1[3]="abc";
	char buf2[8]="defg0000";
	char buf3[2]="hi";
	char buf4[9]="jklmnopqr";
	if((fd = open("./test.txt",O_RDWR|O_CREAT,0644))==-1)
		err_exit("open!\n");
	write(fd,"4",1);
	lseek(fd,4,SEEK_SET);
	write(fd,"3",1);
	lseek(fd,8,SEEK_SET);
	write(fd,"8",1);
	lseek(fd,12,SEEK_SET);
	write(fd,"2",1);	
	lseek(fd,16,SEEK_SET);
	write(fd,"9",1);
	lseek(fd,20,SEEK_SET);
	
	write(fd,buf1,3);
	write(fd,buf2,8);
	write(fd,buf3,2);
	write(fd,buf4,9);
	
	return 0;
}
