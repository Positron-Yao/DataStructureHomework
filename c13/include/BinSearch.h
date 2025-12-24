#pragma once
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
struct SqType {
    KeyType key;
    ElemType data;
};

int BinSearchCount(SqType R[], int n, int k, int &count);
int BinSearch(SqType R[], int n, int k);
