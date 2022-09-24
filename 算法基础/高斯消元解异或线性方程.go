/*
首先这题其实和基本的高斯消元的方式类型 只是需要将其转化为xor来实现
相关的消元而已
*/
package main

import (
    "bufio"
    "os"
    "fmt"
)

const N int = 110

var (
    n int
    a [N][N]int
)

func swap(a, b *int) {
    mid := *a
    *a = *b
    *b = mid
}
func gauss() int {
    c, r := 0, 0
    for ; c < n; c++ {
        t := -1
        for i := r; i < n; i++ {
            if a[i][c] == 1 {
                t = i
                break
            }
        }
        if t == -1 {
            continue
        }
        for i := c; i <= n; i++ {
            swap(&a[t][i], &a[r][i])
        }
        for i := r + 1; i < n; i++ {
            if a[i][c] == 1 {
                for j := c; j <= n; j++ {
                    a[i][j] ^= a[r][j]
                }
            }
        }
        r++
    }
    
    if r < n {
        for i := r; i < n; i++ {
            if a[i][n] != 0 {
                return 1
            }
        }
        return 2
    }
    
    for i := n - 1; i >= 0; i-- {
        for j := i + 1; j < n; j++ {
            a[i][n] ^= a[i][j] & a[j][n]
        }
    }
    return 0
}

func main() {
    input := bufio.NewReader(os.Stdin)
    fmt.Fscan(input, &n)
    for i := 0; i < n; i++ {
        for j := 0; j < n + 1; j++ {
            fmt.Fscan(input, &a[i][j])
        }
    }
    
    res := gauss()
    if res == 0 {
        for i := 0; i < n; i++ {
            fmt.Println(a[i][n])
        }
    }else if res == 1 {
        fmt.Println("No solution")
    }else {
        fmt.Println("Multiple sets of solutions")
    }
}