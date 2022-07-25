/*
首先这一题同样是构建小根堆来实现，首先这题题目有要求就是要是实现对第k个插入的数的相关的操作
那么对于这题而言，就需要将第k个插入的数和heap中的下标联系起来，这样就可以实现这两个数的映射
了；具体的实现方法就是用两个数组来进行存储，ph来存第k个数在heap中的下标是啥；hp是来存储heap
下标对应的是第几个插入的数；如此就可以实现对第k个数的相关的操作。
这里再说一下up操作，就是不断向上迭代找比现在数的大的数，然后进行交换；但是我一开始写的是
h[pos / 2] >= h[pos]但是这样会出问题，因为当两个数相等时，那么再执行上述的swap操作时，
然后在执行删除操作的时候，会再次执行一次swap操作，可能就会删除本不该删除的元素，那么再
执行修改操作的时候，实际上修改的元素可能都不会存在了，那么就可能出现错误；
所以需要修改将其改为h[pos / 2] > h[pos]即可
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
extern const int N = 1e5 + 10;
// 初始化
// ph 和 hp 是两种映射关系，ph -> h, h -> hp
int h[N], cnt, ph[N], hp[N];

void swap_heap(int a, int b)
{
    // 找到第i, j个插入的数
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int pos)
{
    int min_pos = pos;
    if(2 * pos <= cnt && h[2 * pos] < h[min_pos]) min_pos = 2 * pos;
    if(2 * pos + 1 <= cnt && h[2 * pos + 1] < h[min_pos]) min_pos = 2 * pos + 1;
    if(min_pos != pos){
        swap_heap(pos, min_pos);
        down(min_pos);
    }
}
void up(int pos)
{
    while(pos / 2 && h[pos / 2] > h[pos]){
        swap_heap(pos / 2, pos);
        pos /= 2;
    }
}
int main()
{
    int n{0}, x{0}, k{0}, count{0};
    string op;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == "I"){
            cin >> x;
            count++;
            cnt++;
            h[cnt] = x;
            ph[count] = cnt;
            hp[cnt] = count;
            up(cnt);
        }
        else if(op == "PM"){
            cout << h[1] << endl;
        }
        else if(op == "DM"){
            swap_heap(1, cnt);
            cnt --;
            down(1);
        }
        else if(op == "D"){
            cin >> k;
            // 删除的第k个数的下标
            k = ph[k];
            swap_heap(k, cnt);
            cnt--;
            up(k);
            down(k);    
            
        }
        else{
            cin >> k >> x;
            h[ph[k]] = x;
            up(ph[k]);
            down(ph[k]);
        }
    }
    return 0;
}