.data
emptySpace: .asciiz " "
newline: .asciiz "\n"
getRangeYDS: .asciiz "Please enter a range less than 42240 yards: "
getRangeFT: .asciiz "\nThe number of yards in feet is: "
angleTraj: .asciiz "\nThe angle of trajectory is: "
flightTime: .asciiz "\nThe time of flight is: "
maxHeight: .asciiz "\nThe max height is: "

rangeFT: .float 3.0
pi: .float 3.14159
two: .float 2.0
radToDeg: .float 0.01745327777
gravity: .float 32.1522
twoGravity: .float 64.3044
velocity: .float 2500
velocitySquared: .float 6250000

.text
Prompt:
# prompt user to input range in yards
la $a0, getRangeYDS
li $v0, 4
syscall

# get float and store in $f0 using the $v0 code number 6
li $v0, 6		
syscall

mov.s $f12, $f0 

lwc1 $f1, rangeFT
mul.s $f2, $f0, $f1

# print getRangeFT prompt
la $a0, getRangeFT
li $v0, 4
syscall

# print range value in feet
li $v0, 2
mov.s $f12, $f2
syscall 

# math for x = (range * gravity) / v^2 
lwc1 $f5, gravity
lwc1 $f6, velocitySquared
mul.s $f9, $f2, $f5
div.s $f9, $f9, $f6
mfc1 $a0, $f9

# jump and link to loops
jal arcsin
jal tFlight
jal mHeight

# jump back to Prompt loop when all the loops have ran
j Prompt


arcsin:
	# first part of arcsin math
	la $t0, ($a0)
	mtc1 $t0, $f0 
	mtc1 $t0, $f1 
	mtc1 $t0, $f11 
 
 	# setting up arcsin math (power, counter, and divisor)
	li $t1, 3 		
	li $t2, 1 		
	li $t3, 6
	mtc1 $t3, $f2
	cvt.s.w $f2, $f2
 
	loop1:
		# first part of arcsin math
		beq $t1, $t2, loop3
		addi $t2, $t2, 1
		mul.s $f1, $f1, $f11 	
		j loop1
 
	loop2: 
		# second part of arcsin math
		beq $t1, $t2, endLoops
		addi $t2, $t2, 1
		mul.s $f1, $f1, $f11 	
		j loop2
 
	loop3:
		# third part of arcsin math
		div.s $f1, $f1, $f2 	# tempSum / 6
		add.s $f0, $f0, $f1 	# sum += tempSum
		mov.s $f1, $f11 	# reset tempSu
		li $t1, 5 		# change the power to 5
		li $t2, 1 		# resset counter
		j loop2

	endLoops:
		# last part of arcsin math (cleaning up and conversion of angle value)
		li $t3, 3
		mtc1 $t3, $f2
		cvt.s.w $f2, $f2 
		mul.s $f1, $f1, $f2
 
		li $t3, 40
		mtc1 $t3, $f2 		
		cvt.s.w $f2, $f2 	 
		div.s $f1, $f1, $f2 	
		add.s $f0, $f0, $f1 	
 
		# divide by 2 beacuse 2theta
		li $t3, 2
		mtc1 $t3, $f2
		cvt.s.w $f2, $f2  
		div.s $f0, $f0, $f2
		mov.s $f4, $f0		# radian version of final answer
		
		#converting answer to degrees
		lwc1 $f1, pi
		li $t3, 180
		mtc1 $t3, $f2 
		cvt.s.w $f2, $f2 
		mul.s $f0, $f0, $f2
		div.s $f0, $f0, $f1
 
		# print out angle in degrees prompt
		la $a0 , angleTraj
		li $v0 , 4
		syscall 
 
 		#print out angle in degrees value
 		li $v0, 2
		mov.s $f12, $f0	
		syscall

tFlight:
	# time of flight calculation
	lwc1 $f5, two
	lwc1 $f6, velocity
	lwc1 $f7, gravity
	
	mul.s $f9, $f5, $f6
	mul.s $f9, $f9, $f4
	div.s $f9, $f9, $f7
	
	# print out time of flight prompt
	la $a0 , flightTime
	li $v0 , 4
	syscall
	
	# print out time of flight value
	li $v0, 2
	mov.s $f12, $f9
	syscall 

mHeight:
	# max height calculation
	lwc1 $f5, velocitySquared
	lwc1 $f6, twoGravity
	
	mul.s $f9, $f4, $f4
	mul.s $f9, $f5, $f9
	div.s $f9, $f9, $f6
	
	# print out max height prompt
	la $a0 , maxHeight
	li $v0 , 4
	syscall
	
	# print out max height value
	li $v0, 2
	mov.s $f12, $f9
	syscall

	
