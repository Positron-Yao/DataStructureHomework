#pragma once
#include "MatGraph.h"

class Dijkstra {
    private:
        MatGraph g;
        int from;
        int dist[MAXVEX], path[MAXVEX], S[MAXVEX];

    public:
        Dijkstra(MatGraph g, int from): g(g), from(from) {}

        // 输出disp和path
        void show_data();

        // 输出从v出发的所有最短路径
        void show();

        // 求解
        void solve();
};
