#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void RemoveDuplicates(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void Insert(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void PrintList(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    // Insert elements into the list
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 3);
    Insert(&head, 3);
    Insert(&head, 4);

    printf("Original list: ");
    PrintList(head);

    // Remove duplicates
    RemoveDuplicates(head);

    printf("List after removing duplicates: ");
    PrintList(head);

    return 0;
}
