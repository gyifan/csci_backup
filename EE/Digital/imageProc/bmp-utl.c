#include "bmp-utl.h"

struct pixel_t ** getPixels(char* input, struct file_header * hdr, struct bitmap_header * hp) {

	// Pixel table
	struct pixel_t ** pixels;

	//variable dec:
	FILE *fp;
	int n;
	int row, col;

	//Open input file:
	fp = fopen(input, "r");
	if(fp==NULL){ // Can't open input file
		printf("Fail to open input %s\n", input);
		return NULL;
	}

	//Read the input file headers:
	fread(&hdr->filetype, sizeof(unsigned short), 1, fp);
	fread(&hdr->filesize, sizeof(unsigned int), 1, fp);
	fread(&hdr->reserved1, sizeof(unsigned short), 1, fp);
	fread(&hdr->reserved2, sizeof(unsigned short), 1, fp);
	fread(&hdr->dataoffset, sizeof(unsigned int), 1, fp);

	n=fread(hp, sizeof(struct bitmap_header), 1, fp);
	if(n<1){ // Can't read header
		printf("Fail to read header\n");
		return NULL;
	}

	//Prints the general information
	printf("hp->bitmapsize: %d\n", hp->bitmapsize);
	printf("compression: %d\n", hp->compression);
	printf("bitsperpicxel: %d\n", hp->bitsperpixel);
	printf("filetype: %02x\n", hdr->filetype);
	printf("file size: %d\n", hdr->filesize);

	//Read the pixels of the image:
	fseek(fp,sizeof(char)*hdr->dataoffset,SEEK_SET);
	pixels = (struct pixel_t **)wrp_malloc(hp->height*sizeof(struct pixel_t *));
	for(row = 0; row < hp->height; row++){
		pixels[row] = (struct pixel_t *)wrp_malloc(hp->width * sizeof(struct pixel_t));
		for(col = 0; col < hp->width; col++){
			fread(&pixels[row][col].red, 1, 1, fp);
			fread(&pixels[row][col].green, 1, 1, fp);
			fread(&pixels[row][col].blue, 1, 1, fp);
			pixels[row][col].x = col;
			pixels[row][col].y = row;
		}
	}	

	//Clean up
	fclose(fp);
	return pixels;
}

int outputImage(struct pixel_t ** pixels, struct file_header * hdr , struct bitmap_header * hp, char * output)
{
	FILE * out;
	int row, col;
	
	//Open output file:
	out = fopen(output, "w");
	if(out==NULL){ // Can't open output file
		printf("Fail to open output %s\n", output);
		return 1;
	}

	//Write output file headers
	fwrite(&hdr->filetype, sizeof(unsigned short), 1, out);
	fwrite(&hdr->filesize, sizeof(unsigned int), 1, out);
	fwrite(&hdr->reserved1, sizeof(unsigned short), 1, out);
	fwrite(&hdr->reserved2, sizeof(unsigned short), 1, out);
	fwrite(&hdr->dataoffset, sizeof(unsigned int), 1, out);

	fwrite(hp, sizeof(struct bitmap_header), 1, out);

	//Write output file pixels
	fseek(out,sizeof(char)*hdr->dataoffset,SEEK_SET);
	for(row = 0; row < hp->height; row++){
		for(col = 0; col < hp->width; col++){
			fwrite(&pixels[row][col].red, 1, 1, out);
			fwrite(&pixels[row][col].green, 1, 1, out);
			fwrite(&pixels[row][col].blue, 1, 1, out);
		}
	}	
	
	fclose(out);
	return 0;
}

struct pixel_t * initPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	struct pixel_t * pt;
	pt = (struct pixel_t *)wrp_malloc(sizeof(struct pixel_t));
	pt->red = r;
	pt->green = g;
	pt->blue = b;
	pt->x = x;
	pt->y = y;
	
	return pt;
}

int printPx(struct pixel_t * px)
{
	printf("x:%d, y:%d, r:%d, g:%d, b:%d\n", px->x, px->y, px->red, px->green, px->blue);
	return 0;
}
