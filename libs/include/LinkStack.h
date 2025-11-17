#pragma once
#include "ElemType.h"
#include "SLinkNode.h"

namespace LinkStack {
    typedef struct {
        SLinkNode::SLinkNode *head;
    } LinkStack;

    void InitStack(LinkStack &st);
    void DestroyStack(LinkStack &st);
    int Push(LinkStack &st, ElemType const &x);
    int Pop(LinkStack &st, ElemType &x);
    int GetTop(LinkStack const &st, ElemType &x);
    bool StackEmpty(LinkStack const &st);
};
