#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
#define MAX_QUEUES 10

typedef struct {
    int *elements;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q, int size) {
    q->elements = (int *) malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == (q->rear - q->front + 1);
}

void enqueue(Queue *q, int element) {
    if (!isFull(q)) {
        q->rear++;
        q->elements[q->rear] = element;
        q->size++;
    }
}

int dequeue(Queue *q) {
    int element = q->elements[q->front];
    q->front++;
    q->size--;
    return element;
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    Queue queues[MAX_QUEUES];
    int n, m, i, j, k;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of queues to divide the array: ");
    scanf("%d", &m);

    // initialize the queues
    for (i = 0; i < m; i++) {
        initQueue(&queues[i], n / m + 1);
    }

    // distribute the elements of the array into the queues
    for (i = 0, j = 0; i < n; i++) {
        enqueue(&queues[j], arr[i]);
        if (isFull(&queues[j])) {
            j++;
        }
    }

    // display the elements of each queue
    for (i = 0; i < m; i++) {
        printf("Queue %d: ", i + 1);
        while (!isEmpty(&queues[i])) {
            printf("%d ", dequeue(&queues[i]));
        }
        printf("\n");
    }

    // free the memory allocated for the queues
    for (i = 0; i < m; i++) {
        free(queues[i].elements);
    }

    return 0;
}
