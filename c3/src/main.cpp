#include <iostream>
#include "SLinkNode.h"

int main(int argc, char** argv) {
    int const size = 5;
    ElemType data[size] = {1, 2, 3, 4, 5};
    SLinkNode *head;
    CreateNodeList(head, size, data);
    DestroyNodeList(head);
    std::cout << "hello world!" << std::endl;
    return 0;
}
