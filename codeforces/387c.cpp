#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100001
char num[MAXN];

int main()
{
    int i, len, rnt;
    while (cin >> num) {
        rnt = 1;
        for (i = strlen(num) - 1, len = 0; i >= 0; i--) {
            len++;
            if (i < len) break;
            if (num[i] == '0') continue;
            if (i > len) {rnt++; len = 0; continue;}
            if (i == len) {
                if (strncmp(num, num + i, len) < 0) break;
                else {rnt++; len = 0;}
            }
        }
        cout << rnt << endl;
    }
    return 0;
}
