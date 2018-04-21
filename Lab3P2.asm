# -----
#  calcHighestBit:
#  		This subroutine will return the highest set bit of input n in a0
#			equivalently the largest power of 2 >= to arg n


	addi	$8, $0, 500# Move in the argument of the routine
	addi	$9, $0, 0	# The value we're calculating, we will add to it

# -----
#  We will now loop and shift right logical until we reach 1, counting
#			the number of shifts it took


#	loopBegin:					# Start of the loop
	addi		$8, $8, -1 		# Rightshift t0 by 1
	beq		$8, $0, 0x2		# If our value has reached 0, branch from loop
	addi	$9, $9, 2 		# Add 1 for 1 rightshift on our value
	beq		$0, $0, -0x4		# Branch to start since our value hasn't reached 0
#	loopEnd:
	addi	$2, $9, $0	# Move the calculated result into v0, the return val
