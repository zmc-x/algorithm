/*
    本题采用spfa来对最短路来进行求解，这个优化的方法就是利用一个
    queue来将更新了的dist存入，以便于来更新满足条件的点。
    其实有点类似于dijkstra算法的思路
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
extern const int N = 1e5 + 10;
int n, m, dist[N], val[N], ne[N], w[N], idx, h[N];
bool sta[N];

void add(int a, int b, int c)
{
    val[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int spfa()
{
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    q.push(1);
    sta[1] = true;
    while(q.size()){
        int mid = q.front();
        q.pop();
        sta[mid] = false;
        for(int i = h[mid]; i != -1; i = ne[i]){
            if(dist[val[i]] > dist[mid] + w[i]){
                dist[val[i]] = dist[mid]+ w[i];
                if(!sta[val[i]]){
                    q.push(val[i]);
                    sta[val[i]] = true;
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return 0x3f3f3f3f;
    else return dist[n];
}
int main()
{
    memset(h, -1, sizeof(h));
    int a{0}, b{0}, c{0};
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int res = spfa();
    if(res == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}