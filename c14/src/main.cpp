#include <cstdio>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
struct SqType {
    KeyType key;
    ElemType data;
};

void dispR(SqType R[], int n, int i) {
    if (i == -1) {
        for (int j = 0; j < n; j++) {
            printf("%d ", R[j].key);
        }
        printf("\n");
    } else {
        printf("[");
        for (int j = 0; j < n; j++) {
            if (j == i) {
                printf("%d] ", R[j].key);
            } else {
                printf("%d ", R[j].key);
            }
        }
        printf("\n");
    }
}

void InsertSort(SqType R[], int n) {
    int i, j;
    SqType tmp;
    for (i = 1; i < n; i++) {
        if (R[i-1].key < R[i].key) {
            tmp = R[i];
            j = i - 1;
            do {
                R[j+1] = R[j];
                j--;
            } while (j >= 0 && R[j].key < tmp.key);
            R[j+1] = tmp;
        }
        printf("  i = %d: ", i);
        dispR(R, n, i);
    }
}

void BinInsertSort(SqType R[], int n) {
    int i, j, low, high, mid;
    SqType tmp;
    for (i = 1; i < n; i++) {
        if (R[i-1].key > R[i].key) {
            tmp = R[i];
            low = 0; high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (tmp.key < R[mid].key) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            for (j = i - 1; j >= high + 1; j--) {
                R[j+1] = R[j];
            }
            R[high+1] = tmp;
        }
        printf("  i = %d: ", i);
        dispR(R, n, i);
    }
}

void SHellSort(SqType R[], int n) {
    int i, j, d;
    SqType tmp;
    d = n / 2;
    while (d > 0) {
        for (i = d; i < n; i++) {
            tmp = R[i];
            j = i - d;
            while (j >= 0 && tmp.key < R[j].key) {
                R[j+d] = R[j];
                j = j - d;
            }
            R[j+d] = tmp;
        }
        printf("  d = %d: ", d);
        dispR(R, n, -1);
        d = d / 2;
    }
}

int main(int argc, char **argv) {
    SqType R[MaxSize];
    KeyType A[] = {13, 17, 3, 5, 19, 7, 11, 2};
    int i , n = 8;

    for (i = 0; i < n; i++) R[i].key = A[i];
    printf("原始数据:\n");
    dispR(R, n, 0);
    printf("插入排序:\n");
    InsertSort(R, n);

    printf("\n");
    for (i = 0; i < n; i++) R[i].key = A[i];
    printf("折半插入排序:\n");
    BinInsertSort(R, n);

    printf("\n");
    for (i = 0; i < n; i++) R[i].key = A[i];
    printf("希尔排序:\n");
    SHellSort(R, n);
}
