#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a new node to the end of the list
void append(Node** head, Node** tail, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*tail == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

// Function to create a new copy of a linked list
Node* CopyList(Node* head) {
    Node* new_head = NULL;
    Node* new_tail = NULL;
    Node* current = head;
    while (current != NULL) {
        append(&new_head, &new_tail, current->data);
        current = current->next;
    }
    return new_head;
}

// Function to print the elements of a linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for a linked list
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function to test the CopyList() function
int main() {
    // Create the original linked list
    Node* head = NULL;
    Node* tail = NULL;
    append(&head, &tail, 1);
    append(&head, &tail, 2);
    append(&head, &tail, 3);
    append(&head, &tail, 4);
    printf("Original list: ");
    print_list(head);

    // Copy the list and print the new copy
    Node* new_head = CopyList(head);
    printf("Copy of list: ");
    print_list(new_head);

    // Free the memory allocated for the lists
    free_list(head);
    free_list(new_head);

    return 0;
}
