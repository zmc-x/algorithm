/*
首先这是一个很简单的堆排序
至于建立heap的过程，从n / 2开始建heap，然后不断的进行down操作，将数据下沉，这样的时间复杂度是小于O(n)的。
然后就是down操作，首先就是找到三个数的min最小的value，然后进行swap，如果此时min的position就是形参，那么
就不用再递归调用了，否则就需要循环调用down(min_pos);
*/
#include<iostream>
#include<algorithm>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化
int h[N], cnt;

// down 
void down(int pos)
{
    int min_pos{pos};
    // 找min
    if(pos * 2 <= cnt && h[pos * 2] < h[pos]) min_pos = pos * 2;
    if(pos * 2 + 1 <= cnt && h[pos * 2 + 1] < h[min_pos]) min_pos = pos * 2 + 1;
    if(min_pos != pos){
        swap(h[pos], h[min_pos]);
        down(min_pos);
    }
}
int main()
{
    int n{0}, m{0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    cnt = n;
    // 建heap
    for(int i = n / 2; i >= 1; i--) down(i);
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[cnt];
        cnt--;
        down(1);
    }
    return 0;
}