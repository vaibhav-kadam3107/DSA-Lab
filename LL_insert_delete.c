#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create(int n)
{
    struct node *p, *head;
    head = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter elements: ");
    scanf("%d", &head->data);
    head->next = NULL;

    p = head;
    for (int i = 1; i < n; i++)
    {
        p->next = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->next->data);
        p = p->next;
        p->next = NULL;
    }
    return head;
}

void print(struct node *head)
{
    printf("\nElements are : ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *insert(struct node *head, int data, int key)
{
    struct node *p, *q;

    // creating a new node
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;

    // inserting at start
    if (key == -1)
    {
        p->next = head;
        head = p;
    }
    else
    {
        // inserting after a key
        q = head;
        while (q->data != key && q != NULL)
        {
            q = q->next;
        }
        if (q != NULL)
        {
            p->next = q->next;
            q->next = p;
        }
    }
    return head;
}


struct node *delete(struct node *head, int key)
{
    struct node *p, *q;
    if (head == NULL)
    {
        printf("\nEmpty list");
        return head;
    }
    // delete at start
    if (head->data == key)
    {
        p = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(p);
    }
    else
    {
        // deleting after a key
        q = head;
        while (q != NULL && q->data != key)
        {
            q = q->next;
        }
        if (q != NULL)
        {
            p = q->prev;
            p->next = q->next;
            if (q->next != NULL)
            {
                q->next->prev = p;
            }
            free(q);
        }
        else
        {
            printf("\nKey not found");
        }
    }
    return head;
}


int main()
{

    struct node *head;
    int n, data, key;
    printf("\nEnter how many elements you want to insert : ");
    scanf("%d", &n);
    head = create(n);
    printf("\nLL before insert: ");
    print(head);
    printf("\nEnter data and key : ");
    scanf("%d %d", &data, &key);
    head = insert(head, data, key);
    printf("\nLL after insert: ");
    print(head);

    return 0;
}