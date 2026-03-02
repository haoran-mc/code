package main

import "fmt"

var mod int = 1e9 + 7

func main() {
	var n int
	fmt.Scanf("%d", &n)

	var primes map[int]int = make(map[int]int)

	for k := 0; k < n; k++ {
		var N int
		fmt.Scanf("%d", &N)

		for i := 2; i <= N/i; i++ {
			for N%i == 0 {
				N /= i
				primes[i]++
			}
		}

		if N > 1 {
			primes[N]++
		}
	}

	var res int = 1
	for k, v := range primes {
		// p^0 + p^1 + p^2 + ... + p^a1
		var t int = 1

		for i := 0; i < v; i++ {
			t = (t*k)%mod + 1
		}
		res = res * t % mod
	}

	fmt.Println(res)
}
