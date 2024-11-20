#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    
};

struct Node* createNode(int data)
{
    struct Node *n;//creating a node pointer
    n=(struct Node*)malloc(sizeof(struct Node));//allocating memory
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//............................................PreOrder............................

void preOrder(struct Node* root)
{
 if(root!=NULL)
 {
    //preOrder: root->left->right
    printf("%d\t",root->data);
    preOrder(root->left);
    preOrder(root->right);
 }
}

//.............................................InOrder.................................

void inOrder(struct Node* root)
{
 if(root!=NULL)
 {
    //preOrder:left-> root->right
    inOrder(root->left);
    printf("%d\t",root->data);
    inOrder(root->right);
 }
}


//.............................................PostOrder.................................

void postOrder(struct Node* root)
{
 if(root!=NULL)
 {
    //preOrder:left->right->root
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t",root->data);
 }
}

int main ()
{

// struct Node *p;
// p=(struct Node*)malloc(sizeof(struct Node));

//trees
        //        4
        //       / \ 
        //      1   6
        //     / \ 
        //    5   2

struct Node *p=createNode(4);
struct Node *p1=createNode(1);
struct Node *p2=createNode(6);
struct Node *p3=createNode(5);
struct Node *p4=createNode(2);



//Linking the root node with children
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;

preOrder(p);
// inOrder(p);
// postOrder(p);


    return 0;
}