#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* stackNode = (struct Node*)malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}


int isEmpty(struct Node* top) {
    return !top;
}

struct Node* push(struct Node* top, int data) {
    struct Node* stackNode = newNode(data);
    stackNode->next = top;
    top = stackNode;
    printf("%d pushed to stack\n", data);
    return top;
}


struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        return top;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
    return top;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;
    while(1) {
        
    printf("Stack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display stack\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value); 
                display(top); 
                break;

            case 2: // Pop
                top = pop(top); 
                display(top); 
                break;

            case 3: // Peek
                value = peek(top);
                if (value != -1)
                    printf("Top element is %d\n", value);
                display(top);
                break;

            case 4: // Display stack
                display(top);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}