/*************************************************************************
    > File Name: 1-4.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 21时18分04秒
 ************************************************************************/

#include<stdio.h>
#include "ch03.h"

int main(int argc,char**argv){
	int fd;
	int account;
	char buf[5];
	char*data;
	int i,m,o;
	m=0;
	o=0;
	if(argc!=2)
		err_exit("参数错误\n");

	if((fd = open("./test.txt",O_RDONLY,0644))<0)
		err_exit("open error!\n");
	int n = atoi(argv[1]);
	read(fd,&buf,4);
	account = atoi(buf);
	if(account<n||n<=0)
		err_exit("越界！\n");
	for(i=0;i<n-1;i++){
		lseek(fd,4*(i+1),SEEK_SET);
		read(fd,&buf,4);
		m+=atoi(buf);
	}
	printf("account = %d\t m = %d\n",account,m);
	lseek(fd,n*4,SEEK_SET);
	read(fd,&buf,4);
	//第n条记录长度
	o = atoi(buf);
	printf("o = %d\n",o);
	data = (char*)malloc(sizeof(char)*o);	
	lseek(fd,(account+1)*4+m,SEEK_SET);

	read(fd,data,o);
	printf("%s\n",data);	
	return 0;
}
