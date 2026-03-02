package main

import (
	"fmt"
	"net/http"
)

func sayHello(w http.ResponseWriter, r *http.Request) {
	_, _ = fmt.Fprintln(w, "<h1>Hello, Goland!</h1>")
	_, _ = fmt.Fprintln(w, "<h2>Hello, Goland!</h2>")
	_, _ = fmt.Fprintln(w, "<h3>Hello, Goland!</h3>")
}

func main() {
	http.HandleFunc("/hello", sayHello)
	err := http.ListenAndServe(":9001", nil)
	if err != nil {
		fmt.Printf("HTTP server failed, err: %v\n", err)
		return
	}
}
