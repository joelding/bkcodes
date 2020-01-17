#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>		//Unix标准函数定义
#include <sys/types.h>	//提供对文件控制的函数

int main(void){
	mode_t newmask = 0222,oldmask;
	system("touch before");
	oldmask=umask(newmask);
	printf("old umask is %#o\n",oldmask);
	printf("new umask is %#o\n",newmask);
	system("touch after");

	exit(EXIT_SUCCESS);
}
