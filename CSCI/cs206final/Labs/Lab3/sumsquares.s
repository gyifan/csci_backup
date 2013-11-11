# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
# Yifan Ge
# Pre-Lab3

# data segment -------------------------------------
.data
.align 2

squares:
.word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 # array squares[.]
ivar:
.word 0                         # int i
sum:
.word 0                         # int k
squarestringupp:
.asciiz "squares["
squarestringdown:
.asciiz "] = "
enter:
.asciiz "\n"
donestring:
.asciiz "sum of squares from 0 to 99 = "
# code segment --------------------------------------
.text
init:
	li	$s0, 0			# set $s0 to be the ivar
	sw	$s0, ivar
	li	$s1, 0			# set $s1 to be the sum
	sw	$s1, sum
	la	$s2, squares		# load the base address of squares array to $s2

Loop:
	bge	$s0, 100, print		# check if ivar is over 100
	jal	squareInit		# calculate the square
	add	$s1, $s1, $t3		# add the sum
	sw	$s1, sum		# store the sum to the memory
	addi	$s0, $s0, 1		# increase ivar
	sw	$s0, ivar		
	j	Loop

squareInit:
	sll	$t0, $s0, 2		# Shift the counter
	add	$t1, $s2, $t0		# Get the address
	li	$t2, 0			# clear $t2
	li	$t3, 0			# clear $t3
squareLoop:	
	bge	$t2, $s0, squareEnd	# check if the square calculation finished
	add	$t3, $t3, $s0
	addi	$t2, $t2, 1
	j	squareLoop
squareEnd:
	sw	$t3, 0($t1)		# store the squared value
	jr	$ra

print:
	li	$s0, 0			# clear ivar
	sw	$s0, ivar

LoopPrint:
	bge	$s0, 100, Terminate	# check if done printing
	
	sll	$t0, $s0, 2		# set the offset
	add	$t1, $s2, $t0
	
	lw	$t2, 0($t1)		# load the sum to $t2
	
	la	$a0, squarestringupp	# print the value.
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s0
	li	$v0, 1
	syscall
	
	la	$a0, squarestringdown
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $t2
	li	$v0, 1
	syscall
	
	la	$a0, enter
	li	$v0, 4
	syscall
	
	addi	$s0, $s0, 1
	j	LoopPrint
	
Terminate:
	
	la	$a0, donestring		# print the sum
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s1		
	li	$v0, 1
	syscall
	
	li	$v0, 10			# end the program
	syscall
	
