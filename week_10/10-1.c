/*************************************************************************
    > File Name: test.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 12时25分18秒
 ************************************************************************/

#include"ch10.h"
int main(int argc,char**argv){
	printf("10-1 : pid = %d , ppid = %d\n",getpid(),getppid());
	system("./test hello world 2020 11 23");
//	sleep(60);
	printf("after calling\n");
	return 0;
}
