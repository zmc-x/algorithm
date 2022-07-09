/*
本算法需要注意的地方就是在最后分治的时候，当你取j来作为分界点来做的话，那么就不能够取R来作为参考值（一开始做比较的数），
取i来作为分界点，不能够取L作为参考值；
一般来书取中间值/随机值会好一些，这样就可以避免一些边界问题；
但是对于取i的来说，使用中间值可能在后面的递归的同时也有可能出现死循环的过程（其原理和取L时的一样；
所以一般来说，推荐使用j来作为分界点。
算法的基本过程：
1.使用双指针来实现对参考值左右两边的数的比较，已经换位，
  当a[i] >= x 时i停下，当a[j] <= x时停下，然后当i与j没有相遇的时候就将其swap，
2.最后就是左右递归
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
// n个整数
extern const int N = 1e5 + 10;
void quickly_sort(long long a[], int l, int r)
{
    // 判断边界
    if (l >= r) return;
    // 便于向中间移动
    int x = a[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        // 交换的条件为i < j
        if (i < j) {
            int mid = a[i];
            a[i] = a[j];
            a[j] = mid;
        }
    }
    quickly_sort(a, l, j);
    quickly_sort(a, j + 1, r);
}
int main()
{
    // define the parameters
    int n{0};
    long long a[N];
    scanf("%d" ,&n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    quickly_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%lld ", a[i]);
    return 0;
}
