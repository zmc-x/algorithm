/*
首先对于这一题也是采用差分的方法来实现。
向定义两个数组a[][], b[][];
a是前缀和数组，b是差分数组；同样是先将其初始化为0；
然后构造差分即可；
那么在(x1, y1)和(x2, y2)的区间中都加c；
=> 只需要b[x1][y1] + c; b[x2 + 1][y1] - c; 
   b[x1][y2 + c] - c; b[x2 + 1][y2 + 1] + c;
   然后在计算一下前缀和即可
同样差分数组的初始化也是通过上述公式实现的；因为可以看成一个很小的区间的数加上一个数（前提是初始化为0）
*/
#include<iostream>

using namespace std;
extern const int N = 1e3 + 10;
// 初始化前缀和数组和差分数组
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    int n{0},m{0},q{0},x1{0},y1{0},x2{0},y2{0},c{0};
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            // 构造差分数组
            insert(i, j, i, j, a[i][j]);
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    // 算前缀和
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j]);
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}