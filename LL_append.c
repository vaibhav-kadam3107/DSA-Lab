#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void Append(Node** a, Node** b) {
    if (*a == NULL) { // if list a is empty, set a to b
        *a = *b;
    } else {
        Node* temp = *a; // iterate through list a to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *b; // append list b to the end of list a
    }
    *b = NULL; // set b to NULL since it is now part of a
}

void PrintList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // create list a
    Node* a = NULL;
    Node* a1 = (Node*)malloc(sizeof(Node));
    Node* a2 = (Node*)malloc(sizeof(Node));
    Node* a3 = (Node*)malloc(sizeof(Node));
    a1->data = 1;
    a2->data = 2;
    a3->data = 3;
    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;
    a = a1;

    // create list b
    Node* b = NULL;
    Node* b1 = (Node*)malloc(sizeof(Node));
    Node* b2 = (Node*)malloc(sizeof(Node));
    b1->data = 4;
    b2->data = 5;
    b1->next = b2;
    b2->next = NULL;
    b = b1;

    printf("List a: ");
    PrintList(a);
    printf("List b: ");
    PrintList(b);

    Append(&a, &b);

    printf("List a after appending b: ");
    PrintList(a);
    printf("List b after appending to a: ");
    PrintList(b);

    return 0;
}
