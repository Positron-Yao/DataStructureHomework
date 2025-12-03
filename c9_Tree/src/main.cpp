#include <iostream>
#include "BTNode.h"
using namespace std;

int main(int argc, char **argv) {
    cout << "BTNode\n";
    BTNode::BTNode *bt;
    BTNode::create(bt, "5(1,2)");
    return 0;
}
