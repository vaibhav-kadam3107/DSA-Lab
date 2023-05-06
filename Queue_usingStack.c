#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;

void push(Stack *s, int item) {
    if (s->top == MAXSIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

typedef struct {
    Stack s1;
    Stack s2;
} Queue;

void enqueue(Queue *q, int item) {
    push(&(q->s1), item);
}

int dequeue(Queue *q) {
    if (q->s1.top == -1 && q->s2.top == -1) {
        printf("Queue underflow\n");
        return -1;
    }

    if (q->s2.top == -1) {
        while (q->s1.top != -1) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    return pop(&(q->s2));
}

void display(Queue q) {
    if (q.s1.top == -1 && q.s2.top == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = q.s2.top; i >= 0; i--) {
        printf("%d ", q.s2.data[i]);
    }

    for (int i = 0; i <= q.s1.top; i++) {
        printf("%d ", q.s1.data[i]);
    }

    printf("\n");
}

int main() {
    Queue q;
    q.s1.top = -1;
    q.s2.top = -1;

    int choice, item;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;

            case 2:
                item = dequeue(&q);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}
