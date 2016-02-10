/**
 * Creates a server that receives a list of integers from
 * a client and then sends back a list of primes from the 
 * original list.
 */
package assignment7;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {
	
	public static boolean isPrime(int number) {
		/**
		 * Determines if a number is prime
		 * Input: int
		 * Output: boolean
		 */
		boolean flag = true;
	    if (number % 2 == 0) 
	    {
	    	flag = false;
	    	return flag;
	    }
	    for(int i = 3; i * i <= number; i += 2) 
	    {
	        if(number % i == 0)
	        {
	        	flag = false;
	            return flag;
	        }
	    }
	    return flag;
	}
	
	//initiates the list to be sent back to Client
	private static ArrayList<Integer> sendableList = new ArrayList<Integer>();
	
	public static void primeList(ArrayList<Integer> list){	
		/**
		 * Puts prime number is an ArrayList to be sent back to client
		 * Input: ArrayList
		 * Output: Nothing
		 */
		for (int element : list){
			if (isPrime(element)){
				sendableList.add(element);
			}
		}
	}

	private static final int PORT = 12345;
	
	//forms an empty list to be filled by incoming list
	private static ArrayList<Integer> recievedList = new ArrayList<Integer>();
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		/**
		 * main() attempts to connect with client, if client found 
		 * waits for message then creates response and sends it to
		 * client. Also prints statuses to standard output.
		 */
		try{
			//initiates server socket
			ServerSocket serverSocket = new ServerSocket(PORT);
			System.out.println("Waiting for connection...");
			
			//accepts incoming sockets
			Socket socket = serverSocket.accept();
			
			System.out.println("Accepted connection!");
			
			//initiates output stream
			ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
			outputStream.flush();
			
			//initiates input stream
			ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());
			
			try{
				//recieves incoming list
				Object object = inputStream.readObject();
				recievedList = (ArrayList<Integer>) object;
				System.out.println("List recieved: " + recievedList);
			}
			catch (ClassNotFoundException ex){
				ex.printStackTrace();
			}
			
			System.out.println("Altering recieved list.");
			primeList(recievedList);
			
			//sends back altered list
			outputStream.writeObject(sendableList);
			outputStream.flush();
			
			System.out.println("Altered list sent: " + sendableList);
			
			//closes connections
			inputStream.close();
			outputStream.close();
			socket.close();
			
		}
		catch (IOException ex){
			ex.printStackTrace();
		}	
	}
}
