#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the list
void insertNode(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list in reverse order
void printList(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    printList(head->next);
    printf("%d", head->data);
}

// Function to add two numbers represented as singly linked lists
struct Node *add(struct Node *a, struct Node *b)
{
    int carry = 0;
    struct Node *result = NULL;
    while (a != NULL || b != NULL || carry != 0)
    {
        int sum = carry;
        if (a != NULL)
        {
            sum += a->data;
            a = a->next;
        }
        if (b != NULL)
        {
            sum += b->data;
            b = b->next;
        }
        insertNode(&result, sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Function to subtract two numbers represented as singly linked lists
struct Node *subtract(struct Node *a, struct Node *b)
{
    int borrow = 0;
    struct Node *result = NULL;
    while (a != NULL || b != NULL)
    {
        int diff = borrow;
        if (a != NULL)
        {
            diff += a->data;
            a = a->next;
        }
        if (b != NULL)
        {
            diff -= b->data;
            b = b->next;
        }
        if (diff < 0)
        {
            borrow = -1;
            diff += 10;
        }
        else
        {
            borrow = 0;
        }
        insertNode(&result, diff);
    }
    // Remove leading zeros
    while (result != NULL && result->data == 0)
    {
        struct Node *temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}

// Function to multiply two numbers represented as singly linked lists
struct Node *multiply(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;
    int shift = 0;
    while (b != NULL)
    {
        int carry = 0;
        struct Node *temp = a;
        struct Node *product = NULL;
        while (temp != NULL)
        {
            int prod = (temp->data * b->data) + carry;
            insertNode(&product, prod % 10);
            carry = prod / 10;
            temp = temp->next;
        }
        if (carry > 0)
        {
            insertNode(&product, carry);
        }
        // Shift the product to the left based on the position of b
        for (int i = 0; i < shift; i++)
        {
            insertNode(&product, 0);
        }
        result = add(result, product);
        b = b->next;
        shift++;
    }
    return result;
}

int main()
{
    // Read two numbers as strings and convert them to linked lists
    char num1[11], num2[11];
    printf("Enter the first number (up to 10 digits): ");
    scanf("%s", num1);
    printf("Enter the second number (up to 10 digits): ");
    scanf("%s", num2);
    Node *head1 = NULL;
    Node *head2 = NULL;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Convert num1 to a linked list
    for (int i = len1 - 1; i >= 0; i--)
    {
        int digit = num1[i] - '0';
        head1 = insert_at_front(head1, digit);
    }

    // Convert num2 to a linked list
    for (int i = len2 - 1; i >= 0; i--)
    {
        int digit = num2[i] - '0';
        head2 = insert_at_front(head2, digit);
    }

    // Print the two linked lists
    printf("First number: ");
    print_list(head1);
    printf("Second number: ");
    print_list(head2);

    // Perform arithmetic operations on the linked lists
    Node *sum = add_linked_lists(head1, head2);
    printf("Sum: ");
    print_list(sum);

    Node *diff = subtract_linked_lists(head1, head2);
    printf("Difference: ");
    print_list(diff);

    Node *prod = multiply_linked_lists(head1, head2);
    printf("Product: ");
    print_list(prod);

    // Free memory
    delete_list(head1);
    delete_list(head2);
    delete_list(sum);
    delete_list(diff);
    delete_list(prod);

    return 0;
}