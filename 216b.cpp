#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 101;
int f[MAXN],cnt[MAXN];

int found(int x)
{
    return x == f[x] ? x : found(f[x]);
}

int main()
{
    int n,m,i,x,y,tx,ty,rnt;
    while(cin >> n >> m)
    {
        rnt = 0;
        for(i = 1;i <= n;i++) f[i] = i,cnt[i] = 1;
        for(i = 0;i < m;i++)
        {
             cin >> x >> y;
             tx = found(x);
             ty = found(y);
             if(tx == ty && cnt[tx] % 2) rnt++;
             if(tx != ty) f[ty] = tx,cnt[tx] += cnt[ty];
        }
        if((n - rnt) % 2) rnt++;
        cout << rnt << endl;
    }
    return 0;
}

