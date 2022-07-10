/*
一个单纯的快速排序， 然后取其第k个数即可
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;

void quick_sort(int a[], int l, int r)
{
    // 递归出口
    if(l >= r) return;
    // 取参考值
    int mid = a[(r + l) >> 1], i = l - 1, j = r + 1;
    while(i < j){
        while(a[++ i] < mid);
        while(a[-- j] > mid);
        if(i < j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
int main()
{
    int n{0},k{0},a[N];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0 , n - 1);
    cout << a[k - 1];
    return 0;
}