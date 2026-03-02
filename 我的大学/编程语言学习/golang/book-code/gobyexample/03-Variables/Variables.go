/*
 * In Go, variables are explicitly declared and used by the compiler to e.g. check type-correctness of function calls.
 *
 * Run codeCopy code
 * You can declare multiple variables at once.
 * Go will infer the type of initialized variables.
 * Variables declared without a corresponding initialization are zero-valued. For example, the zero value for an int is 0.
 * The := syntax is shorthand for declaring and initializing a variable, e.g. for var f string = "apple" in this case.
 */

package main

import "fmt"

func main() {
	var a = "initial"
	fmt.Println(a)

	var b, c int = 1, 2
	fmt.Println(b, c) //以空格隔开

	var d = true
	fmt.Println(d) //直接打印true

	var e int
	fmt.Println(e) //未初始化的变量默认初值是0

	f := "apple" //快速赋值
	fmt.Println(f)

	g := 1
	fmt.Println(g)

	h := 1.010
	fmt.Println(h)

	i := true
	fmt.Println(i)
}
