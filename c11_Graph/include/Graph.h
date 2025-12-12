#pragma once

int const MAXVEX = 100;
int const INF = 32767;

typedef char VertexType[10];
struct ArcNode {
    int adjvex;
    int weight;
    ArcNode *nextarc;
};

struct VHeadNode {
    VertexType data;
    ArcNode *firstarc;
};

struct AdjGraph {
    int n, e;
    VHeadNode adjlist[MAXVEX];
};

void CreateGraph(AdjGraph *&G, int A[][MAXVEX], int n, int e);
void DestroyGraph(AdjGraph *&G);
void DispGraph(AdjGraph *G);
int Degree1(AdjGraph *G, int v);
int Degree2(AdjGraph *G, int v);

class CycleSolver {
    public:
        CycleSolver(AdjGraph *G): G(G) {}
        bool solve();
        bool solve_from(int v);

    private:
        AdjGraph *G;
        bool visited[MAXVEX];
};

void Travelsal(AdjGraph *G, int u, int v, int k, int path[], int d);
void FindCPath(AdjGraph *G, int k);
