#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE][100];

void push(char element[]) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    strcpy(stack[top], element);
}

char* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char* element = stack[top];
    top--;
    return element;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

// Main function
int main() {
    char name[100], *token;
    printf("Enter your full name (First name Middle name Surname): ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0'; // Removing the newline character from the input
    token = strtok(name, " ");
    while (token != NULL) {
        push(token);
        token = strtok(NULL, " ");
    }
    printf("Name in the order of Surname, First name, and Middle name: ");
    printf("%s ", pop());
    printf("%s ", pop());
    printf("%s\n", pop());
    return 0;
}
