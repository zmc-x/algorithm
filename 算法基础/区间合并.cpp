/*
思路：
1. 先调用sort函数排序，
2. 然后再选择进行相应的区间合并的操作
   这里有三种情况（起始区间是[st, ed]）：
   1' ed > item.second 在第一个区间的内部
   2' ed >= item.first && item.second >= ed 存在交集
   3' item.first > ed 另一区间，即可以合并区间了
   这里的1&2其实是可以合并写的，就是取max（）即可
3. 最后需要合并一下最后的区间，前提是不是最开始的区间，也就是不是空的区间
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using PLL = pair<long long, long long>;
extern const int N = 1e5 + 10;
// 区间合并
int merge(vector<PLL> &store)
{
    long long st{0},en{0};
    st = -1e9 -10;
    en = 1e9 + 10;
    int cnt{0};
    for(auto item : store){
        if(st == (-1e9 - 10)){
            st = item.first;
            en = item.second;
        }
        else{
            if(en >= item.first && item.second >= en){
                en = item.second;
            }
            else if(item.first > en){
                cnt++;
                st = item.first;
                en = item.second;
            }
        }
    }
    // 判断最后一个区间，可能为空的区间
    if(st != -1e9 - 10) cnt++;
    return cnt;
}
int main()
{
    vector<PLL> store;
    int n{0};
    long long l{0}, r{0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        store.push_back({l, r});
    }
    sort(store.begin(), store.end());
    auto res = merge(store);
    cout << res << endl;
    return 0;
}