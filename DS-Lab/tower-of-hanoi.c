//Program to solve Tower of Hanoi using recurssion
#include <stdio.h>
#include<stdlib.h>
void TOH (int n, char src, char dest, char temp) {
    if (n>0) {
        TOH(n-1, src, temp, dest);
        printf("Move disk %d from %c to %c\n", n,src, dest);
        TOH(n-1, temp, dest, src);
    }
    return;
}
int main() {
    int n;
    printf("Enter disk number: ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B');
    return 0;
}