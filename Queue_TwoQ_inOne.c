#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE];
int front1 = -1, rear1 = -1;
int front2 = MAXSIZE, rear2 = MAXSIZE;

// Function to add an element to the first queue
void addq1(int item) {
    if (rear1 == MAXSIZE - 1) {
        printf("Queue 1 is full\n");
        return;
    }
    if (front1 == -1)
        front1 = 0;
    rear1++;
    queue[rear1] = item;
    printf("Element added to Queue 1: %d\n", item);
}

// Function to add an element to the second queue
void addq2(int item) {
    if (rear2 == 0) {
        printf("Queue 2 is full\n");
        return;
    }
    if (front2 == MAXSIZE)
        front2 = MAXSIZE - 1;
    rear2--;
    queue[rear2] = item;
    printf("Element added to Queue 2: %d\n", item);
}

// Function to delete an element from the first queue
void delq1() {
    if (front1 == -1) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Element deleted from Queue 1: %d\n", queue[front1]);
    front1++;
    if (front1 > rear1)
        front1 = rear1 = -1;
}

// Function to delete an element from the second queue
void delq2() {
    if (front2 == MAXSIZE) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Element deleted from Queue 2: %d\n", queue[front2]);
    front2--;
    if (front2 < rear2)
        front2 = rear2 = MAXSIZE;
}

// Function to display both queues
void display() {
    int i;
    printf("Queue 1:\n");
    if (front1 == -1)
        printf("Empty\n");
    else {
        for (i = front1; i <= rear1; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
    printf("Queue 2:\n");
    if (front2 == MAXSIZE)
        printf("Empty\n");
    else {
        for (i = front2; i >= rear2; i--)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function to test the multiple queue implementation
int main() {
    int choice, item;
    do {
        printf("\n1. Add element to Queue 1\n");
        printf("2. Add element to Queue 2\n");
        printf("3. Delete element from Queue 1\n");
        printf("4. Delete element from Queue 2\n");
        printf("5. Display both queues\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to be added to Queue 1: ");
                scanf("%d", &item);
                addq1(item);
                break;
                
            case 2:
                printf("Enter element to be added to Queue 2: ");
                scanf("%d", &item);
                addq2(item);
                break;
                
            case 3:
                delq1();
                break;
                
            case 4:
                delq2();
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 6);
    
    return 0;
}
