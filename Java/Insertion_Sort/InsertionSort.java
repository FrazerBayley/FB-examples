/**
 * InsertionSort completes an insertion sort on both an
 * Array and ArrayList, functions insertArray and insertList are
 * given a random integer to place in the appropriate position. 
 * Program prints a list of unsorted integers and then two lists
 * (array and arrayList) of sorted integers to standard output.
 */

package insertionsort;

import java.util.ArrayList;
import java.util.Random;

public class InsertionSort {
	
	private static int indexArrayList = 0;
	private static int tempIndexAL = 0;
	private static int indexArray = 0;
	
	public static void insertArray(int[] array, int a) {
		/**
		 * Performs an insertion sort on an array of integers.
		 * Input: Array of integers, Integer to be added to Array
		 * Output: Nothing
		 */
		array[indexArray] = a;
		int i = indexArray;
		while (i > 0) {
			if (array[i] > array[i-1]) {
				break;
			}
			else {
				int temp = array[i-1];
				array[i-1] = array[i];
				array[i] = temp;
			}
			i--;
		}
		indexArray++;
	}

	public static void insertList(ArrayList<int[]> arrayList, int a) {
		/**
		 * Performs an insertion sort on an ArrayList. 
		 * Assisted by the function move().
		 * Input: ArrayList, integer
		 * Output: Nothing
		 */
		arrayList.add(new int[] {indexArrayList, a});
		tempIndexAL = indexArrayList;
		move(arrayList);
		indexArrayList++;
	}
	
	public static void move(ArrayList<int[]> arrayList) {
		/**
		 * Moves the array to the necessary position inside
		 * the ArrayList, also changes that arrays index.
		 * Input: ArrayList
		 * Output: Nothing
		 */
		if (tempIndexAL == 0) {
			return;
		}
		int[] first = arrayList.get(tempIndexAL - 1);
		int[] second = arrayList.get(tempIndexAL);
		if (first[1] <= second[1]) {
			return;
		}
		else {
			int[] newSecond = arrayList.get(tempIndexAL - 1);
			int[] newFirst = arrayList.get(tempIndexAL);
			newSecond[0] = tempIndexAL;
			newFirst[0] = tempIndexAL - 1;
			arrayList.set(tempIndexAL - 1, newFirst);
			arrayList.set(tempIndexAL, newSecond);
			tempIndexAL--;
			move(arrayList);
		}
	}
	
public static void main(String[] args) {
		/**
		 * Prints unsorted list and sorted array, ArrayList
		 * to standard output.
		 */
		
		ArrayList<int[]> arrayList = new ArrayList<int[]>();
		int[] array = new int[10];
		Random num = new Random();
		
		System.out.println("Unsorted List:");
		System.out.println("[index, value]");
		
		for (int i = 0; i < 10; i++) {
			int n = num.nextInt(100);
			insertList(arrayList, n);
			insertArray(array, n);
			System.out.printf("[%d, %d]\n", indexArrayList - 1, n);
		}
		
		System.out.printf("\nSorted Array:\n");
		for (int i = 0; i < 10; i++) {
			System.out.println(array[i]);
		}
		
		System.out.printf("\nSorted ArrayList:\n");
		for (int i = 0; i < 10; i++) {
			int[] temp = arrayList.get(i);
			System.out.printf("[%d, %d]\n", temp[0], temp[1]);
		}
	}
}
