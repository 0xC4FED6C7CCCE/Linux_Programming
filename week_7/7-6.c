/*************************************************************************
    > File Name: 7-6.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 14时28分23秒
 ************************************************************************/

#include "ch07.h"
int main(){
	int i;

	extern char ** environ;

	printf("%s\n",getenv("PATH"));
	
	for(i=0;environ[i]!=NULL;i++)
		printf("env[%d]: %s\n",i,environ[i]);


	return 0;
}
