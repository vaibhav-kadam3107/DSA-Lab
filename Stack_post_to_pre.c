#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack
{
    int top;
    char data[MAX][MAX];
} Stack;

void push(Stack *s, char *str)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    strcpy(s->data[++(s->top)], str);
}

char *pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

char *postfixToPrefix(char *postfix)
{
    Stack s;
    s.top = -1;
    int len = strlen(postfix);
    for (int i = 0; i < len; i++)
    {
        if (isalnum(postfix[i]))
        {
            char str[MAX] = "";
            strncat(str, &postfix[i], 1);
            push(&s, str);
        }
        else if (isOperator(postfix[i]))
        {
            char op1[MAX] = "", op2[MAX] = "", op[MAX] = "";
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            strncat(op, &postfix[i], 1);
            strcat(op, op2);
            strcat(op, op1);
            push(&s, op);
        }
        else
        {
            printf("Invalid Expression!\n");
            exit(1);
        }
    }
    return pop(&s);
}

int evaluatePrefix(char *prefix)
{
    Stack s;
    s.top = -1;
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            char str[MAX] = "";
            strncat(str, &prefix[i], 1);
            push(&s, str);
        }
        else if (isOperator(prefix[i]))
        {
            char op1[MAX] = "", op2[MAX] = "";
            int val1, val2, result;
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            val1 = atoi(op1);
            val2 = atoi(op2);
            switch (prefix[i])
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            case '^':
                result = pow(val1, val2);
                break;
            default:
                printf("Invalid Operator!\n");
                exit(1);
            }
            char str[MAX];
            sprintf(str, "%d", result);
            push(&s, str);
        }
        else
        {
            printf("Invalid Expression!\n");
            exit(1);
        }
    }
    return atoi(pop(&s));
}

int main()
{
    char postfix[MAX], prefix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    printf("Postfix Expression: %s\n", postfix);
    strcpy(prefix, postfixToPrefix(postfix));
    printf("Prefix Expression: %s\n", prefix);
    // Evaluation of Prefix Expression
    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}
/*
Suppose we have a postfix expression "23+4*5-". To convert it into a prefix expression, we follow the steps mentioned in the algorithm:

We traverse the postfix expression from left to right.
If we encounter an operand (in this case, 2, 3, 4, and 5), we push it onto the stack.
If we encounter an operator (in this case, + and *), we pop the top two operands from the stack (3 and 2 for +, and 5 and 4 for *), and concatenate them with the operator in reverse order (i.e., +23 for the first operation and *54 for the second operation).
We push the resulting string back onto the stack.
Repeat steps 2-4 until we reach the end of the postfix expression.
After performing the above steps, we will be left with a single string on the stack, which will be our final prefix expression. In this case, the final prefix expression will be "-+23*45".
*/