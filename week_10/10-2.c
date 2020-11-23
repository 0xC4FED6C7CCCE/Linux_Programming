/*************************************************************************
    > File Name: 10-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 12时38分53秒
 ************************************************************************/

#include"ch10.h"
int main(){
	char*argv[]={
		"./test",
		"hello",
		"world",
		NULL
	};
	int i;
	printf("10-2 : pid = %d, ppid = %d \n",getpid(),getppid());
	i=execve("./test",argv,NULL);
	if(i==-1){
		perror("execve failed!\n");
		exit(1);
	}
	printf("after calling!\n");
	return 0;
	
}
