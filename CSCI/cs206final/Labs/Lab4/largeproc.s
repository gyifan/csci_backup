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
# This program demonstrates passing a large number of arguments to a
# procedure which is not a leaf procedure.

	.data
A:	.word 3
B:	.word 7
C:	.word 4
D:	.word 9
E:	.word 3
F:	.word 8
Result1:.word 0xDEADBEEF
Result2:.word 0xDEADBEEF
enter:	.asciiz "\n"

	.text

# The main() procedure calls largeProc, storing the results into
# Result1 and Result2 and also printing them out to the terminal.

main:

	# Prepare arguments to pass to largeProc
	addi	$sp, $sp, -4	# saving registers
	sw	$ra, 0($sp)
	
	lw	$a0, A		# load A,B,C,D,E,F values to saved registers
	lw	$a1, B
	lw	$a2, C
	lw	$a3, D
	
	lw	$t0, E		# load E,F to temp registers
	lw	$t1, F
	
	addi	$sp, $sp, -4	#save E to the stack
	sw	$t0, 0($sp)
	
	addi	$sp, $sp, -4	#save F to the stack
	sw	$t1, 0($sp)

	# Call largeProc
	jal	largeProc

	# Print the results returned from largeProc
	sw	$v0, Result1
	sw	$v1, Result2
	
	lw	$a0, Result1
	addi	$v0, $zero, 1
	syscall
	
	addi	$a0, $zero, 0x1001
	sll	$a0, $a0, 16
	or	$a0, $a0, 0x0020
	addi	$v0, $zero, 4
	syscall
	
	
	lw	$a0, Result2
	addi	$v0, $zero, 1
	syscall
	
	# Restore saved registers
	addi	$sp, $sp, 8
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4

# The program is finished. Terminate the execution.
	addi	$v0, $zero, 10		# system call for exit
	syscall

# This large complicated procedure takes 6 paramters and returns 2.
# Additionally this procedure calls another procedure.
# It is assumed that $fp has been set correctly

largeProc:
	
	# Store registers which must be saved onto the stack
	add	$fp, $sp, $zero		# relocate the frame pointer for this procedure
	
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	lw	$t0, 4($fp)		# load E
	lw	$t1, 0($fp)		# load F
	
	# Compute the first result
	add	$v0, $a1, $a2		# calculate B + C + E and store in $v0
	add	$v0, $v0, $t0

	# Compute the second result
	sub	$v1, $a2, $a3		# calculate C - D + F and store in $v1
	add	$v1, $v1, $t1

	# Call smallProc for the heck of it, but save $v0,
	# and $v1 because smallProc could possibly overwrite them!
	addi	$sp, $sp, -4		# store $v0 and $v1 to the stack
	sw	$v0, 0($sp)
	
	addi	$sp, $sp, -4
	sw	$v1, 0($sp)
	
	jal	smallProc

	# Restore registers using the stack
	lw	$v1, 0($sp)		# restore $v0 and $v1 from the stack
	addi	$sp, $sp, 4
	
	lw	$v0, 0($sp)
	addi	$sp, $sp, 4
	
	lw	$ra, 0($sp)		# restore $ra
	addi	$sp, $sp, 4
	
	jr	$ra

# This procedure computes nothing useful, it just returns

smallProc:

	jr	$ra
		
# If we had three result, I would need to push at least one result to the stack and pop it back after return.
