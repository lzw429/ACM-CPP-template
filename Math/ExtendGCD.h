//
// Created by 舒意恒 on 2018/5/16.
// 扩展欧几里得算法：求出A,B的最大公约数，且求出X,Y满足AX + BY = GCD(A,B)
//

#ifndef ACM_CPP_TEMPLATE_EXTENDGCD_H
#define ACM_CPP_TEMPLATE_EXTENDGCD_H

template<class T>
T extend_gcd(T a, T b, T &x, T &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        T r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

#endif //ACM_CPP_TEMPLATE_EXTENDGCD_H
