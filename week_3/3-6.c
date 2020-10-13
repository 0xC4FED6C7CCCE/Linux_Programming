/*************************************************************************
    > File Name: 3-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时49分58秒
 ************************************************************************/

#include "ch03.h"
int main(){

	int fd;
	FILE * fp;
	fd = open("./test.txt",O_RDWR);
	printf("fd = %d\n",fd);
	fp=fdopen(fd,"w+");
	fprintf(fp,"test data %s\n","hello");
	fclose(fp);
	close(fd);
	return 0;
}
