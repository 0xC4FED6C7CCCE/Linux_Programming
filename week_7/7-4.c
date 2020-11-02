/*************************************************************************
    > File Name: 7-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 10时52分01秒
 ************************************************************************/

#include "ch07.h"
static void callback1(void){
	printf("---------Callback1-----------\n");
}

static void callback2(void){
	printf("---------Calback2------------\n");
}

static void callback3(void){
	printf("---------Calback3------------\n");
}

static void __attribute__((destructor))after_main(void){
	printf("---------After main-----------\n");
}
int main(void){
		atexit(callback1);	atexit(callback2);atexit(callback3);
	printf("----data in buffer-----");
	exit(0);
//	_exit(0);
}

