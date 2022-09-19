/**
 * @file 能被整除的数.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 思路：首先这题是一个典型的容斥原理的题目，ta其实也就是能被所用p[i]整除数的一个并集
 * 这个其实也就是s1 + s2 + .. + sn - s1 ^ s2 ..... + (-1 ^ m - 1) * s1 ^ s2 ^ s3 ^ ... ^ sn
 * 这个求的是一个个数，而p是质数，那么其数的个数就是n / pi；而对于多个其实也可以表示成为
 * n / p1 * p2 * ... * pn；
 * 而对于这里所有的组合其实等于2 ^ m - 1；这种虽然可以通过爆搜来实现，但是这里采用二进制来表示
 * 通过m位二进制来表示选择的p1~pn中的一个数
 * 然后通过cnt来实现res的相关的计算
 */
#include<iostream>

using namespace std;
using ll = long long;

extern const int M = 20;
int p[M], n, m;
int res;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> p[i];
    // 通过位运算来实现相关的运算
    for(int i = 1; i < 1 << m; i++){
        int t{1}, cnt{0};
        for(int j = 0; j < m; j++){
            // 来判断存在1
            if(i >> j & 1){
                cnt++;
                if((ll)t * p[j] > n){
                    t = -1;
                    break;
                }
                t = (ll)t * p[j];
            }
        }
        if(t != -1){
            if(cnt % 2) res += n / t;
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}