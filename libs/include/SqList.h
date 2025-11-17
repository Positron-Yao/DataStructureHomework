#pragma once
#include <cstdlib>
#include "ElemType.h"

namespace SqList {
    int const MaxSize = 1024;

    typedef struct {
        ElemType data[MaxSize];
        size_t length;
    } SqList;

    void InitList(SqList &L);
    void DestroyList(SqList &L);
    size_t GetLength(SqList const &L);
    int GetElem(SqList const &L, size_t i, ElemType &e);
    size_t Locate(SqList const &L, ElemType const &e);
    int InsElem(SqList &L, size_t i, ElemType const &e);
    int DelElem(SqList &L, size_t i);
    void DispList(SqList const &L);
    void CreateList(SqList &L, ElemType e[], size_t n);
};
