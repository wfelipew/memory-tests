#include <stdio.h>
#include <sys/mman.h>
#include <string.h>



int main (int argc, char* argv[]){

	char *ptr_a, *ptr_b, *ptr_c;	
        size_t size = 1024*1024*4;
        
	printf("Pressione qualquer tecla para alocar memoria anonima:"); 
	getchar();
        ptr_a=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        ptr_b=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        ptr_c=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	printf("Pressiona qualquer tecla para desalocar prt_b:");
	getchar();
        munmap(ptr_b,size);
	printf("Pressiona qualquer tecla para desalocar prt_a:");
	getchar();
        munmap(ptr_a,size);
	printf("Pressiona qualquer tecla para desalocar prt_c:");
	getchar();
        munmap(ptr_c,size);
	printf("Pressione qualquer tecla para encerrar");
	getchar();
}

