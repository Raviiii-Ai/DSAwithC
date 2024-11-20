#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}


void enqueue(struct Node** head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

 
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
       
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d with priority %d\n", data, priority);
}

// Function to dequeue the highest priority element
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    struct Node* temp = *head;
    printf("Dequeued %d with priority %d\n", temp->data, temp->priority);
    *head = (*head)->next;
    free(temp);
}

// Function to display the elements in the priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Priority Queue:\n");
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    struct Node* pq = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;

            case 2:
                dequeue(&pq);
                break;

            case 3:
                display(pq);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
