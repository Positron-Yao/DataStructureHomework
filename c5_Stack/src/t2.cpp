#include <cstdio>
#include "LinkStack.h"
using Stack = LinkStack::LinkStack;
using namespace LinkStack;

int main(int argc, char** argv) {
    Stack st;
    printf("初始化st\n");
    InitStack(st);
    printf("栈为 %s\n", StackEmpty(st) ? "空" : "非空");
    printf("入栈\n");
    Push(st, 'e');
    Push(st, 'f');
    Push(st, 'g');
    Push(st, 'h');
    printf("栈为 %s\n", StackEmpty(st) ? "空" : "非空");
    ElemType x;
    GetTop(st, x);
    printf("栈顶元素: %c\n", x);

    printf("出栈: ");
    while (!StackEmpty(st)) {
        Pop(st, x);
        printf("%c ", x);
    }
    printf("\n");
    printf("栈为 %s\n", StackEmpty(st) ? "空" : "非空");
    return 0;
}
