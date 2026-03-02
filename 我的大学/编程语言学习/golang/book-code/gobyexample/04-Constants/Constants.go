/*
 * Go supports constants of character, string, boolean, and numeric values.
 *
 * A const statement can appear anywhere a var statement can.
 * Constant expressions perform arithmetic with arbitrary precision.
 * A numeric constant has no type until it’s given one, such as by an explicit conversion.
 * A number can be given a type by using it in a context that requires one, such as a variable assignment or function call. For example, here math.Sin expects a float64.
 */

package main

import (
	"fmt"
	"math"
)

const s string = "constant"

func main() {
	fmt.Println(s)

	const n = 500000000

	const d = 3e20 / n
	fmt.Println(d) //以常量的类型输出

	fmt.Println(int64(d)) //以int变量的类型输出

	fmt.Println(math.Sin(n))
	fmt.Println(math.E)
}
