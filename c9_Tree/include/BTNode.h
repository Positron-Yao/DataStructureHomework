#pragma once
#include <cstdlib>

namespace BTNode {

size_t const MaxSize = 256;
typedef char Elemtype;

class BTNode {
    public:
        Elemtype data;
        BTNode *left, *right;
};

BTNode *create(BTNode *& bt, char const *str);

} // BTNode
