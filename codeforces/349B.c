#include <stdio.h>
#include <string.h>

int main()
{
    int v,i,j,m,left,cnt;
    int a[10];
    while(scanf("%d",&v) == 1) {
        for(i = 1, m = 0; i <= 9; i++) {
            scanf("%d", &a[i]);
            if(v / a[i] > m) {m = v / a[i]; j = a[i];}
        }
        if(m == 0) {
            printf("-1\n");
            continue;
        }
        while(m--) {
            for(i = 9; i >= 1; i--) {
                if((v - a[i]) / j == m && v >= a[i]) {
                    v -= a[i];
                    printf("%d", i);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
