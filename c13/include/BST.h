#pragma once
typedef int KeyType;
typedef char ElemType;
struct BSTNode {
    KeyType key;
    ElemType data;
    BSTNode *lchild, *rchild;
};

int BSTInsert(BSTNode *&bt, KeyType k);
void CreateBST(BSTNode *&bt, KeyType a[], int n);
void DestroyBST(BSTNode *&bt);
void DispBST(BSTNode *bt);

