/*************************************************************************
    > File Name: 5-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 22时16分53秒
 ************************************************************************/

#include "ch05.h"
int main(){
	int i;	
	//方法一
	//printf("hello!\n");

	//方法二
	
	/*
	printf("hello");
	for(i=0;i<1024;i++){
		printf(" ");
	}
	*/

	//方法三
	
	/*
	printf("hello");
	fflush(stdout);
	*/

	//方法四
	
	/*
	printf("hello");
	fclose(stdout);
	*/

	//方法五
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello!\n");
	while(1);
	return 0;
}
