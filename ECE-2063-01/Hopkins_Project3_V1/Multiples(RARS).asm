.data
emptySpace: .asciz " "
newline: .asciz "\n"
multiple3prompt: .asciz  "The sum of all the multiples of 3 between 0 and 1000 is: " 
multiple5prompt: .asciz  "\nThe sum of all the multiples of 5 between 0 and 1000 is: " 
multiple15prompt: .asciz "\nThe sum of all the multiples of 15 between 0 and 1000 is: "
answerprompt: .asciz "\nThe sum of the multiples 3 and 5 between 0 and 1000 is: "

.text
#MULTIPLE 3
prompt3:
	la a0, multiple3prompt
	li a7, 4
	ecall

#Declared variables for multiple3
li t0, 3
li t1, 6
li t2, 3
li t3, 1000

multiple3:
	bgt t1, t3, print3 	#Checks if t1 > 1000
	addi t0, t0, 3		#Starts the increment at 3
	addi t1, t1, 3		#Increments 6 first to compare so the counter doesn't count 101 after 999
	add  t2, t0, t2		#All multiples of 3 between 0 and 1000 stored in t2
	j multiple3

print3:
	li a7 1	
	mv a0 t2
	ecall

#MULTIPLE 5 	
prompt5:
	la a0, multiple5prompt
	li a7, 4
	ecall

#Declared variables for multiple5
li t0, 5
li t1, 15
li t4, 5

multiple5:
	bgt t1, t3, print5
	addi t0, t0, 5
	addi t1, t1, 5
	add  t4, t0, t4
	j multiple5

print5:
	li a7 1	
	mv a0 t4
	ecall

#MULTIPLE 15
prompt15:
	la a0, multiple15prompt
	li a7, 4
	ecall

#Declared variables for multiple15
li t0, 15
li t1, 30
li t5, 15

multiple15:
	bgt t1, t3, print15
	addi t0, t0, 15
	addi t1, t1, 15
	add  t5, t0, t5
	j multiple15

print15:
	li a7 1	
	mv a0 t5
	ecall

calculationprompt:
	la a0, answerprompt
	li a7, 4
	ecall

calculation:
	add t6, t2, t4		#Adds multiples of 3 and 5
	sub t6, t6, t5		#Subtracts the multiples of 15 from the sum of the multiples of 3 and 5 (eliminates duplicates)

printcalculation:
	li a7 1	
	mv a0 t6
	ecall

exit:
	li a0, 0
	li a7, 10
	ecall





