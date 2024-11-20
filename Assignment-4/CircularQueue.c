#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct CircularQueue{
    int queue[max];
    int front;
    int rear;
} cq ;

void initialize(cq *q){
    q->front=-1;
    q->rear=-1;
}


int isFull(cq *q){
    if((q->front==0 && q->rear==max-1) || (q->rear==(q->front-1)%(max-1))){
return 1;
    }
    return 0;
}


int isEmpty(cq *q){
    if(q->front==-1){
        return 1;
    }
    return 0;
}

void enqueue(cq *q,int value){
    if(isFull(q)){
        printf("Queue is Full!,Cann't enqueue\n");
        return ;
    }
    if(q->front==-1){
        q->front=0;
    }

    q->rear=(q->rear+1)%max;
    q->queue[q->rear]=value;
    printf("enqueued: %d\n",value);
}

void dequeue(cq *q){
    if(isEmpty(q)){
        printf("Queue is empty! cann't dequeue\n");
        return;
    }

    int data=q->queue[q->front];
    printf("Dequeued: %d\n",data);

    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        q->front=(q->front+1)%max;
    }
}

void display(cq *q){
     if(isEmpty(q)){
        printf("Queue is empty! cann't dequeue\n");
        return;
    }
    
    printf("Queue element are: ");
    int i=q->front;
    while(i!=q->rear){
        printf("%d\t",q->queue[i]);
        i=(i+1)%max;
    }
    printf("%d\t",q->queue[q->rear]);
}

// Main function
   int main (){
    struct CircularQueue q;
    initialize(&q);
    int choice,value;

    while(1){
        printf("Circular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
    case 1: printf("Enter value to enqueue:");
            scanf("%d",&value);
            enqueue(&q,value);
            break;

    case 2: dequeue(&q);
            break;   

    case 3: display(&q);
            break;

    default:
    printf("Invalid choice! please enter again\n");

        }
    }
    return 0;
}

