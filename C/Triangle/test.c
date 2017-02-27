/*
	Frazer Bayley
	CIS 330
	assignment2/test.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "triangle.h"

void clearInputBuffer() {
  while ( getchar() != '\n' );
}

int getInt(const char* msg, int low, int high) {
	/* Keep prompting the user for input until they enter a single integer
	 * whose value is between low and high (inclusive).
	 */
	int numInts = 0, num = 0;
	while (numInts != 1 || num < low || num > high) {
	    printf("%s",msg);
	    numInts = scanf("%d", &num);  // returns the number of integers read from input
	    clearInputBuffer();
	}
	return num;
}

int main(){
	print5Triangle();

	int **triangle;
	int userInput = 0;
	int i;

	userInput = getInt("Please enter the height of the triangle [1 - 5]: ", 1, 5);

	const int height = userInput;

	allocateNumberTriangle(height, &triangle);
	initializeNumberTriangle(height, triangle);
	printNumberTriangle(height, triangle);
	deallocateNumberTriangle(height, triangle);

	return 0;
}