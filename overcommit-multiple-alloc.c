#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char  *ptr1,*ptr2;
	if(argc < 2){
		printf("Usage: <Size allocation (megabytes)>");
	}
	int megabytes = atoi(argv[1]);
	ptr1=malloc(1024*1024* (unsigned long) megabytes);

	if(ptr1==NULL){
                printf("Falha ao realizar a primeira alocação\n");
                return 1;
        }

	ptr2=malloc(1024*1024* (unsigned long) megabytes);
	if(ptr2==NULL){
                printf("Falha ao realizar a segunda alocação\n");
                return 1;
        }


	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	free(ptr1);
	free(ptr2);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


