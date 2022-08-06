/*
    首先针对于这一题其实相对说其实也就是一个简单的bfs的过程，
    本题难的是如何进行相关的状态的转换，其实说白了就是如何去
    存储最后对应的字符串以及相应的distance；这里采用unordered_map
    来实现，其实也就是dict；将每一种state存入即可，当满足最后的
    条件时，那么就可以输出最后的dist了；
    当然主体还是一个bfs的过程，通过采用队列来实现。
    这里还有一维数组 -> 二维数组 这个其实一眼就可以看出来
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

int bfs(string start)
{
    int distance{0};
    string end = "12345678x";
    // 定义队列
    queue<string> q;
    q.push(start);
    unordered_map<string , int> dist;
    dist[start] = 0;
    // 移动向量
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    while(q.size()){
        string mid = q.front();
        q.pop();
        distance = dist[mid];
        // 判断是否具有结束的条件
        if(mid == end) return distance;
        // find 'x'
        int pos_x = mid.find('x');
        int x = pos_x / 3, y = pos_x % 3;
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            // swap两个数
            swap(mid[pos_x], mid[3 * a + b]);
            if(a >= 0 && a < 3 && b >= 0 && b < 3 && dist[mid] == 0){
                q.push(mid);
                dist[mid] = distance + 1;
            }
            // restore
            swap(mid[pos_x], mid[3 * a + b]);
        }
    }
    return -1;
}

int main()
{
    string start;
    char x;
    while(cin >> x) start += x;
    cout << bfs(start) << endl;
    return 0;
}