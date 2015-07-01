#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if (n < 1 || m < 1)
            return -1;

        list<int> list;
        for (unsigned int i = 0; i < n; i++) {
            list.push_back(i);
        }

        auto it = list.begin();
        while (list.size() != 1) {
            for (unsigned int i = 0; i < m - 1; i++) {
                ++it;
                if (it == list.end())
                    it = list.begin();
            }
            it = list.erase(it);
            if (it == list.end())
                it = list.begin();
        }

        return *list.begin();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.LastRemaining_Solution(5, 3) << endl;
    return 0;
}
