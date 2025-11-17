#include "SqStack.h"

namespace SqStack {

void InitStack(SqStack &st) {
    st.top = -1;
}

void DestroyStack(SqStack &st) {}

int Push(SqStack &st, ElemType const &x) {
    if (st.top == MaxSize - 1) {
        return -1;
    } else {
        st.top++;
        st.data[st.top] = x;
        return 0;
    }
}

int Pop(SqStack &st, ElemType &x) {
    if (st.top == -1) {
        return -1;
    } else {
        x = st.data[st.top];
        st.top--;
        return 0;
    }
}

int GetTop(SqStack const &st, ElemType &x) {
    if (st.top == -1) {
        return -1;
    } else {
        x = st.data[st.top];
        return 0;
    }
}

bool StackEmpty(SqStack const &st) {
    return st.top == -1;
}

} // SqStack
