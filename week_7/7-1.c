/*************************************************************************
    > File Name: 7-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 08时51分02秒
 ************************************************************************/

#include "ch07.h"
int main(int argc, char*argv[],char*env[]){
	int i;
	if(argc!=3){
		printf("Arguments failed!\n");
	}
	int x,y;
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	printf("%d + %d = %d \n",x,y,x+y);
	for(i=0;i<argc;i++){
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	for(i=0;env[i];i++){
		printf("env[%d] : %s\n",i,env[i]);
	}
}

