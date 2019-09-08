package main

import "fmt"

func find(pr map[int][]int, flag []int, n int) bool {
	if flag[n] == 1 {
		return false
	} else if flag[n] == -1 {
		return true
	}

	flag[n] = 1
	for i := 0; i < len(pr[n]); i++ {
		if find(pr, flag, pr[n][i]) == false {
			return false
		}
	}

	flag[n] = -1
	return true
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	pr := make(map[int][]int, numCourses)
	flag := make([]int, numCourses)

	for _, req := range prerequisites {
		pr[req[1]] = append(pr[req[1]], req[0])
	}

	for i := 0; i < numCourses; i++ {
		if find(pr, flag, i) == false {
			return false
		}
	}
	return true
}

func main() {
	pr := [][]int{
		{1, 0},
	}

	fmt.Println(canFinish(2, pr))
}
