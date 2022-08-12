/*
首先讲一下bellmanford算法，这个算法主要就是适用于存在边数限制、存在负权边的状况；
算法细节就是首先循环迭代n条边（这个表示的其实也就是存在多少条边数的限制），之后再
将对每一个边进行相关的判断，看其是否满足需要替换的情况。
但是在这里需要注意的情况就是需要对这个dist数组进行相关的拷贝，否则可能会出现答案不符合的
情况，也就是所谓的串联的情况；所以更新的结果只能是受限于之前的dist
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 10010;
int n, m, k, dist[N], CopyDist[N];
struct{
    int a, b, c;
}edge[N];

int BellmanFord()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    // 至少经过多少条边
    for(int i = 0; i < k; i++){
        memcpy(CopyDist, dist, sizeof(dist));
        // 遍历所有的edge
        for(int j = 0; j < m; j++){
            dist[edge[j].b] = min(dist[edge[j].b], CopyDist[edge[j].a] + edge[j].c);
        }
    }
    // 判断
    if(dist[n] > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
    else return dist[n];
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }
    int res = BellmanFord();
    if(res == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}