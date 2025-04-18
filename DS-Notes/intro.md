Classification and examples (notes)
![pg1](https://github.com/user-attachments/assets/d6b1eefb-ada0-4341-8fbe-c944a0d12211)

![pg2](https://github.com/user-attachments/assets/c0d8a02e-4a2a-4d4d-95b6-55f1998241aa)

## Storage classes

---

#### Example for AUTO

```c
#include <stdio.h>

void display() {
    auto int x = 5; // `auto` is optional here
    printf("Auto variable x = %d\n", x);
}

int main() {
    display();
    // Uncommenting below will cause an error as `x` is not accessible here
    // printf("%d\n", x);
    return 0;
}
```

In this program, `x` is automatically destroyed after `display()` exits.

#### Example for STATIC

```c
#include <stdio.h>

void count_calls() {
    static int count = 0; // retains its value between calls
    count++;
    printf("Function called %d times\n", count);
}

int main() {
    count_calls();
    count_calls();
    count_calls();
    return 0;
}
```

In this program, `count` retains its value across multiple calls to `count_calls()`, so each call increments `count`. The output will be:

```
Function called 1 times
Function called 2 times
Function called 3 times
```

#### Example for EXTERN

#Step 1: Define `pi` in `file.c`

```c
// file.c
#include <stdio.h>

double pi = 3.14159; // Define pi here

void displayPi() {
    printf("Value of pi: %f\n", pi);
}
```

#Step 2: Use `extern` to access `pi` in `file2.c`

```c
// file2.c
#include <stdio.h>

extern double pi; // Declare pi as an external variable

void printPi() {
    printf("Using extern in file2.c, pi = %f\n", pi);
}
```

#Step 3: Main Program to Compile Both Files

You can create a third file, `main.c`, to call functions from `file.c` and `file2.c`:

```c
// main.c
#include <stdio.h>

void displayPi();
void printPi();

int main() {
    displayPi(); // Function from file.c
    printPi();   // Function from file2.c
    return 0;
}
```

#Compilation
To compile and link these files, use:

```bash
gcc main.c file.c file2.c -o program
```

Running `program` will produce:

```
Value of pi: 3.141590
Using extern in file2.c, pi = 3.141590
```

This setup demonstrates how `extern` allows `pi` to be accessed across multiple C files.

## Bitfields

---

Bitfields in C are a way to allocate specific bits for variables within a struct, allowing memory-efficient storage.

1. **Definition**: Bitfields let you specify the number of bits each variable uses, ideal for saving memory in scenarios like embedded systems.

2. **Example**:

   ```c
   // Space optimized representation of the date
   struct date {
    // d has value between 0 and 31, so 5 bits
    // are sufficient
    int d : 5;
    // m has value between 0 and 15, so 4 bits
    // are sufficient
    int m : 4;
    int y;
   };
   int main() {
    printf("Size of date is %lu bytes\n",
           sizeof(struct date));
    struct date dt = { 31, 12, 2014 };
    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
    return 0;
   }
   ```

3. **Usage**: They’re used to represent flags, status registers, or compact data that fits within limited bits.

4. **Memory efficiency**: Allows specific bit-level control, reducing memory use compared to regular data types.

5. **Limitations**: Bitfields aren’t portable across architectures and can be challenging to manipulate.

---

### 1. _Array of Structures_

An **array of structures** is a collection of structures of the same type stored in contiguous memory locations, allowing you to manage multiple objects of the same kind easily.

#### Example

Consider a structure `Student` that holds information about students. An array of structures lets you store multiple students' data.

```c
#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float grade;
};

int main() {
    struct Student students[3] = {
        {101, "Alice", 89.5},
        {102, "Bob", 72.3},
        {103, "Charlie", 91.2}
    };

    for (int i = 0; i < 3; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    return 0;
}
```

---

### 2. _Arrays within Structures_

An **array within a structure** allows storing multiple elements of the same type within a single structure, ideal for attributes that contain multiple values (e.g., marks, address).

#### Example

Here, the `Student` structure contains an array to store marks in different subjects.

```c
#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float marks[3]; // array of marks for 3 subjects
};

int main() {
    struct Student s = {101, "Alice", {85.5, 92.0, 76.3}};
    printf("ID: %d, Name: %s\n", s.id, s.name);

    for (int i = 0; i < 3; i++) {
        printf("Mark in Subject %d: %.2f\n", i + 1, s.marks[i]);
    }

    return 0;
}
```

---

### 3. _Structures within Structures_

A **structure within a structure** is a way to nest structures, allowing complex data hierarchies.

#### Example

The `Student` structure has a nested structure `Address` to hold address details.

```c
#include <stdio.h>

struct Address {
    char city[20];
    int zip;
};

struct Student {
    int id;
    char name[20];
    struct Address address; // nested structure
};

int main() {
    struct Student s = {101, "Alice", {"New York", 10001}};
    printf("ID: %d, Name: %s\n", s.id, s.name);
    printf("City: %s, ZIP: %d\n", s.address.city, s.address.zip);

    return 0;
}
```

---

### 4. _Structures and Functions_

You can pass structures to functions by value or by reference (pointer) for processing data within functions.

#### Struct member as argument

```
Define Structure BIG
    int num
    string name

Main Program:
    init Struct myStruct num = 5, name = "Alice"
    Print "Before: num =", myStruct.num

    Call modifyNumber(myStruct.num)  // Pass only the num member

    Print "After: num =", myStruct.num  // Original num remains unchanged

Function modifyNumber(int num)
    Set num = num + 10
    Print "Inside modifyNumber: num =", num  // Change is local to the function
End Function
```

#### Pass by Value

```c
#include <stdio.h>

// Define a structure called BIG
struct BIG {
    int num;
};
// Function that takes a BIG structure by value and returns a BIG structure
struct BIG changestruct(struct BIG s) {
    s.num += 10;  // Modify the structure's num field
    return s;     // Return the modified structure
}
int main() {
    struct BIG myStruct = {5};  // Initialize myStruct with num = 5
    printf("Before: %d\n", myStruct.num);
    myStruct = changestruct(myStruct);  // Call the function, reassign to myStruct
    printf("After: %d\n", myStruct.num);
    return 0;
}
```

#### Pass by Reference

```c
#include <stdio.h>
// Define a structure called BIG
struct BIG {
    int num;
};
// Function that takes a pointer to a BIG structure (pass by reference)
void changestruct(struct BIG *s) {
    s->num += 10;  // Modify the original structure's num field directly
}
int main() {
    struct BIG myStruct = {5};  // Initialize myStruct with num = 5
    printf("Before: %d\n", myStruct.num);
    changestruct(&myStruct);  // Pass the address of myStruct
    printf("After: %d\n", myStruct.num);
    return 0;
}
```

---

### 5. _Self-Referential Structures_

A **self-referential structure** is a structure that contains a pointer to itself. This concept is commonly used in data structures like linked lists.

```c
struct node {
    int data1;            // Holds integer data
    char data2;           // Holds character data
    struct node* link;    // Pointer to another struct node (self-referential)
};
```

- **Definition**:
  - `data1`: stores an integer.
  - `data2`: stores a character.
  - `link`: a pointer of type `struct node *`, which points to another structure of the same type.

This structure is **self-referential** because it contains a pointer to an instance of itself, `struct node* link`. Self-referential structures are commonly used to create **linked data structures** like linked lists, stacks, or queues, where each element (node) can point to another element.

#### Example Usage of Self-Referential Structures (Linked List)

```c
struct node node1;
struct node node2;

node1.data1 = 5;
node1.data2 = 'A';
node1.link = &node2;    // node1 points to node2

node2.data1 = 10;
node2.data2 = 'B';
node2.link = NULL;       // End of the list
```

In this example:

- `node1` points to `node2` through its `link` member, creating a simple linked list with two nodes.
- `node2` has `link` set to `NULL`, indicating the end of the list.

---

(A program can we written to demonstrate these differences using: sizeof(), keywords, initializing errors, syntax)
![structs vs unions](https://github.com/user-attachments/assets/160802e0-dcba-4ff9-a583-a7f6e830f3a3)

### Pointer manipulation

```
ptr++; // Pointer moves to the next int position (as if it was an array)
++ptr; // Pointer moves to the next int position (as if it was an array)
++*ptr; // The value of ptr is incremented
++(*ptr); // The value of ptr is incremented
*ptr++; // Pointer moves to the next int position (as if it was an array). But returns the old content
(*ptr)++; // The value of ptr is incremented
*(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
*++ptr; // Pointer moves to the next int position, and then get's accessed, with your code, segfault
*(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault
```

### Incrementing and decrementing a pointer

```c
#include <stdio.h>
const int MAX = 3;
int main ()
{
int var[] = {10, 100, 200};
int i, *ptr; /* let us have array address in pointer */
ptr = &var[MAX-1]; //last elemnt
for ( i = MAX; i > 0; i--) //decrement
{
printf("Address of var[%d] = %x\n", i-1, ptr );
printf("Value of var[%d] = %d\n", i-1, *ptr ); /* move to the previous location */
ptr--; //move pointer to i-1
}
return 0;
}
```

---

### Types of pointers:

##### Pointer to a Constant (`const int* ptr`):

A pointer to a constant is a pointer that points to a value that cannot be modified through the pointer. The value being pointed to is constant, but the pointer itself can be changed to point to another memory location. For example:

```c
const int x = 10;
const int* ptr = &x; // ptr points to a constant integer
// *ptr = 20; // Error: Cannot modify the value through ptr
ptr = NULL; // Valid: The pointer itself can be changed
```

##### Pointer Constant (`int* const ptr`):

A pointer constant is a pointer whose address (the memory location it points to) cannot be changed. The value being pointed to can be modified, but the pointer itself cannot point to a different memory location. For example:

```c
int x = 10;
int* const ptr = &x; // ptr is a constant pointer to an integer
*ptr = 20; // Valid: The value being pointed to can be modified
// ptr = NULL; // Error: Cannot change the address the pointer points to
```

##### Null Pointer:

A null pointer is a pointer that is explicitly initialized to `NULL`. It does not point to any valid memory location and is often used to indicate that the pointer is not currently in use. For example:

```c
int* ptr = NULL; // ptr is a null pointer
if (ptr == NULL) {
    printf("Pointer is null\n");
}
```

##### Void Pointer (`void* ptr`):

A void pointer is a pointer that has no specific type associated with it. It can point to any data type, but it cannot be dereferenced directly. It must first be cast to a specific type. For example:

```c
int x = 10;
void* ptr = &x; // ptr is a void pointer pointing to an integer
int* intPtr = (int*)ptr; // Cast to int* before dereferencing
printf("%d\n", *intPtr); // Output: 10
```

##### Wild Pointer:

A wild pointer is a pointer that has not been initialized to any valid memory address or `NULL`. It points to a random memory location, which can lead to undefined behavior if dereferenced. For example:

```c
int* ptr; // ptr is a wild pointer (uninitialized)
// *ptr = 10; // Undefined behavior: ptr points to an unknown location
```

##### Dangling Pointer:

A dangling pointer is a pointer that points to a memory location that has been freed or deleted. Dereferencing a dangling pointer leads to undefined behavior. For example:

```c
int* ptr = (int*)malloc(sizeof(int)); // Dynamically allocate memory
*ptr = 10;
free(ptr); // Memory is freed
// ptr is now a dangling pointer
// *ptr = 20; // Undefined behavior: ptr points to freed memory
ptr = NULL; // Best practice: Set pointer to NULL after freeing memory
```

#### Pointer operations

##### 1. Function Returning a Pointer

```c
int* createInt(int value) {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = value;
    return ptr;
}

int main() {
    int* ptr = createInt(42);
    printf("Value: %d\n", *ptr); // Output: 42
    free(ptr);
    return 0;
}
```

##### 2. Pointer to a Function

```c
int add(int a, int b) { return a + b; }

int main() {
    int (*funcPtr)(int, int) = &add;
    printf("Result: %d\n", funcPtr(5, 3)); // Output: 8
    return 0;
}
```

##### 3. Pointers and Structures

```c
struct Point { int x; int y; };

int main() {
    struct Point p1 = {10, 20};
    struct Point* ptr = &p1;
    printf("x: %d, y: %d\n", ptr->x, ptr->y); // Output: x: 10, y: 20
    ptr->x = 30; ptr->y = 40;
    printf("x: %d, y: %d\n", ptr->x, ptr->y); // Output: x: 30, y: 40
    return 0;
}
```

##### 4. Array of Pointers

```c
int main() {
    int a = 10, b = 20, c = 30;
    int* arr[3] = {&a, &b, &c};
    for (int i = 0; i < 3; i++) {
        printf("Value %d: %d\n", i, *arr[i]);
    }
    // Output:
    // Value 0: 10
    // Value 1: 20
    // Value 2: 30
    return 0;
}
```

---

### Dynamic Memory Allocation in C

Dynamic memory allocation allows allocating memory during runtime. It enables handling memory more flexibly, especially useful when the memory requirement is unknown at compile time.

#### Advantages of Dynamic Memory Allocation:

- **Efficient Memory Use**: Memory can be allocated and deallocated as needed.
- **Flexibility**: Allows creating data structures like arrays and linked lists with varying sizes.
- **Memory Resizing**: Resizing is possible with `realloc` without recreating data structures.

#### Disadvantages:

- **Memory Management Complexity**: Developers need to manage memory manually, which can lead to memory leaks if `free` isn’t used.
- **Performance Overhead**: Dynamic allocation may be slower than stack allocation.

#### Functions in Dynamic Memory Allocation

In C, dynamic memory functions include:

- **`malloc`**: Allocates memory block of a specified size and returns a pointer to it. Memory isn’t initialized.
- **`calloc`**: Similar to `malloc`, but initializes memory to zero.
- **`free`**: Frees the allocated memory.
- **`realloc`**: Resizes previously allocated memory.

---

#### Example Programs for Each Dynamic Memory Allocation Function:

(Modify this based on required function lol)
**`DMA` Example**

```c
#include <stdio.h>
#include<stdlib.h>
int main() {
    // Write C code here
    printf("UwU\n");
    int n = 3;
    int *arr;
    arr = (int*)calloc(n,sizeof(int)); // Or (int*)malloc(n*sizeof(int))
    if (arr == NULL) {
        printf("Memory allocation failed");
    }
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("%d", arr[i]);
    }
    printf("\nNow realloc to 5: \n");
    n = 5;
    arr = (int*)realloc(arr, n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}
```

- `malloc` allocates memory for 5 integers. Each element is initialized, and memory is released with `free`.
- `calloc` allocates and initializes memory to zero for 5 integers. This differs from `malloc`, which leaves memory uninitialized.
- `realloc` resizes the memory block, allowing the array to hold additional elements without creating a new array
- `free` releases dynamically allocated memory, avoiding memory leaks.

---

### Command-Line Arguments

Command-line arguments allow passing parameters to `main` directly from the command line. They’re useful for configuring program behavior based on user input.

- **Syntax**: `int main(int argc, char *argv[])`
  - `argc` (argument count): Number of arguments, including the program name.
  - `argv` (argument vector): Array of argument strings.

#### Command-Line Arguments Example:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program Name: %s\n", argv[0]);

    if (argc < 2) { // Because first argument is always the executable file that contains the output binaries
        printf("No arguments passed\n");
    } else {
        for (int i = 1; i < argc; i++) {
            printf("Argument %d: %s\n", i, argv[i]);
        }
    }

    return 0;
}
```

- **Explanation**: This program prints each command-line argument. `argv[0]` is the program name, while `argv[1]`, `argv[2]`, etc., are additional arguments.

#### Output:

## ![Pasted image 20241111163119](https://github.com/user-attachments/assets/5c648cf1-eba6-4d47-8243-173f570f6ed4)

### File Management with Command-Line Arguments

File management in C allows working with files by opening, reading, writing, and closing them. Command-line arguments let users specify files dynamically.

#### Example: Copying Content from One File to Another

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // ./exe <srcfile> <destfile>
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
	 //Open source and dest files
    FILE *src = fopen(argv[1], "r");
    if (src == NULL) {
        printf("Failed to open source file\n");
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL) {
        printf("Failed to open destination file\n");
        fclose(src);
        return 1;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);  // Copy character from source to destination
    }

    printf("File copied successfully\n");

    fclose(src);
    fclose(dest);
    return 0;
}
```

- **Explanation**: The program takes two arguments (source and destination filenames) and copies the content of the source file to the destination file.

#### How it looks:

("touch" creates files, "echo" inputs string into file, "cat" outputs contents of file)
![Pasted image 20241111163614](https://github.com/user-attachments/assets/72834a02-3de4-42f7-a9f2-8f4ada7b7778)

### Misc:

#### Flowchart

![image](https://github.com/user-attachments/assets/1692a7e4-4cb6-4cd2-81eb-4bbf913dbefe)

#### String operations:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[] = "World";
    char str3[20];

    // strlen: Get length of str1
    printf("Length of str1: %zu\n", strlen(str1)); // Output: 5

    // strcat: Concatenate str2 to str1
    strcat(str1, " ");
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1); // Output: Hello World

    // strcmp: Compare str1 and str2
    strcpy(str3, "Hello World"); // Copy "Hello World" to str3
    if (strcmp(str1, str3) == 0) {
        printf("str1 and str3 are equal\n"); // Output: str1 and str3 are equal
    } else {
        printf("str1 and str3 are not equal\n");
    }

    return 0;
}
```

#### Dynamic memory allocation for struct

```c
// Dynamically allocate memory for an array of structures
    struct Person* persons = (struct Person*)malloc(n * sizeof(struct Person));
    if (persons == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
```
