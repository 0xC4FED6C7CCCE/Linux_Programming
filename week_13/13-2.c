/*************************************************************************
    > File Name: 13-1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年12月14日 星期一 08时20分27秒
 ************************************************************************/

#include"ch13.h"
int main(int argc,char**argv)
{
	int fifo_fd,n,i,total_bytes=0;
	char sendbuf[PIPE_BUF];
	
	if((fifo_fd=open(FIFO_FILE,O_WRONLY))<0){
		printf("Could not open fifo %s\n",FIFO_FILE);
		exit(-1);
	}
	printf("Parent %d 's child %d opened: %s\n",getppid(),getpid(),FIFO_FILE);
	do{
		if((n=write(fifo_fd,sendbuf,PIPE_BUF))==-1){
			perror("Write failed!\n");
			exit(-1);
		}
		printf("%d write %d bytes\n",getpid(),n);
		total_bytes+=n;
	}while(total_bytes<TEN_MEG);
	close(fifo_fd);
	printf("Process %d finished \n",getpid());
	return 0; 
}

