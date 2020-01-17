#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc,char **argv){
	struct stat buf;
	mode_t mode;
	char type[80];
	int fd;
	if(argc!=2){
		puts("USAGE:mstat {file}");
		exit(EXIT_FAILURE);
		}
	if((fd=open(argv[1],O_RDONLY))<0){
		perror("open");
		exit(EXIT_FAILURE);
		}
	if((fstat(fd,&buf))<0){
		perror("fstat");
		exit(EXIT_FAILURE);
		}
}
