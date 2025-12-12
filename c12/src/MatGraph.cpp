#include <cstdio>
#include "MatGraph.h"

MatGraph::MatGraph(int A[][MAXVEX], int n, int e): n(n), e(e) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = A[i][j];
        }
    }
}

void MatGraph::show() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (edges[i][j] < INF) {
                printf("%4d", edges[i][j]);
            } else {
                printf("%4s", "∞");
            }
        }
        printf("\n");
    }
}

int MatGraph::degree1(int v) {
    if (v < 0 || v >= n) {
        return -1;
    }
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (edges[v][i] > 0 && edges[v][i] < INF) {
            d++;
        }
    }
    return d;
}

int MatGraph::degree2(int v) {
    if (v < 0 || v >= n) {
        return -1;
    }
    int d1 = 0, d2 = 0, d;
    for (int i = 0; i < n; i++) {
        if (edges[v][i] > 0 && edges[v][i] < INF) {
            d1++;
        }
        if (edges[i][v] > 0 && edges[i][v] < INF) {
            d2++;
        }
    }
    d = d1 + d2;
    return d;
}
