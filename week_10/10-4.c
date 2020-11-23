/*************************************************************************
    > File Name: 10-4.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月23日 星期一 08时35分34秒
 ************************************************************************/

#include"ch10.h"
void foo(){
	fprintf(stderr,"foo says bye.\n");
}

void bar(){
	fprintf(stderr,"bar says bye.\n");
}

int main(int argc,char**argv){
	atexit(foo);
	atexit(bar);

	fprintf(stdout,"Oops ~~~ forget a newline!");
	sleep(2);
	//exit会刷新缓冲区，而_exit不会
	if(argc>1&&strcmp(argv[1],"exit")==0)
		exit(0);
	if(argc>1&&strcmp(argv[1],"_exit")==0)
		_exit(0);
	return 0;
}
