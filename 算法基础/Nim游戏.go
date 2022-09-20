/*
首先这种判断的方式就是一个简单的xor运算；
当所用堆中数量的进行xor计算即可
为0：表示为先手必败
为1：为先手必胜
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

func main(){
    input := bufio.NewReader(os.Stdin)
    output := bufio.NewWriter(os.Stdout)
    var n, res int 
    fmt.Fscan(input, &n)
    for i := 0; i < n; i++{
        var x int
        fmt.Fscan(input, &x)
        res ^= x
    }
    
    if res == 0{
        fmt.Fprintln(output,"No")
    }else {
        fmt.Fprintln(output, "Yes")
    }
    output.Flush()
}