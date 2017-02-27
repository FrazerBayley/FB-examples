/*
 * Frazer Bayley
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 *
 * This program reads a sorted array from a file and finds a requested number
 *    using recursive or iterative binary search. The array is read from a file
 *    defined by FILE_NAME, which should be written as the number of elements
 *    followed by the elements themselses. each number can be deliniated with
 *    any whitepace character. Also, the maximum size of the array is defined 
 *    as MAX_SIZE.
 * 
 * NOTE: The array must be sorted!!
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void sortArray();
int itBinary();
void recBinary();

// Implement the rest of the program

int main(void) {

   FILE *in_file;
   int array[MAX_SIZE];
   int orderedArray[MAX_SIZE];
   int size;
   
   printf("\n\n=== CIS314 Fall 2014 - Lab 1: Part 2: Program 2 ===\n\n");

   in_file = fopen("array.dat", "r");

   printf("Reading integers from 'array.dat' into array....");
   for (int i = 0; i <= MAX_SIZE; i = i + 1){
   		fscanf(in_file, "%d", &array[i]);
   }
   printf(" Array Complete\n\n");

   printf("Sorting array....");
   sortArray(array);
   printf(" Array Sorted\n\n");

   printf("Printing sorted array:\n\n");
   for (int i = 0; i <= MAX_SIZE; i = i + 1){
      printf(" %d ", array[i]);
   }

   printf("\n\nEnter the integer you would like the binary searches to find:\n");
   int userTarget;
   scanf("%d", &userTarget);

   printf("\nStarting iterative binary search... ");
   int delta;  //finds the amount of time the search takes
   clock_t t1;
   clock_t t2;
   t1 = clock();
   int value = itBinary(array, userTarget);
   t2 = clock();
   delta = t2 - t1;
   printf("The iterative binary search time took %d\n", delta);

   printf("\nStarting recursive binary search... ");
   int delta1;
   clock_t t1b;
   clock_t t2b;
   t1b = clock();
   recBinary(array, userTarget, 0, MAX_SIZE);
   t2b = clock();
   delta1 = t2b - t1b;
   printf("The recursive binary search time took %d\n\n\n", delta1);

   return 0;
}

void sortArray(int *array){
   //sorts the given array to make it ready for the binary search

   int i = 1;
   while (i <= 100) {
      for (int j = i; array[j - 1] > array[j]; j = j - 1) {
         int temp = array[j];
         array[j] = array[j - 1];
         array[j - 1] = temp;
      }
      i = i + 1;
   }
}

int itBinary(int array[MAX_SIZE], int target){
   //uses a iterator binary search to find a given number in a sorted array
   
   int first = 0;
   int last = MAX_SIZE;
   int middle = (first+last)/2; //sets the middle term to compare with the target
 
   while (first <= last) { //while first is less than or equal to last
      if (array[middle] < target){  //if middle value in array is less than target
         first = middle + 1;  //set first equal to middle + 1 (we've ruled out middle int) 
      }
      else if (array[middle] == target) { //when search finds the target
         printf("\n%d found at array[%d].\n", target, middle + 1);   //returns location of target
         break;
      }
      else{ //if middle value is greater than target
         last = middle - 1;
      }
      middle = (first + last)/2; //resets middle to new value
   }
   if (first > last){   //controls algorthm if target is not in array
      printf("\nThe search could not find %d in the array!\n", target);
   }
   return target; 
}

void recBinary(int array[MAX_SIZE], int target, int first, int last){
   //uses a recursive binary search algorithm to search through a sorted array

   int middle;
 
   if (first > last) {  //checks to see if target is not in array
      printf("\nThe search could not find %d in the array!\n", target);
      return;
   }
   middle = (first + last) / 2;  //sets the middle value to be compared
   if (array[middle] == target){ //prints the location of the found target
      printf("\n%d found at array[%d].\n", target, middle + 1);
   }
   else if (array[middle] > target){
      //if middle value is greater than target set the back of the array to middle - 1
      recBinary(array, target, first, middle - 1);
   }
   else if (array[middle] < target){
      //if middle value is less than target set the front of the array to middle + 1
      recBinary(array, target, middle + 1, last);
   }
}

