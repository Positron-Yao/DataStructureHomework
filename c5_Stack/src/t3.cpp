#include <cstdio>
#include "ElemType.h"
#include "SqStack.h"
using Stack = SqStack::SqStack;
using namespace SqStack;

int DelMatchedElem(Stack &st, ElemType const &e) {
    ElemType t;
    Stack ret;
    InitStack(ret);
    while (!StackEmpty(st)) {
        Pop(st, t);
        if (t != e) Push(ret, t);
    }
    while (!StackEmpty(ret)) {
        Pop(ret, t);
        Push(st, t);
    }
    return 0;
}

int main() {
    Stack st;
    InitStack(st);
    printf("入栈: a b a c a d a \n");
    Push(st, 'a');
    Push(st, 'b');
    Push(st, 'a');
    Push(st, 'c');
    Push(st, 'a');
    Push(st, 'd');
    Push(st, 'a');
    DelMatchedElem(st, 'a');
    printf("出栈: ");
    ElemType t;
    while (!StackEmpty(st)) {
        Pop(st, t);
        printf("%c ", t);
    }
    printf("\n");
    return 0;
}
