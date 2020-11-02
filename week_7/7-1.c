/*************************************************************************
    > File Name: 7-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 08时51分02秒
 ************************************************************************/

#include "ch07.h"
int main(int argc, char*argv[]){
	int i;
	for(i=0;i<argc;i++){
		printf("argv[%d]: %s\n",i,argv[i]);
	}
}

