package main

type AuthenticationManager struct {
	startTime  map[string]int
	expireTime int
}

func Constructor(timeToLive int) AuthenticationManager {
	a := AuthenticationManager{expireTime: timeToLive}
	a.startTime = make(map[string]int)
	return a
}

func (this *AuthenticationManager) Generate(tokenId string, currentTime int) {
	this.startTime[tokenId] = currentTime
}

func (this *AuthenticationManager) Renew(tokenId string, currentTime int) {
	if _, ok := this.startTime[tokenId]; !ok {
		return
	}
	if this.startTime[tokenId]+this.expireTime > currentTime {
		this.startTime[tokenId] = currentTime
	}
}

func (this *AuthenticationManager) CountUnexpiredTokens(currentTime int) int {
	count := 0
	for _, v := range this.startTime {
		if v+this.expireTime > currentTime {
			count++
		}
	}
	return count
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * obj := Constructor(timeToLive);
 * obj.Generate(tokenId,currentTime);
 * obj.Renew(tokenId,currentTime);
 * param_3 := obj.CountUnexpiredTokens(currentTime);
 */
