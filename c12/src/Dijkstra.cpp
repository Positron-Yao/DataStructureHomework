#include <cstdio>
#include "Dijkstra.h"
#include "MatGraph.h"

void Dijkstra::solve() {
    int mindis, i, j, u = 0;
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[from][i];
        S[i] = 0;
        if (g.edges[from][i] < INF) {
            path[i] = from;
        } else {
            path[i] = -1;
        }
    }
    show_data();
    S[from] = 1;
    for (i = 0; i < g.n - 1; i++) {
        mindis = INF;
        for (j = 0; j < g.n; j++) {
            if (S[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }
        }
        printf("将顶点%d加入S中.\n", u);
        S[u] = 1;
        for (j = 0; j < g.n; j++) {
            if (S[j] == 0) {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
        show_data();
    }
    show();
}

void Dijkstra::show_data() {
    printf("\tdist\t\t\tpath\n");
    for (int i = 0; i < g.n; i++) {
        if (dist[i] == INF) {
            printf("%3s", "  ∞");
        } else {
            printf("%3d", dist[i]);
        }
    }
    printf("\t");
    for (int i = 0; i < g.n; i++) {
        printf("%3d", path[i]);
    }
    printf("\n");
}

void Dijkstra::show() {
    int k;
    int count = 0;
    int apath[MAXVEX], d;
    for (int i = 0; i < g.n; i++) {
        if (path[i] != -1) {
            count++;
        }
    }
    if (count == 1) {
        printf("从该顶点到其他顶点都没有路径\n");
        return;
    }
    for (int i = 0; i < g.n; i++) {
        if (S[i] == 1 && i != from) {
            printf("  从%d到%d最短路径长度为: %d\t路径: ", from ,i, dist[i]);
            d = 0; apath[d] = i;
            k = path[i];
            if (k == -1) {
                printf("无路径\n");
            } else {
                while (k != from) {
                    d++; apath[d] = k;
                    k = path[k];
                }
                d++; apath[d] = from;
                printf("%d", apath[d]);
                for (int j = d - 1; j >= 0; j--) {
                    printf(" -> %d", apath[j]);
                }
                printf("\n");
            }
        }
    }
}
