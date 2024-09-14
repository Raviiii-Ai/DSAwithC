#include<stdio.h>
int stack[100],n,top,choice=0;//global variable

void push(){
   
    if(top==n-1){
        printf("Overflow!");
    }
    else{
         int value;
        printf("Enter value which you want to push in stack:");
        scanf("%d",&value);
        top=top+1;
        stack[top]=value;
        printf("%d\n",stack[top]);


    }
}

void pop(){
    if(top==-1){
        printf("underflow!");
    }
    else{
        printf("%d\n",top);
        top=top-1;
        
    }
}

void peep(){
    if(top==-1){
        printf("Stack is empty,nothing to peep\n");

    }
    else{
        printf("Top element is %d\n",stack[top]);
    }
}

void show(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{

    
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
    }
    

}

int main (){
    top=-1;
    printf("Enter the no of element in stack:");
    scanf("%d",&n);

    printf(".........Stack operation using Array...........\n");

   while(choice!=5){
    printf("Enter your choice:");
    scanf("%d",&choice);


    switch(choice){
        case 1:push();
        break;

        case 2:pop();
        break;

        case 3:peep();
        break;

        case 4:show();
        break;

        default:
        printf("Please enter default choice!");
            
    };
   }



    return 0;
}