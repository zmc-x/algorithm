/*
	压位操作就是不是一个数组空间存一个位，而是直接存多位数，这样就可以降低时间复杂度&空间复杂度
*/
package main

import (
    "bufio"
    "fmt"
    "os"
)

const Mod int = 1e9

func add(a, b []int) []int {
    res := make([]int, 0)
    lena, lenb := len(a), len(b)
    // t表示进位
    i, j, t := 0, 0, 0
    for i < lena || j < lenb {
        mid := t
        if i < lena {
            mid += a[i]
            i++
        }
        if j < lenb {
            mid += b[j]
            j++
        }
        t = mid / Mod
        mid %= Mod
        res = append(res, mid)
    }
    if t != 0 {
        res = append(res, t)
    }
    return res;
}
func main(){
    input := bufio.NewReader(os.Stdin)
    output := bufio.NewWriter(os.Stdout)
    
    var a, b string
    fmt.Fscan(input, &a, &b)
    
    A := make([]int, 0)
    B := make([]int, 0)
    
    lena, lenb := len(a), len(b)
    
    for i, j, s, t := lena - 1, 0, 0, 1; i >= 0; i-- {
        s += int(byte(a[i]) - '0') * t 
        j ++
        t *= 10
        if j == 9 || i == 0 {
            A = append(A, s)
            j, s = 0, 0
            t = 1
        }
    }
    
    for i, j, s, t := lenb - 1, 0, 0, 1; i >= 0; i-- {
        s += int(byte(b[i]) - '0') * t 
        j ++
        t *= 10
        if j == 9 || i == 0 {
            B = append(B, s)
            j, s = 0, 0
            t = 1
        }
    }
    
    res := add(A, B)
    lenres := len(res)
    fmt.Printf("%d", res[lenres - 1])
    for i := lenres - 2; i >= 0; i-- {
        fmt.Fprintf(output, "%09d", res[i])
    }
    output.Flush()
    fmt.Println()
}