import "math"

func sortedSquares(A []int) []int {
	var pi int
	n := len(A)
	for pi = 0; pi < n; pi++ {
		if A[pi] > 0 {
			break
		}
	}
	i, j := pi-1, pi
	ans := make([]int, n)
	for k := range ans {
		ans[k] = math.MaxInt32
		if i >= 0 && A[i]*A[i] < ans[k] {
			ans[k] = A[i] * A[i]
			i--
		}
		if j < n && A[j]*A[j] < ans[k] {
			if ans[k] != math.MaxInt32 {
				i++
			}
			ans[k] = A[j] * A[j]
			j++
		}
	}
	return ans
}
