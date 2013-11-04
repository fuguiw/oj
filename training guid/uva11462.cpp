#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100 + 4
int cnt[MAXN];

int main()
{
    int n,i,j,num;
    while (cin >> n && n) {
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < n;i++) {
            cin >> num;
            cnt[num]++;
        }
        for (i = 1; i <= 100; i++) 
            if (cnt[i] != 0) {cout << i;cnt[i]--;}
        for (i = 1; i <= 100; i++) 
            for (j = 0; j < cnt[i]; j++) 
                cout << " " << i;
        cout << endl;
    }
    return 0;
}
