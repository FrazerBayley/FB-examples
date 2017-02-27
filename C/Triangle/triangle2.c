/*
	Frazer Bayley
	CIS 330
	assignment2/triangle2.c
*/
#include <stdio.h>
#include <stdlib.h>

void allocateNumberTriangle(int height, int ***triangle){
  /*
    Funtion takes a given height and a reference to a int array triangle and then
    allocates memory for that 2D array.
  */
	int i, j;
  (*triangle) = (int **) malloc ( (height + 1) * sizeof(int *) );
  for (i = 0; i < height; i++) {
    (*triangle)[i] = (int *) malloc ( 9 * sizeof(int) );
    for (j = 0; j < 9; j++) {
      	(*triangle)[i][j] = 0;
    }
  }
}

void initializeNumberTriangle(int height, int **triangle){
  /*
    Funtion takes a given height and a reference to a int array triangle and then 
    puts the appropriate numbers in [0 - 8] in that row.
  */
  int i, j;
  for (i = 0; i < height; i++){
    int a = 0;
    for (j = 0; j < 9; j++){
        if (j >= (5 - (i + 1)) && j < (5 + i)){
          triangle[i][j] = a;
          a++;
        }
        else {
          triangle[i][j] = -1;
        }
    }
  }
}

void printNumberTriangle(int height, int **triangle){
  /*
    Funtion takes a given height and a reference to a int array triangle and then 
    2D array in the shape of a triangle.
  */
  int i, j;
  for (i = 0; i < height; i++){
    for (j = 0; j < 9; j++){
      if (triangle[i][j] != -1) {
        printf("%d ", triangle[i][j]);
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void deallocateNumberTriangle(int height, int **triangle){
  /*
    Funtion takes a given height and a reference to a int array triangle and then
    frees the referenced memory.
  */
  int i;
  for (i = 0; i < height; ++i){
    free(triangle[i]);
  }
  free(triangle);
}
