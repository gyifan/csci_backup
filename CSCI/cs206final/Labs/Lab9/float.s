	.data
	.align 2

single:			.word 0x3f000000
double:			.word 0x00000000
			.word 0x3fe00000
single_increment:	.word 0x33800000
double_increment:	.word 0x00000000
			.word 0x3ca00000
two_single:		.float 2
two_double:		.double 2
five_single:		.float 5
five_double:		.double 5
single_largest:		.word 0x7f7fffff
double_largest:		.word 0xffffffff
			.word 0x7fefffff
single_smallest:	.word 0x00000001
double_smallest:	.word 0x00000001
			.word 0x00000000
delta:			.float 0.00001
single_print:		.asciiz "(single + smallest increment) = "
double_print:		.asciiz "(double + smallest increment) = "
p3_single_print:	.asciiz "smallest single = "
p3_double_print:	.asciiz "smallest double = "
p4_single_print:	.asciiz "largest single = "
p4_double_print:	.asciiz "largest double = "
print_after:		.asciiz ", after "
print_iterations:	.asciiz " iterations"
print_p7_equal:		.asciiz	"A == B"
print_p7_not_equal:	.asciiz	"A != B"
nl:			.asciiz "\n"

	.text

main:

problem_two:
	lwc1	$f1, single		# load the single, double and their smallest increment 
	
	ldc1	$f4, double
	
	lwc1	$f3, single_increment
	ldc1	$f6, double_increment
	
	add.s	$f12, $f1, $f3
	
	li	$v0, 4
	la	$a0, single_print
	syscall
	
	li	$v0, 2
	syscall
	
	li	$v0, 4
	la	$a0, nl
	syscall
	
	add.d	$f12, $f4, $f6
	
	li	$v0, 4
	la	$a0, double_print
	syscall
	
	li	$v0, 3
	syscall
	
	li	$v0, 4
	la	$a0, nl
	syscall
	
problem_three:
	lwc1	$f29, single_smallest
	lwc1	$f25, two_single

single_iteration_3:
	lwc1	$f12, single
	li	$t0, 0
iteration_single_loop_3:
	sub.s	$f27, $f12, $f29	# calculate the difference bewtween the current value and the smallest single precision value
	c.le.s	$f29, $f27		# check if we still can multiply
	bc1f	exit_3
	addi	$t0, $t0, 1
	div.s	$f12, $f12, $f25
	j	iteration_single_loop_3
exit_3:
	li	$v0, 4			# print single precision answer
	la	$a0, p3_single_print
	syscall	
	li	$v0, 2
	syscall	
	li	$v0, 4
	la	$a0, print_after
	syscall	
	li	$v0, 1
	add	$a0, $zero, $t0
	syscall
	li	$v0, 4
	la	$a0, print_iterations
	syscall
	li	$v0, 4
	la	$a0, nl
	syscall
	
double_iteration_3:
	ldc1	$f30, double_smallest
	ldc1	$f12, double
	ldc1	$f24, two_double
	li	$t0, 0
iteration_double_loop_3:
	sub.d	$f26, $f12, $f30	# calculate the difference bewtween the current value and the smallest single precision value
	c.le.d	$f30, $f26		# check if we still can multiply
	bc1f	exit_p3
	addi	$t0, $t0, 1
	div.d	$f12, $f12, $f24
	j	iteration_double_loop_3
exit_p3:
	li	$v0, 4			# print single precision answer
	la	$a0, p3_double_print
	syscall	
	li	$v0, 3
	syscall	
	li	$v0, 4
	la	$a0, print_after
	syscall	
	li	$v0, 1
	add	$a0, $zero, $t0
	syscall
	li	$v0, 4
	la	$a0, print_iterations
	syscall
	li	$v0, 4
	la	$a0, nl
	syscall

problem_four:
	lwc1	$f29, single_largest
	lwc1	$f25, two_single
	
single_iteration:
	lwc1	$f12, single		# load the initial value 0.5
	li	$t0, 0			# load the counter
iteration_single_loop:
	sub.s	$f27, $f29, $f12	# calculate the difference bewtween the current value and the largest single precision value
	c.le.s	$f12, $f27		# check if we still can multiply
	bc1f	exit_p4_single
	addi	$t0, $t0, 1
	mul.s	$f12, $f12, $f25
	j	iteration_single_loop
