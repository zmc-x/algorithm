/**
 * @file 扩展欧几里得算法.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 很简单的一个算法：同样也是分两种情况，1. b == 0，那么x = 1, y = 0;
 * 2. b != 0, exgcd(b, a % b, y, x)
 * gcd(b, a % b) = a * x + b * (y - a / b * b) = gcd(a, b);
 * 所以y = y - a / b * b;
 * ps：记得return value
 */
#include<iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0){
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
    cin >> n;
    while(n--){
        int a{0}, b{0}, x{0}, y{0};
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}