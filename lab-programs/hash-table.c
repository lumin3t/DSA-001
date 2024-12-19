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