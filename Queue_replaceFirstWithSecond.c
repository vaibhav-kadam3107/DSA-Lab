#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue overflow.\n");
    } else if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->elements[q->rear] = x;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->elements[q->rear] = x;
    }
}

int dequeue(Queue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue underflow.\n");
        return -1;
    } else if (q->front == q->rear) {
        data = q->elements[q->front];
        q->front = q->rear = -1;
    } else {
        data = q->elements[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return data;
}

void replace(Queue *q, int oldItem, int newItem) {
    Queue temp;
    initQueue(&temp);

    while (!isEmpty(q)) {
        int item = dequeue(q);
        if (item == oldItem) {
            enqueue(&temp, newItem);
        } else {
            enqueue(&temp, item);
        }
    }

    while (!isEmpty(&temp)) {
        int item = dequeue(&temp);
        enqueue(q, item);
    }
}


void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->elements[i]);
            i = (i+1) % MAX_SIZE;
        }
        printf("%d ", q->elements[i]);
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Before replacing:\n");
    display(&q);

    replace(&q, 30, 35);

    printf("After replacing:\n");
    display(&q);

    return 0;
}
