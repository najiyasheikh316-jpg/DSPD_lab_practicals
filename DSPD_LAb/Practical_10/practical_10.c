//Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file. This program will read data from one file and copy them to another. The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt"). Once the two file names have been obtained, the program must open the input file and create and open the output file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char source[50], destination[50];
    char ch;

    printf("Enter source file name (e.g., input.txt): ");
    scanf("%s", source);

    printf("Enter destination file name (e.g., output.txt): ");
    scanf("%s", destination);

    
    fp1 = fopen(source, "r");
    if (fp1 == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(1);
    }

    
    fp2 = fopen(destination, "w");
    if (fp2 == NULL) {
        printf("Error: Cannot create destination file.\n");
        fclose(fp1);
        exit(1);
    }


    while ((ch = fgetc(fp1)) != EOF)
        fputc(ch, fp2);

    printf("File copied successfully from %s to %s.\n", source, destination);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
