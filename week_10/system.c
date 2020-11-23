/*************************************************************************
    > File Name: system.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 12时28分38秒
 ************************************************************************/

#include "ch10.h"
#include "string.h"
int main(int argc,char**argv){
	int i;
	pid_t pid;
	char ** Argvs = (char**)malloc(sizeof(char*)*(argc-2));
	char * name =(char*)malloc(sizeof(char)*(strlen(argv[1])));
	if(argc<=2){
		perror("param failed!\n");
		exit(0);
	}
	strcpy(name,argv[1]);
	printf("name = %s\n",name);
	for(i=2;i<argc;i++){
		Argvs[i-2] = (char*)malloc(sizeof(char)*(strlen(argv[i])));
		strcpy(Argvs[i-2],argv[i]);
	}
		
/*
	for(i=0;i<argc-2;i++){
		printf("argvs[%d] : %s\n",i,Argvs[i]);
	}
	*/

	pid = fork();
	if(pid==0){
		printf("child : pid = %d , ppid = %d\n",getpid(),getppid());
		execve(name,Argvs,NULL);
		exit(99);
	}else
	{
		int s,r;
		r = wait(&s);
		printf("exit code = %d, wait pid = %d\n",WEXITSTATUS(s),r);
	}

	return 0;
}
