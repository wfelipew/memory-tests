#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char  *ptr;
	if(argc < 2){
		printf("Usage: <Size allocation (megabytes)>");
	}
	int megabytes = atoi(argv[1]);
	ptr=malloc(1024*1024* (unsigned long) megabytes);

	if(ptr==NULL){
                printf("Falha ao alocar esta quantidade de memoria\n");
                return 1;
        }

	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	free(ptr);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


