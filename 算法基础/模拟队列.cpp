/*
通过数组来模拟query
对于这题只需要理解query的性质即可
-> 先进先出
*/
#include<iostream>
#include<string>

using namespace std;
extern const int N = 1e5 + 10;

// push
void push(int Query[], int &top, int x)
{
    Query[top ++] = x;
}
// pop
void pop(int Query[], int &low)
{
    low++;
}
// empty
bool empty(int top, int low)
{
    if(top - low == 0) return true;
    else return false;
}
// query
int query(int Query[], int &low)
{
    return Query[low];
}
int main()
{
    int Query[N], m{0}, x{0}, top{0}, low{0};
    string op;
    cin >> m;
    while(m --){
        cin >> op;
        if(op == "push"){
            cin >> x;
            push(Query, top, x);
        }
        else if(op == "pop"){
            if(!empty(top, low)) pop(Query, low);
        }
        else if(op == "empty"){
            if(empty(top, low)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            if(!empty(top, low)) cout << query(Query, low) << endl;
        }
    }
    return 0;
}