#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int hello(int n);

int main(int argc, char* argv[]){
	char  *ptr, *tmp_ptr;
	int fd;
	struct  stat st;

	ptr=malloc(1024*1024);
	if(ptr==NULL){
		printf("Falha ao alocar esta quantidade de memoria\n");
		return 1;
	}
	
	printf("Memoria alocada. Pressione qualquer tecla para preencher a memoria\n");
	getchar();

	tmp_ptr=ptr;
	for(int i=0;i<(1024*1024);i++){

		strcpy(tmp_ptr,"a");
		tmp_ptr+=1;
	}

	printf("Memoria preenchida. Pressione qualquer tecla para desalocar\n");
	getchar();
	free(ptr);

	printf("Pressione qualquer tecla mapear o arquivo %s em memoria\n",argv[1]);
	getchar();

	fd = open(argv[1],O_RDONLY);
	stat(argv[1],&st);
	posix_fadvise(fd, 0, st.st_size, POSIX_FADV_DONTNEED);

	ptr=mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,fd,0);
	close(fd);

	if( ptr == MAP_FAILED ){
		printf("Falha ao realizar o mapeamento\n");
		return 1;
	}
	
	printf("Arquivo mapeado com sucesso. Pressione qualquer tecla para percorrer os bytes do arquivo\n");
        getchar();

	int total=0;
	for( int count=0; count < st.st_size; count++ ){
		total+= ptr[count];
	}

	printf("Pressione qualquer tecla desfazer o mapeamento\n");
        getchar();

	munmap(ptr,0);
	
	return 0;
}

