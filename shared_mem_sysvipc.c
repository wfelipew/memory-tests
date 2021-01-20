#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>



int main (int argc, char* argv[]){

        char *ptr, tmp;
	char option;
	int shm_id;
	size_t size = 1024*1024*100;
	size_t count;


	shm_id=shmget(334,size,IPC_CREAT|0666);

        if( shm_id < 0 ){
                printf("Falha alocacao de memoria \n");
                return 1;
        }
	
	ptr = shmat(shm_id,NULL,0);
        if( (void *) ptr < 0 ){
                printf("Falha em atachar memoria compartilhada \n");
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
                		fgets(ptr,size-1024,stdin);
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
	


	shmdt(ptr);
	shmctl(shm_id,IPC_RMID,NULL);
}

