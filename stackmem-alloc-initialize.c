#include <stdio.h>
#include <stdlib.h>

int hello(int n);

int main(int argc, char* argv[]){
	int teste =1000;
	char big[1024*1000];
	if(argc<=1){
		printf("Usage:\n ./stackmem-alloc.o <recursion number>\n\n");
		return 1;
	}
	int recursion = atoi(argv[1]);
	hello(recursion);
	getchar();
	return 0;
}


int hello(int number){
	char big[1000*1024]="";
	printf("Recursion  %d\n",number);
	if(number==0){
		printf("->Recursion  %d\n",number);
		getchar();
		return number;
	}
	return hello(number-1);
}
