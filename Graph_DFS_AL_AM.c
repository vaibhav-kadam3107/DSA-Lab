//AL
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dest;
    struct node* next;
};

struct graph
{
    int V;
    struct node** adjList;
};

struct graph* createGraph(int V)
{
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    G->V = V;
    G->adjList = (struct node**)malloc(V * sizeof(struct node*));
    for (int i = 0; i < V; i++)
    {
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(struct graph* G, int src, int dest)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->dest = dest;
    newNode->next = G->adjList[src];
    G->adjList[src] = newNode;
}

void DFSUtil(struct graph* G, int v, int visited[])
{
    visited[v] = 1;
    printf("%d ", v);
    struct node* temp = G->adjList[v];
    while (temp != NULL)
    {
        int adjV = temp->dest;
        if (visited[adjV] == 0)
        {
            DFSUtil(G, adjV, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct graph* G, int start)
{
    int visited[G->V];
    for (int i = 0; i < G->V; i++)
    {
        visited[i] = 0;
    }
    DFSUtil(G, start, visited);
}

int main()
{
    int V, E, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct graph* G = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(G, src, dest);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &src);
    /*
       0
      / \
     1 - 2
          \
           3

    
    printf("DFS traversal: ");
    DFS(G, src);
    return 0;
}

*/

//AM

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct node {
    int vertex;
    struct node* next;
};

struct stack {
    int top;
    int arr[MAX_NODES];
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct node* A[], int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = A[src];
    A[src] = newNode;

    newNode = createNode(src);
    newNode->next = A[dest];
    A[dest] = newNode;
}

struct stack* createStack() {
    struct stack* s = malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

int Empty(struct stack* s) {
    return s->top == -1;
}

void push(struct stack* s, int item) {
    s->top++;
    s->arr[s->top] = item;
}

int pop(struct stack* s) {
    int item = s->arr[s->top];
    s->top--;
    return item;
}

void DFS(struct node* A[], int n) {
    struct node* p;
    int v, visited[MAX_NODES], f;
    struct stack* s = createStack();

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the start vertex: ");
    scanf("%d", &v);

    visited[v] = 1;
    printf("%d ", v);
    push(s, v);

    do {
        p = A[v];
        while (p != NULL) {
            if (visited[p->vertex] == 0) {
                visited[p->vertex] = 1;
                printf("%d ", p->vertex);
                push(s, p->vertex);
                v = p->vertex;
                break;
            } else {
                p = p->next;
            }
        }

        if (p == NULL) {
            f = pop(s);
            if (!Empty(s)) {
                v = s->arr[s->top];
            }
        }

    } while (!Empty(s));
}
/*
void DFS(int g[][20], int v, int visited[], int n)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
    {
        if (g[v][i] != 0 && visited[i] == 0)
        {
            DFS(g, i, visited, n);
        }
    }
}


int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct node* A[V];
    for (int i = 0; i < V; i++) {
        A[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (source, destination):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(A, src, dest);
    }

    DFS(A, V);
    printf("\n");

    return 0;
}

*/