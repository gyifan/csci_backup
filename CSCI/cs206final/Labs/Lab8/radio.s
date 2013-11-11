# CSCI 206 Computer Organization & Programming
# Lab 8 from Prof. Perrone
# Date: 2011-10-25
# Author: Yifan Ge

	.data
	.align 2
space:	
	.asciiz " "
nl:	
	.asciiz "\n"
directory:
	.word # 1st 4 chars of name for directory[0]
 	.word # 2nd 4 chars of name
 	.word # 3rd 4 chars of name
 	.float
 	.word # 1st 4 chars of name for directory[1]
 	.word # 2nd 4 chars of name
 	.word # 3rd 4 chars of name
 	.float
 	.word # 1st 4 chars of name for directory[2]
 	.word # 2nd 4 chars of name
 	.word # 3rd 4 chars of name
 	.float
 	.word # 1st 4 chars of name for directory[3]
 	.word # 2nd 4 chars of name
 	.word # 3rd 4 chars of name
 	.float
 	.word # 1st 4 chars of name for directory[4]
 	.word # 2nd 4 chars of name
 	.word # 3rd 4 chars of name
 	.float
 	
	.text
main:
	la	$s0, directory		# load base address in $s0
	li	$s1, 16			# length of each element in $s1
	li	$s2, 0			# index of the element in $s2
	
input_loop:
	bgt	$s2, 4, print

	multu	$s2, $s1		# calculate the base address of the string and store $t1
	mflo	$t1			
	add	$t1, $t1, $s0
	
	add	$a0, $t1, $zero		# read the string input with base address in $a0 and length in $a1
	addi	$a1, $zero, 12
	li	$v0, 8
	syscall
	
	jal	strip_line_feed
	
	multu	$s2, $s1		# calculate the address of the frequency and store $t1
	mflo	$t1
	addi	$t1, $t1, 12
	add	$t1, $t1, $s0
	
	li	$v0, 6
	syscall				# read the frequency input
	swc1	$f0, 0($t1)		
	
	addi	$s2, $s2, 1		# increment the counter
	
	j	input_loop
	
print:
	li	$s2, 0			# reset the counter
print_loop:
	bgt	$s2, 4, exit
	
	multu	$s2, $s1		# calculate the base address of the string and store $t1
	mflo	$t1			
	add	$t1, $t1, $s0
	
	li	$v0, 4			# print the name string
	add	$a0, $t1, $zero
	syscall
	
	la	$a0, space
	li	$v0, 4
	syscall
	
	multu	$s2, $s1		# calculate the address of the frequency and store $t1
	mflo	$t1
	addi	$t1, $t1, 12
	add	$t1, $t1, $s0
	
	li	$v0, 2
	lwc1	$f12, 0($t1)
	syscall
	
	la	$a0, nl
	li	$v0, 4
	syscall
	
	addi	$s2, $s2, 1		# increment the counter
	
	j	print_loop
	
exit:
	li	$v0, 10
	syscall

strip_line_feed:
	add	$t0, $zero, $a0		# get the base address
	addi	$t1, $a0, 12		# set the end address
	li	$t2, 10			# store the ascii code value for the line feed in $t2
strip_line_feed_loop:
	bgt	$t0, $t1, strip_end	# set the line feed character to 0 (end loop if all char is check OR nl is reset)
	lb	$t3, 0($t0)
	beq	$t3, $t2, strip_nl
	addi	$t0, $t0, 1
	j	strip_line_feed_loop
strip_nl:
	sb	$zero, 0($t0)
strip_end:
	jr	$ra
	
	
