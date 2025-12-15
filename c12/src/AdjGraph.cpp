#include <cstdio>
#include <cstdlib>
#include "AdjGraph.h"

void CreateGraph(AdjGraph *&G, int A[][MAXVEX], int n, int e) {
    int i, j;
    ArcNode *p;
    G = new AdjGraph;
    G->n = n;
    G->e = e;
    for (i = 0; i < G->n; i++) {
        G->adjlist[i].firstarc = nullptr;
    }
    for (i = 0; i < G->n; i++) {
        for (j = G->n - 1; j >= 0; j--) {
            if (A[i][j] > 0 && A[i][j] < INF) {
                p = new ArcNode;
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
}

void DestroyGraph(AdjGraph *&G) {
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstarc;
        if (pre != nullptr) {
            p = pre->nextarc;
            while (p != nullptr) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void DispGraph(AdjGraph *G) {
    ArcNode *p;
    int i;
    for (i = 0; i < G->n; i++) {
        printf("[%d]", i);
        p = G->adjlist[i].firstarc;
        if (p != nullptr) {
            printf(" -> ");
        }
        while (p != nullptr) {
            printf("%d(%d) ", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
}

int Degree1(AdjGraph *G, int v) {
    int d = 0;
    ArcNode *p;
    if (v < 0 || v >= G->n) {
        return -1;
    }
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        d++;
        p = p->nextarc;
    }
    return d;
}

int Degree2(AdjGraph *G, int v) {
    int i, d1 = 0, d2 = 0, d;
    ArcNode *p;
    if (v < 0 || v >= G->n) {
        return -1;
    }
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        d1++;
        p = p->nextarc;
    }
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        while (p != nullptr) {
            if (p->adjvex == v) d2++;
            p = p->nextarc;
        }
    }
    d = d1 + d2;
    return d;
}

bool CycleSolver::solve_from(int v) {
    ArcNode *p;
    int w;
    visited[v] = true;
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        w = p->adjvex;
        if (!visited[w]) {
            if (solve_from(w)) return true;
        } else return true;
        p = p->nextarc;
    }
    return false;
}

bool CycleSolver::solve() {
    for (int i = 0; i < G->n; i++) {
        for (int j = 0; j < G->n; j++) {
            visited[j] = false;
        }
        if (solve_from(i)) return true;
    }
    return false;
}

int vedge[MAXVEX][MAXVEX];
int edge_count = 0;
void Travelsal(AdjGraph *G, int u, int v, int k, int path[], int d) {
    int w, i;
    ArcNode *p;
    d++; path[d] = v;
    vedge[u][v] = vedge[v][u] = 1;
    p = G->adjlist[v].firstarc;
    while (p != nullptr) {
        w = p->adjvex;
        if (w == k && d == G->e - 1) {
            printf("  路径%d: ", ++edge_count);
            for (i = 0; i <= d; i++) {
                printf("%d -> ", path[i]);
            }
            printf("%d\n", w);
        }
        if (vedge[v][w] == 0) {
            Travelsal(G, v, w, k, path, d);
        }
        p = p->nextarc;
    }
    vedge[u][v] = vedge[v][u] = 0;
}

void FindCPath(AdjGraph *G, int k) {
    int path[MAXVEX];
    int i, j, v;
    ArcNode *p;
    for (i = 0; i < G->n; i++) {
        for (j = 0; j < G->n; j++) {
            if (i == j) vedge[i][j] = 1;
            else vedge[i][j] = 0;
        }
    }
    printf("由%d出发:\n", k);
    path[0] = k;
    p = G->adjlist[k].firstarc;
    while (p != nullptr) {
        v = p->adjvex;
        Travelsal(G, k, v, k, path, 0);
        p = p->nextarc;
    }
}
