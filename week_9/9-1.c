/*************************************************************************
    > File Name: 9-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 09时27分14秒
 ************************************************************************/

#include "ch09.h"
int g=0;
int main(){
	pid_t pid;
	int l=99;
	pid = fork();
	if(pid<0){
		perror("Fork failed!\n");
		exit(-1);
	}else if(pid==0){

		printf("child : ppid = %d,pid=%d \n",getppid(),getpid());
		printf("child : init g = %d,l=%d \n",g,l);
		g--;
		l++;
		printf("child : g = %d,l=%d \n",g,l);
	}else{
		wait(NULL);
		printf("parent : child ppid = %d,pid = %d\n",pid,getpid());
		printf("parent : init g = %d,l=%d \n",g,l);
		g++;
		l--;
		printf("parent : g = %d, l = %d\n",g,l);
		return 0;
	}

}
