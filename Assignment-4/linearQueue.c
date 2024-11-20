#include<stdio.h>
#include<stdlib.h>

#define max 100

int queue[max];
int front =-1;
int rear=-1;

int isFull(){
    return rear==max-1;
}

int isEmpty(){
    return (front==-1 || front>rear);
}

void enqueue(int value){
    if(isFull()){
        printf("Queue is Full! cann't do enqueue operation\n");
        return ;
    }
    if(front==-1){
        front=0;
        }
        
        rear++;
        queue[rear]=value;
        printf("enqueued %d\n",value);

}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty! Cann't dequeue\n");
        return;
    }
    printf("Dequeued %d\n",queue[front]);
    front++;

    if(front>rear){
        front=rear=-1;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return 0;
    }
    printf("Queue elements: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main (){
    int choice,value;

    while(1){
        printf("Linear Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
    case 1: printf("Enter value to enqueue:");
            scanf("%d",&value);
            enqueue(value);
            break;

    case 2: dequeue();
            break;   

    case 3: display();
            break;

    default:
    printf("Invalid choice! please enter again\n");

        }
    }
    return 0;
}