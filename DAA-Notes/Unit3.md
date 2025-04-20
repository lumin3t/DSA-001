![Merge Sort Quick Sort](https://github.com/user-attachments/assets/5dec0af5-9a29-4b8e-a6d9-e215bdb7a78f)

Merge sort:
All cases have same efficiency: Θ(n log n)
 Number of comparisons in the worst case is close to theoretical minimum for comparison-based sorting:
log2 n!
 ≈ n log2 n - 1.44n
 Space requirement: Θ(n) (not in-place)
 Can be implemented without recursion (bottom-up)

Quick sort
Best case: split in the middle — Θ(n log n)
 Worst case: sorted array! — Θ(n^2 )
 Average case: random arrays — Θ(n log n)
 Improvements: • better pivot selection: median of three partitioning • switch to insertion sort on small subfiles • elimination of recursion These combine to 20-25% improvement \
 Considered the method of choice for internal sorting of large files (n ≥ 10000)

## Tree traversal

```
ALGORITHM Height(T )
//Computes recursively the height of a binary tree
//Input: A binary tree T
//Output: The height of T
if T = ∅ return −1
else return max{Height(Tlef t ), Height(Tright)} + 1
```

```
ALGORITHM LeafCount(T ) //Computes recursively the number of leaves in a binary tree
//Input: A binary tree T
//Output: The leaf count of T
if (T!= NULL) {
	LeafCount(T->left);
	if ((T->left == NULL) && (T->right == NULL)) {
		count++;
	}
	LeafCount(T->right);
} return count;
```

inorder preorder postorder

## Multiply large Integers

![Mpy large int](https://github.com/user-attachments/assets/c7f3505f-e7ab-47f7-a7fc-cca510904ff5)

## Strassen Matrix

![Strassen Matrix](https://github.com/user-attachments/assets/faa46ef5-aa1d-4a98-ae32-0fe31013aa4a)
