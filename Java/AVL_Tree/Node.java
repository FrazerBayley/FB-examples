package avlTree;

public class Node {
	Node left,right;
	int data;
	int height;
	
	public Node(int val){
		data = val;
		left = null;
		right = null;
		height = 0;
	}
	public Node getLeft() {
		return left;
	}
	public void setLeft(Node left) {
		this.left = left;
	}
	public Node getRight() {
		return right;
	}
	public void setRight(Node right) {
		this.right = right;
	}
	public int getData() {
		return data;
	}
	public void setData(int data) {
		this.data = data;
	}
}