#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create(int n) {
    struct node *head = NULL;
    struct node *tail = NULL;
    printf("\nEnter elements: ");
    for (int i = 0; i < n; i++) {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->prev = NULL;
        p->next = NULL;

        if (head == NULL) {
            head = p;
            tail = p;
        }
        else {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void print(struct node *head) {
    printf("\nElements are : ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *insert(struct node *head, int data, int key) {
    struct node *p, *q;

    // creating a new node
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    // inserting at start
    if (key == -1) {
        p->next = head;
        if (head != NULL) {
            head->prev = p;
        }
        head = p;
    }
    else {
        // inserting after a key
        q = head;
        while (q->data != key && q != NULL) {
            q = q->next;
        }
        if (q != NULL) {
            p->prev = q;
            p->next = q->next;
            if (q->next != NULL) {
                q->next->prev = p;
            }
            q->next = p;
        }
    }
    return head;
}

struct node *delete(struct node *head, int key) {
    struct node *p, *q;
    
    // deleting at start
    if (head->data == key) {
        p = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(p);
    }
    else {
        // deleting after a key
        q = head;
        while (q != NULL && q->data != key) {
            q = q->next;
        }
        if (q != NULL) {
            p = q->prev;
            p->next = q->next;
            if (q->next != NULL) {
                q->next->prev = p;
            }
            free(q);
        }
    }
    return head;
}

int main() {
    struct node *head;
    int n, data, key;
    printf("\nEnter how many elements you want to insert : ");
    scanf("%d", &n);
    head = create(n);
    printf("\nDLL before insert: ");
    print(head);
    printf("\nEnter data and key : ");
    scanf("%d %d", &data, &key);
    head = insert(head, data, key);
    printf("\nDLL after insert: ");
    print(head);
    printf("\nEnter key to delete : ");
    scanf("%d", &key);
    head = delete(head, key);
    printf("\nDLL after delete: ");
    print(head);
    return 0;
}
