/*************************************************************************
    > File Name: myfun.c
    > Author: 
    > Mail:  
    > Created Time: 2020年10月26日 星期一 14时15分13秒
 ************************************************************************/

#include "my.h"

int id_is_exist(int id){
	int count;
	int i;
	user ** u = getUsers(&count);
	for(i=0;i<count;i++)
		if(u[i]->id==id)
			return 1;
	return 0;
}

void input(){
	user u={
		0,"","",""
	};
	printf("请输入id\n");
	scanf("%d",&u.id);
	if(id_is_exist(u.id)){
		err_exit("id is exist!");
		exit(-1);
	}
	printf("请输入姓名\n");
	scanf("%s",u.name);
	printf("请输入手机号\n");
	scanf("%s",u.htel);
	printf("请输入电话号码\n");
	scanf("%s",u.tel);
	save(u);
}

void save(user u){
	FILE * fp;
	if((fp = fopen("./user.dat","a+"))==NULL)
		err_exit("open fail");
	fprintf(fp,"%d\t%s\t%s\t%s\n",u.id,u.name,u.htel,u.tel);	
	fclose(fp);
}

void output(){
	FILE*fp;
	user u;
	if((fp=fopen("./user.dat","r"))==NULL)
		err_exit("open fail");
	printf("userid\tname\thtel\ttel\n");
	while((fscanf(fp,"%d%s%s%s",&u.id,u.name,u.htel,u.tel))!=EOF)
	{
		printf("%d\t%s\t%s\t%s\n",u.id,u.name,u.htel,u.tel);	
	}
}

int cmp_low(const void* c1,const void *c2){
	return strcmp(*(char**)c2 , *(char**)c1);
}

int cmp_up(const void* c1,const void *c2){
	return strcmp(*(char**)c1 , *(char**)c2);
}

void print(user** u,int count){
	int i=0;	
	for(i=0;i<count;i++)
		printf("%d\t%s\t%s\t%s\n",u[i]->id,u[i]->name,u[i]->htel,u[i]->tel);
	
}





int getIndex(map*maps,char*s,int count){
	int i=0;
	for(i=0;i<count;i++)
		if(strcmp(maps[i].name,s)==0)
			return maps[i].index;
}

user** getUsers(int *Count){
	int count=0;
	int i=0;
	user**u;
	char buf[40];	
	FILE * fp;
	if((fp = fopen("./user.dat","r"))==NULL)
		err_exit("open fail");

	while((fgets(buf,40,fp))!=NULL)
		count++;
	*Count=count;
	u=(user**)malloc(sizeof(user*)*count);
	for(i=0;i<count;i++){
		u[i] = (user*)malloc(sizeof(user));
	}
	i=0;
	fseek(fp,0,SEEK_SET);
	while((fscanf(fp,"%d%s%s%s",&(u[i]->id),u[i]->name,u[i]->htel,u[i]->tel))!=EOF)
		i++;
	return u;
}

void sort(){
	int i=0;
	int count;
	user**u = getUsers(&count);
	map maps[count]; 
	char* strings[count];
	for(i=0;i<count;i++)
		strings[i]=(char*)malloc(sizeof(char)*8);
	for(i=0;i<count;i++){
		maps[i].index=i;
		strcpy(maps[i].name,u[i]->name);
		strcpy(strings[i],u[i]->name);
	}


	printf("输入升序/降序( u / l )\n");
	char c;
	int index;
	fflush(stdin);
	scanf("%c",&c);
	switch(c){
	case 'u':
	qsort(strings,count,sizeof(strings[0]),cmp_up);
		break;
	case 'l':
	qsort(strings,count,sizeof(strings[0]),cmp_low);
		break;
	default:
		printf("输入 u/l \n");
		break;
	}

	for(i=0;i<count;i++){
		index = getIndex(maps,strings[i],count);
		printf("%d\t%s\t%s\t%s\n",u[index]->id,u[index]->name,u[index]->htel,u[index]->tel);
	}
	
}

/*4294967295*/

user *randdat(){
	int Rand;
	srand((unsigned)time(NULL));
	Rand = rand();
	int id = rand()%4294967295;
	printf("%d\n",id);
	char*[]={
		"135","188","1"
	}
	return NULL;
}
