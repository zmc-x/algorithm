/*
    字符串hash，首先先将一个数转化为P进制的数（P取131 or 13331）然后进行取mod 2 ^ 64运算;
但是在这里这个mod运算可以不用去做，直接定义unsigned long long即可。
    其次就是给定范围内的hash，这个有点类似于前缀和，推断出来：hash = h[r] - h[l - 1] * P ^ (r - l + 1)
    如此给定范围内的判断其hash值是否相等即可知道字符串是否匹配
*/
#include<iostream>
#include<string>
using namespace std;
using ull = unsigned long long;
extern const int N = 1e5 + 10, P = 131;
// 初始化 p数组中存的是P的次方
ull h[N], p[N];
// find
ull find(int l, int r)
{
    ull res = h[r] - h[l - 1] * p[r - l + 1];
    return res;
}
int main()
{
    string str;
    int n{0}, m{0}, l1{0}, r1{0}, l2{0}, r2{0};
    // 因为p中存的P的幂指数，需要将其置为1
    p[0] = 1;
    cin >> n >> m;
    cin >> str;
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i - 1];
    }
    while(m--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(find(l1, r1) == find(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}