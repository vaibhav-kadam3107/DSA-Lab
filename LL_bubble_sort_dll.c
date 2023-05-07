#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

// Function to traverse the list and print the elements
void printList(struct node *head)
{
    printf("List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to perform bubble sort on the list
void bubbleSort(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main()
{
    struct node *head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
    }

    printf("Before sorting:\n");
    printList(head);

    bubbleSort(head);

    printf("After sorting:\n");
    printList(head);

    return 0;
}
