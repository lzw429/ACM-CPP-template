//
// Created by 舒意恒 on 2018/5/21.
//

#include<iostream>
#include "../Math/Matrix.h"

using namespace std;

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        Matrix<int> A(3, 3);
        A.mod = 10007;
        A.mat[0][0] = 2;
        A.mat[0][1] = 1;
        A.mat[0][2] = 0;
        A.mat[1][0] = 2;
        A.mat[1][1] = 2;
        A.mat[1][2] = 2;
        A.mat[2][0] = 0;
        A.mat[2][1] = 1;
        A.mat[2][2] = 2;
        cin >> N;
        A = A.pow(N);
        cout << A.mat[0][0] << endl;
    }
    return 0;
}