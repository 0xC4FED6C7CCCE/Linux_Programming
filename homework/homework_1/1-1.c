/*************************************************************************
    > File Name: 1-1.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2020年10月19日 星期一 11时33分51秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <unistd.h>

int main()
{
	int	i=0x0;
	int k,j;
	k = pow(2,sizeof(short)*8);
	for(j=0;j<k;j++){
		printf("%-20x%-20hd%-20hu\n",i,i,i);
		i++;
	}

    return 0;
}
