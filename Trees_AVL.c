#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *new_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return (height(root->left) - height(root->right));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *Left_rotate(struct node *root)
{
    struct node *x = root->right;
    struct node *t = x->left;
    x->left = root;
    root->right = t;
    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(root->left), height(root->right));
    return x;
}

struct node *Right_rotate(struct node *root)
{
    struct node *x = root->left;
    struct node *t = x->right;

    x->right = root;
    root->left = t;
    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(root->left), height(root->right));
    return x;
}

struct node *insert(struct node *root, int val)
{

    // similar to that of BST insertion
    if (root == NULL)
        root = new_node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }


    root->height = 1 + max(height(root->left), height(root->right));


    int balance = getBalance(root);

    if (balance > 1 && val < root->left->data)
        return (Right_rotate(root));

    if (balance < -1 && val > root->right->data)
        return (Left_rotate(root));

    if (balance > 1 && val > root->left->data)
    {
        root->left = Left_rotate(root->left);
        return (Right_rotate(root));
    }

    if (balance < -1 && val < root->right->data)
    {
        root->right = Right_rotate(root->right);
        return (Left_rotate(root));
    }

    return root;
}

void level_order(struct node *root)
{
    if (root == NULL)
        return;
    
    struct node *queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;

    while (front != rear)
    {
        struct node *temp = queue[front++];

        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;

        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}


void in_order(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        in_order(root->left);
        printf("%d " , root->data);
        in_order(root->right);
    }
}

int main()
{

    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* 
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */

    printf("\nPreorder traversal of AVL tree is: ");
    in_order(root);

    printf("\nLevel wise nodes of AVL tree are: ");
    level_order(root);    


    return 0;
}