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

#ifndef _READLINE_H_
#define _READLINE_H_

/**
 * This function implements a safer way to read strings from a C stream
 * (that is, safer than scanf and gets).
 *
 * The function causes characters to be read one at a time and placed into
 * an input buffer that is automatically enlarged to fit the entire string.
 * The returned value is a pointer to a dynamically allocated area of
 * memory. Note that the caller of this function becomes responsible for
 * disposing of the memory allocated for the string read in.
 *
 * @parm stream Pointer to an open C stream (such as stdin)
 * @return A pointer to the line read from source on success or NULL on failure.
 */
extern char* 
readline(FILE* stream);

#endif /* _READLINE_H_ */
