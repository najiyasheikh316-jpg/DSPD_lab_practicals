#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int num, count = 0;

    printf("Enter integers to add to the linked list (0 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;

        // new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        // Insert node at the end
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        count++;
    }

    // Display 
    printf("\nLinked List Elements:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nTotal number of nodes: %d\n", count);

    return 0;
}
