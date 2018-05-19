//
// Created by 舒意恒 on 2018/5/18.
//

#ifndef ACM_CPP_TEMPLATE_FRACTION_H
#define ACM_CPP_TEMPLATE_FRACTION_H


#include <cassert>
#include "GCD.h"

class Fraction {
    long long num; // 分子
    long long den; // 分母
    Fraction(long long num = 0, long long den = 1) {
        if (den < 0) { // 把负号转移到分子
            num = -num;
            den = -den;
        }
        assert(den != 0); // 确保分母不为0
        // 分数化简
        long long g = gcd(abs(num), den);
        this->num = num / g;
        this->den = den / g;
    }

    Fraction operator+(const Fraction &f) const { // 通分相加
        return Fraction(num * f.den + den * f.num, den * f.den);
    }

    Fraction operator-(const Fraction &f) const { // 通分相减
        return Fraction(num * f.den - den * f.num, den * f.den);
    }

    Fraction operator*(const Fraction &f) const {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(const Fraction &f) const {
        return Fraction(num * f.den, den * f.num);
    }

    bool operator<(const Fraction &f) const {
        return num * f.den < den * f.num;
    }

    bool operator==(const Fraction &f) const {
        return num * f.den == den * f.num;
    }
};


#endif //ACM_CPP_TEMPLATE_FRACTION_H
