/**
 * Class Stack makes a stack with first in last out
 * properties with functions puch, pop, and isEmpty.
 */
package palindrome;

import palindrome.Node;

public class Stack {

	private Node top = new Node();
	
	public void push(char c) {
		/**
		* Adds a char to a node then adds node to top of stack.
		* Input: char
		* Output: Nothing
		*/
		c = Character.toLowerCase(c);
		Node newNode = new Node();
		newNode.setData(c);
		newNode.setNext(null);
		if (top == null) {
			top = newNode;
		}
		else {
			Node tempTop = top;
			top = newNode;
			top.setNext(tempTop);
		}
	}
	
	public Node pop() {
		/**
		* Removes a node from the top of the stack.
		* Input: Nothing
		* Output: Node
		*/ 
		if (top != null) {
			Node tempTop = top;
			top = top.getNext();
			return tempTop;
		}
		else {
			return null;
		}
	}
	
	//checks to see if the stack is empty
	public boolean isEmpty() {
		/**
		* If stack is empty returns false;
		* Input: Nothing
		* Output: boolean
		*/
		boolean flag = true;
		if (top.getNext() != null) {
			flag = false;
		}
		return flag;
	}
	
}
