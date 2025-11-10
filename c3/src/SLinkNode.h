#pragma once

typedef int ElemType;

typedef struct _SLinkNode {
    ElemType data;
    struct _SLinkNode *next;
} SLinkNode;

void CreateNodeList(SLinkNode *&head, int n, ElemType arr[]);
void DestroyNodeList(SLinkNode *&head);

