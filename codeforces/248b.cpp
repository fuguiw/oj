#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int n,i,p;
    while(cin >> n)
    {
        if(n <= 3) cout << (n <= 2 ? -1 : 210) << endl;
        else
        {
            printf("1");
            for(i = 1,p = 50;i < n - 3;i++)
                printf("0"),p = p * 10 % 210;
            printf("%03d\n",p);
        }
    }
    return 0;
}
