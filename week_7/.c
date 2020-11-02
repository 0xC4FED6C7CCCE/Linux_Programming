/*************************************************************************
    > File Name: .c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年11月02日 星期一 14时41分43秒
 ************************************************************************/

#include"ch07.h"

static void set_env_string(void){
	char test_env[]="test_env=test";
	if(putenv(test_env)!=0){
		printf("Faild to put new env var!\n");
	}
	printf("1.The test_env string is %s\n",getenv("test_env"));
}

static void show_env_string(void){
	printf("2.The test_env string is %s\n",getenv("test_env"));
}

int main(){
	set_env_string();
	show_env_string();
}

