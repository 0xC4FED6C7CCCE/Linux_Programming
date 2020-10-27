/*************************************************************************
    > File Name: 1-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 12时59分13秒
 ************************************************************************/
#include "ch03.h"
#define records_size 4
int main(){
	int fd;
	int i;
	record records[records_size];
	records[0].size=3;
	records[1].size=8;
	records[2].size=2;
	records[3].size=9;
	for(i=0;i<records_size;i++)
		records[i].string = (char*)malloc(sizeof(char)*records[i].size);
	strcpy(records[0].string,"abc");
	strcpy(records[1].string,"defghijk");
	strcpy(records[2].string,"lm");
	strcpy(records[3].string,"nopqrstuv");
	if((fd = open("./test.txt",O_RDWR|O_CREAT,0644))==-1)
		err_exit("open!\n");
	char size[4];
	sprintf(size,"%d",records_size);
	write(fd,size,1);
	lseek(fd,4,SEEK_SET);
	for(i=0;i<records_size;i++){
		sprintf(size,"%d",records[i].size);
		write(fd,size,1);
		lseek(fd,4*(i+2),SEEK_SET);
	}
	for(i=0;i<records_size;i++){
		write(fd,records[i].string,records[i].size);
	}
	
	return 0;
}
