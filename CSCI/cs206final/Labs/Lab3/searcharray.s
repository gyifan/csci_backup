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
# data segment -------------------------------------
.data	 
.align 2
 
save:
.word 0,0,0,0,7,0,0,0,0,0 	# array save[.]
ivar:
.word 0 			# int i
kvar:
.word 0 			# int k
searched_value:
.word 0
failstring:
.asciiz	"value not found"
donestring:
.asciiz "loop terminated, i= "
# code segment --------------------------------------
.text
init:
	li 	$s3, 0 		# store 0 in i
	sw 	$s3, ivar
	li 	$s5, 7 		# store 7 in k
	sw 	$s5, kvar
        la 	$s4, save 	# put the address of save[0] in $s4
        			# at this point all the assumptions of (5) are valid
        			
        li	$v0, 5		# load the input from user
        syscall
        
        add 	$t0, $zero, $v0 	# $t0=input value 
        sw	$t0, searched_value
        addi	$t3, $zero, 0	# $t3=0 stores the current index in the array
        
test:
	# reserve $t1 for byte offset of save array
	add	$t1, $zero, $s3 	# $t1 = i
	sll	$t1, $t1, 2 		# multiply $t1 by 4
	add	$t1, $t1, $s4		# $t1 = &save[0] + $t1
	lw	$t2, 0($t1)		# $t2 = save[i]
	beq	$t2, $t0, success
	addi	$t3, $t3, 1
	bge	$t3, 10, fail
	addi	$s3, $s3, 1
	j	test
	 
success:
	la	$a0, donestring
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s3		# print value of i
	li	$v0, 1
	syscall
	
	j terminate
	
fail:
	la	$a0, failstring
	li	$v0, 4
	syscall
	
terminate:
	    
	li 	$v0, 10 		# terminate program
	syscall	
	
