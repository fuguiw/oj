#include<iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        if (A == NULL || n <= 0)
            return -1;

        int left = 0;
        int right = n - 1;
        int mid = 0;

        while (A[left] >= A[right]) {
            if (right == left) {
                if (A[left] == target)
                    return left;
                else
                    return -1;

            }

            mid = (left + right) / 2;
            if (A[mid] >= A[left])
                left = mid;
            else if (A[mid] <= A[right])
                right = mid;
        }
    
        return mid;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[44];
    int n;

    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << sol.search(a, n, 4) << endl;
    }

    return 0;
}
