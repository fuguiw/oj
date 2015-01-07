#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int m = 1;
        int index = A[0];
        int tmp = A[0];

        if (n == 1)
            return 0;

        for (int i = 0; i <= index && index < n - 1;) {
            for (; i <= index && i < n; i++) {
                if (A[i] + i >= n - 1)
                    return m + 1;

                tmp = max(tmp, A[i] + i);
            }

            index = tmp;
            ++m;
        }

        return m;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    /* int a[] = {1,2,1,1,4}; */

    cout << sol.jump(a, 15) << endl;

    return 0;
}
