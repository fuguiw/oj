#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,k,i;
    while (cin >> n >> k) {
        n *= 2;
        k *= 2;
        for (i = 1; i <= k; i += 2)
            printf("%d %d ", i, i + 1);
        for (i = k + 1; i <= n; i += 2)
            printf("%d %d ", i + 1, i);
        printf("\n");
    }
    return 0;
}

