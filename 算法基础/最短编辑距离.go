/*
本题思路：
	状态表示：f(i, j)表示从a中前i个字符和b中前j个字符相等的次数的最小值
	状态计算：这里通过三种修改情况来实现：
	1. 删除：若删掉最后一个字符就和b相同了，那么前i - 1个字符和j相同，那么可以表示为f(i - 1, j) + 1
	2. 添加：表示为f(i, j - 1) + 1;
	3. 修改：
		(1).若最后的字符相同那么 f(i - 1, j - 1)
		(2).不同 f(i - 1, j - 1) + 1
	最后取最小值即可

	注意这里需要对f[N][N]初始化，当a中无元素，b中存在，那么就需要添加i次
	同理，a中存在元素，b中没有，那么就需要删掉i次
*/
package main

import (
    "os"
    "bufio"
    "fmt"
)

const N int = 1010
var (
    n, m int
    f [N][N]int
)

func min(a, b int) int {
    if a <= b {
        return a
    } else {
        return b
    }
}

func main() {
    input := bufio.NewReader(os.Stdin)
    
    fmt.Fscan(input, &n)
    a := make([]byte, 1)
    b := make([]byte, 1)
    var mid string
    fmt.Fscan(input, &mid)
    a = append(a, mid...)
    fmt.Fscan(input, &m)
    fmt.Fscan(input, &mid)
    b = append(b, mid...)
    
    // 将f[N][N]初始化
    for i := 1; i <= n; i++ {
        f[i][0] = i
    }
    
    for i := 1; i <= m; i++ {
        f[0][i] = i
    }
    
    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1)
            if a[i] == b[j] {
                f[i][j] = min(f[i][j], f[i - 1][j - 1])
            } else {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1)
            }
        }
    }
    
    fmt.Println(f[n][m])
}