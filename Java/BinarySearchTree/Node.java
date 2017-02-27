package binaryTree;

/*
 * Frazer Bayley / CIS 313
 * Node class sets up binary tree nodes. Each has a left and right
 * pointer.
 */

public class Node {
	
	public int data; 
	public Node left;
	public Node right;
	
	public void setData(int data) {
		//sets the int value for the node
		this.data = data;
	}
	
	public int getData() {
		//returns the int value contained within node
		return data;
	}
	
	public void setLeft(Node left) {
		//sets the node's left child
		this.left = left;
	}
	
	public void setRight(Node right) {
		//sets the node's right child
		this.right = right;
	}
	
	public Node getLeft() {
		//returns the node's left child
		return left;
	}
	
	public Node getRight() {
		//returns the node's right child
		return right;
	}
	
}
