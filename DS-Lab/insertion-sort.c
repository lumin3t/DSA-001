#include<stdio.h>
int main () {
    //Insertion sort 
    int i,j,k;
    int a[6] = {1, 7, 3, 9, 2, 5}; //Assumed
    for (i=1; i<6; i++) { //i<size, start with i=1 assuming first element is already sorted
        k = a[i];
        for (j=i-1; j>=0 && k<a[j]; j--) { //Compare all elemnts before a[i] to it
            a[j+1]=a[j]; //Swap prev greater element with k
        }
        a[j+1]=k; //Assign value of j+1 to k
    }
    printf("Sorted array: ");
    for (i=0; i<6; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}