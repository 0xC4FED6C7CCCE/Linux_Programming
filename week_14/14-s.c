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
	long int msg_type = -57;
	if((msgid==msgget((key_t)1234,0666|IPC_CREAT))==-1)
		err_exit("msgget failed!\n");
	while(running){
		if(msgrcv(msgid,(void*)&msgbuf,BUFSIZ,-57,IPC_NOWAIT)!=-1)
			printf("You wrote %s\n",msgbuf.text);
		else if(errno==ENOMSG && msgrcv(msgid,(void*)&msgbuf,BUFSIZ,0,0)!=-1)
			printf("You wrote %s\n",msgbuf.text);
		else
			err_exit("msgrcv failed!\n");
		if(strncmp(msgbuf.text,"end",3)==0)
			break;
	}
	if(msgctl(msgid,IPC_RMID,0)==-1)
		err_exit("msgctl failed!\n");
	
	return 0; 
}

