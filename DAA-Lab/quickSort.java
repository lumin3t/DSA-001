import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int s = partition(arr, low, high);
            quickSort(arr, low, s - 1);
            quickSort(arr, s + 1, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (i <= high && arr[i] <= pivot);
            do {
                j--;
            } while (j >= low && arr[j] > pivot);
            if (i >= j)
                break;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        // Swap pivot into correct position
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        return j;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in Array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter elements: ");
        for (int k = 0; k < n; k++) {
            arr[k] = sc.nextInt();
        }

        System.out.println("Original Array = " + Arrays.toString(arr));

        long startTime = System.nanoTime();
        quickSort(arr, 0, n - 1);
        long endTime = System.nanoTime();

        System.out.println("Sorted Array = " + Arrays.toString(arr));
        System.out.println("Time taken: " + (endTime - startTime) + " nanoseconds");
        sc.close();
    }
}
