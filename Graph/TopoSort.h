//
// Created by 舒意恒 on 2018/5/15.
// 用于对一个有向无环图拓扑排序。
//
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#ifndef ACM_CPP_TEMPLATE_TOPOSORT_H
#define ACM_CPP_TEMPLATE_TOPOSORT_H

const int maxn = 100000 + 5;
vector<int> g[maxn]; // g[i]表示从点i连出去的边
int du[maxn]; // du[i]表示点i的入度
int n; // 顶点数量
int L[maxn]; // 拓扑排序的结果

bool toposort() { // 能拓扑排序返回true，否则返回false
    memset(du, 0, sizeof(du));
    for (int i = 0; i < n; i++) { // 计算入度
        for (int j = 0; j < g[i].size(); j++)
            du[g[i][j]]++;
    }
    int tot = 0; // 当前已排序的顶点数
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (!du[i]) Q.push(i); // 入度为0，入队列
    }
    while (!Q.empty()) {
        int cur = Q.front(); // 当前顶点
        Q.pop();
        L[tot++] = cur;
        for (int j = 0; j < g[cur].size(); j++) {
            int t = g[cur][j];
            du[t]--; // 当前顶点连接的所有顶点的入度减1
            if (!du[t]) // 如果入度减为0，入队列
                Q.push(t);
        }
    }
    return tot == n;
}

#endif //ACM_CPP_TEMPLATE_TOPOSORT_H
