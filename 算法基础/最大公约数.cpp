/*
首先求gcd就是采用辗转相除来计算，首先可以知道gcd(a, b) = gcd(a, a % b)；
证明：
    d是公因子，那么d | a, d | b, d | s * a + t * b；
    对于a mod b = r1 = a - (a / b) * b；所以其实也是一个a与b的线性组合；
    所以d | a mod b
    故：gcd(a, b) = gcd(a, a mod b)；
    从而存在递归：b ? gcd(max(a, b), max(a, b) % min(a, b)) : a;
*/
#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(min(a, b), max(a, b) % min(a, b)) : a;
}
int main()
{
    int n{0}, a{0}, b{0};
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}