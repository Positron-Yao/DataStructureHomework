#include <cstdio>
#include <memory>
#include "Dijkstra.h"
#include "Floyd.h"
#include "MatGraph.h"
using namespace std;

int main(int argc, char **argv) {
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
    return 0;
}

