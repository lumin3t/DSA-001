import java.util.*;

class MergeSort {
    public static void mergeSort (int[] array, int left, int right) {
        //recursive condn 
        if (left<right) {
            //calc mid
            int mid = left + (right-left)/2;
            mergeSort(array, left, mid);
            mergeSort(array, mid+1, right);
            merge(array, left, mid, right);
        }
        //sort left, right, merge 
    }
    public static void merge (int[] array, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        //new left and right arrays
        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];
        
        for (int i = 0; i< n1; i++) {
            leftArray[i] = array[left+i];
        }
        for (int j =0; j<n2; j++) {
            rightArray[j] = array[mid+1+j];
        }
        int i=0, j=0, k=left;
        //merge em condn based
        while (i<n1 && j<n2) {
            if (leftArray[i] <= rightArray[j]) {
                array[k++] = leftArray[i++];
            } else {
                array[k++] = rightArray[j++];
            }
        }
        //add remaining 
        while (i<n1) {
            array[k++] = leftArray[i++];
        }
        while(j<n2) {
            array[k++] = rightArray[j++];
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        //number of times
        System.out.println("Enter the number of times it should execute: ");
        int times = scanner.nextInt();
        System.out.println("Enter the number of elements in array each time: ");
        int n = scanner.nextInt();
        //number of elements 
        // for each time
        double totalTime = 0;
        for (int a=0; a<times; a++) {
            int[] array = new int[n];
            for (int b=0; b<n; b++) {
                array[b] = random.nextInt(100);
            }
            System.out.println("Run #"+ times);
            System.out.println("Original Array: "+ Arrays.toString(array));
            double startTime = System.nanoTime();
            mergeSort(array, 0, n-1);
            double endTime = System.nanoTime();
            double duration = startTime-endTime;
            totalTime += duration;
            System.out.println("Sorted Array: "+ Arrays.toString(array));
            System.out.println("Time taken: "+ duration+ " ns");
            System.out.println("---------------------------");
        }
        //each time array of random numbers sort it add to duration
        double avgTime = totalTime/times;
        System.out.println("Average time: "+ avgTime+ "ns");
        System.out.println("In ms: "+ avgTime/1_000_000+ "ms");
	scanner.close();
    }
}
