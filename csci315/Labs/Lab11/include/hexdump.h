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

#ifndef __HEXDUMP_H__
#define __HEXDUMP_H__

/**
 * This function prints to stdout the contents of a buffer in hexadecimal
 * and in its ASCII representation. The output is similar to what you would
 * get by running the Linux utility xxd on a file.
 *
 * @param buffer pointer to a memory buffer
 * @param length number of bytes in the buffer
 */
extern void hexdump(unsigned char* buffer, unsigned int length);

#endif /* __HEXDUMP_H__ */
