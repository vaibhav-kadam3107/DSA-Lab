#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node * insert(struct node *root , int data){
    if(root == NULL)
        root = createNode(data);

    else if (data <= root->data)
    {
        root->left = insert(root->left , data);
    }
    else{
        root->right = insert(root->right , data);
    }

    return root;
}

struct node * inorderPre(struct node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *Delete(struct node *root , int data){
    if(root == NULL)
        return NULL;

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(data < root->data)
        root->left = Delete(root->left , data);

    if(data > root->data)
        root->right = Delete(root->right , data);

    else{
        struct node * ipre = inorderPre(root);
        root->data = ipre->data;
        root->left = Delete(root->left , ipre->data);
    }
    return root;
}

void in_order(struct node *root){
    if(root==NULL)return;

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}


int main(){
    struct node *root = insert(root , 10);
    root = insert(root , 9);
    root = insert(root , 8);
    root = insert(root , 7);
    root = insert(root , 11);


    printf("\nIn order of the BST : ");
    in_order(root);

    Delete(root , 30);
    printf("\nIn order of the BST after deletion : ");
    in_order(root);
}
