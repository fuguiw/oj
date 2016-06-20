#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char str[129];

    gets(str);

    int len = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]))
            ++len;
        else
            len = 0;
    }

    printf("%d\n", len);

    return 0;
}
