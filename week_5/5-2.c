/*************************************************************************
    > File Name: 5-2.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 23时16分09秒
 ************************************************************************/

#include "ch05.h"
#include "y_or_n_ques.c"
int main(){

	int answer;
	printf("1: This is a buffer test program. ");
	fprintf(stderr,"2: --test message\n");
	answer = y_or_n_ques("3: Hello, Are you a student?");
	if(answer==1)
		printf("4: Hope you have high score.");
	else
		printf("4: Hope you have good salary");
	fprintf(stderr,"5: bye!\n");
	return 0;
}
