/**
 * @file 求组合数（Ⅰ）.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 思路：因为这里询问次数过多，所以直接采用预处理的方法来算
 * c(b, a) = c(b, a - 1) + c(b - 1, a - 1)
 * 那么直接采用双重循环来实现即可，对于j = 0的情况直接特判一些c(0, i) = 1
 * 
 */
#include<iostream>

using namespace std;

extern const int N = 2e3 + 10, mod = 1e9 + 7;

int c[N][N], n;

void init()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(!j) c[j][i] = 1;
            else c[j][i] = (c[j][i - 1] + c[j - 1][i - 1]) % mod;
        }
    }
}
int main()
{
    int n{0}, a{0}, b{0};
    cin >> n;
    init();
    while(n--){
        cin >> a >> b;
        cout << c[b][a] << endl;
    }
    return 0;
}