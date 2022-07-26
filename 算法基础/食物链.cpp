/*
首先而言，这题可以通过并查集维护一些相关的信息来实现；任何的关系都可以转换为
和根节点之间的关系；而通过案例的分析以及题意可知这个其实就是也就只有3种关系
1，x 吃 root
2，root 吃 x
3，x 与 同类
那么很显然这个就是一个和%3挂钩的问题，那么假定mod 3 == 0 是 1；mod 3 == 1 
是 2；mod 3 == 2 是 3
那么就可以将这些数据全部存入一个树中进行相关的存储，从而可以得到两两之间的
相关的关系；
具体的实现：初始化两个数组，一个就是存入父节点，一个就是存入到root的路径；
首先对于find function的书写：
其中有这么一步，不是root点；那么就需要更新d数组，这里如果之间先加上d[p[x]]
那么由于find(p[x])没有执行，那么就有可能出现一些错误数据；
所以要先执行find(p[x])，然后使用中间值来进行相关的存储；
再就是假话的数目就是先看其是否满足 <= n；其次就是分是否再同一个集合来进行
相关的判断；来实现相关数目的加法
*/
#include<iostream>

using namespace std;
extern const int N = 5e4 + 10;
// 初始化
int p[N], d[N];
// find
int find(int x)
{
    if(p[x] != x){
        int mid = find(p[x]);
        d[x] += d[p[x]];
        p[x] = mid;
    }
    return p[x];
}
int main()
{
    int n{0}, k{0}, D{0}, x{0}, y{0}, cnt{0};
    cin >> n >> k;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(k--){
        cin >> D >> x >> y;
        int px = find(x), py = find(y);
        // x y > N
        if(x > n || y > n) cnt ++;
        else{
            // 同类
            if(D == 1){
                if(px == py && (d[x] - d[y]) % 3) cnt++;
                else if(px != py){
                    p[px] = py;
                    d[px] = (d[y] - d[x]) % 3;
                }
            }
            // 不是同类
            else{
                if(px == py && (d[x] - d[y] - 1) % 3) cnt++;
                else if(px != py){
                    p[px] = py;
                    d[px] = (d[y] + 1 - d[x]) % 3;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}