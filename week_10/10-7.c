/*************************************************************************
    > File Name: 10-7.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 09时10分40秒
 ************************************************************************/

#include"ch10.h"
int main(int argc,char**argv)
{
	int r1,r2,r3,r21,r22;
	r1=fork();
	if(r1==0){
		printf("child 1 : pid = %d, ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	if(r1>0){
		r2=fork();
		if(r2==0){
			r21 = fork();
			if(r21==0){
				printf("child 21 : pid = %d , ppid = %d \n",getpid(),getppid());
				exit(0);
			}
			if(r21>0){
				r22 = fork();
				if(r22==0){
					printf("child 22 : pid = %d , ppid= %d \n",getpid(),getppid());
					exit(0);
				}
			wait(NULL);
			wait(NULL);
			printf("child 2 : pid = %d, ppid = %d\n",getpid(),getppid());
			exit(0);
			}
		
		}
		if(r2>0){
			r3=fork();
			if(r3==0){
				printf("child 3 : pid = %d, ppid = %d\n",getpid(),getppid());
				exit(0);
			}
		wait(NULL);
		wait(NULL);
		wait(NULL);
		printf("parent : pid = %d , r1 = %d , r2 = %d , r3 = %d\n",getpid(),r1,r2,r3);
		}

		return 0; 
	}
}

