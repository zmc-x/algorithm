/*
floyd算法具体就是三重循环，ta本质上其实是一个动态规划的问题，
for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}
对于这题同样也是需要处理重边和自环的问题，重边取最小值即可，自环可以直接删掉
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 300, MaxVal = 0x3f3f3f3f;

int n, m, q, dist[N][N];

void floyd()
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main()
{
    int a{0}, b{0}, c{0}, x{0}, y{0};
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = MaxVal;
        }
    }
    while(m--){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    floyd();
    while(q--){
        cin >> x >> y;
        if(dist[x][y] > MaxVal / 2) cout << "impossible" << endl;
        else cout << dist[x][y] << endl;
    }
    return 0;
}