/*************************************************************************
    > File Name: 3-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时49分58秒
 ************************************************************************/

#include "ch03.h"
int main(){
	char buf[80];

	FILE * fp;
	if((fp=fopen("test_file","w"))==NULL)
	{
		perror("fopen failed! \n");
		exit(1);
	}

	printf("writing string to testfile\n");
	fputs("test data",fp);
	if((fp=freopen("test_file","r",fp))==NULL){
		perror("freopen failed!\n");
		exit(1);
	}
	printf("read string from test_file:\t");
	fgets(buf,sizeof(buf),fp);
	printf("the string is	%s\n",buf);

	fclose(fp);
	return 0;
}
