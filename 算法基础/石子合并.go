/*
这是一个区间dp的问题，首先状态表示为：f(i, j)表示为从第i堆石子到第j堆石子
所耗费的最大的代价
状态计算：因为最后一次合并都是两个变一个，那么就可以通过分界线来实现对集合的划分
	k表示分界线的下标：f(i, j) = min(f(i, j), f(i, k) + f(k + 1, j) + s[j] - s[r - 1])

	这里的循环需要保证每一次都有序的去实现，那么就可以先枚举区间长度，然后再枚举区间的起始点
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const N int = 310
const Max int = 0x3f3f3f3f

var (
    s [N]int
    f [N][N]int
)

func min(a, b int) int {
    if a <= b {
        return a
    } else {
        return b
    }
}


func main() {
    input := bufio.NewReader(os.Stdin)
    
    var n int 
    fmt.Scanf("%d", &n)
    
    for i := 1; i <= n; i++ {
        fmt.Fscan(input, &s[i])
        // 前缀和
        s[i] += s[i - 1]
    }
    // 通过区间长度来计算
    for len := 2; len <= n; len ++ {
        // 右边界需要小于n
        for i := 1; i + len - 1 <= n; i++ {
            // 枚举区间起始点
            l, r := i, i + len - 1
            f[l][r] = Max
            for k := l; k <= r - 1; k ++ {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1])
            }
        }
    }
    
    fmt.Println(f[1][n])
}