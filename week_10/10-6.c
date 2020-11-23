/*************************************************************************
    > File Name: 10-6.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 09时10分40秒
 ************************************************************************/

#include"ch10.h"
int main(int argc,char**argv)
{
	int r1,r2,r3;
	r1=fork();
	if(r1==0){
		printf("child 1 : pid = %d, ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	if(r1>0){
		r2=fork();
		if(r2==0){
			printf("child 2 : pid = %d, ppid = %d\n",getpid(),getppid());
			exit(0);
		}
		wait(NULL);
		wait(NULL);
		printf("parent : pid = %d , r1 = %d , r2 = %d\n",getpid(),r1,r2);
		return 0; 
	}
}

