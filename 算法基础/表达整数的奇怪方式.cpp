/**
 * @file 表达整数的奇怪方式.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 首先这一题本身就是中国剩余定理，但是受限于不能保证mod的数是互素的，所以这里采用一种新的方式
 * 将两个等式两两合并，然后最后就可以得到一个新的等式，若满足相关的条件话，那么最后的x直接mod a1即可
 * 合并：
 * x = m1(mod a1)
 * x = m2(mod a2)
 * k1 * a1 + m1 = k2 * a2 + m2 -> k1 * a1 - k2 * a2 = m2 - m1
 * 然后通过扩展欧几里得算法来实现k1 & k2的解
 * 最后在保证k1的最小值 k1 = k1 + a2 / d * k;
 * 最后将其带入到一式中即可。
 * 其中有解的条件就是 m2 - m2 | (a1, a2)
 */
#include<iostream>

using namespace std;
using ll = long long;

// 扩展欧几里得算法
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b){
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}
int main()
{
    int n{0};
    cin >> n;
    ll a1{0}, m1{0};
    cin >> a1 >> m1;
    bool flag = true;
    for(int i = 1; i < n; i++){
        ll a2{0}, m2{0}, k1{0}, k2{0};
        cin >> a2 >> m2;
        ll d = exgcd(a1, a2, k1, k2);
        if((m2 - m1) % d){
            flag = false;
            break;
        }
        k1 = (m2 - m1) / d * k1;
        ll mid = a2 / d;
        k1 = (k1 % mid + mid) % mid;
        m1 = a1 * k1 + m1;
        a1 = a2 / d * a1;
    }
    if(flag) cout << (ll)(m1 % a1 + a1) % a1 << endl;
    else cout << -1 << endl;
    return 0;
}

