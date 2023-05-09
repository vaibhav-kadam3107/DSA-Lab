#include <stdio.h>
#include <stdlib.h>

#define max 50

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

void enQueue(struct queue *q, int val) {
    if(q->r == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if(q->f == -1 && q->r == -1) {
        q->f = q->r = 0;
    }
    else {
        q->r++;
    }
    q->arr[q->r] = val;
}

int dQueue(struct queue *q) {
    if(q->f == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->f];
    if(q->f == q->r) {
        q->f = q->r = -1;
    }
    else {
        q->f++;
    }
    return val;
}

int isEmpty(struct queue *q) {
    if(q->f == -1 || q->f > q->r) {
        return 1;
    }
    return 0;
}

void BFS(int G[max][max], int ver, int start) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *)malloc(sizeof(int)*q->size);

    int visited[max] = {0};

    visited[start] = 1;
    enQueue(q, start);
    while(!isEmpty(q)) {
        start = dQueue(q);
        printf("%d ", start);

        for(int i = 0; i<ver; i++) {
            if(G[start][i] != 0 && visited[i] == 0) {
                enQueue(q, i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int G[max][max], int ver, int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);
    for(int i = 0; i<ver; i++) {
        if(G[start][i] != 0 && visited[i] == 0) {
            DFS(G, ver, i, visited);
        }
    }
}


int main() {
    int ver, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &ver);

    int G[max][max];
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<ver; i++) {
        for(int j=0; j<ver; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(G, ver, start);

    int visited[max] = {0};
    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(G, ver, start, visited);

    return 0;
}
