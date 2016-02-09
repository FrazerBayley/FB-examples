/**
 * Checks a string to see if it is a palindrome. Employing 
 * the properties of stack and queue. Prgram prompts the user 
 * for a string, checks to see if a palindrome, prints its 
 * conclusion to standard output.
 */
package palindrome;

import java.util.Scanner;

import palindrome.Node;

public class Palindrome {
	
		private static String str;
		private static Queue queue = new Queue();
		private static Stack stack = new Stack();
		
		public static void main(String[] args) {
			/**
			* main() gets input from user then passes string to filler()
			* and gets a boolean from checker() to determin if string
			* is a palindrome. Prints answer to standard output.
			*/
			
			Scanner in = new Scanner(System.in);
			
			System.out.println("Enter a string to test whether it's "
					+ "a Palindrome:");
			
			str = in.nextLine();
			
			filler(str);
			boolean result = checker();
			
			if (result == true) {
				System.out.println("Your string is a palindrome!"
						+ " Good job!");
			}
			else {
				System.out.println("Your string is not a palindrome. "
						+ "Try again.");
			}
			
		}
		
		public static void filler(String s) {
			/**
			* Splits string into char array and then feeds chars into 
			* both a stack and queue. Ignores ' '.
			* Input: string
			* Output: Nothing
			*/
			char[] charArray = s.toCharArray();
			
			for (char a : charArray) {
				if(a != ' '){
					queue.enqueue(a);
					stack.push(a);
				}
				else {
					continue;
				}
			}
		}
		
		public static boolean checker() {
			/**
			* Removes chars from stack and queue then compares,
			* if chars do not match the function returns false,
			* string is not a palindrome.
			* Input: Nothing
			* Output: boolean
			*/ 
			boolean flag = true;
			while (queue.isEmpty() != true && stack.isEmpty() != true) {
				Node queueNode = queue.dequeue();
				Node stackNode = stack.pop();
				if (queueNode.getData() != stackNode.getData()) {
					flag = false;
					break;
				}
			}
			return flag;
		}
		
}
