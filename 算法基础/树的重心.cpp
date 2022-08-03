/*
    这题本质上是一个dfs的过程，因为在寻找子树个数其实本质上就是一个深搜的过程，
    那么这一题的主要的解法就是先return子树的个数和总的连通块进行比较然后取max；
    然后再回溯的时候遍历另外的一个子树即可；然后通过总的节点数目来求最后的连通块的
    数目，然后不断的取min，最后所得的就是answer
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化
int h[N], val[2 * N], ne[2 * N], idx, ans{N}, n;
bool sta[N];
// 构建邻接表
void add(int a, int b)
{
    val[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++; 
}
// dfs
int dfs(int u)
{
    sta[u] = true;
    int sum = 1, res{0};
    for(int i = h[u]; i != -1; i = ne[i]){
        if(!sta[val[i]]){
            int mid = dfs(val[i]);
            res = max(mid, res);
            sum += mid;
        }
    }
    
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main()
{
    int a{0}, b{0};
    memset(h, -1, sizeof(h));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}