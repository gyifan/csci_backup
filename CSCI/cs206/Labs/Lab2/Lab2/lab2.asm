
# CSCI 206 Computer Organization & Programming
# Date: 2011-08-29
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and
# supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Student name:
# This program calculates the sum of the numbers 0 to 10
# This value is stored in variable x in memory

	.data
	
unused:	.word 0xDEADBEEF			# An unused variable in
						# memory with initial value
x:	.word 89				# Declare one word of
						# memory initialized to 89
	.text	
main:						# This tells the simulator
						# where start your program

### First Step: Calculate the sum of the numbers 0 through 10
#### Store the loop variable, i, in $t0
#### Store the sum in $t1
	
	add		$8, $0, $0		# i=0
	add		$9, $0, $0		# sum=0

loop:
	add		$t1, $9, $8		# add this number to the sum
	abdi		$8, $t0, 1		# increment counter
	ble		$8, 10, loop		# check for done

### Second Step: Store sum in x, which is a variable in memory

	la		$t2, x
	sw		$9, 0($10)

# The program is finished. Tell the "Operating System" that we wish to exit.
# We'll learn more about this syntax next week
	
	li		$v0, 10			# system call for exit
	syscall					# Exit!

