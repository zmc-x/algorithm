/*
    很常规的一个bfs求取权重为1的一个最短路问题，同样采取队列来实现，
    首先将起点入queue，然后遍历其点的周围的所有的点，然后将符合要求
    的点存入到queue中，当queue为null时，那么此时的d[n]就是所要求的
    值
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化
int h[N], val[N], ne[N], idx, q[N], d[N], n, m;
void add(int a, int b)
{
    val[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    int low{0}, top{0};
    q[top++] = 1;
    d[1] = 0;
    while(low != top){
        int mid = q[low++];
        for(int i = h[mid]; i != -1; i = ne[i]){
            if(d[val[i]] == -1){
                d[val[i]] = d[mid] + 1;
                q[top++] = val[i];
            }
        }
    }
    return d[n];
}
int main()
{
    int a{0}, b{0};
    memset(h, -1, sizeof(h));
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}