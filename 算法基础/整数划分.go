/*
首先这题按照题目的意思是存在两种做法的：
	1. 通过完全背包问题的抽象，对于这种整数的划分，可以抽象为1 ~ n的体积为i的背包，
	每个背包可以选多次：那么f(i, j)表示为从1 ~ i个物品中可以选择多个物品使得体积
	刚好为j的方案数，那么对于状态表示则分第i件物品选多少次来划分，
	则有：f(i, j) = f(i - 1, j) + f(i - 1, j - k * i) i >= 1 && i <= n
	同时优化之后为 f(i, j) = f(i - 1, j) + f(i, j - i)
	这里同样也可以优化为一维的来实现
	2. 这一种比较巧妙，f(i, j)表示的i可以通过j个数来进行表示的方案数，那么对于
	状态表示的划分依据就是通过最后一项是否为1来进行划分
	f(i, j) = f(i - 1, j - 1) + f(i - j, j) 这里对于最后一项不是1的表示还是有点抽象的
	这种最后的结果需要枚举从1 ~ n的情况，因为这里表示的状态不一样。
*/
package main

import (
    "fmt"
    "bufio"
    "os"
)

const (
    N int = 1010
    Mod int = 1e9 + 7
)

var (
    n int
    f [N][N]int
)
func main() {
    input := bufio.NewReader(os.Stdin)
    
    fmt.Fscan(input, &n)
    
    f[1][1] = 1
    for i := 2; i <= n; i++ {
        for j := 1; j <= i; j++ {
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % Mod
        }
    }
    res := 0
    for i := 1; i <= n; i++ {
        res = (res + f[n][i]) % Mod
    }
    
    fmt.Println(res)
}