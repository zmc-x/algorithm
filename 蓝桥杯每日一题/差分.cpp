#include<iostream>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int s[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        s[i] += x, s[i + 1] -= x;
    }
    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        s[l] += c, s[r + 1] -= c;
    }
    for(int i = 1; i <= n; i++) s[i] += s[i - 1], cout << s[i] << ' ';
    cout << endl;
    return 0;
}