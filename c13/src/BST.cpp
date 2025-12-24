#include "BST.h"
#include <cstdlib>
#include <cstdio>

int BSTInsert(BSTNode *&bt, KeyType k) {
    BSTNode *f, *p = bt;
    while (p != nullptr) {
        if (p -> key == k) {
            return 0;
        }
        f = p;
        if (k < p->key) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    p = (BSTNode*)malloc(sizeof(BSTNode));
    p->key = k;
    p->lchild = p->rchild = nullptr;
    if (bt == nullptr) {
        bt = p;
    } else if (k < f->key) {
        f->lchild = p;
    } else {
        f->rchild = p;
    }
    return 1;
}

void CreateBST(BSTNode *&bt, KeyType *a, int n) {
    bt = nullptr;
    int i = 0;
    while (i < n) {
        BSTInsert(bt, a[i]);
        i++;
    }
}

void DestroyBST(BSTNode *&bt) {
    if (bt != nullptr) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}

void DispBST(BSTNode *bt) {
    if (bt != nullptr) {
        printf("%d", bt->key);
        if (bt -> lchild != nullptr || bt->rchild != nullptr) {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild != nullptr) {
                printf(",");
            }
            DispBST(bt->rchild);
            printf(")");
        }
    }
}
