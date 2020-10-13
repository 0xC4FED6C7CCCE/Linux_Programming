/*************************************************************************
    > File Name: 3-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时49分58秒
 ************************************************************************/

#include "ch03.h"
int main(){

	FILE *fp;
	fp = fopen("./test.txt","r");
	printf("fd = %d\n",fp->_fileno);
	return 0;
}
