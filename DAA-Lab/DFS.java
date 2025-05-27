import java.util.*;

public class DFS {
    private int v;
    private List<Integer> adjList[];
    public DFS (int V) {
        v = V;
        adjList = new LinkedList[v];
        for (int i=0; i<v; i++) {
            adjList[i] = new LinkedList<>();
        }
    }
    private void addEdge (int v, int w) {
        adjList[v].add(w);
    }
    private void topologicalSortUntil (int v, boolean[] visited, Stack<Integer> stack) {
        //till neighbor visited
        visited[v] = true;
        for (Integer neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                topologicalSortUntil(neighbor, visited, stack);
            }
        }
        stack.push(v);
    }
    private void topologicalSort () {
         //stack, visited arr
         Stack<Integer> stack = new Stack<>();
         boolean[] visited = new boolean[v];
         Arrays.fill(visited, false);
         //for loop i till visited 
         for (int i = 0; i<v; i++) {
             if (!visited[i]) {
                topologicalSortUntil(i, visited, stack);   
             }
         }
         while(!stack.isEmpty()) {
             System.out.print(stack.pop()+ " ");
         }
         //pop output 
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices: ");
        int V = sc.nextInt();
        DFS g = new DFS(V); //init constructor
        System.out.println("Enter adjacency matrix: ");
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (sc.nextInt() == 1) {
                 g.addEdge(i, j);
                }   
            }
        }
        g.topologicalSort();
        sc.close();
    }
}
