package main

import "fmt"

func main() {
	str0 := make([]string, 3)
	str0[0] = "0"
	str0[1] = "0"
	str0[2] = "0"
	fmt.Println(str0)

	str1 := str0
	str0[0] = "1"
	fmt.Println(str1)

	str0[0] = "0"
	copy(str1, str0)
	fmt.Println(str1)
	str0[0] = "1"
	fmt.Println(str1)

	str2 := make([]string, 3)
	str0[0] = "0"
	fmt.Println(str2)

	str3 := "hello"
	fmt.Println(str3)
	str3[0] = "H"
}
