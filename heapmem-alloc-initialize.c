#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int hello(int n);

int main(int argc, char* argv[]){
	char  *ptr, *tmp_ptr;
	ptr=malloc(1024*1024);
	tmp_ptr=ptr;
	for(int i=0;i<(1024*1024);i++){

		strcpy(tmp_ptr,"a");
		tmp_ptr+=1;
	}
	printf("Memoria alocada, pressiona qualquer tecla para desalocar\n");
	getchar();
	free(ptr);
	printf("Memoria desalocada, pressiona qualquer tecla para encerrar\n");
	getchar();
	return 0;
}


