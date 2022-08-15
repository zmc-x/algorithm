/*
首先对于这种二分图的最大匹配的问题所采用的方式是：匈牙利算法
假定有两个集合A，B；
对于a中的元素，选边的其另一个点；若该点存在匹配的，可以尝试将与之匹配的点更新为
b中的另一个与之前的匹配的元素边的另一个顶点，如若没有则放弃即可。
那么这种情况下的匹配的数目就是Max
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 1e3, M = 1e5 + 10;
int h[N], val[M], ne[M], idx;
int n1, n2, m;
// 表示配对的点
int match[N];
bool sta[N];

void add(int a, int b)
{
    val[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = val[i];
        if(!sta[j]){
            sta[j] = true;
            if((!match[j]) || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    memset(h, -1, sizeof(h));
    int a{0}, b{0};
    cin >> n1 >> n2 >> m;
    while(m--){
        cin >> a >> b;
        add(a, b);
    }
    int res{0};
    for(int i = 1; i <= n1; i++){
        memset(sta, false, sizeof(sta));
        if(find(i)) res++;
    }
    cout << res << endl;
    return 0;
}