#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "hexdump.h"

int main(int argc, char *argv[]){
	
	char *fn;
	unsigned int offset;
	unsigned int size;
	FILE *fd;
	unsigned char *buffer;

	if(argc!=4){
		printf("USAGE: fdump filename offset size\n");
		exit(-1);
	}else{
		fn = argv[1];
		offset = atoi(argv[2]);
		size = atoi(argv[3]);
	}

	if(NULL==(fd=fopen(fn, "r"))){
		perror("fopen failed");
		exit(-1);
	}

	if(fseek(fd, offset, SEEK_SET)){
		perror("fseek failed");
		exit(-1);
	}
	
	buffer = malloc(size);
	if(1!=fread(buffer, size, 1, fd)){
		perror("fread failed");
		exit(-1);
	}
	
	hexdump(buffer, size);
	
	fclose(fd);
		
	return 0;
}
