/*
首先就是二分图，二分图就是边的两个端点是不同的，也就是可以分为两个不一样的集合；
在图论中存在：“当图中存在奇数环的时候那么就必然不会存在二分图”

对于这一题，让我对dfs有了更深的理解，虽然本质上就是一个一直向前走，再回溯的过程；
但是再图论中必然是会先穷举ta的所有的邻接点，之后再向下走。

那么，对于这一题而言，染色：当邻接点未染色，那么就染上与之相对的颜色，再做相应的判断即可；
当邻接点的color与此时的颜色相同时，那么return false；
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
extern const int N = 1e5 + 10;
int h[N], val[2 * N], ne[2 * N], idx, n, m, color[N];

void add(int a, int b)
{
    val[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int x, int c)
{
    color[x] = c;
    for(int i = h[x]; i != -1; i = ne[i]){
        if(!color[val[i]]){
            if(!dfs(val[i], 3 - c)) return false;
        }
        else{
            // 相邻的两个端点颜色不能相同
            if(color[val[i]] == c) return false;
        }
    }
    return true;
}
int main()
{
    int a{0}, b{0};
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    // 染色法
    // 通过一个flag来判断是否出现了冲突
    bool flag{true};
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}