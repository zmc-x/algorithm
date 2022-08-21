package main

import ("fmt" 
        "bufio" 
        "os")

func Result(a, k, p int64) int64{
    var res int64 = 1
    for k != 0 {
        if k & 1 == 1 {
            res = res * a % p
        }
        k >>= 1
        a = a * a % p
    }
    return res
}

func main(){
    var n int64
    input := bufio.NewReader(os.Stdin)
	output := bufio.NewWriter(os.Stdout)
    fmt.Fscan(input, &n)
    for n != 0 {
        var a, k, p int64
        fmt.Fscan(input, &a, &k, &p)
        fmt.Fprintln(output,Result(a, k, p))
        n--
    }
    output.Flush()
}