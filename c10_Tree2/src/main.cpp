#include <iostream>
#include "HNode.h"
#include "BTNode.h"
using namespace std;

int main(int argc, char **argv) {
    // ## 1
    cout << "计算WPL\n";
    HNode *b = new HNode(0);
    b->l = new HNode(4);
    b->r = new HNode(0);
    b->r->l = new HNode(3);
    b->r->r = new HNode(0);
    b->r->r->l = new HNode(2);
    b->r->r->r = new HNode(1);
    cout << "WPL = " << b->WPL() << "\n";

    // ## 2
    cout << "\n";
    cout << "创建带权二叉树\n";
    BTNode *bt;
    BTNode::init(bt, "A(B(D(F,G),E),C)");
    Display(bt);
    cout << "\n";

    char v[] = "abcd";
    int w[] = {1, 2, 3, 4};
    cout << "赋值叶子: \n";
    SetLeaf(bt, v, w);
    Display(bt);
    cout << "\n";

    cout << "求权值: \n";
    Sum(bt);
    Display(bt);
    cout << "\n";

    cout << "输出哈夫曼编码: \n";
    HuffmanCode(bt);
    Destroy(bt);
    
    // ## 3
    cout << "\n";
    BTree t;
    BTNode *b2;
    BTNode::init(b2, "A(B(D(G),E),C(F(H,I)))");
    cout << "创建另一个二叉树:\n";
    Display(b2);
    cout << "\n";
    t.root = b2;
    cout << "输出最大宽度: " << t.getMaxWidth() << "\n";
    return 0;
}

