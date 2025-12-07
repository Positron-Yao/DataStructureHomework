#include <iostream>
#include "BTNode.h"
using namespace std;

int main(int argc, char **argv) {
    cout << "创建二叉树\n";
    BTNode::BTNode<char> *bt = new BTNode::BTNode<char>("a( b( c, d ), e( f, g( h, i ) ) )");
    cout << "输出二叉树: \t";
    bt->show();
    cout << "\n";
    cout << "树的高度: \t" << bt->get_height() << "\n";
    cout << "结点总数: \t" << bt->get_nodes() << "\n";
    cout << "叶子总数: \t" << bt->get_leaves() << "\n";
    cout << "计数大于'f'的结点总数: \t";
    cout << bt->preorder_GTcount('f') << "\n";
    cout << "输出根结点到每个叶子结点的路径: \n";
    bt->preorder_leafpath();

    cout << "\n";
    cout << "创建整型二叉树\n";
    BTNode::BTNode<int> *bt2 = new BTNode::BTNode<int>("a( b( d( b, c ), e), c(b, c( b, c ) ) )");
    cout << "输出二叉树: \t";
    bt2->show();
    cout << "\n";
    cout << "输出路径和为5的路径: \n";
    bt2->path_with_sum(5);
    return 0;
}
