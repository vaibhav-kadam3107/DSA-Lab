#include<stdio.h>
#include<stdlib.h>
#define max 100

struct stack{
    int top;
    int size;
    int arr[max];
};

void push(struct stack *s , int data){
    if(s->top == s->size-1)
        printf("stack is full");
    s->top++;
    s->arr[s->top] = data;
}
int pop(struct stack* s){
    if(s->top == -1)
        printf("stack is empty");
    int temp = s->arr[s->top];
    s->top--;
    return temp;
}

void decimal_to_binary(struct stack* s , int dec){
    while(dec > 0){
        int rem = dec % 2;
        push(s , rem);
        dec /= 2;
    }
}

int binary_to_decimal(struct stack *s){
    int dec = 0;
    int base = 1;
    while(s->top != -1){
        int bit = pop(s);
        dec = dec + base * bit;
        base = base *2;
    }
    return dec;
}

int main(){
    int dec;
    struct stack s;
    s.top = -1;
    printf("Enter the decimal no: ");
    scanf("%d" , &dec);

    decimal_to_binary(&s , dec);

    printf("Binary is of %d is: " , dec);
    while(s.top != -1){
        printf("%d " , pop(&s));
    }

    return 0;
}
