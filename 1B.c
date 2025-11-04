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

