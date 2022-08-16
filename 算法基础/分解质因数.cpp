/*
首先这一题就是求质数分解；
过程：
1.首先枚举所有的数（>= 2）；然后再判断是否可以整除；若整除那么此时i就必然是一个质数
    证明如下：
    首先当为i时被整除，此时的n中不含有2 ~ i - 1的质因数 => n mod 其中的数 != 0；
    若n % i = 0；=> p * i mod 其中的数 != 0；=> i mod 其中的数 != 0；所以此时的
    i必然就是一个素数
2. 求次数 整除n即可；

优化：存在定理：n中最多存在一个大于n ^ 1 / 2 的质因子；所有就可以枚举小于sqrt(n)的因子
将 i <= n 改为 i < n / i即可；
最后若n无变化即为存在大于sqrt(n)的数；手动判断即可 => if(n > 1) xxxxx
*/
#include<iostream>

using namespace std;

void find(int m)
{
    for(int i = 2; i <= m / i; i++){
        if(m % i == 0){
            int s = 0;
            while(m % i == 0){
                m /= i;
                s++;
            }
            cout << i << ' ' << s << endl;
        }
    }
    if(m > 1) cout << m << ' ' << 1 << endl;
}
int main()
{
    int n{0}, m{0};
    cin >> n;
    while(n--){
        cin >> m;
        find(m);
        cout << endl;
    }
    return 0;
}