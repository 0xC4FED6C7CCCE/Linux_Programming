/*************************************************************************
    > File Name: 5-3.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 23时32分12秒
 ************************************************************************/

#include "ch05.h"
int main(){
	char buf[20];
	int ret;
	FILE *fp=fopen("./tmp.txt","w+");
	if(!fp){
		printf("Fail to open file\n");
		exit(-1);
	}
	ret = fwrite("123",sizeof("123"),1,fp);
	printf("We write %d byte\n",ret);

	memset(buf,0,sizeof(buf));
	fseek(fp,0,SEEK_SET);
	ret = fread(buf,1,20,fp);
	printf("We read %s ,ret is %d\n",buf,ret);
	fwrite("456",sizeof("456"),1,fp);
	fclose(fp);
	return 0;
}

