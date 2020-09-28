#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int hello(int n);

int main(int argc, char* argv[]){
	char  *ptr;
	printf("Pressione qualquer tecla para alocar\n");
	getchar();
	ptr=sbrk(1024*1024);
	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	sbrk(-(1024*1024));
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


