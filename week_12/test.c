/*************************************************************************
    > File Name: test.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 12时28分38秒
 ************************************************************************/

#include "ch12.h"
int main(int argc,char**argv){
	int i;
	printf(" pid = %d , ppid = %d\n",getpid(),getppid());
	for(i=0;i<argc;i++){
		printf("argv[%d] : %s\n",i,argv[i]);
	}
	return 0;
}
