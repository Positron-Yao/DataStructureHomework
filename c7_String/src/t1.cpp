#include <iostream>
#include "SqString.h"
using String = SqString::SqString;
using namespace SqString;
using namespace std;

int Reverse(String &s) {
    String t;
    t.length = s.length;
    for (int i = s.length - 1; i >= 0; i--) {
        t.data[s.length - i - 1] = s.data[i];
    }
    s = t;
    return 0;
}

int main() {
    String s;
    Assign(s, "abcdefg");
    cout << "初始字符串: \t";
    DispStr(s);
    Reverse(s);
    cout << "反转后: \t";
    DispStr(s);
}
