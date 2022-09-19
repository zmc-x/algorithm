package main

import (
    "fmt"
    "os"
    "bufio"
    )


const(
    M = 20
    )

var p [M]int
var n, m, res int

func main(){
    input := bufio.NewReader(os.Stdin)
    output := bufio.NewWriter(os.Stdout)
    fmt.Fscan(input, &n, &m)
    for i := 0; i < m; i++{
        fmt.Fscan(input, &p[i])
    }
    
    for i := 1; i < 1 << m; i++ {
        t, cnt := 1, 0
        for j := 0; j < m; j++ {
            if i >> j & 1 == 1 {
                cnt ++
                if t * p[j] > n {
                    t = -1
                    break
                }
                t = t * p[j]
            }
        }
        if t != -1 {
            if cnt % 2 == 1{
                res += n / t
            }else {
                res -= n / t
            }
        }
    }
    fmt.Fprintln(output, res)
    output.Flush()
}