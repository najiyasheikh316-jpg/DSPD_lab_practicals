//Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
//a. Insert an Element on to QUEUE
//b. Delete an Element from QUEUE
//c. Demonstrate Overflow and Underflow situations on QUEUE
//d. Display the status of QUEUE
//e. Exit
//Support the program with appropriate functions for each of the above operations.




#include <stdio.h>
#include <stdlib.h>
#define MAX 10  

char queue[MAX];
int front = -1, rear = -1;


int isFull() {
    return rear == MAX - 1;
}


int isEmpty() {
    return (front == -1 || front > rear);
}

// Insert element into queue
void insert(char element) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert '%c'\n", element);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = element;
        printf("\n'%c' inserted into Queue.\n", element);
    }
}

// Delete element from queue
void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Nothing to delete.\n");
    } else {
        printf("\n'%c' deleted from Queue.\n", queue[front]);
        front++;
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nCurrent Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

//  overflow and underflow
void demoOverflowUnderflow() {
    printf("\n--- Overflow Demonstration ---\n");
    rear = MAX - 1;
    insert('X'); 

    printf("\n--- Underflow Demonstration ---\n");
    front = rear = -1;
    delete(); 
}


int main() {
    int choice;
    char element;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow/Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;

            case 2:
                delete();
                break;

            case 3:
                demoOverflowUnderflow();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
