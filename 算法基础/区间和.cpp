/*
首先这题采用离散化的方法来实现，所谓离散化，其实也就是一种映射关系；
一般来说也就是将其去重排序后映射到下标，这样可以起到一种简化空间的功能。
（一般的情况也就是其值域很大，但是题目中所用到的数很少）
针对于这一题其实很简单的，就是将x,l,r全部映射到另一个数组，然后在对应的
数组中进行相关的加法，然后用前缀和将区间和输出；其实这个思路还是很简单的
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

extern const int N = 3e5 + 10;
struct Two{
    long long one;
    long long two;
};
// 初始化离散化后的数组
int a[N], s[N];
// 存所有离散化的数
vector<long long> store;
// 两个操作加，询问
vector<Two> add, query;
// 映射
long long find(long long x)
{
    long long l{0}, r{0}, mid{0};
    r = store.size() - 1;
    while(l < r){
        mid = (l + r + 1) / 2;
        if(store[mid] <= x) l = mid;
        else r = mid - 1;
    }
    // 为了求前缀和，起始位置为1
    return l + 1;
}
int main()
{
    long long x{0}, r{0}, l{0};
    int n{0}, m{0}, c{0}, len{0};
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        Two mid;
        mid.one = x;
        mid.two = c;
        add.push_back(mid);
        store.push_back(x);
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        Two mid;
        mid.one = l;
        mid.two = r;
        query.push_back(mid);
        store.push_back(l);
        store.push_back(r);
    }
    // 排序
    sort(store.begin(), store.end());
    // 去掉store中重复的元素
    store.erase(unique(store.begin(),store.end()),store.end());
    // 根据给定的x找到已经进行处理的数的离散化
    for(auto mid: add){
        a[find(mid.one)] += mid.two;
    }
    len = store.size();
    for(int i = 1; i <= len; i++) s[i] = s[i - 1] + a[i];
    for(auto mid: query){
        cout << s[find(mid.two)] - s[find(mid.one) - 1] << endl;
    }
    return 0;
}