/*************************************************************************
    > File Name: 9-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 09时44分46秒
 ************************************************************************/

#include "ch09.h"

int main(){
	
	int fd_out;

	char buf[1024];

	pid_t pid;
	pid_t pid1;

	memset(buf,0,1024);

	fd_out = open(OUTFILE,O_WRONLY|O_CREAT,O_TRUNC,MODE);
	if(fd_out<0){
		fprintf(stderr,"failed to open %s reason(%s)\n",OUTFILE,strerror(errno));
		return 1;
	}

	pid = fork();
	if(pid<0){
		fprintf(stderr,"failed to fork , reason(%s)\n",strerror(errno));
		return 1;
	}
	if(pid==0){

		memset(buf,0,1024);
		sprintf(buf,"pid-c = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));
	
		pid1 = fork();
		if(pid1<0){
		fprintf(stderr,"failed to fork , reason(%s)\n",strerror(errno));
		return 1;
		}
		if(pid1==0){
		memset(buf,0,1024);		
		sprintf(buf,"pid-c-c = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));

		}else{
			wait(NULL);
			memset(buf,0,1024);
		sprintf(buf,"pid = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));
		}
	}else{

		wait(NULL);

		memset(buf,0,1024);
		sprintf(buf,"pid = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));
		pid1=fork();
		if(pid1<0){
		fprintf(stderr,"failed to fork , reason(%s)\n",strerror(errno));
		return 1;
		}
		if(pid1==0){

		memset(buf,0,1024);
		sprintf(buf,"pid = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));
		}else{
			wait(NULL);
		memset(buf,0,1024);
		sprintf(buf,"pid = %d, sj\n",getpid());
		write(fd_out,buf,strlen(buf));
		}
	}
}
