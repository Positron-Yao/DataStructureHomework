#include <cstdio>
#include <cstdlib>
#include "Dijkstra.h"
#include "Floyd.h"
#include "MatGraph.h"
#include "AdjGraph.h"
using namespace std;

int Maxdist(AdjGraph *G, int v);

int main(int argc, char **argv) {
    // ## 1
    system("sentr ' Dijkstra ' 50 =");
    int n = 7, e = 12, from = 0;
    int A[][MAXVEX] = {
        {0, 2, 5, 3, INF, INF, INF},
        {INF, 0, 2, INF, INF, 8, INF},
        {INF, INF, 0, 1, 3, 5, INF},
        {INF, INF, INF, 0, 5, INF, INF},
        {INF, INF, INF, INF, 0, 3, 9},
        {INF, INF, INF, INF, INF, 0, 5},
        {INF, INF, INF, INF, INF, INF, 0},
    };
    printf("Dijkstra 求解结果:\n");
    MatGraph g(A, n, e);
    Dijkstra D(g, from);
    D.solve();
    printf("Floyd 求解结果:\n");
    Floyd F(g);
    F.solve();

    // ## 2
    printf("\n");
    system("sentr ' Max Distance ' 50 =");
    AdjGraph *G;
    int B[MAXVEX][MAXVEX] = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
    };
    n = 5; e = 6;
    CreateGraph(G, B,n, e);
    printf("邻接表G:\n");
    DispGraph(G);
    printf("求解结果:\n");
    for (int v = 0; v < G->n; v++) {
        printf("  距离顶点%d最远的顶点是%d;\n", v, Maxdist(G, v));
    }
    DestroyGraph(G);
    return 0;
}

int Maxdist(AdjGraph *G, int v) {
    ArcNode *p;
    int Qu[MAXVEX], front = 0, rear = 0;
    int visited[MAXVEX], i, j, k;
    for (i = 0; i < G->n; i++) {
        visited[i] = 0;
    }
    rear++;
    Qu[rear] = v;
    while (rear != front) {
        front = (front + 1) % MAXVEX;
        k = Qu[front];
        p = G->adjlist[k].firstarc;
        while (p != nullptr) {
            j = p->adjvex;
            if (visited[j] == 0) {
                visited[j] = 1;
                rear = (rear + 1) % MAXVEX;
                Qu[rear] = j;
            }
            p = p -> nextarc;
        }
    }
    return k;
}
