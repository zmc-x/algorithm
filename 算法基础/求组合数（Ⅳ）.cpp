/**
 * @file 求组合数（Ⅳ）.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 思路：
 * 本题的思路就是将使用高精度的运算来实现，将c(a, b) = a! / b! * (a - b)!
 * 然后将上述式子转化为相关的质数的幂指运算，之后再求出相关的p的幂指数即可。
 * 对于a! 中的p的个数= a / p + a / p ^ 2 + a / p ^ 3 + .....
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
extern const int N = 5e3 + 10;

int primes[N], cnt, sum[N];
bool sta[N];

// 求出质数因子
void GetPrimes(int n)
{
    for(int i = 2; i <= n; i++){
        if(!sta[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            sta[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

// 求质因子的个数
int get(int n, int p)
{
    int res{0};
    while(n){
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mult(vector<int>& a, int p)
{
    vector<int> res;
    int t{0}, len = a.size();
    for(int i = 0; i < len || t != 0; i++){
        if(i < len) t = a[i] * p + t;
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}
int main()
{
    int a{0}, b{0};
    cin >> a >> b;
    GetPrimes(a);
    for(int i = 0; i < cnt; i++){
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }
    vector<int> res;
    // 用1来简化后续的计算
    res.push_back(1);
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < sum[i]; j++){
            res = mult(res, primes[i]);
        }
    }
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
    cout << endl;
    return 0;
}