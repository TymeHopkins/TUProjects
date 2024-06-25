.data

.text
#Loaded 0 into $t0 and 3 into $t1
li $t0, 0
li $t1, 3	
li $t2, 5
li $t3, 15


multiple3:
	#Check that $t0 is not 1000, if it is equal jump to exit
	beq $t0, 1000, exit

	#Divide $t0 by $t1
	div $t0, $t1
	mfhi $t4

	#If $t2 is equal to 0, jump to sum3, if not then jump to multiple5
	beq $t4, 0, sum3
	j multiple5


sum3:
	#Add $t0 to $s0 and store it in $s0
	add $s0, $t0, $s0
	j multiple5

multiple5:
	#Divide $t0 by $t2
	div $t0, $t2
	mfhi $t5
	
	#If $t4 is equal to 0, jump to sum5, if not then jump to increment
	beq $t5, 0, sum5
	j multiple15

sum5:
	#Add $t0 to $s0 and store it in $s0
	add $s0, $t0, $s0
	j multiple15
	
	
multiple15:
	#Divide $t0 by $t3
	div $t0, $t3
	mfhi $t6
	
	#If $t6 is equal to 0, jump to sum5, if not then jump to increment
	beq $t6, 0, sum15
	j increment


sum15:
	#Add $t0 to $s1 and store it in $s1
	add $s1, $t0, $s1
	j increment


increment:
	#Increment the value of $t0 to continue the loop
	add $t0, $t0, 1
	j multiple3


exit:
#Subtract the multiples of q5 from the all of the multiples of 3 and 5 combined to eliminate repaeated multiples
sub $s2, $s0, $s1

#Print $s0
li $v0, 1
move $a0, $s2
syscall

#Exit protocol
li $v0, 10
syscall

