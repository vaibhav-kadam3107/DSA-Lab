#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Stack {
    struct Node* head;
    int size;
};

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    if (stack->head == NULL) {
        newNode->next = NULL;
        stack->head = newNode;
    } else {
        newNode->next = stack->head;
        stack->head->prev = newNode;
        stack->head = newNode;
    }

    stack->size++;
}

int pop(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    int data = stack->head->data;

    if (stack->head->next == NULL) {
        free(stack->head);
        stack->head = NULL;
    } else {
        struct Node* temp = stack->head;
        stack->head = stack->head->next;
        stack->head->prev = NULL;
        free(temp);
    }

    stack->size--;

    return data;
}

void display(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    struct Node* temp = stack->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack = { NULL, 0 };

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
