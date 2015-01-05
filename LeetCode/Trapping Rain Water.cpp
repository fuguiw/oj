#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int i, j, s, e, rnt, t;

        s = rnt = 0;
        for (i = 0; i < n; i++) {

            for (; i < n - 1; i++) {
                if (A[i] > A[i + 1]) {
                    if (i == 0 || A[i] >= A[i - 1]) {
                        s = i++;
                        break;
                    }
                }
            }
            if (i == n - 1)
                break;

            for (; i < n; i++) {
                if (i == n - 1 || A[i] >= A[s]) {
                    e = i--;
                    break;
                }
            }

            t = min(A[s], A[e]);
            for (j = e - 1; j > s; j--) {
                if (t >= A[j])
                    rnt += t - A[j];
                else 
                    t = A[j];
            }

            if (e == n - 1)
                break;
        }

        return rnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int A[] = {4,2,0,3,2,4,3,4};

    cout << sol.trap(A, 8) << endl;

    return 0;
}
