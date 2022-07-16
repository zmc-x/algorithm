/*
本题其实就是一个双指针罢了，具体思路就是：
不断的找相同的元素，当元素相同了，两个指针在同时向
后同时移动一位，
当j（下）>= len(下) No
当i（上）>= len(上) Yes
*/
#include<iostream>
using namespace std;

extern const int N = 1e5 + 10;

int main()
{
    long long a[N], b[N];
    int n{0}, m{0}, i{0}, j{0};
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    // 双指针template
    for(i = 0; i < n; i++, j++){
        while(j < m && b[j] != a[i]) j++;
        if(j >= m){
            cout << "No" << endl;
            break;
        }
    }
    if(i >= n) cout << "Yes" << endl;
    return 0;
}