//
// Created by 舒意恒 on 2018/5/15.
// 以前向星方式存储一个有向图的基本信息。
//
#include <vector>

using namespace std;
#ifndef ACM_CPP_TEMPLATE_FORWARDSTAR_H
#define ACM_CPP_TEMPLATE_FORWARDSTAR_H

struct Graph {
    vector<int> info; // 由该点出发的所有边构成的链表的表
    vector<int> next; // 链表中下一条边在to数组中的位置
    vector<int> to; // to[i]表示编号为i的边指向的节点

    Graph(int n = 0, int m = 0) : to(0), next(0) {
        // 初始化图为n个点，m条边
        info.resize(n);
        next.reserve(m); // 使向量容量至少为m
        to.reserve(m);
    }

    int edge_size() { // 返回边的数量
        return to.size();
    }

    int vertex_size() { // 返回值为最大点的编号+1
        return info.size();
    }

    void expand(int i) {
        if (info.size() < i + 1)
            info.resize(i + 1);
    }

    void add(int i, int j) { // 添加一条i到j的边
        expand(i), expand(j);
        to.push_back(j);
        next.push_back(info[i]);
        info[i] = to.size() - 1;
    }

    void del_back() { // 删除最后一次添加的边
        for (int i = 0; i < info.size(); i++) {
            if (info[i] == to.size() - 1) {
                info[i] = next.back();
                break;
            }
        }
        to.pop_back();
        next.pop_back();
    }

    void clear() { // 清空图类
        info.clear();
        next.resize(0);
        to.resize(0);
    }
};

#endif //ACM_CPP_TEMPLATE_FORWARDSTAR_H
