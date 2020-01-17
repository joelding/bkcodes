#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	int fd ;
	char path[]= "hello";
	if ((fd=open(path,O_CREAT|O_TRUNC|O_WRONLY))<0){		//O_CREAT	如果文件不存在则建立文件
														//O_TRUNC	如果文件存在，则将文件的长度截至0
														//O_WRONLY	只写访问
		perror("open");
		exit(EXIT_FAILURE);
		}
	else{
		printf("opened %s\n",path);
		printf("descriptor is %d\n",fd);
		}
	if(close(fd)<0){
		perror("close");
		exit(EXIT_FAILURE);		
		}
	else{
		printf("close %s\n",path);
		}
	exit(EXIT_SUCCESS);
}
