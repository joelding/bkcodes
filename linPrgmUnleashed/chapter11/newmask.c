#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>		//Unix��׼��������
#include <sys/types.h>	//�ṩ���ļ����Ƶĺ���

int main(void){
	mode_t newmask = 0222,oldmask;
	system("touch before");
	oldmask=umask(newmask);
	printf("old umask is %#o\n",oldmask);
	printf("new umask is %#o\n",newmask);
	system("touch after");

	exit(EXIT_SUCCESS);
}
