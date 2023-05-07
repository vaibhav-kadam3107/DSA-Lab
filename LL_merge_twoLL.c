#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* merge(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node* mergedList = NULL;
    if (head1->data <= head2->data) {
        mergedList = head1;
        mergedList->next = merge(head1->next, head2);
    } else {
        mergedList = head2;
        mergedList->next = merge(head1, head2->next);
    }
    mergedList->next->prev = mergedList;
    mergedList->prev = NULL;
    return mergedList;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // create first sorted doubly linked list
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 1;
    node1->prev = NULL;
    node1->next = node2;
    node2->data = 3;
    node2->prev = node1;
    node2->next = node3;
    node3->data = 5;
    node3->prev = node2;
    node3->next = NULL;
    head1 = node1;

    // create second sorted doubly linked list
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node6 = (struct Node*)malloc(sizeof(struct Node));
    node4->data = 2;
    node4->prev = NULL;
    node4->next = node5;
    node5->data = 4;
    node5->prev = node4;
    node5->next = node6;
    node6->data = 6;
    node6->prev = node5;
    node6->next = NULL;
    head2 = node4;

    // display the two original lists
    printf("List 1: ");
    display(head1);
    printf("\nList 2: ");
    display(head2);

    // merge the two lists and display the result
    struct Node* mergedList = merge(head1, head2);
    printf("\nMerged List: ");
    display(mergedList);

    return 0;
}
