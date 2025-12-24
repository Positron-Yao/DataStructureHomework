#include <stdio.h>
#include "BinSearch.h"

int BinSearchCount(SqType R[], int n, int k, int &count) {
    int low = 0, high = n - 1, mid;
    count = 0;
    bool tail = false;
    printf("(");
    while (low <= high) {
        mid = (low + high) / 2;
        count++;
        printf("%s%d", tail? " " : "", mid);
        tail = true;
        if (R[mid].key == k) {
            printf(") ");
            return mid + 1;
        } else if (R[mid].key > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf(") ");
    return 0;
}

int BinSearch(SqType R[], int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (R[mid].key == k) {
            return mid + 1;
        } else if (R[mid].key > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}

