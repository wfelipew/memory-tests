#include <stdio.h>
#include <sys/mman.h>
#include <string.h>



int main (int argc, char* argv[]){

	char *ptr_a, *ptr_b, *ptr_c;	
        size_t size = 1024*1024*4;
        
	printf("Pressione qualquer tecla para alocar memoria anonima:"); 
	getchar();
        ptr_a=mmap(0,size,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	getchar();
        ptr_b=mmap(0,size,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	getchar();
        ptr_c=mmap(0,size*2,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	printf("Pressiona qualquer tecla para desalocar memoria anonima");
	getchar();
        munmap(ptr_b,size);
	getchar();
        munmap(ptr_c,size*2);
	getchar();
        munmap(ptr_a,size);
	printf("Pressione qualquer tecla para encerrar");
	getchar();
}

