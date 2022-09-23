#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;
extern const int N = 110, M = 10010;

int k, n;
int s[N], f[M];

// 记忆化搜索
int sg(int x)
{
    // 如果已经计算过
    if(f[x] != -1) return f[x];
    
    unordered_set<int> S;
    for(int i = 0; i < k; i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum));
    }
    
    // 计算此时的sg，通过定义来计算
    for(int i = 0; ; i++){
        if(!S.count(i)){
            f[x] = i;
            return f[x];
        }
    }
}

int main()
{
    cin >> k;
    for(int i = 0; i < k; i++) cin >> s[i];
    cin >> n;
    int res{0};
    // 初始化
    memset(f, -1, sizeof(f));
    for(int i = 0; i < n; i++){
        int x{0};
        cin >> x;
        res ^= sg(x);
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}