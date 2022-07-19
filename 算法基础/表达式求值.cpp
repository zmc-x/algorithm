/*
    这题其实就是使用两个stack来实现数据的相关的存储，一个数据stack，一个操作stack;
    首先需要解决的就是两个操作符的优先级。因为stack中的元素优先级>输入操作的优先级
    那么就会先将数据从stack中pop，然后进行相关的操作之后再将数据push进入到number stack中
    反之直接push
    优先级：+ - < * /
    但是在本题还需要考虑的是括号的问题，左括号直接push即可，但是右括号直接就算到左括号即可，
    然后将左括号pop出来即可
    还有一个疑问就是在stack中是有可能出现右括号的，但是右括号的优先级最低，可以直接特判一下即可。
    当然还有一下小细节，直接看code即可
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 开辟两个vector来存储数据
vector<int> num;
vector<char> op;
// 计算相关的值
void conclude()
{
    char oper = op.back();
    op.pop_back();
    int a = num.back();
    num.pop_back();
    int b = num.back();
    num.pop_back();
    if(oper == '+') num.push_back(a + b);
    else if(oper == '-') num.push_back(b - a);
    else if(oper == '/') num.push_back(b / a);
    else num.push_back(a * b);
}
// level
bool level(char a, char b)
{
    // 特判一下(
    if(a == '(') return false;
    else if((a == '+' || a == '-') && (b == '*' || b == '/')) return false;
    else if((a == '+' || a == '-') && (b == '+' || b == '-')) return true;
    else if((a == '*' || a == '/') && (b == '*' || b == '/')) return true;
    else return true;
}
int main()
{
    string str;
    int mid{0};
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        // 将数据插入num
        if(str[i] >= '0' && str[i] <= '9'){
            mid = mid * 10 + str[i] - 48;
            if(i == str.size() - 1 || str[i + 1] < '0' || str[i + 1] > '9') num.push_back(mid), mid = 0;
        }
        // (直接push进入到op中
        else if(str[i] == '(') op.push_back(str[i]);
        // )直接计算到(
        else if(str[i] == ')'){
            while(op.back() != '(') conclude();
            // 将( pop弹出
            op.pop_back();
        }
        else{
            // 将+ - * /放入到op中
            while((!op.empty()) && level(op.back(), str[i])) conclude();
            op.push_back(str[i]);
        }
    }
    // 输出值
    while(!op.empty()) conclude();
    cout << num.back() << endl;
    return 0;
}