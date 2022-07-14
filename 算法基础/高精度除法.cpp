/*
同样也是模拟人工的做法，
首先从最高位开始，置余数为最高位，然后开始/，将商写入res中，
余数=此时的余数 * 10 + 下一位数，然后再循环即可，
最后将数组reverse一下方便处理前导零
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> division(vector<int> &x, int &y)
{
    vector<int> res;
    int mid{0}, i{0}, len = x.size();
    for(int i = len - 1; i >= 0; --i){
        mid = mid * 10 + x[i];
        res.push_back(mid / y);
        mid = mid % y;
    }
    // 将整个数组reverse，调用c++中自带的算法库
    reverse(res.begin(), res.end());
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    res.push_back(mid);
    return res;
}
int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    // 逆序存储
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - 48);
    auto c = division(A, b);
    for(int i = c.size() - 2; i >= 0; --i) cout << c[i];
    cout << endl;
    cout << c[c.size() - 1] << endl;
    return 0;
}