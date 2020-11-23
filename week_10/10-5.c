/*************************************************************************
    > File Name: 10-5.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月23日 星期一 09时00分34秒
 ************************************************************************/

#include"ch10.h"
int main(int argc,char**argv)
{
	
	pid_t pid;
	pid = fork();
	if(pid<0){
		perror("error fork!");
		exit(1);
	}else if(pid == 0){
		exit(0);
	}else{
		sleep(300);
		wait(NULL);
	}

	return 0; 
}

