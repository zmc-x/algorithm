/*
本题的思路和上一题类似，这不过这里采用的是用heap来直接获取到最min's value
从而使时间复杂度降低到O(m * logn)；适合稀疏图；
这里需要注意的是：当sta[MinPos] == true时，那么就已经重复了，将其continue掉即可。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;
// first express dot and second express the distance
using pii = pair<int , int>;
extern const int N = 2e5;
int h[N], val[N], ne[N], idx, w[N], dist[N], n, m, cnt{1};
bool sta[N];
pii heap[N];
// heap up
void up(int x)
{
    while(x / 2 && heap[x].second < heap[x / 2].second){
        swap(heap[x], heap[x / 2]);
        x /= 2;
    }
}
// heap down
void down(int x)
{
    int MinPos = x;
    if(2 * x <= cnt && heap[MinPos].second > heap[2 * x].second) MinPos = 2 * x;
    if(2 * x + 1 <= cnt && heap[MinPos].second > heap[2 * x + 1].second) MinPos = 2 * x + 1;
    // 判断是否需要交换
    if(MinPos != x){
        swap(heap[x], heap[MinPos]);
        down(MinPos);
    }
}
// 构建邻接表
void add(int x, int y, int z)
{
    val[idx] = y;
    ne[idx] = h[x];
    w[idx] = z;
    h[x] = idx++;
}
// dijkstra
int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    heap[1].first = 1, heap[1].second = dist[1];
    // 遍历n个点
    while(cnt){
        int MinPos = heap[1].first, MinVal = heap[1].second;
        swap(heap[1], heap[cnt]);
        cnt--;
        down(1);
        // cout << MinPos << endl;
        if(sta[MinPos]) continue;
        // 将值加入到sta
        sta[MinPos] = true;
        for(int j = h[MinPos]; j != -1; j = ne[j]){
            // 判断是否满足更新的条件
            if(dist[val[j]] > MinVal + w[j]){
                dist[val[j]] = MinVal + w[j];
                heap[++cnt] = {val[j], dist[val[j]]};
                up(cnt);
            }
        }
    }
    if(dist[n] != 0x3f3f3f3f) return dist[n];
    else return -1;
}
int main()
{
    memset(h, -1, sizeof(h));
    int x{0}, y{0}, z{0};
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra() << endl;
    return 0;
}