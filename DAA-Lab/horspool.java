import java.util.*;

class Horspool {
    public static int[] shiftTable (String pattern) {
        //table of 256
        int[] table = new int[256];
        int m = pattern.length();
        //init m for all
        for (int i=0; i<256; i++) {
            table[i] = m;
        }
        for (int i=0; i<m-1; i++) {
            table[pattern.charAt(i)] = m-1-i;
        }
        return table;
        //till m-1 for ones in pattern 
    }
    public static int horspoolSearch (String pattern, String text) {
        //basic condn
        int n = text.length();
        int m = pattern.length();
        if (m>n) {
            return -1;
        }
        //get table
        int[] table = shiftTable(pattern);
        //while loop, compare two
        int i = m-1; // we working in terms of indices
        while (i<n) {
            int k=0;
            while(k < m && pattern.charAt(m-1-k) == text.charAt(i-k)) {
                k++;
            }
            if (k == m) {
                return i-m+1;
            } else {
                i+= table[text.charAt(i)];
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter text: ");
        String text = scanner.nextLine();
        System.out.println("Enter pattern: ");
        String pattern = scanner.nextLine();
        long startTime = System.nanoTime();
        int index = horspoolSearch(pattern, text);
        long endTime = System.nanoTime();
        if (index != -1) {
            System.out.println("Found from index "+ index);
        } else {
            System.out.println("Pattern not found L");
        }
        
        double timeElapsed = (endTime - startTime) / 1_000_000.0;
        System.out.println("Time taken: " + timeElapsed + " milliseconds");
        scanner.close();
    }
}
