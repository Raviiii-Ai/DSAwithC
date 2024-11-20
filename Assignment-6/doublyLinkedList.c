#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void insertAtPosition(Node** head, int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}


void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}


void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    Node* temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    Node* temp = *head;

    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printList(head);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printList(head);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                printList(head);
                break;

            case 4:
                deleteAtBeginning(&head);
                printList(head);
                break;

            case 5:
                deleteAtEnd(&head);
                printList(head);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                printList(head);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
