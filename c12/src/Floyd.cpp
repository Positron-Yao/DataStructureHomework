#include <cstdio>
#include "Floyd.h"
#include "MatGraph.h"

void Floyd::solve() {
    int i, j, k;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    show_data(-1);
    for (k = 0; k < g.n; k++) {
        for (i = 0; i < g.n; i++) {
            for (j = 0; j < g.n; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
        show_data(k);
    }
    show();
}

void Floyd::show_data(int k) {
    int i, j;
    printf("\tA[%d]\t\t\t\tpath[%d]\n", k, k);
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            if (A[i][j] == INF) {
                printf("%4s", "   ∞");
            } else {
                printf("%4d", A[i][j]);
            }
        }
        printf("\t");
        for (j = 0; j < g.n; j++) {
            printf("%4d", path[i][j]);
        }
        printf("\n");
    }
}

void Floyd::show() {
    int i, j, k, s;
    int apath[MAXVEX], d;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            if (A[i][j] != INF && i != j) {
                printf("  顶点%d到%d的最短路径长度: %d\t路径: ", i, j, A[i][j]);
                k = path[i][j];
                d = 0; apath[d] = j;
                while (k != -1 && k != i) {
                    d++; apath[d] = k;
                    k = path[i][k];
                }
                d++; apath[d] = i;
                printf("%d", apath[d]);
                for (s = d - 1; s >= 0; s--) {
                    printf(" -> %d", apath[s]);
                }
                printf("\n");
            }
        }
    }
}
