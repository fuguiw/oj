#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int index = A[0];

        for (int i = 0; i <= index && i < n; i++) {
                index = max(index, A[i] + i);
        }

        if (index >= n - 1)
            return true;
        else
            return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = {1,1,0,0};

    cout << sol.canJump(a, 4) << endl;

    return 0;
}
