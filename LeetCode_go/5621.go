package main

func countStudents(students []int, sandwiches []int) int {
	ans := len(students)
	i, j := 0, 0
	for len(students) != 0 {
		n := len(students)
		for i = 0; i < n; i++ {
			if students[i] == sandwiches[j] {
				students = append(students[:i], students[i+1:]...)
				j++
				ans--
				break
			}
		}
		if i == n {
			return ans
		}
	}
	return ans
}
