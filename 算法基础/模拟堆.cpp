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