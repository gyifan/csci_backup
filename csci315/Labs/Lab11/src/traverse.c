#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
#include "read_dir.h"

// function prototypes
void process(char *name);
void enqueue(char *name, que_t *q);
void dequeue(que_t *q);
void peek_front(char *name,que_t q);
bool queue_empty(que_t q);
void initq(que_t *q);

// traverse a directory tree applying a function when a file is found
void traverse(char *root)
{
				int numOfFiles = 0;
				que_t nameq;
				char dname[MAXLENGTH];
				char cname[MAXLENGTH];
				char prefix[MAXLENGTH];

				struct dirent *dp;
				DIR *dirp;

				struct stat file_info;
//				unsigned int fd;

				// stores the smallest file size
				unsigned long int size_s = 0;

				// stores the largest file size 
				unsigned long int size_l = 0;

				// stores the average file size
				unsigned long int size_avg = 0;

				// stores the number of directories
				int numOfDir = 0;

				// stores the name of the file that was most recently modified
				char mrName[MAXLENGTH];
				time_t mrTime = 0;

				// stores the name of the file that was least recently modified
				char lrName[MAXLENGTH];
				time_t lrTime = 0;

				initq(&nameq);
				enqueue(root,&nameq);

				while (true != queue_empty(nameq)) {
								peek_front(dname,nameq); 
								dequeue(&nameq);

								// Open the file or directory
/*
								fd = open(dname, O_RDONLY);
								if (-1 == fd) {
												perror("Failed to open read only file - ");
												exit(-1);
								}

								if(fstat(fd, &file_info)==0){
*/
								if(lstat(dname, &file_info)==0){
												if (S_ISDIR(file_info.st_mode)) { // it is a directory
																dirp = opendir(dname);

																numOfDir++; // Increments the number of directory

																printf("directory : %s\n",dname);
																strncpy(prefix, dname, MAXLENGTH);
																strncat(prefix,"/", MAXLENGTH);

																for (dp = readdir(dirp); NULL != dp; dp = readdir(dirp)) {
																				if ((strcmp(dp->d_name,"..") != 0) && 
																												(strcmp(dp->d_name,".") != 0)) {

																								// prevent from infinite loop
																								strncpy(cname, prefix, MAXLENGTH);

																								// concatenate the prefix
																								strncat(cname, dp->d_name, MAXLENGTH);  
																								enqueue(cname,&nameq);
																				}
																}
																closedir (dirp);
												} else if(S_ISREG(file_info.st_mode)){
																// test if it is a regular file and not a device or link -- TO-DO

																// if this is a regular file, then process it -- TO-DO
																printf(" processing file: %s\n", dname);
																numOfFiles++;

																size_avg = (size_avg*(numOfFiles-1)+file_info.st_size)/numOfFiles;

																if(size_s == 0){
																				size_s = file_info.st_size;
																				size_l = file_info.st_size;
																} else if (size_s>file_info.st_size)
																				size_s = file_info.st_size;
																else if(size_l<file_info.st_size)
																				size_l = file_info.st_size;	

																if(mrTime == 0){
																				mrTime = lrTime = file_info.st_mtime;
																				strncpy(mrName, dname, MAXLENGTH);
																				strncpy(lrName, dname, MAXLENGTH);
																} else if(mrTime < file_info.st_mtime){
																				mrTime = file_info.st_mtime;
																				strncpy(mrName, dname, MAXLENGTH);
																} else if(lrTime > file_info.st_mtime){
																				lrTime = file_info.st_mtime;
																				strncpy(lrName, dname, MAXLENGTH);
																}

												} else 
																printf("file(%s) is not a regular file\n", dname);
								} else {
												printf("stat failed");
												exit(-1);
								}
//								close(fd);
				} // while

				printf(" The file size analysis result is: \n");
				printf(" 		Smallest: %lu;	Largest: %lu;		Avergage: %lu\n", size_s, size_l, size_avg);
				printf(" Total number of directory counted were: %d\n", numOfDir);
				printf(" Total number of regular files counted were: %d\n",numOfFiles);
				printf(" Most recently modified file: %s\n", mrName);
				printf(" Least recently modified file: %s\n", lrName);

				fflush(stdout);
}


// main function
int main(int argc,char *argv[]) {

				if (2 != argc) {
								printf(" usage: %s dirpath\n", argv[0]);
								exit(-1);
				}
				else {
								// pass in the starting directory
								traverse(argv[1]);
				}

				return 0;
}
