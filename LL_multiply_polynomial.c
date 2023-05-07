#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(int coeff, int exp) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

// Function to add a term to the polynomial
void add_term(Node** poly, int coeff, int exp) {
    Node* new_node = create_node(coeff, exp);
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display the polynomial
void display_poly(Node* poly) {
    Node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to perform multiplication of two polynomials
Node* multiply_poly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    while (temp1 != NULL) {
        Node* temp2 = poly2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            add_term(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    add_term(&poly1, 3, 2);
    add_term(&poly1, 4, 1);
    add_term(&poly1, 2, 0);
    add_term(&poly2, 2, 1);
    add_term(&poly2, 1, 0);
    printf("Polynomial 1: ");
    display_poly(poly1);
    printf("Polynomial 2: ");
    display_poly(poly2);
    Node* result = multiply_poly(poly1, poly2);
    printf("Resultant Polynomial: ");
    display_poly(result);
    return 0;
}
