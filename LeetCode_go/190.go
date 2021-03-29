package main

func reverseBits(num uint32) uint32 {
	var ans uint32
	for i := 0; i < 32; i++ {
		ans = ans<<1 + num%2
		num >>= 1
	}
	return ans
}
