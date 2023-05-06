#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

typedef struct {
    int *elements;
    int front;
    int rear;
    int size;
} Deque;

void initializeDeque(Deque *dq) {
    dq->elements = (int*)malloc(MAX_SIZE * sizeof(int));
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE-1) || (dq->front == dq->rear+1);
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

void insertFront(Deque *dq, int element) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert element.\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = MAX_SIZE-1;
        } else {
            dq->front--;
        }
        dq->elements[dq->front] = element;
        dq->size++;
        printf("Element %d inserted at front.\n", element);
    }
}

void insertRear(Deque *dq, int element) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert element.\n");
    } else {
        if (dq->front == -1) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->rear == MAX_SIZE-1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->elements[dq->rear] = element;
        dq->size++;
        printf("Element %d inserted at rear.\n", element);
    }
}

int deleteFront(Deque *dq) {
    int element = INT_MIN;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete element.\n");
    } else {
        element = dq->elements[dq->front];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->front == MAX_SIZE-1) {
            dq->front = 0;
        } else {
            dq->front++;
        }
        dq->size--;
    }
    return element;
}

int deleteRear(Deque *dq) {
    int element = INT_MIN;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete element.\n");
    } else {
        element = dq->elements[dq->rear];
        if (dq->front == dq->rear) {
            dq->front = -1;
            dq->rear = -1;
        } else if (dq->rear == 0) {
            dq->rear = MAX_SIZE-1;
        } else {
            dq->rear--;
        }
        dq->size--;
    }
    return element;
}
void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = dq->front;
        do {
            printf("%d ", dq->elements[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (dq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    Deque dq;
    initializeDeque(&dq);
    int choice, val;

    do {
        printf("\nCircular Double Ended Queue Operations\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(&dq, val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(&dq, val);
                break;
            case 3:
                val = deleteFront(&dq);
                if (val != INT_MIN) {
                    printf("Deleted element: %d\n", val);
                }
                break;
            case 4:
                val = deleteRear(&dq);
                if (val != INT_MIN) {
                    printf("Deleted element: %d\n", val);
                }
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
