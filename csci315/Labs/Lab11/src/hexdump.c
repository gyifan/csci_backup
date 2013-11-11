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

#include <stdio.h>

char is_printable(unsigned char c) {
     if ((c >= 0x20) && (c < 0x7F))
	  return c;
     else
	  return '.';
}

void hexdump(unsigned char* buffer, unsigned int length) {
     int b=0, c=0;
     int s, rem;

     // b is a counter for the number of bytes (half the number of hex digits)

     printf("\n     PAYLOAD HEXDUMP:\n");
     while (b < length) {
	  printf("\n     %07x:", b);
	  for (; (b%16<15) && (b<length); b++) {
	       if (0 == b % 2)
		    printf(" ");
	       printf("%02hhx", buffer[b]);
	  }

	  if (b < length)
	       printf("%02hhx   ",  buffer[b++]);
	  else { // print a number of spaces to align the remaining text
	       rem = b % 16;
	       for (s=0; s < 44 - ((rem*2) + (rem/2) + 1); s++)
		    printf(" ");
	  }

	  for (;(c%16<15) && (c<length); c++) {
	       printf("%c", is_printable(buffer[c]));
	  }
	  if (c<length)
	       printf("%c", is_printable(buffer[c++]));
     }
}
