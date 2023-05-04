#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct stack {
    int size;
    int top;
    char arr[MAX];
};

void push(struct stack *s, char data) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return '\0';
    } else {
        char temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}

int precedence(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    int i, j;
    char c;
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->top = -1;
    s->size = MAX;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while ((c = pop(s)) != '(') {
                postfix[j++] = c;
            }
        } else {
            while (s->top != -1 && precedence(s->arr[s->top]) >= precedence(infix[i])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while (s->top != -1) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    free(s);
}

void reverse(char *exp) {
    int len = strlen(exp);
    char temp[len];
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        temp[j] = exp[i];
    }
    temp[j] = '\0';
    strcpy(exp, temp);
}

void infix_to_prefix(char *infix, char *prefix) {
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    infix_to_postfix(infix, prefix);
    reverse(prefix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    infix_to_prefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
