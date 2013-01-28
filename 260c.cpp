#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int  MAXN = 100004;
long long num[MAXN];
int main()
{
    long long n,x,i,j,m;
    while(cin >> n >> x)
    {
        for(i = 1,j = 1;i <= n;i++)
        {
            cin >> num[i];
            if(i == 1) m = num[i];
            if(num[i] < m) m = num[i], j = i;
            if(j < x && num[i] == m && i < x) j = i;
            if(j > x && num[i] == m) j = i;
        }
        if(j != x && num[j] == num[x]) j = x;
        if(j > x) m++;
        for(i = 1;i <= n;i++)
        {
            num[i] -= m;
        }
        num[j] += m * n;
        for(i = j + 1;i <= x;i++) num[i]--,num[j]++;
        for(i = x + 1;i < j;i++) num[i]++,num[j]--;
        for(i = 1;i <= n;i++) cout << num[i] << " ";
        cout << endl;
    }
    return 0;
}
