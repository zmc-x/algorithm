/*
典型的并查集的问题；
core就是find function这里蕴含路径压缩
对于这一题其实每一个element对应一个集合编号
也就是自身的编号，那么对应find(x)就是集合编号
那么同样root编号也就是find(x)的编号；
那么集合合并 -> p[find(a)] = find(b) 就很好解释了
同样find function其实也运用到了这个性质，并将全部的
点最后都指向了集合编号，即路径压缩
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;
// 来存储每个元素的父节点
int p[N];

// 查询x的祖宗节点（集合编号） + 路径压缩
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n{0}, m{0}, a{0}, b{0};
    char op;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        cin >> op >> a >> b;
        if(op == 'M'){
            // 此处find(a) = root编号
            p[find(a)] = find(b);
        }
        else{
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}