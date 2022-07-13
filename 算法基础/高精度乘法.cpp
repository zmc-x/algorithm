/*
首先对于这一题同样也是手工的模拟，将b（较小的数）看成一个整体，然后通过
高精度的数来逐位的来乘，然后控制进位，循环迭代完就可以了。
同样这道题也需要考虑前导零的问题，似乎好像也是可以通过0来特判的
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> multiplication(vector<int>& x, int &b)
{
    vector<int> res;
    int i{0},mid{0}, len = x.size();
    while(i < len){
        mid += (x[i ++] * b);
        res.push_back(mid % 10);
        mid /= 10;
    }
    if(mid){
        while(mid / 10){
            res.push_back(mid % 10);
            mid /= 10;
        }
        res.push_back(mid % 10);
    }
    // 前导零的问题
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}
int main()
{
    string a;
    int b{0};
    vector<int> A;
    cin >> a >> b;
    // 逆序
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - 48);
    decltype(multiplication(A, b)) c = multiplication(A, b);
    // auto c = multiplication(A, b);
    for(int i = c.size() - 1; i >= 0; --i) cout << c[i];
    cout << endl;
    return 0;
}