/*
运用dp问题的常规思路来实现，通过状态表示可以知道
f(i, j) = max(f(i - 1, j), f(i - 1, j - vi) + wi, f(i - 1, j - 2 * vi) + 2 * wi...)
这里就是通过将i选择0 ~ k次来进行相关的划分实现

二维：
	f(i, j - vi) = max(f(i - 1, j - vi), f(i - 1, j - 2 * vi) + wi, ...)不难发现
	f(i, j)的后部分就等于f(i, j - vi)的max
	f(i, j) = max(f(i - 1, j), f(i, j - vi) + wi)

一维
	就是运用01背包的优化来实现，同样也可以通过滚动数组来实现，那么就可以直接用一维数组来实现了
	而且这里使用的是第i层的数据，那么直接正序即可

*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const N int = 1010

var (
    // n 数量 m体积
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
    // 从1开始计数
    for i := 1; i <= n; i++ {
        fmt.Fscan(input, &v[i], &w[i])
    }
    
    for i := 1; i <= n; i++ {
        // 这里因为需要的数据是第i层的数据，所有只需要正序来实现即可
        for j := v[i]; j <= m; j++ {
            // 需要判断不要超过体积j
            f[j] = max(f[j], f[j - v[i]] + w[i])
        }
    }
    fmt.Println(f[m])
}