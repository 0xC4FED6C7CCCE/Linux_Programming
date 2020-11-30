/*************************************************************************
    > File Name: 11-1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 15时14分12秒
 ************************************************************************/

#include"ch11.h"
int main()
{
	int i;
	pid_t pid1;
	pid1 = fork();
	if(pid1<0){
		perror("fork failed!\n");
		exit(-1);
	}else if(pid1==0){
		char*argv[]={
		"./test","hello",NULL
		};
		printf("child : pid1 = %d , ppid = %d , re = %d \n",getpid(),getppid(),pid1);
		execve("./test",argv,NULL);
		exit(0);
		
	}else{
		pid_t pid2;
		pid2 = fork();
		if(pid2<0){
			perror("fork failed!\n");
			exit(-1);
		}
		else if(pid2==0){
			printf("child2 : pid2 = %d ,ppid = %d , re = %d\n",getpid(),getppid(),pid2);
			for(i=0;i<9;i++)
				printf("%d : Hello!\n",i);
			exit(0);
		}else{
			int s1,r1,s2,r2;
			r1 = wait(&s1);
			r2 = wait(&s2);
			if(r1==pid1){
				printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
			}else if(r1==pid2){
				printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
			}
			if(r2==pid2){
				printf("child 1 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
			}else if(r2==pid1){
				printf("child 2 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
			}
		}
		return 0;
	}
}

