/**
 * @file 欧拉函数.cpp
 * @author hellozmc(306943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * 先大数分解，然后套用公式 euler function' value = n * (1 - 1 / p1) .... (1 - 1 / pn) 
 */
#include<iostream>

using namespace std;
using ll = long long;

ll GetCnt(int m)
{
    ll res{m};
    for(int i = 2; i <= m / i; i++){
        if(m % i == 0){
            res = res * (i - 1) / i;
            while(m % i == 0) m /= i;
        }
    }
    if(m > 1) res = res * (m - 1) / m;
    return res;
}
int main()
{
    int n{0}, m{0};
    cin >> n;
    while(n--){
        cin >> m;
        cout << GetCnt(m) << endl;
    }
    return 0;
}