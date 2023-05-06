#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct Stack {
    int top;
    char data[MAX_SIZE];
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }

    char item = stack->data[stack->top];
    stack->top--;

    return item;
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }

    return stack->data[stack->top];
}

// Function to check if character is an operator or not
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }

    return 0;
}

// Function to convert prefix expression to postfix expression
void preToPost(char* prefix) {
    Stack stack;
    initStack(&stack);
    int len = strlen(prefix);

    // Reading from right to left
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If character is an operand, push it to stack
        if (isdigit(ch) || isalpha(ch)) {
            push(&stack, ch);
        }

        // If character is an operator, pop two operands from stack,
        // concatenate them with the operator and push the resultant string back to stack
        else if (isOperator(ch)) {
            char op1 = pop(&stack);
            char op2 = pop(&stack);
            char temp[MAX_SIZE];

            sprintf(temp, "%c%c%c", op1, op2, ch);
            push(&stack, temp[0]);
        }
    }

    // Postfix expression is stored in stack, print it
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }

    printf("\n");
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter prefix expression: ");
    fgets(prefix, MAX_SIZE, stdin);

    printf("Postfix expression: ");
    preToPost(prefix);

    return 0;
}
