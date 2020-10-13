#include <stdio.h>
int main(){

	int ret = write(0,"hello\n",13);
	printf("ret=%d",ret);	
	sleep(500);
}
