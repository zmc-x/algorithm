/*
首先这题的具体做法是采用双指针来实现，通过逼近的思想来实现，
因为两个数组都是逐渐递增的，那么对于两个数组中一个取最小的元素（i下标），一个取最大的元素（j下标）
若和 > x；那么j--（此时的值已经不满足的，那么就得j--；使值变小，），同样当i++时，也进行相关的判断，
对j采取是否--的操作。
最后将满足的i，j输出即可。
本题关键是两个数组都是“递增的”，
*/
#include<iostream>

using namespace std;
extern const int N = 1e5 + 10;

int main()
{
    int n{0}, m{0}, x{0}, a[N], b[N], i{0}, j{0};
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    // 双指针的算法
    for(int i = 0, j = m - 1; i < n; i++){
        while(j >= 0 && a[i] + b[j] > x) j--;
        if(a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }
    return 0;
}