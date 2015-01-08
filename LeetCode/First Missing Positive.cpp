#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int v[n + 1];
        int i;

        memset(v, 0, sizeof(v));

        for (i = 0; i < n; i++)
            if (A[i] > 0 && A[i] <= n)
                v[A[i]] = 1;

        for (i = 1; i <= n; i++)
            if (!v[i])
                break;

        return i;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = {3,4,-1,1};

    cout << sol.firstMissingPositive(a, 4) << endl;

    return 0;
}
