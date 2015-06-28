#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); i++)
            ++m[numbers[i]];

        for (auto it = m.begin(); it != m.end(); it++)
            if (it->second > numbers.size() / 2)
                return it->first;

        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,2,3,2,2,2,5,4,2};
    cout << sol.MoreThanHalfNum_Solution(v) << endl;
    return 0;
}
