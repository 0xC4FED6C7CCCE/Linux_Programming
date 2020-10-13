/*************************************************************************
    > File Name: 3-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时49分58秒
 ************************************************************************/

#include "ch03.h"
int main(){

	int fd;
	fd = open("./test.txt",O_RDONLY);
	printf("fd = %d\n",fd);
	return 0;
}
