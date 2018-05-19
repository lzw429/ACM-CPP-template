//
// Created by 舒意恒 on 2018/5/16.
// 欧几里得算法：求两个数a,b的最大公约数
//

#ifndef ACM_CPP_TEMPLATE_GCD_H
#define ACM_CPP_TEMPLATE_GCD_H

#include <algorithm>

using namespace std;

template<class T>
T gcd(T a, T b) { // 非递归实现
    if (!a || !b)
        return 0;
    T t;
    while (t) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

template<class T>
T lcm(T a, T b) { // 最小公倍数
    return a * b / gcd(a, b);
}

template<class T>
T gcd_(T a, T b) { // 递归实现
    return (!b) ? a : gcd(b, a % b);
}

#endif //ACM_CPP_TEMPLATE_GCD_H
