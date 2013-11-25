#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 200004

char input[MAXN], output[MAXN];

int main()
{
    int i, j;
    while (cin >> input) {
        int len = strlen(input);
        output[0] = input[0];
        output[1] = input[1];
        for (i = j = 2; i < len; i++) {
            if (input[i] == output[j - 1] && input[i] == output[j - 2]) continue;
            if (i != 2 && output[j - 2] == output[j - 3] && input[i] == output[j - 1]) continue;
            output[j++] = input[i];
        }
        output[j] = '\0';
        cout << output << endl;
    }
    return 0;
}
