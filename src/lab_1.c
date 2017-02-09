/*
 ============================================================================
 Name        : lab_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//initializes function
float circleArea(float);

#define pi 3.14

int main(void) {

	//start of part 1
	//initializes variables for part 1
	float radius=0;
	float area=0;

	printf("\n***Part 1***");

	printf("\nPlease enter the radius of a circle: ");
	scanf("%f", &radius); //user input of the radius
	area = circleArea(radius); //calls the area function
	printf("\nThe area of the circle is: %.3f\n", area); //displays the area of the circle

	//end of part 1
	//start of part 2

	//initializes variables for part 2
	float cost=0;
	float selling=0;
	float profit=0;
	float loss=0;

	printf("\n***Part 2***");

	do{
		//sets cost and selling prices back to zero after each loop
		cost=0;
		selling=0;
		printf("\n\nPlease enter the following prices as positive numbers.\n");
		printf("\nPlease input the cost of the item: $");
		scanf("%f", &cost);
		printf("\n\nPlease input the selling price of the item: $");
		scanf("%f", &selling);
	}while(cost<0 || selling<0); //loop if user keeps inputing negative prices

	if(cost < selling){
		//profit
		profit = (selling - cost); //calculates profit made
		printf("\nYou have made a profit of: $%.2f", profit);
	}
	else if(selling < cost){ //if not profit then check if they incurred loss
		//loss
		loss = (cost - selling); //calculates the money lost
		printf("\nYou have incurred a loss of: $%.2f", loss);
	}
	else if(cost == selling){
		//net zero
		printf("\nYou have broke even.\n"); // neither profit nor loss
	}

	//end of part 2

	//start of part 3

	//initializes part 3 variables
	float operand1=0;
	float operand2=0;
	char operator;
	float sum;
	double product;
	double quotient;
	float difference;
	int flag=0;
	char x;

	printf("\n\n***Part 3***");

	do{
		flag=0; //resets the flag after each loop
		printf("\n\nOperand 1: ");
		scanf("%f", &operand1); //gets first operand from the user

		printf("\nOperator: ");
		x = getchar(); //gets the return character
		operator = getchar(); //gets the operator

		printf("\nOperand 2: ");
		scanf("%f", &operand2);
		//gets the second operand from the user

		//switch statement depending on operator
		switch (operator) {
			case '+':
				sum = (float) operand1 + operand2; //calculates sum
				printf("\n%.3f %c %.3f = %.3f\n", operand1, operator, operand2, sum);
				flag = 1; //sets flag to end loop
				break;
			case '-':
				difference = (float) operand1 - operand2; //calculates difference
				printf("\n%.3f %c %.3f = %.3f\n", operand1, operator, operand2, difference);
				flag = 1; //sets flag to end loop
				break;
			case '*':
				product = (double) operand1 * operand2; //calculates product
				printf("\n%.3f %c %.3f = %.3f\n", operand1, operator, operand2, product);
				flag = 1; //sets flag to end loop
				break;
			case '/':
				if(operand2==0){ //checks if there is a division by zero
					printf("\nError! Division by zero!"); //if so, print error and don't set flag
					break;
				}

				quotient = (double) operand1 / operand2; //calculates quotient
				printf("\n%.3f %c %.3f = %.3f\n", operand1, operator, operand2, quotient);
				flag = 1; //sets flag to end loop
				break;
			default:
				printf("\nWrong format! Please re-enter!\n"); //print error message if wrong operator
				//don't set flag so it asks again
				break;
		}
	}while(flag!=1 ); //keep asking for operands and operator if they input an invalid operator

	//end of part 3

	return 0;
}

float circleArea(float radius){
	float cir;
	cir = (float)(pi*radius*2); //calculates area

	return cir; //returns area to main
}

