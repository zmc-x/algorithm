/*
这是一个典型的动态规划的问题，这里采用一种通用的方式来实现，
首先对于状态转移方程f[i][j] 可以表示为从0 ~ i个物品中选择，而总体积不超过j
每次实现其实选择的就是最大的值，也就是取max
状态计算：
    对于f(i, j)可以分为是否包含i，对于包含i的那么就可以表示为f(i - 1, j - v[i]) + w[i]；
    而不包含的就可以表示为f(i - 1, j)；由此状态方程可以表示为f(i, j) = max(f(i - 1, j - vi) + wi, f(i - 1, j))
    然后之后枚举每个物品，和所有体积即可

优化：
    首先从状态转移方程来看，每次其实只是用到了上一次的状态，那么其实就可以通过一维数组来实现；
    f(j)就表示从N个物品中，选出最佳的权重的值（不超过j）。
    但是这里需要逆序来枚举体积，因为正序的话，对于取到的值可能不是第i - 1层所得到的，那么就会出现一些错误
    而逆序的话，就可以保证取到的是第i - i层的数据
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const N int = 1010
var (
    n, m int
    f [N][N]int
    v, w [N]int
)

func max(a, b int)int{
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
        fmt.Fscan(input, &v[i], &w[i])
    }
    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            f[i][j] = f[i - 1][j]
            if j >= v[i] {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    fmt.Println(f[n][m]);
}