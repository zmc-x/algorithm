/**
 * @file 高斯消元解线性方程组.cpp
 * @author hellozmc (3106943528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 思路：
 * 首先针对于每一个列进行迭代操作
 * 1. 求出绝对值最大的行的行号
 * 2. 然后在将其放到最上面
 * 3. 将该行的数第一个数置为1
 * 4. 再将c列的数字置为0
 * 再不断的迭代求即可
 * 
 * 对于无解＆多组解的问题：
 * 首先r < n；那么之后的应该就是倍数，那么左边应该为0；
 * 若右边不是0；则是无解；反之多组解
 * 
 * 存解的过程 就是从最后倒着来算；需要注意的就是要记住其是个n * n的系数，可以直接调已知的解的
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

extern const int N = 110;
extern const double cp = 1e-6;
int n;
double a[N][N];

int gauss()
{
    int r{0}, c{0};
    for(c = 0; c < n; c++){
        int t = r;
        for(int i = r; i < n; i++){
            if(fabs(a[i][c]) > fabs(a[t][c])) t = i;
        }
        if(fabs(a[t][c]) < cp) continue;
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c];
        // 把第c列的其他的数置为0
        for(int i = r + 1; i < n; i++){
            if(fabs(a[i][c]) > cp){
                for(int j = n; j >= c; j--){
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    
    if(r < n){
        for(int i = r; i < n; i++){
            if(fabs(a[i][c]) > cp) return 1;// 无解
        }
        return 2;//无解
    }
    // 将数据存入
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++) a[i][n] -= a[i][j] * a[j][n];
    }
    return 0;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++) cin >> a[i][j];
    }
    int t = gauss();
    if(t == 0){
        for(int i = 0; i < n; i++){
            if(fabs(a[i][n]) < cp) cout << "0.00" << endl;
            else printf("%.2lf\n", a[i][n]);
        } 
    }
    else if(t == 1) cout << "No solution" << endl;
    else cout << "Infinite group solutions" << endl;
    return 0;
}