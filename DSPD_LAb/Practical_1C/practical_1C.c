//write a program which creates a structure Student which must have the attribute Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort.
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    int age;
    float avgMarks;
};

void bubbleSort(struct Student s[], int n) {
    int i, j;
    struct Student temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(s[j].avgMarks < s[j+1].avgMarks) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Age: ");
        scanf("%d", &s[i].age);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    bubbleSort(s, n);

    printf("\nStudents sorted in descending order of Average Marks:\n");
    printf("------------------------------------------------------\n");
    printf("Name\tRollNo\tAge\tAvgMarks\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%.2f\n", s[i].name, s[i].rollNo, s[i].age, s[i].avgMarks);
    }

    return 0;
}
