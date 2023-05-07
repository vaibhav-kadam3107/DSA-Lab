#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create(int n) {
    struct node *head, *p, *q;
    head = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element: ");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    p = head;
    for (int i = 1; i < n; i++) {
        p->next = (struct node *)malloc(sizeof(struct node));
        q = p;
        p = p->next;
        printf("\nEnter element: ");
        scanf("%d", &p->data);
        p->prev = q;
        p->next = NULL;
    }
    return head;
}

void print(struct node *head) {
    printf("\nElements are: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *append_start(struct node *head1, struct node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    struct node *p = head1;
    while (p->prev != NULL) {
        p = p->prev;
    }
    p->prev = head2;
    head2->next = p;
    return head2;
}

struct node *append_end(struct node *head1, struct node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    struct node *p = head1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = head2;
    head2->prev = p;
    return head1;
}

int main() {
    struct node *head1, *head2;
    int n1, n2;
    printf("\nEnter number of elements for the first list: ");
    scanf("%d", &n1);
    head1 = create(n1);
    printf("\nFirst list before append: ");
    print(head1);
    printf("\nEnter number of elements for the second list: ");
    scanf("%d", &n2);
    head2 = create(n2);
    printf("\nSecond list before append: ");
    print(head2);
    head1 = append_start(head1, head2);
    printf("\nList after appending at start: ");
    print(head1);
    head1 = create(n1);
    printf("\nFirst list before append: ");
    print(head1);
    head1 = append_end(head1, head2);
    printf("\nList after appending at end: ");
    print(head1);
    return 0;
}
