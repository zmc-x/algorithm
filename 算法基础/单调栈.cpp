/*
    本题是单调栈的一般的template，而其一般要解决的问题就是求某个数左边比ta小的第一个数；
    其他的类型也是和其差不多的。
    以这题为例，ta要找比ta小的左边的第一个数；
    我们用栈来实现，如果单纯的使用stack的话，那么就是一个O(n^2)的算法；现在稍微优化一下，那么
    就是当存在stack[top] >= x的话；那么其实此时的stack[top]是永远也用不到的，因为x更符合题目
    的要求一点。
    然后就是stack的实现，其实可以掉container的，但是由于想尝试一下数组模拟；结果搞了好久，就是
    下标没有处理好，这里采用的是从1开始来实现stack store
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;

int main()
{
    // stack从1开始存数据
    int n{0}, top{0}, stack[N], x{0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(top && stack[top] >= x) top--;
        if(top) cout << stack[top] << ' ';
        else cout << -1 << ' ';
        stack[++top] = x;
    }
    cout << endl;
    return 0;
}