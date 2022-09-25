/*
实现的具体思路：
这里采用sg函数来实现相关的处理，此处和其他不一样的是；ta是将一个
heap直接分成了两个，然后来计算相关的值；对于如何来计算就是采用xor的方式
来实现，其实也就是类似于多种局面的合成。
for i := 0; i < x; i++ {
	for j := 0; j <= x; j++ {
		set[sg[i] ^ sg[j]] = true
	}
}
*/
package main

import (
    "fmt"    
    "bufio"
    "os"
)

const N int = 110

var f [N]int

func sg(x int) int {
    if f[x] != -1 {
        return f[x]
    }
    // 建立一个hash表
    
    set := make(map[int]bool)
    for i := 0; i < x; i++ {
        for j := 0; j <= i; j++ {
            set[sg(i) ^ sg(j)] = true
        }
    }
    
    for i := 0; ; i++ {
        if set[i] == false {
            f[x] = i
            return f[x]
        }
    }
}

func main(){
    
    // 初始化
    for i := 0; i < N; i++ {
        f[i] = -1
    }
    input := bufio.NewReader(os.Stdin)
    
    var n int
    res := 0
    fmt.Fscan(input, &n)
    
    for i := 0; i < n; i++ {
        x := 0
        fmt.Fscan(input, &x)
        res ^= sg(x)
    }
    
    if res == 0 {
        fmt.Println("No")
    }else {
        fmt.Println("Yes")
    }
    
}