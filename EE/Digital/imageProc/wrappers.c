/*
 * CSCI 363 Computer Networks
 * Lab 2
 * Yifan Ge
 * 01/28/2014
 * 
 * File name: wrappers.c
 *
 */

#include "wrappers.h"


int wrp_socket(int domain, int type, int protocol){
	int fd;

	if( (fd = socket(domain, type, protocol)) < 0){
		perror("open socket error");
		exit(-1);
	}
	return fd;
}

int wrp_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
	int retval;

	if( (retval = bind(sockfd, addr, addrlen)) < 0){
		perror("bind error");
		exit(-1);
	}
	return retval;
}

int wrp_listen(int sockfd, int backlog){
	int retval;
	
	if( (retval = listen(sockfd, backlog)) < 0){
		perror("listen error");
		exit(-1);
	}
	return retval;
}

int wrp_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
	int newSockfd;

	if( (newSockfd = accept(sockfd, addr, addrlen)) < 0){
		perror("accept error");
		exit(-1);
	}
	return newSockfd;
}

int wrp_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
	int retval;

	if( (retval = connect(sockfd, addr, addrlen)) < 0){
		perror("connect error");
		exit(-1);
	}
	return retval;
}

void * wrp_malloc(size_t size){
	void * ptr;
	if((ptr = malloc(size)) == NULL){
		perror("malloc failed.");
		exit(-1);
	}
	
	return ptr;
}

int wrp_gettimeofday(struct timeval *tv, struct timezone *tz){
	int retval;
	if((retval = gettimeofday(tv, tz)) < 0){
		perror("gettimeofday error.");
		exit(-1);
	}

	return retval;
}

/*
 * Copyright (c) 2012 Bucknell University
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: L. Felipe Perrone (perrone@bucknell.edu)
 */

/* Read "n" bytes from a descriptor. */

ssize_t
readn(int fd, void *vptr, size_t n)
{
        size_t  nleft;
        ssize_t nread;
        char    *ptr;

        ptr = vptr;
        nleft = n;
        while (nleft > 0) {
                if ( (nread = read(fd, ptr, nleft)) < 0) {
                        if (errno == EINTR)
                                nread = 0; /* and call read() again */
                        else
                                return(-1);
                } else if (nread == 0)
                        break; /* EOF */
                nleft -= nread;
                ptr   += nread;
        }
        return(n - nleft); /* return >= 0 */
}
/* end readn */

/* Wrapper function for readn */

ssize_t
wrp_readn(int fd, void *ptr, size_t nbytes)
{
     ssize_t            n;

     if ( (n = readn(fd, ptr, nbytes)) < 0) {
          printf("readn error\n");
          exit(-1);
     }
     return(n);
}

/*
 * Copyright (c) 2012 Bucknell University
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: L. Felipe Perrone (perrone@bucknell.edu)
 */

/* Write "n" bytes to a descriptor. */

ssize_t
writen(int fd, const void *vptr, size_t n)
{
        size_t          nleft;
        ssize_t         nwritten;
        const char      *ptr;

        ptr = vptr;
        nleft = n;
        while (nleft > 0) {
                if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
                        if (nwritten < 0 && errno == EINTR)
                                nwritten = 0;           /* and call write() again */
                        else
                                return(-1);                     /* error */
                }

                nleft -= nwritten;
                ptr   += nwritten;
        }
        return(n);
}
/* end writen */

/* Wrapper function for writen */

void
wrp_writen(int fd, void *ptr, size_t nbytes)
{
  if (writen(fd, ptr, nbytes) != nbytes) {
    printf("readn error\n");
    exit(-1);
  }
}

/* Wrapper function for open a file */
int wrp_open(const char *pathname, int flags){
	int retval;
	retval = open(pathname, flags);
	if(retval < 0){
		perror("file open error.");
		exit(-1);
	}
	return retval;
}

/* Wrapper function for fopen a file */
FILE *wrp_fopen(const char *path, const char *mode){
	FILE * retval;
	retval = fopen(path, mode);
	if(retval == NULL){
		perror("file open error.");
		exit(-1);
	}
	return retval;
}

/* Wrapper function for fgets a file */
char *wrp_fgets(char *s, int size, FILE *stream){
	char *retval;
	retval = fgets(s, size, stream);
	if(retval == NULL){
		perror("file open error.");
		exit(-1);
	}
	return retval;
}
