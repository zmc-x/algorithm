/*
    本题思考模式为每一个砖块只能操作一次；那么对于第一个砖块而言，只有其第1，2发生
    改变，才可能发生变化；然后开始对后n - 1个砖块进行操作，同样也是考虑“第一个砖块”；
    原则是：若第一个满足条件，则reverse；否则不变；
    当到达n - 1时，若其不满足，则return -1；反之有解
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int T;

void update(char& a) {
    if(a == 'W') a = 'B';
    else a = 'W';
}

bool check(string str, char c, int n) {
    vector<int> res;
    for(int i = 0; i + 1 < n; i++) {
        if(str[i] != c){
            update(str[i]), update(str[i + 1]);
            res.push_back(i + 1);
        }
    }
    if(str[n - 1] != c) return false;
    cout << res.size() << endl;
    for(int i : res) cout << i << ' ';
    if(res.size() != 0) cout << endl;
    return true;
}
int main() {
    cin >> T;
    while(T--) {
        int n;
        string str;
        cin >> n >> str;
        if(!check(str, 'B', n) && !check(str, 'W', n)) puts("-1");
    }
    return 0;
}

