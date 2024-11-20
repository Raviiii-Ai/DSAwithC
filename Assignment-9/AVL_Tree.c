#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // height at leaf
    return newNode;
}

// Function to get the height of the node
int height(struct Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the balance factor of the node
int BalanceFactor(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Utility function to get maximum of two integers
int max(int a, int b){ 
    if (a > b)
        { 
        return a;
         }
    else { 
        return b;
         }
}

// Right rotate subtree rooted with y

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* z = x->right;

    // Perform rotation
    x->right = y;
    y->left = z;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* z = y->left;

    // Perform rotation
    y->left = x;
    x->right = z;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}



//  insert a node and check the tree balanced
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else 
        return node;

    node->height = 1 + max(height(node->left), height(node->right));


    int balance = BalanceFactor(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

//  inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

//  input from the user
void takeInput(struct Node** root) {
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        *root = insertNode(*root, data);
    }
}

int main() {
    struct Node* root = NULL;

    takeInput(&root);

    printf("Inorder traversal of the AVL Tree:\n");
    inorderTraversal(root);
    
    return 0;
}