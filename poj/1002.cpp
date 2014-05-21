#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <map>
using namespace std;

int main()
{
    int n, num;
    map<int, int> pn;
    map<int, int>::iterator it;
    char str[444];
    int i, tmp;
    cin >> n;
    tmp = n;
    int pnum[n + 1];

    while (tmp--) {
        scanf("%s", str);
        num = 0;
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == '-') continue;
            if (isalpha(str[i])) {
                if (str[i] > 'Q') 
                    num = num * 10 + (str[i] - 1 - 'A') / 3 + 2;
                else 
                    num = num * 10 + (str[i] - 'A') / 3 + 2;
            }
            if (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
            }
        }
        pn[num]++;
    }
    for (i = 0, it = pn.begin(); it != pn.end(); i++, it++) {
        pnum[i] = it->first;
    }
    sort(pnum, pnum + i);
    tmp = 0;
    for (i = 0, it = pn.begin(); it != pn.end(); i++, it++) {
        if (pn[pnum[i]] <= 1) continue;
        tmp++;
        printf("%03d-%04d %d\n", pnum[i] / 10000, pnum[i] % 10000, pn[pnum[i]]);
    }
    if (tmp == 0) printf("No duplicates.\n");
    return 0;
}
