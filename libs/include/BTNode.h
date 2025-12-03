#pragma once
#include <iostream>

namespace BTNode {

template <typename T>
class BTNode {
    public:
        T data;
        BTNode *left, *right;

        BTNode() {}
        BTNode(T data): data(data) {}
        BTNode(T data, BTNode *left, BTNode *right): data(data), left(left), right(right) {}

        void insert(T data) {
            if (data < this->data) {
                if (this->left == nullptr) {
                    this->left = new BTNode(data);
                } else {
                    this->left->insert(data);
                }
            } else {
                if (this->right == nullptr) {
                    this->right = new BTNode(data);
                } else {
                    this->right->insert(data);
                }
            }
        }

        void show() {
            std::cout << "Call BTNode::show()\n";
        }
};

} // BTNode
