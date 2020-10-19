/*************************************************************************
    > File Name: y_or_n_ques.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 23时10分58秒
 ************************************************************************/

#include<stdio.h>
int y_or_n_ques(char*s){
	char answer;
	printf("%s\n",s);
	scanf("%c",&answer);
	if(answer=='y')
		return 1;
	else
		return 0;
}
