// am
/*
#include <stdio.h>

#define MAX 10

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, g[MAX][MAX], parent[MAX];

int find_parent(int i){
    while(parent[i]){
        i = parent[i];
    }
    return i;
}

int union_sets(int i, int j){
    if(i != j){
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal(int g[MAX][MAX], int n)
{
    printf("MST: ");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (g[i][j] < min)
                {
                    min = g[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find_parent(u);
        v = find_parent(v);

        if (union_sets(u, v))
        {
            printf("(%d , %d) = %d, ", a, b, min);
            mincost += min;
            ne++;
        }
        g[a][b] = g[b][a] = 999;
    }
    printf("\nMinimum Cost : %d", mincost);
}

int main()
{
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }

    kruskal(g, n);

    return 0;
}

*/

//AL
/*
#include <stdio.h>
#include <stdlib.h>

// structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// structure to represent a graph with adjacency list representation
struct Graph
{
    int V, E;
    struct Edge *edge;
};

// create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

// find the parent of a vertex i
int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}

// perform union of two subsets
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// compare two edges based on their weights
int compare(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

// function to find Minimum Spanning Tree of a graph using Kruskal's algorithm
void kruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0, i = 0;

    // sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // allocate memory for parent array
    int *parent = (int *)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++)
    {
        parent[v] = -1;
    }

    // process sorted edges one by one
    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // print the Minimum Spanning Tree
    printf("Minimum Spanning Tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%d - %d \t %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Total weight of the Minimum Spanning Tree: %d\n", minimumCost);
}

// driver function
int main()
{
    int V = 4; // number of vertices in graph
    int E = 5; // number of edges in graph
    struct Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);

    return 0;
}

*/