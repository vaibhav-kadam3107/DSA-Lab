#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct stack {
    int size;
    int top;
    int *arr;
};

int Full(struct stack *s){
    if(s->top == s->size -1)
        return 1;
    return 0;
}

int Empty(struct stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

void push(struct stack *s , int data){
    if(Full(s))
        return;
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack * s){
    if(Empty(s))
        return ;
    else{
        int temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}

struct node * createNode(int data){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void Inorder(struct node * root){
    if(root == NULL)
        return;

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    while(root != NULL){
        push(s , (int)root);
        root = root->left;
    }
    while(!Empty(s)){
        root = (struct node*)pop(s);
        printf("%d " , root->data);
        root = root->right;

        while(root != NULL){
            push(s , (int)root);
            root = root->left;
        }
    }
}

void Preorder(struct node * root){
    if(root==NULL)
        return;

    struct stack *s= (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int*) * s->size);

    while(root != NULL){
        printf("%d " , root->data);
        push(s , (int)root);
        root = root->left;
    }

    while(!Empty(s)){
        root = (struct node *)pop(s);
        root = root->right;

        while(root != NULL){
            printf("%d " , root->data);
            push(s , (int)root);
            root = root->left;
        }
    }
}

void Postorder(struct  node* root){
    if(root == NULL)
        return;

    struct stack *s= (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int*) * s->size);

    struct node * prev =NULL;

    do{
        while(root != NULL){
            push(s , (int)root);
            root = root->left;
        }

        while(root == NULL && !Empty(s)){
            root = (struct node*)s->arr[s->top];
            if(root->right == NULL || root->right == prev){
                printf("%d " , root->data);
                pop(s);
                prev = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }
    }while(!Empty(s));
}

void mirror(struct node *root){
    if(root == NULL)
        return;
    struct stack *s= (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int*) * s->size);

    struct node *prev = NULL;

    push(s , (int)root);

    while(!Empty(s)){
        root = (struct node*)pop(s);
        swap(root);

        if(root->left != NULL)
            push(s , (int)root->left);

        if(root->right != NULL)
            push(s , (int)root->right);
    }

}

int main(){
    struct node* root = createNode(5);
    struct node * p1 = createNode(6);
    struct node * p2 = createNode(7);
    struct node * p3 = createNode(2);
    struct node * p4 = createNode(3);

    root->left = p1;
    root->right = p2;
    root->left->left = p3;
    root->left->right = p4;

    printf("\nIn_order is : ");
    Inorder(root);

    printf("\nPre_order is : ");
    Preorder(root);

    printf("\nPost_order is : ");
    Postorder(root);

}
