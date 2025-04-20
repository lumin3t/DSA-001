# Greedy Technique

A problem-solving approach that builds solutions through **sequential, irrevocable choices** that are:

1. **Feasible** (satisfy all constraints)
2. **Locally optimal** (best immediate choice by some metric)
3. **Greedy** (maximizes short-term gain)

#### Optimal Solutions (Where Greedy Works)

- Coin change (normal denominations)
- Minimum Spanning Trees (MST)
- Shortest path problems
- Interval scheduling
- Huffman coding

#### Approximations (Where Greedy is Heuristic)

- Traveling Salesman Problem (TSP)
- Knapsack problems
- Other NP-hard optimization problems

```pseudocode
Algorithm Greedy(A, n):
    solution ← ∅
    for i ← 1 to n do
        x ← choose(A)          # Select best local option
        if feasible(x):        # Check constraints
            solution ← solution ∪ x
    return solution
```

# Prim's Algorithm (MST)

**Greedy Nature:** At each step, adds the **cheapest edge** connecting the growing tree to a new vertex.

1. Prim's algorithm is used to find the Minimum Spanning Tree (MST) of a weighted undirected graph.
2. Start with a single vertex (any vertex can be chosen) and create a set to track vertices included in the MST.
3. While there are still vertices not included in the MST, find the minimum weight edge that connects a vertex in the MST to a vertex outside the MST.
4. Add this edge and the connected vertex to the MST.
5. Continue the process until all vertices are included in the MST.
6. The result is a tree that connects all vertices with the minimum possible total edge weight.
7. The algorithm has a time complexity of O(E log V) when using a priority queue, where E is the number of edges and V is the number of vertices.
8. Prim's algorithm is used in network design, such as designing least-cost networks and in various optimization problems.

### Important terms

- **Spanning Tree:** Connected acyclic subgraph containing all vertices
- **Minimum Spanning Tree:** Spanning tree with lowest total edge weight

### Efficiency

- **O(n²)** with adjacency matrix + array
- **O(m log n)** with adjacency list + min-heap  
  _(m = edges, n = vertices)_

### Algorithm

![Prim's Algorithm](https://github.com/user-attachments/assets/e104f7db-34ff-498e-bd55-404298e6f482)

### Construction of MST

![MST Construction](https://github.com/user-attachments/assets/398db85f-5451-41ef-a905-865b8a945430)

How that'd look:

![MST Example](https://github.com/user-attachments/assets/8a89ccba-4ca8-4e2c-ba35-e79466134f79)

Cost Matrix:

![Cost Matrix](https://github.com/user-attachments/assets/e3cb549e-98eb-49a4-bec3-b79b95e39459)

# Kruskal's algorithm

![Kruskal Algo](https://github.com/user-attachments/assets/129e3687-1826-4aed-96bf-fb45579b2820)

# Dijkstra

![Dijkstra](https://github.com/user-attachments/assets/a99212b9-fba1-42c1-aa4b-d8ed1cc39700)

heres all of em
![Solvin em](https://github.com/user-attachments/assets/804f5252-92c9-41ba-8ba9-132fc854b535)

# Huffman coding

![Huffman coding](https://github.com/user-attachments/assets/d1a6d1e9-7119-4593-94c9-0616dcb83d10)
