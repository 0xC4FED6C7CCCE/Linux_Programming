/*************************************************************************
    > File Name: 3-5.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 12时03分44秒
 ************************************************************************/

#include "ch03.h"
int main(){
	FILE * fp = fdopen(1,"w+");
	fprintf(fp,"%s\n","hello!");
	fclose(fp);
	return 0;
}

