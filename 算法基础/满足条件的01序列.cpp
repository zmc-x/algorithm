/**
 * @file 满足条件的01序列.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 思路：本题可以抽象为卡特兰数来计算
 * 那么直接套用公式计算即可
 * C(n, 2* n) - C(n - 1, 2 * n) = 1 / (n + 1) * C(n, n * 2)
 */
#include<iostream>
#include<algorithm>

using namespace std;

extern const int Mod = 1e9 + 7;
using ll = long long;

int qmi(int a, int b, int p)
{
    int res{1};
    while(b){
        if(b & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n{0};
    cin >> n;
    int a = 2 * n;
    int res{1};
    // 套公式
    // for(int i = 1, j = a; i <= n; i++, j--){
    //     res = (ll)res * j % Mod;
    //     res = (ll)res * qmi(i, Mod - 2, Mod) % Mod;
    // }
    for(int i = a; i >= a - n + 1; i--) res = (ll)res * i % Mod;
    for(int i = 1; i <= n; i++) res = (ll)res * qmi(i, Mod - 2, Mod) % Mod;
    // 乘以n + 1 ^ -1
    res = (ll)res * qmi(n + 1, Mod - 2, Mod) % Mod;
    cout << res << endl;
    return 0;
}