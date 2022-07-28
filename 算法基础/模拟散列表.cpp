/*
    拉链法
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
/*
    开放寻址法
    首先这种方法比较简单，只需要开辟一个数组空间就可以完成了。
这种方法就类似于上厕所，寻找坑位的过程。如果此时位置存在位置，那么就不断向后寻找，
直到找到空的地方位置，值得注意的是需要找一个不在数据范围的数进行相关的标志操作。
而核心就是find function，
*/
#include<iostream>
using namespace std;
extern const int N = 3e5 + 17;
extern const long long Flag = 1e9 + 1;
// 初始化
long long h[N];
// return the position
int find(int x)
{
    int pos{0};
    pos = ((x % N) + N) % N;
    while(h[pos] != Flag && h[pos] != x) pos = (pos + 1) % N;
    return pos;
}
int main()
{
    for(int i = 0; i < N; i++) h[i] = Flag;
    char op;
    int x{0}, n{0}, k{0};
    cin >> n;
    while(n--){
        cin >> op >> x;
        k = find(x);
        if(op == 'I'){
            h[k] = x;
        }
        else{
            if(h[k] == Flag) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}