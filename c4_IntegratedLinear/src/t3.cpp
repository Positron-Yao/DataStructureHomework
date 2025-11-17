#include <cstdio>
#include "SLinkNode.h"

void DeleteRange(SLinkNode::SLinkNode *&L, ElemType min, ElemType max) {
    if (L == NULL || L->next == NULL) return;
    DelIf(L, [min, max](SLinkNode::SLinkNode *L){return L->data >= min && L->data <= max;});
}

int main(int argc, char** argv) {
    size_t const size = 8;
    ElemType data[size] = {1, 2, 3, 4, 5, 6, 7, 8};
    SLinkNode::SLinkNode *h;
    SLinkNode::CreateListR(h, data, size);
    printf("初始数据: \t");
    SLinkNode::DispList(h);
    DeleteRange(h, 3, 6);
    printf("删除[3, 6]: \t");
    SLinkNode::DispList(h);
    // printf("Hello world.\n");
    return 0;
}
