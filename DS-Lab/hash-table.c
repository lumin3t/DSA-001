#include <stdio.h>
int main() {
    int a[20], a1[10] = {0}, result, n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
   printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // Hash table 
    for (i = 0; i < n; i++) {
        result = a[i] % 10; // Get the last digit of entered element
        a1[result] = a[i]; // a1 array contains elements at the index of the digit
        printf("%d is stored at position a1[%d]\n", a[i], result);
    }
    printf("Hash table: ");
    for (int j = 0; j < 10; j++) { // Print the hash table
        if (a1[j] != 0) {
            printf("%d ", a1[j]);
        }
    }
    printf("\n"); // New line for better output formatting
    return 0;
}
