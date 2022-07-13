/*
这题思路和加法的类型，都是模拟人工计算
首先就两种情况：
1. a - b - t >= 0; result = a - b -t;
2. a - b - t < 0; result = a - b - t + 10;
=> result = (a - b - t + 10) % 10
需要注意的就是前导零的问题（因为是逆序存储的）
判断位数 > 1和最后一位是否为0，然后剔除即可
*/
#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
bool cmp(vector<int> &x, vector<int> &y)
{
    // 先判断位数
    if(x.size() != y.size()) return x.size() > y.size();
    else{
        // 逆序判断
        for(int i = x.size() - 1; i >= 0; --i){
            if(x[i] != y[i]) return x[i] > y[i];
        }
        // 全部相等
        return true;
    }
}
vector<int> subtraction(vector<int> & x, vector<int> & y)
{
    vector<int> res;
    int i{0}, mid{0}, len_x = x.size(), len_y = y.size();
    for(i = 0; i < len_x; i++){
        mid = x[i] - mid;
        if(i < len_y) mid -= y[i];
        res.push_back((mid + 10) % 10);
        if(mid < 0) mid = 1;
        else mid = 0;
    }
    // 将前导零去掉
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}
int main()
{
    string a,b;
    vector<int>A,B;
    cin >> a >> b;
    // 同样将数组逆序存入
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - 48);
    for(int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - 48);
    // 先判断A，B的大小
    if(cmp(A, B)){
        auto c = subtraction(A, B);
        for(int i = c.size() - 1; i >= 0; --i) cout << c[i];
    }
    else{
        auto c = subtraction(B, A);
        cout << '-';
        for(int i = c.size() - 1; i >= 0; --i) cout << c[i];
    }
    cout << endl;
    return 0;
}