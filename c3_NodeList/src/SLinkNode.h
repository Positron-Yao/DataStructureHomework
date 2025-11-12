#pragma once
#include <cstdlib>
#include <functional>

typedef int ElemType;

typedef struct _SLinkNode {
    ElemType data;
    struct _SLinkNode *next;
} SLinkNode;

void DispList(SLinkNode *L);
void InitList(SLinkNode *&L);
void MakeNode(SLinkNode *&p, ElemType e);
void TailNode(SLinkNode *L, SLinkNode *&t);
void Append(SLinkNode *&L, ElemType e);
void Prepend(SLinkNode *&L, ElemType e);
void DestroyNodeList(SLinkNode *&L);
size_t GetLength(SLinkNode *L);
int GetElem(SLinkNode *L, size_t i, ElemType &e);
int GetNode(SLinkNode *L, size_t i, SLinkNode *&g);
size_t Locate(SLinkNode *L, ElemType e);
int InsElem(SLinkNode *&L, size_t i, ElemType x);
int DelElem(SLinkNode *&L, size_t i);
int DelIf(SLinkNode *&L, std::function<bool(SLinkNode*)>);
int CreateListL(SLinkNode *&L, ElemType arr[], size_t n);
int CreateListR(SLinkNode *&L, ElemType arr[], size_t n);

void Reverse(SLinkNode *&L);
void Merge(SLinkNode *L1, SLinkNode *L2, SLinkNode *&L);
void BubbleSort(SLinkNode *&L, bool increasing=true);

