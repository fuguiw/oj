#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const  int  MAXN = 100001;
bool visit[MAXN];
int n;

int next_min(int m)
{
    for(int i = m;i <= n;i++)
    {
        if(!visit[i]) return i;
    }
    return n;
}

int main()
{
    int num,i,m,rnt;
    while(cin >> n)
    {
        rnt = 0;
        memset(visit,0,sizeof(visit));
        m = 1;
        for(i = 0;i < n;i++)
        {
            cin >> num;
            visit[num] = true;
            if(num > m)
            {
                rnt += i - rnt + 1;
                m = next_min(m);
            }
            if(num == m) m = next_min(m);
        }
        cout << rnt << endl;
    }
    return 0;
}
