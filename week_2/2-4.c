#include "ch2.h"
int main(){
	int fd,i;
	char buf[100];	
	fd = open("./test.data",O_WRONLY|O_CREAT,0644);
	gets(buf);
	printf("process id = %d,i = %d,fd = %d",getpid(),i,fd);
	i=write(fd,buf,sizeof(buf));
	printf("after i=%d",i);
	sleep(500);
	return 0;
}
