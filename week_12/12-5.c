/*************************************************************************
    > File Name: 12-5.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年12月07日 星期一 08时07分12秒
 ************************************************************************/

#include "ch12.h"
int main(int argc,char**argv)
{
	int fd[2],i;
	pid_t k;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pipe(fd);
	k = fork();
	if(k<0){
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0){
		printf("parent pid = %d\n",getppid());
		close(1);
		dup(fd[1]);
		execlp("./test","test","hello","world",NULL);
		exit(1);
	}
	else{
		wait(NULL);
		read(fd[0],buf,sizeof(buf));
		printf("%d receive from test : %s\n",getpid(),buf);
		return 0; 
	}
}

