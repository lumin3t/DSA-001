#include <stdio.h>
int main () {
    printf("uWu \n");
    int i, a1[10], j, cnt=0;
    int n = 3;
    int a[3] = { 11, 20, 30 }; //assumed
    for (i=0; i<10; i++) {
        a1[i] = -1;
    }
    for(i=0; i<10; i++) {
        printf("%d ", a1[i]);
    }
    for (i=0; i<n; i++) {
        int result = a[i]%10;
        if (a1[result] == -1) {
            a1[result] = a[i];
            printf("%d stored at a1[%d]\n", a[i], result);
        } else {
            j = result + 1;
            while(1) {
                if (j>9) { //wrap
                    j = 0;
                }
                 if (a1[j] == -1) {
                    a1[j] = a[i];
                    printf("%d stored at a1[%d]", a[i], j);
                    break;
                }
                cnt++;
                if(cnt>=n) {
                    break;
                }
                j++;
            }
        }
    }
    printf("Hash table: ");
    for(i=0; i<n; i++) {
        if(a1[i] != -1) {
            printf("%d ", a1[i]);
        }
    }
    return 0;
}