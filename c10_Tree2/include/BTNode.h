#pragma once
#include <queue>

typedef char ElemType;

class BTNode {
    public:
        ElemType data;
        BTNode *l, *r;
        int w;

        BTNode() {}

        static void init(BTNode *&bt, char const *str) {
            BTNode *St[100], *p = nullptr;
            int top = -1, k, j = 0;
            char ch;
            bt = nullptr;
            ch = str[j];
            while (ch != '\0') {
                switch (ch) {
                    case '(':
                        top++;
                        St[top] = p;
                        k = 1;
                        break;
                    case ')':
                        top--;
                        break;
                    case ',':
                        k = 2;
                        break;
                    default:
                        p = new BTNode;
                        p->data = '-';
                        p->w = 0;
                        p->l = p->r = nullptr;
                        if (bt == nullptr) {
                            bt = p;
                        } else {
                            switch (k) {
                                case 1:
                                    St[top]->l = p;
                                    break;
                                case 2:
                                    St[top]->r = p;
                                    break;
                            }
                        }
                }
                j++;
                ch = str[j];
            }
        }
};

class BTree {
    public:
        BTNode *root;

        int getMaxWidth() {
            if (root == nullptr) {
                return 0;
            }
            
            int maxWidth = 0;
            std::queue<BTNode*> q;
            q.push(root);
            
            while (!q.empty()) {
                int levelSize = q.size();  // 当前层的节点数
                maxWidth = std::max(maxWidth, levelSize);  // 更新最大宽度
                
                // 遍历当前层的所有节点
                for (int i = 0; i < levelSize; i++) {
                    BTNode* current = q.front();
                    q.pop();
                    
                    // 将子节点加入队列
                    if (current->l != nullptr) {
                        q.push(current->l);
                    }
                    if (current->r != nullptr) {
                        q.push(current->r);
                    }
                }
            }
            
            return maxWidth;
        }
};

void Destroy(BTNode *&bt);
void Display(BTNode *bt);
void SetLeaf(BTNode *&bt, char v[], int w[]);
int Sum(BTNode *bt);
void HuffmanCode(BTNode *bt);

