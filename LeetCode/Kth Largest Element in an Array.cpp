#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    typedef vector<int>::iterator it;

    int findKthLargest(vector<int>& nums, int k, it first, it last) {
        if (first == last)
            return *first;

        int pivot = *(last - 1);

        it mid1 = partition(first, last, [pivot](int em) {return em > pivot; });

        if (mid1 - first >= k) {
            return findKthLargest(nums, k, first, mid1);
        } else {
            it mid2 = partition(mid1, last, [pivot](int em) { return pivot == em; });
            k -= (mid1 - first);
            if (mid2 - mid1 >= k)
                return *mid1;
            else
                return findKthLargest(nums, k - (mid2 - mid1), mid2, last);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, nums.begin(), nums.end());
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{3,2,1,5,6,4,4,7};
    cout << sol.findKthLargest(v, 1) << endl;
    cout << sol.findKthLargest(v, 2) << endl;
    cout << sol.findKthLargest(v, 3) << endl;
    cout << sol.findKthLargest(v, 4) << endl;
    cout << sol.findKthLargest(v, 5) << endl;
    cout << sol.findKthLargest(v, 6) << endl;

    return 0;
}
        
