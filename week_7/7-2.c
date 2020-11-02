/*************************************************************************
    > File Name: 7-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 08时42分17秒
 ************************************************************************/

#include<stdio.h>
#include "ch07.h"

static void __attribute__((constructor))before_main(void){
	printf("--------Before main ----------\n");
}

static void __attribute__((destructor))after_main(void){
	printf("---------After main-----------\n");
}
int main(){
	printf("   main   function  is runnning!\n");
}
