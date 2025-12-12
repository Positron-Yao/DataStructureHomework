#pragma once
#include "MatGraph.h"

struct Floyd {
    int A[MAXVEX][MAXVEX];
    int path[MAXVEX][MAXVEX];
    MatGraph g;

    Floyd(MatGraph g): g(g) {};
    void solve();
    void show_data(int k);
    void show();
};
