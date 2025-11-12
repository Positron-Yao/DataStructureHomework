#include <cstdio>
#include "SqList.h"

void MoveLTZ(SqList &L) {
    size_t lt = 0, i = 0;
    ElemType to_move;
    while (i < L.length) {
        if (L.data[i] < 0) {
            // 移动元素
            to_move = L.data[i];
            for (size_t j = i; j > lt; j--) {
                L.data[j] = L.data[j-1];
            }
            L.data[lt] = to_move;
            lt++;
        }
        i++;
    }
}

int main() {
    size_t const size = 13;
    ElemType data[size] = {1, -1, 9, -1, 1, -4, 9, -5, 8, -1, 1, -4, 0};
    SqList L;
    CreateList(L, data, size);
    printf("初始列表: \t");
    DispList(L);
    MoveLTZ(L);
    printf("移动后: \t");
    DispList(L);
    // printf("Hello world\n");
}
