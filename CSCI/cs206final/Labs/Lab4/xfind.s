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
# This program uses a procedure xfind to find a particular character.
# See detailed instructions in lab handout

	.data
# Define constants here

	.align 2

# These are the two test strings, use one at a time
string: .asciiz "Where is my xbox 360?"
#string: .asciiz "None of that character in herei."
x:	.asciiz "x"

	.text

main:
	# Prepare for procedure call
	addi	$sp, $sp, -4		# saving registers
	sw	$ra, 0($sp)
	
	la	$a0, string		# load address of string
	jal	xfind			# call function convert

	add	$a0, $zero, $v0		# print the answer
	li	$v0, 34
	syscall

	lw	$ra, 0($sp)		# restoring registers
	addi	$sp, $sp, 4
	
	li	$v0, 10			# exit to OS
	syscall

xfind:
	add	$t0, $a0, $zero		# copy the base address of string
	lb	$t1, x			# load the x code
loop:
	lb	$t2, 0($t0)		# load the char for checking
	beq	$t2, $t1, success	# check if the char is x
	addi	$t0, $t0, 1		# load the address of the next char
	lb	$t2, 0($t0)
	beq	$t2, $zero, fail	# check if it's the end of the string
	j	loop			# check the next char
success:
	add	$v0, $zero, $t0		# return the address of x
	jr	$ra
fail:	
	addi	$v0, $zero, -1		# return -1
	jr	$ra
