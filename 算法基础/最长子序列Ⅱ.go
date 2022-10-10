/*
这是一种贪心的做法，
对于每一种长度的子序列而言，最后的值取最小的有利于扩展
那么就可以通过这个来实现优化版的最长子序列的问题，时间复杂度O(n * logn)
通过二分来寻找最小于该值的最大的数，然后将其加入到下一个长度中去，而此时的长度
就是max，

ps：golang中的>> & << 优先级高于+ - 
*/
package main

import (
    "bufio"
    "os"
    "fmt"
)

const N int = 1e5 + 10
var (
    a, q [N]int 
)


func main() {
    input := bufio.NewReader(os.Stdin)
    var n int
    fmt.Fscan(input, &n)
    for i := 0; i < n; i++ {
        fmt.Fscan(input, &a[i])
    }
    // q 数组的长度就是最长的长度
    Len := 0
    for i := 0; i < n; i++ {
        l, r := 0, Len
        for l < r {
            // + 1
            mid := (l + r + 1) >> 1
            if q[mid] < a[i] {
                l = mid                
            } else {
                r = mid - 1
            }
        }
        if r + 1 > Len {
            Len = r + 1
        }
        q[r + 1] = a[i]
    }
    fmt.Println(Len)
}