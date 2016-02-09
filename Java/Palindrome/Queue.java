/**
 * Class Queue forms a first in first out queue method
 * with functions enqueue, dequeue, and isEmpty.
 */
package palindrome;

import palindrome.Node;

public class Queue {
	
	private Node tempFirst;
	private Node first;
	private Node last;
	
	Queue() {
		first = null;
		last = first;
	}
	
	public void enqueue(char c) {
		/**
		* Takes a char makes a node with it and places it in the queue.
		* Input: char
		* Output: Nothing
		*/
		c = Character.toLowerCase(c);
		Node newNode = new Node();
		newNode.setData(c);
		newNode.setNext(null);
		if (first == null) {
			first = newNode;
			last = first;
			first.setNext(last);
		}
		else {
			last.setNext(newNode);
			last = newNode;
		}
	}
	
	public Node dequeue(){
		/**
		* Removes first node in queue.
		*/ 
		if (first != null) {
			tempFirst = first;
			first = first.getNext();
			return tempFirst;
		}
		else {
			return null;
		}	
	}
	
	public boolean isEmpty() { 
		/**
		* Checks to see if queue is empty.
		* Input: Nothing
		* Output: boolean
		*/
		boolean flag = true;
		if (first != null) {
			flag = false;
		}
		return flag;
	}
		
}
