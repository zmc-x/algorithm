/*
求二进制中1的个数通常使用lowbit操作来实现；
lowbit返回的是最后的一个1，那么再次将这个return value
减掉，然后再做上述操作，直到值为0，那么此时的cnt就是1的个数；
lowbit操作：x & -x；（这样可以返回二进制中的最后的一个1）
求二进制中的第k位：x >> k & 1；（右移k位将其移到个位上，然后就可以判断是1还是0）
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;
// 使用lowbit来实现
int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n{0},a[N],cnt{0};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt = 0;
        while(a[i]){
            a[i] -= lowbit(a[i]);
            cnt++;
        }
        cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}