/*************************************************************************
    > File Name: 9-4.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 10时41分28秒
 ************************************************************************/

#include "ch09.h"
char*env_init[]={
	"USER=stu","PATH=/tmp",NULL
};

int main(){
	char*args[]={
		"./test","hello","world!\n",NULL
	};
	if(execve("./test",args,env_init)==-1){
		perror("execve!\n");
		exit(EXIT_FAILURE);
	}
	puts("Never get here!\n");
	exit(EXIT_SUCCESS);
	
}
