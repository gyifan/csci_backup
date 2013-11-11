#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int 
main(int argc, char* argv[])
{

	int fd_out; // file descriptor for output file
	int fd_in; // file descriptor for input file

	ssize_t retval; // return value from system calls 
	unsigned char buffer; // storage for bytes read from file
	int i;
	int num_bytes;

	// modify to read number of bytes from kbd
	num_bytes = atoi(argv[2]);

	fd_in = open("/dev/random", O_RDONLY); // open random stream for reading
	fd_out = open(argv[1], O_WRONLY|O_CREAT); // open key file for writing

	for (i=0; i<num_bytes; i++) {
		retval = read(fd_in, &buffer, 1);
		retval = write(fd_out, &buffer, 1);
	}

	retval = close(fd_in); 
	retval = close(fd_out);

	return 0;
}
