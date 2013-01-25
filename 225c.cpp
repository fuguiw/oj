#include<iostream>
#include<cstring>
using namespace std;
#define INF 4444444
const int MAXN = 1001;
char pixels[MAXN][MAXN];
int num[MAXN][2][MAXN];
int bnum[MAXN];
int main()
{
    int n,m,x,y,i,j,rnt;
    while(cin >> n >> m >> x >> y)
    {
        for(i = 0;i < n;i++)
        {
            cin >> pixels[i];
        }
        memset(bnum,0,sizeof(bnum));
        for(i = 0;i < m;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(pixels[j][i] == '#') bnum[i]++;
            }
            for(j = 0;j <= y;j++)
            {
                num[i][0][j] = num[i][1][j] = INF;
            }
        } 
        num[0][0][1] = n - bnum[0];
        num[0][1][1] = bnum[0];
        for(i = 1;i < m;i++)
        {
            if(i >= x)
            {
                for(j = x;j <= min(i,y);j++)
                {
                    num[i][0][1] = min(num[i - 1][1][j] + n - bnum[i],num[i][0][1]);
                    num[i][1][1] = min(num[i - 1][0][j] + bnum[i],num[i][1][1]);
                }
            }
            for(j = 2;j <= min(i + 1,y);j++)
            {
                num[i][0][j] = min(num[i][0][j],num[i - 1][0][j - 1] + n - bnum[i]);
                num[i][1][j] = min(num[i][1][j],num[i - 1][1][j - 1] + bnum[i]);
            }
        }
        rnt = INF;
        for(i = x;i <= y;i++)
            rnt = min(num[m - 1][0][i],min(num[m - 1][1][i],rnt));
        cout << rnt << endl;
    }
}

