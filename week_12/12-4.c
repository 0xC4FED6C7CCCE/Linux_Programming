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
		close(fd1[0]);
		close(fd2[1]);
		read(fd1[1],buf,sizeof(buf));
			sprintf(buf,"parent = %d : %d send message!\n",getpid());
			write(fd2[0],buf,sizeof(buf));
			read(fd1[1],buf,sizeof(buf));
			printf("%d receive %s\n",getpid(),buf);
			exit(1);
		
	}
	else{
		pid_t k1;
		k1=fork();
		if(k1<0){
			perror("fork error!\n");
		}
		else if(k1==0){
			close(fd1[1]);
			close(fd2[0]);
			read(fd1[0],buf,sizeof(buf));
			printf("%d receive %s\n",getpid(),buf);
			sprintf(buf,"parent = %d : %d send message!\n",getpid());
			write(fd2[1],buf,sizeof(buf));
				
		}else{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
			wait(NULL);
			wait(NULL);
			return 0; 
		}
	}
}

