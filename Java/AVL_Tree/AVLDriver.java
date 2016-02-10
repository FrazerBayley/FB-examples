package avlTree;

import java.util.Scanner;

public class AVLDriver {

	public static AVL tree;

	/**
	 * Main method to get first input and perform BST operations.
	 * @param args
	 */
	public static void main(String[] args) {
		tree = new AVL();
		Scanner sc  = new Scanner(System.in);
		System.out.println("Enter command:\n");
		String[] inputs = getInput(sc);
		performBSToperations(sc,inputs);
	}

	/**
	 * Method to loop until exit is entered.
	 * @param sc Scanner Object.
	 * @param inputs The instruction stored in a String array.
	 */
	private static void performBSToperations(Scanner sc, String[] inputs) {
		while(!inputs[0].equalsIgnoreCase("exit")){
			performNextBSTOperation(inputs);
			inputs = getInput(sc);
		}		
		System.out.println("\nExiting");
		System.out.println("\nPreOrder Traversal: ");
		tree.traverse();
	}

	/**
	 * Method to identify a BST operation and perform it. 
	 * @param inputs The instruction stored in a String array.
	 */
	private static void performNextBSTOperation(String[] inputs) {
		if(inputs[0].equalsIgnoreCase("insert")){
			tree.insert(inputs[1]);
		}
		else if(inputs[0].equalsIgnoreCase("delete")){
			tree.delete(inputs[1]);
		}
		else if(inputs[0].equalsIgnoreCase("search")){
			tree.search(inputs[1]);
		}
		else if(inputs[0].equalsIgnoreCase("exit")){
		}
		else{
			System.out.println("\nInput should be in the format: command int\nCommand can be : insert, delete, search or exit.\n");
		}
	}

	/**
	 * Helper function to get input from the user. This method splits the input and stores it in a String array. 
	 * @param sc Scanner Object.
	 * @return The string array. 
	 */
	public static String[] getInput(Scanner sc){
		String input = sc.nextLine();
		String[] inputs = input.split(" ");
		return inputs;
	}
}
