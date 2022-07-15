/*
这一题主要使用差分的思想来实现，
1. 构建差分数组，先将前缀和数组a[]和差分数组s[]初始化为0；
2. 对于a[]中[l, r]区间中每一个数都加c，那么对于差分数组b[]而言，
   只需要满足b[l] + c，和b[r + 1] - c即可；如此这样便可以实现
   区间内的前缀和都加c而其他的前缀和不影响。
3. 对于差分数组的构造，可以这么理解：向a[]中插入一个数，就可以看作在
   一个区间中插入数，那么就可以在原来的差分数组中进行+，-操作即可。
4. 再循环调用即可。
*/
#include<iostream>

using namespace std;
extern const int N = 1e5 + 10;
// 初始化前缀和数组和差分数组
int a[N], s[N];
void insert(int l, int r, int c)
{
    s[l] += c;
    s[r + 1] -= c;
}
int main()
{
    int n{0}, m{0}, l{0}, r{0}, c{0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // 构造差分的数组
        insert(i, i, a[i]);
        a[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    // 重新算前缀和
    for(int i = 1; i <= n; i++) a[i] = a[i - 1] + s[i];
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}