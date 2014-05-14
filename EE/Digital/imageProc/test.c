#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "bmp-utl.h"

int main(int argc, char * argv[])
{

	if(argc != 3){
		printf("USAGE: %s [input file] [output file]\n", argv[0]);
		exit(-1);
	}
	char * input = argv[1];
	char * output = argv[2];
	
	int i, j;
	int height;
	int width;

	struct pixel_t ** pixels;
	struct file_header * hdr;
	struct bitmap_header * hp;
        hdr=(struct file_header*)malloc(sizeof(struct file_header));
        hp=(struct bitmap_header*)wrp_malloc(sizeof(struct bitmap_header));

	/* Get pixels from the file */	
	if(NULL == (pixels = getPixels(input, hdr, hp))){
		exit(-1);
	}
	
	outputImage(pixels, hdr, hp, output);

	height = hp->height;
	width = hp->width;
	
	struct pixel_t * maxR = &pixels[0][0];
	struct pixel_t * maxG = &pixels[0][0];
	struct pixel_t * maxB = &pixels[0][0];
	struct list_t * pixel_list;
	pixel_list = initList();
	
	printf("height: %d, width: %d\n", height, width);

	/* get the average the of all pixels */
	int aveR;
	int aveG;
	int aveB;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			aveR += pixels[i][j].red;
			aveG += pixels[i][j].green;
			aveB += pixels[i][j].blue;
		}
	}
	aveR = aveR/(height*width);
	aveG = aveG/(height*width);
	aveB = aveB/(height*width);

	printf("aveR: %d, aveG: %d, aveB: %d\n",aveR, aveG, aveB);

	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(pixels[i][j].red > maxR->red)
				maxR = &pixels[i][j];
			if(pixels[i][j].green > maxG->green)
				maxG = &pixels[i][j];
			if(pixels[i][j].blue > maxB->blue)
				maxB = &pixels[i][j];
		}
	}

	/* go through the pixels with the threshold.
 	 *  if the pixel pass the threshold, make it white, 255 255 255.
 	 *  otherwise, make it black, 0 0 0.
 	 */
	for(i=0; i<height; i++){
		for(j=0; j<width; j++){
			if(pixels[i][j].red > 250){
				pixels[i][j].red = 255;
				pixels[i][j].green = 255;
				pixels[i][j].blue = 255;
			}else{
				pixels[i][j].red = 0;
				pixels[i][j].green = 0;
				pixels[i][j].blue = 0;
			}
				
		}
	}
	
	outputImage(pixels, hdr, hp, "processed.bmp");
	
	printf("maxR->\n");
	printPx(maxR);
	printf("maxG->\n");
	printPx(maxG);
	printf("maxB->\n");
	printPx(maxB);

	return 0;
}
