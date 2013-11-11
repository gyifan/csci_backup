#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int fd_out;
	int fd_in;
	int fd_key;

	ssize_t retval;
	unsigned char buffer;
	unsigned char key;	
	unsigned char result;

	fd_key = open(argv[1], O_RDONLY);
	fd_in = open(argv[2],O_RDWR|O_CREAT);
	fd_out = open(argv[3],O_RDWR|O_CREAT);

	do {
		retval = read(fd_in, &buffer, 1);
		if (retval > 0){
			retval = read(fd_key, &key, 1);
			result = buffer^key;
			retval = write(fd_out, &result, 1);
		}
	} while (retval > 0);

	retval = close(fd_in);
	retval = close(fd_out);
	retval = close(fd_key);
	
	return 0;
}	
