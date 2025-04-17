# Notion of an Algorithm

### Definition

An algorithm is a **step-by-step procedure** (recipe, method, technique) with the following **requirements**:

1. **Finiteness** → Must terminate after a finite number of steps.
2. **Definiteness** → Each step must be rigorously and unambiguously defined.
3. **Input** → Clearly specified valid inputs.
4. **Output** → Clearly defined expected results; provably correct for valid inputs.
5. **Effectiveness** → Steps must be simple and executable.

![Notion](https://github.com/user-attachments/assets/016942c5-213f-4f6c-b52f-f5aedd5370af)

# Algorithm Design Process

1. **Understanding the problem** → Analyze and formally define input/output requirements.
2. **Decide on computational means** → Select data structures and computational approach
   - exact vs approx
   - algo design tech
3. **Design** → Create solution blueprint using algorithmic techniques
   - methods of specifying (pseudocode, flowchart)
4. **Proving correctness** → Mathematically verify the algorithm works for all cases.
5. **Coding it** → Implement the designed solution in code.

![DAA Process](https://github.com/user-attachments/assets/72b909d5-e658-4399-bbe3-b213664aa542)

# Algorithm Analysis & Examples

### Common Problem Types

- **Sorting** → Arranging data in a specific order (e.g., ascending/descending).
- **Searching** → Finding the location of a target element in a dataset.
- **String Processing** → Manipulating and analyzing sequences of characters.
- **Graph Problems** → Solving problems modeled as nodes and edges (e.g., shortest path).
- **Combinatorial Problems** → Dealing with combinations/permutations of discrete structures.
- **Geometric Problems** → Solving problems involving shapes, points, and spatial relationships.
- **Numerical Problems** → Addressing mathematical computations and number-related algorithms.

### Sorting Algorithms

#### Key Properties

- **Stability** → Preserves order of equal elements.
- **In-place** → Uses minimal extra memory (usually O(1)).

#### Example: Selection Sort (O(n²))

```java
import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] A = {3, 1, 2};
        System.out.println("Unsorted: " + Arrays.toString(A));

        for (int i = 0; i < A.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < A.length; j++) {
                if (A[j] < A[min]) min = j;
            }
            // Swap
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }

        System.out.println("Sorted: " + Arrays.toString(A));
    }
}
```

**Time Complexity**: O(n²) (Inefficient for large datasets)

### Searching Algorithms

#### Example: Binary Search (O(log n))

```java
import java.util.Arrays;

class BinarySearch {
    public static void main(String[] args) {
        int[] A = {0, 1, 2, 3, 4, 5};
        int key = 3;
        boolean found = false;
        int low = 0, high = A.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == key) {
                System.out.println("Found at index " + mid);
                found = true;
                break;
            } else if (A[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (!found) System.out.println("Not found");
    }
}
```

**Time Complexity**: O(log n) (Efficient for sorted arrays)

### Algorithm Design Techniques _(To be discussed further)_

- Divide and Conquer
- Greedy Algorithms
- Dynamic Programming
- Backtracking
- Randomized Algorithms

# Analysis

![Analysis Framework](https://github.com/user-attachments/assets/4f686b37-3851-446f-81b3-0be8c1f6a120)

### Space Complexity Analysis

**Formula:**  
`S(P) = Fixed Space (C) + Variable Space (S(P))`

- **Fixed Space (C):** Memory for code, constants, static data (compiler allocated)
- **Variable Space (P):** Input-dependent storage (e.g., dynamic arrays, recursion stack)  
  _Example:_ Quicksort uses **O(log n)** variable space for recursion stack.

### Input Size Measurement

**Determines scalability:**

- **Arrays/Strings:** Number of elements (_n_)
- **Matrices:** Rows × Columns (_n×m_)
- **Graphs:** Vertices (_|V|_) + Edges (_|E|_)
- **Numbers:** Bit length (_log n_) for arithmetic ops  
  _Key Idea:_ Complexity is always expressed as a function of input size(s).

### Runtime Measurement Units

**Two perspectives:**

1. **Machine-Dependent:**
   - Nanoseconds/CPU cycles (actual hardware time) , compiler
1. **Machine-Independent:**
   - **Step counts** (abstract operations)
   - **Asymptotic notation** (Big-O for scalability analysis)

### Time Complexity Breakdown

**Three Fundamental Metrics:**

1. **Step Count × Frequency:**
   - _Steps:_ Basic operations (assignments, comparisons)
   - _Frequency:_ How often steps execute (loop iterations)
2. **Operation Count:**
   - _Primitive ops:_ Arithmetic, memory access, branching
3. **Frequency Count:**
   - _Example:_ Nested loops → **O(n²)** frequency

![Operation freq chart](https://github.com/user-attachments/assets/0c68b0f8-dba7-4fb5-8d46-626740f2ba7b)

# Theoretical Analysis

![Basic ops](https://github.com/user-attachments/assets/05fe21a6-76cf-498b-9dc2-7e6ff057e687)

### Order of Growth

Describes how an algorithm's runtime or memory requirements increase as the input size grows.

![Order of growth](https://github.com/user-attachments/assets/88932ef4-e51d-4188-b0b8-820ebbc43bb9)
![Order of growth graph](https://github.com/user-attachments/assets/c5285c39-17bd-405d-b877-8c891562ae4c)

### Best/Average/Worst Case

All algorithms have three performance profiles:

1. **Best-case (Ω)** - Cbest: Minimum possible operations for ideal input
2. **Average-case (Θ)** - Cavg: Prob of successfuls ops + Prob of unsuccessful ops
3. **Worst-case (O)** - Cworst: Maximum operations for most challenging input

### Asymptotic Notations

Mathematical tools to describe algorithm performance limits:

- Big-O (O): Upper bound/worst-case performance
- Big-Omega (Ω): Lower bound/best-case performance
- Big-Theta (Θ): Tight bound when best and worst cases match

![Asymptotic notations](https://github.com/user-attachments/assets/5f89c244-39af-4bfa-9992-e8a4d636ab13)

### Basic Efficiency Classes

Common runtime complexity categories:

1. O(1) - Constant time
2. O(log n) - Logarithmic
3. O(n) - Linear
4. O(n log n) - Linearithmic
5. O(n²) - Quadratic
6. O(n³) - Cubic
7. O(2ⁿ) - Exponential
8. O(n!) - Factorial
