//
// Created by 舒意恒 on 2018/5/16.
// 完成高精度整数的加减乘除以及取模运算。
//

#ifndef ACM_CPP_TEMPLATE_BIGNUMBER_H
#define ACM_CPP_TEMPLATE_BIGNUMBER_H

#include <cstring>
#include <iostream>

#define MAX_L 2005
using namespace std;

class BigInteger {
private:
    int len; // 大数长度
    int num[MAX_L]; // 记录数组；索引越大，位越高
    bool sign; // 正数true，负数false
public:
    // 构造函数
    BigInteger();

    BigInteger(const char *);

    BigInteger(int);

    string to_string() const; // 转化为字符串，用于输出

    // 输入输出流
    friend istream &operator>>(istream &, BigInteger &);

    friend ostream &operator<<(ostream &, BigInteger &);

    // 赋值运算
    BigInteger operator=(const char *);

    BigInteger operator=(const int);

    BigInteger operator=(const string);

    // 比较运算
    bool operator>(const BigInteger &) const;

    bool operator>=(const BigInteger &) const;

    bool operator<(const BigInteger &) const;

    bool operator<=(const BigInteger &) const;

    bool operator==(const BigInteger &) const;

    bool operator!=(const BigInteger &) const;

    // 四则运算
    BigInteger operator+(const BigInteger &) const;

    BigInteger operator++(); // 前缀自增

    BigInteger operator++(int); // 后缀自增

    BigInteger operator+=(const BigInteger &);

    BigInteger operator-(const BigInteger &) const;

    BigInteger operator--();

    BigInteger operator--(int);

    BigInteger operator-=(const BigInteger &);

    BigInteger operator*(const BigInteger &) const;

    BigInteger operator*(const int) const;

    BigInteger operator*=(const BigInteger &);

    BigInteger operator/(const BigInteger &) const;

    BigInteger operator/=(const BigInteger &);

    // 其他运算
    BigInteger operator%(const BigInteger &) const; // 取模

    BigInteger factorial() const; // 阶乘

    BigInteger sqrt() const; // 整数开方，向下取整

    BigInteger pow(const BigInteger &) const; // 乘方

    // 其他函数
    void calc_len();

    ~BigInteger();
};

BigInteger::BigInteger() {
    memset(num, 0, sizeof(num));
    len = 1;
    sign = true; // 默认为+1
}

BigInteger::BigInteger(const char *ch) {
    *this = ch;
}

BigInteger::BigInteger(int num) {
    *this = num;
}

string BigInteger::to_string() const {
    string res = "";
    for (int i = 0; i < len; i++)
        res = (char) (num[i] + '0') + res;
    if (res == "")
        res = "0";
    if (!sign && res != "0")
        res = "-" + res; // 添加负号
    return res;
}

friend istream &operator>>(istream &is, BigInteger &b) {
    string str;
    is >> str; // 将输入内容存储到str
    b = str; // 赋值给b
    return is;
}

friend ostream &operator<<(ostream &os, BigInteger &b) {
    os << b.to_string();
    return os;
}

BigInteger BigInteger::operator=(const char *ch) {
    // TODO 前导0和负0
    memset(num, 0, sizeof(num));
    if (ch[0] != '-') { // 正数
        this->sign = true;
        this->len = strlen(ch);
    } else { // 负数
        this->sign = false;
        this->len = strlen(ch) - 1;
    }
    for (int i = 0; i < len; i++)
        num[i] = ch[len - i - 1] - 48;
    return *this;
}

BigInteger BigInteger::operator=(int num) {
    char tmp[MAX_L];
    sprintf(tmp, "%d", num);
    return *this = tmp;
}

BigInteger BigInteger::operator=(const string str) {
    const char *tmp;
    tmp = str.c_str();
    return *this = tmp;
}

bool BigInteger::operator<(const BigInteger &b) const {
    if (this->sign ^ b.sign) // 异或
        return b.sign;
    if (this->len != b.len)
        return this->len < b.len;

    for (int i = len - 1; i >= 0; i--) { // 从高位开始比较
        if (this->num[i] != b.num[i])
            return sign & (this->num[i] < b.num[i]);
    }
    return !sign;
}

