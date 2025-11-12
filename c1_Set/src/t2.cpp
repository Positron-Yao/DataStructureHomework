#include <iostream>
#include "timer.h"
using namespace std;

long FactAcc1(long n) {
    long acc = 0, fact;
    for (long i = 1; i <= n; i++) {
        fact = 1;
        for (long j = 1; j <= i; j++) {
            fact *= j;
        }
        acc += fact;
    }
    // std::cout << acc << std::endl;
    return acc;
}

long FactAcc2(long n) {
    long acc = 1, fact = 1;
    for (long i = 2; i <= n; i++) {
        fact *= i;
        acc += fact;
    }
    // std::cout << acc << std::endl;
    return acc;
}

int main() {
    long n = 10000;
    cout << "阶乘累加函数测试: n = " << n << endl;
    timeit<long(long)>("FactAcc1", FactAcc1, n);
    timeit<long(long)>("FactAcc2", FactAcc2, n);
    return 0;
}
