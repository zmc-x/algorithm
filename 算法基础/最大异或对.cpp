/*
首先这一题真的比较巧妙，暴力的做法就是将两重循环，但是这样实现O(n ^ 2);
所以通过trie树来存储每一个数据的二进制表示，同时显而易见对于a xor b
要想满足最大的值，那么每一个二进制的表示就需要找到其对应的数；
譬如说：1 -> 0; 0 -> 1；由此就可以实现最大的数的表示；
所以实现原则就是近可能的找到与之对立的那个数，当然如果没有的话，那就选与之相同的
由此便可以实现
*/
#include<iostream>
#include<algorithm>

using namespace std;
extern const int N = 1e5 + 10;
// 初始化
int son[31 * N][2], index, a[N];
void insert(int x)
{
    int p{0};
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++index;
        p = son[p][u];
    }
}
// 返回最好的搭档 xor的另外的一个数
int query(int x)
{
    int p{0}, res{0};
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(son[p][!u]){
            res = (res << 1) + !u;
            p = son[p][!u];
        }
        else{
            res = (res << 1) + u;
            p = son[p][u];
        }
    }
    return res;
}
int main()
{
    int n{0}, res{0};
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        insert(a[i]);
        int mid = query(a[i]);
        res = max(res, mid ^ a[i]);
    }
    cout << res << endl;
    return 0;
}