/*
首先这是多重背包的优化版，对于这种多重背包问题其实可以抽象为多件物品的
01背包问题，但是直接枚举的时间复杂度比较大，那么可以通过二进制分堆来实现
简化操作；这种可以将时间复杂度优化到logS，可以对于每件物品数量可以分为
1, 2, 4, 8, 2 ^ k, c(c < 2 ^ k + 1)这么几个堆
那么这样就可以实现对任意的s的枚举了，然后把每个堆当成一种物品，来进行01背包问题的
处理即可
*/
package main

import (
    "bufio"
    "os"
    "fmt"
)

const N int = 12010

var (
      n, m int
      v, w [N]int
      f [N]int
)

func max(a, b int) int {
    if a >= b {
        return a 
    } else {
        return b
    }
}
func main() {
    input := bufio.NewReader(os.Stdin)
    fmt.Fscan(input, &n, &m)
    // 用来记录分的堆的个数
    cnt := 0
    for i := 1; i <= n; i++ {
        // a 体积 b 权重 c 限制个数
        var a, b, c int
        fmt.Fscan(input, &a, &b, &c)
        mid := 1
        for mid <= c {
            // 保证还是从1开始
            cnt ++
            v[cnt] = mid * a
            w[cnt] = mid * b 
            c -= mid
            mid <<= 1
        }
        if c > 0 {
            cnt++
            v[cnt] = c * a
            w[cnt] = c * b
        }
    }
    
    n = cnt
    for i := 1; i <= n; i++ {
        for j := m; j >= v[i]; j-- {
            f[j] = max(f[j], f[j - v[i]] + w[i])
        }
    }
    
    fmt.Println(f[m])
}