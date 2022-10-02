/*
首先这题本质上还是背包问题，那么其需要解决的问题就是使得在体积小于V下，权重最大
状态表示：
	f(i, j) i表示从0 ~ i中取选择物品，而总体积不超过j
状态计算：
	按照第i组选择第几种物品来进行相应的划分，如：不选，选择第一种物品，第二种，。。。。
	f(i, j) = Max(f(i - 1, j), f(i - 1, j - Vi1) + Wi1, ....)

同样这样也可以优化为一维来进行相关的表示。
*/
package main

import (
    "bufio"
    "fmt"
    "os"
)

const N int = 110

var (
    n, m int
    s [N]int
    v, w [N][N]int
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
    
    for i := 1; i <= n; i++ {
        // s[i]表示存在多少个物品
        fmt.Fscan(input, &s[i])
        for j := 1; j <= s[i]; j++ {
            fmt.Fscan(input, &v[i][j], &w[i][j])
        }
    }
    
    for i := 1; i <= n; i++ {
        for j := m; j >= 0; j-- {
            // 将每组的不选的情况赋值个f(i, j)
            for k := 1; k <= s[i]; k++ {
                if j >= v[i][k] {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k])
                }
            }
        }
    }
    fmt.Println(f[m])
}