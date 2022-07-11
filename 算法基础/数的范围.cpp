/*
本题采用二分的思想来实现，通过二分不断的缩小区间范围，求取边界，
到最后边界就是l/r，因为就是一个逼近的思想；
这里需要注意就是加一与否的问题，
记住当l = mid时就要+1，不然就会死循环,
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;

int main()
{
    int n{0}, q{0},a[N],k{0};
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i ++){
        cin >> k;
        // 根据实际情况看是否需要+1
        int l = 0, r = n - 1, mid{0};
        while(l < r){
            mid = (l + r) / 2;
            if(a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(a[l] != k) cout << "-1 -1" << endl;
        else {
                cout << l << ' ';
                l = 0, r = n - 1;
                while(l < r){
                    mid = (l + r + 1) / 2;
                    if(a[mid] <= k) l = mid;
                    else r = mid - 1;
                }
                cout << l << endl;
        }
    }
    return 0;
}