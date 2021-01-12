/*************************************************************************
    > File Name: 12-1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年12月07日 星期一 08时07分12秒
 ************************************************************************/

#include "ch12.h"
int main(int argc,char**argv)
{
	int fd1[2],fd2[2],i;
	pid_t k;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pipe(fd1);
	pipe(fd2);
	k = fork();
	if(k<0){
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0){
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		i=read(fd1[0],buf,sizeof(buf));
		if(i==0){
			printf("child read failed!\n");
			exit(0);
		}
		else{
			fprintf(stdout,"read from pipe : %s \t %s:byte\n",buf,i);
			sprintf(buf,"receive from parent %d byte!",strlen(buf));
			write(fd2[1],buf,sizeof(buf));
			exit(1);
		}
	}
	else{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d say hello to %d!",getpid(),k);
		i=write(fd1[1],buf,sizeof(buf));
		if(i==0){
			printf("parent write failed!\n");
			exit(0);
		}
		else{
			printf("write to pipe : %s\n",buf);
			i = read(fd2[0],buf,sizeof(buf));
			printf("child receive %s\n",buf);	
			exit(1);
		}
		wait(NULL);
		exit(0);
	}
	return 0; 
}

