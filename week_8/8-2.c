/*************************************************************************
    > File Name: 8-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月09日 星期一 08时02分13秒
 ************************************************************************/

#include"ch08.h"

int main(){
	int *pt=NULL;
	int i=0;
	for(i=0;i<1024*1024;i++){
		pt=(int*)malloc(i*1024*sizeof(int));
		if(pt==NULL){
			err_exit("alloc_err!");
		}
		printf("system allocate %dKB\n",4*i);

		free(pt);
	}
	printf("address of pt : %x, %d\n",pt,sizeof(pt));
	return 0;
}

