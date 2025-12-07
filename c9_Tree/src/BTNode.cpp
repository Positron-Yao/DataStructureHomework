#include "BTNode.h"

namespace BTNode {

template<>
void BTNode::create<char>() {
    while (str[pos] != '\0') {
        switch (str[pos]) {
            case ' ':
                pos++;
                break;
            case '(':
                pos++;
                left = new BTNode(str + pos);
                left->create<char>();
                pos += left->pos + 1;
                right = new BTNode(str + pos);
                right->create<char>();
                pos += right->pos + 1;
                break;
            case ')':
            case ',':
                return;
            default:
                data = str[pos];
                pos++;
                break;
        }
    }
}

template<>
void BTNode::create<int>() {
    while (str[pos] != '\0') {
        switch (str[pos]) {
            case ' ':
                pos++;
                break;
            case '(':
                pos++;
                left = new BTNode(str + pos);
                left->create<int>();
                pos += left->pos + 1;
                right = new BTNode(str + pos);
                right->create<int>();
                pos += right->pos + 1;
                break;
            case ')':
            case ',':
                return;
            default:
                data = str[pos] - 'a';
                pos++;
                break;
        }
    }
}


} // BTNode
