/**
 * @file 筛选法求欧拉函数.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * 思路：本题采用筛选法的方法来实现相关的欧拉函数的计算，首先判断其师质数的基础上
 * 在计算到其的Euler function's value = primes - 1;
 * 而在常规的二重循环中再计算的合数的欧拉函数的值：首先需要计算的是primes[j] 是 i的
 * 最小质因数，那么Euler[primes[j] * i] = primes[j] * euler[i]；
 * 反之则为(primes[j] - 1) * euler[i]
 * 先计算是其是质因子，是为了防止计算多次欧拉函数的值，保证值的正确性
 */
#include<iostream>

using namespace std;
using ll = long long;
extern const int N = 1e6 + 10;
int n;
int primes[N], euler[N], cnt;
bool sta[N];

ll GetCnt(int n)
{
    // 1的欧拉函数为1
    euler[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!sta[i]){
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for(int j = 0; primes[j] * i <= n; j++){
            sta[primes[j] * i] = true;
            if(i % primes[j] == 0){
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            euler[primes[j] * i] = (primes[j] - 1) * euler[i];
        }
    }
    ll res{0};
    for(int i = 1; i <= n; i++) res += euler[i];
    return res;
}
int main()
{
    cin >> n;
    cout << GetCnt(n) << endl;
    return 0;
}