/*
 ============================================================================
 Name        : lab_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//declare the functions
unsigned long factorial(unsigned short);
void leapYear(unsigned int);
float maximum(float, float);
float division(int, int);
unsigned long arithmetic(unsigned short);
void binar(unsigned short);

int main(void) {

	//initialize the variables
	char option;
	int exit_flag=0;
	unsigned short fac_input=0;
	unsigned long fac_answer=0;
	unsigned int year=0;
	float input1=0;
	float input2=0;
	float max=0;
	int operand1=0;
	int operand2=0;
	float quotient=0;

	printf("***Part 1***");

	//keep asking for a selection until the user selects exit
	while(exit_flag == 0){

		//reinitialize variables to zero at beginning of loop
		exit_flag = 0;
		fac_input = 0;
		fac_answer = 0;
		year=0;
		input1=0;
		input2=0;
		max=0;
		operand1=0;
		operand2=0;
		quotient=0;


		printf("\nPlease enter the number of one of the following options:");
		printf("\nA. Factorial\nB. Leap year or not\nC. Maximum\nD. Division\nE. Exit\n");
		scanf(" %c", &option);

		switch (option){
			//allow user to type either an upper case or lower case letter selection:
			case 'a':
			case 'A':
				//factorial
				printf("\nPlease enter a number to find its factorial: ");
				scanf("%hu", &fac_input); //input number as unsigned short

				//ask for an input until the input is in the range of the unsigned long output
				while(fac_input<1 || fac_input>12){
					printf("\nNumber out of range, please enter a number between 1 and 12: ");
					scanf("%hu", &fac_input); //input number as unsigned short
				}

				fac_answer = factorial(fac_input); //call factorial function
				printf("\nThe factorial is %lu\n", fac_answer); //print answer as unsigned long
				break;
			case 'b':
			case 'B':
				//leap year
				printf("\nPlease enter a year: ");
				scanf("%d", &year); //input unsigned int
				leapYear(year); //call leap year function
				break;
			case 'c':
			case 'C':
				//maximum
				printf("\nPlease enter input 1: ");
				scanf("%f", &input1); //input type float
				printf("\nPlease enter input 2: ");
				scanf("%f", &input2); //input type float

				max = maximum(input1,input2); //call find max function
				printf("\n%.2f is the maximum of the two numbers\n", max); //print max
				break;
			case 'd':
			case 'D':
				//division
				do{
				printf("\nPlease enter the first operand: ");
				scanf("%d", &operand1); //input data type int
				printf("\nPlease enter a non-zero number for the second operand: ");
				scanf("%d", &operand2); //input data type int
				}while(operand2 == 0); //keep asking for inputs until operand2 is not 0
				quotient = division(operand1, operand2); //call division function
				printf("\nThe quotient is %.2f\n", quotient);
				break;
			case 'e':
			case 'E':
				//exit
				exit_flag=1; //sets flag to 1 to end loop
				break;
			default:
				printf("\nError! Invalid input. Please re-enter!");
				break;
		}
	}

	printf("\n***Part 2***");

	//initializes part 2 variables
	unsigned short num=0;
	char choice;
	unsigned long bin=0;
	int input_flag=0;

	printf("\nPlease enter a number between 0 and 65,535: ");
	scanf(" %hu", &num); //input is unsigned short

	do{
		printf("\nEnter the letter of one of the options provided: ");
		printf("\nA. Arithmetic Operation\nB. Bitwise Operations\n");
		scanf(" %c", &choice);

		switch(choice){
			case 'A':
			case 'a':
				input_flag = 1;
				bin = arithmetic(num); //call arithmetic function
				printf("\nThe binary representation of %hu is %016lu\n", num, bin);
				break;
			case 'B':
			case 'b':
				input_flag = 1;
				binar(num); //call bitwise function
				break;
			default: //error for selection input
				printf("\nInvalid option. Please choose again.\n");
				input_flag = 0;
				break;
		}

	}while(input_flag == 0); //keep asking for an option until a correct one is entered

	return 0;
}

unsigned long factorial(unsigned short fac_input){
	unsigned short x=0;
	unsigned short y=1;
	unsigned long answer=1;

	//loop the length of the input
	for(x=fac_input; x>0; x--){
		answer *= (unsigned long) y; //multiply each number with each other
		y++; //increment y for the length of the loop
	}
	return answer;
}

void leapYear(unsigned int year){
	int remainder1=0;
	int remainder2=0;
	int remainder3=0;

	remainder1 = year % 4; //check if divisible by 4

	//if not, then not a leap year
	if(remainder1 != 0){
		printf("\n%d is not a leap year.\n", year);
		return;
	}

	remainder2 = year % 100; //check if divisible by 100

	//if not, then it's a leap year
	if(remainder2 != 0){
		printf("\n%d is a leap year.\n", year);
		return;
	}

	//if divisible by 100, check is divisible by 400
	remainder3 = year % 400;

	//if not, then not a leap year
	if(remainder3 != 0){
		printf("\n%d is not a leap year.\n", year);
	}
	else{
		//if yes, then it is a leap year
		printf("\n%d is a leap year.\n", year);
	}
	return;
}

float maximum(float input1, float input2){
	float max;
	//if input1 is greater then input2, then input one is max
	//if not, then input 2 is max
	max = input1>input2 ? input1 : input2;
	return max;
}

float division(int operand1, int operand2){
	float quotient=0;
	quotient = (float) operand1 / operand2; //divide to find quotient
	return quotient; //returns a float
}

unsigned long arithmetic(unsigned short num){
	unsigned long bi=0;
	int x=0;
	int ex=0;

	//loop until the number divided by 2 is zero
	while(num!=0){
		x = num%2; //determines whether its a 1 or 0
		num = (int) num/2; //divides by 2 to get next number for the loop
		bi += (x * (pow(10,ex))); //multiply the 1 or zero by its place value
		ex++; //increment the exponent for the proper place value
	}

	return bi; //return the unsigned long binary representation
}

void binar(unsigned short num){
	unsigned short test_bit=32768; //makes the binary: 1000 0000 0000 0000
	int an;

	printf("\nThe binary representation of %hu is ", num);

	while(test_bit > 0){
		an = (num & test_bit); //AND's the first bit to see whether it is a 1 or 0
		if(an == 0){ //if the bit is 0, then print a 0
			printf("0");
		}
		else{
			printf("1");
		}

		test_bit = (test_bit >> 1); //shift the 1 to the right to test the next bit
	}

	printf("\n");
	return;
}

