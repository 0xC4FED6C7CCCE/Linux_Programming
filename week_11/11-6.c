/*************************************************************************
    > File Name: 11-1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 15时14分12秒
 ************************************************************************/

#include"ch11.h"
#include <time.h>


int main()
{
	pid_t pid1;
	pid1 = fork();
	if(pid1<0){
		perror("fork failed!\n");
		exit(-1);
	}else if(pid1==0){
		pid_t pid11;
		pid11 = fork();
		time_t timep1;
		timep1 = time((time_t*)0);

		if(pid11<0){
		perror("fork failed!\n");
		exit(-1);
		}
		else if(pid11==0){
			printf("child 11 : pid11 = %d, ppid = %d\n",getpid(),getppid());
			printf("%s\n",ctime(&timep1));

			sleep(5);
		}else{
			int s11,r11;
			r11 = waitpid(pid11,&s11,0);
			if(WIFEXITED(s11)){
				printf("child 11 exit normaly! exit code %d\n",WEXITSTATUS(s11));
				printf("child 1 : pid1 = %d , ppid = %d , re = %d \n",getpid(),getppid(),pid1);
			}else{
				printf("child 11 exit abnormaly! exit with exitcode %d\n",WTERMSIG(s11));
			}
		}
	}else{
		pid_t pid2;
		pid2 = fork();
		time_t timep2;
	timep2 = time((time_t*)0);
		if(pid2<0){
			perror("fork failed!\n");
			exit(-1);
		}
		else if(pid2==0){
		pid_t pid21;
		pid21 = fork();
		if(pid21<0){
			perror("fork failed!\n");
			exit(-1);
		}
		else if(pid21==0){
			printf("child 21 : pid21 = %d, ppid = %d\n",getpid(),getppid());
			printf("%s\n",ctime(&timep2));

			sleep(5);
		}else{
			int s21,r21;
			r21 = waitpid(pid21,&s21,0);
			if(WIFEXITED(s21)){
				printf("child 21 exit normaly! exit code %d\n",WEXITSTATUS(s21));
				printf("child 2 : pid2 = %d , ppid = %d , re = %d \n",getpid(),getppid(),pid2);
			}else{
				printf("child 21 exit abnormaly! exit with exitcode %d\n",WTERMSIG(s21));
				}
			}
		}
		else{

				int s1,r1,s2,r2;
				r1 = waitpid(pid1,&s1,0);
				r2 = waitpid(pid2,&s2,0);
				if(WIFEXITED(s1))
					printf("child 1 exit normaly! exit code %d\n",WEXITSTATUS(s1));
				else
					printf("child 1 exit abnormaly! exit with signal %d\n",WTERMSIG(s1));
				if(WIFEXITED(s2))
					printf("child 2 exit normaly! exit code %d\n",WEXITSTATUS(s2));
				else
					printf("child 2 exit abnormaly! exit with exitcode %d\n",WTERMSIG(s2));
				printf("parent ended!\n");
			}		
		}
		return 0;	
}

