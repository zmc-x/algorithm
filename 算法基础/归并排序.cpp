/*
算法思路：对于归并排序，这个其实就是分治的思想，首先将一个数组递归处理，对“归”的两个有序数组进行合并（主要思想就是双指针的思想）
1. 将数组分解为两个等长的数组（可能不等
2. 分别左右的递归
3. 对左右递归的数组进行合并处理
*/
#include<iostream>

using namespace std;
extern const int N = 1e5 + 10;
// temperary the data
int tem[N];
// merge_sort
void merge_sort(int a[], int l, int r)
{
    // 递归函数的出口
    if(l >= r) return;
    // 分界点
    int mid = (l + r) / 2;
    // 左右递归
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    // 将两个有序的数组中的元素进行合并
    // 定义两个指针
    int i = l, j = mid + 1, cnt{0};
    while(i < mid + 1 && j <= r){
        if(a[i] <= a[j]){
            tem[cnt ++] = a[i];
            i++;
        }
        else{
            tem[cnt ++] = a[j];
            j++;
        }
    }
    // 将余下的数组元素加入到tem中
    while(i <= mid){
        tem[cnt ++] = a[i];
        i++;
    }
    while(j <= r){
        tem[cnt ++] = a[j];
        j++;
    }
    // 将tem数组中的元素写入到a中
    // for(i = 0, j = l; i < cnt, j <= r; i++, j++) a[j] = tem[i];
    for(i = l,j = 0;i <= r,j < cnt; i++,j++) a[i] = tem[j];
}
int main()
{
    int n{0}, a[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}