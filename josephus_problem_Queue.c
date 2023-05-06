#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct queue{
    struct node* f;
    struct node *r;
    int size;
};

struct queue* createQueue(){
    struct queue * q = (struct queue*)malloc(sizeof(struct queue));
    q->f = q->r = NULL;
    return q;
};

void enqueue(struct queue * q ,int data){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if(q->r == NULL)
        q->f = q->r = new;
    else{
        q->r->next = new;
        q->r = new;
    }
}

int dequeue(struct queue * q){
    if(q->f == NULL)
        printf("queue is empty");
    int data = q->f->data;
    struct queue* temp = q->f;
    q->f = q->f->next;
    free(temp);
    return data;
}

void josephus(int n , int k){
    struct queue *q =  createQueue();

    for(int i=1 ; i<= n; i++){
        enqueue(q , i);
    }

    while(q->f != q->r){
        for(int i = 0; i < k -1; i++){
            int data = dequeue(q);
            enqueue(q, data);
        }
        printf("\nKilled the person at %d" , dequeue(q));
    }
    printf("\nSafest place is at : %d", dequeue(q));
}

int main(){
    int n , k;
    printf("\nEnter value of n: ");
    scanf("%d" , &n);

    printf("\nEnter value of k: ");
    scanf("%d" , &k);

    josephus(n , k);
}
