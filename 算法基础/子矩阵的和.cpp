/*
本题同样也是前缀的思想，但是对于二维来说应该是相对来书是比较麻烦的。
1. s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j] (i,j >= 1);
2. 给定某一区间：x1, y1, x2, y2;
   那么x1 -> x2, y1 -> y2的范围中的数据和为：
   s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] (i,j >= 1)
*/
#include<iostream>
using namespace std;
extern const int N = 1e3 + 10;
// 初始化前缀和数组
int s[N][N];

int main()
{
    int n{0}, m{0}, q{0}, a[N][N],x1{0}, y1{0}, x2{0}, y2{0};
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    // 求前缀和
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}