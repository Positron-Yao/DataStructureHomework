#include "LinkStack.h"
#include "SLinkNode.h"

namespace LinkStack {

void InitStack(LinkStack &st) {
    SLinkNode::InitList(st.head);
}

void DestroyStack(LinkStack &st) {
    SLinkNode::DestroyNodeList(st.head);
}

int Push(LinkStack &st, ElemType const &x) {
    SLinkNode::Prepend(st.head, x);
    return 0;
}

int Pop(LinkStack &st, ElemType &x) {
    if (StackEmpty(st)) {
        return -1;
    }
    x = st.head->next->data;
    SLinkNode::DelElem(st.head, 1);
    return 0;
}

int GetTop(LinkStack const &st, ElemType &x) {
    if (StackEmpty(st)) {
        return -1;
    }
    x = st.head->next->data;
    return 0;
}

bool StackEmpty(LinkStack const &st) {
    if (st.head->next == nullptr) {
        return true;
    } else {
        return false;
    }
}

} // LinkStack
