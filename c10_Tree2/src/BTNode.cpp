#include <iostream>
#include "BTNode.h"

void Destroy(BTNode *&bt) {
    if (bt != nullptr) {
        Destroy(bt->l);
        Destroy(bt->r);
        free(bt);
    }
}

void Display(BTNode *bt) {
    if (bt != nullptr) {
        std::cout << bt->data << "[" << bt->w << "]";
        if (bt->l != nullptr || bt->r != nullptr) {
            std::cout << "( ";
            Display(bt->l);
            if (bt->r != nullptr) {
                std::cout << ", ";
            }
            Display(bt->r);
            std::cout << " )";
        }
    }
}

void SetLeaf_helper(BTNode *&bt, char v[], int w[], int &i) {
    if (bt != nullptr) {
        if (bt->l == nullptr && bt->r == nullptr) {
            bt->data = v[i];
            bt->w = w[i];
            i++;
        }
        SetLeaf_helper(bt->l, v, w, i);
        SetLeaf_helper(bt->r, v, w, i);
    }
}

void SetLeaf(BTNode *&bt, char v[], int w[]) {
    int i = 0;
    SetLeaf_helper(bt, v, w, i);
}

int Sum(BTNode *bt) {
    if (bt != nullptr) {
        if (bt->l != nullptr && bt->r != nullptr) {
            int s = Sum(bt->l) + Sum(bt->r);
            bt->w = s;
            return s;
        } else {
            return bt->w;
        }
    } else {
        return 0;
    }
}

void HuffmanCode_helper(BTNode *bt, char hc[], int d) {
    if (bt == nullptr) return;
    if (bt->l == nullptr && bt->r == nullptr) {
        std::cout << bt->data << ": ";
        for (int i = 0; i <= d; i++) {
            std::cout << hc[i];
        }
        std::cout << "\n";
    } else {
        d++;
        hc[d] = '0';
        HuffmanCode_helper(bt->l, hc, d);
        hc[d] = '1';
        HuffmanCode_helper(bt->r, hc, d);
    }
}

void HuffmanCode(BTNode *bt) {
    char hc[1000];
    int d = -1;
    HuffmanCode_helper(bt, hc, d);
}

