/*
    首先这一题是Hash表的一个典型的题目，本题采用拉链法来实现对数据的
存储，首先通过mod来取得再主串中的position，然后通过静态链表的方式来
进行相关的存储即可
*/
#include<iostream>
#include<cstring>
using namespace std;
extern const int N = 1e5 + 3;
// 初始化
int h[N], val[N], ne[N], idx;
// insert
void insert(int x)
{
    int pos{0};
    pos = ((x % N) + N) % N;
    val[idx] = x;
    ne[idx] = h[pos];
    h[pos] = idx++;
}
// query
void query(int x)
{
    int pos{0}, mid{0};
    pos = ((x % N) + N) % N;
    mid = h[pos];
    while(val[mid] != x && mid != -1){
        mid = ne[mid];
    }
    if(mid != -1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main()
{
    // 将所有的头节点置为-1
    memset(h, -1, sizeof(h));
    char op;
    int x{0}, n{0};
    cin >> n;
    while(n--){
        cin >> op >> x;
        if(op == 'I'){
            insert(x);
        }
        else{
            query(x);
        }
    }
    return 0;
}