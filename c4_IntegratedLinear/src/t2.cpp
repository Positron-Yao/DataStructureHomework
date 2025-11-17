#include <cstdio>
#include "SqList.h"

void Merge(SqList const &L1, SqList const &L2, SqList &L) {
    size_t i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {
            L.data[k++] = L1.data[i];
            L.length++;
            i++;
        } else {
            L.data[k++] = L2.data[i];
            L.length++;
            j++;
        }
    }
    while (i < L1.length) {
        L.data[k++] = L1.data[i];
        L.length++;
        i++;
    }
    while (j < L2.length) {
        L.data[k++] = L2.data[j];
        L.length++;
        j++;
    }
}

int main() {
    size_t const size = 5;
    ElemType d1[size] = {1, 3, 5, 7, 9};
    ElemType d2[size] = {0, 2, 4, 6, 8};
    SqList l1, l2, l;
    CreateList(l1, d1, size);
    CreateList(l2, d2, size);
    InitList(l);
    printf("初始数据: \n");
    printf("  - l1: \t");
    DispList(l1);
    printf("  - l2: \t");
    DispList(l2);
    Merge(l1, l2, l);
    printf("归并后: \n");
    printf("  - l: \t\t");
    DispList(l);
    // printf("Hello world.\n");
    return 0;
}
