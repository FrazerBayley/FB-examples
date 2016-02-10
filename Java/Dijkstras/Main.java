import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int lastNeighbor = 0; //keeps track of last used neighbor
	
	private static int pathFinder(ArrayList<int[]> arrayList, int n, int function){
		/* 
		 * Input: arrayList (matrix), # of nodes, int problem type (1-2)
		 * Output: The last integer in an array.
		 * Finds the shortest and longest path in the graph.
		 */
		
		int[] distances = new int[n];
		Queue<Integer> queue = new LinkedList<Integer>();
		int value = 0;
		
		if (function == 1){ //shortest path initialization
			value = Integer.MAX_VALUE; //close enough to infinity
		}
		if (function == 2){ //longest path initialization
			value = -1;
		}
		
		for (int i = 0; i < n; i++){ //init array
			distances[i] = value;
			queue.add(i);
		}
		distances[0] = 0; //source
		if (function == 3){
			distances[0] = 1;
		}
		
		
		while (queue.peek() != null){	//check queue to see if empty
			int u = queue.remove();
			lastNeighbor = 0;
			int v = nextNeighbor(arrayList, u); //checks to see if u has any neighbors
			while (v != -1){		//while there are neighbors to u
				if (function == 1){	//shortest path
					if (distances[v] > distances[u] + 1){
						distances[v] = distances[u] + 1;
					}
					v = nextNeighbor(arrayList, u);
				}
				if (function == 2){ //longest path
					if (distances[v] < distances[u] + 1){
						distances[v] = distances[u] + 1;
					}
					v = nextNeighbor(arrayList, u);
				}
				if (function == 3){
					distances[v] += distances[u];
					v = nextNeighbor(arrayList, u);
				}
			}
		}
	
		return distances[distances.length - 1]; //return last integer
	}
	
	private static int nextNeighbor(ArrayList<int[]> arrayList, int u){
		int[] array = new int[arrayList.size()];
		array = arrayList.get(u);
		int flag = -1;	//returns this if no neighbors
		for (int i = lastNeighbor + 1; i < array.length; i++){
			if (array[i] == 1){
				lastNeighbor = i; //sets the last neighbor used
				return i;
			}
		}
		return flag;
	}
	
	private static ArrayList<int[]> createMatrix(ArrayList<int[]> arrayList, int n){
		//creates matrix filled with zeros
		for (int i = 0; i < n; i++){
			int[] matrixRow = new int[n];	//creates row for matrix
			for (int k = 0; k < n; k++){
				matrixRow[k] = 0;	//sets each column in row to zero
			}
			arrayList.add(matrixRow);
		}
		return arrayList;
	}
	
	private static ArrayList<int[]> initMatrix(ArrayList<int[]> arrayList, int e, Scanner s){
		//initializes matrix
		for (int i = 0; i < e; i++){
			int row = s.nextInt() - 1, column = s.nextInt() - 1; 
			int array[] = new int[arrayList.size()]; 
			array = arrayList.get(row);
			array[column] = 1;
			arrayList.set(row, array);
		}
		return arrayList;
	}

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		int graphs = scanner.nextInt(); //# of graphs from first line in file
		for (int i = 0; i < graphs; i++){
			int nodes = scanner.nextInt(), edges = scanner.nextInt();
			ArrayList<int[]> matrix = new ArrayList<int[]>();
			matrix = initMatrix(createMatrix(matrix, nodes), edges, scanner);
			System.out.println("Graph number: " + (i+1));
			System.out.println("Shortest path: " + pathFinder(matrix, nodes, 1));
			System.out.println("Longest path: " + pathFinder(matrix, nodes, 2));
			System.out.println("Number of paths: "+ pathFinder(matrix, nodes, 3));
			System.out.println();
		}
	}
}