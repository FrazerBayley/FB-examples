/*
 * Frazer Bayley
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 * 
 * This program converts a x base to y base converter [less than 16]. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM 16
#define MAX_DECIMAL 2147483647 //for int

int convertToDecimal();
void convertToBase();

// Implement the rest of the program

int main() {

	char in_number[MAX_NUM+1]; //size 17 char[]
	int in_base = 0;
	int out_base = 0;
	char out_number[MAX_NUM+1]; //size 17 char[]

	printf("\n\n=== CIS314 Fall 2014 - Lab 1: Part 1: Program 1 ===\n\n");

	//takes the users number and defines it
	printf("Enter the number you would like to convert: \n");
	scanf("%s", in_number); //converts a string to a char[]

	//takes the base of the previous number and defines it
	printf("Enter your number's base: \n");
	scanf("%d", &in_base);

	//checks to see if base is out of range
	if (in_base <= 1){
		printf("The base you entered is out of range. (2-16)\n");
		return 0;
	}
	if (in_base > 16){
		printf("The base you entered is out of range. (2-16)\n");
		return 0;
	}

	//converts given number to decimal value
	int decimal = convertToDecimal(in_number, in_base);

	//stops the program if a condition isnt met in convertToDecimal function
	if (decimal == -1){
		return 0;
	}

	printf("Your number's decimal value = %d \n", decimal);

	//sets all ints in the array to zero
	int bitPlace = 16;
	for (int i = 0; i < 16; i++) {
		out_number[i] = '0';
	}
	out_number[bitPlace--] = '\0';

	//takes the users new base and defines it
	printf("Enter your number's NEW base: \n");
	scanf("%d", &out_base);

	//checks to see if base is out of range
	if (out_base <= 1){
		printf("The base you entered is out of range. (2-16)\n");
		return 0;
	}
	if (out_base > 16){
		printf("The base you entered is out of range. (2-16)\n");
		return 0;
	}

	//converts decimal value to new base
	convertToBase(decimal, out_number, &bitPlace, out_base);

	printf("Your number's value in base %d = %s (Ignore leading zeros)\n\n", out_base, out_number);

	return 0;
	//end of program
}

int convertToDecimal(char x[MAX_NUM+1], int y){	//converts any even base from 2 to 16 to decimal
	
	int outcome = -1;
	int len = strlen(x) - 1;
	int flag = 0;
	
	if (y >= 2 && y <= 16){
		int sum = 0;
		for (int i = 0; x[i] != '\0'; i++) {

			//gets the ASCII value for the given char
			int intValue = x[i] - '0';

			if (intValue >= 0 && intValue <= 9){
				if (intValue >= y){
					printf("The character %c exceeds base %d.\n", x[i], y);
					flag = 1;
					break;
				}
				else {
					int a = intValue * pow(y, len);		//int * 2^(len - n)
					sum = sum + a;
					len = len - 1;
				}
			}

			if (intValue > 9 && intValue < 17){
				printf("The character entered (%c) does not follow base %d logic.\n", x[i], y);
				flag = 1;
				break;
			}
			
			if (intValue >= 17 && intValue <= 22){
				if (intValue - 7 >= y){
					printf("The character %c exceeds base %d.\n", x[i], y);
					flag = 1;
					break;
				}
				else {
					intValue = intValue - 7;
					int a = intValue * pow(y, len);
					sum = sum + a;
					len = len - 1;
				}
			}

			if (intValue > 22){
				printf("The character %c exceeds base %d.\n", x[i], y);
				flag = 1;
				break;
			}
		}
		outcome = sum;
	}
	if (flag == 0){
		return outcome;
	}
	else{
		return -1;
	}
}

void convertToBase(int decimal, char *out_number, int *bitPlace, int base){ 
//converts decimal value to any base

    int quotient; 
    int remain;
    char ch;
    
    quotient = decimal / base;
	remain   = decimal % base;

	if (remain >= 0 && remain <= 9){
		ch = remain + '0';
	}
	if (remain >= 10 && remain <= 15){
		remain = remain + 7;
		ch = remain + '0';
	}
   
    out_number[(*bitPlace)--] = ch;
    
   
	if (quotient != 0) {
		convertToBase(quotient, out_number, bitPlace, base);
	}
	

 }

