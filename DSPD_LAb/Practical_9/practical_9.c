//Assume that you have a seven-slot closed hash table (the slots are numbered o through 6) Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.

#include <stdio.h>

#define SIZE 7

int main() {
    int hashTable[SIZE];
    int i, key, n, index;

    // Initialize hash table with -1 (empty)
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;

        // Linear probing
        while (hashTable[index] != -1)
            index = (index + 1) % SIZE;

        hashTable[index] = key;
    }

    printf("\nFinal Hash Table (index : key):\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("%d : %d\n", i, hashTable[i]);
        else
            printf("%d : ---\n", i);
    }

    return 0;
}
