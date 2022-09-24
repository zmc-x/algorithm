#include<iostream>
#include<algorithm>

using namespace std;

extern const int N = 110;

int a[N][N], n;

int gauss()
{
    int r{0}, c{0};
    for(c = 0; c < n; c++){
        int t = -1;
        for(int i = r; i < n; i++){
            if(a[i][c]){
                t = i;
                break;
            }
        }
        if(t == -1) continue;
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        for(int i = r + 1; i < n; i++){
            if(a[i][c]){
                for(int j = c; j <= n; j++){
                    a[i][j] ^= a[r][j];
                }
            }
        }
        r++;
    }
    if(r < n){
        for(int i = r; i < n; i++){
            if(a[i][n]) return 1;
        }
        return 2;
    }
    
    // 倒着求解
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            a[i][n] ^= a[i][j] & a[j][n];
        }
    }
    
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++) cin >> a[i][j];
    }
    int res = gauss();
    if(res == 0){
        for(int i = 0; i < n; i++) cout << a[i][n] << endl;
    }
    else if(res == 1) cout << "No solution"  << endl;
    else cout << "Multiple sets of solutions" << endl;
    return 0;
}