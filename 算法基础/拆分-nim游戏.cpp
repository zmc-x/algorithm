#include<iostream>
#include<cstring>
#include<unordered_set>

using namespace std;
extern const int N = 110;

int f[N];

int sg(int x)
{
    if(f[x] != -1) return f[x];
    
    unordered_set<int> S;
    // 计算sg的值
    for(int i = 0; i < x; i++){
        for(int j = 0; j <= i; j++){
            S.insert(sg(i) ^ sg(j));
        }
    }
    
    for(int i = 0; ; i++){
        if(!S.count(i)) {
            f[x] = i;
            return f[x];
        }
    }
}
int main()
{
    int n{0}, res{0};
    cin >> n;
    // 初始化
    memset(f, -1, sizeof(f));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}