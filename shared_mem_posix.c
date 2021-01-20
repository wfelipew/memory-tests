#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main (int argc, char* argv[]){

        char *ptr, tmp;
	char option;
	size_t size = 1024*1024*100;
	size_t count;
	int fd;


	
	fd = shm_open(argv[1],O_RDWR|O_CREAT,S_IRWXU);
	if( fd <0 ){
		printf("Falha ao abrir o arquivo\n");
		return 1;
	}
	ftruncate(fd,size);

        ptr=mmap(NULL,size,PROT_WRITE,MAP_SHARED,fd,0);
        if( ptr == MAP_FAILED ){
                printf("Falha ao realizar o mapeamento\n");
                return 1;
        }



	while(1){
		printf("Acoes:\n (1)Exibir configuração atual\n (2)Alterar a configuração\n (3)Encerrar\n");
		printf("Digite a opçao:");
		option= (char) getchar();
		while ((getchar()) != '\n');
		switch(option){
			case '1':
				printf("Configuração atual:\n");
                		printf("%s\n",ptr);
				for(count=0;count<size;count++){
                                        tmp = *(ptr+count);
                                }
				break;
			case '2':
				printf("Digite a nova configuração:\n");
                		fgets(ptr,size,stdin);
				printf("\n");
				break;
			case '3':
				printf("\nEncerrando\n");
				break;
			default :
				printf("\nInvalid Option");
		}
		if(option == '3'){
			break;
		}
	}
	


        munmap(ptr,size);
	shm_unlink(argv[1]);
}

