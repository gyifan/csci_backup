#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>

#include "wrappers.h"

/* Windows 3.x bitmap file header */
struct file_header{
	unsigned short filetype;   /* magic - always 'B' 'M' */
	unsigned int   filesize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int   dataoffset;    /* offset in bytes to actual bitmap data */
};

/* Windows 3.x bitmap full header, including file header */
struct bitmap_header{
	unsigned int   headersize;
	int            width;
	int            height;
	unsigned short planes;
	unsigned short bitsperpixel;  /* we only support the value 24 here */
	unsigned int   compression;   /* we do not support compression */
	unsigned int   bitmapsize;
	int            horizontalres;
	int            verticalres;
	unsigned int   numcolors;
	unsigned int   importantcolors;
};

/* pixel struct with RGB */
struct pixel_t {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	int x;
	int y;
};

/* read in pixels from a bmp file, return a 2D pixel-array */
struct pixel_t ** getPixels(char * input, struct file_header * hdr, struct bitmap_header * hp);

/* output the pixels to a bmp file */
int outputImage(struct pixel_t ** pixels, struct file_header * hdr , struct bitmap_header * hp, char * output);

struct pixel_t * initPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
int printPx(struct pixel_t * px);

