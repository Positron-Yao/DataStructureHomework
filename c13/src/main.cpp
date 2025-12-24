#include <cstdio>
#include "BinSearch.h"
#include "BST.h"

void ReOrder(BSTNode *bt) {
    if (bt != nullptr) {
        ReOrder(bt->rchild);
        printf("%d ", bt->key);
        ReOrder(bt->lchild);

    }
}

int main(int argc, char **argv) {
    // # 1
    printf("#1 有序顺序表折半查找:\n");
    int i, j;
    int const n = 10;
    KeyType a[n] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    SqType R[MaxSize];
    for (i = 0; i < n; i++) {
        R[i].key = a[i];
    }
    printf("结果: \n");
    for (j = 0; j < n; j++) {
        i = BinSearch(R, n, a[j]);
        printf("[%2d]: %2d\n", i, a[j]);
    }
    printf("\n");

    // # 2
    printf("#2 折半查找比较次数:\n");
    int const m = 8;
    int b[m] = {1, 3, 6, 11, 13, 17, 21, 50};
    printf("查找比对:\n");
    int count;
    for (i = 0; i < m; i++) {
        printf("查找%2d: ", b[i]);
        int res = BinSearchCount(R, n, b[i], count);
        printf("%s\t查找%s, 比对次数: %d\n",
                (count < 3 ? "\t" : ""),
                (res ? "成功" : "失败"),
                count);
    }
    printf("\n");

    // # 3
    printf("#3 递减有序输出二叉排序树的结点&关键字\n");
    KeyType c[n] = {19, 13, 2, 7, 29, 3, 5, 17, 11, 23};
    BSTNode *bt;
    CreateBST(bt, c, n);
    printf("二叉排序树:\n");
    DispBST(bt);
    printf("输出:\n");
    ReOrder(bt);
    printf("\n");
    DestroyBST(bt);
}

