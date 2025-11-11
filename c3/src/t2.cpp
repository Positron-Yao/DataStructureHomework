#include <cstdio>
#include "SLinkNode.h"

void OrderedDelRepetition(SLinkNode *&L) {
    if (L == NULL || L->next == NULL) return;
    SLinkNode *pre = L->next, *p = pre->next;
    while (p != NULL) {
        if (pre->data == p->data) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = pre->next;
        }
    }
}

int main() {
    size_t const size = 15;
    ElemType data[size] = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5};
    SLinkNode *head;
    CreateListR(head, data, size);
    printf("初始数据: \t");
    DispList(head);
    OrderedDelRepetition(head);
    printf("去重后: \t");
    DispList(head);
    // printf("Hello world\n");
    return 0;
}
