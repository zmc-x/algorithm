/*
这一题是采用静态链表的方式来模拟链表；主要是这个比较快
需要开辟的数组有val[], ne[], head, index
val就是表示当前下标的value
ne就是表示当前下标的下一个下标
head表示头指针
index表示当前的位置，就是一个工作指针
*/
#include<iostream>
using namespace std;
extern const int N = 1e5 + 10;

int val[N], ne[N], head{-1}, index{0}; 
// 在头节点后面插入数据
void add_head(int x)
{
    val[index] = x;
    ne[index] = head;
    head = index;
    index++;
}
// remove
void remove(int k)
{
    if(k){
        ne[k - 1] = ne[ne[k - 1]];
    }
    else{
        head = ne[head];
    }
}
// common add
void add(int k, int x)
{
    val[index] = x;
    ne[index] = ne[k - 1];
    ne[k - 1] = index;
    index++;
}
int main()
{
    int m{0}, k{0}, x{0}, i{0};
    char op{'0'};
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_head(x);
        }
        else if(op == 'D'){
            cin >> k;
            remove(k);
        }
        else{
            cin >> k >> x;
            add(k, x);
        }
    }
    // 输出
    i = head;
    while(i != -1){
        cout << val[i] << ' ';
        i = ne[i];
    }
    cout << endl;
    return 0;
}