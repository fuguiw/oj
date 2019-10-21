package main

func canCompleteCircuit(gas []int, cost []int) int {
	total_tank, curr_tank := 0, 0
	start := 0
	for i := range gas {
		total_tank += gas[i] - cost[i]
		curr_tank += gas[i] - cost[i]

		if curr_tank < 0 {
			start = i + 1
			curr_tank = 0
		}
	}

	if total_tank >= 0 {
		return start
	}
	return -1
}
