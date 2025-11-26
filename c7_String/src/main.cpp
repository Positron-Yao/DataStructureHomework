#include <iostream>
#include "SqString.h"
#include "LinkString.h"
using namespace std;

void test_sqstring() {
    using String = SqString::SqString;
    using namespace SqString;

    String s;
    Assign(s, "Hello SqString");
    cout << "创建字符串: \t";
    DispStr(s);
    cout << "长度: \t\t" << StrLength(s) << "\n";
    String sub;
    Assign(sub, "Str");
    cout << "'Str' 出现在: \t" << Index(s, sub) << "\n";
}

void test_linkstring() {
    using String = LinkString::LinkString;
    using namespace LinkString;

    String s;
    Assign(s, "Hello LinkString");
    cout << "创建字符串: \t";
    DispStr(s);
    cout << "长度: \t\t" << StrLength(s) << "\n";
    String sub;
    Assign(sub, "Str");
    cout << "'Str' 出现在: \t" << Index(s, sub) << "\n";
}


int main(int argc, char** argv) {
    cout << "顺序串测试:\n";
    test_sqstring();
    cout << "\n";
    cout << "链串测试:\n";
    test_linkstring();
    return 0;
}
