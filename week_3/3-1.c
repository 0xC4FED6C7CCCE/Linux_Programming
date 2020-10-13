/*************************************************************************
    > File Name: 3-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月08日 星期四 11时31分53秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	FILE *fp =fopen("./ftest.txt","w");
	int ret;
	char buf[80];
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	ret = fwrite(buf,sizeof(buf),1,fp);
	printf("%d\n",ret);
	fclose(fp);
	return 0;
}
