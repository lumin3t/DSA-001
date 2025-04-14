
#### Selection sort 
```java
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        final int n = 3;
        int i, min, j;
        int[] A = {3, 1, 2};
        
        System.out.print("Unsorted: ");
        System.out.println(Arrays.toString(A));
        
        for (i = 0; i <= n - 2; i++) {
            min = i;
            for (j = i + 1; j <= n-1; j++) {
                if (A[j] < A[min]) {
                    min = j;
                }
            }
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
        
        System.out.print("Sorted: ");
        System.out.println(Arrays.toString(A));
    }
}
```

O(n^2)

#### Binary search 
```java
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        System.out.println("Binary search for key 3");
        int[] A = {0,1,2,3,4,5}; 
        int key = 9;
        boolean found = false;
        int high = A.length-1;
        int low = 0;
        int mid;
        
        while (low <= high) {  // Changed from for loop to while
            mid = (low + high) / 2;
            if (A[mid] == key) {
                System.out.println("Found at index "+ mid);
                found = true;
                break;
            } else if (A[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (!found) {  // Fixed assignment (=) to comparison (==)
            System.out.println("Not found bruh");
        }
    }
}
```

O(logn)
