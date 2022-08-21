/**
 * @file 快速幂.cpp
 * @author hellozmc (310693528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 这个思路很常规，就是先将k分解为二进制，然后用二进制的幂指数来拆分k
 * 从而使得时间复杂度由O(k) -> O(log k)
 * 其实算法的本质就是不断的平方，来实现相关的二进制的幂指运算
 * 即2 ^ 0, 2 ^ 1, 2 ^ 2 ......... 2 ^ logk
 */
#include<iostream>

using namespace std;
using ll = long long;

ll Result(int a, int k, int p)
{
    ll res = 1;
    while(k){
        if(k & 1) res = res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}
int main()
{
    int n{0};
    cin >> n;
    while(n--){
        int a{0}, k{0}, p{0};
        cin >> a >> k >> p;
        cout << Result(a, k, p) << endl;
    }
}