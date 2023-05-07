#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void sortedInsert(struct node** head, struct node* new_node) {
    struct node* current;

    // Case for empty list
    if (*head == NULL) {
        *head = new_node;
    }
    // Case for new_node being less than the first node
    else if ((*head)->data >= new_node->data) {
        new_node->next = *head;
        *head = new_node;
    }
    // Case for new_node being greater than the first node
    else {
        current = *head;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = 3;
    new_node->next = NULL;

    sortedInsert(&head, new_node);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = 1;
    new_node->next = NULL;

    sortedInsert(&head, new_node);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = 5;
    new_node->next = NULL;

    sortedInsert(&head, new_node);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = 2;
    new_node->next = NULL;

    sortedInsert(&head, new_node);

    printList(head);

    return 0;
}
