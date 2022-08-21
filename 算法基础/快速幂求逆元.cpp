/**
 * @file 快速幂求逆元.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 逆元就是满足a * x = 1 (mod p) 
 * 这里保证p为质数，那么就很简单了，直接调用费马小定理来计算即可，a ^ p = a (mod p) p为质数
 * 那么计算a ^ p - 2即可，但是当a mod p = 0那么就是不会存在逆元
 */
#include<iostream>
#include<algorithm>

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
        int a{0}, p{0};
        cin >> a >> p;
        ll res = Result(a, p - 2, p);
        // 当p | a 那么就不存在逆元
        if(a % p) cout << res << endl;
        else cout << "impossible" << endl;
        
    }
    return 0;
}