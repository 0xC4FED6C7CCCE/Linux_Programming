/*************************************************************************
    > File Name: ch03.h
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时52分12秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void err_exit(char*s){

	printf("Usage : %s is faild\n",s);
	exit(1);
}
