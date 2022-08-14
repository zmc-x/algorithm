/*
首先这题的思路比较简单，就是先将所有的边sort，然后通过并查集的方式来
将集合来合并，同时通过cnt变量来判断集合的数目；每一次合并那么集合数必然
- 1；所以当最后cnt != 1，那么就不存在最小生成树；
ps：这里这么写是对于c++中运算符重载有点不是很清楚
*/
#include<iostream>
#include<algorithm>

using namespace std;
extern const int N = 2e5 + 10;
struct{
    int a, b, c;
}edge[N], tem[N];
int n, m, p[N];

void merge_sort(int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    // 将两个有序的数组合并
    int i = l, j = mid + 1, cnt{0};
    while(i <= mid && j <= r){
        if(edge[i].c < edge[j].c) tem[cnt++] = edge[i++];
        else tem[cnt++] = edge[j++];
    }
    // 处理未完结的data
    while(i <= mid) tem[cnt++] = edge[i++];
    while(j <= r) tem[cnt++] = edge[j++];
    // 将tem中的数组存入到edge中
    for(int i = 0, j = l; i < cnt, j <= r; i++, j++) edge[j] = tem[i];
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    else return p[x];
}
int main()
{
    int res{0};
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> edge[i].a >> edge[i].b >> edge[i].c;
    merge_sort(0, m - 1);
    // kruskal
    for(int i = 1; i <= n; i++) p[i] = i;
    int cnt{n};
    for(int i = 0; i < m; i++){
        int pa = find(edge[i].a), pb = find(edge[i].b);
        if(pa != pb) {
            p[pa] = pb;
            res += edge[i].c;
            cnt--;
        }
    }
    if(cnt == 1) cout << res << endl;
    else cout << "impossible" << endl;
    return 0;
}