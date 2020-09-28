#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int hello(int n);

int main(int argc, char* argv[]){
	char  *ptr, *ptr_a, *ptr_b;
	size_t size = 1024*1024*4;
	char teste2[90] = " ########################### teste stack ############################################# ";
	int a = 7777777;

	ptr=malloc(128);
	strcpy(ptr,"-- Aqui temos a memoria heap --");

	ptr_a=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        ptr_b=mmap(0,size,PROT_WRITE|PROT_READ,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        strcpy(ptr_a,"mapeado a");
        strcpy(ptr_b,"mapeado b");

	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	free(ptr);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


