package main

import "fmt"

func main() {
	// 1. 声明切片
	var s1 []int

	if s1 == nil {
		fmt.Println("s1 == nil")
	} else {
		fmt.Println("s1 != nil")
	}

	// 2. :=
	s2 := []int{}
	if s2 == nil {
		fmt.Println("s2 == nil")
	} else {
		fmt.Println("s2 != nil")
	}

	s3 := []int{1, 2, 3}
	fmt.Println(s3)

	// 3. make()
	var s4 []int = make([]int, 0)
	fmt.Println(s1, s2, s4)

	// 4. 初始化赋值
	var s5 []int = make([]int, 0, 0)
	fmt.Println(s5)

	// 5. 从数组切片
	arr := [5]int{1, 2, 3, 4, 5}
	var s6 []int
	s6 = arr[1:4]
	fmt.Println(s6)
}
