//
// Created by 舒意恒 on 2018/5/16.
// 格雷码
//

#ifndef ACM_CPP_TEMPLATE_GRAY_H
#define ACM_CPP_TEMPLATE_GRAY_H

#include <vector>

using namespace std;

vector<int> Gray_Create(int n) { // 输出n位格雷码
    vector<int> res;
    res.clear();
    for (int i = 0; i < (1 << n); i++)
        res.push_back(i ^ (i >> 1));
    return res;
}

#endif //ACM_CPP_TEMPLATE_GRAY_H
