package main

func circularArrayLoop(nums []int) bool {
	n := len(nums)
	v := make([]int, n)

	var dfs func(int) bool
	dfs = func(idx int) bool {
		if v[idx] > 0 {
			return v[idx] == 1
		}

		v[idx] = 1
		next := (n + idx + (nums[idx] % n)) % n
		if nums[idx] > 0 && nums[next] > 0 || nums[idx] < 0 && nums[next] < 0 {
			if next != idx && dfs(next) {
				return true
			}
		}

		v[idx] = 2
		return false
	}

	for i := range nums {
		if dfs(i) {
			return true
		}
	}

	return false
}
