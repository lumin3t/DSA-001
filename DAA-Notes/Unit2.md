# Brute Force

![Brute force Searches](https://github.com/user-attachments/assets/c424383b-e619-4f1d-aa68-844590f8b8a5)
Closest pair: Distance formula
Convex hull: Both sides distance signs same
sqrt((x2-x1)^2 + (y2-y1)^2)

selection sort : N^2
Bubble sort - N^2
Linear Search - N
Pattern matching - nm

# Exhaustive Search

## TSP

N!

![TSP](https://github.com/user-attachments/assets/85dd5a97-6116-46b9-9ad7-39c543249623)

## Knapsack

2^N

![Knapsack](https://github.com/user-attachments/assets/c37d4182-27a9-4f68-8e1a-de19e8c8d58d)

#### Difference Between DFS (Depth-First Search) and BFS (Breadth-First Search)

| Feature              | **BFS (Breadth-First Search)**                                                     | **DFS (Depth-First Search)**                                    |
| -------------------- | ---------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| **Traversal Order**  | Explores all neighbors at the current level before moving deeper (level-by-level). | Explores as far as possible along a branch before backtracking. |
| **Data Structure**   | Uses a **Queue** (FIFO).                                                           | Uses a **Stack** (LIFO, or recursion).                          |
| **Memory Usage**     | Higher (stores all nodes at current level).                                        | Lower (only stores current path).                               |
| **Applications**     | Shortest path in unweighted graphs, peer-to-peer networks.                         | Maze solving, topological sorting, cycle detection.             |
| **Time Complexity**  | **O(V + E)** (V = vertices, E = edges).                                            | **O(V + E)** (same as BFS).                                     |
| **Space Complexity** | **O(V)** (worst case: stores all nodes).                                           | **O(d)** (d = depth of recursion stack).                        |

![BFS](https://github.com/user-attachments/assets/528be910-eb87-4364-aaaa-e09ebc1ba376)
![DFS](https://github.com/user-attachments/assets/43376cb0-a70f-4d42-9c70-95c65bb66a33)

# Decrease and Conquer

- By constant (usually 1) eg Insertion sort
- By constant factor (usually 2) Binary search
- By variable (Euclids gcd)

## Insertion Sort

N^2

![Insertion Sort](https://github.com/user-attachments/assets/6eeeca2f-3112-4ed7-9834-532f9ba889a8)

## Topological Sort (BFS DFS)

DFS
![Topo DFS](https://github.com/user-attachments/assets/94c98da9-5543-453b-aac0-3c72b050d5ea)
BFS
![Topo BFS](https://github.com/user-attachments/assets/c7da0474-3beb-4645-9aba-0310c6390c06)

## Generating Permutations

N!

jhonson trotter
![jhonson trotter](https://github.com/user-attachments/assets/311c67d8-8974-406d-b232-d12db4e1deed)
working
![generating permutations](https://github.com/user-attachments/assets/5ad34c94-19b3-40ea-bc46-dbd6b800d3df)

## Binary search

yk
logn

computing median and selection problem
