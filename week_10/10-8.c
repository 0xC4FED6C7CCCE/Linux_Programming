/*************************************************************************
    > File Name: 10-8.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 15时14分12秒
 ************************************************************************/

#include"ch10.h"
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("fork failed!\n");
		exit(-1);
	}else if(pid==0){
		char*argv[]={
		"./test","hello",NULL
		};
		printf("child : pid = %d , ppid = %d , re = %d \n",getpid(),getppid(),pid);
		execve("./test",argv,NULL);
		exit(99);
		
	}else{
		int s,r;
		r = wait(&s);
		printf("exit code = %d , wait pid = %d\n",WEXITSTATUS(s),r);
		return 0;
	}
}

