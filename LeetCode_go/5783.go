package main

import "sort"

type movie struct {
	id    int
	shop  int
	price int
	rent  bool
}

type MovieRentingSystem struct {
	movies       map[int]map[int]*movie
	orderByMovie map[int][]*movie
	orderByPrice []*movie
}

func Constructor(n int, entries [][]int) MovieRentingSystem {
	sys := MovieRentingSystem{}
	sys.movies = make(map[int]map[int]*movie)
	sys.orderByMovie = make(map[int][]*movie)
	for _, entry := range entries {
		s, m, p := entry[0], entry[1], entry[2]
		movie := &movie{
			m,
			s,
			p,
			false,
		}
		if sys.movies[s] == nil {
			sys.movies[s] = make(map[int]*movie)
		}
		sys.movies[s][m] = movie
		sys.orderByMovie[m] = append(sys.orderByMovie[m], movie)
		sys.orderByPrice = append(sys.orderByPrice, movie)
	}

	for _, shop := range sys.orderByMovie {
		sort.Slice(shop, func(i, j int) bool {
			return shop[i].price < shop[j].price
		})
	}
	sort.Slice(sys.orderByPrice, func(i, j int) bool {
		if sys.orderByPrice[i].price == sys.orderByPrice[j].price {
			if sys.orderByPrice[i].shop == sys.orderByPrice[j].shop {
				return sys.orderByPrice[i].id < sys.orderByPrice[j].id
			}
			return sys.orderByPrice[i].shop < sys.orderByPrice[j].shop
		}
		return sys.orderByPrice[i].price < sys.orderByPrice[j].price
	})
	return sys
}

func (this *MovieRentingSystem) Search(movie int) []int {
	var ans []int
	for i := range this.orderByMovie[movie] {
		if this.orderByMovie[movie][i].rent == false {
			ans = append(ans, this.orderByMovie[movie][i].shop)
			if len(ans) == 5 {
				return ans
			}
		}
	}

	return ans
}

func (this *MovieRentingSystem) Rent(shop int, movie int) {
	this.movies[shop][movie].rent = true

}

func (this *MovieRentingSystem) Drop(shop int, movie int) {
	this.movies[shop][movie].rent = false
}

func (this *MovieRentingSystem) Report() [][]int {
	var ans [][]int
	for i := range this.orderByPrice {
		if this.orderByPrice[i].rent {
			ans = append(ans, []int{this.orderByPrice[i].shop, this.orderByPrice[i].id})
		}
		if len(ans) == 5 {
			return ans
		}
	}
	return ans
}

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * obj := Constructor(n, entries);
 * param_1 := obj.Search(movie);
 * obj.Rent(shop,movie);
 * obj.Drop(shop,movie);
 * param_4 := obj.Report();
 */
