#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 5000 + 4;
int a[MAXN];
int n;

int f(int s, int e, int c)
{
	int i, m;
	if (s > e) return 0;
	for (i = m = s; i <= e; i++)
		if (a[i] < a[m]) m = i;
	return min(e - s + 1, f(s, m - 1, a[m]) + f(m + 1, e, a[m]) + a[m] - c);
}

int main()
{
	int i;

	while (cin >> n) {
		for (i = 1; i<= n; i++) cin >> a[i];
		cout << f(1, n, 0) << endl;
	}
	return 0;
}

