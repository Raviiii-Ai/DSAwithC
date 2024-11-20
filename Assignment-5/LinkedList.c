#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
     struct Node* next;

};

//creation a linked list
struct Node* creationNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
}



//linked list structure
struct List{
   struct Node* head;
   struct Node* tail;
};

//initialize values
void valList(struct List* list){
    list->head=NULL;
    list->tail=NULL;
}


//push front
void push_front(struct List* list,int val){
    struct Node* newNode=creationNode(val);

    if(list->head==NULL){
        list->head=list->tail=newNode;
    }else{
        newNode->next=list->head;
        list->head=newNode;
    }
}

//push_back
void push_back(struct List* list,int val){
    struct Node* newNode=creationNode(val);

    if(list->head==NULL){
        list->head=list->tail=newNode;
    }else{
        list->tail->next=newNode;
        list->tail=newNode;
    }
}

void printList(struct List* list){
    struct Node* temp=list->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert(struct List* list,int val,int pos){
    struct Node* newNode=creationNode(val);
    struct Node* temp=list->head;

    if(pos==0){
        push_front(list,val);
        return;
    }

    for(int i=0;i<pos-1;i++){
        if(temp==NULL){
            printf("Position is Invalid\n");
            return;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}


int main (){
    struct List ll;
    valList(&ll);
    int choice,value,pos;

    while(1){
        printf("Choose an Option: \n");
        printf("1: Push Front\n");
        printf("2: Push Back\n");
        printf("3: Insert at Position\n");
        printf("4: Print List\n");

        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter value to push front: ");
            scanf("%d",&value);
            push_front(&ll,value);
            break;

            case 2: printf("Enter value to push back: ");
            scanf("%d",&value);
            push_back(&ll,value);
            break;

            case 3: printf("Enter value and position to insert :");
            scanf("%d %d",& value,&pos);
            insert(&ll,value,pos);
            break;

            case 4: printList(&ll);
            break;

            default: printf("Invalid choice! Try again.....\n");

        }
    }
    return 0;
}