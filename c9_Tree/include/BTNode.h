#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace BTNode {

typedef int Elemtype;

template<typename T>
class BaseBTNode {
    public:
        Elemtype data;
        BaseBTNode *left, *right;
        int pos;

        BaseBTNode() = default;

        void show() {
            std::cout << static_cast<T>(data);
            if (left || right) {
                std::cout << "(";
                if (left)
                    left->show();
                else
                    std::cout << "#";
                std::cout << ",";
                if (right)
                    right->show();
                else
                    std::cout << "#";
                std::cout << ")";
            }
        }

        size_t get_height() {
            if (left && right) {
                return 1 + std::max(left->get_height(), right->get_height());
            } else if (left) {
                return 1 + left->get_height();
            } else if (right) {
                return 1 + right->get_height();
            }
            return 1;
        }

        size_t get_nodes() {
            if (left && right) {
                return 1 + left->get_nodes() + right->get_nodes();
            } else if (left) {
                return 1 + left->get_nodes();
            } else if (right) {
                return 1 + right->get_nodes();
            }
            return 1;
        }

        size_t get_leaves() {
            if (left && right) {
                return left->get_leaves() + right->get_leaves();
            } else if (left) {
                return left->get_leaves();
            } else if (right) {
                return right->get_leaves();
            }
            return 1;
        }

        // 使用先序遍历统计大于ref的结点数
        size_t preorder_GTcount(int ref) {
            int count = data > ref ? 1 : 0;
            if (left) count += left->preorder_GTcount(ref);
            if (right) count += right->preorder_GTcount(ref);
            return count;
        }

        // 使用先序遍历输出根节点到每个叶子结点的路径
        int preorder_leafpath() {
            std::vector<T> path;
            preorder_leafpath_helper(path);
            return 0;
        }

        void preorder_leafpath_helper(std::vector<T>& path) {
            path.push_back(data);
            if (left == nullptr && right == nullptr) {
                // 输出路径
                for (T node : path) {
                    std::cout << node << " -> ";
                }
                std::cout << "#\n";
            }
            if (left) left->preorder_leafpath_helper(path);
            if (right) right->preorder_leafpath_helper(path);
            path.pop_back();
        }

        int path_with_sum(T target) {
            std::vector<T> path;
            path_with_sum_helper(path, target);
            return 0;
        }

        void path_with_sum_helper(std::vector<T>& path, T target) {
            path.push_back(data);
            if (left == nullptr && right == nullptr) {
                // 输出路径
                int sum = 0;
                for (auto a : path) {
                    sum += a;
                }
                if (sum == target) {
                    for (T node : path) {
                        std::cout << node << " -> ";
                    }
                    std::cout << "#\n";
                }
            }
            if (left) left->path_with_sum_helper(path, target);
            if (right) right->path_with_sum_helper(path, target);
            path.pop_back();
        }

};

template<typename T>
class BTNode;

template<>
class BTNode<char>: public BaseBTNode<char> {
    public:
        char const *str;

        BTNode(char const *str): str(str) {
            while (str[pos] != '\0') {
                switch (str[pos]) {
                    case ' ':
                        pos++;
                        break;
                    case '(':
                        pos++;
                        left = new BTNode<char>(str + pos);
                        pos += left->pos + 1;
                        right = new BTNode<char>(str + pos);
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
};

template<>
class BTNode<int>: public BaseBTNode<int> {
    public:
        char const *str;

        BTNode(char const *str): str(str) {
            while (str[pos] != '\0') {
                switch (str[pos]) {
                    case ' ':
                        pos++;
                        break;
                    case '(':
                        pos++;
                        left = new BTNode<int>(str + pos);
                        pos += left->pos + 1;
                        right = new BTNode<int>(str + pos);
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
};

} // BTNode
