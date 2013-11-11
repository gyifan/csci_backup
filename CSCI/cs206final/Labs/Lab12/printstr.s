# File: putc.asm
# CSCI 206 lab work skelton
# For use with the MARS Keyboard and Display Simulator
# This program prints a character 'q' to the screen using memory-mapped I/O
	
	.data
	.align 2
string: 
	.ascii "Hi There!"
	.text
main:
	la	$s0, string	# load the string base address to $s0
	li	$s1, 1		# set $s1 to be the counter

loop:
	lb	$a0, 0($s0)	# load the printing letter to $a0
	jal	putc		# print
	addi	$s0, $s0, 1	# increment the address
	addi	$s1, $s1, 1	# increment the counter
	bgt	$s1, 9, exit	# if the 9 letters are all printed, exit
	j	loop

exit:
	li      $v0, 10		
	syscall			
	
putc:		
# Inputs: $a0 = byte to transmit
# Outputs: None

	li	$t0,0xffff0000	# The base address of the memory mappped
				# device registers		
pcloop:
	lw	$t1,8($t0)	# Load the transmit ctrl word into
				# $t1 (effective address=0xFFFF0008)
	andi	$t1,$t1,0x0001 	# Extract just the ready bit 
	beq	$t1,$0,pcloop	# Wait till ready
	sw	$a0, 0xc($t0)	# Write data (effective address=0xFFFF000C)
				# (Side effect of clearing transmitter ready)
	jr		$ra		
	

