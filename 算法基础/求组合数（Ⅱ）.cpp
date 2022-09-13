/**
 * @file 求组合数（Ⅱ）.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 思路：
 * 本题a和b的范围比较大，所以不能够采用递归枚举的方法来实现
 * 这里采用的就是通过预处理阶乘的方式来实现相关的组合数的计算
 * 当然这里需要采用逆元来计算相关的1 / b! 这里通过快速幂的方式来进行相关的计算
 * qmi(i, mod - 2, mod)
 */
#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;
extern const int N = 1e5 + 10, mod = 1e9 + 7;
// infact表示带逆元的
int fact[N], infact[N];

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
void init()
{
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}
int main()
{
    init();
    int n{0};
    cin >> n;
    while(n--){
        int a{0}, b{0};
        cin >> a >> b;
        cout << (ll)fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
    }
    return 0;
}