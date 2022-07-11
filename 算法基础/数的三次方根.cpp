/*
这一题就是一个浮点数的二分，首先对于浮点数的二分，这个就是一个取精度的问题，
因为对于浮点数而言，不可能存在相等的问题，
故边界也就不可能存在+1和-1的问题了
当然这里还需要考虑<1的情况
*/
#include<iostream>
using namespace std;

int main()
{
    double n{0.00};
    int flag{0};
    cin >> n;
    if(n < 0){
        n = -n;
        flag = 1;
    }
    double l{0},r{n},mid{0};
    if(n < 1) r = 1;
    while(r - l > 1e-8){
        mid = (l + r) / 2;
        if((mid * mid * mid) <= n) l = mid;
        else r  = mid;
    }
    if(flag) l = -l;
    printf("%.6lf\n",l);
    return 0;
}