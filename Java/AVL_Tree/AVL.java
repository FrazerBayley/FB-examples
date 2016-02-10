package avlTree;

public class AVL {
	Node root;

	public AVL(){
		root = null;
	}

	/**
	 * Non recursive public insert method. 
	 * @param v Value to be inserted. 
	 */
	public void insert(String v) {
		int val = Integer.parseInt(v);  // Create an int
		Node n = new Node(val);			// Create a Node with the given value.
		root = insertNode(root, n);		// Begin insertion by starting at root. 
	}

	public int getHeight(Node n){	//returns the height of a node, handles null pointer 
		if(n == null){
			return 0;
		}else{
			return n.height;
		}
	}

	public int updateHeight(Node current) {	//retrieve height of node by gettingg the max subtree height + 1
		int height = Math.max(getHeight(current.left), getHeight(current.right)) + 1;
		return height;
	}


	/**
	 * Method to compare the value to be inserted with a node and either go to the left or right, until we find a null or a duplicate.
	 * @param current Represents the root of the subtree that the node is being inserted into. 
	 * @param n The node being inserted. 
	 * @return A reference to the node.
	 */
	private Node insertNode(Node current, Node n) {		// Think about how this code works recursively. 
		if(current == null){ 			// Reached a null leaf node. 
			current = n;				// Make that null node the node we want to insert and then return current. 
			System.out.println("Insert done.");
		}
		else if(current.data < n.data){	// Go down the right.
			current.right = insertNode(current.right, n);	// Important to notice I assign whatever is returned to current.right. 

		}
		else if(current.data > n.data){ // Go down the left.
			current.left = insertNode(current.left, n);		// Important to notice I assign whatever is returned to current.left.

		}
		else if(current.data == n.data){	// Return current as it is.
			System.out.println("Duplicate entry");
		}
		current = checkBalance(current); //restructure the AVL tree if needed
		return current;	
	}

	private Node checkBalance(Node current) {
		if (current == null) { //if current is null move on
			return current;
		}
		current.height = updateHeight(current);	//updates the height of current before using the height below
		int heightDif = getHeight(current.left) - getHeight(current.right);	//gets the difference of the left and right subtrees heights
		if (heightDif > 1) { //covers the case of the left heavy subtree
			int howHigh = getHeight(current.left.left) - getHeight(current.left.right);
			if (howHigh >= 0) {	//covers the case of the left heavy subtree of the first subtree
				current = rotateRight(current);
			}
			else {	//covers the case of the right heavy subtree of the original subtree
				current = rotateLeftRight(current);
			}
		}
		else if (heightDif < -1) {	//covers the case of the right heavy subtree
			int howHigh = getHeight(current.right.left) - getHeight(current.right.right);
			if (howHigh <= 0) { //covers the case of the right heavy subtree of the original subtree
				current = rotateLeft(current);
			}
			else {	//covers the case of the left heavy subtree of the original subtree
				current = rotateRightLeft(current);
			}	
		}
		return current;
	}

	private Node rotateRight(Node n) { //performs a right rotate
		Node temp = n.left;
		n.left = temp.right;
		temp.right = n;
		n.height = updateHeight(n);
		temp.height = updateHeight(temp);
		return temp;
	}

	private Node rotateLeftRight(Node n) {	//performs a left right rotate
		n.left = rotateLeft(n.left);
		return rotateRight(n);
	}

	private Node rotateLeft(Node n) {	//performs a left rotate
		Node temp = n.right;
		n.right = temp.left;
		temp.left = n;
		n.height = updateHeight(n);
		temp.height = updateHeight(temp);
		return temp;
	}

	private Node rotateRightLeft(Node n) {	//performs a right left rotate
		n.right = rotateRight(n.right);
		return rotateLeft(n);
	}

	public void traverse() {	//performs a pre-order traversal to check correctness of tree
		traversePreOrder(root); 
	}
	private void traversePreOrder(Node current) {
		if(current!=null){ 
			System.out.print(current.data + " ");
			traversePreOrder(current.left);
			traversePreOrder(current.right);
		} 
	}

