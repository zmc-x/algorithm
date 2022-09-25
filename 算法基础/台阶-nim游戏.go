/*
本题是在普通的nim游戏上的一个变种，
在这里通过分析题意只需要xor奇数台阶上的石子个数就行（原因是在这里面地面相当于第
0层，是偶数层，所有考虑到相关奇数层即可）
证明：a1 ^ a2 ^ ... ^ an = x
	当x != 0，先手必然存在多种情况使得后手的局面为0；而当后手从奇数的台阶取石子的话，
	由基本nim游戏，那么必然先手的还是非零；而当其从偶数中取，那么先手可以从相对应的奇数的
	台阶中移出去，那么最终xor还是和之前的一样。总之这样就可以保证必胜态
	当x == 0时，那么后手必然存在多种方式将你干死
*/
package main

import (
    "os"
    "bufio"
    "fmt"
)

func main(){
    input := bufio.NewReader(os.Stdin)
    var n int
    fmt.Scan(&n)
    res := 0
    for i := 1; i <= n; i++{
        var x int
        fmt.Fscan(input, &x)
        if i % 2 == 1 {
            res ^= x
        }
    }
    if res != 0 {
        fmt.Println("Yes")
    }else{
        fmt.Println("No")
    }
}