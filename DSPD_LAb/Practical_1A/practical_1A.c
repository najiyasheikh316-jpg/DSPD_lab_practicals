
//Write a program to accept ‘n’ numbers into an array and then calculate the sum of numbers present in odd positions and even positions respectively.




#include <stdio.h>

int main() {
    int n, i, evenSum = 0, oddSum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if((i + 1) % 2 == 0)
            evenSum += arr[i];
        else
            oddSum += arr[i];
    }
    
    printf("\nSum of elements at odd positions: %d", oddSum);
    printf("\nSum of elements at even positions: %d\n", evenSum);
    return 0;
}
