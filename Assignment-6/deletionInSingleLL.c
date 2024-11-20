#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void beg_insert(Node** head, int key) {
    Node* newNode = createNode(key);
    newNode->next = *head;  
    *head = newNode;        
}

// Function to delete a node at the beginning
void begin_delete(Node** head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void end_delete(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    
    // Traverse to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    if (prev != NULL) {
        prev->next = NULL;  // Second last node becomes the last node
    } else {
        *head = NULL;  // If there's only one node
    }
    
    free(temp);
}

// Function to delete a node at a random position
void delete_random(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;
    
    if (pos == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position not valid\n");
        return;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, key, pos;

    while (1) {
        printf("Choose an Option:\n");
        printf("1: Insert at beginning\n");
        printf("2: Deletion at beginning\n");
        printf("3: Deletion at end\n");
        printf("4: Deletion at specific position\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                beg_insert(&head, key);
                  print(head);
                break;

            case 2:
                begin_delete(&head);
                  print(head);
                break;

            case 3:
                end_delete(&head);
                  print(head);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_random(&head, pos);
                  print(head);
                break;

            default:
                printf("Invalid choice! Try again...\n");
        }
    }

    return 0;
}
