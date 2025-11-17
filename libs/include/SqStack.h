#pragma once
#include <cstdio>
size_t const MaxSize = 100;

typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &st);
void DestroyStack(SqStack &st);
int Push(SqStack &st, ElemType const &x);
int Pop(SqStack &st, ElemType &x);
int GetTop(SqStack &st, ElemType &x);
bool StackEmpty(SqStack &st);
