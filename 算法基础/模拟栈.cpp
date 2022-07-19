/*
本题理解栈的基本结构即可--“先进后出”
然后本题直接采用c++中的vector container来实现
当然c++中也是存在stack的；但是vector在实现的过程中
其实也就是stack
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
extern const int N = 1e5 + 10;

int main()
{
    int m{0}, x{0};
    string op;
    vector<int> stack;
    cin >> m;
    while(m--){
        cin >> op;
        if(op == "push") cin >> x, stack.push_back(x);
        else if(op == "pop") stack.pop_back();
        else if(op == "query") cout << stack.back() << endl;
        else{
            if(stack.empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}