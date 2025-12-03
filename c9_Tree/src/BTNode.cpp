#include "BTNode.h"

namespace BTNode {

BTNode *create(BTNode *& bt, char const *str) {
    bt = nullptr;
    BTNode *st[MaxSize], *p=nullptr;
    int top = -1, k, j = 0;
    char ch = str[j];

    while (ch != '\0') {
        switch (ch) {
            case '(': top++; st[top] = p; k = 1; break;
            case ')': top--; break;
            case ',': k = 2; break;
            default: 
                p = new BTNode;
                p->data = ch;
                p->left = p->right = nullptr;
                if (bt == nullptr) {
                    bt = p;
                } else {
                    switch (k) {
                        case 1: st[top]->left = p; break;
                        case 2: st[top]->right = p; break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
    return bt;
}

}; // BTNode
