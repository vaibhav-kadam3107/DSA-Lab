#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node* create(int n){
    struct node *p , *head;
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d" , &head->data);
    head->next = NULL;

    p = head;
    for (int i = 1; i < n; i++)
    {
        p->next = (struct node*)malloc(sizeof(struct node));
        scanf("%d" , &p->next->data);
        p = p->next;
        p->next = NULL;
    }
    return head;
}

void print(struct node * head){
    printf("Linked list elements are: ");
    while (head != NULL)
    {
        printf("%d " , head->data);
        head = head->next;
    }
}

int count(struct node * head){
    int i = 0;
    while(head != NULL){
        head = head->next;
        i++;
    }
    return i;
}

int main(){

    struct node* head;
    int n,x;
    printf("Enter how many elements you want to insert: ");
    scanf("%d" , &n);
    head = create(n);
    print(head);
    x = count(head);
    printf("\nNo. of nodes are: %d" , x);

    return 0;
}