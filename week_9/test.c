/*************************************************************************
    > File Name: test.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 10时45分08秒
 ************************************************************************/

#include "ch09.h"

int main(int argc,char*argv[]){
	int i;
	extern char**environ;
	char**env = environ;

	for(i=0;i<argc;i++){
		printf("%s",argv[i+1]);
	}

	while(*env){
		printf("%s\n",*env);
		env++;
	}
		
	
	return 0;
}
