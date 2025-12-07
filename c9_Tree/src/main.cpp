#include <iostream>
#include "BTNode.h"
using namespace std;
using BT = BTNode::BTNode;

int main(int argc, char **argv) {
    cout << "创建二叉树\n";
    BT *bt = new BT("a( b( c, d ), e( f, g( h, i ) ) )");
    bt->create<int>();
    cout << "输出二叉树: \t";
    bt->show<int>();
    cout << "\n";
    cout << "树的高度: \t" << bt->get_height() << "\n";
    cout << "结点总数: \t" << bt->get_nodes() << "\n";
    cout << "叶子总数: \t" << bt->get_leaves() << "\n";
    cout << "计数大于'h'的结点总数: \t";
    cout << bt->preorder_GTcount('h') << "\n";
    cout << "输出根结点到每个叶子结点的路径: \n";
    bt->preorder_leafpath();
    cout << "输出路径和为__的路径: \n";

    cout << "创建整型二叉树\n";
    BT *bt2 = new BT("a( b( c, d ), e( f, g( h, i ) ) )");
    bt2->create<int>();
    cout << "输出二叉树: \t";
    bt2->show<int>();
    cout << "\n";
    bt2->path_with_sum();
    return 0;
}
