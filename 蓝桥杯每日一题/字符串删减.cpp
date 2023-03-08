#include<iostream>
#include<string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0, res = 0;
    for(int r = 0; r < n; r++) {
        if(str[r] == 'x') cnt++;
        else cnt = 0;
        while(cnt >= 3) {
            cnt--;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
