/*
和编辑最小距离同样的思路，只不过需要遍历很多次而已
*/
package main

import (
    "bufio"
    "fmt"
    "os"
)

const (
    N int = 1010
    M int = 20
)

var (
    n, m int
    f [M][M]int
)

func min(a, b int) int {
    if a <= b {
        return a
    } else {
        return b
    }
}

func reckonCount(a, b []byte)int {
    la, lb := len(a) - 1, len(b) - 1
    
    for i := 1; i <= la; i++ {
        f[i][0] = i
    }
    for i := 1; i <= lb; i++ {
        f[0][i] = i    
    }
    
    for i := 1; i <= la; i++ {
        for j := 1; j <= lb; j++ {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1)
            if a[i] == b[j] {
                f[i][j] = min(f[i][j], f[i - 1][j - 1])
            } else {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1)
            }
        }
    }
    return f[la][lb]
}

func main() {
    input := bufio.NewReader(os.Stdin)
    
    fmt.Fscan(input, &n, &m)
    
    str := make([][]byte, N)
    var mid string
    for i := 0; i < n; i++ {
        fmt.Fscan(input, &mid)
        str[i] = make([]byte, 1)
        str[i] = append(str[i], mid...)
    }
    
    for i := 0; i < m; i++ {
        var limit, res int
        a := make([]byte, 1)
        fmt.Fscan(input, &mid, &limit)
        a = append(a, mid...)
        for j := 0; j < n; j++ {
            if reckonCount(str[j], a) <= limit {
                res ++
            }
        }
        
        fmt.Println(res)
    }
}