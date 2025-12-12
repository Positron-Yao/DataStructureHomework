#pragma once

int const MAXVEX = 100;
int const INF = 32767;

typedef char VertexType[10];

struct VType {
    int adjvex;
    VertexType data;
};

struct MatGraph {
    int n, e;
    VType vexs[MAXVEX];
    int edges[MAXVEX][MAXVEX];

    MatGraph(int A[][MAXVEX], int n, int e);
    void show();
    int degree1(int v);
    int degree2(int v);
};


