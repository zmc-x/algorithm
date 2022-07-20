/*
    首先这题其实是单调队列的一个典型的例题，就是采用一个队列来存取
    数据，譬如说这里是求min，那么当队列的最后的一个数 > 此时输入的
    数据时，那么队顶元素其实永远也用不到，那么就可以将这个数pop掉；
    那么此时得到的query其实就是一个单调的query；
    同时这里也需要注意就是队头可能会出窗口，那么当队头出窗口时，那么
    就将这个队头给pop掉。
    同时这里需要注意的是，这query中其实存的是数组的下标，因为这样可以
    较为简单的处理出界的问题
*/
#include<iostream>
#include<cstdio>
using namespace std;
extern const int N = 1e6 + 10;

int Query[N], a[N];
int main()
{
    int n{0}, k{0}, low{0}, top{0};
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    // 处理元素
    for(int i = 0; i < n; i++){
        // 先判断是否超过窗口
        if(top - low > 0 && Query[low] < i - k + 1 ) low++;
        // 处理队列元素
        while(top - low && a[Query[top - 1]] >= a[i]) top--;
        Query[top++] = i;
        if(i >= k - 1) printf("%d ", a[Query[low]]);
    }
    cout << endl;
    // max
    top = low = 0;
    for(int i = 0; i < n; i++){
        // 先判断是否超过窗口
        if(top - low > 0 && Query[low] < i - k + 1 ) low++;
        // 处理队列元素
        while(top - low && a[Query[top - 1]] <= a[i]) top--;
        Query[top++] = i;
        if(i >= k - 1) printf("%d ", a[Query[low]]);
    }
    cout << endl;
    return 0;
}