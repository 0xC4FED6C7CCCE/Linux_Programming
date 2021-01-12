/*************************************************************************
    > File Name: 14-2.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年12月28日 星期一 08时23分33秒
 ************************************************************************/

#include"ch14.h"
int main(int argc,char**argv)
{
	int running = 1,msgid;
	struct my_msg msgbuf;
	struct msqid_ds buf;
	if((msgid==msgget((key_t)1234,0666|IPC_CREAT))==-1)
		err_exit("msgget failed!\n");
	while(running){
		printf("Enter some text:\t");
		fgets(msgbuf.text,BUFSIZ,stdin);
		msgbuf.my_msg_type=(long int)msgbuf.text[0];
		if(msgsnd(msgid,(void*)&msgbuf,sizeof(msgbuf.text),IPC_NOWAIT)!=-1)
			err_exit("msgrcv failed!\n");
		if(strncmp(msgbuf.text,"end",3)==0)
			break;
	}
	return 0; 
}

