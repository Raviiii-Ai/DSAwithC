#include<stdio.h>
#include<malloc.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* queueNode = (struct Node*)malloc(sizeof(struct Node));
    queueNode->data = data;
    queueNode->next = NULL;
    return queueNode;
}

int isEmpty(struct Node* front) {
    return (front == NULL);
}

//....................................Enqueue....................................................................
struct Node* enqueue(struct Node* rear, int data) {
    struct Node* queueNode = newNode(data);
    if (rear == NULL) {
        rear = queueNode;
    } else {
        rear->next = queueNode;
        rear = queueNode;
    }
    printf("%d enqueued to queue\n", data);
    return rear;
}

//....................................Dequeue.......................................................................
struct Node* dequeue(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue underflow\n");
        return front;
    }
    struct Node* temp = front;
    printf("%d dequeued from queue\n", front->data);
    front = front->next;
    free(temp);
    return front;
}

//....................................peek...........................................................................
int peek(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main ()
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;


    while(1) {
          printf("Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display queue\n");
   
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
  

        switch(choice) {
            case 1: 
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (isEmpty(front)) {
                    front = enqueue(front, value);
                    rear = front; 
                } else {
                    rear = enqueue(rear, value);
                }
                display(front);
                break;

            case 2: 
                if (!isEmpty(front)) {
                    front = dequeue(front);
                    if (front == NULL) {  
                        rear = NULL;
                    }
                } else {
                    printf("Queue is already empty\n");
                }
                display(front);
                break;

            case 3: 
                value = peek(front);
                if (value != -1)
                    printf("Front element is %d\n", value);
                display(front);
                break;

            case 4: 
                display(front);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

}