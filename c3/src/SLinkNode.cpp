#include <cstdlib>
#include <cstdio>
#include "SLinkNode.h"

void CreateNodeList(SLinkNode *&head, int n, ElemType *arr) {
    for (int i = 0; i < n; i++) {
        SLinkNode *p = (SLinkNode *)malloc(sizeof(SLinkNode));
        p->data = arr[i];
        p->next = head;
        head = p;
    }
    SLinkNode *p = (SLinkNode *)malloc(sizeof(SLinkNode));
    p->data = NULL;
    p->next = head;
    head = p;
}

void DestroyNodeList(SLinkNode *&head) {
    if (head != NULL) {
        printf("This is: %d\n", head->data);
        DestroyNodeList(head->next);
        free(head);
    } else {
        printf("End!\n");
    }
}
