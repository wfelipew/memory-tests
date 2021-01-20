#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>



int main (int argc, char* argv[]){

        char *ptr,tmp;
	char option;
	size_t size = 1024*1024*100;
	size_t count;
	int pid;


        ptr=mmap(NULL,size,PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
        if( ptr == MAP_FAILED ){
                printf("Falha ao realizar o mapeamento\n");
                return 1;
        }

	pid=fork();
	if(pid>0){

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
					kill(pid,SIGTERM);
					break;
				default :
					printf("\nInvalid Option");
			}
			if(option == '3'){
				break;
			}
		}
	}else if(pid==0){
		FILE* log;
		log = fopen("/tmp/memory.log", "w+"); 
		
		if(log==NULL){
			printf("Falha ao abrir arquivo de log\n");
			return 1;
		}  
	        
	        fprintf(log,"Iniciando Logger\n");
		fflush(log);

		while(1){
			sleep(5);
			fprintf(log,"%s\n",ptr);
			fflush(log);
		}
		fclose(log);
	}else{
		printf("Falha ao criar processo\n");
		return 1;
	}


        munmap(ptr,size);
}

