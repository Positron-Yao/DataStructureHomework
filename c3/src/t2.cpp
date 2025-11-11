#include <cstdio>
#include "SLinkNode.h"

void DelRepetition(SLinkNode *&L) {
    if (L == NULL || L->next == NULL) return;
    SLinkNode *p = L->next, *h;
    MakeNode(h, 0);
    while (p != NULL && p->next != NULL) {
        h->next = p->next;
        DelIf(h, [p](SLinkNode *n) {
            return n->data == p->data;
        });
        p->next = h->next;
        p = h->next;
    }
}

int main() {
    size_t const size = 21;
    ElemType data[size] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0, 3, 3, 5, 5, 0, 3, 3, 6};
    SLinkNode *head;
    CreateListR(head, data, size);
    printf("初始数据: \t");
    DispList(head);
    DelRepetition(head);
    printf("去重后: \t");
    DispList(head);
    // printf("Hello world\n");
    return 0;
}
