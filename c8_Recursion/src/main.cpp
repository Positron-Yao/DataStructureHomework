#include <functional>
#include <iostream>
#include "ElemType.h"
#include "SLinkNode.h"
using Node = SLinkNode::SLinkNode;
using namespace std;
using namespace SLinkNode;

int FindFlag(Node *&L, ElemType &x, bool max);
int FindMax(Node *&L, ElemType &x);
int FindMin(Node *&L, ElemType &x);
void Display(Node *&L);
void RevDisplay(Node *&L);

int main(int argc, char **argv) {
    size_t const size = 10;
    ElemType data[size] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9};
    Node *L;
    CreateListR(L, data, size);
    cout << "正向输出: \t";
    Display(L);
    cout << "反向输出: \t";
    RevDisplay(L);
    ElemType max, min;
    FindMax(L, max);
    FindMin(L, min);
    cout << "Max: \t" << max << "\n";
    cout << "Min: \t" << min << "\n";
    // std::cout << "hello world!" << std::endl;
    return 0;
}

int FindFlag(Node *&L, ElemType &x, bool max=true) {
    if (L == nullptr || L->next == nullptr) {
        return -1;
    }
    x = L->next->data;
    function<void(Node *&, ElemType &)> FindMaxHelper = [&](Node *&L, ElemType &x) {
        if (L != nullptr) {
            if ((L->data < x) ^ max) {
                x = L->data;
            }
            FindMaxHelper(L->next, x);
        }
    };
    FindMaxHelper(L->next, x);
    return 0;
}

int FindMax(Node *&L, ElemType &x) {
    return FindFlag(L, x, true);
}

int FindMin(Node *&L, ElemType &x) {
    return FindFlag(L, x, false);
}

void Display(Node *&L) {
    cout << "HEAD -> ";
    DispList(L);
}

void RevDisplay(Node *&L) {
    if (L == nullptr || L->next == nullptr) {
        return;
    }
    function<void(Node *&L)> RevDisplayHelper = [&](Node *&L) {
        if (L != nullptr) {
            RevDisplayHelper(L->next);
            cout << L->data << " <- ";
        }
    };
    RevDisplayHelper(L->next);
    cout << "HEAD\n";
}

