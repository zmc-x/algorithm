/*
首先这题就是采用sg函数来实现，通过对每一个堆来进行模拟可以得到的状态从而来
得到一个sg函数的值，这个值就代表这可以取到的值 - 1；当这个值取到0就不可能获胜；
通过这个sg函数，那么就可以将当前的一个状态转化为一个普通的nim游戏，然后通过xor来判断可以获胜。

ps：这个其实是通过mex函数来计算sg的值
*/
package main

import (
    "fmt"
    "os"
    "bufio"
)

const (
    N = 110
    M = 10010
)

var (
    k, n int
    s [N]int
    f [M]int
)

func sg(x int) int {
    if f[x] != -1 {
        return f[x]
    }
    // 建立一个map
    S := make(map[int]bool)
    for i := 0; i < k; i++ {
        sum := s[i]
        if x >= sum {
            S[sg(x - sum)] = true
        }
    }
    
    for i := 0; ; i++ {
        if S[i] == false {
            f[x] = i
            return f[x]
        }
    }
}
func main(){
    input := bufio.NewReader(os.Stdin)
    fmt.Fscan(input, &k)
    for i := 0; i < k; i++ {
        fmt.Fscan(input, &s[i])
    }
    // 初始化
    for i := 0; i < M; i++ {
        f[i] = -1;
    }
    // 记录结果
    var res int
    fmt.Fscan(input, &n)
    for i := 0; i < n; i++ {
        var x int
        fmt.Fscan(input, &x)
        res ^= sg(x)
    }
    
    if res != 0 {
        fmt.Println("Yes")
    }else {
        fmt.Println("No")
    }
}