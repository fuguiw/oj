#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 10000

struct _ant {
    int no,pos,dir;
}ant[MAXN];

bool cmp1(struct _ant a,struct _ant b) 
{
    return a.pos < b.pos;
}

bool cmp2(struct _ant a,struct _ant b) 
{
    return a.no < b.no;
}

int main()
{
    int N,c,l,t,n,i;
    int no[MAXN];
    char d;
    cin >> N;
    for (c = 1; c <= N; c++) {
        cin >> l >> t >> n;
        for (i = 0; i < n; i++) {
            cin >> ant[i].pos >> d;
            if (d == 'L') ant[i].dir = -1;
            else ant[i].dir = 1;
            ant[i].no = i;
        }
        sort(ant, ant + n, cmp1);
        for (i = 0; i < n; i++) {
            no[i] = ant[i].no;
            ant[i].pos += t * ant[i].dir;
        } 
        sort(ant, ant + n, cmp1);
        for (i = 0; i < n; i++) {
            ant[i].no = no[i];
            if (ant[i].pos == ant[i + 1].pos) 
                ant[i].dir = ant[i + 1].dir = 0;
        }
        sort(ant, ant + n, cmp2);
        printf("Case #%d:\n",c);
        for (i = 0; i < n; i++) {
            if (ant[i].pos < 0 || ant[i].pos > l) {
                cout << "Fell off" << endl; 
                continue;
            }
            cout << ant[i].pos;
            if (ant[i].dir == -1) cout << " L" << endl;
            if (ant[i].dir == 0) cout << " Turning" << endl;
            if (ant[i].dir == 1) cout << " R" << endl;
        }
        cout << endl;
    }
    return 0;
}
