#include <stdio.h>
#include <sys/mman.h>
#include <string.h>



int main (int argc, char* argv[]){

	char *ptr_a, *ptr_b;	
        size_t size = 1024*1024*4;
        
	printf("Pressione qualquer tecla para alocar memoria anonima:"); 
	getchar();
        ptr_a=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        ptr_b=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	strcpy(ptr_a,"mapeado a");
	strcpy(ptr_b,"mapeado b");
	printf("Pressiona qualquer tecla para desalocar memoria anonima");
	getchar();
        munmap(ptr_a,size);
        munmap(ptr_b,size);
	printf("Pressione qualquer tecla para encerrar");
	getchar();
}

