/*
 * CSCI 315 Operating Systems Design
 * Author: L. Felipe Perrone
 * Date: 2010-02-16
 * Copyright (c) 2011 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual
 * or institution obtaining a copy of this software and associated
 * documentation files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright
 * and permission notice is maintained, intact, in all copies and
 * supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE     512 // length of message buffer    
#define	QLEN		        6   // length of request queue

#define FOREVER         1

#define TRUE 1
#define FALSE 0

int	num_requests = 0;  // tally of client requests

/*------------------------------------------------------------------------
 * Program:   echod - a server for echo requests
 *
 * Purpose:   repeatedly execute the following:
 *    (0) wait for a connection request from client
 *		(1) wait for a null-terminated string from client
 *		(2) send back the same string to client 
 *		(3) close the connection
 *		(4) go back to step (0)
 *
 * Usage:    echod [ port ]
 *
 *		 port  - a port number in user space
 *
 *------------------------------------------------------------------------
 */

void removespace(char *string){
	int i=0, y=0;
	int leading=0;
	
	for(i=0,y=0;string[i]!='\0';i++,y++){
		string[y]=string[i];
		if(isspace(string[i])){
			if(isspace(string[i+1])||string[i+1]=='\0'||leading!=1)
				y--;
		} else leading = 1;
	}
	string[y]='\0';
}
	

int main (int argc, char* argv[]) {

	struct sockaddr_in sad;  // structure to hold server's address	
	struct sockaddr_in cad;  // structure to hold client's address	
	int sd, sd2;	           // socket descriptors			
	int port;		             // protocol port number		
	socklen_t alen;	         // length of address			
	char in_msg[BUFFER_SIZE];  // buffer for incoming message
	unsigned int in_index;   // index to incoming message buffer
	
	int ret_val;
	
	// prepare address data structure

	memset((char *)&sad,0,sizeof(sad)); // zero out sockaddr structure	
	sad.sin_family = AF_INET;	          // set family to Internet	        
	sad.sin_addr.s_addr = INADDR_ANY;   // set the local IP address	

	// verify usage

	if (argc > 1) {			
		port = atoi(argv[1]);	        
	}
	else {
		printf("Usage: %s [ port ]\n", argv[0]);
		exit(-1);
	}

	if (port > 0)	
		// test for illegal value	
		sad.sin_port = htons((u_short)port);
	else {				
		// print error message and exit	
		fprintf(stderr,"ECHOD: bad port number %s\n", argv[1]);
		exit(-1);
	}

	// create socket 

	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sd < 0) {
		perror("ECHOD: socket creation failed");
		exit(-1);
	}

	// assign IP/port number to socket where connections come in 

	if (bind(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
		perror("ECHOD: bind failed");
		exit(-1);
	}

	// set up socket to receive incomming connections 

	if (listen(sd, QLEN) < 0) {
		perror("ECHOD: listen failed");
		exit(-1);
	}

	// main server loop - accept and handle requests 

	while (FOREVER) {
		alen = sizeof(cad);

		if ( (sd2 = accept(sd, (struct sockaddr *)&cad, &alen)) < 0) {
			perror("ECHOD: accept failed\n");
			exit(-1);
		}

		num_requests++;

		// receive the string sent by client
		
        	if(0>(ret_val=recv(sd2, in_msg, BUFFER_SIZE, 0))){
               		perror("ECHOD: recv failed");
        	        exit(-1);
 	       	}
		printf("ECHOD: %d bytes received.\n", ret_val);
		
		// send the received string back to client
		
		removespace(in_msg);
		
		if(0>(ret_val=send(sd2, in_msg, BUFFER_SIZE,0))){
                	perror("ECHOD: send failed");
        	        exit(-1);
	        }
		printf("ECHOD: %d bytes sent.\n", ret_val);

		
		close(sd2);
	}
}
