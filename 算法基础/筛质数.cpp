/*
这里采用的是线性筛法，通过采用素数序列来筛掉相关的合数。
其实利用的相关的原理就是整数的分解，然后通过素数序列和i
即可完成最小质数来筛选合数的任务。而对于二重循环中的i % primes[j] == 0，
则可以保证筛选的过程是一个线性的。
对于i为质数：那么必然可以筛到priems[j] == i
而对于i为合数，那么就要primes[]中肯定存在一个数使得 | i，从而结束二重循环；


对于埃式筛法，比较简单，就是将是质数的倍数的数全部筛掉，时间复杂度为：O(n * log(log n))
*/
#include<iostream>

using namespace std;
extern const int N = 1e7 + 10;

int primes[N];
bool sta[N];
// 不是质数true，是质数为false
int find(int n)
{
    int cnt{0};
    for(int i = 2; i <= n; i++){
        if(!sta[i]) primes[cnt++] = i;
        // 通过素数序列来筛掉合数
        for(int j = 0; primes[j] * i <= n; j++){
            sta[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
    return cnt;
}

int main()
{
    int n{0};
    cin >> n;
    cout << find(n) << endl;
    return 0;
}