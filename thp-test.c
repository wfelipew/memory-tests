#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char* argv[]){
	char  *ptr, *tmp_ptr;


	unsigned long i,n,total_size,offset;

	if(argc < 2){
		printf("Usage: <Size allocation (megabytes)>");
	}
	int megabytes = atoi(argv[1]);
	total_size = 1024*1024* (unsigned long) megabytes;
        ptr=mmap(0,1024*1024* (unsigned long) megabytes,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);

	if(ptr==MAP_FAILED){
                printf("Falha ao alocar esta quantidade de memoria\n");
                return 1;
        }

	tmp_ptr=ptr;
        for(i=0;i+1<  (unsigned long) megabytes; i++){
		offset=((unsigned long) random()) % (total_size + 1);
		for(n=0;n<8388608;n++){
			if(tmp_ptr+offset+n >= (tmp_ptr+total_size)-1 ){
				break;
			}
                	strcpy(tmp_ptr+offset+n,"a");
		}
        }



	printf("Memoria alocada\n");
	munmap(ptr,1024*1024* (unsigned long) megabytes);
	printf("Memoria desalocada\n");
	return 0;
}


