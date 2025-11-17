#include <cstdio>
#include <vector>
#include "ElemType.h"
#include "LinkStack.h"
using Stack = LinkStack::LinkStack;
using namespace LinkStack;

bool CheckStackSequence(std::vector<ElemType> const seq) {
    size_t len = seq.size();
    Stack st;
    InitStack(st);
    ElemType x;
    int p_seq = 0, st_top = 1;
    Push(st, st_top);
    while (p_seq < len && st_top < len) {
        // printf("检查 st_top = %d, seq[p_seq] = %d\n", st_top, seq[p_seq]);
        if (st_top < seq[p_seq]) {
            st_top++;
            Push(st, st_top);
        } else if (st_top == seq[p_seq]) {   // 验证成功
            Pop(st, x);
            p_seq++;
        } else {
            return false;
        }
    }
    while (!StackEmpty(st)) {
        Pop(st, x);
        if (x != seq[p_seq]) {
            return false;
        }
        p_seq++;                        // 验证成功
    }
    return true;
}

int main() {
    std::vector<ElemType> v1 {4, 3, 2, 1};
    printf("序列为: ");
    for (auto x: v1) {
        printf("%d ", x);
    }
    printf("\n");
    if (CheckStackSequence(v1)) {
        printf("该序列是可实现的\n");
    } else {
        printf("该序列不可实现\n");
    }

    std::vector<ElemType> v2 {2, 4, 1, 3};
    printf("序列为: ");
    for (auto x: v2) {
        printf("%d ", x);
    }
    printf("\n");
    if (CheckStackSequence(v2)) {
        printf("该序列是可实现的\n");
    } else {
        printf("该序列不可实现\n");
    }
}
