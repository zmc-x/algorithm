/*
这里约数之和其实就是等于(p1 ^ 0 + ... +  p1 ^ n) * .... * (pn ^ 0 + pn ^ 1 + ..... + pn ^ n)
ps：这里需要注意的是在计算每一项的时候数可能会超过相应的范围所以在计算的过程中需要将其mod Mod
已到达相应的不会爆范围的错误
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
    while(n--){
        cin >> m;
        for(int i = 2; i <= m / i; i++){
            while(m % i == 0){
                m /= i;
                dict[i]++;
            }
        }
        if(m > 1) dict[m]++;
    }
    ll res{1};
    for(auto p : dict){
        ll mid{1};
        int t = p.first, k = p.second;
        for(int i = 1; i <= k; i++) mid = (mid * t + 1) % Mod;
        res = res * mid % Mod;
    }
    cout << res % Mod << endl;
    return 0;
}