/*
    本题思考相对比较巧妙，操作到第i个数的时候；需要使得i - a[i] + 1 -> i中的数据全部变为1
    那么我们可以通过维护一个数组来记录区间中的操作次数，由此转变为差分的模块，直接套用即可
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e5 + 10;

int main() {
    int t;
    cin >> t;
    while(t--) {
        // v[N]来维护添加的次数
        int n, v[N], s[N];
        cin >> n;
        memset(v, 0, (n + 1) * 4);
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
            int l = i - s[i] + 1;
            if(l < 1) l = 1;
            // 差分
            v[l]++, v[i + 1]--;
        }
        for(int i = 1; i <= n; i++) {
            v[i] += v[i - 1];
            if(v[i]) cout << '1' << ' ';
            else cout << '0' << ' ';
        }
        cout << endl;
    }
    return 0;
}