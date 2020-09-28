#include <stdio.h>
#include <stdlib.h>

int hello(int n);

int main(int argc, char* argv[]){
	char  *ptr;
	ptr=malloc(1024*1024);
	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	free(ptr);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


