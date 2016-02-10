/**
 * The QuickSort program takes an Array of integers and sorts
 * it from least to greatest. Prints an unsorted list to standard
 * output then a sorted list.
 */

package quicksort;

import java.util.Random;

public class QuickSort {
	
	public static int[] quickSort(int[] array) {
		/**
		 * The function quickSort() takes an unsorted array
		 * of integers and sorts them from least to greatest. 
		 * Uses recursion to break apart array.
		 * Input: Unsorted Array
		 * Output: Sorted Array
		 */
		if (array.length <= 1) {	//base case
			return array;
		}
		int pivotIndex = array.length - 1;
		int pivot = array[pivotIndex];
		for (int i = 0; i < array.length; i++) {
			if (i == pivotIndex){
				break;
			}
			if (array[i] > pivot) {
				int temp = array[i];
				array[i] = array[pivotIndex - 1];
				array[pivotIndex - 1] = array[pivotIndex];
				array[pivotIndex] = temp;
				pivotIndex--;
				i = i - 1;
			}
		}
		
		int[] a = new int[pivotIndex];
		for (int i = 0; i < pivotIndex; i++) {
			a[i] = array[i];
		}
		
		int[] b = new int[array.length - (pivotIndex + 1)];
		for (int i = pivotIndex + 1; i < array.length; i++) {
			b[i - (pivotIndex + 1)] = array[i];
		}
		
		a = quickSort(a); //recursion
		b = quickSort(b);
		
		int[] sortedArray = new int[a.length + b.length + 1];
		for (int i = 0; i < a.length; i++) {
			sortedArray[i] = a[i];
		}
		
		sortedArray[a.length] = array[pivotIndex];
		
		for (int i = 0; i < b.length; i++) {
			sortedArray[i + (a.length + 1)] = b[i];
		}
			
		return sortedArray;
	}
	
	public static void main(String[] args) {
		/**
		 * Prints unsorted and sorted array to standard output.
		 */
		int[] intArray = new int[10];
		Random num = new Random();
		
		System.out.println("Unsorted List:");
		for (int i = 0; i < 10; i++) {
			int n = num.nextInt(100);
			intArray[i]= n;
			System.out.println(intArray[i]);
		}
		System.out.println();
		
		intArray = quickSort(intArray);
		
		System.out.println("Sorted List:");
		for (int i = 0; i < 10; i++) {
			System.out.println(intArray[i]);
		}
	}

}
