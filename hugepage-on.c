#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char* argv[]){
	char  *ptr, *tmp_ptr;


	unsigned long i;
	if(argc < 2){
		printf("Usage: <Size allocation (megabytes)>");
	}
	int megabytes = atoi(argv[1]);
        ptr=mmap(0,1024*1024* (unsigned long) megabytes,PROT_WRITE|PROT_READ,MAP_HUGETLB|MAP_PRIVATE|MAP_ANONYMOUS,-1,0);

	if(ptr==MAP_FAILED){
                printf("Falha ao alocar esta quantidade de memoria\n");
                return 1;
        }
	tmp_ptr=ptr;
	for(i=0;i-1<1024*1024* (unsigned long) megabytes; i++){
                strcpy(tmp_ptr,"a");
		tmp_ptr++;
	}

	printf("Memoria alocada\n");
	munmap(ptr,1024*1024* (unsigned long) megabytes);
	printf("Memoria desalocada\n");
	return 0;
}


