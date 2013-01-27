#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 2001;
int emp[MAXN],rnt;

void f(int i,int num)
{
    if(i == -1) 
    {
        rnt = max(rnt,num);
        return ;
    }
    f(emp[i],num + 1);
}

int main()
{
    int n,i;
    while(cin >> n)
    {
        rnt = 1;
        for(i = 1;i <= n;i++)
            cin >> emp[i];
        for(i = 1;i <= n;i++)
            f(emp[i],1);
        cout << rnt << endl;
    }
    return 0;
}
