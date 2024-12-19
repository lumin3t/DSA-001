#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fout1, *fout2, *fout3, *fin1, *fin2, *fin3;
    char data1[30], data2[30], ch1, ch2, ch3;
    
    fout1 = fopen("file1.txt", "w");
    fout2 = fopen("file2.txt", "w");
    if (fout1 == NULL) {
        printf("Could not open file1\n");
        exit(0);
    }
    if (fout2 == NULL) {
        printf("Could not open file2\n");
        exit(0);
    }
    printf("Enter content for file1:\n");
    fgets(data1, sizeof(data1), stdin);  // Use fgets to prevent buffer overflow
    printf("Enter content for file2:\n");
    fgets(data2, sizeof(data2), stdin);  // Use gets(data) for old and rusty compilers

    fprintf(fout1, "%s", data1);
    fprintf(fout2, "%s", data2);
    
    fclose(fout1);
    fclose(fout2);

    fin1 = fopen("file1.txt", "r");
    fin2 = fopen("file2.txt", "r");
    fout3 = fopen("file3.txt", "w");  // Ensure the output file has a consistent extension

    if (fin1 == NULL) {
        printf("Could not read from file1\n");
        exit(0);
    }
    if (fin2 == NULL) {
        printf("Could not read from file2\n");
        exit(0);
    }
    if (fout3 == NULL) {
        printf("Could not open file3\n");
        exit(0);
    }

    ch1 = getc(fin1);
    ch2 = getc(fin2);

    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) {
            fputc(ch2, fout3);  // Write the differing character from file2
        }
        ch1 = getc(fin1);
        ch2 = getc(fin2);
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout3);

    fin3 = fopen("file3.txt", "r");  // Read from file3.txt (consistent with earlier)
    
    if (fin3 == NULL) {
        printf("Could not read from file3\n");
        exit(0);
    }
    ch3 = getc(fin3);

    if (ch3 == EOF) {
        printf("No difference between file1 and file2\n");
        exit(0);
    }
    printf("Differences between file1 and file2 are:\n");
    while (ch3 != EOF) {
        printf("%c", ch3);
        ch3 = getc(fin3);
    }
    fclose(fin3);
    return 0;
}
