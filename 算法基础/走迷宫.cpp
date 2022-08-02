/*
    bfs，这个使用queue来实现，将需要点存入queue中，然后当queue为
空的时候那么就实现了题目的要求，
    首先针对于这一题而言，采用pair来实现对坐标的存储，然后遍历四个方向，
然后将满足要求（在数组范围内，且不是墙，没有走过）的点存入queue中，然后
将其点到第一个点的距离存入到d二维数组中。那么就可以得到题目的解
*/
#include<iostream>
#include<utility>
#include<cstring>

using namespace std;
using pii = pair<int, int>;
extern const int N = 110;
int g[N][N], d[N][N], n, m;
// 定义队列
pii q[N * N];

int bfs()
{
    int low{0}, top{1};
    memset(d, -1, sizeof(d));
    q[0] = {0, 0};
    d[0][0] = 0;
    // 定义四个方向的向量
    int ax[4] = {-1, 1, 0, 0};
    int ay[4] = {0, 0, -1, 1};
    int x{0}, y{0};
    while(low != top){
        auto mid = q[low++];
        for(int i = 0; i < 4; i++){
            x = mid.first + ax[i];
            y = mid.second + ay[i];
            // cout << x << ' ' << y << endl;
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 1 && d[x][y] == -1){
                d[x][y] = d[mid.first][mid.second] + 1;
                // cout << d[x][y] << endl;
                q[top ++] = {x, y};
            }
        }
    }
    return d[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> g[i][j];
    }
    cout << bfs() << endl;
    return 0;
}