/*
    有关有向图的拓扑排序，首先有环的有向图是一定没有拓扑排序的，
    那么具体的实现方式是采用和bfs相同的方式来实现的，首先先将
    入度是0的点入queue，那么就满足的出queue的条件；同时在将
    其与之相连的点的入度--，当其入度为0时即可入队，循环往复即可
    最后判断是否存在环的条件：
    队中的元素是否存在n个，若有则不是拓扑排序，反之则存在环
*/
#include<iostream>
#include<cstring>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化
int h[N], val[N], ne[N], idx, n, m, d[N], q[N];
void add(int a, int b)
{
    val[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool topsort()
{
    int low{0}, top{0};
    for(int i = 1; i <= n; i++){
        if(!d[i]) q[top++] = i;
    }
    while(low != top){
        int mid = q[low++];
        for(int i = h[mid]; i != -1; i = ne[i]){
            d[val[i]]--;
            if(!d[val[i]]) q[top++] = val[i];
        }
    }
    // 判断
    return top == n;
}
int main()
{
    int a{0}, b{0};
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if(topsort()){
        for(int i = 0; i < n; i++) cout << q[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}