/*************************************************************************
    > File Name: test.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 12时28分38秒
 ************************************************************************/

#include "ch11.h"
int main(int argc,char**argv){
	int i;
	printf("test : pid = %d , ppid = %d\n",getpid(),getppid());
	for(i=0;i<argc;i++){
		printf("argv[%d] : %s\n",i,argv[i]);
	}
//	sleep(60);
	return 0;
}
