#include <iostream>
#include "SLinkNode.h"
using LinkString = SLinkNode::SLinkNode;
using namespace SLinkNode;
using namespace std;

void Create(LinkString *&s, char const *str, size_t n) {
    for (int i = 0; i < n; i++) {
        Append(s, str[i]);
    }
}

int CountSubs(LinkString *s, LinkString *sub) {
    // 设计一个计数子串出现次数的函数，要求子串不重叠
    int count = 0;
    LinkString *p = s->next, *q = sub->next;
    while (p != nullptr) {
        if (p->data == q->data) {
            // 第一个字符匹配成功，开始匹配后续字符
            p = p->next;
            q = q->next;
            bool match = true;
            while (p != nullptr && q != nullptr) {
                if (p->data != q->data) {
                    // 提前返回
                    match = false;
                    break;
                } else {
                    p = p->next;
                    q = q->next;
                }
            }
            if (match) {
                count++;
                // 恢复q
                q = sub->next;
            }
        }
        if (p != nullptr) {
            p = p->next;
        }
    }
    return count;
}

int main() {
    LinkString *s, *t;
    InitList(s);
    InitList(t);
    Create(s, "abcababc", 8);
    Create(t, "abc", 3);
    cout << "创建字符串: \tabcababc\n";
    cout << "子字符串: \tabc\n";
    cout << "出现次数: \t" << CountSubs(s, t) << "\n";
}
