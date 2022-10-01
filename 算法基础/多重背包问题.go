/*
朴素的解法：类似于完全背包问题的解法，只不过存在每件物品的限制条件
*/
package main

import (
    "bufio"
    "os"
    "fmt"
)

const N int = 110

var (
      n, m int
      v, w, s [N]int
      f [N][N]int
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
        fmt.Fscan(input, &v[i], &w[i], &s[i])
    }


    for i := 1; i <= n; i++ {
        for j := 0; j <= m; j++ {
            for k := 0; k <= s[i] && k * v[i] <= j; k++ {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i])
            }
        }
    }

    fmt.Println(f[n][m])
}
