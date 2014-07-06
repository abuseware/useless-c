#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char* bytecode;
	FILE* pf;
	int fsiz;
	
	puts("Bytecode loader by thc_flow");
	
	pf = fopen(argv[1],"rb");
	if(pf != NULL){
		fseek(pf,0,SEEK_END);
		fsiz=ftell(pf);
		rewind(pf);
		bytecode = (char*) malloc(sizeof(char)*fsiz);
		if(bytecode != NULL){
			fread(bytecode,1,fsiz,pf);
			(*(void(*)(void)) bytecode)();
		} else return 1;
		free(bytecode);
	} else return 1;
	fclose(pf);
	
	return 0;
}

