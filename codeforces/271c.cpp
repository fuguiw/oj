#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n,k,i;
    while(scanf("%d%d",&n,&k) == 2)
    {
        if(n < 3 * k) 
        {
            printf("-1\n");
            continue;
        }
        for(i = 1;i <= k;i++)
            printf("%d %d ",i,i);
        for(i = 0;i < n - 2 * k;i++)
            printf("%d ",i % k + 1);
        printf("\n");
    }
    return 0;
}
