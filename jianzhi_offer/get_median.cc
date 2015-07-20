#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        int n = max.size() + min.size();
        if (n % 2)
        {
            if (!min.empty() && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
        else
        {
            if (!max.empty() && max[0] > num)
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
    }

    double GetMedian()
    { 
        int n = max.size() + min.size();
        double median = 0;
        if (n % 2)
            median = min[0];
        else
            median = (max[0] + min[0]) / 2.0;
        return median;
    }


private:
    vector<int> min;
    vector<int> max;
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{5,2,3,4,1,6,7,0,8};
    for (auto n : v)
    {
        sol.Insert(n);
        cout << sol.GetMedian() << endl;
    }
    return 0;
}
