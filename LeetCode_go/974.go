package main

func subarraysDivByK(A []int, K int) int {
	sum, ans := 0, 0
	m := make(map[int]int)
	m[0] = 1

	for i := 1; i <= len(A); i++ {
		sum += A[i-1]
		n := (sum%K + K) % K
		ans += m[n]
		m[n]++
	}

	return ans
}
