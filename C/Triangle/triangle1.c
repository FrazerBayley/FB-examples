/*
	Frazer Bayley
	CIS 330
	assignment2/triangle1.c
*/
#include <stdio.h>

void print5Triangle(){
	/*
		Prints a simple triangle of chars using a 2-d array.
	*/
	int triangle[6][10] = {
		{-1, -1, -1, -1, 0, -1, -1, -1, -1},
		{-1, -1, -1, 0, 1, 2, -1, -1, -1},
		{-1, -1, 0, 1, 2, 3, 4, -1, -1},
		{-1, 0, 1, 2, 3, 4, 5, 6, -1},
		{0, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	int i, j;
	printf("Problem 1 (a triangle of height 5):\n\n");
	for (i = 0; i < 5; i++){	//loops through rows
		for (j = 0; j < 9; j++){ 	//loops through columns
			if (triangle[i][j] == -1){
				printf("  ");	//prints char at coordinates
			}
			else {
				printf("%d ", triangle[i][j]);
			}
		}
		printf("\n");	
	}
	printf("\n");
}