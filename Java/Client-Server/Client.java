/**
 * Creates a client that interacts with a server by sending
 * a list of integers. Then receives an altered list from 
 * server.
 */

package assignment7;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Client {
	
	private static ArrayList<Integer> list = new ArrayList<Integer>();
	
	private static ArrayList<Integer> sendableList(){	
		/**
		 * Returns the list to be sent to server
		 * Input: Nothing
		 * Output: ArrayList
		 */
		enterInt();
		return list;
	}

	private static void enterInt(){
		/**
		 * Gets user input to be sent to server.
		 * Input: Nothing
		 * Output: Nothing
		 */
		Scanner scanner = new Scanner(System.in);
		while (true)
		{	//initiates the command line prompts, then puts user input into array list
			System.out.println("Enter a number to add to the list. Enter 'send' to send current list:");
			
			boolean input = scanner.hasNext("send");
			
			if (input)
			{
				break;
			}
			else
			{
				try //try catch to handle a non integer input
				{
				list.add(scanner.nextInt());
				}
				catch(Exception ex)
				{
					System.out.println("Sorry. That was not a number or 'send'. Try again.");
					enterInt();
					break;
				}
			}
			System.out.println("Current List: " + list);
		}
	}

	private final static int PORT = 12345;
	
	//forms the list in which the returned object will be placed 
	private static ArrayList<Integer> returnedList = new ArrayList<Integer>();
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
			/**
			 * Establishes connection with server, sends list, receives list.
			 * Prints statuses to standard output.
			 */
			
			//gives the user the command line and ready's the list for sending
			sendableList();
		    
		    try
		    {
		    	//IP Address for computer
		    	InetAddress address = InetAddress.getLocalHost();
		    	//creates a socket in the IP address and specific PORT
				Socket socket = new Socket(address, PORT);
				
				//initiates the output stream
				ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
				outputStream.flush();
				
				//initiates input stream
				ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());
				
				//sends the list of integers to server
				outputStream.writeObject(list);
				outputStream.flush();
				
				System.out.println("Client sent: " + list);
				
				try
				{
					//recieves the list sent back by Server
					Object object = inputStream.readObject();
					returnedList = (ArrayList<Integer>) object;
					System.out.println("Client recieved: " + returnedList);
				}
				catch (ClassNotFoundException ex)
				{
					ex.printStackTrace();
				}
				
				//closes connection
				inputStream.close();
				outputStream.close();
				socket.close();
				
		    }
		    catch (IOException ex)
		    {
		    	ex.printStackTrace();
		    }    
		    
	}
}
