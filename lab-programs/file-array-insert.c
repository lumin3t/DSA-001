#include <stdio.h>
#include <stdlib.h>

struct student {
    int regno;
    char name[20];
};

void main() {
    struct student stud[20], temp;
    FILE *fout, *fin;
    int i, n;

    fout = fopen("student.dat", "wb");  // Open in binary write mode
    if (fout == NULL) {
        printf("Error, could not open file....\n");
        exit(0);
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("For student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", stud[i].name);
        printf("Register no: ");
        scanf("%d", &stud[i].regno);
    }

    fwrite(stud, sizeof(struct student), n, fout);
    fclose(fout);

    fin = fopen("student.dat", "rb");  // Open in binary read mode
    if (fin == NULL) {
        printf("Error, could not read from file....\n");
        exit(0);
    }

    printf("\nData read from file is as follows:\n");
    while (fread(&temp, sizeof(struct student), 1, fin)) {
        printf("Name: %s\n", temp.name);
        printf("Reg No: %d\n\n", temp.regno);
    }

    fclose(fin);
}
