package main

import (
	"fmt"
	"testing"
)

func TestHelloWorld(t *testing.T) {
	fmt.Println("hello world.")
}

func Benchmark_Add(b *testing.B) {
	var n int
	for i := 0; i < b.N; i++ {
		n++
	}
}
