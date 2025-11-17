#pragma once
#include <cstdlib>
#include "ElemType.h"

namespace SqStack {
    size_t const MaxSize = 100;

    typedef struct {
        ElemType data[MaxSize];
        int top;
    } SqStack;

    void InitStack(SqStack &st);
    void DestroyStack(SqStack &st);
    int Push(SqStack &st, ElemType const &x);
    int Pop(SqStack &st, ElemType &x);
    int GetTop(SqStack const &st, ElemType &x);
    bool StackEmpty(SqStack const &st);
};
