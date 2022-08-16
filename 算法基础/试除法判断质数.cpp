/*
简单的判断质数的问题，当然也可以直接暴力
这里使用的是O(log n)的算法；
首先对于n来说，若d | n；那么就有n / d | n:
从而存在所要枚举的因子的个数就是 <= n / d；
*/

#include<iostream>

using namespace std;

bool check(int x)
{
    if(x == 1) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main()
{
    int n{0}, a{0};
    cin >> n;
    while(n--){
        cin >> a;
        if(check(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}