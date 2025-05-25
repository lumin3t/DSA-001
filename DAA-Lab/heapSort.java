import java.util.*;
class HeapSort {
    public static void heapSort (int[] arr) {
        //from last non leaf node call heapify upwards
        int n = arr.length;
        for (int i = n/2-1; i>=0; i--) {
            heapify(arr, n, i);
        }
        //extract each element part 
        int temp;
        for (int i = n-1; i>=0; i--) {
            //swap largest to end
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify (arr, i, 0);
        }
    }
    public static void heapify (int[] arr, int n, int i) {
        //left, right and largest 
        int largest = i; //init root as largest
        int left = 2*i + 1;
        int right = 2*i + 2;
        //find largest child from left and right
        if (left<n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right<n && arr[right] > arr[largest]) {
            largest = right;
        }
        //if root not largest 
        int temp;
        if (largest != i) {
            //swap 
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            //affected subtree
            heapify (arr, n, largest);
        }
    }
    public static void main(String[] args) {
           Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];
        System.out.println("Enter the elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Original array: " + Arrays.toString(arr));

        long startTime = System.nanoTime();
        heapSort(arr);
        long endTime = System.nanoTime();

        System.out.println("Sorted array: " + Arrays.toString(arr));

        long duration = endTime - startTime;
        System.out.println("Time taken for sorting: " + duration + " nanoseconds");
        scanner.close(); 
    }
}
