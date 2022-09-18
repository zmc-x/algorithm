package main

import (
    "fmt"
    "os"
    "bufio"
    )

const Mod int = 1e9 + 7

func qmi(a, b, p int) int{
    var res int = 1
    for b != 0 {
        if b & 1 == 1 {
            res = res * a % Mod
        }
        a = a * a % Mod
        b >>= 1
    }
    return res
}

func main(){
    input := bufio.NewReader(os.Stdin)
    output := bufio.NewWriter(os.Stdout)
    var n int
    fmt.Fscan(input, &n)
    a, b := 2 * n, n
    var res int = 1
    for i, j := 1, a; i <= b; i, j = i + 1, j - 1{
        res = res * j % Mod
        res = res * qmi(i, Mod - 2, Mod) % Mod
    }
    res = res * qmi(n + 1, Mod - 2, Mod) % Mod
    fmt.Fprintln(output, res)
    output.Flush()
}