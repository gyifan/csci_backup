#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg;
	int fd[2];
	int fd_return[2];
	int i;
	pid_t pid;

	/* create the pipe */
	if (pipe(fd) == -1){
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* create another pipe */
	if (pipe(fd_return) == -1){
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* fork a child process */
	pid = fork();

	if (pid > 0){/* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		close(fd_return[WRITE_END]);

		/* write to the pipe */
		for(i=0;i<10;i++){
			if(-1==write(fd[WRITE_END], (write_msg+i), 1)){
				perror("write failed");
				exit(-1);
			}
		}
		/* close the write end of the pipe */
		close(fd[WRITE_END]);

		while(1==read(fd_return[READ_END],&read_msg,1)){
			sleep(1);
			printf("read %c\n",read_msg);
			fflush(stdout);
		}

		close(fd_return[READ_END]);
		wait(pid);
	}else{
		close(fd[WRITE_END]);
		close(fd_return[READ_END]);
		
		i = 0; /* reset counter*/
		while(1==read(fd[READ_END],&read_msg,1)){
			sleep(1);
			printf("read %c\n",read_msg);
			fflush(stdout);
			write_msg[i] = toupper((int)read_msg);
			i ++;
		}
		close(fd[READ_END]);

		for(i=0;i<10;i++){
			if(-1==write(fd_return[WRITE_END], (write_msg+i), 1)){
				perror("write failed");
				exit(-1);
			}
		}
		close(fd_return[WRITE_END]);	

	}

	return 0;
}
