//
// Created by 舒意恒 on 2018/5/15.
// 实现矩阵的基本变换。
//

#ifndef ACM_CPP_TEMPLATE_MATRIX_H
#define ACM_CPP_TEMPLATE_MATRIX_H

#include <cstring>

const int MAXN = 1010;
const int MAXM = 1010;

template<class T>
struct Matrix {
    int n, m; // 矩阵大小
    T a[MAXN][MAXM]; // 矩阵内容
    void clear();

    Matrix operator+(const Matrix &b) const;

    Matrix operator-(const Matrix &b) const;

    Matrix operator*(const Matrix &b) const;

    Matrix pow(long long n) const;
};

template<class T>
void Matrix<T>::clear() {
    n = m = 0;
    memset(a, 0, sizeof(a));
}

template<class T>
Matrix Matrix<T>::operator+(const Matrix &b) const {
    Matrix res;
    res.n = n;
    res.m = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.a[i][j] = this->a[i][j] + b.a[i][j];
        }
    }
    return res;
}

template<class T>
Matrix Matrix<T>::operator-(const Matrix &b) const {
    Matrix res;
    res.n = n;
    res.m = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.a[i][j] = this->a[i][j] - b.a[i][j];
        }
    }
    return res;
}

template<class T>
Matrix Matrix<T>::operator*(const Matrix &b) const {
    Matrix res;
    res.clear();
    res.n = this->n;
    res.m = b.m;
    res.n = n;
    res.m = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b.m; j++)
            for (int k = 0; k < this->m; k++)
                res.a[i][j] += this->a[i][k] * b.a[k][j];
    return res;
}

template<class T>
Matrix Matrix<T>::pow(long long n) const {
    // TODO 矩阵快速幂
    return Matrix();
}

#endif //ACM_CPP_TEMPLATE_MATRIX_H
