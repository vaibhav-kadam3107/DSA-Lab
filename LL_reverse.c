#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the list
void add_node(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the list using an iterative approach
void Reverse(struct Node** head_ref) {
    struct Node *prev_node = NULL, *current_node = *head_ref, *next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *head_ref = prev_node;
}

// Driver program to test the implementation
int main() {
    struct Node* head = NULL;

    // Add some nodes to the list
    add_node(&head, 5);
    add_node(&head, 4);
    add_node(&head, 3);
    add_node(&head, 2);
    add_node(&head, 1);

    // Print the original list
    printf("Original list: ");
    print_list(head);

    // Reverse the list
    Reverse(&head);

    // Print the reversed list
    printf("Reversed list: ");
    print_list(head);

    return 0;
}
