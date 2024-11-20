#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node *node;
    node=(struct Node*)malloc(sizeof(struct Node));//allocating memory
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


//.............................................Insert Node................................
struct Node* insertNode(struct Node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }

    if(data<root->data)
    {
        root->left=insertNode(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insertNode(root->right,data);
    }

    return root;

}

//Find the inorder predecessor
struct Node* predecessor(struct Node*root)
{
root=root->left;
while(root->right!=NULL)
{
    root=root->right;
}
return root;
}


//..........................delete Node in BST...........................
struct Node *deleteNode(struct Node* root,int value)
{
    //baseCase
    if(root==NULL)
    {
        return NULL;
    }

    //leaf NOde
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }

    //search for the node to be deleted
    if(value<root->data)
    {
        //Searching left subtree
        root->left=deleteNode(root->left,value);

    }
     // Searching right

    else if(value>root->data)
    {
        //right Subtree
        root->right=deleteNode(root->right,value);
    }
    else{
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct Node* inPre = predecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
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


#include<stdio.h>

int main () {
    struct Node* root=NULL;
    int choice,value;

    while(1)
    {
        printf("Binary Search Tree Operations\n");
        printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf(" Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter value to insert: ");
            scanf("%d",&value);
            root=insertNode(root,value);
            break;

            case 2: printf("Enter value to delete: ");
            scanf("%d",&value);
            root=deleteNode(root,value);
            break;

            case 3: printf("Inorder Traversal: ");
            inOrder(root);
            printf("\n");
            break;

            case 4: exit(0);

            default: printf("Invalid choice\n");
        }      
    }   
return 0;
}
