#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    char data[MAX_SIZE];
    int top;
};

void push(struct Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

bool isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Function to check the validity of parentheses
bool isValidParentheses(char *str) {
    int i;
    struct Stack s;
    s.top = -1;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(&s)) {
                return false;
            }
            char c = pop(&s);
            if ((str[i] == ')' && c != '(') || (str[i] == '}' && c != '{') || (str[i] == ']' && c != '[')) {
                return false;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);
    if (isValidParentheses(str)) {
        printf("The parentheses are valid.\n");
    } else {
        printf("The parentheses are not valid.\n");
    }
    return 0;
}
