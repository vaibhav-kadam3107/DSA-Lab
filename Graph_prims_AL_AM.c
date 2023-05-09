//al
/*
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

// Structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};

// Structure to represent the graph
struct Graph
{
    int V;
    struct AdjList *array;
};

// Function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode =
        (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array =
        (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the minimum spanning tree
void printMST(int parent[], int key[], int n, struct Graph *graph)
{
    printf("Edge \t Weight\n");
    for (int i = 1; i < n; ++i)
        printf("%d - %d \t %d \n", parent[i], i, key[i]);
}

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int n)
{
    int min = __INT_MAX__, min_index;

    for (int v = 0; v < n; ++v)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


void primMST(struct Graph *graph)
{
    int n = graph->V;
    int parent[n];
    int key[n];
    int mstSet[n];

    for (int i = 0; i < n; ++i)
    {
        key[i] = __INT_MAX__;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            int weight = pCrawl->weight;
            if (mstSet[v] == 0 && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
            pCrawl = pCrawl->next;
        }
    }

    // Print the Minimum Spanning Tree
    printf("Edge \t Weight\n");
    for (int i = 1; i < n; ++i)
    {
        printf("%d - %d \t %d \n", parent[i], i, key[i]);
    }
}


int main()
{
    int V = 5;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    return 0;
}

*/

// AM

/*
#include <stdio.h>

#define V 5

int minKey(int key[], int set[]) {
    int min = 999, index;
    for (int i = 0; i < V; i++) {
        if (set[i] == 0 && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void display(int parent[], int g[V][V]) {
    printf("Edge \t Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t %d \n", parent[i], i, g[i][parent[i]]);
    }
}

void prim(int g[V][V]) {
    int parent[V], key[V], set[V], u;

    for (int i = 0; i < V; i++) {
        key[i] = 999; //initialize the key value to max
        set[i] = 0; // initialize the set for visited node to 0
    }
    key[0] = 0; // consider 0th vertex first
    parent[0] = -1; // parent of 0 th vertex

    for (int i = 0; i < V - 1; i++) {
        u = minKey(key, set); //find the closest vertex
        set[u] = 1;  // mark vertex as visited

        for (int j = 0; j < V; j++) { // for connected vertex of u
            if (g[u][j] != 0 && set[j] == 0 && g[u][j] < key[j]) {
                parent[j] = u;
                key[j] = g[u][j];
            }
        }
    }
    display(parent, g);
}

int main() {
    int g[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    prim(g);

    return 0;
}

*/