/*
    本题同样还是spfa算法，但是在其基础上存在一定的改动，加上了一个存边数的数组。
    这样就可以来通过鸽巢原理来判断是否存在负环。
    条件：当cnt[x] + 1 > n；那么就可知存在重复点，也就是存在环
    错误的写法：cnt[x] + 1 >  x；这个当x足够小，n足够大时是有可能出现的，并不一定是存在环
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
extern const int N = 1e5 + 10;
int n, m, dist[N], val[N], ne[N], w[N], idx, h[N], cnt[N];
bool sta[N];

void add(int a, int b, int c)
{
    val[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool spfa()
{
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    // 将所有点存入
    for(int i = 1; i <= n; i++){
        q.push(i);
        sta[i] = true;
    }
    while(q.size()){
        int mid = q.front();
        q.pop();
        sta[mid] = false;
        for(int i = h[mid]; i != -1; i = ne[i]){
            if(dist[val[i]] > dist[mid] + w[i]){
                dist[val[i]] = dist[mid]+ w[i];
                // 边数 + 1
                cnt[val[i]] = cnt[mid] + 1;
                // 存在环
                if(cnt[val[i]] + 1 > n) return false;
                if(!sta[val[i]]){
                    q.push(val[i]);
                    sta[val[i]] = true;
                }
            }
        }
    }
    return true;
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
    if(spfa()) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
