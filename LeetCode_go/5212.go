package main

const mod int = 1e9 + 7
const N int = 1e5 + 7

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func sumOfFlooredPairs(nums []int) int {
	counts := make([]int, N)
	for _, num := range nums {
		counts[num]++
	}

	pre := make([]int, N)
	for i := 1; i < N; i++ {
		pre[i] = pre[i-1] + counts[i]
	}

	var ans int
	for i := 1; i < N; i++ {
		if counts[i] == 0 {
			continue
		}

		for j := 1; j*i < N; j++ {
			l := j*i - 1
			r := min(N-1, (j+1)*i-1)

			ans += int(int64((pre[r]-pre[l])*j) * int64(counts[i]) % int64(mod))
		}
	}

	return ans % mod
}
