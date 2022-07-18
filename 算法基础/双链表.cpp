/*
本题同样是采用静态链表的方式来实现，大致和单链表是差不多的
这里采用的是用下标0, 1的位置来实现链表的首和尾。
其他的操作在草稿纸上画图即可写出
*/
#include<iostream>
#include<string>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化数组
int val[N], l[N], r[N], index{0};
void init()
{
    // 用0，1号点表示边界
    r[0] = 1;
    l[1] = 0;
    index = 2;
}
void add_most_l(int x)
{
    val[index] = x;
    l[index] = 0;
    r[index] = r[0];
    l[r[0]] = index;
    r[0] = index;
    index++;
}
void add_most_r(int x)
{
    val[index] = x;
    l[index] = l[1];
    r[index] = 1;
    r[l[1]] = index;
    l[1] = index;
    index++;
}
// 左右通用，右边等价于r[k + 1] - 1
void add(int k, int x)
{
    val[index] = x;
    l[index] = l[k + 1];
    r[index] = k + 1;
    r[l[k + 1]] = index;
    l[k + 1] = index;
    index++;
}
void remove(int k)
{
    r[l[k + 1]] = r[k + 1];
    l[r[k + 1]] = l[k + 1];
}
int main()
{
    int m{0}, x{0}, k{0}, i{0};
    string op;
    cin >> m;
    init();
    while(m--){
        // cin读取string时遇到空白就不读入了
        cin >> op;
        if(op == "L"){
            cin >> x;
            add_most_l(x);
        }
        else if(op == "R"){
            cin >> x;
            add_most_r(x);
        }
        else if(op == "D"){
            cin >> k;
            remove(k);
        }
        else if(op == "IL"){
            cin >> k >> x;
            add(k, x);
        }
        else{
            cin >> k >> x;
            add(r[k + 1] - 1, x);
        }
    }
    // 遍历输出
    i = r[0];
    while(i != 1){
        cout << val[i] << ' ';
        i = r[i];
    }
    cout << endl;
    return 0;
}