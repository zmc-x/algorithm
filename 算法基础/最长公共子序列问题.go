/*
	分析思路：
		状态表示：很显然使用二维的状态表示f(i, j)，集合表示某一个子序列既在第一个
		序列的前i个字符前出现过，同时也在第二个序列的前j个字符中出现过
		状态计算：
			f(i, j)通过前i, j个字符中是否包括a[i] / b[j]来进行划分，这样就存在4中情况
			00,01,10,11；分别可以表示为：f(i - 1, j - 1), f(i - 1, j), f(i, j - 1),
			f(i - 1, j - 1) + 1
			但是中间两个 ！= 中间两种对应的情况，可以理解为ta包括了其对应的状态，同时在这里
			求的是max，所以也就可以用这个表示，同时中间两种情况也包含了第一种
			情况，所以只用考虑后三种即可
*/
package main

import (
	"bufio"
	"os"
	"fmt"
)

const N int = 1010
var (
	f [N][N]int
)

func max(a, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

func main() {
	input := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(input, &n, &m)
	// 通过切片来实现对字符串从第一位开始存储
	a := make([]byte, 1)
	b := make([]byte, 1)
	// 设置一个中间值
	var mid string
	fmt.Fscan(input, &mid)
	// 使用append函数对a b实现相关的扩展
	a = append(a, mid[ : ]...)
	fmt.Fscan(input, &mid)
	b = append(b, mid[ : ]...)
	// 通过状态转移方程可以知道f(i, j) = max(f(i - 1, j), f(i, j - 1), f(i - 1)(j - 1) + 1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			f[i][j] = max(f[i - 1][j], f[i][j - 1])
			if a[i] == b[j] {
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1)
			}
		}
	}

	fmt.Println(f[n][m])
}