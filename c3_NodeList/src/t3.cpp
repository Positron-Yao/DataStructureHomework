#include <cstdio>
#include "SLinkNode.h"

int MoveLTZ(SLinkNode *&L) {
    if (L == NULL || L->next == NULL) return 0;
    SLinkNode *ltz = L, *z = L, *pre = L, *p = pre->next;
    while (p != NULL) {
        if (p->data < 0) {
        // 处理负数
            pre->next = p->next;    // 断开连接
            p->next = ltz->next;    // 接入ltz
            ltz->next = p;
            p = pre->next;          // p前进
            ltz = ltz->next;        // ltz前进
            z = z->next;            // z前进
        } else if (p->data == 0) {
        // 处理0
            pre->next = p->next;    // 断开连接
            p->next = z->next;      // 接入z
            z->next = p;
            p = pre->next;          // p前进
            z = z->next;            // z前进, ltz不前进
        } else {
            pre = p;
            p = p->next;
        }
    }
    return 1;
}

int main() {
    size_t const size = 13;
    ElemType data[size] = {1, -1, 9, -1, 1, -4, 9, -5, 8, -1, 1, -4, 0};
    SLinkNode *head;
    CreateListR(head, data, size);
    printf("初始数据: \t");
    DispList(head);
    MoveLTZ(head);
    printf("移动后: \t");
    DispList(head);
    return 0;
}

