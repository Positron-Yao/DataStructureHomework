#include <cstdio>
#include "SqList.h"

void DelDup(SqList::SqList &L) {
    // 有序线性表的去重
    for (int i = 0; i < L.length; i++) {
        for (int j = i + 1; j < L.length; j++) {
            if (L.data[i] == L.data[j]) {
                // 找到重复元素，删除后面的元素
                for (int k = j; k < L.length - 1; k++) {
                    L.data[k] = L.data[k + 1];
                }
                L.length--;
                j--;
            }
        }
    }
}

int main() {
    size_t const size = 10;
    ElemType data[size] = {1, 1, 4, 5, 1, 4, 1, 9, 1 ,9};
    SqList::SqList l;
    SqList::CreateList(l, data, size);
    printf("初始数据: \t");
    SqList::DispList(l);
    DelDup(l);
    printf("去重后: \t");
    SqList::DispList(l);
    // printf("Hello world.\n");
    return 0;
};
