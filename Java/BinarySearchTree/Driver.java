package binaryTree;

/*
 * Driver class runs the front end of the program. Handling user
 * input and taking commands to modify a Binary Search Tree.
 */

import java.util.Scanner;

public class Driver {

	public static void main(String[] args) {
		
		BST binaryTree = new BST();	//creates Binary Search Tree
		
		System.out.format("Enter a command and then an integer n.\n"
				+ "Commands include:\n"
				+ "insert n\n"
				+ "search n\n"
				+ "delete n\n"
				+ "exit\n\n");
		
		while(true){
			Scanner in = new Scanner(System.in);
			String command = in.nextLine();	//takes user String
			String[] commandArray = command.split(" ");
			
			String a = commandArray[0];	

			if (a.equals("insert")){
				int n = Integer.parseInt(commandArray[1]);
				binaryTree.insert(n);
				System.out.format("\n");
			}
			if (a.equals("search")){
				int n = Integer.parseInt(commandArray[1]);
				binaryTree.search(n);
				System.out.format("\n");
			}
			if (a.equals("delete")){
				int n = Integer.parseInt(commandArray[1]);
				binaryTree.delete(n);
				System.out.format("\n");
			}
			if (a.equals("exit")){	//exits loop
				System.out.format("Goodbye!\n");
				return;
			}
			
		}	
	}

}
