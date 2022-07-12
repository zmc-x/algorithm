/*
高精度的加法这个其实就是一个模拟人工加法的过程，
首先使用数组将大数逆序存储起来，这样可以方便计算，
然后再用一个mid来进行中间的值的相关的操作；如：进位。。
最后还需要注意的就是需要判断当两个数加完的时候，mid是否为NULL，
如果有，就需要进位；反之不需要
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> add(vector<int> &x, vector<int> &y)
{
    vector<int> res;
    int mid{0}, i{0}, j{0}, len_x = x.size(), len_y = y.size();
    while(i < len_x || j < len_y){
        if(i < len_x) mid += x[i++];
        if(j < len_y) mid += y[j++];
        res.push_back(mid % 10);
        mid /= 10;
    }
    // 向最高位的进位
    if(mid) res.push_back(mid);
    return res;
}
int main()
{
    string a,b;
    vector<int> A, B;
    cin >> a >> b;
    // 进行逆序存储
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - 48);
    for(int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - 48);
    // 高精度加法
    auto res = add(A, B);
    // 逆序输出
    for(int i = res.size() - 1; i >= 0; --i) cout << res[i];
    cout << endl;
    return 0;
}