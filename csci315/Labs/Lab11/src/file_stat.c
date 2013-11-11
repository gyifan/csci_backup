/*
 * CSCI 315 Operating Systems Design
 * Original developed by CSCI 315 staff
 * Modified by: L. Felipe Perrone
 * Date: 2011-4-21
 * Copyright (c) 2011 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual or
 * institution obtaining a copy of this software and associated
 * documentation files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright and
 * permission notice is maintained, intact, in all copies and supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

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

int main(int argc, char *argv[]) {

  // pointer to file name string
  char *name;

  // allocate tm structure to store retrieved time
  struct tm time;

  // allocate space to hold a string with retrieved time (ASCII text)
  char asctime_str[35];

  // container for complete set of file permission bits (binary)
  unsigned int mode;

  // container for the three bits of user permissions
  unsigned int umode;

  // container for the three bits of group permissions
  unsigned int gmode;

  // container for the three bits of owner permission
  unsigned int omode;

  // human readable file permissions (ASCII text)
  char perm_bits_str[] = "---------";

  // file descriptor 
  unsigned int fd;

  // structure to contain the result of the fstat call (info on this file)
  struct stat file_info;

  // structure to contain the result of the vfstat call (info on file system)
  struct statvfs fs_info;
  
  // used to save the return value of realpath
  char resolved_path[PATH_MAX];
  char* ret_path;
 
  // structure to contain user information
  struct passwd *usr;

  // structure to contain group information
  struct group *group;
 
  // check number of arguments for appropriate usage
  if (2 != argc) {
    printf(" usage: %s [file_name]\n", argv[0]);
    exit(-11);
  }

  // post-condition: argv[1] contains name of file to use
  
  // try to open file
  fd = open(argv[1], O_RDONLY);
  if (-1 == fd) {
    perror("Failed to open read only file - ");
    exit(-1);
  }
  
  // use fstatvfs to learn details about the file system
  if (fstatvfs(fd, &fs_info) == 0) {
      printf("== FILE SYSTEM INFO ============================\n");
      printf(" file system fstatvfs() call successful\n");
      printf(" file system block size: %lu\n", fs_info.f_bsize); // TO-DO
      printf(" max. file name length: %lu\n", fs_info.f_namemax); // TO-DO
  } else {
    printf("%s: File system fstatvfs call failed\n", argv[0]);
    exit(-1);
  }

  // post-condition: maximum length of file name string is known

  // use calloc to allocate space for file name string
  name = calloc(fs_info.f_namemax, 1);

  if (NULL == name) {
    perror("Problem in calloc - ");
    exit(-1);
  }

  // copy file name into name variable using secure version of string copy
  strncpy(name, argv[1], 500);
   
  // use fstat to get information on specific file
  if (fstat(fd, &file_info) == 0) {
    printf("\n== FILE INFO ============================\n");
    printf(" file fstat() call successful\n");
    
    // mode comes from the lower 9 bits in file_info.st_mode
    mode = file_info.st_mode & 0x1FF;
    
    printf(" file protection bits = 0%o\n", mode);
    
    // umode comes from the high 3 bits in mode
    umode = mode & 0x1C0; // TO-DO
    umode = umode >> 6;
    
    // gmode comes from the middle 3 bits in mode
    gmode = mode & 0x38; // TO-DO
    gmode = gmode >> 3;
    
    // omode comes from the low 3 bits in mode
    omode = mode & 0x7; // TO-DO
      
    // once you have set umode, gmode, and omode, the code below
    // will construct the right string for you and display it

    // construct string with file protection information
    if (umode & 0x4) perm_bits_str[0] = 'r';
    if (umode & 0x2) perm_bits_str[1] = 'w';
    if (umode & 0x1) perm_bits_str[2] = 'x';
    
    if (gmode & 0x4) perm_bits_str[3] = 'r';
    if (gmode & 0x2) perm_bits_str[4] = 'w';
    if (gmode & 0x1) perm_bits_str[5] = 'x';
    
    if (omode & 0x4) perm_bits_str[6] = 'r';
    if (omode & 0x2) perm_bits_str[7] = 'w';
    if (omode & 0x1) perm_bits_str[8] = 'x';
    
    printf(" file protection string = %s\n", perm_bits_str);
    
    printf(" file protection mode (u:g:o) = %o:%o:%o\n",
	   umode, gmode, omode);
    
    // gets user and group information
    if(NULL == (usr=getpwuid(file_info.st_uid))){
      perror("getpwuid failed");
      exit(-1);
    }

    if(NULL == (group=getgrgid(file_info.st_gid))){
      perror("getgrgid failed");
      exit(-1);
    }

    printf(" owner user name = %s\n", usr->pw_name); // TO-DO: man getpwuid 
    printf(" owner group name = %s\n", group->gr_name); // TO-DO: man getgrgid 
    
		// TO-DO: print "mode = x", where x may be:
		// "regular file"
		// "directory"
		// "character device"
		// "block device"
		// "symbolic link"
		// "socket"
		// "fifo"
		// "unknown"

    if (S_ISREG(file_info.st_mode)) { 
      printf(" mode = regular file\n");
    } else if(S_ISDIR(file_info.st_mode)){ // see TO-DO above
      printf(" mode = directory\n");
    } else if(S_ISCHR(file_info.st_mode)){ // see TO-DO above
      printf(" mode = character device\n");
    } else if(S_ISBLK(file_info.st_mode)){ // see TO-DO above
      printf(" mode = block device\n");
    } else if(S_ISLNK(file_info.st_mode)){ // see TO-DO above
      printf(" mode = symbolic link\n");
    } else if(S_ISSOCK(file_info.st_mode)){ // see TO-DO above
      printf(" mode = socket\n");
    } else if(S_ISFIFO(file_info.st_mode)){ // see TO-DO above
      printf(" mode = fifo\n");
    } else printf(" mode = unknown\n");
       
    ret_path = realpath(name, resolved_path);
    if (NULL != ret_path) 
      printf(" absolute path = %s\n", ret_path);
    else {
      perror(" couldn't resolve path");
      exit(-1);
    }
        
    // fill in the time the last write was made to file
    localtime_r(&(file_info.st_mtime), &time);      
    asctime_r(&time, asctime_str);
    printf(" time of last modification: %s", asctime_str);
   
    // fill in the time the last access was made to file
    localtime_r(&(file_info.st_atime), &time);      
    asctime_r(&time, asctime_str);
    printf(" time of last access: %s", asctime_str);
    
    // fill in the time the last status change was made to file
    localtime_r(&(file_info.st_ctime), &time);      
    asctime_r(&time, asctime_str);
    printf(" time of last status change: %s\n", asctime_str);
    
    fflush(stdout);
    close(fd);
    exit(0);
  }
  else
    printf(" fstat call failed\n");

  return 0;
}
