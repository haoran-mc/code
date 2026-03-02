/*
 * for is Go’s only looping construct. Here are some basic types of for loops.
 * The most basic type, with a single condition.
 * A classic initial/condition/after for loop.
 * for without a condition will loop repeatedly until you break out of the loop or return from the enclosing function.
 * You can also continue to the next iteration of the loop.
 */

package main

import "fmt"

func main() {
	i := 1
	for i <= 3 {
		fmt.Println(i)
		i = i + 1
	}

	for j := 7; j <= 9; j++ { // 没有++j这种形式了，难受
		fmt.Println(j)
	}

	for {
		fmt.Println("loop")
		break
	}

	for n := 0; n <= 5; n++ {
		if n%2 == 0 {
			continue
		} //好烦啊，不想单独一行还加大括号
		fmt.Println(n)
	}
}
