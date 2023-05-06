#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int coeff;
    int expo;
};

void insert(struct node **node, int coeff, int expo)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;
    
    if (*node == NULL)
        *node = temp;
    else
    {
        struct node *curr = *node;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

struct node * addition(struct node * p1 , struct node * p2){
    struct node * temp = NULL;
    struct node ** ans = &temp;
    while(p1 != NULL && p2 != NULL){
        if(p1->expo == p2->expo){
            int ans_coeff = p1->coeff + p2->coeff;
            insert(ans , ans_coeff , p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo)
        {
            insert(ans , p1->coeff , p1->expo);
            p1 = p1->next;
        }
        else{
            insert(ans , p2->coeff , p2->expo);
            p2 = p2->next;
        }
        ans = &((*ans)->next); 
    }
    while(p1 != NULL){
        insert(ans , p1->coeff , p1->expo);
        p1 = p1->next;
        ans = &((*ans)->next);
    }
    while(p2 != NULL){
        insert(ans , p2->coeff , p2->expo);
        p2 = p2->next;
        ans = &((*ans)->next);
    }
    return temp;
}

void display(struct node * p){
    struct node * curr = p;
    while(curr != NULL){
        printf("%dx^%d " , curr->coeff , curr->expo);
        curr = curr->next;
        if (curr!= NULL) 
            printf(" + ");
    }
    printf("\n");
}

int main()
{

    struct node *p1 = NULL;
    struct node *p2 = NULL;

    int n1 , n2 ,coeff ,expo ;

    printf("Enter the number of terms in P1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("\nEnter the coefficient and exponent value of %d term: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insert(&p1, coeff, expo);
    }
    printf("\nP1 is : ");
    display(p1);

    printf("\nEnter the number of terms in P2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("\nEnter the coefficient and exponent value of %d term: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insert(&p2, coeff, expo);
    }
    printf("\nP2 is : ");
    display(p2);

    struct node * p3 = addition(p1, p2);

    printf("\n\nAddition of P1 and P2 is : ");
    display(p3);

    return 0;
}