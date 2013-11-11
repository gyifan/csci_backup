# CSCI 206 Computer Organization & Programming
# Date: 2011-09-19
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
# Student name: Yifan Ge
#
#
# This simple program demonstrates writing very simple leaf procedures.
# The program computes an expression in the form of "4x - (2y + c)".
# You are to call the procedure "myFunc", taking two parameters (x and y) and
# produce "4x - (2y + c)" within the procedure.

	.data
# Define the constant c here
C:	.word	1
printstring:
	.asciiz "4x - (2y + C) = "
enter:
	.asciiz "\n"

	.text

main:
	# Call myFunc(2, 3)
	addi	$a0, $zero, 2
	addi	$a1, $zero, 3
	jal	myFunc
	add	$s0, $zero, $v0		# save result in $s0

	# Call myFunc(5, 6)
	addi	$a0, $zero, 5
	addi	$a1, $zero, 6
	jal	myFunc
	add	$s1, $zero, $v0     # save result in $s1

    add $s1, $s1, $s0

    #
    # add code here to print the result of myFunc(2,3)+myFunc(5,6)
    #

	addi	$v0, $zero, 10				# system call for exit
	syscall

# myFunc = 4x - (2y + 1)
myFunc:
    	sll	$t0, $a1, 1		# calculate 2y
    	lw	$t2, C			# load C value
    	
    	add 	$t0, $t0, $t2		# calculate 2y + C
    	sll	$t1, $a0, 2		# calculate 4x
    	
    	nor	$t0, $t0, $zero		# get -(2y + C)
    	addi	$t0, $t0, 1
    	
    	add	$t3, $t0, $t1		# calculate 4x - (2y + C)
    	
    	la	$a0, printstring	# print the answer
    	li	$v0, 4
    	syscall
    	
    	add	$a0, $zero, $t3
    	li	$v0, 1
    	syscall
    	
    	la	$a0, enter
    	li	$v0, 4
    	syscall
    	
    	add	$v0, $zero, $v1		# return the answer
    	
	jr $ra
	
# First time: $ra == 0x0040000c. This address corespond to add $s0, $zero, 5 (line 45)
# Second time: $ra == 0x0040001c. This address corespond to add $s1, $zero, $v0 (line 51)
