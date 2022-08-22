/**
 * @file 线性同余方程.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 首先对于这一题而言，a * x = b (mod m)；有解就是(a, b) | b；
 * 上述式子可以化为a * x + p * m = b；那么只需要求解a，m的最大公约数，
 * 若有解的话，x扩大b / gcd倍然后 mod m即可。
 */
#include<iostream>
#include<cstdio>

using namespace std;
using ll = long long;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return gcd;
}

int main()
{
    int n{0};
    scanf("%d", &n);
    while(n--){
        int a{0}, b{0}, m{0}, x{0}, y{0};
        scanf("%d %d %d", &a, &b, &m);
        int mid = exgcd(a, m, x, y);
        if(b % mid) printf("impossible\n");
        else printf("%d\n", (ll)b / mid * x % m);
    }
    return 0;
}