#include <iostream>
#include "timer.h"
using namespace std;

long Sum1(long n) {
    long s = 0;
    for (long i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

long Sum2(long n) {
    long s = n * (n + 1) / 2;
    return s;
}

int main(int argc, char** argv) {
    long n = 1000000;
    cout << "求和函数测试: n = " << n << endl;
    timeit<long(long)>("Sum1", Sum1, 1000000);
    timeit<long(long)>("Sum2", Sum2, 1000000);
    return 0;
}
