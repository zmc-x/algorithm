/**
 * @file 组合数（Ⅲ）.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 思路：
 * 这里采用的是通过lucass来计算组合数 lucass(a, b) = C(a % p, b % p) * lucass(a / p, b / p) % p
 * 而对于Cfunction而言这里采用(a * a - 1 * a - 2 * ... * a - b + 1) / b!
 * 这里的实现方式为：
 * for(int i = 1, j = a; i <= b; i++, j--){
 *      res = res * j % p
 *      res = res * qmi(i, p - 2) % p
 * }
 * 
 */
#include<iostream>

using namespace std;
using ll = long long;
int p;


int pmi(int a, int k)
{
    int res{1};
    while(k){
        if(k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
int C(int a, int b)
{
    if(a < b) return 0;
    
    int res{1};
    for(int i = 1, j = a; i <= b; i++, j--){
        res = (ll)res * j % p;
        res = (ll)res * pmi(i, p - 2) % p;
    }
    return res;
}
int lucas(ll a, ll b)
{
    // 当a，b < p时直接正常运算
    if(a < p && b < p) return C(a, b);
    return (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main()
{
    int n{0};
    cin >> n;
    while(n--){
        ll a{0}, b{0};
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
    return 0;
}