#include<iostream>

using namespace std;
const int N = 1010;

int s[N][N];
int n, m, q;

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            s[i][j] += x, s[i][j + 1] -= x, s[i + 1][j] -= x, s[i + 1][j + 1] += x;
        }
    }
    while(q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        s[x1][y1] += c, s[x1][y2 + 1] -= c, s[x2 + 1][y1] -= c, s[x2 + 1][y2 + 1] += c;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}