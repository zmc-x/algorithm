/*
和dijkstra算法很想，但是在这里dist不是指的到1号点的距离，而是指的是到集合的距离，
1. 将dist全部初始化为+∞
2. 迭代n次，寻找最小的到集合的距离，将其加入到集合中，
   然后update其他点到集合的距离。
ps：当图不连通时，也就是在 >= 第2次迭代的时候dist若还是等于0x3f3f3f3f，那么表示不
连通
对于堆优化版的，其实同dijkstra算法优化类似，就是将寻找min、更新点使用heap来优化，将时间
复杂度优化为O(m * logn)
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 1000, MaxVal = 0x3f3f3f3f;
int n, m, dist[N], g[N][N];
bool sta[N];

int prime()
{
    int res{0};
    // 初始化所有
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < n; i++){
        // 寻找最小值
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!sta[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        // 判断不连通
        if(i && dist[t] == MaxVal) return MaxVal;
        sta[t] = true;
        // 对于第一个数据不能够加
        if(i) res += dist[t];
        // 更新dist
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
int main()
{
    int u{0}, v{0}, w{0};
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m--){
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = g[u][v];
    }
    int res = prime();
    if(res == MaxVal) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}