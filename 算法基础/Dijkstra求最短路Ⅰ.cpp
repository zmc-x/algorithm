/*
首先说一下大致的思路，这个就是采用贪心的策略来实现的；
就是每次找出最小的值，然后更新之前的数据即可。
1. 先循环迭代n个点，然后找出最小的dist（之前不存在最小值）
2. 看是否满足更新的条件，如若满足则将其更新为最短的值。反之不用更新
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 1000;

int n, m, g[N][N], dist[N];
bool sta[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    // 循环遍历n个节点
    for(int i = 1; i <= n; i++){
        // 寻找最小的不存在min的dist
        int pos{-1};
        for(int j = 1; j <= n; j++){
            if(!sta[j] && (pos == -1 || dist[pos] > dist[j])) pos = j;
        }
        sta[pos] = true;
        // update the data
        for(int j = 1; j <= n; j++){
            if(dist[j] > dist[pos] + g[pos][j]) dist[j] = dist[pos] + g[pos][j];
        }
    }
    if(dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << dist[n] << endl;
}
int main()
{
    int x{0}, y{0}, z{0};
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    dijkstra();
    return 0;
}