bool BigInteger::operator>(const BigInteger &b) const {
    return b < *this;
}

bool BigInteger::operator<=(const BigInteger &b) const {
    return !(*this > b);
}

bool BigInteger::operator>=(const BigInteger &b) const {
    return !(*this < b);
}

bool BigInteger::operator!=(const BigInteger &b) const {
    return (*this > b) || (*this < b);
}

bool BigInteger::operator==(const BigInteger &b) const {
    return !(b != *this);
}

BigInteger BigInteger::operator+(const BigInteger &b) const {
    if (this->sign ^ b.sign) { // 符号相异 TODO
        BigInteger res = (this->sign) ? (*this - b) : (b - *this);
        res.sign = true;
        return res;
    }
    BigInteger res;
    res.len = 0;
    res.sign = this->sign;
    int carry = 0; // 进位
    for (int i = 0; carry || i < max(this->len, b.len); i++) {
        int add = num[i] + b.num[i] + carry;
        res.num[res.len++] = add % 10;
        carry = add / 10;
    }
    return res;
}

BigInteger BigInteger::operator++() { // 前缀自增，先加后返回
    return *this = *this + 1;
}

BigInteger BigInteger::operator++(int) { // 后缀自增，先返回后加
    BigInteger old = *this;
    ++(*this);
    return old;
}

BigInteger BigInteger::operator+=(const BigInteger &b) {
    return *this = *this + b;
}

BigInteger BigInteger::operator-(const BigInteger &b) const {
    BigInteger x = *this, y = b; // 该函数是const类型
    // 计算 x-y
    if (!x.sign && !y.sign) { // 两负数相减
        x.sign = true;
        y.sign = true;
        return y - x; // 等同于两正数相减
    }
    if (!y.sign) { // 减数为负数
        y.sign = true;
        return x + y; // 等同于加上正数
    }
    if (!x.sign) { // 被减数为负数
        x.sign = true;
        return BigInteger(0) - (x + y);
    }
    // 两正数相减
    if (x < y) { // 小数减大数
        BigInteger z = (y - x);
        z.sign = false;
        return z;
    }
    // 大数减小数
    BigInteger res;
    res.len = 0;
    int borrow = 0; // 借位
    for (int i = 0; i < x.len; i++) {
        int sub = x.num[i] - borrow;
        if (i < y.len)
            sub -= y.num[i];
        if (sub >= 0)
            borrow = 0;
        else {
            borrow = 1;
            sub += 10; // 借高位的1作该位的10
        }
        res.num[res.len++] = sub;
    }
    res.calc_len();
    return res;
}

BigInteger BigInteger::operator--() { // 前缀自减
    return *this = *this - 1;
}

BigInteger BigInteger::operator--(int) { // 后缀自减
    BigInteger old = *this;
    --(*this);
    return old;
}

BigInteger BigInteger::operator-=(const BigInteger &b) {
    return *this = *this - b;
}

BigInteger BigInteger::operator*(const BigInteger &b) const {
    BigInteger res;
    res.len = this->len + b.len; // 乘积位数不会超过二者位数和
    for (int i = 0; i < this->len; i++) {
        for (int j = 0; j < b.len; j++) {
            res.num[i + j] += this->num[i] * b.num[j];
        }
    }
    for (int i = 0; i < res.len; i++) { // 进位
        res.num[i + 1] += res.num[i] / 10;
        res.num[i] %= 10;
    }
    res.calc_len();
    res.sign = !(this->sign ^ b.sign); // 同或
    return res;
}

BigInteger BigInteger::operator*(const int num) const {
    BigInteger x = num;
    return *this * x;
}

BigInteger BigInteger::operator*=(const BigInteger &b) {
    return *this = *this * b;
}

BigInteger BigInteger::operator/(const BigInteger &) const {
    return BigInteger();
}

BigInteger BigInteger::operator/=(const BigInteger &) {
    return BigInteger();
}

void BigInteger::calc_len() {
    if (this->len == 0) // 如果数是0，长度为1
        len++;
    while (len > 1 && num[len - 1] == '\0')
        len--;
}

BigInteger::~BigInteger() {

}

#endif //ACM_CPP_TEMPLATE_BIGNUMBER_H
