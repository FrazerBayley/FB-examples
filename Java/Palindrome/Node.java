/**
* Node object that provides getters and setters for other
* classes to use. Also provides a toString method. Takes 
* a char as data.
*/
package palindrome;

public class Node {
	
	private char data; 
	private Node next;
	
	public char getData() {
		return data;
	}
	public void setData(char data) {
		this.data = data;
	}
	public Node getNext() {
		return next;
	}
	public void setNext(Node next) {
		this.next = next;
	}
	
	public String toString() {
		return data + "";
	}
		
	
}
