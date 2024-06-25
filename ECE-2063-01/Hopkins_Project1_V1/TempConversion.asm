.data
emptySpace: .asciiz " "
newline: .asciiz "\n"
getCelsiusTemp: .asciiz "Please choose a number between -20 degrees C and 110 degrees C: "
verifyTempValue: .asciiz "/nThe celsius temperature you chose was: "

celsiusValue: .asciiz "/nThe temperature in celsius is: "
kelvinValue: .asciiz "/nThe temperature in kelvin is: "
fahrenheitValue: .asciiz "/nThe temperatrue in fahrenheit is: "

.text
Prompt:
	#Ask for float
	la $a0, getCelsiusTemp 
	li $v0, 4
	syscall

	#Get float and store in $f0 using the $v0 code number 6
	li $v0, 6		
	syscall
	
	mov.s $f12, $f0

	#Verify if the number chosen is correct
	la $a0, verifyTempValue	
	li $v0, 4
	syscall
	
	#Print float at $f0
	li $v0, 2		
	mov.s $f12, $f0
	syscall

Celsius:
	#Print prompt for celcius value
	la $a0, celsiusValue
	li $v0, 4
	syscall
	
	#Print float at $f0
	li $v0, 2
	mov.s $f12, $f0
	syscall

Kelvin:
	#Loaded the float value of kelvinFloat into $f2
	lwc1 $f1, kelvinFloat
	
	#Convert to kelvin
	add.s $f2, $f0, $f1
	
	#Print kevlinValue statement
	la $a0, kelvinValue
	li $v0, 4
	syscall
	
	#Print float at $f2
	li $v0, 2
	mov.s $f12, $f2
	syscall

Fahrenheit:
	#Loaded the float value of farhenheitFloat1 into $f3
	lwc1 $f3, fahrenheitFloat1
	lwc1 $f5, fahrenheitFloat2
	
	#Convert to fahrenheit
	mul.s $f4, $f0, $f3
	add.s $f6, $f4, $f5

	#Print fahrenheitValue statement
	la $a0, fahrenheitValue
	li $v0, 4
	syscall
	
	#Print float at $f5
	li $v0, 2
	mov.s $f12, $f6
	syscall

Exit:
	#System call for exit
	li $v0, 10
	syscall
	

	
	
	
	
	
	
	
	
	
	
	
