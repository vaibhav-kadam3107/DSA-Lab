#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE][MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char *str) {
    if (isFull(s)) {
        printf("Stack is full\n");
    }
    else {
        ++s->top;
        strcpy(s->items[s->top], str);
    }
}

void pop(struct Stack *s, char *str) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    }
    else {
        strcpy(str, s->items[s->top]);
        --s->top;
    }
}

int isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return 1;
    }
    return 0;
}

char *preToInfix(char *pre_exp) {
    struct Stack stack;
    initStack(&stack);
    int length = strlen(pre_exp);
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            char op1[MAX_SIZE], op2[MAX_SIZE];
            pop(&stack, op1);
            pop(&stack, op2);
            char temp[MAX_SIZE];
            sprintf(temp, "(%s%c%s)", op1, pre_exp[i], op2);
            push(&stack, temp);
        }
        else {
            char temp[MAX_SIZE];
            sprintf(temp, "%c", pre_exp[i]);
            push(&stack, temp);
        }
    }
    char *infix = malloc(MAX_SIZE);
    pop(&stack, infix);
    return infix;
}

int main() {
    char pre_exp[] = "*-A/BC-/AKL";
    //Infix: ((A-(B/C))*((A/K)-L))
    char *infix = preToInfix(pre_exp);
    printf("Infix: %s\n", infix);
    free(infix);
    return 0;
}
