/*
	题意：就是指最长的满足递增序列的长度
	思路：
	状态表示：f(i)可以表示为以i结尾的最长的序列
	状态计算：和容易想到通过拆分为多个子问题来实现，那么就可以通过其i - 1前面的数组index
		来实现对f(i)的间接求解，
		f(i) = max(f(j) + 1) a[j] < a[i] 且 j < i；
		在这之前需要考虑到其他都不满足的情况，只有ta自己符合要求的情况，也就是f(i) = 1
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const N int = 1010

var (
    n int 
    a, f [N]int
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
    fmt.Fscan(input, &n)
    for i := 1; i <= n; i++ {
        fmt.Fscan(input, &a[i])
    }
    
    for i := 1; i <= n; i++ {
        f[i] = 1
        for j := 1; j <= i - 1; j++ {
            if a[j] < a[i] {
                f[i] = max(f[i], f[j] + 1)
            }
        }
    }
    res := 0
    for i := 1; i <= n; i++ {
        res = max(res, f[i])
    }
    
    fmt.Println(res)
}