#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findX(int A[], int m, int B[], int n, int x) {
        if (m == 0) return B[x];
        if (n == 0) return A[x];
        if (x == 0) return min(A[0], B[0]);

        int t = x / 2;
        int i = min(m - 1, min(n - 1, t));

        if (A[i] >= B[i]) {
            if (i == 0) i = 1;
            B += i;
            n -= i;
        } else {
            if (i == 0) i = 1;
            A += i;
            m -= i;
        }

        return findX(A, m, B, n, x - i);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2) {
            return findX(A, m, B, n, (m + n) / 2);
        } else {
            int t1 = findX(A, m, B, n, (m + n) / 2 - 1);
            int t2 = findX(A, m, B, n, (m + n) / 2);
            return (t1 + t2) / 2.0;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = {1,2,4};
    int b[] = {3,4,5,6};

    cout <<  sol.findMedianSortedArrays(b,1,a,3) << endl;

    return 0;
}
