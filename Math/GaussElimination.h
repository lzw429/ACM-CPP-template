
//
// Created by 舒意恒 on 2018/5/15.
// 给一个n元一次方程组，求它们的解集。
//

#ifndef ACM_CPP_TEMPLATE_GAUSSELIMINATION_H
#define ACM_CPP_TEMPLATE_GAUSSELIMINATION_H

#include <cmath>
#include <utility>
#include "Matrix.h"

using namespace std;

inline int solve(double a[][MAXN], bool l[], double ans[], const int &n, double EPS) {
    // 输入：
    // a        方程组对应的矩阵
    // n        未知数个数
    // l, ans   存储解，l[]表示是否为自由元
    // 输出：解空间的维数
    int res = 0, r = 0;
    for (int i = 0; i < n; i++)
        l[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = r; j < n; j++) {
            if (fabs(a[j][i]) > EPS) {
                for (int k = i; k <= n; k++) {
                    double t = a[j][k];
                    a[j][k] = a[r][k];
                    a[r][k] = t;
                }
                break;
            }
        }
        if (fabs(a[r][i]) < EPS) {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j != r && fabs(a[j][i]) > EPS) {
                double t = a[j][i] / a[r][i];
                for (int k = i; k <= n; k++)
                    a[j][k] -= t * a[r][k];
            }
        }
        l[i] = true, r++;
    }
    for (int i = 0; i < n; i++) {
        if (l[i]) {
            for (int j = 0; j < n; j++) {
                if (fabs(a[j][i]) > 0)
                    ans[i] = a[j][n] / a[j][i];
            }
        }
    }
    return res;
}

#endif //ACM_CPP_TEMPLATE_GAUSSELIMINATION_H
