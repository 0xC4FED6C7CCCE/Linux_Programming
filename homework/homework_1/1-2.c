/*************************************************************************
    > File Name: 1-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 11时41分13秒
 ************************************************************************/
#include "ch03.h"
#define buf_size 8

typedef struct iobuf{
	char buf[buf_size];
	char over_flow[buf_size];
}iobuf;

int main( )
{	
	iobuf buffer;
	memset(buffer,'\0',sizeof(iobuf));
	gets(buffer.buf);

	fprintf(stdout,"buf is \"s \n",buffer.buf);
	fprintf(stdout,"over_flow is \"s \n",buffer.over_flow);

	return 0;
}

