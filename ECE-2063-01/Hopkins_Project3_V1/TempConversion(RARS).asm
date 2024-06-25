.data
emptySpace: .asciz " "
newline: .asciz "\n"
getCelsiusTemp: .asciz "Please choose a number between -20 degrees C and 110 degrees C: "
verifyTempValue: .asciz "\nThe celsius temperature you chose was: "

celsiusValue: .asciz "\nThe temperature in celsius is: "
kelvinValue: .asciz "\nThe temperature in kelvin is: "
fahrenheitValue: .asciz "\nThe temperatrue in fahrenheit is: "

.text
#Declared variables
li t0, -20
li t1, 110
li t2, 273
li t3, 9
li s1, 5

prompt:
	#Prompt user for value between -20 and 110
	la a0, getCelsiusTemp
	li a7, 4
	ecall

	#Get value and store somewhere safe
	li a7, 5
	ecall
	
	#Move value into t4
	mv t4, a0
	
	#Check if the user input a value between -20 and 110
	blt t4, t0, prompt
		bgt t4, t1, prompt
	

	#Verify if the number chosen is correct
	la a0, verifyTempValue	
	li a7, 4
	ecall
	
	#Print user input value
	li a7 1	
	mv a0 t4
	ecall

celcius:
	#Print Celcius prompt
	la a0, celsiusValue
	li a7, 4
	ecall
	
	#Print Celcius value
	li a7 1
	mv a0 t4
	ecall

kelvin:
	#Calculate Kelvin
	add t5, t2, t4
	
	#Print Kelvin prompt
	la a0, kelvinValue
	li a7, 4
	ecall
	
	#Print Kelvin value
	li a7 1
	mv a0 t5
	ecall

fahrenheit:
	#Caclulate Fahrenheit
	mul t6, t4, t3		#Multiplied by 9
	div t6, t6, s1		#Divided by 5
	addi t6, t6, 32		#Added 32
	
	#Print Fahrhenheit prompt
	la a0, fahrenheitValue
	li a7, 4
	ecall
	
	#Print Fahrenheit value
	li a7 1
	mv a0 t6
	ecall

exit:
	li a0, 0
	li a7, 10
	ecall
