#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int elements[MAX_QUEUE_SIZE];
    int front, rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq) {
    return dq->front == -1 && dq->rear == -1;
}

int isFull(Deque *dq) {
    return dq->front == 0 && dq->rear == MAX_QUEUE_SIZE - 1 || dq->front == dq->rear + 1;
}

void addFront(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
    } else if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->elements[dq->front] = x;
    } else if (dq->front == 0) {
        dq->front = MAX_QUEUE_SIZE - 1;
        dq->elements[dq->front] = x;
    } else {
        dq->front--;
        dq->elements[dq->front] = x;
    }
}

void addRear(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
    } else if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->elements[dq->rear] = x;
    } else if (dq->rear == MAX_QUEUE_SIZE - 1) {
        dq->rear = 0;
        dq->elements[dq->rear] = x;
    } else {
        dq->rear++;
        dq->elements[dq->rear] = x;
    }
}

int removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    } else if (dq->front == dq->rear) {
        int x = dq->elements[dq->front];
        dq->front = dq->rear = -1;
        return x;
    } else if (dq->front == MAX_QUEUE_SIZE - 1) {
        int x = dq->elements[dq->front];
        dq->front = 0;
        return x;
    } else {
        int x = dq->elements[dq->front];
        dq->front++;
        return x;
    }
}

int removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    } else if (dq->front == dq->rear) {
        int x = dq->elements[dq->rear];
        dq->front = dq->rear = -1;
        return x;
    } else if (dq->rear == 0) {
        int x = dq->elements[dq->rear];
        dq->rear = MAX_QUEUE_SIZE - 1;
        return x;
    } else {
        int x = dq->elements[dq->rear];
        dq->rear--;
        return x;
    }
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = dq->front;
        do {
            printf("%d ", dq->elements[i]);
            i = (i + 1) % MAX_QUEUE_SIZE;
        } while (i != (dq->rear + 1) % MAX_QUEUE_SIZE);
        printf("\n");
    }
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, element;

    do {
        printf("\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                addFront(&dq, element);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                addRear(&dq, element);
                break;

            case 3:
                element = removeFront(&dq);
                if (element != INT_MIN) {
                    printf("Deleted element: %d\n", element);
                }
                break;

            case 4:
                element = removeRear(&dq);
                if (element != INT_MIN) {
                    printf("Deleted element: %d\n", element);
                }
                break;

            case 5:
                displayDeque(&dq);
                break;

            case 6:
                printf("Exiting from the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
