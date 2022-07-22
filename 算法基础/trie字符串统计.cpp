/*
 首先这一题是一个典型的trie字典树的题目；
 而trie就是将字符串拆分然后不断的进行添加节点；
 在这一点上，这个其实有点类似Huffman（但是trie和Huffman不同）
 现在来讲一下实现的过程，
 首先用一个二维数组来进行结点的存储，第一维就是一个大致的位置，而第二维就是存储26个字母
 的节点的位置。如果该点不存在value，那么就直接将index值+1赋给ta；然后整个二维数组中的值
 就指向下一个节点大致的位置即p = son[p][u]；最后在字符结束的同时给其打上一个flag即可，cnt[p]++；
 对于每一个p都是unique的，所以cnt就可以来存储出现的字符串出现的次数
 而query是和insert类似的
*/
#include<iostream>
#include<string>

using namespace std;
extern const int N = 1e5 + 10;
int son[N][26], cnt[N], index;

void insert(char str[])
{
    int p{0};
    for(int i = 0; str[i]; i++){
        // 映射
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++index;
        p = son[p][u];
    }
    // 为每一个字符串设置一个flag
    cnt[p]++;
}
void query(char str[])
{
    int p{0};
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        p = son[p][u];
        if(!p) break;
    }
    if(cnt[p]) cout << cnt[p] << endl;
    else cout << 0 << endl;
}
int main()
{
    int n{0};
    char op, str[N];
    cin >> n;
    while(n --){
        cin >> op >> str;
        if(op == 'I') insert(str);
        else query(str);
    }
    return 0;
}