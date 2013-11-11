# File: putc.asm
# CSCI 206 lab work skelton
# For use with the MARS Keyboard and Display Simulator
# This program prints a character 'q' to the screen using memory-mapped I/O
	
	.data
	
	.text
main:

	jal	getc
	add	$a0,$v0,$0
	jal	putc
	j	main

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
	
getc:
# Inputs: None
# Outputs: $v0 = byte retrieved from keyboard

	li	$t0, 0xffff0000 # The base address of the memory mapped device registers
	
gcloop:
	lw	$t1, 0($t0)	# Load the input ctrl word into $t1
	andi	$t1,$t1,0x0001	# Extract just the ready bit
	beq	$t1,$0,gcloop	# Wait for input
	lw	$v0, 4($t0)	# Load the input to $v0
	jr	$ra
