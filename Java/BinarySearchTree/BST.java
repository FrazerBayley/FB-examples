package binaryTree;

/*
 * Frazer Bayley / CIS 313
 * BST class sets up a binary search tree. Allowing for insertion,
 * search and deletion. 
 */

public class BST {
	
	public static Node root;
	
	public void insert(int a) {
		/*
		 * Takes an int and places it into the tree. If the int is less 
		 * than an existing node it goes to the left, if it is greater
		 * than or equal to an existing node it goes to the right.
		 */
		
		Node node = new Node();
		node.setData(a);
		
		//handles the root case
		if (root == null) {
			root = node;
			System.out.format("%d was inserted successfully!\n", a);
			return;
		}
		
		Node current = root;
		Node parent;
		
		while (true) {
			parent = current;
			if (a < current.getData()) {
				current = current.getLeft();
				if (current == null) {
					parent.setLeft(node);
					System.out.format("%d was inserted successfully!\n", a);
					return;
				}
			}
			else {
				current = current.getRight();
				if (current == null) {
					parent.setRight(node);
					System.out.format("%d was inserted successfully!\n", a);
					return;
				}
			}
		}
	}
	
	public void search(int a) {
		/*
		 * Searches for a given int. If int is found output
		 * is given, if scope reaches a leaf with int not found
		 * it reports int not found in tree.
		 */
		
		Node scope = root;
		
		while(true) {
			//handles null scope
			if (scope == null){
				System.out.format("Search could not find %d.\n", a);
				break;
			}
			if (a < scope.getData()){
				if (scope.getLeft() == null){
					System.out.format("Search could not find %d.\n", a);
					return;
				}
				else{	
					scope = scope.getLeft();
				}
			}
			if (a > scope.getData()){
				if (scope.getRight() == null){
					System.out.format("Search could not find %d.\n", a);
					return;
				}
				else{	
					scope = scope.getRight();
				}
			}
			if (a == scope.getData()){
				System.out.format("Search found %d!\n", a);
				return;
			}
		}
	}
	
	public void delete(int a){
		/*
		 * Deletes a given int from the tree. There are 4 different cases 
		 * that need to be handled. (1) If the node being deleted has no 
		 * children. (2) If the node has 1 left child. (3) if the node has
		 * one right child. Or (4) the node has two children.
		 */
		
		Node scope = root;
		Node parentScope = root;
		Node tempScope = null;
		
		while (true){
			if (scope == null){
				System.out.format("There is no %d to delete.\n", a);
				return;
			}
			if (a < scope.getData()){
				if (scope.getLeft() == null){
					System.out.format("There is no %d to delete.\n", a);
					return;
				}
				else{	
					parentScope = scope;
					scope = scope.getLeft();
				}
			}
			if (a > scope.getData()){
				if (scope.getRight() == null){
					System.out.format("There is no %d to delete.\n", a);
					return;
				}
				else{	
					parentScope = scope;
					scope = scope.getRight();
				}
			}
			//node that needs to be deleted is found
			if (a == scope.getData()){
				
				//node has no children
				if (scope.getLeft() == null && scope.getRight() == null){
					if (scope == root){
						root = null;
					}
					if (scope.getData() < parentScope.getData()){
						parentScope.setLeft(null);
					}
					else{
						parentScope.setRight(null);
					}
					scope = null; // this is not deleting the node for some reason
					System.out.format("%d has been deleted!\n", a);
					return;
				}
				
				//node has left child but no right child
				if (scope.getLeft() != null && scope.getRight() == null){
					if (scope == root){
						root = scope.getLeft();
						scope = null;
						System.out.format("%d has been deleted!\n", a);
						return;
					}
					if (scope != root){
						if (parentScope.getData() > scope.getData()){
							parentScope.setLeft(scope.getLeft());
							scope = null;
							System.out.format("%d has been deleted!\n", a);
							return;
						}
						if (parentScope.getData() <= scope.getData()){
							parentScope.setRight(scope.getLeft());
							scope = null;
							System.out.format("%d has been deleted!\n", a);
							return;
						}
					}
				}
				
				//node has no left child but does have a right child
				if (scope.getLeft() == null && scope.getRight() != null){
					if (scope == root){
						root = scope.getRight();
						scope = null;
						System.out.format("%d has been deleted!\n", a);
						return;
					}
					if (scope != root){
						if (parentScope.getData() > scope.getData()){
							parentScope.setLeft(scope.getRight());
							scope = null;
							System.out.format("%d has been deleted!\n", a);
							return;
						}
						if (parentScope.getData() <= scope.getData()){
							parentScope.setRight(scope.getRight());
							scope = null;
							System.out.format("%d has been deleted!\n", a);
							return;
						}
					}
				} 
				
				//Node has two children; in order to handle
				//turn right, then keep turning left
				if (scope.getLeft() != null && scope.getRight() != null){
					tempScope = scope;
					scope = scope.getRight();
					while (true){
						if (scope.getLeft() == null){
							tempScope.setData(scope.getData());
							tempScope.setRight(null);
							scope = null;
							System.out.format("%d has been deleted!\n", a);
							return;
						}
						if (scope.getLeft() != null){
							parentScope = scope;
							scope = scope.getLeft();
						}
					}	
				}
			}
		}
	}
}
