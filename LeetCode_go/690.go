package main

/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func getImportance(employees []*Employee, id int) int {
	m := make(map[int]*Employee)
	for _, e := range employees {
		m[e.Id] = e
	}

	ans := 0
	var dfs func(i int)
	dfs = func(i int) {
		e := m[i]
		ans += e.Importance
		for _, sub := range e.Subordinates {
			dfs(sub)
		}
	}
	dfs(id)

	return ans
}
