#include<iostream>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int s[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}