#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>		//Unix标准函数定义
#include <fcntl.h>			//提供对文件控制的函数

#define BUFSZ 1024

void err_quit(char * msg);

int main(void){
	int fds[2];
	char buf[BUFSZ];
	int i,rc,maxfd;
	fd_set watchset,inset;

	if((fds[0]=open("pipe1", O_RDWR|O_NONBLOCK))<0)
		err_quit("Open pipe1");
	if((fds[1]=open("pipe2", O_RDWR|O_NONBLOCK))<0)
		err_quit("Open pipe2");

	FD_ZERO(&watchset);			//清除watchset集合
	FD_SET(fds[0],&watchset);	//把串口0的描述符com[COM0].fd添加到watchset中
	FD_SET(fds[1],&watchset);

	maxfd=fds[0]>fds[1] ? fds[0]:fds[1];

	while(FD_ISSET(fds[0],&watchset)||FD_ISSET(fds[1],&watchset)){
		inset=watchset;
		if(select(maxfd+1,&inset,NULL,NULL,NULL)<0)
			err_quit("select");

		for(i=0;i<2;++i){
			if(FD_ISSET(fds[i],&inset)){
				rc=read(fds[i],buf,BUFSZ-1);		//接收数据
//				printf("\n接收字符数：%d\n",rc);
				if(rc>0){
					buf[rc]=0;
					printf("read:%s",buf);
					}
				else if(rc==0){
					close(fds[i]);
					FD_CLR(fds[i],&watchset);
					}
				else
					err_quit("read");
				}
			}
		}
	exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
     perror(msg);//#define perror(s) printf("%s: no files!\n", (s))
     exit(EXIT_FAILURE);
}
