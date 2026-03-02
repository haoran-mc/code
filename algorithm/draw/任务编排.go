package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan int, 4)
	for {
		for i := 1; i < 5; i++ {
			ch <- i
			go func() {
				st := <-ch
				fmt.Println(st)
			}()
			time.Sleep(1 * time.Second)
		}
	}
}
