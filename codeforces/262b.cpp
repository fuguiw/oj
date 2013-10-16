#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    int n,k,num,rnt,i,pre;
    while(cin >> n >> k)
    {
        rnt = pre = 0;
        for(i = 0;i < n;i++)
        {
            cin >> num;
            if(k == 0) 
            {
                rnt += num;
                continue;
            }
            if(num >= 0)
            {
                if(k & 1) 
                {
                    if(i == 0) rnt -= num;
                    if(i > 0) 
                    {
                        if(-pre > num) rnt -= num;
                        else rnt += num + 2 * pre;
                    }
                }
                else rnt += num;
                k = 0;
            }
            if(num < 0)
            {
                k--;
                rnt -= num;
            }
            pre = num;
        }
        if(k > 0 && k & 1)
        {
            rnt += 2 * num;
        }
        cout << rnt << endl;
    }
    return 0;
}
