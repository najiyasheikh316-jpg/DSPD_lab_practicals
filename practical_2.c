#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10  

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}


int isEmpty() {
    return top == -1;
}

// Push operation
void push(int value) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("\n%d pushed onto stack.\n", value);
    }
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Nothing to pop.\n");
    } else {
        printf("\n%d popped from stack.\n", stack[top--]);
    }
}

// Display the stack
void display() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nCurrent Stack:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

// Check palindrome using stack
void checkPalindrome() {
    char str[50];
    int len, i, flag = 1;
    top = -1;  

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);

    
    for (i = 0; i < len; i++)
        push(str[i]);

    
    for (i = 0; i < len; i++) {
        if (str[i] != stack[top--]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("\n'%s' is a Palindrome.\n", str);
    else
        printf("\n'%s' is NOT a Palindrome.\n", str);
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Demonstrate Overflow/Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                printf("\n--- Overflow Demonstration ---\n");
                top = MAX - 1;
                push(100);
                printf("\n--- Underflow Demonstration ---\n");
                top = -1;
                pop(); 
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
