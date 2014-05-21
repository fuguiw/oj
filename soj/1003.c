#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1111

char a[MAXN];
char b[MAXN];
int c[MAXN];

int main()
{
	int len_a, len_b, i, j, k;
	while (scanf("%s %s", a, b) == 2) {
		memset(c, 0, sizeof(c));
		len_a = strlen(a);
		len_b = strlen(b);
		for (i = len_a - 1; i >= 0; i--) {
			for(j = len_b - 1, k = len_a - 1 - i; j >= 0; ) {
					c[k++] += (b[j--] - '0') * (a[i] - '0');
			}
		}
		for (i = 0; i < k; i++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		for (i = k; i > 0; i--) {
			if (c[i]) break;
		}
		for (; i >= 0; i--)
			printf("%d", c[i]);
		printf("\n");
	}
	return 0;
}
