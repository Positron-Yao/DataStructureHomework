#include <cstdio>
#include "Graph.h"
using namespace std;

int main(int argc, char **argv) {
    // ## 1
    AdjGraph *G;
    int A[][MAXVEX] = {
        {0,		2,		5,		3,		INF,	INF,	INF},
        {INF,	0,		2,		INF,	INF,	8,		INF},
        {INF,	INF,	0,		1,		3,		5,		INF},
        {INF,	INF,	INF,	0,		5,		INF,	INF},
        {INF,	INF,	INF,	INF,	0,		3,		9},
        {INF,	INF,	INF,	INF,	INF,	0,		5},
        {INF,	INF,	INF,	INF,	INF,	INF,	0},
    };
    int n = 7, e = 12;
    CreateGraph(G, A, n, e);
    printf("输出存储结构:\n");
    DispGraph(G);
    printf("图中所有顶点的度:\n");
    printf("\t顶点\t度\n");
    for (int i = 0; i < G->n; i++) {
        printf("\t%d\t%d\n", i, Degree2(G, i));
    }
    DestroyGraph(G);

    // ## 2
    printf("\n");
    AdjGraph *B, *C;
    int b[][MAXVEX] = {
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
    };
    n = 5; e = 7;
    CreateGraph(B, b, n, e);
    printf("邻接表B:\n");
    DispGraph(B);
    printf("B中%s存在环\n", (CycleSolver(B).solve()) ? "" : "不");
    DestroyGraph(B);

    int c[][MAXVEX] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
    };
    n = 5; e = 6;
    CreateGraph(C, c, n, e);
    printf("邻接表C:\n");
    DispGraph(C);
    printf("C中%s存在环\n", (CycleSolver(C).solve()) ? "" : "不");
    DestroyGraph(C);

    // ## 3
    printf("\n");
    int D[MAXVEX][MAXVEX] = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
    };
    n = 5; e = 6;
    CreateGraph(G, D, n, e);
    printf("邻接表D:\n");
    DispGraph(G);
    printf("路径:\n");
    int v = 4;
    FindCPath(G, v);
    printf("\n");
    DestroyGraph(G);

    return 0;
}
