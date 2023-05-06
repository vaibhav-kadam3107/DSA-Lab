#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10

typedef enum {STUDENT, STAFF, GUEST, HOD, DEAN, DIRECTOR} Entity;

typedef struct {
    Entity entities[MAX_CAPACITY];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(Queue *q) {
    return q->count == MAX_CAPACITY;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, Entity e) {
    if (isFull(q)) {
        printf("The lift is full. Please wait for the next one.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_CAPACITY;
    q->entities[q->rear] = e;
    q->count++;
}

Entity dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("The lift is empty.\n");
        return -1;
    }
    Entity e = q->entities[q->front];
    q->front = (q->front + 1) % MAX_CAPACITY;
    q->count--;
    return e;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("The lift is empty.\n");
        return;
    }
    printf("The lift contains: ");
    int i;
    for (i = 0; i < q->count; i++) {
        printf("%d ", q->entities[(q->front + i) % MAX_CAPACITY]);
    }
    printf("\n");
}
int main() {
    Queue lift;
    initQueue(&lift);

    printf("Welcome to the college lift simulator!\n");
    printf("Students can use the lift when there are no staff members.\n");
    printf("Staff members can use the lift unless HODs/Deans/Directors are present.\n");
    printf("HODs/Deans/Directors have the highest priority.\n");

    while (1) {
        printf("\nEnter the entity using the lift (0=student, 1=staff, 2=guest, 3=HOD, 4=Dean, 5=Director): ");
        int input;
        scanf("%d", &input);
        if (input < 0 || input > 5) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        Entity e = (Entity) input;
        if (e == STUDENT) {
            if (!isEmpty(&lift) && lift.entities[lift.front] == STAFF) {
                printf("Sorry, staff members are in the lift. Please wait for the next one.\n");
                continue;
            }
            enqueue(&lift, e);
            printf("Student added to the lift queue.\n");
        } else if (e == STAFF) {
            int priority = 1;
            while (!isEmpty(&lift) && lift.entities[lift.front] != HOD && lift.entities[lift.front] != DEAN && lift.entities[lift.front] != DIRECTOR) {
                dequeue(&lift);
                priority = 0;
            }
            if (priority) {
                printf("Please wait for the lift to be available for HODs/Deans/Directors.\n");
                continue;
            }
            enqueue(&lift, e);
            printf("Staff added to the lift queue.\n");
        } else if (e == HOD || e == DEAN || e == DIRECTOR) {
            while (!isEmpty(&lift) && lift.entities[lift.front] != e) {
                dequeue(&lift);
            }
            if (isEmpty(&lift)) {
                printf("No staff members are in the lift. Please wait for the next one.\n");
                continue;
            }
            printf("%s has entered the lift. All staff members are required to exit the lift.\n", entityNames[e]);
            clearQueue(&lift);
            enqueue(&lift, e);
        } else {
            enqueue(&lift, e);
            printf("Guest added to the lift queue.\n");
        }
    }
}
