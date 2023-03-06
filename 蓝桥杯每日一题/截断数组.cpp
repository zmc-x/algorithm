/*
本题思路即为三个相同的子数组，故均为s[n] / 3；
只需要枚举最后一个分段（第二个的最后一个元素），当s[j] = 2 * s[n] / 3；则开始枚举i；
当s[i] = s[n] / 3时，则cnt++；
最后累加即可
*/
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

typedef long long ll;
int s[N];
int n;

int main() {
    ll res = 0, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    // 不能被3整除
    if(s[n] % 3) cout << 0 << endl;
    else {
        int j = 1;
        for(int i = 2; i <= n - 1; i++) {
            if(s[i] == s[n] * 2 / 3) {
                while(j < i) {
                    if(s[j++] == s[n] / 3) cnt++;
                }
                res += cnt;
            }
        }
        cout << res << endl;
    }
    return 0;
}