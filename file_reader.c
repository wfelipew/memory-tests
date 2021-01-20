#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int fd;
	char buff[100];
	fd=open(argv[1],O_RDWR);
		while(read(fd,buff,100)){
	}

}
