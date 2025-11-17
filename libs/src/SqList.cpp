#include <cstdio>
#include "SqList.h"

namespace SqList {

void InitList(SqList &L) {
    L.length = 0;
}

void DestroyList(SqList &L) {}

size_t GetLength(SqList const &L) {
    return L.length;
}

int GetElem(SqList const &L, size_t i, ElemType &e) {
    if (i < 1 || i > MaxSize) {
        return 0;
    } else {
        e = L.data[i - 1];
        return 1;
    }
}

size_t Locate(SqList const &L, ElemType const &e) {
    for (size_t i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

int InsElem(SqList &L, size_t i, ElemType const &e) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    for (size_t j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return 1;
}

int DelElem(SqList &L, size_t i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    for (size_t j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return 1;
}

void DispList(SqList const &L) {
    for (size_t i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void CreateList(SqList &L, ElemType e[], size_t n) {
    for (int i = 0; i < n; i++) {
        L.data[i] = e[i];
    }
    L.length = n;
}

} // SqList
