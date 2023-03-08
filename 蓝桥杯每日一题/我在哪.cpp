#include<iostream>
/*
本题思路就是通过枚举k的范围[1, n]；然后再来判断区间中的每一个str；
然后即可计算出min(k);
然后对于k的枚举，可以采用二分的思路来做，因为满足二段性；
时间复杂度为O(n ^ 2 logn)
*/
#include<string>
#include<unordered_set>

using namespace std;

int n;
string str;

bool check(int k) {
    unordered_set<string>hash;
    for(int i = 0; i <= n - k; i++) {
        string mid = str.substr(i, k);
        if(hash.count(mid)) return false;
        hash.emplace(mid);
    }
    return true;
}

int main() {
    cin >> n >> str;
    // 二分
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
