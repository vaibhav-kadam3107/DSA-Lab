#include <stdio.h>
#include <stdlib.h>

// Define a node of the doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Initialize the front and rear pointers of the deque to NULL
struct node* front = NULL;
struct node* rear = NULL;

// Function to add an element to the rear end of the deque
void add(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // If deque is empty, set front and rear pointers to newNode
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    
    // Add the newNode to the rear end of the deque
    rear->next = newNode;
    newNode->prev = rear;
    rear = newNode;
}

// Function to remove an element from the front end of the deque
void delete() {
    // If deque is empty, return
    if(front == NULL) {
        printf("\nDequeue is Empty.\n");
        return;
    }
    
    struct node* temp = front;
    
    // If deque has only one node, set front and rear pointers to NULL
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
        front->prev = NULL;
    }
    
    // Free the memory allocated to the node being removed
    free(temp);
}

// Function to display the deque from front to rear
void display() {
    // If deque is empty, return
    if(front == NULL && rear == NULL) {
        printf("\nDequeue is Empty.\n");
        return;
    }
    
    struct node* temp = front;
    
    printf("\nDequeue from front to rear is: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    // Adding elements to the deque
    add(10);
    add(20);
    add(30);
    add(40);
    
    // Display the deque
    display();
    
    // Deleting an element from the front end of the deque
    delete();
    
    // Display the deque
    display();
    
    // Adding an element to the rear end of the deque
    add(50);
    
    // Display the deque
    display();
    
    return 0;
}
