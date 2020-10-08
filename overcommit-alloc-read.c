#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	char  *ptr, *tmp_ptr;
	unsigned long i;
	char str[50];
	if(argc < 2){
		printf("Usage: <Size allocation (megabytes)>");
	}
	int megabytes = atoi(argv[1]);
	ptr=malloc(1024*1024* (unsigned long) megabytes);

	if(ptr==NULL){
                printf("Falha ao alocar esta quantidade de memoria\n");
                return 1;
        }
	tmp_ptr=ptr;
	for(i=0;i<1024*1024* (unsigned long) megabytes; i++){
                strcpy(tmp_ptr,"a");
		tmp_ptr++;
	}

	printf("Memoria alocada, pressiona qualquer tecla para iniciar a leitura\n");
	getchar();


	tmp_ptr=ptr;
        for(i=0;i<1024*1024* (unsigned long) megabytes; i++){
                sprintf(str,"Aqui: %c",*tmp_ptr);
                tmp_ptr++;
        }





	free(ptr);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


