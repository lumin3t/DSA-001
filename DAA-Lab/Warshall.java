import java.util.Scanner;

public class Warshall {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the number of vertices from the user
        System.out.print("Enter the number of vertices: ");
        int vertices = scanner.nextInt();

        // Initialize the adjacency matrix (representing the graph)
        int[][] graph = new int[vertices][vertices];

        // Get the adjacency matrix from the user
        System.out.println("Enter the adjacency matrix (0 for no edge, 1 for edge):");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        // --- Warshall's Algorithm to find the transitive closure ---
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
                }
            }
        }

        // Display the transitive closure matrix
        System.out.println("Transitive Closure:");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(graph[i][j] + " ");
            }
            System.out.println(); // Move to the next line after printing a row
        }

        scanner.close(); // Close the scanner to release resources
    }
}
