#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN = 100001;
char str[MAXN];
int main()
{
    int i;
    while(cin >> str)
    {
        int len = strlen(str);
        for(i = 0;i < len;i++)
        {
            if(str[i] == '0') {i++;break;}
            if(i < len - 1)
                cout << str[i];
        }
        for(;i < len;i++) cout << str[i];
        cout << endl;
    }
    return 0;
}
