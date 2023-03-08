#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

int s[N];
int main() {
    int n, a[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, res = 0; 
    for(int r = 0; r < n; r++) {
        while(s[a[r]]) {
            s[a[l++]] --;
        }
        s[a[r]]++;
        res = max(res, r - l + 1);
    }
    cout << res << endl;
    return 0;
}