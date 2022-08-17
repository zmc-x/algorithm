/*
首先说一下约数个数如何求；对于N可以质数分解
而其约数的个数就等于(a1 + 1) * ... * (an + 1);
所以采用hash来存储

还有就是result mod Mod = ((a1 + 1) % Mod) * ... * ((an + 1) % Mod) % Mod;
所以需要先将值赋给res再mod才行 
不能使用 res *= (i.second + 1) % Mod
*/
#include<iostream>
#include<unordered_map>

using namespace std;
using ll = long long;
extern const int Mod = 1e9 + 7;

unordered_map<int , int> dict;
int main()
{
    int n{0}, m{0};
    cin >> n;
    while(n --){
        cin >> m;
        for(int i = 2; i <= m / i; i++){
            if(m % i == 0){
                while(m % i == 0){
                    m /= i;
                    dict[i]++;
                }
            }
        }
        if(m > 1) dict[m]++;
    }
    ll res{1};
    for(auto i : dict) res = res * (i.second + 1) % Mod;
    res = res % Mod;
    cout << res << endl;
    return 0;
}