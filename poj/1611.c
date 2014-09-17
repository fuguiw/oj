#include <stdio.h>

#define MAXN 30004

int n, m;
int fa[MAXN];

int get_father(int no)
{
	if (no != fa[no])
		return (fa[no] = get_father(fa[no]));
	else
		return no;
}

void un(int a, int b)
{
	int ta = get_father(a);
	int tb = get_father(b);
	if (ta == tb) return ;
	fa[ta] = b;
}

int main()
{
	int i, j, cnt, f, tmp, rnt;
	while (scanf("%d %d", &n, &m) && n) {
		for (i = 0; i < n; i++) fa[i] = i;
		rnt = 1;
		for (i = 0; i < m; i++) {
			scanf("%d %d", &cnt, &f);
			for (j = 1; j < cnt; j++) {
				scanf("%d", &tmp);
				if (get_father(f) != get_father(tmp)) un(f, tmp);
			}
		}
		for (i = 1; i < n; i++) {
			tmp = get_father(0);
			if (tmp == get_father(i)) rnt++;
		}
		printf("%d\n", rnt);
	}
}
