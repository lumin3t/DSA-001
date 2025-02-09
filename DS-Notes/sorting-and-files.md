### Radix sort

![image](https://github.com/user-attachments/assets/52a10bc6-51d2-4474-ad5d-1b247d62528a)

```c
#include <stdio.h>
#include <stdlib.h>

void main() {
    int unsorted[50], bucket[10][50] = {{0}}, sorted[50];
    int j, k, m, p, flag = 0, num, N;

    printf("\nEnter the number of elements to be sorted: ");
    scanf("%d", &N);

    printf("\nEnter the elements to be sorted:\n");
    for (k = 0; k < N; k++) {
        scanf("%d", &num);
        sorted[k] = unsorted[k] = num; // Initialize both sorted and unsorted arrays
    }

    // Perform Radix Sort
    for (p = 1; flag != N; p *= 10) {
        flag = 0;
        // Distribute elements into buckets based on the current digit
        for (k = 0; k < N; k++) {
            bucket[(sorted[k] / p) % 10][k] = sorted[k]; // Place in the corresponding bucket
            if ((sorted[k] / p) % 10 == 0) {
                flag++; // Check if this digit is 0 (for checking the termination condition)
            }
        }

        // Collect the elements back into the sorted array from the buckets
        m = 0;
        for (j = 0; j < 10; j++) {
            for (k = 0; k < N; k++) {
                if (bucket[j][k] != 0) { // Ensure non-zero values are added
                    sorted[m] = bucket[j][k];
                    bucket[j][k] = 0; // Clear the bucket after moving to sorted array
                    m++;
                }
            }
        }
    }

    // Print the sorted array
    printf("\nSorted List:\n");
    for (j = 0; j < N; j++) {
        printf("%d\t", sorted[j]);
    }
    printf("\n");

    // Pause the program before exiting (for DOS environments)
    getch();
}
```

### Insertion sort:

![image](https://github.com/user-attachments/assets/1e59780d-8efa-4334-ae17-cb17e517bc89)

```c
#include<stdio.h>
#include<stdlib.h>
int main () {
    printf("Hehehe\n");
    //Insertion sort
    int i,j,k;
    int a[6] = {1, 7, 3, 9, 2, 5};
    for (i=1; i<6; i++) {
        k = a[i];
        for (j=i-1; j>=0 && k<a[j]; j--) {
            a[j+1]=a[j];
        }
        a[j+1]=k;
    }
    printf("Sorted array: ");
    for (i=0; i<6; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```

### Hashing

##### Program to implement hash table

```c
#include<stdio.h>
int main () {
    int a[20], a1[20], a2[20], result, n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //Hash table
    for (i = 0; i < n; i++) {
        result = a[i]%10; //get the last digit of entered elemnt
        a1[result] = a[i]; //a1 array contains elemnts at the index of the digit
        a2[i] = a1[result]; //a2 array contains the hash table
        printf("%d is stored at position %d\n", a[i], result);
    }
    printf("Hash table: ");
    for (int j = 0; j < n; j++){
        printf("%d ", a2[j]);
    }
    return 0;
}
```

When two or more keys hash to the same index in a hash table, a **collision** occurs. To handle collisions, we use **collision resolution techniques**. These techniques ensure that all keys can be stored and retrieved correctly, even if they initially hash to the same index.

**Open Addressing** is a **collision resolution strategy** where all elements are stored directly in the hash table itself. When a collision occurs, the algorithm searches for an alternative slot (or bucket) within the table to place the key. This is done using a **probe sequence** (a sequence of indices to check).

Linear probing is a **collision resolution technique** used in hash tables. When a collision occurs (i.e., two keys hash to the same index), linear probing searches for the next available slot in the hash table by incrementing the index linearly (one step at a time) until an empty slot is found.

The hash function for linear probing is typically defined as:

$h_i(x) = \left( \text{hash}(x) + F(i) \right) \mod \text{table size}$

where:

- $hash(x)$ is the initial hash value of the key xx,
- $F(i)$ is a function of the probe number ii. For linear probing, $F(i)=iF(i)=i$
- $table size$ is the size of the hash table.

**Open Addressing** includes other probing methods like: - **Quadratic Probing**: $F(i)=i^2$ - **Double Hashing**: $F(i)=i⋅hash_2​(x)$

##### Quadratic Probing

Quadratic probing resolves collisions by using a quadratic function to find the next available slot. If a collision occurs at index $h(x)$, it checks slots at $h(x) + 1^2$, $h(x) + 2^2$, $h(x) + 3^2$, and so on. The hash function is:
$h_i(x) = (h(x) + c_1 .i + c_2 . i^2) \, \% \, \text{table size}$

- Reduces **primary clustering** but may still suffer from **secondary clustering**.
- Works best when the table size is a prime number.

##### Double Hashing

Double hashing uses a second hash function to determine the probe sequence. If a collision occurs at $h_1(x)$, it checks slots at $h_1(x) + i . h_2(x)$. The hash function is:
$h_i(x) = (h_1(x) + i . h_2(x)) \, \% \, \text{table size}$

- $h_2(x)$ should never evaluate to 0, and the table size should be prime.
- Eliminates clustering and provides a more uniform distribution of keys.

##### Collision handling with Linear Probing

```c
#include <stdio.h>  
#include <stdlib.h>  

int main() {
    int a[100], a1[100], i, j, result, n, cnt = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Initialize the hash table (a1) to -1, indicating empty slots
    for(i = 0; i < 10; i++) {
        a1[i] = -1;
    }
    // Inserting elements into the hash table using open addressing (linear probing)
    for(i = 0; i < n; i++) {
        result = a[i] % 10;  // Hash function
        if(a1[result] == -1) { //if empty
            a1[result] = a[i];
            printf("Location: a1[%d], Value: %d\n", result, a1[result]);
        } else {
            // Collision handling
            j = result + 1;  // Start from the next index
            while(1) {
                if(a1[j] == -1) {  // Check if the slot is empty
                    a1[j] = a[i];
                    printf("Location: a1[%d], Value: %d\n", j, a1[j]);
                    break;
                }
                if(j > 9) {  // Wrap arpund
                    j = 0;
                }
                if(cnt == n) {
                    break;
                }
                cnt++;  
                j++;  
            }
        }
    }
    printf("Hash table using open addressing mode:\n");
    for(i = 0; i < 10; i++) {
        if(a1[i] != -1) {  // Print only the filled slots
            printf("%d ", a1[i]);
        }
    }
    return 0;
}
```

![image](https://github.com/user-attachments/assets/953d0bdd-9c56-40ff-a6d4-faf87a43670c)

(Rest of it in the book hehe)
