#include <cstdio>
#include "SLinkNode.h"

int main(int argc, char** argv) {
    size_t const size = 5;
    ElemType data[size] = {1, 2, 3, 4, 5};
    SLinkNode *head;
    CreateListR(head, data, size);
    printf("创建链表: \t");
    DispList(head);

    InsElem(head, 2, 9);
    printf("在第2位插入9: \t");
    DispList(head);

    DelElem(head, 4);
    printf("删除第4位: \t");
    DispList(head);

    Reverse(head);
    printf("反转后: \t");
    DispList(head);

    printf("冒泡排序:\n");
    printf("  - 升序: \t");
    BubbleSort(head, true);
    DispList(head);
    printf("  - 降序: \t");
    BubbleSort(head, false);
    DispList(head);

    ElemType d1[size] = {1, 3, 5, 7, 9};
    ElemType d2[size] = {0, 2, 4, 6, 8};
    SLinkNode *h1, *h2, *m;
    CreateListR(h1, d1, size);
    CreateListR(h2, d2, size);
    printf("二路归并:\n");
    printf("  - h1: \t");
    DispList(h1);
    printf("  - h2: \t");
    DispList(h2);
    printf("  - 结果: \t");
    Merge(h1, h2, m);
    DispList(m);

    DestroyNodeList(head);
    return 0;
}
