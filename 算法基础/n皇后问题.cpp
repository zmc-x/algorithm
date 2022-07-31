/*
    首先可以抽象为一行只有一个皇后，那么就可以抽象为一个全排列的问题；
所以只需要判断求行，diagonal，反diagonal是否存在皇后即可。
    当其中没有皇后时，就可以向下一层递归，同时回溯时也需要恢复原样。
    其实在这里涉及到剪枝的操作，也就是一些contradict的方法可以直接pass掉
*/
#include<iostream>

using namespace std;
extern const int N = 19;
// 初始化
char g[N][N];
bool col[N], dg[N], udg[N];
int n{0};

// dfs
void dfs(int u)
{
    // 皇后的数目为n
    if(u == n){
        for(int i = 0; i < n; i++){
            cout << g[i] << endl;
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && !dg[u - i + n] && !udg[u + i]){
            g[u][i] = 'Q';
            col[i] = dg[u - i + n] = udg[u + i] = true;
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u - i + n] = udg[u + i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) g[i][j] = '.';
    }
    dfs(0);
    return 0;
}