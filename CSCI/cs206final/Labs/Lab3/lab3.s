# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
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
#
# This program calculates the sum of the values in array A and counts
# the number of values in the array.
#
# Similarly to a C-string, the array is terminated by sentinel value
# equal to zero.
#
# The sum is stored in $s0 and the count in $s1

	.data
A:	.word 5 4 3 2 4 1 0	# declare array int A[]={5,4,3,2,4,1,0};
endelement:
	.asciiz "Number of elements = "
endsummation:
	.asciiz "Summation = "
enter:
	.asciiz "\n"

	.text	
main:				# This symbols marks the first instruction of your program

init:
	li 	$s1, 0 		# reserve $s1 for element counter
	move 	$t1, $zero	# $t1 = 0 for the relative base of the element
	li 	$s2, 0		# reserve $s2 for the value of the element
	li 	$s3, 0		# reserve $s3 for the summation and set initial value to 0
	
test:
	lw 	$s2, A($t1)		# load the element to $s2
	beq 	$s2, 0, terminate	# check if it's the end of the array
	add 	$s3, $s3, $s2		# add the sum
	addi 	$s1, $s1, 1		# increase the element counter
	addi 	$t1, $t1, 4		# increase the relative base
	j 	test
	
terminate:
	la 	$a0, endelement		# print the string "Number of elements = "
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s1		# output the number of elemetns
	li	$v0, 1
	syscall
	
	la	$a0, enter		# next line
	li	$v0, 4
	syscall
	
	la 	$a0, endsummation	# print the string "Summation = "
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s3		# output the summation
	li	$v0, 1
	syscall
	
	li	$v0, 10		# system call for exit
	syscall			# Exit!

