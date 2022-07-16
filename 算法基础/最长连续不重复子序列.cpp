/*
本题就是双指针的做法，说一下思路：首先通过s数组来动态的存储数的个数，用i来表示终点，
j表示起点，然后判断一下，当新加入的数的cnt != 1（可能换成> 1 好一些） 那么就是说明
这个数是重复的，然后j++；最后在判断max（res，和此时的res）；然后输出res即可
*/
#include<iostream>

using namespace std;
extern const int N = 1e5 + 10;
// 初始化s[]
int s[N];

int main()
{
    int n{0},b[N],res{0};
    cin >> n;
    for(int i = 0; i <= n; i++) cin >> b[i];
    // 双指针算
    for(int i = 0, j = 0; i < n; i++){
        // 计数
        s[b[i]] ++;
        while(j < i && s[b[i]] != 1){
            // 将数据的个数减少
            s[b[j]] --;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}