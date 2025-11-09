#include <cstdio>
#include "SqList.h"

void DelMaxItems(SqList &L) {
    ElemType max = L.data[0];
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] > max) {
            max = L.data[i];
        }
    }
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] == max) {
            // 移动元素
            for (int j = i; j < L.length - 1; j++) {
                L.data[j] = L.data[j + 1];
            }
            L.length--;
            i--;
        }
    }

}

int main() {
    size_t const size = 8;
    ElemType data[size] = {3, 3, 5, 5, 0, 3, 3, 0};
    SqList L;
    CreateList(L, data, size);
    printf("初始列表: \t");
    DispList(L);
    DelMaxItems(L);
    printf("删除后: \t");
    DispList(L);
    // printf("Hello world\n");
}
