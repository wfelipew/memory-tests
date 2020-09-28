#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MMAP 1
#define HEAP 2
#define STACK 3


struct position {
	size_t start;
	size_t end;
};

struct position parseMaps(char* pid, int type);

int main(int argc, char* argv[]){
        FILE *mem;
	char path[255], buff[256];
	int count=0;
	size_t startPos=0x7fa97b122000, endPos=0x7fa97b922000; 
	struct position pos;

	pos=parseMaps(argv[1],atoi(argv[2]));
	
	sprintf(path,"/proc/%s/mem",argv[1]);
        mem=fopen(path,"r");
	if(mem==NULL){
		printf("Error: Unable do load file %s\n",path);
		return 1;
	}
	fseek(mem,pos.start,SEEK_SET);
	while(pos.start<pos.end){
		fread(buff,1,1,mem);	
		printf("%s",buff);
		pos.start+=1;
		count++;
	}
	printf("\n");
	
	fclose(mem);
}


struct position parseMaps(char* pid, int type){
	char path[255], buff[512];
	FILE *maps;
	sprintf(path,"/proc/%s/maps",pid);
	size_t *start, *end;
	char *perms,*offset,*dev,*inode,*pathname;
	struct position pos;
	pos.start = 0;
	pos.end = 0;

	perms=malloc(5);
	offset=malloc(9);
	dev=malloc(6);
	inode=malloc(8);
	pathname=malloc(256);
	
	start=malloc(sizeof(size_t));
	end=malloc(sizeof(size_t));

	maps=fopen(path,"r");
	
	while(fgets(buff,512,maps)!=NULL){
		
		sscanf(buff,"%lx-%lx %s %s %s %s %s",start,end,perms,offset,dev,inode,pathname);
		switch(type){
		case MMAP:
			if(strcmp(pathname,"")==0){
				printf("Private segment found: %lx-%lx \n",*start,*end);
				pos.start=*start;
				pos.end=*end;
				free(perms);
				free(offset);
				free(dev);
				free(inode);
				free(pathname);
				return pos;
			};
		break;
		case HEAP:
                        if(strcmp(pathname,"[heap]")==0){
                                printf("Heap segment found: %lx-%lx \n",*start,*end);
                                pos.start=*start;
                                pos.end=*end;
                                free(perms);
                                free(offset);
                                free(dev);
                                free(inode);
                                free(pathname);
                                return pos;
                        };
		break;
		case STACK:
                        if(strcmp(pathname,"[stack]")==0){
                                printf("Stack segment found: %lx-%lx \n",*start,*end);
                                pos.start=*start;
                                pos.end=*end;
                                free(perms);
                                free(offset);
                                free(dev);
                                free(inode);
                                free(pathname);
                                return pos;
                        };

		break;
		}
		strcpy(pathname,"");
	}
	
	return pos;
	

}