	/**
	 * Public method to check if a value exists in the tree. This is just a wrapper. A recursive search is called within.  
	 * @param v The value.
	 */
	public void search(String v) {
		int val = Integer.parseInt(v);
		if(searchNode(root, val)){
			System.out.println("Node was found!");
		}
		else{
			System.out.println("Node not found");
		}
	}

	/**
	 * Private recursive method. To search for the string.
	 * @param current The current represents the root of a given subtree. 
	 * @param val The value being searched for.
	 * @return boolean true or false, depending on whether the node has been found.
	 */
	private boolean searchNode(Node current, int val) {
		if(current != null){
			if(current.data == val){
				return true;
			}
			else if(current.data > val){
				return searchNode(current.left, val);	// Notice how instead of assigning whatever is returned like we did in the insertNode method, I simply return it back. 
			}
			else if(current.data < val){
				return searchNode(current.right, val);
			}
		}
		return false;
	}

	/**
	 * Public delete method. 
	 * @param v value to be deleted.
	 */
	public void delete(String v) {
		int val = Integer.parseInt(v);
		if(searchNode(root, val)){	// This is a bit of a hack to make life a little simpler. I print node deleted before I do it, since I wont' need an extra flag to check the result in this case. If the node exists in the tree, I say it has been deleted.
			System.out.println("Node deleted.");
		}
		root = findDeleteNode(root, val);	// Begin a recursive delete method. Reference to the updated node is returned. 
	}

	/**
	 * Method to simply arrive at the node which needs to be deleted if it exists in the tree.
	 * @param current The current node, which represents the root of a subtree.
	 * @param val The value to be deleted.
	 * @return A reference to an updated Node. 
	 */
	private Node findDeleteNode(Node current, int val) {
		if(current == null){	// If we get to a leaf or null, it means we didn't find the node.
			System.out.println("Node not found.");
		}
		else if(current.data == val){	// Node has been found. Perform delete operation.
			return deleteCurrentNode(current);
		}
		else if(current.data > val){	// Traversing to find the node. 
			current.left = findDeleteNode(current.left, val);
		}
		else if(current.data < val){
			current.right = findDeleteNode(current.right, val);
		}
		current = checkBalance(current); //check the state of the tree if incorrect, corrects it, also updates heights
		return current;
	}

	/**
	 * We now are at the node that needs to be deleted. Identify the case and handle accordingly.
	 * @param current The node that needs to be deleted. 
	 * @return A reference to whatever the parent of current should point to. 
	 */
	private Node deleteCurrentNode(Node current) {
		int icase = IdentifyCase(current);
		if(icase == 1){ //no children
			return null;
		}
		else if(icase == 2){ // one child
			return deleteCase2(current);
		}
		else if(icase == 3){ //two children
			return deleteCase3(current);
		}
		return null;
	}

	/**
	 * Method to delete a node with only one child. Whatever is returned from this method, will replace the current node in the tree.
	 * @param current The node which needs to be deleted.
	 * @return The replacement. 
	 */
	private Node deleteCase2(Node current) {
		if(current.left == null){
			return current.right;
		}
		return current.left;
	}

	/**
	 * Method to delete a node with 2 children. 
	 * @param current The node to be deleted. 
	 * @return The node that the parent will point to. 
	 */
	private Node deleteCase3(Node current) {
		int replaceInt = findLowestInRightSubTree(current.right);	// Call a method to find the value of the replacement.
		current.setData(replaceInt);								// Set the data of the current node to the replacement value.
		current.right = findDeleteNode(current.right, replaceInt);	// Call delete on the right subtree, with the replacement value the one being deleted. Assign whatever is returned to the right subtree.
		return current;
	}

	/**
	 * Method to find the lowest value in the right subtree.
	 * @param current The root of the right subtree.
	 * @return Value of the lowest node in the subtree.
	 */
	private int findLowestInRightSubTree(Node current) {
		int val = current.data;
		while(current.left != null){
			current = current.left;
			val = current.data;
		}
		return val;
	}

	/**
	 * Method to identify how many children a node has.
	 * @param current The node that needs to be checked.
	 * @return A case number representing the above. 
	 */
	private int IdentifyCase(Node current) {
		if(current.left == null && current.right == null){
			return 1;
		}
		else if(current.left != null && current.right != null){
			return 3;
		}
		return 2;
	}
}
