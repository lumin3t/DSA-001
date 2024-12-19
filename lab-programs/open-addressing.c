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
        result = a[i] % 10;  // Hash function
        if(a1[result] == -1) { //if empty
            a1[result] = a[i];
            printf("Location: a1[%d], Value: %d\n", result, a1[result]);
        } else {
            // Collision handling
            j = result + 1;  // Start from the next index
            while(1) {
                if(a1[j] == -1) {  // Check if the slot is empty
                    a1[j] = a[i];
                    printf("Location: a1[%d], Value: %d\n", j, a1[j]);
                    break;
                }
                if(j > 9) {  // Wrap arpund
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
        if(a1[i] != -1) {  // Print only the filled slots
            printf("%d ", a1[i]);
        }
    }
    return 0;
}
