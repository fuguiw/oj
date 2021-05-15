package main

import (
	"sort"
	"strconv"
	"strings"
)

func sortSentence(s string) string {
	type word struct {
		str string
		pos int
	}
	var words []word
	for _, str := range strings.Split(s, " ") {
		pos, _ := strconv.Atoi(string(str[len(str)-1:]))
		words = append(words, word{str[:len(str)-1], pos})
	}

	sort.Slice(words, func(i, j int) bool {
		return words[i].pos < words[j].pos
	})

	var ans string
	for i := range words {
		if i != 0 {
			ans += " "
		}
		ans += words[i].str
	}

	return ans
}
