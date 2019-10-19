package main

func find(prob []float64, p [][]float64, i, target int) float64 {
	if target < 0 {
		return 0
	}

	if i == len(prob) {
		if target == 0 {
			return 1
		}
		return 0
	}

	if p[i][target] >= 0 {
		return p[i][target]
	}

	p[i][target] = find(prob, p, i+1, target)*(1-prob[i]) + find(prob, p, i+1, target-1)*prob[i]
	return p[i][target]
}

func probabilityOfHeads(prob []float64, target int) float64 {
	p := make([][]float64, len(prob))
	for i := 0; i < len(prob); i++ {
		p[i] = make([]float64, target+1)
		for j := 0; j < target+1; j++ {
			p[i][j] = -1
		}
	}
	result := find(prob, p, 0, target)
	return result
}
