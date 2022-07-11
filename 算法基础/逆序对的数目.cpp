/*
首先这一题其实就是归并的一个变体，它借用了归并的相关的思想，
但是不同的是，ta需要找最大的value，然后通过在合并的同时就可以求出
逆序对的个数，
重要的地方：
这个难点其实就是加的个数，因为是有序的数组，那么每次相加的其实就是下面有序数组还存在的数组的个数
*/
#include<iostream>
using namespace std;
extern const int N =1e5;
// 计数
long long cnt{0};
// temporary array to store the data
int tem[N];
void merge_sort_count(int a[], int l, int r)
{
    // 递归出口
    if(l >= r) return;
    int mid = (l + r) / 2;
    // 左右递归
    merge_sort_count(a, l, mid);
    merge_sort_count(a, mid + 1, r);
    // 将两个有序的数组合并，并计数
    int i = l, j = mid + 1, k{0};
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) tem[k ++] = a[j ++];
        else{
            tem[k ++] = a[i ++];
            // 逆序对的个数
            cnt += (r - j + 1);
        }
    }
    // 将余下的全部存入tem中
    while(i < mid + 1) tem[k ++] = a[i ++];
    while(j <= r) tem[k ++] = a[j ++];
    // 将数据写回
    for(i = 0, j = l; i < k, j <= r; i++, j++) a[j] = tem[i];
}
int main()
{
    int n{0},a[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort_count(a, 0, n - 1);
    cout << cnt << endl;
    return 0;
} 