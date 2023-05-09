#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash_function2(int hf, int size)
{
    return (hf + 1) % size;
}

int hash_function(int key, int size)
{
    return key % size;
}

int* create_table(int size)
{
    int* table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }
    return table;
}

void insert(int *table, int size, int key)
{
    int index = hash_function(key, size);

    if (table[index] == -1)
    {
        table[index] = key;
    }
    else
    {
        int index2 = hash_function2(index, size);
        while (table[index2] != -1)
        {
            index2 = hash_function2(index2, size);
        }
        table[index2] = key;
    }
}

int search(int *table, int size, int key)
{
    int index = hash_function(key, size);

    if (table[index] == key)
    {
        return 1;
    }

    int index2 = hash_function2(index, size);
    while (index2 != index)
    {
        if (table[index2] == key)
        {
            return 1;
        }
        index2 = hash_function2(index2, size);
    }

    return 0;
}

void display(int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d]: %d\n", i, table[i]);
    }
}

int main()
{
    int *table = create_table(SIZE);

    insert(table, SIZE, 15);
    insert(table, SIZE, 5);
    insert(table, SIZE, 28);
    insert(table, SIZE, 8);
    insert(table, SIZE, 19);
    insert(table, SIZE, 25);

    display(table, SIZE);

    int key = 19;
    if (search(table, SIZE, key))
    {
        printf("%d is found\n", key);
    }
    else
    {
        printf("%d is not found\n", key);
    }

    key = 40;
    if (search(table, SIZE, key))
    {
        printf("%d is found\n", key);
    }
    else
    {
        printf("%d is not found\n", key);
    }

    free(table);

    return 0;
}