exit_p4_single:
	li	$v0, 4			# print single precision answer
	la	$a0, p4_single_print
	syscall	
	li	$v0, 2
	syscall	
	li	$v0, 4
	la	$a0, print_after
	syscall	
	li	$v0, 1
	add	$a0, $zero, $t0
	syscall
	li	$v0, 4
	la	$a0, print_iterations
	syscall
	li	$v0, 4
	la	$a0, nl
	syscall
	
double_iteration:
	ldc1	$f12, double		# load the initial value 0.5
	ldc1	$f30, double_largest
	ldc1	$f24, two_double
	li	$t0, 0			# set counter
iteration_double_loop:
	sub.d	$f26, $f30, $f12	# calculate the difference bewtween the current value and the largest single precision value
	c.le.d	$f12, $f26		# check if we still can multiply
	bc1f	exit_p4
	addi	$t0, $t0, 1
	mul.d	$f12, $f12, $f24
	j	iteration_double_loop
exit_p4:
	li	$v0, 4			# print double precision answer
	la	$a0, p4_double_print
	syscall	
	li	$v0, 3
	syscall	
	li	$v0, 4
	la	$a0, print_after
	syscall	
	li	$v0, 1
	add	$a0, $zero, $t0
	syscall
	li	$v0, 4
	la	$a0, print_iterations
	syscall
	li	$v0, 4
	la	$a0, nl
	syscall
	
problem_seven:
	lwc1	$f1, single
	ldc1	$f2, double
	lwc1	$f4, delta
	
	li	$t1, 5			# divide the single 0.5 by 5
	lwc1	$f5, five_single
	div.s	$f1, $f1, $f5
	
	lwc1	$f6, five_double	# divide the double 0.5 by 5
	div.d	$f2, $f2, $f6
	
	mfc1.d	$a0, $f2
	mfc1	$a2, $f1
	mfc1	$a3, $f4
	
	jal	equal_single_double
	
	beqz	$v0, print_not_equal
	
	la	$a0, print_p7_equal
	li	$v0, 4
	syscall
	
	j	exit
print_not_equal:
	la	$a0, print_p7_not_equal
	li	$v0, 4
	syscall
	
exit:	
	li	$v0, 10
	syscall
	
single_to_double:
	move	$t0, $a0		
	srl	$t1, $t0, 31		# get the sign bit and store in 31 bit position of $t1
	sll	$t1, $t1, 31
	
	sll	$t2, $t0, 1		# get the exp bits and store in $t2
	srl	$t2, $t2, 24
	
	sll	$t3, $t0, 9		# get the fraction bits
	srl	$t3, $t3, 9		
	
	addi	$t2, $t2, 896		# exp_double = exp_single + 896 store in $t2
	sll	$t2, $t2, 21		# get the exponential bits to the right place (30 - 19)
	srl	$t2, $t2, 1
	
	sll	$t4, $t3, 29		# get the last three fraction bits and store in (31 - 29) of $t4
	
	srl	$t3, $t3, 3		# get the first 20 fraction bits
	
	move	$v1, $t1		# put return value to $v0 and $v1
	or	$v1, $v1, $t2
	or	$v1, $v1, $t3
	move	$v0, $t4
	
	jr	$ra

equal_single_double:
	addi	$sp, $sp, -4		# store the return address to the stack
	sw	$ra, 0($sp)
	
	mtc1.d	$a0, $f2		# get the double from $a0, $a1
	mtc1	$a2, $f1		# get the single from $a2
	mtc1	$a3, $f4		# get the delta value from $a3
	
	mfc1	$a0, $f1		# convert the single to double and store in $f6 and $f7
	jal	single_to_double
	mtc1.d	$v0, $f6
	
	mfc1	$a0, $f4		# convert the delta value to double and store in $f8 and $f9
	jal	single_to_double
	mtc1.d	$v0, $f8
	
	lw	$ra, 0($sp)		# restore the return address
	addi	$sp, $sp, 4
	
	sub.d	$f10, $f2, $f6		# get the difference between the double and single and store the absolute valued double in $f10
	abs.d	$f10, $f10
	
	c.le.d	$f10, $f8		# set return value
	bc1f	return_true
	li	$v0, 0
	
	jr	$ra
return_true:
	li	$v0, 1	
	jr	$ra
