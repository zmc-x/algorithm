/*
	这题的状态表示：f(i, j)表示从a(1, 1)点到a(i, j)路径的最大值
	状态计算：
		分为两个部分：1. 从左上：f(i - 1, j - 1) + a(i, j),
					2. 从右上：f(i - 1, j) + a(i, j)
		=> f(i, j) = max(f(i - 1, j - 1) + a(i, j), f(i - 1, j) + a(i, j))
	首先需要将f全部初始化为负无穷
	但是在这里需要注意边界情况，一个是最左侧的情况，还有就是在右侧还需要向右侧继续扩展一位

	同时还需要将f(1, 1)先进行赋值，否则就会错误
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const (
    N int = 510
    INF int = 1e9
)

var (
    a [N][N]int
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
    var n int
    
    fmt.Fscan(input, &n)
    for i := 1; i <=n; i++ {
        for j := 1; j <= i; j++ {
            fmt.Fscan(input, &a[i][j])
        }
    }
    // 首先将f初始化
    for i := 0; i <= n; i++ {
        for j := 0; j <= i + 1; j++ {
            f[i][j] = -INF
        }
    }
    // 第一个数的max就是a[i][j]
    f[1][1] = a[1][1]
    for i := 1; i <= n; i++ {
        for j := 1; j <= i; j++ {
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j])
        }
    }
    res := -INF
    // 遍历最后一层，find the value of max
    for i := 1; i <= n; i++ {
        res = max(res, f[n][i])
    }
    
    fmt.Printf("%d\n", res)
}