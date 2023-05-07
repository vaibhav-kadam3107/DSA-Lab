#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertSort(struct node **head) {
    struct node *sorted = NULL;
    struct node *current = *head;
    while(current != NULL) {
        struct node *nextNode = current->next;
        if(sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node *temp = sorted;
            while(temp->next != NULL && current->data > temp->next->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    *head = sorted;
}

int main() {
    struct node *head = NULL;
    insert(&head, 7);
    insert(&head, 3);
    insert(&head, 9);
    insert(&head, 4);
    insert(&head, 5);

    printf("Before sorting: ");
    printList(head);

    insertSort(&head);

    printf("After sorting: ");
    printList(head);

    return 0;
}
