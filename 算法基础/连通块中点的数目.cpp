/*
首先这一题虽然是图，但是可以把其抽像其多个集合的并查集的问题
用cnt数组来存储每个顶点的数目（其实也就是一个集合所有元素的个数）
这里需要注意的是：当find(a) = find(b)，那么就不能够执行元素个数的
增加；此处受限于题目描述，一开始将判断条件加上了一个两个数不相等，
但是当两个数在同一个集合，且数不相等时，就会出现错误。故不需要，只需要
判断是否在同一个集合即可
*/
#include<iostream>
#include<string>
using namespace std;
extern const int N = 1e5 + 10;
// p[]中存fater，size[]存每个集合的数目
int p[N], cnt[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    string op;
    int n{0}, m{0}, a{0}, b{0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cnt[i] = 1;
    }
    while(m--){
        cin >> op;
        if(op == "C"){
            cin >> a >> b;
            if(find(a) != find(b)) cnt[find(b)] += cnt[find(a)];
            p[find(a)] = find(b);
        }
        else if(op == "Q1"){
            cin >> a >> b;
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}