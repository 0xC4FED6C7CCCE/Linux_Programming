/*************************************************************************
    > File Name: my.h
    > Author: 
    > Mail: 
    > Created Time: 2020年10月26日 星期一 14时11分47秒
 ************************************************************************/

#include "ch05.h"

typedef struct user{
	int id;
	char name[8];
	char htel[12];
	char tel[12];
}user;

typedef struct map{
	int index;
	char name[8];
}map;

void input();

void save(user u);
void output();
int cmp_up(const void*c1,const void*c2);
int cmp_low(const void*c1,const void*c2);
void sort();
int getIndex(map*maps,char *s,int count);
user** getUsers();
int id_is_exist(int id);
user *randdat();
