//Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 //implement the following algorithm: 
//Examine the value in the middle of the current array and print it. 
//If the midpoint value is the value that we are looking for, return true 
//If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
//if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
//Continue until you find the value, or until the start reaches the end, 





#include <stdio.h>

int binarySearch(int searchList[], int size, int key) {
    if (searchList == NULL || size == 0) {
        return -1;  // NULL equivalent for integer return
    }

    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Examining value: %d (at index %d)\n", searchList[mid], mid);

        if (searchList[mid] == key) {
            printf("Value found at index %d.\n", mid);
            return mid;  // Found
        }
        else if (key > searchList[mid]) {
            printf("Searching right half, adjusting start to index %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Searching left half, adjusting end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found in list.\n");
    return -1;  // Not found
}

int main() {
    int searchList[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(searchList) / sizeof(searchList[0]);
    int key;

    printf("Enter value to search: ");
    scanf("%d", &key);

    int result = binarySearch(searchList, size, key);

    if (result == -1)
        printf("Result: NULL (value not found)\n");
    else
        printf("Result: Found at index %d\n", result);

    return 0;
}

