/*
    首先这一其实是用dfs来做的一个比较典型的题目，首先用一个数组来存储一个
结果集，然后不断的递归调用然后回溯，就可以得到一个正确数据；
    本题比较重要就是需要使用一个bool数组来存储对应的数据是否使用过，当使用过
那么就跳过，然后使用value为true的值，就将这个值赋给path；并且向下一层递归，当
回溯是在恢复原样即可
    当path的长度到达n时，即可输出答案
*/
#include<iostream>

using namespace std;
extern const int N = 10;

// 初始化
int path[N], n{0};
bool flag[N];
// dfs
void dfs(int x)
{
    if(x == n){
        for(int i = 0; i < n; i++) cout << path[i] << ' ';
        cout << endl;
        return;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(!flag[i]){
                path[x] = i;
                flag[i] = true;
                dfs(x + 1);
                // restore the place
                path[x] = 0;
                flag[i] = false;
            }
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}