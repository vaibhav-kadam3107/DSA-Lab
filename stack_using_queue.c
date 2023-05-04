#include<stdio.h>
#include<stdlib.h>
#define max 100

struct queue{
    int arr[max];
    int f,r;
};
int isEmptyQueue(struct queue *q){
    if(q->f == q->r)
        return 1;
    return 0;
}
int isFullQueue(struct queue *q){
    if(q->r == max-1)
        return 1;
    return 0;
}

void enqueue(struct queue *q , int data){
    if(isFullQueue(q))
        printf("Queue is empty");
    else{
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct queue *q){
    if(isEmptyQueue(q))
        printf("Queue is empty");
    else{
        q->f++;
        int temp = q->arr[q->f];
        return temp;
    }
}

struct stack{
    struct queue q1 , q2;
};

void push(struct stack *s , int data){
    while(!isEmptyQueue(&s->q1)){
        enqueue(&s->q2 , dequeue(&s->q1));
    }

    enqueue(&s->q1 , data);

    while(!isEmptyQueue(&s->q2)){
        enqueue(&s->q1 , dequeue(&s->q2));
    }
}

int pop(struct stack *s){
    return dequeue(&s->q1);
}

int main(){
    struct stack s;
    s.q1.f = s.q1.r = 0;
    s.q2.f = s.q2.r = 0;
    push(&s , 10);
    push(&s , 20);
    push(&s , 30);
    push(&s , 40);
    printf("\nPop s %d" , pop(&s));
}

