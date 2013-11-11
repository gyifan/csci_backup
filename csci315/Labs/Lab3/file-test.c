#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
#define FILE_PATH "data.txt"

int main(void){
        char write_msg = '0';
        char read_msg[BUFFER_SIZE];
        int fd;
	int i;	

        /* open the file */
        if (-1==(fd=open(FILE_PATH,O_CREAT|O_WRONLY,S_IRWXU))){
                fprintf(stderr,"Open failed");
                return 1;
        }

        for(i=0;i<10;i++){
		if(-1==(write(fd,&write_msg,1))){
			fprintf(stderr,"Write Failed");
			return 1;
		}
		write_msg++;
	}

        return 0;
}
