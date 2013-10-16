#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int MAXN = 100004;
int num[MAXN],cnt[MAXN];
int main()
{
    int n,i,j,tmp,rnt;
    while(cin >> n)
    {
        rnt = 0;
        memset(cnt,0,sizeof(cnt));
        for(i = 0;i < n;i++)
        {
            cin >> num[i];
            cnt[num[i]] = 1;
            tmp = sqrt(num[i]);
            for(j = 2;j <= tmp;j++)
            {
                if(num[i] % j == 0) cnt[num[i]] = max(cnt[num[i]],max(cnt[j],cnt[num[i] / j]) + 1);
            }
            for(j = 2;j <= tmp;j++)
            {
                if(num[i] % j == 0) 
                {
                    cnt[j] = max(cnt[j],cnt[num[i]]);
                    cnt[num[i] / j] = max(cnt[num[i] / j],cnt[num[i]]);
                }
            }
            rnt = max(rnt,cnt[num[i]]);
        }
        cout << rnt << endl;
    }
    return 0;
}
