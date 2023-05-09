#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int element = stack[top];
    top--;
    return element;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = n; i >= 1; i--) {
        push(i);
    }
    while (!isEmpty()) {
        result *= pop();
    }
    return result;
}

// Function to generate the Fibonacci series
void fibonacci(int n) {
    if (n <= 0) {
        printf("Invalid input\n");
        return;
    }
    int a = 0, b = 1, c;
    push(a);
    push(b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        push(c);
        a = b;
        b = c;
    }
    printf("Fibonacci Series: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
}

// Main function
int main() {
    int choice, n;
    while (1) {
        printf("\n1. Factorial of a number\n2. Fibonacci series\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                fibonacci(n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
