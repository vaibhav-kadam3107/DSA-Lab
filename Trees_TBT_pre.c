#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the threaded binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
    int isThreaded;
};

// Create a new node with the given data value
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Insert a new node into the TBT
void insert(struct node **root, int data) {
    printf("Inserting %d\n", data);
    struct node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        struct node *current = *root;
        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    newNode->right = current;
                    newNode->isThreaded = 1;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->isThreaded || current->right == NULL) {
                    newNode->left = current;
                    newNode->right = current->right;
                    current->right = newNode;
                    current->isThreaded = 0;
                    newNode->isThreaded = 1;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Get the inorder successor of a node in the TBT
struct node *getInorderSuccessor(struct node *current) {
    if (current->isThreaded) {
        return current->right;
    } else {
        current = current->right;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
}

// Perform pre-order traversal of the TBT
void preorderTraversal(struct node *root) {
    struct node *current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->left != NULL) {
            current = current->left;
        } else if (current->isThreaded) {
            current = current->right;
        } else {
            current = getInorderSuccessor(current);
        }
    }
}

// Perform in-order traversal of the TBT
void inorderTraversal(struct node *root) {
    struct node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->isThreaded) {
            current = current->right;
        } else {
            current = getInorderSuccessor(current);
        }
    }
}

// Main function to test the threaded binary tree and traversals
int main() {
    struct node *root = NULL;

    // Insert nodes into the threaded binary tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Traverse the threaded binary tree in inorder and preorder ways
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
