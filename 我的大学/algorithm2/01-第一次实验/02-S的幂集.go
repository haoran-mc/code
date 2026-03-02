package main

import "fmt"

var n int
var ha = make(map[byte]bool)
var S string
var s []byte

func findsubset(idx int) {
    if idx == n {
        fmt.Printf("<")
        for i := 0; i < n; i ++ {
            if ha[s[i]] == true {
                fmt.Printf("%c", s[i])
            }
        }
        fmt.Printf(">")
        return
    }
    findsubset(idx + 1)
    ha[s[idx]] = true
    findsubset(idx + 1)
    ha[s[idx]] = false
}

func main() {
    fmt.Scanf("%d", &n)
    fmt.Scanf("%s", &S)
    s = []byte(S)
    findsubset(0)
}
